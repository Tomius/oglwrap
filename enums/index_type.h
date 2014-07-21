// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_INDEX_TYPE_H_
#define OGLWRAP_ENUMS_INDEX_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class IndexType : GLenum {
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
