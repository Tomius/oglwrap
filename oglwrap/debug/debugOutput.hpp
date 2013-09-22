/** @file debugOutput.hpp
    @brief Implements ARB_Debug_Output
*/

#pragma once

#include "../config.hpp"

namespace oglwrap {

#if OGLWRAP_DEBUG

/// The default callback function for errors. It prints the error to stderr.
void default_callback(std::string error_message) {
    std::cerr << error_message << std::endl;
}

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
        NUM_ERRORS
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
        std::string errors[NUM_ERRORS];

        ErrorInfo() {}
        ErrorInfo(const std::string& funcS, const std::string errs[]) : funcSignature(funcS) {
            for(int i = 0; i < NUM_ERRORS; i++) {
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
        using namespace std;

        // The GLerrors.txt should be in the same folder as this file.
        // So we can use the __FILE__ macro to get the path to this file,
        // and replaces the "debugOutput.hpp" to "GLerrors.txt"
        std::string filename(OGLWRAP_GET_FILENAME());
        auto directoryPath = filename.find("debugOutput.hpp");
        assert(directoryPath != string::npos); // Maybe it got renamed?
        filename.erase(directoryPath, string::npos);
        filename.append("GLerrors.txt");

        ifstream is(filename);
        if(!is.good()){
            std::cerr <<
                "Couldn't initialize DebugOutput because GLerrors.txt is missing or corrupted." << std::endl;
        }

        // Read until EOF, or until an error occurs.
        while(is.good()) {
            string func, funcSignature, errors[NUM_ERRORS];
            string buffer, buffer2;

            // Get the first not empty row, containing the function's name
            while(getline(is, func) && func.empty());

            // Get lines until we find we ending with );
            while(getline(is, buffer)) {
                while(isspace(buffer[buffer.size() - 1])) {
                    buffer.pop_back();
                }
                funcSignature += "    " + buffer + '\n';
                if(buffer[buffer.size() - 1] == ';' && buffer[buffer.size() - 2] == ')') {
                    break;
                }
            }

            // Get the error messages
            while(getline(is, buffer) && !buffer.empty()) {

                stringstream strstream(buffer);
                strstream >> buffer2;
                for(int i = 0; i < NUM_ERRORS; i++) {
                    if(buffer2 == glErrorNames[i]) {

                        // Make the error string a bit nicer
                        string errIsGendIf(buffer2 + " is generated if ");
                        if(buffer.find(errIsGendIf) == 0) {
                            buffer.erase(0, errIsGendIf.size() - 2);
                        } else {
                            string errMayBeGendIf(buffer2 + " may be generated if ");
                            if(buffer.find(errMayBeGendIf) == 0) {
                                buffer.erase(0, errMayBeGendIf.size() - 2);
                            }
                        }
                        buffer[0] = '-';
                        buffer[1] = ' ';
                        buffer[2] = toupper(buffer[2]);

                        errors[i] += buffer + '\n';
                        break;
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

    /// If there was an error, notifies you about it through the callback function.
    /** The default callback function prints the error to the stdout
      * @param functionCall - The name of the GL function that was called.
      * @param sstream - The stream to write the error */
    void print_error(const std::string& functionCall, std::stringstream& sstream) {
        using namespace std;

        size_t errIdx = getErrorIndex();
        if(errIdx == NUM_ERRORS)
            return;

        size_t funcNameLen = functionCall.find_first_of('(');
        string funcName = string(functionCall.begin(), functionCall.begin() + funcNameLen);

        if(errorMap.find(funcName) != errorMap.end() && !errorMap[funcName].errors[errIdx].empty()) {
            ErrorInfo errinfo = errorMap[funcName];
            sstream << "The following OpenGL function: " << endl << endl;
            sstream << errinfo.funcSignature << endl;
            sstream << "Has generated the error because one of the following(s) were true:" << endl;
            sstream << errinfo.errors[errIdx];
        }

        sstream << endl;
        size_t lineSize = strlen("---------========={[  ]}=========---------") +
                          strlen(glErrorNames[errIdx]);
        for(size_t i = 0; i < lineSize; i++)
            sstream << '-';
        sstream << endl;
    }
};

#endif // !OGLWRAP_DISABLE_DEBUG_OUTPUT
#endif // OGLWRAP_DEBUG

} // namespace oglwrap

