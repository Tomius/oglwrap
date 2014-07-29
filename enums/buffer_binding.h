// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_BINDING_H_
#define OGLWRAP_ENUMS_BUFFER_BINDING_H_

#include "../config.h"
#include "../debug/debug_output.h"
#include "./buffer_type.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class BufferBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER_BINDING)
  kArrayBufferBinding = GL_ARRAY_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
  kAtomicCounterBufferBinding = GL_ATOMIC_COUNTER_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
  kCopyReadBuffer = GL_COPY_READ_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
  kCopyWriteBuffer = GL_COPY_WRITE_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER_BINDING)
  kDispatchIndirectBufferBinding = GL_DISPATCH_INDIRECT_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER_BINDING)
  kDrawIndirectBufferBinding = GL_DRAW_INDIRECT_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER_BINDING)
  kElementArrayBufferBinding = GL_ELEMENT_ARRAY_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER_BINDING)
  kPixelPackBufferBinding = GL_PIXEL_PACK_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER_BINDING)
  kPixelUnpackBufferBinding = GL_PIXEL_UNPACK_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
  kShaderStorageBufferBinding = GL_SHADER_STORAGE_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_BUFFER)
  kTextureBindingBuffer = GL_TEXTURE_BINDING_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
  kTransformFeedbackBufferBinding = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING)
  kUniformBufferBinding = GL_UNIFORM_BUFFER_BINDING,
#endif
};

}  // namespace enums
using namespace enums;
inline BufferBinding GetBindingTarget(BufferType type) {
  BufferBinding target;

  switch (type) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER_BINDING) && defined(GL_ARRAY_BUFFER)
    case BufferType::kArrayBuffer:
      target = BufferBinding::kArrayBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_ARRAY_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING) && defined(GL_ATOMIC_COUNTER_BUFFER)
    case BufferType::kAtomicCounterBuffer:
      target = BufferBinding::kAtomicCounterBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_ATOMIC_COUNTER_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER) && defined(GL_COPY_READ_BUFFER)
    case BufferType::kCopyReadBuffer:
      target = BufferBinding::kCopyReadBuffer;
      DebugOutput::LastUsedBindTarget() = "GL_COPY_READ_BUFFER";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER) && defined(GL_COPY_WRITE_BUFFER)
    case BufferType::kCopyWriteBuffer:
      target = BufferBinding::kCopyWriteBuffer;
      DebugOutput::LastUsedBindTarget() = "GL_COPY_WRITE_BUFFER";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER_BINDING) && defined(GL_DISPATCH_INDIRECT_BUFFER)
    case BufferType::kDispatchIndirectBuffer:
      target = BufferBinding::kDispatchIndirectBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_DISPATCH_INDIRECT_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER_BINDING) && defined(GL_DRAW_INDIRECT_BUFFER)
    case BufferType::kDrawIndirectBuffer:
      target = BufferBinding::kDrawIndirectBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_DRAW_INDIRECT_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER_BINDING) && defined(GL_ELEMENT_ARRAY_BUFFER)
    case BufferType::kElementArrayBuffer:
      target = BufferBinding::kElementArrayBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_ELEMENT_ARRAY_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER_BINDING) && defined(GL_PIXEL_PACK_BUFFER)
    case BufferType::kPixelPackBuffer:
      target = BufferBinding::kPixelPackBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_PIXEL_PACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER_BINDING) && defined(GL_PIXEL_UNPACK_BUFFER)
    case BufferType::kPixelUnpackBuffer:
      target = BufferBinding::kPixelUnpackBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_PIXEL_UNPACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING) && defined(GL_SHADER_STORAGE_BUFFER)
    case BufferType::kShaderStorageBuffer:
      target = BufferBinding::kShaderStorageBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_SHADER_STORAGE_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_BUFFER) && defined(GL_TEXTURE_BUFFER)
    case BufferType::kTextureBuffer:
      target = BufferBinding::kTextureBindingBuffer;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_BUFFER";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING) && defined(GL_TRANSFORM_FEEDBACK_BUFFER)
    case BufferType::kTransformFeedbackBuffer:
      target = BufferBinding::kTransformFeedbackBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING) && defined(GL_UNIFORM_BUFFER)
    case BufferType::kUniformBuffer:
      target = BufferBinding::kUniformBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_UNIFORM_BUFFER_BINDING";
      break;
#endif
  }

 return target;
}

}  // namespace oglwrap

#endif
