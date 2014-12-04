// Copyright (c) 2014, Tamas Csala

/** @file buffer.h
    @brief Implements wrappers around OpenGL Buffer glObject.
*/

#ifndef OGLWRAP_BUFFER_H_
#define OGLWRAP_BUFFER_H_

#include <vector>

#include "enums/buffer_type.h"
#include "enums/buffer_binding.h"
#include "enums/indexed_buffer_type.h"
#include "enums/indexed_buffer_binding.h"
#include "enums/buffer_usage.h"
#include "enums/buffer_map_access.h"
#include "enums/buffer_map_access_flags.h"

#include "./config.h"
#include "./globjects.h"
#include "./bitfield.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING \
      || (defined(glGenBuffers) && defined(glDeleteBuffers))
template<enum BufferType BUFFER_TYPE>
/// Buffer Objects are OpenGL data stores, arrays on the server memory.
/** Buffer Objects are OpenGL Objects that store an array
  * of unformatted memory allocated by the OpenGL context (aka: the GPU).
  * These can be used to store vertex data, pixel data retrieved from
  * images or the framebuffer, and a variety of other things.
  * @see glGenBuffers, glDeleteBuffers */
class BufferObject {
 public:

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferData)
  /// Creates and initializes a buffer object's data store.
  /** @param size    Specifies the size in bytes of the buffer object's new data
    *                store.
    * @param data    Specifies a pointer to data that will be copied into the
    *                data store for initialization, or NULL if no data is to be
    *                copied.
    * @param usage   Specifies the expected usage pattern of the data store.
    * @see glBufferData */
  void data(GLsizei size, const void* data,
            BufferUsage usage = BufferUsage::kStaticDraw);

  template<typename GLtype>
  /// Creates and initializes a buffer object's data store.
  /** @param data - Specifies a vector of data to upload.
    * @param usage - Specifies the expected usage pattern of the data store.
    * @see glBufferData */
  void data(const std::vector<GLtype>& data,
            BufferUsage usage = BufferUsage::kStaticDraw);
#endif  // glBufferData

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferSubData)
  template<typename GLtype>
  /// Updates a subset of a buffer object's data store.
  /** @param offset  Specifies the offset into the buffer object's data store
    *                where data replacement will begin, measured in bytes.
    * @param size    Specifies the size in bytes of the data store region being
    *                replaced.
    * @param data    Specifies a pointer to the new data that will be copied
    *                into the data store.
    * @see glBufferSubData */
  void subData(GLintptr offset, GLsizei size, const GLtype* data);
#endif  // glBufferSubData


#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferSubData)
  template<typename GLtype>
  /// Updates a subset of a buffer object's data store.
  /** @param offset  Specifies the offset into the buffer object's data store
    *                where data replacement will begin, measured in bytes.
    * @param data    Specifies a vector containing the new data that will be
    *                copied into the data store.
    * @see glBufferSubData */
  void subData(GLintptr offset, const std::vector<GLtype>& data);
#endif  // glBufferSubData

#if OGLWRAP_DEFINE_EVERYTHING \
    || (defined(glGetBufferParameteriv) && defined(GL_BUFFER_SIZE))
  /// A getter for the buffer's size.
  /** @return The size of the buffer currently bound to the buffer objects
    *         default target in bytes.
    * @see glGetBufferParameteriv, GL_BUFFER_SIZE */
  size_t size() const;
#endif  // glGetBufferParameteriv && GL_BUFFER_SIZE

  /// Returns the handle for the buffer.
  const glObject& expose() const { return buffer_; }

