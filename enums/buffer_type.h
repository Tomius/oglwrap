// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_TYPE_H_
#define OGLWRAP_ENUMS_BUFFER_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class BufferType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
  ArrayBuffer = GL_ARRAY_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
  AtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
  CopyReadBuffer = GL_COPY_READ_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
  CopyWriteBuffer = GL_COPY_WRITE_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER)
  DispatchIndirectBuffer = GL_DISPATCH_INDIRECT_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER)
  DrawIndirectBuffer = GL_DRAW_INDIRECT_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
  ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER)
  PixelPackBuffer = GL_PIXEL_PACK_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER)
  PixelUnpackBuffer = GL_PIXEL_UNPACK_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
  ShaderStorageBuffer = GL_SHADER_STORAGE_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
  TextureBuffer = GL_TEXTURE_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
  TransformFeedbackBuffer = GL_TRANSFORM_FEEDBACK_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
  UniformBuffer = GL_UNIFORM_BUFFER,
#endif
};

} // enums

} // oglwrap

#endif
