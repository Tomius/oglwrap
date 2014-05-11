#ifndef OGLWRAP_ENUMS_INDEXED_BUFFER_TYPE_H_
#define OGLWRAP_ENUMS_INDEXED_BUFFER_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class IndexedBufferType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
  AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
  ShaderStorage = GL_SHADER_STORAGE_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
  TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
  Uniform = GL_UNIFORM_BUFFER,
#endif
};

} // enums

} // oglwrap

#endif
