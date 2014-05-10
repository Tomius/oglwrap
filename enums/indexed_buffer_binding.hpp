#ifndef OGLWRAP_ENUMS_INDEXED_BUFFER_BINDING_HPP_
#define OGLWRAP_ENUMS_INDEXED_BUFFER_BINDING_HPP_

#include "../config.hpp"
#include "../debug/binding.hpp"
#include "indexed_buffer_type.hpp"

namespace oglwrap {

inline namespace enums {

enum class IndexedBufferBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
  AtomicCounter = GL_ATOMIC_COUNTER_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
  ShaderStorage = GL_SHADER_STORAGE_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
  TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING)
  Uniform = GL_UNIFORM_BUFFER_BINDING,
#endif
};

} // enums

/// Returns the indexed buffer binding point's GLenum for the given buffer target.
/** @param buffer_t - The buffer target. */
inline IndexedBufferBinding GetBindingTarget(IndexedBufferType buffer_t) {
  IndexedBufferBinding target;

  switch(buffer_t) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
    case IndexedBufferType::AtomicCounter:
      target = IndexedBufferBinding::AtomicCounter;
      OGLWRAP_LAST_BIND_TARGET = "GL_ATOMIC_COUNTER_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
    case IndexedBufferType::ShaderStorage:
      target = IndexedBufferBinding::ShaderStorage;
      OGLWRAP_LAST_BIND_TARGET = "GL_SHADER_STORAGE_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
    case IndexedBufferType::TransformFeedback:
      target = IndexedBufferBinding::TransformFeedback;
      OGLWRAP_LAST_BIND_TARGET = "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING)
    case IndexedBufferType::Uniform:
      target = IndexedBufferBinding::Uniform;
      OGLWRAP_LAST_BIND_TARGET = "GL_UNIFORM_BUFFER_BINDING";
      break;
#endif
  }

  return target;
}

} // oglwrap

#endif
