// Copyright (c) Tamas Csala

/** @file error_checking.h
    @brief Contains error handling macros
*/

#ifndef OGLWRAP_DEBUG_ERROR_CHECKING_H_
#define OGLWRAP_DEBUG_ERROR_CHECKING_H_

#include "./debug_output.h"
#include "../context/errors.h"

namespace OGLWRAP_NAMESPACE_NAME {

#ifndef OGLWRAP_FUNCTION_MACRO
  #if __PRETTY_FUNCTION__
    #define OGLWRAP_FUNCTION_MACRO __PRETTY_FUNCTION__
  #else
    #define OGLWRAP_FUNCTION_MACRO __FUNCTION__
  #endif
#endif

#if OGLWRAP_DEBUG

#if OGLWRAP_DISABLE_DEBUG_OUTPUT
  #define OGLWRAP_CHECKED_GLFUNCTION(func) func;
#else
  #define OGLWRAP_CHECKED_GLFUNCTION(func) \
    func;\
    OGLWRAP_CHECK_ERROR_NAMED(#func);
#endif  // OGLWRAP_DISABLE_DEBUG_OUTPUT

/**
 * @brief Prints additional info in case of a specific OpenGL error.
 *
 * Conditionally prints more information about an error if the
 * condition equals with the last error catched by OGLWRAP_CHECK_ERROR()
 */
#define OGLWRAP_PRINT_IF_ERROR(cond, title, message) \
  if (DebugOutput::LastError() == cond) { \
    DebugOutput::PrintError( \
      ErrorMessage{title, message, __FILE__, OGLWRAP_FUNCTION_MACRO, __LINE__}  \
    ); \
  }

#define OGLWRAP_PRINT_ERROR(title, message) \
  DebugOutput::PrintError( \
    ErrorMessage{title, message, __FILE__, OGLWRAP_FUNCTION_MACRO, __LINE__}  \
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
  OGLWRAP_NAMESPACE_NAME::OGLWRAP_CheckError(__FILE__, OGLWRAP_FUNCTION_MACRO, __LINE__)

/**
 * @brief Same as OGLWRAP_CHECK_ERROR, but you can specify the called
 *        functions's name.
 * @see OGLWRAP_CHECK_ERROR
 */
#define OGLWRAP_CHECK_ERROR_NAMED(glfunc) \
  OGLWRAP_NAMESPACE_NAME::OGLWRAP_CheckError(__FILE__, OGLWRAP_FUNCTION_MACRO, __LINE__, glfunc)


inline void OGLWRAP_CheckError(const char *file,
                               const char *func,
                               int line,
                               const char* glfunc = "") {
  DebugOutput::LastError() = GetError();
  if (DebugOutput::LastError() != ErrorType::kNoError) {
    std::string title;

    switch (DebugOutput::LastError()) {
      case ErrorType::kInvalidEnum: title = "Invalid Enum"; break;
      case ErrorType::kInvalidValue: title = "Invalid Value"; break;
      case ErrorType::kInvalidOperation: title = "Invalid Operation"; break;
      case ErrorType::kStackOverflow: title = "Stack Overflow"; break;
      case ErrorType::kStackUnderflow: title = "Stack Underflow"; break;
      case ErrorType::kOutOfMemory: title = "Out of Memory"; break;
      case ErrorType::kInvalidFramebufferOperation: title = "Invalid Framebuffer Operation"; break;
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
  #define OGLWRAP_CHECKED_GLFUNCTION(func) func;
  #define OGLWRAP_PRINT_IF_ERROR(cond, title, message)
  #define OGLWRAP_PRINT_ERROR(title, message)
  #define OGLWRAP_PRINT_FATAL_ERROR(title, message)
  #define OGLWRAP_CHECK_ERROR()
  #define OGLWRAP_CHECK_ERROR_NAMED(glfunc)
#endif

#define OGLWRAP_CHECKED_FUNCTION(func) OGLWRAP_CHECKED_GLFUNCTION(gl##func)

} // namespace oglwrap

#endif  // OGLWRAP_DEBUG_ERROR_CHECKING_H_

