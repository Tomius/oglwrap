// Copyright (c) 2014, Tamas Csala

#include "./buffer.h"
#include "./uniform.h"
#include "./debug/debug_output.h"
#include "./debug/error_formatting.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING \
      || (defined(glGenBuffers) && defined(glDeleteBuffers))

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
  template class BufferObject<BufferType::kArrayBuffer>;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
  template class BufferObject<BufferType::kElementArrayBuffer>;
#endif

#endif  // glGenBuffers && glDeleteBuffers

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetUniformLocation)
  template class Uniform<GLint>;
  template class Uniform<glm::vec3>;
  template class Uniform<glm::vec4>;
  template class Uniform<glm::mat3>;
  template class Uniform<glm::mat4>;
  template class LazyUniform<GLint>;
  template class LazyUniform<glm::vec3>;
  template class LazyUniform<glm::vec4>;
  template class LazyUniform<glm::mat3>;
  template class LazyUniform<glm::mat4>;
#endif  // glGetUniformLocation

DebugOutput *DebugOutput::instance;
std::string *DebugOutput::last_used_bind_target;
ErrorType DebugOutput::last_error;

#if OGLWRAP_STOP_AFTER_X_ERRORS
  int OGLWRAP_ERRORS_NUM = 0;
#endif

}  // namespace oglwrap
