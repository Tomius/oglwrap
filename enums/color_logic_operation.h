// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_COLOR_LOGIC_OPERATION_H_
#define OGLWRAP_ENUMS_COLOR_LOGIC_OPERATION_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class ColorLogicOperation : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
  Clear = GL_CLEAR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
  Set = GL_SET,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
  Invert = GL_INVERT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
  Noop = GL_NOOP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
  And = GL_AND,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
  AndReverse = GL_AND_REVERSE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
  AndInverted = GL_AND_INVERTED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
  Nand = GL_NAND,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
  Or = GL_OR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
  OrReverse = GL_OR_REVERSE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
  OrInverted = GL_OR_INVERTED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
  Xor = GL_XOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
  Nor = GL_NOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
  Copy = GL_COPY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
  CopyInverted = GL_COPY_INVERTED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
  Equiv = GL_EQUIV,
#endif
};

} // enums

} // oglwrap

#endif
