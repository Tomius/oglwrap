#ifndef OGLWRAP_ENUMS_WHOLE_DATA_TYPE_HPP_
#define OGLWRAP_ENUMS_WHOLE_DATA_TYPE_HPP_

#include "../config.hpp"

namespace oglwrap {

inline namespace enums {

enum class WholeDataType : GLenum {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BYTE)
  Byte = GL_BYTE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SHORT)
  Short = GL_SHORT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_INT)
  Int = GL_INT,
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
