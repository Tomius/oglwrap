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
  Array = GL_ARRAY_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
  AtomicCounter = GL_ATOMIC_COUNTER_BUFFER_BINDING,
#endif
// Note: these two do not end with _BINDING
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
  CopyRead = GL_COPY_READ_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
  CopyWrite = GL_COPY_WRITE_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER_BINDING)
  DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER_BINDING)
  DrawIndirect = GL_DRAW_INDIRECT_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER_BINDING)
  ElementArray = GL_ELEMENT_ARRAY_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER_BINDING)
  PixelPack = GL_PIXEL_PACK_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER_BINDING)
  PixelUnpack = GL_PIXEL_UNPACK_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
  ShaderStorage = GL_SHADER_STORAGE_BUFFER_BINDING,
#endif
// Note: It's not BUFFER_BINDING but BINDING_BUFFER.
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_BUFFER)
  Texture = GL_TEXTURE_BINDING_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
  TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING)
  Uniform = GL_UNIFORM_BUFFER_BINDING,
#endif
};

} // enums


/// Returns the buffer binding point's GLenum for the given buffer target.
/** @param buffer_t - The buffer target. */
inline BufferBinding GetBindingTarget(BufferType buffer_t) {
  BufferBinding target;

  switch (buffer_t) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER_BINDING)
    case BufferType::Array:
      target = BufferBinding::Array;
      DebugOutput::LastUsedBindTarget() = "GL_ARRAY_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
    case BufferType::AtomicCounter:
      target = BufferBinding::AtomicCounter;
      DebugOutput::LastUsedBindTarget() = "GL_ATOMIC_COUNTER_BUFFER_BINDING";
      break;
#endif

// Note: these two do not end with _BINDING
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
    case BufferType::CopyRead:
      target = BufferBinding::CopyRead;
      DebugOutput::LastUsedBindTarget() = "GL_COPY_READ_BUFFER";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
    case BufferType::CopyWrite:
      target = BufferBinding::CopyWrite;
      DebugOutput::LastUsedBindTarget() = "GL_COPY_WRITE_BUFFER";
      break;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER_BINDING)
    case BufferType::DispatchIndirect:
      target = BufferBinding::DispatchIndirect;
      DebugOutput::LastUsedBindTarget() = "GL_DISPATCH_INDIRECT_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER_BINDING)
    case BufferType::DrawIndirect:
      target = BufferBinding::DrawIndirect;
      DebugOutput::LastUsedBindTarget() = "GL_DRAW_INDIRECT_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER_BINDING)
    case BufferType::ElementArray:
      target = BufferBinding::ElementArray;
      DebugOutput::LastUsedBindTarget() = "GL_ELEMENT_ARRAY_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER_BINDING)
    case BufferType::PixelPack:
      target = BufferBinding::PixelPack;
      DebugOutput::LastUsedBindTarget() = "GL_PIXEL_PACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER_BINDING)
    case BufferType::PixelUnpack:
      target = BufferBinding::PixelUnpack;
      DebugOutput::LastUsedBindTarget() = "GL_PIXEL_UNPACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
    case BufferType::ShaderStorage:
      target = BufferBinding::ShaderStorage;
      DebugOutput::LastUsedBindTarget() = "GL_SHADER_STORAGE_BUFFER_BINDING";
      break;
#endif
      // Note: It's not BUFFER_BINDING but BINDING_BUFFER.
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_BUFFER)
    case BufferType::Texture:
      target = BufferBinding::Texture;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_BUFFER";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
    case BufferType::TransformFeedback:
      target = BufferBinding::TransformFeedback;
      DebugOutput::LastUsedBindTarget() = "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING)
    case BufferType::Uniform:
      target = BufferBinding::Uniform;
      DebugOutput::LastUsedBindTarget() = "GL_UNIFORM_BUFFER_BINDING";
      break;
#endif
  }

  return target;
}

} // oglwrap

#endif
