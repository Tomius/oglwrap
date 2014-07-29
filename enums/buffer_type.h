// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_TYPE_H_
#define OGLWRAP_ENUMS_BUFFER_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class BufferType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
  kArrayBuffer = GL_ARRAY_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
  kAtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
  kCopyReadBuffer = GL_COPY_READ_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
  kCopyWriteBuffer = GL_COPY_WRITE_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER)
  kDispatchIndirectBuffer = GL_DISPATCH_INDIRECT_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER)
  kDrawIndirectBuffer = GL_DRAW_INDIRECT_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
  kElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER)
  kPixelPackBuffer = GL_PIXEL_PACK_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER)
  kPixelUnpackBuffer = GL_PIXEL_UNPACK_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
  kShaderStorageBuffer = GL_SHADER_STORAGE_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
  kTextureBuffer = GL_TEXTURE_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
  kTransformFeedbackBuffer = GL_TRANSFORM_FEEDBACK_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
  kUniformBuffer = GL_UNIFORM_BUFFER,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
