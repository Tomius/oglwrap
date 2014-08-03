// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_STORAGE_BIT_H_
#define OGLWRAP_ENUMS_BUFFER_STORAGE_BIT_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class BufferStorageBit : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_STORAGE_BIT)
  kDynamicStorageBit = GL_DYNAMIC_STORAGE_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
  kMapReadBit = GL_MAP_READ_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
  kMapWriteBit = GL_MAP_WRITE_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
  kMapPersistentBit = GL_MAP_PERSISTENT_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
  kMapCoherentBit = GL_MAP_COHERENT_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_STORAGE_BIT)
  kClientStorageBit = GL_CLIENT_STORAGE_BIT,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
