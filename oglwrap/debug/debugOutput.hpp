/** @file debugOutput.hpp
    @brief Implements the oglwrap debug output.
*/

#ifndef OGLWRAP_DEBUG_DEBUGOUTPUT_HPP_
#define OGLWRAP_DEBUG_DEBUGOUTPUT_HPP_

#include "../config.hpp"

namespace oglwrap {

/// The default callback function for errors. It prints the error to stderr.
inline void default_callback(std::string error_message) {
  std::cerr << error_message << std::endl;
}

#if OGLWRAP_DEBUG

/// A global variable storing the last OpenGL error.
/** An instance of this is defined per file. */
static GLenum OGLWRAP_LAST_ERROR = GL_NO_ERROR;

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
    ErrorInfo(const std::string& funcS, const std::vector<std::string> errs[]) : funcSignature(funcS) {
      for(int i = 0; i < NUM_ERRORS + 1; i++) {
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

public:
  /// A pointer to the callback function that will be called everytime an oglwrap error happens.
  /** By default it prints to stderr, but you can assign any void(*)(std::string) type function to it.
    * Note: you can find out where the error happened inside your code, by setting a
    * breakpoint into this function, and repeatedly stepping out until you get out
    * into your code. It's INCREDIBLY useful! */
  void (*callback)(std::string);

  /// Loads in the list of OpenGL errors.
  DebugOutput() : callback(default_callback) {
    // The GLerrors.txt should be in the same folder as this file.
    // So we can use the __FILE__ macro to get the path to this file,
    // and replaces the "debugOutput.hpp" to "GLerrors.txt"
    std::string filename(OGLWRAP_GET_FILENAME());
    auto directoryPath = filename.find("debugOutput.hpp");
    assert(directoryPath != std::string::npos); // Maybe it got renamed?
    filename.erase(directoryPath, std::string::npos);
    filename.append("GLerrors.txt");

    std::ifstream is(filename);
    if(!is.good()) {
      std::cerr <<
                "Couldn't initialize DebugOutput because GLerrors.txt is missing or corrupted." << std::endl;
    }

    // Read until EOF, or until an error occurs.
    while(is.good()) {
      std::string func, funcSignature;
      std::vector<std::string> errors[NUM_ERRORS + 1];
      std::string buffer, buffer2;

      // Get lines until we find ending with );
      while(getline(is, funcSignature) && funcSignature.empty());
      {
        size_t end_pos = funcSignature.find('(');
        size_t start_pos = funcSignature.rfind(' ', end_pos) + 1;
        func = funcSignature.substr(start_pos, end_pos - start_pos);
      }

      // Get the error messages
      while(getline(is, buffer) && !buffer.empty()) {

        std::stringstream strstream(buffer);
        strstream >> buffer2;
        bool found_error = false;
        bool in_a_list = false;
        int last_err_type = NUM_ERRORS;

        for(int i = 0; i < NUM_ERRORS; i++) {
          if(buffer2 == glErrorNames[i]) {
            // Make the error string a bit nicer
            const char * possible_starts[3] = {
              " is generated if ",
              " error is generated if ",
              " may be generated if ",
            };
            for(int i = 0; i < 3; i++) {
              std::string errIsGendIf(buffer2 + possible_starts[i]);
              if(buffer.find(errIsGendIf) == 0) {
                buffer.erase(0, errIsGendIf.size() - 2);
                break;
              }
            }
            buffer[0] = '-';
            buffer[1] = ' ';
            buffer[2] = toupper(buffer[2]);
            if(buffer[buffer.find_last_not_of(' ')] == ':') {
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
        if(!found_error) {
          if(in_a_list) {
            errors[last_err_type].back() += std::string("\n") + buffer;
          } else {
            errors[ADDITIONAL_NOTES].push_back(buffer);
          }
        }
      }

      if(errorMap.find(func) == errorMap.end()) {
        errorMap.insert(std::pair<std::string, ErrorInfo>(
            func, ErrorInfo(funcSignature, errors)
        ));
      }
    }
  }

private:
  std::string formated_func_signature(std::string func_signature) {
    // Ident the function a little.
    func_signature.insert(0, "  ");
    size_t parameters_start = func_signature.find('(');

    std::string endl_plus_tabulation = std::string(parameters_start + 1, ' ');
    endl_plus_tabulation[0] = '\n';

    size_t param_pos = parameters_start;
    while((param_pos = func_signature.find(',', param_pos + 1)) != std::string::npos) {
      func_signature.insert(param_pos + 1, endl_plus_tabulation);
    }

    return func_signature;
  }

public:
  /// If there was an error, notifies you about it through the callback function.
  /** The default callback function prints the error to the stdout
    * @param functionCall - The name of the GL function that was called.
    * @param sstream - The stream to write the error */
  void print_error(const std::string& functionCall, std::stringstream& sstream) {
    size_t errIdx = getErrorIndex();
    if(errIdx == NUM_ERRORS) {
      return;
    }

    size_t funcNameLen = functionCall.find_first_of('(');
    std::string funcName = std::string(functionCall.begin(), functionCall.begin() + funcNameLen);

    if(errorMap.find(funcName) != errorMap.end() && !errorMap[funcName].errors[errIdx].empty()) {
      ErrorInfo errinfo = errorMap[funcName];
      sstream << "The following OpenGL function: " << std::endl << std::endl;
      sstream << formated_func_signature(errinfo.funcSignature) << std::endl << std::endl;
      sstream << "Has generated the error because one of the following(s) were true:" << std::endl;
      for(size_t i = 0; i != errinfo.errors[errIdx].size(); ++i) {
        sstream << errinfo.errors[errIdx][i] << std::endl;
      }
      if(errinfo.errors[ADDITIONAL_NOTES].size() != 0) {
        sstream << std::endl << "Note that: " << std::endl;
        for(size_t i = 0; i != errinfo.errors[ADDITIONAL_NOTES].size(); ++i) {
          sstream << "- " << errinfo.errors[ADDITIONAL_NOTES][i] << std::endl;
        }
      }
    }

    sstream << std::endl;
    size_t lineSize = strlen("---------========={[  ]}=========---------") +
                      strlen(glErrorNames[errIdx]);
    for(size_t i = 0; i < lineSize; i++) {
      sstream << '-';
    }
    sstream << std::endl;
  }
};

#endif // !OGLWRAP_DISABLE_DEBUG_OUTPUT
#endif // OGLWRAP_DEBUG

#if !OGLWRAP_DEBUG || OGLWRAP_DISABLE_DEBUG_OUTPUT
struct DebugOutput {
  /// A pointer to the callback function that will be called everytime an oglwrap error happens.
  /** By default it prints to stderr, but you can assign any void(*)(std::string) type function to it.
    * Note: you can find out where the error happened inside your code, by setting a
    * breakpoint into this function, and repeatedly stepping out until you get out
    * into your code. It's INCREDIBLY useful! */
  void (*callback)(std::string);

  /// Loads in the list of OpenGL errors.
  DebugOutput() : callback(default_callback) {}

  /// If there was an error, notifies you about it through the callback function.
  /** The default callback function prints the error to the stdout */
  void print_error(const std::string&, std::stringstream&) {}
};
#endif

} // namespace oglwrap

#endif // OGLWRAP_DEBUG_DEBUGOUTPUT_HPP_

