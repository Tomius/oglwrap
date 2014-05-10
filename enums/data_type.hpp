#ifndef OGLWRAP_ENUMS_DATA_TYPE_HPP_
#define OGLWRAP_ENUMS_DATA_TYPE_HPP_

#include "../config.hpp"

namespace oglwrap {

inline namespace enums {

enum class DataType : GLenum {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BYTE)
  Byte = GL_BYTE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SHORT)
  Short = GL_SHORT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_INT)
  Int = GL_INT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FIXED)
  Fixed = GL_FIXED,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FLOAT)
  Float = GL_FLOAT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_HALF_FLOAT)
  HalfFloat = GL_HALF_FLOAT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DOUBLE)
  Double = GL_DOUBLE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_BYTE)
  UnsignedByte = GL_UNSIGNED_BYTE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_SHORT)
  UnsignedShort = GL_UNSIGNED_SHORT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_INT)
  UnsignedInt = GL_UNSIGNED_INT,
#endif
};

} // enums

} // oglwrap

#endif
