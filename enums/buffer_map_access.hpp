#ifndef OGLWRAP_ENUMS_BUFFER_MAP_ACCESSS_HPP_
#define OGLWRAP_ENUMS_BUFFER_MAP_ACCESSS_HPP_

#include "../config.hpp"

namespace oglwrap {

inline namespace enums {

enum class BufferMapAccess : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
  Read = GL_READ_ONLY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
  Write = GL_WRITE_ONLY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
  ReadWrite = GL_READ_WRITE,
#endif
};

} // enums

} // oglwrap

#endif
