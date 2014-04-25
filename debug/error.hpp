/** @file error.hpp
    @brief Contains error handling macros
*/

#ifndef OGLWRAP_DEBUG_ERROR_HPP_
#define OGLWRAP_DEBUG_ERROR_HPP_

#if __GLIBC__
  #include <execinfo.h>
#endif

#include "debugOutput.hpp"

namespace oglwrap {

/// A global debug output variable.
/** It is always defined, but is only functional, if
  * OGLWRAP_DEBUG is true, and OGLWRAP_DISABLE_DEBUG_OUTPUT is false */
#if OGLWRAP_INSTATIATE_TEMPLATES
  // Yeah i know, a global variable is not a template, whatever...
  DebugOutput oglwrap_debug_output;
#else
  #if OGLWRAP_HEADER_ONLY
    static DebugOutput oglwrap_debug_output;
  #else
    extern DebugOutput oglwrap_debug_output;
  #endif
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
#define OGLWRAP_PRINT_ERROR(cond, text) \
    if(OGLWRAP_LAST_ERROR == cond) {oglwrap_debug_output.callback(text);}

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
  oglwrap::__CheckError(__FILE__, __PRETTY_FUNCTION__, __LINE__)

/**
 * @brief Same as OGLWRAP_CHECK_ERROR, but you can specify the called
 *        functions's name.
 * @see OGLWRAP_CHECK_ERROR
 */
#define OGLWRAP_CHECK_ERROR_NAMED(glfunc) \
  oglwrap::__CheckError(__FILE__, __PRETTY_FUNCTION__, __LINE__, glfunc)

/**
 * @brief Cuts the [with: ... part of the pretty func (not quite useful with
 *        oglwrap, but looks ugly).
 */
inline std::string cut_end_of_pretty_func(const std::string& func) {
  return func.substr(0, func.find(")") + 1) + ';';
}

inline void __PrintStackTrace(std::ostream& os) {
  #if __GLIBC__
    // Print stack trace
    os << "Stack trace:" << std::endl;

    void *array[32];
    size_t size = backtrace(array, 32);
    char** stack_trace = backtrace_symbols(array, size);
    for(int i = 0; i < size; ++i) {
      os << stack_trace[i] << std::endl;
    }
    free(stack_trace);
    os << std::endl;
#endif
}

#if OGLWRAP_STOP_AFTER_X_ERRORS
  #if OGLWRAP_INSTATIATE_TEMPLATES
    int OGLWRAP_ERRORS_NUM = 0;
  #else
    #if OGLWRAP_HEADER_ONLY
      static int OGLWRAP_ERRORS_NUM = 0;
    #else
      extern int OGLWRAP_ERRORS_NUM;
    #endif
  #endif
#endif

/**
 * @brief Use this via the OGLWRAP_CHECK_ERROR or OGLWRAP_CHECK_ERROR_NAMED
 *        macros.
 * @see glGetError
 */
inline void __CheckError(const char *file,
                         const char *func,
                         int line,
                         const char* glfunc = nullptr) {
  OGLWRAP_LAST_ERROR = glGetError();
  if(OGLWRAP_LAST_ERROR != GL_NO_ERROR) {
    std::stringstream sstream;

    sstream << "\n---------========={[ ";

    switch(OGLWRAP_LAST_ERROR) {
      case GL_INVALID_ENUM:
        sstream << "GL_INVALID_ENUM";
        break;
      case GL_INVALID_VALUE:
        sstream << "GL_INVALID_VALUE";
        break;
      case GL_INVALID_OPERATION:
        sstream << "GL_INVALID_OPERATION";
        break;
      case GL_STACK_OVERFLOW:
        sstream << "GL_STACK_OVERFLOW";
        break;
      case GL_STACK_UNDERFLOW:
        sstream << "GL_STACK_UNDERFLOW";
        break;
      case GL_OUT_OF_MEMORY:
        sstream << "GL_OUT_OF_MEMORY";
        break;
      case GL_INVALID_FRAMEBUFFER_OPERATION:
        sstream << "GL_INVALID_FRAMEBUFFER_OPERATION";
        break;
      case GL_TABLE_TOO_LARGE:
        sstream << "GL_TABLE_TOO_LARGE";
        break;
    };

    sstream << " ]}=========---------\n" << std::endl;

    if(glfunc) {
      sstream << "Caused by " << glfunc << std::endl;
    }
    sstream << "In function: " << cut_end_of_pretty_func(func) << std::endl;
    sstream << "In '" << file << "' at line " << line << std::endl << std::endl;

    __PrintStackTrace(sstream);

    oglwrap_debug_output.printError(glfunc, sstream);

    oglwrap_debug_output.callback(sstream.str());

    #if OGLWRAP_STOP_AFTER_X_ERRORS
      if(++OGLWRAP_ERRORS_NUM >= OGLWRAP_STOP_AFTER_X_ERRORS) {
        oglwrap_debug_output.callback(
          "\nEncountered too many errors, stopping now.\n\n"
        );
        exit(1);
      }
    #endif
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

