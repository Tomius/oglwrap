// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_USAGE_H_
#define OGLWRAP_ENUMS_BUFFER_USAGE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class BufferUsage : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_DRAW)
  kStreamDraw = GL_STREAM_DRAW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_READ)
  kStreamRead = GL_STREAM_READ,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_COPY)
  kStreamCopy = GL_STREAM_COPY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_DRAW)
  kStaticDraw = GL_STATIC_DRAW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_READ)
  kStaticRead = GL_STATIC_READ,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_COPY)
  kStaticCopy = GL_STATIC_COPY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_DRAW)
  kDynamicDraw = GL_DYNAMIC_DRAW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_READ)
  kDynamicRead = GL_DYNAMIC_READ,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_COPY)
  kDynamicCopy = GL_DYNAMIC_COPY,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
