// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_STENCIL_OPERATION_H_
#define OGLWRAP_ENUMS_STENCIL_OPERATION_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class StencilOperation : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
  kKeep = GL_KEEP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  kZero = GL_ZERO,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
  kReplace = GL_REPLACE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
  kIncr = GL_INCR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
  kDecr = GL_DECR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
  kInvert = GL_INVERT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
  kIncrWrap = GL_INCR_WRAP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
  kDecrWrap = GL_DECR_WRAP,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
