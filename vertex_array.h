// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_VERTEX_ARRAY_H_
#define OGLWRAP_VERTEX_ARRAY_H_

#include "./config.h"
#include "./globjects.h"
#include "./buffer.h"

#include "enums/vertex_array_target.h"
#include "enums/vertex_array_binding.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

// -------======{[ Vertex Array declaration ]}======-------

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenVertexArrays) && defined(glDeleteVertexArrays))

struct VertexArray {
  globjects::VertexArray handle;
};

class BoundVertexArray {
 public:
  explicit BoundVertexArray(const VertexArray& vertex_array)
      : index_buffer_(0) {
    gl(GetIntegerv(GL_VERTEX_ARRAY_BINDING,
                   reinterpret_cast<GLint*>(&last_binding_)));
    gl(BindVertexArray(vertex_array.handle));
  }

  ~BoundVertexArray() {
    if (index_buffer_) {
      gl(BindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_));  // HACK
    }
    gl(BindVertexArray(last_binding_));
  }

  // No copy
  BoundVertexArray(const BoundVertexArray&) = delete;
  BoundVertexArray& operator=(const BoundVertexArray&) = delete;

  void setIndexBuffer(const IndexBuffer& index_buffer) {
    index_buffer_ = index_buffer.handle;  // HACK
  }

 private:
  GLuint last_binding_, index_buffer_;
};
#endif  // glGenVertexArrays && glDeleteVertexArrays

}  // namespace oglwrap

#endif
