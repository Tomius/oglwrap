/** @file error.hpp
    @brief Contains error handling macros
*/

#pragma once

#include "debugOutput.hpp"

namespace oglwrap {

#if OGLWRAP_DEBUG

#if OGLWRAP_USE_ARB_DEBUG_OUTPUT
    #define glfunc(func) func;
#else
    static DebugOutput dbgout;

    #define glfunc(func) \
        func;\
        oglwrap_CheckErrorNamed(#func); \
        dbgout.PrintError(#func);
#endif // OGLWRAP_USE_ARB_DEBUG_OUTPUT

/// Prints additional info in case of a specific OpenGL error.
/** Conditionally prints more information about an error if the
  * condition equals with the last error catched by oglwrap_CheckError() */
#define oglwrap_PrintError(cond, text) if(OGLWRAP_LAST_ERROR == cond) {std::cout << text << std::endl;}

/// A wrapper around glGetError, that prints file, function, line, and the error in human-readable format.
/** An error checking macro used for debugging purposes. If OGLWRAP_DEBUG
  * is defined to be a number different than 0, than it oglwrap will
  * check for OpenGL related errors after every gl* function call, and
  * prints out where did the error happen to stderr. */
/// @see glGetError
#define oglwrap_CheckError() _CheckError(__FILE__, __PRETTY_FUNCTION__, __LINE__)

/// @brief Same as oglwrap_CheckError, but you can specify the called functions's name.
/// @see oglwrap_CheckError
#define oglwrap_CheckErrorNamed(glfunc) __CheckError(__FILE__, __PRETTY_FUNCTION__, __LINE__, glfunc)

/// Use this via the oglwrap_CheckError or oglwrap_CheckErrorNamed macros.
/// @see glGetError
inline void __CheckError(const char *file, const char *func, int line, const char* glfunc = nullptr) {
    OGLWRAP_LAST_ERROR = glGetError();
    if (OGLWRAP_LAST_ERROR != GL_NO_ERROR) {

        std::cerr << std::endl << "---------========={[ ";

        switch (OGLWRAP_LAST_ERROR)
        {
            case GL_INVALID_ENUM:
                std::cerr << "GL_INVALID_ENUM";
                break;
            case GL_INVALID_VALUE:
                std::cerr << "GL_INVALID_VALUE";
                break;
            case GL_INVALID_OPERATION:
                std::cerr << "GL_INVALID_OPERATION";
                break;
            case GL_STACK_OVERFLOW:
                std::cerr << "GL_STACK_OVERFLOW";
                break;
            case GL_STACK_UNDERFLOW:
                std::cerr << "GL_STACK_UNDERFLOW";
                break;
            case GL_OUT_OF_MEMORY:
                std::cerr << "GL_OUT_OF_MEMORY";
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                std::cerr << "GL_INVALID_FRAMEBUFFER_OPERATION";
                break;
        };

        std::cerr << " ]}=========---------" << std::endl << std::endl;

        if(glfunc)
            std::cerr << "Caused by " << glfunc << std::endl;
        std::cerr << "In function: " << func << std::endl;
        std::cerr << "In '" << file << "' at line " << line << std::endl << std::endl;
    }
}
#else
#define oglwrap_PrintError(cond, text)
#define oglwrap_CheckError()
#define oglwrap_CheckErrorNamed(glfunc)
#define glfunc(func) func;
#endif

#define gl(func) glfunc(gl##func)

} // namespace oglwrap
