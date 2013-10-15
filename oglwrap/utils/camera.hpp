/** @file camera.hpp
    @brief Implements a basic free-fly camera to help testing. Uses SFML.
*/

#ifndef OGLWRAP_UTILS_CAMERA_HPP_
#define OGLWRAP_UTILS_CAMERA_HPP_

#include <cmath>
#include <SFML/Window.hpp>

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
  glm::vec3 pos, fwd;

  /// Rotation angles(in radians) around the x and y Euler axes.
  float rotx, roty;

  /// Private constant numbers
  const float speedPerSec, maxPitchAngle, mouseSensitivity;
public:
  /// Creates the free-fly camera.
  /** @param pos - The position of the camera.
    * @param target - The position of the camera's target (what it is looking at).
    * @param speedPerSec - Move speed in OpenGL units per second
    * @param mouseSensitivity - The relative sensitivity to mouse movement. */
  FreeFlyCamera(const glm::vec3& pos,
                const glm::vec3& target = glm::vec3(),
                float speedPerSec = 5.0f,
                float mouseSensitivity = 1.0f)
    : pos(pos)
    , fwd(glm::normalize(target - pos))
    , rotx(asin(fwd.y))
    , roty(atan2(fwd.z, fwd.x))
    , speedPerSec(speedPerSec)
    , maxPitchAngle(85./90. * M_PI_2)
    , mouseSensitivity(mouseSensitivity) {

    assert(fabs(rotx) < maxPitchAngle);
  }

  /// Updates the camera's position and rotation.
  /** @param window - The currently active SFML window.
    * @param fixMouse - Specifies if the mouse should be locked into the middle of the screen. */
  void update(const sf::Window& window, bool fixMouse = false) {
    using namespace glm;
    static sf::Clock clock;
    static float prevTime;
    float time = clock.getElapsedTime().asSeconds();
    float dt =  time - prevTime;
    prevTime = time;

    sf::Vector2i loc = sf::Mouse::getPosition(window);
    sf::Vector2i diff;
    if(fixMouse) {
      sf::Vector2i screenHalf = sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2);
      diff = loc - screenHalf;
      sf::Mouse::setPosition(screenHalf, window);
    } else {
      static sf::Vector2i prevLoc;
      diff = loc - prevLoc;
      prevLoc = loc;
    }

    static bool firstExec = true, lastFixMouse = fixMouse;
    if(firstExec || lastFixMouse != fixMouse) {
      firstExec = false;
      lastFixMouse = fixMouse;
      return;
    }

    // Mouse movement - update the coordinate system
    if(diff.x || diff.y) {
      roty += diff.x * mouseSensitivity * 0.0035f;
      rotx += -diff.y * mouseSensitivity * 0.0035f;

      if(fabs(rotx) > maxPitchAngle) {
        rotx = rotx/fabs(rotx) * maxPitchAngle;
      }
    }

    // WASD movement
    float ds = dt * speedPerSec;
    fwd = vec3(
            cos(rotx) * cos(roty),
            sin(rotx),
            cos(rotx) * sin(roty)
          );
    vec3 right = normalize(cross(fwd, vec3(0.0f, 1.0f, 0.0f)));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      pos += fwd * ds;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      pos -= fwd * ds;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      pos += right * ds;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      pos -= right * ds;
    }
  }

  /// Returns the camera matrix.
  glm::mat4 cameraMatrix() const {
    return glm::lookAt(pos, pos + fwd, glm::vec3(0.0f, 1.0f, 0.0f));
  }

  /// Returns the camera's target.
  glm::vec3 getTarget() const {
    return pos + fwd;
  }

  /// Returns the camera's position.
  glm::vec3 getPos() const {
    return pos;
  }

  /// Returns the camera's CCW rotation angle around the X Euler axe.
  float getRotx() const {
    return rotx;
  }

  /// Returns the camera's CCW rotation angle around the Y Euler axe.
  float getRoty() const {
    return roty;
  }
}; // FreeFlyCamera


/// A simple camera class using SFML. Its position depends on an external target, usually a character.
/** It can be controlled with the WASD keys and the mouse */
class ThirdPersonalCamera : public Camera {
  // The target's position and the normalized forward vector
  glm::vec3 target, fwd;

  // Rotation angles(in radians) relative to the pos Z axis in the XZ and YZ planes.
  float rotx, roty;

  // Initial distance  between the camera and target, and the current and destination distance modifier.
  /* It's nearly a must to interpolate this, it looks very ugly without it */
  float currDistMod, destDistMod;

  // Don't interpolate at the first updateTarget call.
  bool firstCall;

