// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_INDEXED_BUFFER_BINDING_H_
#define OGLWRAP_ENUMS_INDEXED_BUFFER_BINDING_H_

#include "../config.h"
#include "../debug/binding.h"
#include "indexed_buffer_type.h"

namespace oglwrap {

inline namespace enums {

enum class IndexedBufferBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
  AtomicCounterBufferBinding = GL_ATOMIC_COUNTER_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
  ShaderStorageBufferBinding = GL_SHADER_STORAGE_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
  TransformFeedbackBufferBinding = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING)
  UniformBufferBinding = GL_UNIFORM_BUFFER_BINDING,
#endif
};

} // enums

inline IndexedBufferBinding GetBindingTarget(IndexedBufferType type) {
  IndexedBufferBinding target;

  switch (type) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING) && defined(GL_ATOMIC_COUNTER_BUFFER)
    case IndexedBufferType::AtomicCounterBuffer:
      target = IndexedBufferBinding::AtomicCounterBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_ATOMIC_COUNTER_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING) && defined(GL_SHADER_STORAGE_BUFFER)
    case IndexedBufferType::ShaderStorageBuffer:
      target = IndexedBufferBinding::ShaderStorageBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_SHADER_STORAGE_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING) && defined(GL_TRANSFORM_FEEDBACK_BUFFER)
    case IndexedBufferType::TransformFeedbackBuffer:
      target = IndexedBufferBinding::TransformFeedbackBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING) && defined(GL_UNIFORM_BUFFER)
    case IndexedBufferType::UniformBuffer:
      target = IndexedBufferBinding::UniformBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_UNIFORM_BUFFER_BINDING";
      break;
#endif
  }

 return target;
}

} // oglwrap

#endif
