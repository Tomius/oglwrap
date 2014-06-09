// Copyright (c) 2014, Tamas Csala

/** @file buffer.h
    @brief Implements wrappers around OpenGL Buffer glObject.
*/

#ifndef OGLWRAP_BUFFER_H_
#define OGLWRAP_BUFFER_H_

#include "enums/buffer_type.h"
#include "enums/buffer_binding.h"
#include "enums/indexed_buffer_type.h"
#include "enums/indexed_buffer_binding.h"
#include "enums/buffer_usage.h"
#include "enums/buffer_map_access.h"
#include "enums/buffer_map_access_flags.h"

#include "general.h"
#include "globjects.h"
#include "debug/binding.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING \
      || (defined(glGenBuffers) && defined(glDeleteBuffers))
template<BufferType BUFFER_TYPE>
/// Buffer Objects are OpenGL data stores, arrays on the server memory.
/** Buffer Objects are OpenGL Objects that store an array
  * of unformatted memory allocated by the OpenGL context (aka: the GPU).
  * These can be used to store vertex data, pixel data retrieved from
  * images or the framebuffer, and a variety of other things.
  * @see glGenBuffers, glDeleteBuffers */
class BufferObject {
protected:
  /// The handle for the buffer.
  globjects::Buffer buffer_;
public:
  /// Default constructor.
  BufferObject() {}

  template<BufferType ANOTHER_BUFFER_TYPE>
  /// Creates a copy of the buffer, or casts it to another type.
  /** Important: if you use this to change the type of the active buffer,
    * don't forget to unbind the old one, and bind the new one */
  BufferObject(const BufferObject<ANOTHER_BUFFER_TYPE> src)
    : buffer_(src.Expose())
  { }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindBuffer)
  /// Binds a buffer object to its default target.
  /** @see glBindBuffer */
  void bind() const {
    gl(BindBuffer(GLenum(BUFFER_TYPE), buffer_));
  }
#endif // glBindBuffer

  /// Returns if this is the currently bound buffer for its target.
  /** @see glGetIntegerv */
  bool isBound() const {
    GLint currentlyBoundBuffer;
    gl(GetIntegerv(GLenum(GetBindingTarget(BUFFER_TYPE)),
                   &currentlyBoundBuffer));
    return buffer_ == GLuint(currentlyBoundBuffer);
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindBuffer)
  /// Unbinds a buffer object from its default target.
  /** @see glBindBuffer */
  static void Unbind() {
    gl(BindBuffer(GLenum(BUFFER_TYPE), 0));
  }
  /// Unbinds a buffer object from its default target.
  /** @see glBindBuffer */
  BIND_CHECKED void unbind() const {
    OGLWRAP_CHECK_BINDING2();
    Unbind();
  }
#endif // glBindBuffer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferData)
  template<typename GLtype>
  /// Creates and initializes a buffer object's data store.
  /** @param size    Specifies the size in bytes of the buffer object's new data
    *                store.
    * @param data    Specifies a pointer to data that will be copied into the
    *                data store for initialization, or NULL if no data is to be
    *                copied.
    * @param usage   Specifies the expected usage pattern of the data store.
    * @see glBufferData */
  static void Data(GLsizei size, const GLtype* data,
                   BufferUsage usage = BufferUsage::kStaticDraw) {
    gl(BufferData(GLenum(BUFFER_TYPE), size, data, GLenum(usage)));
  }
  template<typename GLtype>
  /// Creates and initializes a buffer object's data store.
  /** @param size    Specifies the size in bytes of the buffer object's new data
    *                store.
    * @param data    Specifies a pointer to data that will be copied into the
    *                data store for initialization, or NULL if no data is to be
    *                copied.
    * @param usage   Specifies the expected usage pattern of the data store.
    * @see glBufferData */
  BIND_CHECKED void data(GLsizei size, const GLtype* data,
                         BufferUsage usage = BufferUsage::kStaticDraw) const {
    OGLWRAP_CHECK_BINDING();
    if (BUFFER_TYPE == BufferType::kArrayBuffer) {
      OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    }

    Data(size, data, usage);
  }
