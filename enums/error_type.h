// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_ERROR_TYPE_H_
#define OGLWRAP_ENUMS_ERROR_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class ErrorType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
  kNoError = GL_NO_ERROR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
  kInvalidEnum = GL_INVALID_ENUM,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
  kInvalidValue = GL_INVALID_VALUE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
  kInvalidOperation = GL_INVALID_OPERATION,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
  kStackOverflow = GL_STACK_OVERFLOW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
  kStackUnderflow = GL_STACK_UNDERFLOW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
  kOutOfMemory = GL_OUT_OF_MEMORY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
  kInvalidFramebufferOperation = GL_INVALID_FRAMEBUFFER_OPERATION,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
  kTableTooLarge = GL_TABLE_TOO_LARGE,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
