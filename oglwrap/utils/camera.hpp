/** @file camera.hpp
    @brief Implements a basic free-fly camera to help testing. Uses SFML.
*/

#ifndef OGLWRAP_UTILS_CAMERA_HPP_
#define OGLWRAP_UTILS_CAMERA_HPP_

#include <cmath>
#include <SFML/Window.hpp>
#include "../oglwrap.hpp"

namespace oglwrap {

/// Purely virtual interface class for cameras.
class Camera {
public:
  /// Returns the camera matrix.
  virtual glm::mat4 cameraMatrix() const = 0;

  /// Returns the camera's position.
  virtual glm::vec3 getPos() const = 0;

  /// Returns the camera's target.
  virtual glm::vec3 getTarget() const = 0;

  /// Returns the looking direction of the camera
  virtual glm::vec3 getForward() const {
    return glm::normalize(getTarget() - getPos());
  }

  /// Returns the camera's CCW rotation angle around the X Euler axe.
  /** Assuming that (0,1,0) is up, angle 0 is neg Z (forwards), Pi/2 is pos Y (up) */
  virtual float getRotx() const {
    return asin(getForward().y);
  }

  /// Returns the camera's CCW rotation angle around the Y Euler axe.
  /** Assuming that (0,1,0) is up, angle 0 is pos X (right), Pi/2 is pos Z (backwards) */
  virtual float getRoty() const {
    glm::vec3 fwd = getForward();
    return atan2(fwd.z, fwd.x);
  }

  /// Returns the camera's CCW rotation angle around the Z Euler axe.
  /** Assuming that (0,1,0) is up, angle 0 is neg Z (forwards), Pi/2 is pos Y (up) */
  virtual float getRotz() const {
    return 0;
  }
};

/// A simple free-fly camera class using SFML. It's rather for testing than serious use.
/** It can be controlled with the WASD keys and the mouse */
class FreeFlyCamera : public Camera {
  /// The camera's position and the normalized forward vector
  glm::vec3 pos_, fwd_;

  /// Rotation angles(in radians) around the x and y Euler axes.
  float rotx_, roty_;

  /// Private constant numbers
  const float speed_per_sec_, max_pitch_angle_, mouse_sensitivity_;
public:
  /// Creates the free-fly camera.
  /** @param pos - The position of the camera.
    * @param target - The position of the camera's target (what it is looking at).
    * @param speed_per_sec - Move speed in OpenGL units per second
    * @param mouse_sensitivity - The relative sensitivity to mouse movement. */
  FreeFlyCamera(const glm::vec3& pos,
                const glm::vec3& target = glm::vec3(),
                float speed_per_sec = 5.0f,
                float mouse_sensitivity = 1.0f)
    : pos_(pos)
    , fwd_(glm::normalize(target - pos))
    , rotx_(asin(fwd_.y))
    , roty_(atan2(fwd_.z, fwd_.x))
    , speed_per_sec_(speed_per_sec)
    , max_pitch_angle_(85./90. * M_PI_2)
    , mouse_sensitivity_(mouse_sensitivity) {

    assert(fabs(rotx_) < max_pitch_angle_);
  }

  /// Updates the camera's position and rotation.
  /** @param window - The currently active SFML window.
    * @param fix_mouse - Specifies if the mouse should be locked into the middle of the screen. */
  void update(const sf::Window& window, bool fix_mouse = false) {
    using namespace glm;
    static sf::Clock clock;
    static float prev_time;
    float time = clock.getElapsedTime().asSeconds();
    float dt =  time - prev_time;
    prev_time = time;

    sf::Vector2i loc = sf::Mouse::getPosition(window);
    sf::Vector2i diff;
    if(fix_mouse) {
      sf::Vector2i screen_half = sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2);
      diff = loc - screen_half;
      sf::Mouse::setPosition(screen_half, window);
    } else {
      static sf::Vector2i prev_loc;
      diff = loc - prev_loc;
      prev_loc = loc;
    }

