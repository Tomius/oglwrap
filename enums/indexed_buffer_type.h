// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_INDEXED_BUFFER_TYPE_H_
#define OGLWRAP_ENUMS_INDEXED_BUFFER_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class IndexedBufferType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
  AtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
  ShaderStorageBuffer = GL_SHADER_STORAGE_BUFFER,
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
