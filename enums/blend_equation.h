// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BLEND_EQUATION_H_
#define OGLWRAP_ENUMS_BLEND_EQUATION_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class BlendEquation : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_ADD)
  kFuncAdd = GL_FUNC_ADD,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_SUBTRACT)
  kFuncSubtract = GL_FUNC_SUBTRACT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_REVERSE_SUBTRACT)
  kFuncReverseSubtract = GL_FUNC_REVERSE_SUBTRACT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN)
  kMin = GL_MIN,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAX)
  kMax = GL_MAX,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