    static bool first_exec = true, last_fix_mouse = fix_mouse;
    if(first_exec || last_fix_mouse != fix_mouse) {
      first_exec = false;
      last_fix_mouse = fix_mouse;
      return;
    }

    // Mouse movement - update the coordinate system
    if(diff.x || diff.y) {
      roty_ += diff.x * mouse_sensitivity_ * 0.0035f;
      rotx_ += -diff.y * mouse_sensitivity_ * 0.0035f;

      if(fabs(rotx_) > max_pitch_angle_) {
        rotx_ = rotx_/fabs(rotx_) * max_pitch_angle_;
      }
    }

    // WASD movement
    float ds = dt * speed_per_sec_;
    fwd_ = vec3(
      cos(rotx_) * cos(roty_),
      sin(rotx_),
      cos(rotx_) * sin(roty_)
    );
    vec3 right = normalize(cross(fwd_, vec3(0.0f, 1.0f, 0.0f)));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      pos_ += fwd_ * ds;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      pos_ -= fwd_ * ds;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      pos_ += right * ds;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      pos_ -= right * ds;
    }
  }

  /// Returns the camera matrix.
  glm::mat4 cameraMatrix() const {
    return glm::lookAt(pos_, pos_ + fwd_, glm::vec3(0.0f, 1.0f, 0.0f));
  }

  /// Returns the camera's target.
  glm::vec3 getTarget() const {
    return pos_ + fwd_;
  }

  /// Returns the camera's position.
  glm::vec3 getPos() const {
    return pos_;
  }

  /// Returns the camera's CCW rotation angle around the X Euler axe.
  float getRotx() const {
    return rotx_;
  }

  /// Returns the camera's CCW rotation angle around the Y Euler axe.
  float getRoty() const {
    return roty_;
  }
}; // FreeFlyCamera


/// A simple camera class using SFML. Its position depends on an external target, usually a character.
/** It can be controlled with the WASD keys and the mouse */
class ThirdPersonalCamera : public Camera {
  // The target's position and the normalized forward vector
  glm::vec3 target_, fwd_;

  // Rotation angles(in radians) relative to the pos Z axis in the XZ and YZ planes.
  float rotx_, roty_;

  // Initial distance  between the camera and target, and the current and destination distance modifier.
  /* It's nearly a must to interpolate this, it looks very ugly without it */
  float curr_dist_mod_, dest_dist_mod_;

  // Don't interpolate at the first updateTarget call.
  bool first_call_;

  // Private constant number
  const float initial_distance_, max_pitch_angle_, mouse_sensitivity_, mouse_scroll_sensitivity_;
public:
  /// Creates the third-personal camera.
  /** @param pos - The position of the camera.
    * @param target - The position of the camera's target (what it is looking at).
    * @param mouse_sensitivity - The relative sensitivity to mouse movement.
    * @param mouse_scroll_sensitivity - The relative sensitivity to mouse scrolling. */
  ThirdPersonalCamera(const glm::vec3& pos,
                      const glm::vec3& target = glm::vec3(),
                      float mouse_sensitivity = 1.0f,
                      float mouse_scroll_sensitivity = 1.0f)
    : target_(target)
    , fwd_(glm::normalize(target - pos))
    , rotx_(asin(fwd_.y))
    , roty_(atan2(fwd_.z, fwd_.x))
    , curr_dist_mod_(1.0)
    , dest_dist_mod_(1.0)
    , first_call_(true)
    , initial_distance_(glm::length(target - pos))
    , max_pitch_angle_(60./90. * M_PI_2)
    , mouse_sensitivity_(mouse_sensitivity)
    , mouse_scroll_sensitivity_(mouse_scroll_sensitivity) {

    assert(fabs(rotx_) < max_pitch_angle_);
  }

