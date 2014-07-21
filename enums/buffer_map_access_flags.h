// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_MAP_ACCESS_FLAGS_H_
#define OGLWRAP_ENUMS_BUFFER_MAP_ACCESS_FLAGS_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class BufferMapAccessFlags : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
  kMapReadBit = GL_MAP_READ_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
  kMapWriteBit = GL_MAP_WRITE_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
  kMapInvalidateRangeBit = GL_MAP_INVALIDATE_RANGE_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
  kMapInvalidateBufferBit = GL_MAP_INVALIDATE_BUFFER_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
  kMapFlushExplicitBit = GL_MAP_FLUSH_EXPLICIT_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
  kMapUnsynchronizedBit = GL_MAP_UNSYNCHRONIZED_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
  kMapPersistentBit = GL_MAP_PERSISTENT_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
  kMapCoherentBit = GL_MAP_COHERENT_BIT,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
