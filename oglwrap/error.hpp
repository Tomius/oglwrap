#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>
#include <stdexcept>
#include "config.hpp"

#ifndef OGLWRAP_DEBUG
#define OGLWRAP_DEBUG 0
#endif

#if OGLWRAP_DEBUG
#define oglwrap_CheckError() _CheckError(__FILE__, __FUNCTION__, __LINE__)
inline void _CheckError(const char *file, const char *func, int line) {
    GLenum glErr = glGetError();
    if (glErr != GL_NO_ERROR){
        switch (glErr)
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

        std::cerr << "In file: " << file << std::endl;
        std::cerr << "In function: " << func << std::endl;
        std::cerr << "In line: " << line << std::endl << std::endl;
    }
}
#else
#define oglwrap_CheckError()
#endif


#endif // ERROR_HPP
