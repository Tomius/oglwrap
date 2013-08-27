/** @file error.hpp
    @brief Contains error handling macros
*/

#ifndef ERROR_HPP
#define ERROR_HPP

#define oglfunc(func) \
    func;\
    oglwrap_CheckError();

#define gl(func) \
    gl##func;\
    oglwrap_CheckError();

#if OGLWRAP_DEBUG
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
#define oglwrap_CheckError() _CheckError(__FILE__, __FUNCTION__, __LINE__)
inline void _CheckError(const char *file, const char *func, int line) {
    lastError = glGetError();
    if (lastError != GL_NO_ERROR) {
        switch (lastError)
        {
            case GL_INVALID_ENUM:
                std::cerr << "GL_INVALID_ENUM" << std::endl;
                break;
            case GL_INVALID_VALUE:
                std::cerr << "GL_INVALID_VALUE" << std::endl;
                break;
            case GL_INVALID_OPERATION:
                std::cerr << "GL_INVALID_OPERATION" << std::endl;
                break;
            case GL_STACK_OVERFLOW:
                std::cerr << "GL_STACK_OVERFLOW" << std::endl;
                break;
            case GL_STACK_UNDERFLOW:
                std::cerr << "GL_STACK_UNDERFLOW" << std::endl;
                break;
            case GL_OUT_OF_MEMORY:
                std::cerr << "GL_OUT_OF_MEMORY" << std::endl;
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                std::cerr << "GL_INVALID_FRAMEBUFFER_OPERATION" << std::endl;
                break;
        };

        std::cerr << "In function: " << func << std::endl;
        std::cerr << "In file: " << file << std::endl;
        std::cerr << "In line: " << line << std::endl;
    }
}
#else
#define oglwrap_PrintError(cond, text)
#define oglwrap_Assert(x)
#define oglwrap_CheckError()
#endif

#if OGLWRAP_DEBUG_FULL
/// An error checker to catch errors that happened outside oglwrap.
/** An error checker that can be called at the entry of the every function.
  * It helps to differentiate errors generated by oglwarp code and user written code. */
#define oglwrap_PreCheckError() _PreCheckError(__FILE__, __FUNCTION__, __LINE__)
inline void _PreCheckError(const char *file, const char *func, int line) {
    lastError = glGetError();
    if (lastError != GL_NO_ERROR) {
        switch (lastError)
        {
            case GL_INVALID_ENUM:
                std::cerr << "GL_INVALID_ENUM" << std::endl;
                break;
            case GL_INVALID_VALUE:
                std::cerr << "GL_INVALID_VALUE" << std::endl;
                break;
            case GL_INVALID_OPERATION:
                std::cerr << "GL_INVALID_OPERATION" << std::endl;
                break;
            case GL_STACK_OVERFLOW:
                std::cerr << "GL_STACK_OVERFLOW" << std::endl;
                break;
            case GL_STACK_UNDERFLOW:
                std::cerr << "GL_STACK_UNDERFLOW" << std::endl;
                break;
            case GL_OUT_OF_MEMORY:
                std::cerr << "GL_OUT_OF_MEMORY" << std::endl;
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                std::cerr << "GL_INVALID_FRAMEBUFFER_OPERATION" << std::endl;
                break;
        };
        std::cerr << "Happened BEFORE calling function: " << func << std::endl;
        std::cerr << "In file: " << file << std::endl;
        std::cerr << "In line: " << line << std::endl;
    }
}
#else
#define oglwrap_PreCheckError()
#endif // OGLWRAP_DEBUG_FULL

#endif // ERROR_HPP