  /// Updates the camera's position and rotation.
  /** @param window - The currently active SFML window.
    * @param fix_mouse - Specifies if the mouse should be locked into the middle of the screen. */
  void updateRotation(const sf::Window& window, bool fix_mouse = false) {
    using namespace glm;

    static sf::Clock clock;
    static float prev_time = 0;
    float time = clock.getElapsedTime().asSeconds();
    float dt =  time - prev_time;
    prev_time = time;

    sf::Vector2i loc = sf::Mouse::getPosition(window);
    sf::Vector2i diff;
    if(fix_mouse) {
      sf::Vector2i screen_half = sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2);
      diff = loc - screen_half;
      sf::Mouse::setPosition(screen_half, window);
    } else {
      static sf::Vector2i prev_loc;
      diff = loc - prev_loc;
      prev_loc = loc;
    }

    // We get invalid diff values at the startup or if fix_mouse has just changed
    static bool first_exec = true, last_fix_mouse = fix_mouse;
    if(first_exec || last_fix_mouse != fix_mouse) {
      first_exec = false;
      last_fix_mouse = fix_mouse;
      diff = sf::Vector2i(0, 0);
    }

    // Mouse movement - update the coordinate system
    if(diff.x || diff.y) {
      roty_ += diff.x * mouse_sensitivity_ * 0.0035f;
      rotx_ += -diff.y * mouse_sensitivity_ * 0.0035f;

      // Positive rotx_ is down
      if(rotx_ < -max_pitch_angle_) {
        rotx_ = -max_pitch_angle_;
      }
      if(rotx_ > 0) {
        rotx_ = 0;
      }
    }

    float dist_diff_mod = dest_dist_mod_ - curr_dist_mod_;
    if(fabs(dist_diff_mod) > dt * mouse_scroll_sensitivity_) {
      int sign = dist_diff_mod / fabs(dist_diff_mod);
      curr_dist_mod_ += sign * dt * mouse_scroll_sensitivity_;
    }

    fwd_ = (initial_distance_ * curr_dist_mod_) * vec3(
      cos(rotx_) * cos(roty_),
      sin(rotx_),
      cos(rotx_) * sin(roty_)
    );
  }

  /// Changes the distance in which the camera should follow the target.
  /** @param mouse_wheel_ticks - The number of ticks, the mouse wheel was scrolled. Expect positive on up scroll. */
  void scrolling(int mouse_wheel_ticks) {
    dest_dist_mod_ -= mouse_wheel_ticks / 5.0f * mouse_scroll_sensitivity_;
    if(dest_dist_mod_ < 0.25f) {
      dest_dist_mod_ = 0.25f;
    } else if(dest_dist_mod_ > 2.0f) {
      dest_dist_mod_ = 2.0f;
    }
  }

  /// Updates the target of the camera. Is expected to be called every frame.
  /** @param target - the position of the object the camera should follow. */
  void updateTarget(const glm::vec3& target) {
    static sf::Clock clock;
    static float prev_time = 0;
    float time = clock.getElapsedTime().asSeconds();
    float diff_time = time - prev_time;
    prev_time = time;

    while(diff_time > 0) {
      float time_step = 0.01f;
      float dt = std::min(time_step, diff_time);
      diff_time -= time_step;

      if(first_call_) {
        target_ = target;
        first_call_ = false;
        return;
      }

      target_ = glm::vec3(target.x, target_.y, target.z);

      float diff = target.y - target_.y;
      const float offs = std::max(fabs(diff / 2.0f), 0.05) * dt * 20.0f;
      if(fabs(diff) > offs) {
        target_.y += diff / fabs(diff) * offs;
      }
    }
  }

  /// Returns the camera matrix.
  glm::mat4 cameraMatrix() const {
    return glm::lookAt(target_ - fwd_, target_, glm::vec3(0, 1, 0));
  }

  /// Returns the camera's target.
  glm::vec3 getTarget() const {
    return target_;
  }

  /// Returns the camera's position.
  glm::vec3 getPos() const {
    return target_ - fwd_;
  }

  /// Returns the camera's CCW rotation angle around the X Euler axe.
  float getRotx() const {
    return rotx_;
  }

  /// Returns the camera's CCW rotation angle around the Y Euler axe.
  float getRoty() const {
    return roty_;
  }
}; // ThirdPersonalCamera

} // namespace oglwrap

#endif // OGLWRAP_UTILS_CAMERA_HPP_

