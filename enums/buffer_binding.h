// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_BINDING_H_
#define OGLWRAP_ENUMS_BUFFER_BINDING_H_

#include "../config.h"
#include "../debug/binding.h"
#include "buffer_type.h"

namespace oglwrap {

inline namespace enums {

enum class BufferBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER_BINDING)
  ArrayBufferBinding = GL_ARRAY_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
  AtomicCounterBufferBinding = GL_ATOMIC_COUNTER_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
  CopyReadBuffer = GL_COPY_READ_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
  CopyWriteBuffer = GL_COPY_WRITE_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER_BINDING)
  DispatchIndirectBufferBinding = GL_DISPATCH_INDIRECT_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER_BINDING)
  DrawIndirectBufferBinding = GL_DRAW_INDIRECT_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER_BINDING)
  ElementArrayBufferBinding = GL_ELEMENT_ARRAY_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER_BINDING)
  PixelPackBufferBinding = GL_PIXEL_PACK_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER_BINDING)
  PixelUnpackBufferBinding = GL_PIXEL_UNPACK_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
  ShaderStorageBufferBinding = GL_SHADER_STORAGE_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_BUFFER)
  TextureBindingBuffer = GL_TEXTURE_BINDING_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
  TransformFeedbackBufferBinding = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING)
  UniformBufferBinding = GL_UNIFORM_BUFFER_BINDING,
#endif
};

} // enums

inline BufferBinding GetBindingTarget(BufferType type) {
  BufferBinding target;

  switch (type) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER_BINDING) && defined(GL_ARRAY_BUFFER)
    case BufferType::ArrayBuffer:
      target = BufferBinding::ArrayBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_ARRAY_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING) && defined(GL_ATOMIC_COUNTER_BUFFER)
    case BufferType::AtomicCounterBuffer:
      target = BufferBinding::AtomicCounterBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_ATOMIC_COUNTER_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER) && defined(GL_COPY_READ_BUFFER)
    case BufferType::CopyReadBuffer:
      target = BufferBinding::CopyReadBuffer;
      DebugOutput::LastUsedBindTarget() = "GL_COPY_READ_BUFFER";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER) && defined(GL_COPY_WRITE_BUFFER)
    case BufferType::CopyWriteBuffer:
      target = BufferBinding::CopyWriteBuffer;
      DebugOutput::LastUsedBindTarget() = "GL_COPY_WRITE_BUFFER";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER_BINDING) && defined(GL_DISPATCH_INDIRECT_BUFFER)
    case BufferType::DispatchIndirectBuffer:
      target = BufferBinding::DispatchIndirectBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_DISPATCH_INDIRECT_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER_BINDING) && defined(GL_DRAW_INDIRECT_BUFFER)
    case BufferType::DrawIndirectBuffer:
      target = BufferBinding::DrawIndirectBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_DRAW_INDIRECT_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER_BINDING) && defined(GL_ELEMENT_ARRAY_BUFFER)
    case BufferType::ElementArrayBuffer:
      target = BufferBinding::ElementArrayBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_ELEMENT_ARRAY_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER_BINDING) && defined(GL_PIXEL_PACK_BUFFER)
    case BufferType::PixelPackBuffer:
      target = BufferBinding::PixelPackBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_PIXEL_PACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER_BINDING) && defined(GL_PIXEL_UNPACK_BUFFER)
    case BufferType::PixelUnpackBuffer:
      target = BufferBinding::PixelUnpackBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_PIXEL_UNPACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING) && defined(GL_SHADER_STORAGE_BUFFER)
    case BufferType::ShaderStorageBuffer:
      target = BufferBinding::ShaderStorageBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_SHADER_STORAGE_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_BUFFER) && defined(GL_TEXTURE_BUFFER)
    case BufferType::TextureBuffer:
      target = BufferBinding::TextureBindingBuffer;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_BUFFER";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING) && defined(GL_TRANSFORM_FEEDBACK_BUFFER)
    case BufferType::TransformFeedbackBuffer:
      target = BufferBinding::TransformFeedbackBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING) && defined(GL_UNIFORM_BUFFER)
    case BufferType::UniformBuffer:
      target = BufferBinding::UniformBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_UNIFORM_BUFFER_BINDING";
      break;
#endif
  }

 return target;
}

} // oglwrap

#endif