  // Private constant number
  const float initialDistance, maxPitchAngle, mouseSensitivity, mouseScrollSensitivity;
public:
  /// Creates the third-personal camera.
  /** @param pos - The position of the camera.
    * @param target - The position of the camera's target (what it is looking at).
    * @param mouseSensitivity - The relative sensitivity to mouse movement.
    * @param mouseScrollSensitivity - The relative sensitivity to mouse scrolling. */
  ThirdPersonalCamera(const glm::vec3& pos,
                      const glm::vec3& target = glm::vec3(),
                      float mouseSensitivity = 1.0f,
                      float mouseScrollSensitivity = 1.0f)
    : target(pos)
    , fwd(glm::normalize(target - pos))
    , rotx(asin(fwd.y))
    , roty(atan2(fwd.z, fwd.x))
    , currDistMod(1.0)
    , destDistMod(1.0)
    , firstCall(true)
    , initialDistance(glm::length(target - pos))
    , maxPitchAngle(60./90. * M_PI_2)
    , mouseSensitivity(mouseSensitivity)
    , mouseScrollSensitivity(mouseScrollSensitivity) {

    assert(fabs(rotx) < maxPitchAngle);
  }

  /// Updates the camera's position and rotation.
  /** @param window - The currently active SFML window.
    * @param fixMouse - Specifies if the mouse should be locked into the middle of the screen. */
  void updateRotation(const sf::Window& window, bool fixMouse = false) {
    using namespace glm;

    static sf::Clock clock;
    static float prevTime = 0;
    float time = clock.getElapsedTime().asSeconds();
    float dt =  time - prevTime;
    prevTime = time;

    sf::Vector2i loc = sf::Mouse::getPosition(window);
    sf::Vector2i diff;
    if(fixMouse) {
      sf::Vector2i screenHalf = sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2);
      diff = loc - screenHalf;
      sf::Mouse::setPosition(screenHalf, window);
    } else {
      static sf::Vector2i prevLoc;
      diff = loc - prevLoc;
      prevLoc = loc;
    }

    // We get invalid diff values at the startup or if fixMouse has just changed
    static bool firstExec = true, lastFixMouse = fixMouse;
    if(firstExec || lastFixMouse != fixMouse) {
      firstExec = false;
      lastFixMouse = fixMouse;
      diff = sf::Vector2i(0, 0);
    }

    // Mouse movement - update the coordinate system
    if(diff.x || diff.y) {
      roty += diff.x * mouseSensitivity * 0.0035f;
      rotx += -diff.y * mouseSensitivity * 0.0035f;

      // Positive rotx is down
      if(rotx < -maxPitchAngle) {
        rotx = -maxPitchAngle;
      }
      if(rotx > 0) {
        rotx = 0;
      }
    }

    float distDiffMod = destDistMod - currDistMod;
    if(fabs(distDiffMod) > dt * mouseScrollSensitivity) {
      int sign = distDiffMod / fabs(distDiffMod);
      currDistMod += sign * dt * mouseScrollSensitivity;
    }

    fwd = (initialDistance * currDistMod) * vec3(
            cos(rotx) * cos(roty),
            sin(rotx),
            cos(rotx) * sin(roty)
          );
  }

  /// Changes the distance in which the camera should follow the target.
  /** @param mouseWheelTicks - The number of ticks, the mouse wheel was scrolled. Expect positive on up scroll. */
  void scrolling(int mouseWheelTicks) {
    destDistMod -= mouseWheelTicks / 5.0f * mouseScrollSensitivity;
    if(destDistMod < 0.25f) {
      destDistMod = 0.25f;
    } else if(destDistMod > 2.0f) {
      destDistMod = 2.0f;
    }
  }

  /// Updates the target of the camera. Is expected to be called every frame.
  /** @param _target - the position of the object the camera should follow. */
  void updateTarget(const glm::vec3& _target) {
    static sf::Clock clock;
    static float prevTime = 0;
    float time = clock.getElapsedTime().asSeconds();
    float dt =  time - prevTime;
    prevTime = time;

    if(firstCall) {
      target = _target;
      firstCall = false;
      return;
    }

    target = glm::vec3(_target.x, target.y, _target.z);

    float diff = _target.y - target.y;
    const float offs = std::max(fabs(diff / 2.0f), 0.05) * dt * 20.0f;
    if(fabs(diff) > offs) {
      target.y += diff / fabs(diff) * offs;
    }
  }

  /// Returns the camera matrix.
  glm::mat4 cameraMatrix() const {
    return glm::lookAt(target - fwd, target, glm::vec3(0, 1, 0));
  }

  /// Returns the camera's target.
  glm::vec3 getTarget() const {
    return target;
  }

  /// Returns the camera's position.
  glm::vec3 getPos() const {
    return target - fwd;
  }

  /// Returns the camera's CCW rotation angle around the X Euler axe.
  float getRotx() const {
    return rotx;
  }

  /// Returns the camera's CCW rotation angle around the Y Euler axe.
  float getRoty() const {
    return roty;
  }
}; // ThirdPersonalCamera

} // namespace oglwrap

#endif // OGLWRAP_UTILS_CAMERA_HPP_

