// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_COLOR_LOGIC_OPERATION_H_
#define OGLWRAP_ENUMS_COLOR_LOGIC_OPERATION_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class ColorLogicOperation : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
  kClear = GL_CLEAR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
  kSet = GL_SET,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
  kInvert = GL_INVERT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
  kNoop = GL_NOOP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
  kAnd = GL_AND,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
  kAndReverse = GL_AND_REVERSE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
  kAndInverted = GL_AND_INVERTED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
  kNand = GL_NAND,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
  kOr = GL_OR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
  kOrReverse = GL_OR_REVERSE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
  kOrInverted = GL_OR_INVERTED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
  kXor = GL_XOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
  kNor = GL_NOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
  kCopy = GL_COPY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
  kCopyInverted = GL_COPY_INVERTED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
  kEquiv = GL_EQUIV,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
