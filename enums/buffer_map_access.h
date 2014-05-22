// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_MAP_ACCESS_H_
#define OGLWRAP_ENUMS_BUFFER_MAP_ACCESS_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class BufferMapAccess : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
  ReadOnly = GL_READ_ONLY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
  WriteOnly = GL_WRITE_ONLY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
  ReadWrite = GL_READ_WRITE,
#endif
};

} // enums

} // oglwrap

#endif
