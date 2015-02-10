// Copyright (c) 2014, Tamas Csala

/** @file error.h
    @brief Contains error message formatter utilites
*/

#ifndef OGLWRAP_DEBUG_ERROR_FORMATTING_H_
#define OGLWRAP_DEBUG_ERROR_FORMATTING_H_

#if __GLIBC__
  #include <execinfo.h>
#endif

#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

namespace OGLWRAP_NAMESPACE_NAME {

/**
 * @brief Cuts the [with: ... part of the pretty func (not quite useful with
 *        oglwrap, but looks ugly).
 */
inline std::string cut_end_of_pretty_func(const std::string& func) {
  return func.substr(0, func.find(")") + 1) + ';';
}

inline void OGLWRAP_PrintStackTrace(std::ostream& os) {
  #if __GLIBC__
    // Print stack trace
    void *array[32];
    size_t size = backtrace(array, 32);
    char** stack_trace = backtrace_symbols(array, size);

    // Check if the stack trace at least one function name
    // To do that, check if the brackets of the first entry is empty
    std::string str{stack_trace[0]};
    if (str.find('(') + 1 == str.find(')')) {
      os << "Couldn't print stack trace. "
            "Did you compile with \'-g\' and \'-rdynamic\' flags?\n\n";
    } else {
      os << "Stack trace:" << std::endl;
      // the first 6 entry in the stacktrace are just the error checking
      // functions, don't print them
      for (size_t i = 6; i < size; ++i) {
        os << stack_trace[i] << std::endl;
      }
      os << std::endl;
    }

    free(stack_trace);
#endif
}

#if OGLWRAP_STOP_AFTER_X_ERRORS
  #if OGLWRAP_INSTANTIATE
    int OGLWRAP_ERRORS_NUM = 0;
  #else
    extern int OGLWRAP_ERRORS_NUM;
  #endif
#endif

struct ErrorMessage {
  std::string title, message;
  std::string file, function;
  int line;
  std::string call_string;

  ErrorMessage(const std::string& title,
               const std::string& message,
               const std::string& file = "",
               const std::string& function = "",
               int line = -1,
               const std::string& call_string = "")
      : title(title)
      , message(message)
      , file(file)
      , function(function)
      , line(line)
      , call_string(call_string)
    { }
};

inline void OGLWRAP_PrintError(const ErrorMessage& error) {
  std::stringstream sstream;
  std::string header =
    "---------========={[ " + error.title + " ]}=========---------";
  sstream << '\n' + header + "\n\n";

  if (!error.call_string.empty()) {
    sstream << "Caused by " << error.call_string << std::endl;
  }
  sstream << "In function: " << cut_end_of_pretty_func(error.function) + '\n';
  sstream << "In '" << error.file << "' at line " << error.line << "\n\n";

  OGLWRAP_PrintStackTrace(sstream);

  sstream << error.message;

  // footer
  sstream << '\n' + std::string(header.size(), '-') + "\n\n";

  std::cerr << sstream.str() << std::endl;

  #if OGLWRAP_STOP_AFTER_X_ERRORS
    if (++OGLWRAP_ERRORS_NUM >= OGLWRAP_STOP_AFTER_X_ERRORS) {
      std::cerr <<  "\nOglwrap has encountered too many errors, stopping now.\n\n";
      std::terminate();
    }
  #endif
}

}  // namespace oglwrap

#endif
