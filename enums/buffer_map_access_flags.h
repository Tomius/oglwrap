// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_MAP_ACCESS_FLAGS_H_
#define OGLWRAP_ENUMS_BUFFER_MAP_ACCESS_FLAGS_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class BufferMapAccessFlags : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
  MapReadBit = GL_MAP_READ_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
  MapWriteBit = GL_MAP_WRITE_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
  MapInvalidateRangeBit = GL_MAP_INVALIDATE_RANGE_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
  MapInvalidateBufferBit = GL_MAP_INVALIDATE_BUFFER_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
  MapFlushExplicitBit = GL_MAP_FLUSH_EXPLICIT_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
  MapUnsynchronizedBit = GL_MAP_UNSYNCHRONIZED_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
  MapPersistentBit = GL_MAP_PERSISTENT_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
  MapCoherentBit = GL_MAP_COHERENT_BIT,
#endif
};

} // enums

} // oglwrap

#endif
