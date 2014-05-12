// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_USAGE_H_
#define OGLWRAP_ENUMS_BUFFER_USAGE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class BufferUsage : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_DRAW)
  StreamDraw = GL_STREAM_DRAW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_READ)
  StreamRead = GL_STREAM_READ,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_COPY)
  StreamCopy = GL_STREAM_COPY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_DRAW)
  StaticDraw = GL_STATIC_DRAW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_READ)
  StaticRead = GL_STATIC_READ,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_COPY)
  StaticCopy = GL_STATIC_COPY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_DRAW)
  DynamicDraw = GL_DYNAMIC_DRAW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_READ)
  DynamicRead = GL_DYNAMIC_READ,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_COPY)
  DynamicCopy = GL_DYNAMIC_COPY,
#endif
};

} // enums

} // oglwrap

#endif