#endif // glBufferData

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferData)
  template<typename GLtype>
  /** @brief Creates and initializes a buffer object's data store.
    * @param data - Specifies a vector of data to upload.
    * @param usage - Specifies the expected usage pattern of the data store.
    * @see glBufferData */
  static void Data(const std::vector<GLtype>& data,
                   BufferUsage usage = BufferUsage::kStaticDraw) {
    gl(BufferData(GLenum(BUFFER_TYPE), data.size() * sizeof(GLtype),
                  data.data(), GLenum(usage)));
  }
  template<typename GLtype>
  /// Creates and initializes a buffer object's data store.
  /** @param data - Specifies a vector of data to upload.
    * @param usage - Specifies the expected usage pattern of the data store.
    * @see glBufferData */
  BIND_CHECKED void data(const std::vector<GLtype>& data,
                         BufferUsage usage = BufferUsage::kStaticDraw) const {
    OGLWRAP_CHECK_BINDING();
    if (BUFFER_TYPE == BufferType::kArrayBuffer) {
      OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    }

    Data(data, usage);
  }
#endif // glBufferData

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferSubData)
  template<typename GLtype>
  /// Updates a subset of a buffer object's data store.
  /** @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
    * @param size - Specifies the size in bytes of the data store region being replaced.
    * @param data - Specifies a pointer to the new data that will be copied into the data store.
    * @see glBufferSubData */
  static void SubData(GLintptr offset, GLsizei size, const GLtype* data) {
    gl(BufferSubData(GLenum(BUFFER_TYPE), offset, size, GLenum(data)));
  }
  template<typename GLtype>
  /// Updates a subset of a buffer object's data store.
  /** @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
    * @param size - Specifies the size in bytes of the data store region being replaced.
    * @param data - Specifies a pointer to the new data that will be copied into the data store.
    * @see glBufferSubData */
  BIND_CHECKED void subData(GLintptr offset, GLsizei size, const GLtype* data) const {
    OGLWRAP_CHECK_BINDING();
    if (BUFFER_TYPE == BufferType::kArrayBuffer) {
      OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    }

    SubData(offset, size, data);
  }
#endif // glBufferSubData


#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferSubData)
  template<typename GLtype>
  /// Updates a subset of a buffer object's data store.
  /** @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
    * @param data - Specifies a vector containing the new data that will be copied into the data store.
    * @see glBufferSubData */
  static void SubData(GLintptr offset, const std::vector<GLtype>& data) {
    gl(BufferSubData(GLenum(BUFFER_TYPE), offset,
                     data.size() * sizeof(GLtype), data.data()));
  }
  template<typename GLtype>
  /// Updates a subset of a buffer object's data store.
  /** @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
    * @param data - Specifies a vector containing the new data that will be copied into the data store.
    * @see glBufferSubData */
  BIND_CHECKED void subData(GLintptr offset, const std::vector<GLtype>& data) const {
    OGLWRAP_CHECK_BINDING();
    if (BUFFER_TYPE == BufferType::kArrayBuffer) {
      OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    }

    SubData(offset, data);
  }
#endif // glBufferSubData

#if OGLWRAP_DEFINE_EVERYTHING || (defined(glGetBufferParameteriv) && defined(GL_BUFFER_SIZE))
  /// A getter for the buffer's size.
  /** @return The size of the buffer currently bound to the buffer objects default target in bytes.
    * @see glGetBufferParameteriv, GL_BUFFER_SIZE */
  static size_t Size() {
    GLint data;
    gl(GetBufferParameteriv(GLenum(BUFFER_TYPE), GL_BUFFER_SIZE, &data));
    return data;
  }
  /// A getter for the buffer's size.
  /** @return The size of the buffer currently bound to the buffer objects default target in bytes.
    * @see glGetBufferParameteriv, GL_BUFFER_SIZE */
  BIND_CHECKED size_t size() const {
    OGLWRAP_CHECK_BINDING();
    return Size();
  }
#endif // glGetBufferParameteriv && GL_BUFFER_SIZE

  /// Returns the handle for the buffer.
  const glObject& expose() const {
    return buffer_;
  }

