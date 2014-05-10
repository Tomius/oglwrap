#ifndef OGLWRAP_ENUMS_BUFFER_BINDING_HPP_
#define OGLWRAP_ENUMS_BUFFER_BINDING_HPP_

#include "../config.hpp"
#include "../debug/binding.hpp"
#include "buffer_type.hpp"

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

  switch(buffer_t) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER_BINDING)
    case BufferType::Array:
      target = BufferBinding::Array;
      OGLWRAP_LAST_BIND_TARGET = "GL_ARRAY_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
    case BufferType::AtomicCounter:
      target = BufferBinding::AtomicCounter;
      OGLWRAP_LAST_BIND_TARGET = "GL_ATOMIC_COUNTER_BUFFER_BINDING";
      break;
#endif

// Note: these two do not end with _BINDING
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
    case BufferType::CopyRead:
      target = BufferBinding::CopyRead;
      OGLWRAP_LAST_BIND_TARGET = "GL_COPY_READ_BUFFER";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
    case BufferType::CopyWrite:
      target = BufferBinding::CopyWrite;
      OGLWRAP_LAST_BIND_TARGET = "GL_COPY_WRITE_BUFFER";
      break;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER_BINDING)
    case BufferType::DispatchIndirect:
      target = BufferBinding::DispatchIndirect;
      OGLWRAP_LAST_BIND_TARGET = "GL_DISPATCH_INDIRECT_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER_BINDING)
    case BufferType::DrawIndirect:
      target = BufferBinding::DrawIndirect;
      OGLWRAP_LAST_BIND_TARGET = "GL_DRAW_INDIRECT_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER_BINDING)
    case BufferType::ElementArray:
      target = BufferBinding::ElementArray;
      OGLWRAP_LAST_BIND_TARGET = "GL_ELEMENT_ARRAY_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER_BINDING)
    case BufferType::PixelPack:
      target = BufferBinding::PixelPack;
      OGLWRAP_LAST_BIND_TARGET = "GL_PIXEL_PACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER_BINDING)
    case BufferType::PixelUnpack:
      target = BufferBinding::PixelUnpack;
      OGLWRAP_LAST_BIND_TARGET = "GL_PIXEL_UNPACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
    case BufferType::ShaderStorage:
      target = BufferBinding::ShaderStorage;
      OGLWRAP_LAST_BIND_TARGET = "GL_SHADER_STORAGE_BUFFER_BINDING";
      break;
#endif
      // Note: It's not BUFFER_BINDING but BINDING_BUFFER.
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_BUFFER)
    case BufferType::Texture:
      target = BufferBinding::Texture;
      OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_BUFFER";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
    case BufferType::TransformFeedback:
      target = BufferBinding::TransformFeedback;
      OGLWRAP_LAST_BIND_TARGET = "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING)
    case BufferType::Uniform:
      target = BufferBinding::Uniform;
      OGLWRAP_LAST_BIND_TARGET = "GL_UNIFORM_BUFFER_BINDING";
      break;
#endif
  }

  return target;
}

} // oglwrap

#endif
