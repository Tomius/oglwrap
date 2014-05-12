// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_MAP_ACCESSS_FLAGS_H_
#define OGLWRAP_ENUMS_BUFFER_MAP_ACCESSS_FLAGS_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class BufferMapAccessFlags : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
  Read_Bit = GL_MAP_READ_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
  Write_Bit = GL_MAP_WRITE_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
  Invalidate_Range_Bit = GL_MAP_INVALIDATE_RANGE_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
  Invalidate_Buffer_Bit = GL_MAP_INVALIDATE_BUFFER_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
  Flush_Explicit_Bit = GL_MAP_FLUSH_EXPLICIT_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
  Unsynchronized_Bit = GL_MAP_UNSYNCHRONIZED_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
  Persistent_Bit = GL_MAP_PERSISTENT_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
  Coherent_Bit = GL_MAP_COHERENT_BIT,
#endif
};

} // enums

} // oglwrap

#endif
