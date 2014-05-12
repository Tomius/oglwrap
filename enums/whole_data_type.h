// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_WHOLE_DATA_TYPE_H_
#define OGLWRAP_ENUMS_WHOLE_DATA_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class WholeDataType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BYTE)
  Byte = GL_BYTE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHORT)
  Short = GL_SHORT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INT)
  Int = GL_INT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE)
  UnsignedByte = GL_UNSIGNED_BYTE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT)
  UnsignedShort = GL_UNSIGNED_SHORT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT)
  UnsignedInt = GL_UNSIGNED_INT,
#endif
};

} // enums

} // oglwrap

#endif
