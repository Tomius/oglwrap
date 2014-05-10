#ifndef OGLWRAP_ENUMS_COMPARE_FUNC_HPP_
#define OGLWRAP_ENUMS_COMPARE_FUNC_HPP_

#include "../config.hpp"

namespace oglwrap {

inline namespace enums {

enum class CompareFunc : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
  LEqual = GL_LEQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
  GEqual = GL_GEQUAL,
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
  NotEqual = GL_NOTEQUAL,
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
