/** @file error.hpp
    @brief Contains error handling macros
*/

#ifndef ERROR_HPP
#define ERROR_HPP

#define glfunc(func) \
    func;\
    oglwrap_CheckErrorNamed(#func);

#define gl(func) glfunc(gl##func)

namespace oglwrap {

#if OGLWRAP_DEBUG

/// A global variable storing the last OpenGL error.
/** An instance of this is defined per file. */
static GLenum lastError;

/// Prints additional info in case of a specific OpenGL error.
/** Conditionally prints more information about an error if the
  * condition equals with the last error catched by oglwrap_CheckError() */
#define oglwrap_PrintError(cond, text) if(lastError == cond) {std::cout << text << std::endl;}

/// A conditional assert that only does anything if OGLWRAP_DEBUG is defined.
#define oglwrap_Assert(x) assert(x)

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
    lastError = glGetError();
    if (lastError != GL_NO_ERROR) {

        std::cerr << std::endl << " -------======{[ ";

        switch (lastError)
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

        std::cerr << " ]}======------- " << std::endl << std::endl;

        if(glfunc)
            std::cerr << "Caused by " << glfunc << std::endl;
        std::cerr << "In function: " << func << std::endl;
        std::cerr << "In file: '" << file << "'" << std::endl;
        std::cerr << "In line: " << line << std::endl;
    }
}
#else
#define oglwrap_PrintError(cond, text)
#define oglwrap_Assert(x)
#define oglwrap_CheckError()
#define oglwrap_CheckErrorNamed(glfunc)
#endif

} // namespace oglwrap

#endif // ERROR_HPP