#if OGLWRAP_DEFINE_EVERYTHING \
  || (defined(glMapBuffer) && defined(glUnmapBuffer) && defined(glMapBufferRange))
  template <class T>
  /// Mapping moves the data of the buffer to the client address space.
  class TypedMap {
    void *data_; ///< The pointer to the data fetched from the buffer.
    size_t size_; ///< The size of the data fetched from the buffer.
  public:
    /// Maps the whole buffer.
    /** @param access - Specifies the access policy (R, W, R/W).
      * @see glMapBuffer */
    TypedMap(BufferMapAccess access = BufferMapAccess::kReadWrite) {
      OGLWRAP_CHECK_FOR_DEFAULT_BINDING(GLenum(GetBindingTarget(BUFFER_TYPE)));

      data_ = gl(MapBuffer(GLenum(BUFFER_TYPE), GLenum(access)));
      size_ = BufferObject<BUFFER_TYPE>::Size();
    }

    /// Maps a range of the buffer.
    /** @param length - Specifies a length of the range to be mapped (in bytes).
      * @param offset - Specifies a the starting offset within the buffer of the range to be mapped (in bytes).
      * @param access - Specifies a combination of access flags indicating the desired access to the range.
      * @see glMapBufferRange */
    TypedMap(GLintptr offset,
             GLsizeiptr length,
             Bitfield<BufferMapAccessFlags> access =
                {BufferMapAccessFlags::kMapReadBit, BufferMapAccessFlags::kMapWriteBit}) {

      OGLWRAP_CHECK_FOR_DEFAULT_BINDING(GLenum(GetBindingTarget(BUFFER_TYPE)));

      data_ = gl(MapBufferRange(GLenum(BUFFER_TYPE), offset, length, access));
      size_ = BufferObject<BUFFER_TYPE>::Size();
    }

    /// Unmaps the buffer.
    /** @see glUnmapBuffer */
    ~TypedMap() {
      OGLWRAP_CHECK_FOR_DEFAULT_BINDING(GLenum(GetBindingTarget(BUFFER_TYPE)));

      gl(UnmapBuffer(GLenum(BUFFER_TYPE)));
    }

    /// Returns the size of the mapped buffer in bytes
    size_t size() const {
      return size_;
    }

    /// Returns the size of the mapped buffer in elements
    size_t count() const {
      return size_ / sizeof(T);
    }

    /// Returns a pointer to the data
    T* data() const {
      return static_cast<T*>(data_);
    }

  }; // class Map

  typedef TypedMap<GLbyte> Map;

#endif // glMapBuffer && glUnmapBuffer && glMapBufferRange
};

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
/// A Buffer that stores vertex attribute data.
/** The buffer will be used as a source for vertex data,
  * but only when VertexAttribArray::Pointer​ is called.
  * @see GL_ARRAY_BUFFER */
typedef BufferObject<BufferType::kArrayBuffer> ArrayBuffer;

#if OGLWRAP_INSTANTIATE
  template class BufferObject<BufferType::kArrayBuffer>;
#else
  extern template class BufferObject<BufferType::kArrayBuffer>;
#endif

#endif // GL_ARRAY_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
/// A buffer that stores the order of the vertices for a draw call.
/** All rendering functions of the form gl*Draw*Elements*​ will use the pointer field as a byte offset from
  * the beginning of the buffer object bound to this target. The indices used for indexed rendering will be
  * taken from the buffer object. Note that this binding target is part of a Vertex Array Objects state, so a
  * VAO must be bound before binding a buffer here.
  * @see GL_ELEMENT_ARRAY_BUFFER */
typedef BufferObject<BufferType::kElementArrayBuffer> IndexBuffer;

#if OGLWRAP_INSTANTIATE
  template class BufferObject<BufferType::kElementArrayBuffer>;
#else
  extern template class BufferObject<BufferType::kElementArrayBuffer>;
#endif

#endif // GL_ELEMENT_ARRAY_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
/// A Buffer that stores texture pixels.
/** This buffer has no special semantics, it is intended to use as a buffer object for Buffer Textures.
  * @see GL_TEXTURE_BUFFER */
