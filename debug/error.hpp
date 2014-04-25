/** @file error.hpp
    @brief Contains error handling macros
*/

#ifndef OGLWRAP_DEBUG_ERROR_HPP_
#define OGLWRAP_DEBUG_ERROR_HPP_

#include "debugOutput.hpp"
#include "../context/errors.hpp"

namespace oglwrap {

#if OGLWRAP_INSTATIATE
  DebugOutput DebugOutput::instance;
#endif

#if OGLWRAP_DEBUG

#if OGLWRAP_DISABLE_DEBUG_OUTPUT
  #define OGLWRAP_CHECKED_GLFUNCTION(func) func;
#else
  #define OGLWRAP_CHECKED_GLFUNCTION(func) \
    func;\
    OGLWRAP_CHECK_ERROR_NAMED(#func);
#endif // OGLWRAP_DISABLE_DEBUG_OUTPUT

/**
 * @brief Prints additional info in case of a specific OpenGL error.
 *
 * Conditionally prints more information about an error if the
 * condition equals with the last error catched by OGLWRAP_CHECK_ERROR()
 */
#define OGLWRAP_PRINT_IF_ERROR(cond, title, message) \
  if(OGLWRAP_LAST_ERROR == cond) { \
    DebugOutput::PrintError( \
      ErrorMessage{title, message, __FILE__, __PRETTY_FUNCTION__, __LINE__}  \
    ); \
  }

#define OGLWRAP_PRINT_ERROR(title, message) \
  DebugOutput::PrintError( \
    ErrorMessage{title, message, __FILE__, __PRETTY_FUNCTION__, __LINE__}  \
  );

  #define OGLWRAP_PRINT_FATAL_ERROR(title, message) \
  DebugOutput::PrintError( \
    ErrorMessage{title, message, __FILE__, __PRETTY_FUNCTION__, __LINE__, "", true}  \
  );

/**
 * @brief A wrapper around glGetError, that prints file, function, line, and the
 * error in human-readable format.
 *
 * An error checking macro used for debugging purposes. If OGLWRAP_DEBUG
 * is defined to be a number different than 0, than it oglwrap will
 * check for OpenGL related errors after every gl* function call, and
 * prints out where did the error happen to stderr.
 * @see glGetError
 */
#define OGLWRAP_CHECK_ERROR() \
  oglwrap::OGLWRAP_CheckError(__FILE__, __PRETTY_FUNCTION__, __LINE__)

/**
 * @brief Same as OGLWRAP_CHECK_ERROR, but you can specify the called
 *        functions's name.
 * @see OGLWRAP_CHECK_ERROR
 */
#define OGLWRAP_CHECK_ERROR_NAMED(glfunc) \
  oglwrap::OGLWRAP_CheckError(__FILE__, __PRETTY_FUNCTION__, __LINE__, glfunc)


inline void OGLWRAP_CheckError(const char *file,
                               const char *func,
                               int line,
                               const char* glfunc = nullptr) {
  using namespace _GLError;
  OGLWRAP_LAST_ERROR = context::Errors::GetError();
  if(OGLWRAP_LAST_ERROR != NoError) {
    std::string title;

    #define OGLWRAP_CHECK_ENUM(X, Y) case X: title = Y; break;

    switch(OGLWRAP_LAST_ERROR) {
      OGLWRAP_CHECK_ENUM(InvalidEnum, "Invalid Enum")
      OGLWRAP_CHECK_ENUM(InvalidValue, "Invalid Value")
      OGLWRAP_CHECK_ENUM(InvalidOperation, "Invalid Operation")
      OGLWRAP_CHECK_ENUM(StackOverflow, "Stack Overflow")
      OGLWRAP_CHECK_ENUM(StackUnderflow, "Stack Underflow")
      OGLWRAP_CHECK_ENUM(OutOfMemory, "Out of Memory")
      OGLWRAP_CHECK_ENUM(InvalidFramebufferOperation, "Invalid Framebuffer Operation")
      OGLWRAP_CHECK_ENUM(TableTooLarge, "Table Too Large")
      default:
        break;
    };

    std::string message = DebugOutput::GetDetailedErrorInfo(glfunc);

    DebugOutput::PrintError(
      ErrorMessage{title, message, file, func, line, glfunc}
    );
  }
}
#else
  #define OGLWRAP_PRINT_ERROR(cond, text)
  #define OGLWRAP_CHECK_ERROR()
  #define OGLWRAP_CHECK_ERROR_NAMED(glfunc)
  #define OGLWRAP_CHECKED_FUNCTION(func) func;
#endif

#define OGLWRAP_CHECKED_FUNCTION(func) OGLWRAP_CHECKED_GLFUNCTION(gl##func)

} // namespace oglwrap

#endif // OGLWRAP_DEBUG_ERROR_HPP_

