/** @file debug_output.h
    @brief Implements the oglwrap debug output.
*/

#ifndef OGLWRAP_DEBUG_DEBUG_OUTPUT_H_
#define OGLWRAP_DEBUG_DEBUG_OUTPUT_H_

#include <map>
#include <vector>
#include <cassert>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <functional>

#include "../config.h"
#include "../enums.h"
#include "error_formatting.h"

namespace oglwrap {

#if OGLWRAP_DEBUG

/// A global variable storing the last OpenGL error.
#if OGLWRAP_INSTATIATE
  GLError OGLWRAP_LAST_ERROR = GLError::NoError;
#else
  extern GLError OGLWRAP_LAST_ERROR;
#endif


#if !OGLWRAP_DISABLE_DEBUG_OUTPUT
#define OGLWRAP_GET_FILENAME() __FILE__

/// A configurable debug output that warns you if an OpenGL or a binding error happens.
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
    std::vector<std::string> errors[NUM_ERRORS + 1];

    ErrorInfo() {}
    ErrorInfo(const std::string& funcS, const std::vector<std::string> errs[])
        : funcSignature(funcS) {
      for (int i = 0; i < NUM_ERRORS + 1; i++) {
        errors[i] = errs[i];
      }
    }
  };

  std::map<std::string, ErrorInfo> errorMap;

  glError_t getErrorIndex() const {
    switch(OGLWRAP_LAST_ERROR) {
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


  using ErrorPrintFormatter = void(ErrorMessage error);
  std::function<ErrorPrintFormatter> error_printer{OGLWRAP_PrintError};

  // The instance for this is dynamically allocated at the first use,
  // and that memory is never freed. See the link below to understand why:
  // http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml
  // ?showone=Static_and_Global_Variables#Static_and_Global_Variables
  static DebugOutput* instance;
  static bool inited;


  /// Loads in the list of OpenGL errors.
  DebugOutput() {
    // The GLerrors.txt should be in the same folder as this file.
    // So we can use the __FILE__ macro to get the path to this file,
    // and replaces the "debug_output.h" to "GLerrors.txt"
    std::string filename(OGLWRAP_GET_FILENAME());
    auto directoryPath = filename.find("debug_output.h");
    assert(directoryPath != std::string::npos); // Maybe it got renamed?
    filename.erase(directoryPath, std::string::npos);
    filename.append("GLerrors.txt");

    std::ifstream is(filename);
    if (!is.good()) {
      std::cerr <<
        "Couldn't initialize DebugOutput because "
        "GLerrors.txt is missing or corrupted." << std::endl;
    }

    // Read until EOF, or until an error occurs.
    while(is.good()) {
      std::string func, funcSignature;
      std::vector<std::string> errors[NUM_ERRORS + 1];
      std::string buffer, buffer2;

      // Get lines until the first one that's not empty.
      while(getline(is, funcSignature) && funcSignature.empty());

      size_t end_pos = funcSignature.find('(');
      size_t start_pos = funcSignature.rfind(' ', end_pos) + 1;
      func = funcSignature.substr(start_pos, end_pos - start_pos);


      // Get the error messages
      while(getline(is, buffer) && !buffer.empty()) {

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

      if (errorMap.find(func) == errorMap.end()) {
        errorMap.insert(std::pair<std::string, ErrorInfo>(
            func, ErrorInfo(funcSignature, errors)
        ));
      }
    }
  }

  static std::string formatedFuncSignature(std::string funcSignature) {
    // Ident the function a little.
    funcSignature.insert(0, "  ");
    size_t parameters_start = funcSignature.find('(');

    std::string endl_plus_tabulation = std::string(parameters_start + 1, ' ');
    endl_plus_tabulation[0] = '\n';

    size_t param_pos = parameters_start;
    while((param_pos = funcSignature.find(',', param_pos + 1)) != std::string::npos) {
      funcSignature.insert(param_pos + 1, endl_plus_tabulation);
    }

    return funcSignature;
  }

public:
  static void AddErrorPrintFormatter(std::function<ErrorPrintFormatter> printf) {
    if (!inited) {
      instance = new DebugOutput{};
      inited = true;
    }
    instance->error_printer = printf;
  }

  static void PrintError(ErrorMessage error) {
    if (!inited) {
      instance = new DebugOutput{};
      inited = true;
    }
    if (instance->error_printer) {
      instance->error_printer(error);
    }
  }

  /** @brief Returns detailed information about why could the error happen in
    *        the specified call.
    * @param functionCall - The function call string.
    */
  static std::string GetDetailedErrorInfo(const std::string& functionCall) {
    if (!inited) {
      instance = new DebugOutput{};
      inited = true;
    }
    size_t errIdx = instance->getErrorIndex();
    if (errIdx == NUM_ERRORS) {
      return std::string{};
    }

    std::stringstream sstream;

    size_t funcNameLen = functionCall.find_first_of('(');
    std::string funcName = std::string(functionCall.begin(), functionCall.begin() + funcNameLen);

    if (instance->errorMap.find(funcName) != instance->errorMap.end() &&
       !instance->errorMap[funcName].errors[errIdx].empty()) {
      ErrorInfo errinfo = instance->errorMap[funcName];
      sstream << "The following OpenGL function: " << std::endl << std::endl;
      sstream << formatedFuncSignature(errinfo.funcSignature) << std::endl << std::endl;
      sstream << "Has generated the error because one of the following(s) were true:" << std::endl;
      for (size_t i = 0; i != errinfo.errors[errIdx].size(); ++i) {
        sstream << errinfo.errors[errIdx][i] << std::endl;
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
};

#endif // !OGLWRAP_DISABLE_DEBUG_OUTPUT
#endif // OGLWRAP_DEBUG

#if !OGLWRAP_DEBUG || OGLWRAP_DISABLE_DEBUG_OUTPUT
class DebugOutput {
  using ErrorPrintFormatter = void(const ErrorMessage& error);

  static DebugOutput* instance;
  static bool inited;

  // Loads in the list of OpenGL errors.
  DebugOutput() : printError(OGLWRAP_PrintError) {}
public:

  static void AddErrorPrintFormatter(
    std::function<ErrorPrintFormatter> printFormatter) {}

  static void PrintError(ErrorMessage error) {}

  /// If there was an error, notifies you about it through the callback function.
  /** The default callback function prints the error to the stdout */
  static void GetDetailedErrorInfo(const std::string&, std::stringstream&) {}
};
#endif

} // namespace oglwrap

#endif // OGLWRAP_DEBUG_DEBUGOUTPUT_H_

