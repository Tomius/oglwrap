// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_SWIZZLE_MODE_H_
#define OGLWRAP_ENUMS_SWIZZLE_MODE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class SwizzleMode : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
  kRed = GL_RED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
  kGreen = GL_GREEN,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
  kBlue = GL_BLUE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALPHA)
  kAlpha = GL_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  kZero = GL_ZERO,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
  kOne = GL_ONE,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
