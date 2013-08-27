/** @file camera.hpp
    @brief Implements a basic free-fly camera to help testing. Uses SFML.
*/

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cmath>
#include <SFML/Window.hpp>

namespace oglwrap {

/// A simple camera class using SFML. It's rather for testing than serious use.
/** It can be controlled with the WASD keys and the mouse */
class FreeFlyCamera{
    /// The target's position and the normalized forward vector
    glm::vec3 target, fwd;

    /// Rotation angles(in radians) relative to the pos Z axis in the XZ and YZ planes.
    float rotx, roty;

    /// Move speed in OpenGL units per second
    const float speedPerSec;

    /// a private constant number
    const float maxPitchAngle;
public:
    /// @brief Creates the free-fly camera.
    /// @param pos - The position of the camera.
    /// @param target - The position of the camera's target (what it is looking at).
    /// @param speedPerSec - Move speed in OpenGL units per second
    FreeFlyCamera(const glm::vec3& pos, const glm::vec3& target = glm::vec3(), float speedPerSec = 5.0f)
        : target(pos)
        , fwd(glm::normalize(target - pos))
        , rotx(atan2(fwd.z, fwd.x))
        , roty(asin(fwd.y))
        , speedPerSec(speedPerSec)
        , maxPitchAngle(85./90. * M_PI_2) {

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
            rotx += diff.x * 0.0035f;
            roty += -diff.y * 0.0035f;

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
            target += fwd * ds;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            target -= fwd * ds;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            target += right * ds;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            target -= right * ds;
    }

    /// Returns the camera matrix.
    glm::mat4 CameraMatrix() {
        return glm::lookAt(target - fwd, target, glm::vec3(0.0f, 1.0f, 0.0f));
    }

    /// Returns the target's model matrix.
    glm::mat4 ModelMatrix() {
        return glm::translate(glm::mat4(), target);
    }

    /// Returns the camera's target.
    glm::vec3 getTarget() {
        return target;
    }

    /// Returns the camera's position.
    glm::vec3 getPos() {
        return target - fwd;
    }
}; // FreeFlyCamera

} // namespace oglwrap

#endif // header guard
