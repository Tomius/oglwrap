// Copyright (c) 2014, Tamas Csala

/** @file debug_output.h
    @brief Implements the oglwrap debug output.
*/

#ifndef OGLWRAP_DEBUG_DEBUG_OUTPUT_H_
#define OGLWRAP_DEBUG_DEBUG_OUTPUT_H_

#include <map>
#include <vector>
#include <string>
#include <utility>
#include <cassert>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <functional>

#include "../config.h"
#include "../enums/error_type.h"
#include "./error_formatting.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEBUG

#define OGLWRAP_GET_FILENAME() __FILE__

/**
 * @brief A configurable debug output that warns you if an
 *        OpenGL or a binding error happens.
 */
class DebugOutput {
  enum glError_t {
    INVALID_ENUM,
    INVALID_VALUE,
    INVALID_OPERATION,
    STACK_OVERFLOW,
    STACK_UNDERFLOW,
    OUT_OF_MEMORY,
    INVALID_FRAMEBUFFER_OPERATION,
    NUM_ERRORS,
    ADDITIONAL_NOTES = NUM_ERRORS
  };

  const char* glErrorNames[NUM_ERRORS];

  struct ErrorInfo {
    std::string func_signature;
    std::vector<std::string> errors[NUM_ERRORS + 1];

    ErrorInfo() {}
    ErrorInfo(const std::string& funcS, const std::vector<std::string> errs[])
        : func_signature(funcS) {
      for (int i = 0; i < NUM_ERRORS + 1; i++) {
        errors[i] = errs[i];
      }
    }
  };

  std::map<std::string, ErrorInfo> error_map;

  glError_t getErrorIndex() const {
    switch (GLenum(last_error)) {
      case GL_INVALID_ENUM:
        return INVALID_ENUM;
      case GL_INVALID_VALUE:
        return INVALID_VALUE;
      case GL_INVALID_OPERATION:
        return INVALID_OPERATION;
      case GL_STACK_OVERFLOW:
        return STACK_OVERFLOW;
      case GL_STACK_UNDERFLOW:
        return STACK_UNDERFLOW;
      case GL_OUT_OF_MEMORY:
        return OUT_OF_MEMORY;
      case GL_INVALID_FRAMEBUFFER_OPERATION:
        return INVALID_FRAMEBUFFER_OPERATION;
      default:
        return NUM_ERRORS;
    }
  }

  std::function<void(ErrorMessage error)> error_printer{ OGLWRAP_PrintError };

  // These static variables are dynamically allocated at the first use,
  // and that memory is never freed. See the link below to understand why:
  // http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml
  // ?showone=Static_and_Global_Variables#Static_and_Global_Variables
  static DebugOutput *instance;
  static std::string *last_used_bind_target;
  // static enum is ok, it has trivial constructor and destructor
  static ErrorType last_error;

  /// Loads in the list of OpenGL errors.
  DebugOutput() {
    glErrorNames[0] = "GL_INVALID_ENUM";
    glErrorNames[1] = "GL_INVALID_VALUE";
    glErrorNames[2] = "GL_INVALID_OPERATION";
    glErrorNames[3] = "GL_STACK_OVERFLOW";
    glErrorNames[4] = "GL_STACK_UNDERFLOW";
    glErrorNames[5] = "GL_OUT_OF_MEMORY";
    glErrorNames[6] = "GL_INVALID_FRAMEBUFFER_OPERATION";

    // The GLerrors.txt should be in the same folder as this file.
    // So we can use the __FILE__ macro to get the path (dir) of this file
    std::string filename(OGLWRAP_GET_FILENAME());
    auto dir = filename.find_last_of("/\\");
    if (dir == std::string::npos) {
      // If the path to this file has no directory in it, then
      // we should search for just "GLerrors.txt"
      filename.erase();
    } else {
      filename.erase(dir+1, std::string::npos);
    }
    filename.append("GLerrors.txt");

    std::ifstream is(filename);
    if (!is.good()) {
      std::cerr << "Couldn't initialize DebugOutput because "
                   "GLerrors.txt is missing or corrupted." << std::endl;
      return;
    }

    // Read until EOF, or until an error occurs.
    while (is.good()) {
      std::string func, func_signature;
      std::vector<std::string> errors[NUM_ERRORS + 1];
      std::string buffer, buffer2;

      // Get lines until the first one that's not empty.
      while (getline(is, func_signature) && func_signature.empty());

      size_t end_pos = func_signature.find('(');
      size_t start_pos = func_signature.rfind(' ', end_pos) + 1;
      func = func_signature.substr(start_pos, end_pos - start_pos);


      // Get the error messages
      while (getline(is, buffer) && !buffer.empty()) {
        std::stringstream strstream(buffer);
        strstream >> buffer2;
        bool found_error = false;
        bool in_a_list = false;
        int last_err_type = NUM_ERRORS;

        for (int i = 0; i < NUM_ERRORS; i++) {
          if (buffer2 == glErrorNames[i]) {
            // Make the error string a bit nicer
            const char * possible_starts[3] = {
              " is generated if ",
              " error is generated if ",
              " may be generated if ",
            };
            for (int j = 0; j < 3; j++) {
              std::string errIsGendIf(buffer2 + possible_starts[j]);
              if (buffer.find(errIsGendIf) == 0) {
                buffer.erase(0, errIsGendIf.size() - 2);
                break;
              }
            }
            buffer[0] = '-';
            buffer[1] = ' ';
            buffer[2] = toupper(buffer[2]);
            if (buffer[buffer.find_last_not_of(' ')] == ':') {
              in_a_list = true;
              last_err_type = i;
            } else {
              in_a_list = false;
            }

            errors[i].push_back(buffer);
            found_error = true;
            break;
          }
        }

        // If it wasn't an error, than it was a
        // - either a general note.
        // - or an element inside a list.
        if (!found_error) {
          if (in_a_list) {
            errors[last_err_type].back() += std::string("\n") + buffer;
          } else {
            errors[ADDITIONAL_NOTES].push_back(buffer);
          }
        }
      }

      if (error_map.find(func) == error_map.end()) {
        error_map.insert(std::pair<std::string, ErrorInfo>(
            func, ErrorInfo(func_signature, errors)));
      }
    }
  }

