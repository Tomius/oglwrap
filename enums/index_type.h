#ifndef OGLWRAP_ENUMS_INDEX_DATA_TYPE_H_
#define OGLWRAP_ENUMS_INDEX_DATA_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class IndexType : GLenum {
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