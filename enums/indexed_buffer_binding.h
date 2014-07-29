// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_INDEXED_BUFFER_BINDING_H_
#define OGLWRAP_ENUMS_INDEXED_BUFFER_BINDING_H_

#include "../config.h"
#include "../debug/debug_output.h"
#include "./indexed_buffer_type.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class IndexedBufferBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
  kAtomicCounterBufferBinding = GL_ATOMIC_COUNTER_BUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
  kShaderStorageBufferBinding = GL_SHADER_STORAGE_BUFFER_BINDING,
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
inline IndexedBufferBinding GetBindingTarget(IndexedBufferType type) {
  IndexedBufferBinding target;

  switch (type) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING) && defined(GL_ATOMIC_COUNTER_BUFFER)
    case IndexedBufferType::kAtomicCounterBuffer:
      target = IndexedBufferBinding::kAtomicCounterBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_ATOMIC_COUNTER_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER_BINDING) && defined(GL_SHADER_STORAGE_BUFFER)
    case IndexedBufferType::kShaderStorageBuffer:
      target = IndexedBufferBinding::kShaderStorageBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_SHADER_STORAGE_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING) && defined(GL_TRANSFORM_FEEDBACK_BUFFER)
    case IndexedBufferType::kTransformFeedbackBuffer:
      target = IndexedBufferBinding::kTransformFeedbackBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER_BINDING) && defined(GL_UNIFORM_BUFFER)
    case IndexedBufferType::kUniformBuffer:
      target = IndexedBufferBinding::kUniformBufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_UNIFORM_BUFFER_BINDING";
      break;
#endif
  }

 return target;
}

}  // namespace oglwrap

#endif
