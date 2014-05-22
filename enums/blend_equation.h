// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BLEND_EQUATION_H_
#define OGLWRAP_ENUMS_BLEND_EQUATION_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class BlendEquation : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_ADD)
  FuncAdd = GL_FUNC_ADD,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_SUBTRACT)
  FuncSubtract = GL_FUNC_SUBTRACT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_REVERSE_SUBTRACT)
  FuncReverseSubtract = GL_FUNC_REVERSE_SUBTRACT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN)
  Min = GL_MIN,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAX)
  Max = GL_MAX,
#endif
};

} // enums

} // oglwrap

#endif
