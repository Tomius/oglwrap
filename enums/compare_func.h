// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_COMPARE_FUNC_H_
#define OGLWRAP_ENUMS_COMPARE_FUNC_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class CompareFunc : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
  kLequal = GL_LEQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
  kGequal = GL_GEQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
  kLess = GL_LESS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
  kGreater = GL_GREATER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
  kEqual = GL_EQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
  kNotequal = GL_NOTEQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
  kAlways = GL_ALWAYS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
  kNever = GL_NEVER,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
