// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_ERROR_TYPE_H_
#define OGLWRAP_ENUMS_ERROR_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class ErrorType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
  NoError = GL_NO_ERROR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
  InvalidEnum = GL_INVALID_ENUM,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
  InvalidValue = GL_INVALID_VALUE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
  InvalidOperation = GL_INVALID_OPERATION,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
  StackOverflow = GL_STACK_OVERFLOW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
  StackUnderflow = GL_STACK_UNDERFLOW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
  OutOfMemory = GL_OUT_OF_MEMORY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
  InvalidFramebufferOperation = GL_INVALID_FRAMEBUFFER_OPERATION,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
  TableTooLarge = GL_TABLE_TOO_LARGE,
#endif
};

} // enums

} // oglwrap

#endif
