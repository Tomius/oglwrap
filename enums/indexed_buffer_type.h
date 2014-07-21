// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_INDEXED_BUFFER_TYPE_H_
#define OGLWRAP_ENUMS_INDEXED_BUFFER_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class IndexedBufferType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
  kAtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
  kShaderStorageBuffer = GL_SHADER_STORAGE_BUFFER,
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
