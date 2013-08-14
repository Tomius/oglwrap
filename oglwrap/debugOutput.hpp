/** @file debugOutput.hpp
    @brief Implements ARB_Debug_Output
*/

#ifndef DEBUGOUTPUT_HPP
#define DEBUGOUTPUT_HPP

#include <string>
#include <iostream>
#include <GL/glew.h>

namespace oglwrap {

/// A server side debug utility that helps letting you know what went wrong.
/** It requires a debug context, which for example SFML can't create. But
    if your window loader supports it, you should definitely use this
    when you are debugging, it is really useful. */
class DebugOutput {
private:
    /// The debug callback function
    static void DebugFunc(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                            const GLchar* message, GLvoid* userParam) {
        std::string srcName;
        switch(source) {
            case GL_DEBUG_SOURCE_API_ARB:
                srcName = "API";
                break;
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB:
                srcName = "Window System";
                break;
            case GL_DEBUG_SOURCE_SHADER_COMPILER_ARB:
                srcName = "Shader Compiler";
                break;
            case GL_DEBUG_SOURCE_THIRD_PARTY_ARB:
                srcName = "Third Party";
                break;
            case GL_DEBUG_SOURCE_APPLICATION_ARB:
                srcName = "Application";
                break;
            case GL_DEBUG_SOURCE_OTHER_ARB:
                srcName = "Other";
                break;
        }

        std::string errorType;
        switch(type) {
            case GL_DEBUG_TYPE_ERROR_ARB:
                errorType = "Error";
                break;
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB:
                errorType = "Deprecated Functionality";
                break;
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB:
                errorType = "Undefined Behavior";
                break;
            case GL_DEBUG_TYPE_PORTABILITY_ARB:
                errorType = "Portability";
                break;
            case GL_DEBUG_TYPE_PERFORMANCE_ARB:
                errorType = "Performance";
                break;
            case GL_DEBUG_TYPE_OTHER_ARB:
                errorType = "Other";
                break;
        }

        std::string typeSeverity;
        switch(severity) {
            case GL_DEBUG_SEVERITY_HIGH_ARB:
                typeSeverity = "High";
                break;
            case GL_DEBUG_SEVERITY_MEDIUM_ARB:
                typeSeverity = "Medium";
                break;
            case GL_DEBUG_SEVERITY_LOW_ARB:
                typeSeverity = "Low";
                break;
        }

        std::cerr << errorType << " from " << srcName <<
            ",\t" << typeSeverity << " priority" << std::endl;
        std::cerr << "Message: " << message << std::endl;
    }
public:

    /// Activates the debug output
    static void Activate() {
        if(GLEW_ARB_debug_output)
        {
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
            glDebugMessageCallbackARB(DebugFunc, nullptr);
        }
    }

    /// Deactivates the debug output
    static void Deactivate() {
        if(GLEW_ARB_debug_output)
        {
            glDisable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
            glDebugMessageCallbackARB(nullptr, nullptr);
        }
    }
};


} // namespace oglwrap

#endif
