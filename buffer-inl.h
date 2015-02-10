// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_BUFFER_INL_H_
#define OGLWRAP_BUFFER_INL_H_

#include "./buffer.h"
#include "context/binding.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING \
      || (defined(glGenBuffers) && defined(glDeleteBuffers))

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferData)
template<BufferType BUFFER_TYPE>
void BufferObject<BUFFER_TYPE>::data(GLsizei size, const void* data,
                                     BufferUsage usage) {
  OGLWRAP_CHECK_BINDING();
  if (BUFFER_TYPE == BufferType::kArrayBuffer) {
    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
  }

  gl(BufferData(GLenum(BUFFER_TYPE), size, data, GLenum(usage)));
}

template<BufferType BUFFER_TYPE>
template<typename GLtype>
void BufferObject<BUFFER_TYPE>::data(
    const std::vector<GLtype>& data, BufferUsage usage) {
  OGLWRAP_CHECK_BINDING();
  if (BUFFER_TYPE == BufferType::kArrayBuffer) {
    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
  }

  gl(BufferData(GLenum(BUFFER_TYPE), data.size() * sizeof(GLtype),
                data.data(), GLenum(usage)));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferSubData)
template<BufferType BUFFER_TYPE>
template<typename GLtype>
void BufferObject<BUFFER_TYPE>::subData(GLintptr offset, GLsizei size,
                                        const GLtype* data) {
  OGLWRAP_CHECK_BINDING();
  if (BUFFER_TYPE == BufferType::kArrayBuffer) {
    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
  }

  gl(BufferSubData(GLenum(BUFFER_TYPE), offset, size, GLenum(data)));
}

template<BufferType BUFFER_TYPE>
template<typename GLtype>
void BufferObject<BUFFER_TYPE>::subData(GLintptr offset,
                                        const std::vector<GLtype>& data) {
  OGLWRAP_CHECK_BINDING();
  if (BUFFER_TYPE == BufferType::kArrayBuffer) {
    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
  }

  gl(BufferSubData(GLenum(BUFFER_TYPE), offset,
                   data.size() * sizeof(GLtype), data.data()));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING \
    || (defined(glGetBufferParameteriv) && defined(GL_BUFFER_SIZE))
  template<BufferType BUFFER_TYPE>
  size_t BufferObject<BUFFER_TYPE>::size() const {
    OGLWRAP_CHECK_BINDING();
    GLint size;
    gl(GetBufferParameteriv(GLenum(BUFFER_TYPE), GL_BUFFER_SIZE, &size));
    return size;
  }
#endif  // glGetBufferParameteriv && GL_BUFFER_SIZE

#if OGLWRAP_DEFINE_EVERYTHING || (defined(glMapBuffer) \
     && defined(glUnmapBuffer) && defined(glMapBufferRange))

template<BufferType BUFFER_TYPE>
template <class T>
BufferObject<BUFFER_TYPE>::TypedMap<T>::TypedMap(BufferMapAccess access) {
  OGLWRAP_CHECK_FOR_DEFAULT_BINDING(GLenum(GetBindingTarget(BUFFER_TYPE)));
  data_ = gl(MapBuffer(GLenum(BUFFER_TYPE), GLenum(access)));
  gl(GetBufferParameteriv(GLenum(BUFFER_TYPE), GL_BUFFER_SIZE, (GLint*)&size_));
}

template<BufferType BUFFER_TYPE>
template <class T>
BufferObject<BUFFER_TYPE>::TypedMap<T>::TypedMap(
    GLintptr offset, GLsizeiptr length, Bitfield<BufferMapAccessFlags> access) {
  OGLWRAP_CHECK_FOR_DEFAULT_BINDING(GLenum(GetBindingTarget(BUFFER_TYPE)));
  data_ = gl(MapBufferRange(GLenum(BUFFER_TYPE), offset, length, access));
  gl(GetBufferParameteriv(GLenum(BUFFER_TYPE), GL_BUFFER_SIZE, (GLint*)&size_));
}

template<BufferType BUFFER_TYPE>
template <class T>
BufferObject<BUFFER_TYPE>::TypedMap<T>::~TypedMap() {
  OGLWRAP_CHECK_FOR_DEFAULT_BINDING(GLenum(GetBindingTarget(BUFFER_TYPE)));
  gl(UnmapBuffer(GLenum(BUFFER_TYPE)));
}

#endif  // glMapBuffer && glUnmapBuffer && glMapBufferRange

#endif

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif
