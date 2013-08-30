/** @file debugOutput.hpp
    @brief Implements ARB_Debug_Output
*/

#ifndef DEBUGOUTPUT_HPP
#define DEBUGOUTPUT_HPP

namespace oglwrap {

#ifdef OGLWRAP_USE_OWN_DEBUG_OUTPUT
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
    /// @see glEnable, GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB, glDebugMessageCallbackARB
    static void Activate() {
        if(GLEW_ARB_debug_output) {
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
            glDebugMessageCallbackARB(DebugFunc, nullptr);
        }
    }

    /// Deactivates the debug output
    /// @see glDisable, GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB, glDebugMessageCallbackARB
    static void Deactivate() {
        if(GLEW_ARB_debug_output) {
            glDisable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
            glDebugMessageCallbackARB(nullptr, nullptr);
        }
    }
};
#else

class DebugOutput {
    enum glError_t { INVALID_ENUM, INVALID_VALUE, INVALID_OPERATION, STACK_OVERFLOW
                     ,STACK_UNDERFLOW, OUT_OF_MEMORY, INVALID_FRAMEBUFFER_OPERATION, NUM_ERRORS
                   };

    const char* glErrorNames[NUM_ERRORS] = {
        "GL_INVALID_ENUM",
        "GL_INVALID_VALUE",
        "GL_INVALID_OPERATION",
        "GL_STACK_OVERFLOW",
        "GL_STACK_UNDERFLOW",
        "GL_OUT_OF_MEMORY",
        "GL_INVALID_FRAMEBUFFER_OPERATION"
    };

    struct ErrorInfo {
        std::string funcSignature;
        std::string errors[7];
    };

    std::map<std::string, ErrorInfo> errorMap;
public:
    DebugOutput() {
        using namespace std;

        ifstream is("GLerrors.txt");
        string func, funcSignature, errors[7];
        string buffer, buffer2;
        while(is.good()) {
            getline(is, func);

            // Get lines until we find we ending with );
            while(getline(is, buffer))
                while(isspace(buffer[buffer.size() - 1])) {
                    buffer.pop_back();
                }
            funcSignature += buffer;
            if(buffer[buffer.size() - 1] != ';' || buffer[buffer.size() - 2] != ')') {
                break;
            }
        }

        while(getline(is, buffer) && !buffer.empty()) {

            stringstream strstream(buffer);
            strstream >> buffer2;
            for(int i = 0; i < 7; i++) {
                if(buffer2 == glErrorNames[i]) {
                    errors[i];
                }
            }
        }

    }
};

#endif


} // namespace oglwrap

#endif
