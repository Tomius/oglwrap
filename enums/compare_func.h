// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_COMPARE_FUNC_H_
#define OGLWRAP_ENUMS_COMPARE_FUNC_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class CompareFunc : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
  Lequal = GL_LEQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
  Gequal = GL_GEQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
  Less = GL_LESS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
  Greater = GL_GREATER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
  Equal = GL_EQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
  Notequal = GL_NOTEQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
  Always = GL_ALWAYS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
  Never = GL_NEVER,
#endif
};

} // enums

} // oglwrap

#endif
