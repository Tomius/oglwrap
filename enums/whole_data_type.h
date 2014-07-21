// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_WHOLE_DATA_TYPE_H_
#define OGLWRAP_ENUMS_WHOLE_DATA_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class WholeDataType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BYTE)
  kByte = GL_BYTE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHORT)
  kShort = GL_SHORT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INT)
  kInt = GL_INT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE)
  kUnsignedByte = GL_UNSIGNED_BYTE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT)
  kUnsignedShort = GL_UNSIGNED_SHORT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT)
  kUnsignedInt = GL_UNSIGNED_INT,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
