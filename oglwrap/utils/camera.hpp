/** @file camera.hpp
    @brief Implements a basic free-fly camera to help testing. Uses SFML.
*/

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cmath>
#include <SFML/Window.hpp>

namespace oglwrap {

/// Purely virtual interface class for cameras.
class Camera {
public:
    /// Returns the camera matrix.
    virtual glm::mat4 CameraMatrix() const = 0;

    /// Returns the target's model matrix.
    virtual glm::mat4 ModelMatrix() const = 0;

    /// Returns the camera's target.
    virtual glm::vec3 getTarget() const = 0;

    /// Returns the camera's position.
    virtual glm::vec3 getPos() const = 0;
};

/// A simple free-fly camera class using SFML. It's rather for testing than serious use.
/** It can be controlled with the WASD keys and the mouse */
class FreeFlyCamera : public Camera {
    /// The camera's position and the normalized forward vector
    glm::vec3 pos, fwd;

    /// Rotation angles(in radians) relative to the pos Z axis in the XZ and YZ planes.
    float rotx, roty;

    /// Private constant numbers
    const float speedPerSec, maxPitchAngle, mouseSensitivity;
public:
    /// @brief Creates the free-fly camera.
    /// @param pos - The position of the camera.
    /// @param target - The position of the camera's target (what it is looking at).
    /// @param speedPerSec - Move speed in OpenGL units per second
    FreeFlyCamera(const glm::vec3& pos,
                  const glm::vec3& target = glm::vec3(),
                  float speedPerSec = 5.0f,
                  float mouseSensitivity = 1.0f)
        : pos(pos)
        , fwd(glm::normalize(target - pos))
        , rotx(atan2(fwd.z, fwd.x))
        , roty(asin(fwd.y))
        , speedPerSec(speedPerSec)
        , maxPitchAngle(85./90. * M_PI_2)
        , mouseSensitivity(mouseSensitivity) {

        assert(fabs(roty) < maxPitchAngle);
    }

    /// Updates the camera's position and rotation.
    /// @param window - The currently active SFML window.
    /// @param fixMouse - Specifies if the mouse should be locked into the middle of the screen.
    void Update(const sf::Window& window, bool fixMouse = false) {
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
            rotx += diff.x * mouseSensitivity * 0.0035f;
            roty += -diff.y * mouseSensitivity * 0.0035f;

            if(fabs(roty) > maxPitchAngle)
                roty = roty/fabs(roty) * maxPitchAngle;
        }

        // WASD movement
        float ds = dt * speedPerSec;
        fwd = vec3(
                  cos(roty) * cos(rotx),
                  sin(roty),
                  cos(roty) * sin(rotx)
              );
        vec3 right = normalize(cross(fwd, vec3(0.0f, 1.0f, 0.0f)));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            pos += fwd * ds;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            pos -= fwd * ds;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            pos += right * ds;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            pos -= right * ds;
    }

    /// Returns the camera matrix.
    glm::mat4 CameraMatrix() const {
        return glm::lookAt(pos, pos + fwd, glm::vec3(0.0f, 1.0f, 0.0f));
    }

    /// Returns the target's model matrix.
    glm::mat4 ModelMatrix() const {
        return glm::translate(glm::mat4(), pos + fwd);
    }

    /// Returns the camera's target.
    glm::vec3 getTarget() const {
        return pos + fwd;
    }

    /// Returns the camera's position.
    glm::vec3 getPos() const {
        return pos;
    }
}; // FreeFlyCamera


/// A simple camera class using SFML. Its position depends on an external target, usually a character.
/** It can be controlled with the WASD keys and the mouse */
class ThirdPersonalCamera : public Camera {
    /// The target's position and the normalized forward vector
    glm::vec3 target, fwd;

    /// Rotation angles(in radians) relative to the pos Z axis in the XZ and YZ planes.
    float rotx, roty, distance;

    /// a private constant number
    const float maxPitchAngle, mouseSensitivity;
public:
    /// @brief Creates the third-personal camera.
    /// @param pos - The position of the camera.
    /// @param target - The position of the camera's target (what it is looking at).
    /// @param speedPerSec - Move speed in OpenGL units per second
    ThirdPersonalCamera(const glm::vec3& pos,
                        const glm::vec3& target = glm::vec3(),
                        float mouseSensitivity = 1.0f)
        : target(pos)
        , fwd(target - pos)
        , rotx(atan2(fwd.z, fwd.x))
        , roty(asin(fwd.y))
        , distance(glm::length(fwd))
        , maxPitchAngle(75./90. * M_PI_2)
        , mouseSensitivity(mouseSensitivity) {

        assert(fabs(roty) < maxPitchAngle);
    }

    /// Updates the camera's position and rotation.
    /// @param window - The currently active SFML window.
    /// @param fixMouse - Specifies if the mouse should be locked into the middle of the screen.
    void Update(const glm::vec3& _target, const sf::Window& window, bool fixMouse = false) {
        using namespace glm;

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
            rotx += diff.x * mouseSensitivity * 0.0035f;
            roty += -diff.y * mouseSensitivity * 0.0035f;

            if(fabs(roty) > maxPitchAngle)
                roty = roty/fabs(roty) * maxPitchAngle;
        }

        // FIXME: sf::Event::MouseWheelEvent::delta
        fwd = distance * vec3(
            cos(roty) * cos(rotx),
            sin(roty),
            cos(roty) * sin(rotx)
        );

        target = _target;
    }

    /// Returns the camera matrix.
    glm::mat4 CameraMatrix() const {
        return glm::lookAt(target - fwd, target, glm::vec3(0.0f, 1.0f, 0.0f));
    }

    /// Returns the target's model matrix.
    glm::mat4 ModelMatrix() const {
        return glm::translate(glm::mat4(), target);
    }

    /// Returns the camera's target.
    glm::vec3 getTarget() const {
        return target;
    }

    /// Returns the camera's position.
    glm::vec3 getPos() const {
        return target - fwd;
    }
}; // ThirdPersonalCamera

} // namespace oglwrap

#endif // header guard
