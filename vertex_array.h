// Copyright (c) 2014, Tamas Csala

/** @file vertex_array.h
    @brief Implements a wrapper for the vertex array
*/

#ifndef OGLWRAP_VERTEX_ARRAY_H_
#define OGLWRAP_VERTEX_ARRAY_H_

#include "./config.h"
#include "./globjects.h"

#include "enums/vertex_array_type.h"
#include "enums/vertex_array_binding.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

// -------======{[ Vertex Array declaration ]}======-------

#if OGLWRAP_DEFINE_EVERYTHING \
    || (defined(glGenVertexArrays) && defined(glDeleteVertexArrays))
/**
 * @brief VAO is an object that remembers which ArrayBuffers to use for a
 *        draw call.
 *
 * A Vertex Array glObject (VAO) is an object that encapsulates all of the
 * state needed to specify vertex data. They define the format of the vertex
 * data as well as the sources for the vertex arrays. Note that VAOs do not
 * contain the arrays themselves, the arrays are stored in ArrayBuffer Objects.
 * The VAOs simply reference already existing buffer objects.
 * @see glGenVertexArrays, glDeleteVertexArrays
 */
class VertexArray {
 public:
  /// Returns the handle for the VertexArray.
  const glObject& expose() const { return vao_; }

 private:
  /// The handle for the VertexArray
  globjects::VertexArray vao_;
};
#endif  // glGenVertexArrays && glDeleteVertexArrays

}  // namespace oglwrap

#endif