  static std::string FormatedFuncSignature(std::string func_signature) {
    // Ident the function a little.
    func_signature.insert(0, "  ");
    size_t parameters_start = func_signature.find('(');

    std::string endl_plus_tabulation = std::string(parameters_start + 1, ' ');
    endl_plus_tabulation[0] = '\n';

    size_t param_pos = parameters_start;
    while ((param_pos = func_signature.find(',', param_pos + 1)) !=
            std::string::npos) {
      func_signature.insert(param_pos + 1, endl_plus_tabulation);
    }

    return func_signature;
  }

 public:
  static void AddErrorPrintFormatter(std::function<void(ErrorMessage error)> printf) {
    if (!instance) {
      instance = new DebugOutput{};
    }
    instance->error_printer = printf;
  }

  static void PrintError(ErrorMessage error) {
    if (!instance) {
      instance = new DebugOutput{};
    }
    if (instance->error_printer) {
      instance->error_printer(error);
    }
  }

  /** @brief Returns detailed information about why could the error happen in
    *        the specified call.
    * @param function_call - The function call string.
    */
  static std::string GetDetailedErrorInfo(const std::string& function_call) {
    if (!instance) {
      instance = new DebugOutput{};
    }
    size_t err_idx = instance->getErrorIndex();
    if (err_idx == NUM_ERRORS) {
      return std::string{};
    }

    std::stringstream sstream;

    size_t func_name_len = function_call.find_first_of('(');
    std::string funcName =
      std::string(function_call.begin(), function_call.begin() + func_name_len);

    if (instance->error_map.find(funcName) != instance->error_map.end() &&
       !instance->error_map[funcName].errors[err_idx].empty()) {
      ErrorInfo errinfo = instance->error_map[funcName];
      sstream << "The following OpenGL function: \n\n";
      sstream << FormatedFuncSignature(errinfo.func_signature) << "\n\n";
      sstream << "Has generated the error because one of the "
                 "following(s) were true:\n";
      for (size_t i = 0; i != errinfo.errors[err_idx].size(); ++i) {
        sstream << errinfo.errors[err_idx][i] << std::endl;
      }
      if (errinfo.errors[ADDITIONAL_NOTES].size() != 0) {
        sstream << std::endl << "Note that: " << std::endl;
        for (size_t i = 0; i != errinfo.errors[ADDITIONAL_NOTES].size(); ++i) {
          sstream << "- " << errinfo.errors[ADDITIONAL_NOTES][i] << std::endl;
        }
      }
    }

    return sstream.str();
  }

  static std::string& LastUsedBindTarget() {
    if (!last_used_bind_target) {
      last_used_bind_target = new std::string{};
    }
    return *last_used_bind_target;
  }

  static ErrorType& LastError() {
    return last_error;
  }
};

#else  // !OGLWRAP_DEBUG

class DebugOutput {
  using ErrorPrintFormatter = void(const ErrorMessage& error);

 public:
  static void AddErrorPrintFormatter(
    std::function<ErrorPrintFormatter> print_formatter) {}

  static void PrintError(ErrorMessage error) {}

  /**
   * @brief If there was an error, notifies you
   *        about it through the callback function.
   *
   * The default callback function prints the error to stderr
   */
  static void GetDetailedErrorInfo(const std::string&, std::stringstream&) {}

  static std::string& LastUsedBindTarget() {
    if (!last_used_bind_target) {
      last_used_bind_target = new std::string{};
    }
    return *last_used_bind_target;
  }

  static ErrorType& LastError() {
    return last_error;
  }

 private:
  static DebugOutput *instance;
  static std::string *last_used_bind_target;
  static ErrorType last_error;
  DebugOutput() = default;
};
#endif

#if OGLWRAP_INSTANTIATE
  DebugOutput *DebugOutput::instance;
  std::string *DebugOutput::last_used_bind_target;
  ErrorType DebugOutput::last_error;
#endif

}  // namespace oglwrap

#endif  // OGLWRAP_DEBUG_DEBUGOUTPUT_H_

