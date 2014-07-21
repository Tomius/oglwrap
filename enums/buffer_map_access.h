// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_MAP_ACCESS_H_
#define OGLWRAP_ENUMS_BUFFER_MAP_ACCESS_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class BufferMapAccess : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
  kReadOnly = GL_READ_ONLY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
  kWriteOnly = GL_WRITE_ONLY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
  kReadWrite = GL_READ_WRITE,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