#if OGLWRAP_DEFINE_EVERYTHING || (defined(glMapBuffer) \
     && defined(glUnmapBuffer) && defined(glMapBufferRange))
  template <class T>
  /// Mapping moves the data of the buffer to the client address space.
  class TypedMap {
   public:
    /// Maps the whole buffer.
    /** @param access  Specifies the access policy (R, W, R/W).
      * @see glMapBuffer */
    explicit TypedMap(BufferMapAccess access = BufferMapAccess::kReadWrite);

    /// Maps a range of the buffer.
    /** @param length  Specifies a length of the range to be mapped (in bytes).
      * @param offset  Specifies a the starting offset within the buffer of the
      *                range to be mapped (in bytes).
      * @param access  Specifies a combination of access flags indicating the
      *                desired access to the range.
      * @see glMapBufferRange */
    TypedMap(GLintptr offset, GLsizeiptr length,
             Bitfield<BufferMapAccessFlags> access =
              {BufferMapAccessFlags::kMapReadBit,
               BufferMapAccessFlags::kMapWriteBit});

    /// Unmaps the buffer.
    /** @see glUnmapBuffer */
    ~TypedMap();

    /// Returns the size of the mapped buffer in bytes
    size_t size() const { return size_; }

    /// Returns the size of the mapped buffer in elements
    size_t count() const { return size_ / sizeof(T); }

    /// Returns a pointer to the data
    const T* data() const { return static_cast<const T*>(data_); }

   private:
    void *data_;  // The pointer to the data fetched from the buffer.
    size_t size_;  // The size of the data fetched from the buffer.
  };

  using Map = TypedMap<GLbyte>;
#endif  // glMapBuffer && glUnmapBuffer && glMapBufferRange

 protected:
  globjects::Buffer buffer_;
};

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
/// A Buffer that stores vertex attribute data.
/** The buffer will be used as a source for vertex data,
  * but only when VertexAttribArray::Pointer​ is called.
  * @see GL_ARRAY_BUFFER */
using ArrayBuffer = BufferObject<BufferType::kArrayBuffer>;

#if OGLWRAP_INSTANTIATE
  template class BufferObject<BufferType::kArrayBuffer>;
#else
  extern template class BufferObject<BufferType::kArrayBuffer>;
#endif

#endif  // GL_ARRAY_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
/// A buffer that stores the order of the vertices for a draw call.
/** All rendering functions of the form gl*Draw*Elements*​ will use the pointer
  * field as a byte offset from the beginning of the buffer object bound to this
  * target. The indices used for indexed rendering will be taken from the buffer
  * object. Note that this binding target is part of a Vertex Array Objects
  * state, so a VAO must be bound before binding a buffer here.
  * @see GL_ELEMENT_ARRAY_BUFFER */
using IndexBuffer = BufferObject<BufferType::kElementArrayBuffer>;

#if OGLWRAP_INSTANTIATE
  template class BufferObject<BufferType::kElementArrayBuffer>;
#else
  extern template class BufferObject<BufferType::kElementArrayBuffer>;
#endif

#endif  // GL_ELEMENT_ARRAY_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
/// A Buffer that stores texture pixels.
/** This buffer has no special semantics, it is intended to use as a buffer
  * object for Buffer Textures.
  * @see GL_TEXTURE_BUFFER */
using TextureBuffer = BufferObject<BufferType::kTextureBuffer>;
#endif  // GL_TEXTURE_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindBufferBase)
template<IndexedBufferType BUFFER_TYPE>
/// Buffer objects that have an array of binding targets, like UniformBuffers.
/** Buffer Objects are OpenGL Objects that store an array
  * of unformatted memory allocated by the OpenGL context (aka: the GPU).
  * IndexBufferObject is a buffer that is bound to an indexed target. */
class IndexedBufferObject : public BufferObject<BufferType(BUFFER_TYPE)> {};

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
/// An indexed buffer binding for buffers used as storage for uniform blocks.
/** @see GL_UNIFORM_BUFFER */
using UniformBuffer = IndexedBufferObject<IndexedBufferType::kUniformBuffer>;
#endif  // GL_UNIFORM_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
/// An indexed buffer binding for buffers used in Transform Feedback operations.
/** @see GL_TRANSFORM_FEEDBACK_BUFFER */
using TransformFeedbackBuffer = IndexedBufferObject<IndexedBufferType::kTransformFeedbackBuffer> ;
#endif  // GL_TRANSFORM_FEEDBACK_BUFFER

#endif  // glBindBufferBase
#endif  // glGenBuffers && glDeleteBuffers

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_BUFFER_H_