typedef BufferObject<BufferType::kTextureBuffer> TextureBuffer;

#if OGLWRAP_INSTANTIATE
  template class BufferObject<BufferType::kTextureBuffer>;
#else
  extern template class BufferObject<BufferType::kTextureBuffer>;
#endif

#endif // GL_TEXTURE_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || (defined(glBindBufferBase) && defined(glBindBufferRange))
template<IndexedBufferType BUFFER_TYPE>
/// Buffer objects that have an array of binding targets, like UniformBuffers.
/** Buffer Objects are OpenGL Objects that store an array
  * of unformatted memory allocated by the OpenGL context (aka: the GPU).
  * IndexBufferObject is a buffer that is bound to an indexed target. */
class IndexedBufferObject : public BufferObject<BufferType(BUFFER_TYPE)> {
public:
  /// Bind a buffer object to an index.
  /** @param index - Specify the index of the binding point within the array.
    * @see glBindBufferBase */
  void bindBase(GLuint index) const {
    gl(BindBufferBase(GLenum(BUFFER_TYPE), index,
                      BufferObject<BufferType(BUFFER_TYPE)>::buffer_));
  }

  /// Bind a range within a buffer object to an index.
  /** @param index - Specify the index of the binding point within the array.
    * @param offset - The starting offset in basic machine units into the buffer object.
    * @param size - The amount of data in machine units that can be read from the buffet object while used as an indexed target.
    * @see glBindBufferRange */
  void bindRange(GLuint index, GLintptr offset, GLsizeiptr size) const {
    gl(BindBufferRange(GLenum(BUFFER_TYPE), index, offset, size,
                       BufferObject<BufferType(BUFFER_TYPE)>::buffer_));
  }

  /// Returns if this is the currently bound buffer for an indexed target.
  /** @see glGetIntegeri_v */
  bool isBound(GLuint index) const {
    GLint currentlyBoundBuffer;
    gl(GetIntegeri_v(GLenum(GetBindingTarget(BUFFER_TYPE)), index,
                     &currentlyBoundBuffer));
    return BufferObject<BufferType(BUFFER_TYPE)>::buffer_
           == GLuint(currentlyBoundBuffer);
  }

  /// Unbind a buffer object from an index.
  /** @param index - Specify the index of the binding point within the array.
    * @see glBindBufferBase */
  static void UnbindBase(GLuint index) {
    gl(BindBufferBase(GLenum(BUFFER_TYPE), index, 0));
  }
  /// Unbind a buffer object from an index.
  /** @param index - Specify the index of the binding point within the array.
    * @see glBindBufferBase */
  BIND_CHECKED void unbindBase(GLuint index) const {
    OGLWRAP_CHECK_BINDING2_EXPLICIT(isBound(index));
    UnbindBase(index);
  }
};

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
/// An indexed buffer binding for buffers used as storage for uniform blocks.
/** @see GL_UNIFORM_BUFFER */
typedef IndexedBufferObject<IndexedBufferType::kUniformBuffer> UniformBuffer;

#if OGLWRAP_INSTANTIATE
  template class IndexedBufferObject<IndexedBufferType::kUniformBuffer>;
#else
  extern template class IndexedBufferObject<IndexedBufferType::kUniformBuffer>;
#endif

#endif // GL_UNIFORM_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
/// An indexed buffer binding for buffers used in Transform Feedback operations.
/** @see GL_TRANSFORM_FEEDBACK_BUFFER */
typedef IndexedBufferObject<IndexedBufferType::kTransformFeedbackBuffer> TransformFeedbackBuffer;

#if OGLWRAP_INSTANTIATE
  template class IndexedBufferObject<IndexedBufferType::kTransformFeedbackBuffer>;
#else
  extern template class IndexedBufferObject<IndexedBufferType::kTransformFeedbackBuffer>;
#endif

#endif // GL_TRANSFORM_FEEDBACK_BUFFER

#endif // glBindBufferRange && glBindBufferBase
#endif // glGenBuffers && glDeleteBuffers

} // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif // OGLWRAP_BUFFER_H_
