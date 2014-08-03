// Copyright (c) 2014, Tamas Csala

/** @file buffer.h
    @brief Implements wrappers around OpenGL Buffer glObject.
*/

#ifndef OGLWRAP_BUFFER_H_
#define OGLWRAP_BUFFER_H_

#include <vector>
#include <algorithm>

#include "enums/buffer_target.h"
#include "enums/buffer_binding.h"
#include "enums/indexed_buffer_type.h"
#include "enums/indexed_buffer_binding.h"
#include "enums/buffer_usage.h"
#include "enums/buffer_map_access.h"
#include "enums/buffer_map_access_bit.h"
#include "enums/pixel_data_format.h"
#include "enums/pixel_data_internal_format.h"
#include "enums/data_type.h"
#include "enums/buffer_storage_bit.h"

#include "./config.h"
#include "./globjects.h"
#include "./bitfield.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

class Buffer {
 public:
  BufferTarget target;
  globjects::Buffer handle;

  explicit Buffer(BufferTarget target) : target(target) { }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glInvalidateBufferData)
  /// Invalidates the content of the buffer object's data store
  void invalidate() {
    gl(InvalidateBufferData(handle));
  }
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glInvalidateBufferSubData)
  /// Invalidates a subrange of the buffer object's data store
  void subInvalidate(GLintptr offset, GLsizeiptr length) {
    gl(InvalidateBufferSubData(handle, offset, length));
  }
#endif
};

#if OGLWRAP_DEFINE_EVERYTHING || (defined(glGenBuffers) \
      && defined(glDeleteBuffers) && defined(glBindBuffer))
/// Buffer Objects are OpenGL data stores, arrays on the server memory.
/** Buffer Objects are OpenGL Objects that store an array
  * of unformatted memory allocated by the OpenGL context (aka: the GPU).
  * These can be used to store vertex data, pixel data retrieved from
  * images or the framebuffer, and a variety of other things.
  * @see glGenBuffers, glDeleteBuffers */
class BoundBuffer {
 public:
  explicit BoundBuffer(const Buffer& buffer)
      : target_(static_cast<GLenum>(buffer.target)) {
    gl(GetIntegerv(GLenum(GetBindingTarget(buffer.target)),
                  reinterpret_cast<GLint*>(&last_binding_)));
    gl(BindBuffer(target_, buffer.handle));
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindBufferBase)
  BoundBuffer(const Buffer& buffer, GLuint index)
      : target_(static_cast<GLenum>(buffer.target)) {
    gl(GetIntegerv(GLenum(GetBindingTarget(buffer.target)),
                   reinterpret_cast<GLint*>(&last_binding_)));
    gl(BindBufferBase(target_, index, buffer.handle));
  }
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindBufferRange)
  BoundBuffer(const Buffer& buffer, GLuint index,
              GLintptr offset, GLsizeiptr size)
      : target_(static_cast<GLenum>(buffer.target)) {
    gl(GetIntegerv(GLenum(GetBindingTarget(buffer.target)),
                          reinterpret_cast<GLint*>(&last_binding_)));
    gl(BindBufferRange(target_, index, offset, size, buffer.handle));
  }
#endif

  ~BoundBuffer() {
    if (target_ != GL_ELEMENT_ARRAY_BUFFER) {
      gl(BindBuffer(target_, last_binding_));
    }
  }

  // BoundBuffer shouldn't be copied or dynamically allocated
  BoundBuffer(const BoundBuffer&) = delete;
  BoundBuffer& operator=(const BoundBuffer&) = delete;
  static void* operator new(size_t size) = delete;

  /// Returns the target, to which the buffer is currently bound
  BufferTarget target() const {
    return static_cast<BufferTarget>(target_);
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferData)
  /// Allocates buffer storage to the specified size without any data
  /** @param size    Specifies the size in bytes of the buffer object's new data
    *                store.
    * @param usage   Specifies the expected usage pattern of the data store.
    * @see glBufferData */
  void resize(GLsizei size, BufferUsage usage = BufferUsage::kStaticDraw) {
    gl(BufferData(target_, size, nullptr, GLenum(usage)));
  }

  /// Creates and initializes a buffer object's data store.
  /** @param size    Specifies the size in bytes of the buffer object's new data
    *                store.
    * @param data    Specifies a pointer to data that will be copied into the
    *                data store for initialization, or NULL if no data is to be
    *                copied.
    * @param usage   Specifies the expected usage pattern of the data store.
    * @see glBufferData */
  void data(GLsizei size, const GLvoid* data,
            BufferUsage usage = BufferUsage::kStaticDraw) {
    gl(BufferData(target_, size, data, GLenum(usage)));
  }

  template<typename GLtype>
  /// Creates and initializes a buffer object's data store.
  /** @param data - Specifies a vector of data to upload.
    * @param usage - Specifies the expected usage pattern of the data store.
    * @see glBufferData */
  void data(const std::vector<GLtype>& data,
            BufferUsage usage = BufferUsage::kStaticDraw) {
    gl(BufferData(target_, data.size()*sizeof(GLtype),
                  data.data(), GLenum(usage)));
  }
#endif  // glBufferData

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferSubData)
  /// Updates a subset of a buffer object's data store.
  /** @param offset  Specifies the offset into the buffer object's data store
    *                where data replacement will begin, measured in bytes.
    * @param size    Specifies the size in bytes of the data store region being
    *                replaced.
    * @param data    Specifies a pointer to the new data that will be copied
    *                into the data store.
    * @see glBufferSubData */
  void subData(GLintptr offset, GLsizei size, const GLvoid* data) {
    gl(BufferSubData(target_, offset, size, data));
  }

  template<typename GLtype>
  /// Updates a subset of a buffer object's data store.
  /** @param offset  Specifies the offset into the buffer object's data store
    *                where data replacement will begin, measured in bytes.
    * @param data    Specifies a vector containing the new data that will be
    *                copied into the data store.
    * @see glBufferSubData */
  void subData(GLintptr offset, const std::vector<GLtype>& data) {
    gl(BufferSubData(target_, offset, data.size()*sizeof(GLtype), data.data()));
  }
#endif  // glBufferSubData

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCopyBufferSubData)
  /// Copies that maximum possible amount of data from the other buffer
  void copy(const BoundBuffer& from) {
    gl(CopyBufferSubData(from.target_, target_, 0, 0,
                        std::min(size(), from.size())));
  }

  /// Copies the specified part of the the buffer's data
  void subCopy(const BoundBuffer& from, GLintptr read_offset​,
            GLintptr write_offset​, GLsizeiptr size) {
    gl(CopyBufferSubData(from.target_, target_, read_offset​,
                         write_offset​, size));
  }
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glClearBufferData)
  /// Fills the buffer object's data store with a fixed value
  void clear(PixelDataInternalFormat internal_format,
             PixelDataFormat format,
             DataType type,
             const GLvoid* data) {
    gl(ClearBufferData(target_, GLenum(internal_format),
                       GLenum(format), GLenum(type), data));
  }
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glClearBufferSubData)
  /// Fills the buffer object's data store with a fixed value
  void subClear(PixelDataInternalFormat internal_format,
                GLintptr offset, GLsizeiptr size,
                PixelDataFormat format,
                DataType type,
                const GLvoid* data) {
    gl(ClearBufferSubData(target_, GLenum(internal_format), offset, size,
                          GLenum(format), GLenum(type), data));
  }
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBufferStorage)
  /// Creates and initializes a buffer object's immutable data store
  void storage(GLsizeiptr size, const GLvoid* data,
               Bitfield<BufferStorageBit> flags) {
    gl(BufferStorage(target_, size, data, flags));
  }
#endif

#if OGLWRAP_DEFINE_EVERYTHING \
    || (defined(glGetBufferParameteriv) && defined(GL_BUFFER_SIZE))
  /// A getter for the buffer's size.
  /** @return The size of the buffer currently bound to the buffer objects
    *         default target in bytes.
    * @see glGetBufferParameteriv, GL_BUFFER_SIZE */
  size_t size() const {
    GLint size;
    gl(GetBufferParameteriv(target_, GL_BUFFER_SIZE, &size));
    return size;
  }
#endif  // glGetBufferParameteriv && GL_BUFFER_SIZE

 protected:
  GLuint last_binding_;
  const GLenum target_;
};

#if OGLWRAP_DEFINE_EVERYTHING || (defined(glMapBuffer) \
     && defined(glUnmapBuffer) && defined(glMapBufferRange))
class MappedBuffer {
  public:
    /// Maps the whole buffer.
    /** @param access  Specifies the access policy (R, W, R/W).
      * @see glMapBuffer */
    MappedBuffer(const BoundBuffer& buffer,
                 BufferMapAccess access = BufferMapAccess::kReadWrite)
        : target_(static_cast<GLenum>(buffer.target())) {
      data_ = gl(MapBuffer(target_, GLenum(access)));
      gl(GetBufferParameteriv(target_, GL_BUFFER_SIZE, &size_));
    }

    MappedBuffer(BoundBuffer&& buffer,
                 BufferMapAccess access = BufferMapAccess::kReadWrite) = delete;

    #if OGLWRAP_DEFINE_EVERYTHING ||  defined(glMapBufferRange)
    /// Maps a range of the buffer.
    /** @param length  Specifies a length of the range to be mapped (in bytes).
      * @param offset  Specifies a the starting offset within the buffer of the
      *                range to be mapped (in bytes).
      * @param access  Specifies a combination of access flags indicating the
      *                desired access to the range.
      * @see glMapBufferRange */
    MappedBuffer(const BoundBuffer& buffer,
                 GLintptr offset, GLsizeiptr length,
                 Bitfield<BufferMapAccessBit> access =
                  {BufferMapAccessBit::kMapReadBit,
                   BufferMapAccessBit::kMapWriteBit})
        : target_(static_cast<GLenum>(buffer.target())) {
      data_ = gl(MapBufferRange(target_, offset, length, access));
      gl(GetBufferParameteriv(target_, GL_BUFFER_SIZE, &size_));
    }

    MappedBuffer(BoundBuffer&& buffer,
                 GLintptr offset, GLsizeiptr length,
                 Bitfield<BufferMapAccessBit> access =
                  {BufferMapAccessBit::kMapReadBit,
                   BufferMapAccessBit::kMapWriteBit}) = delete;
    #endif  // glMapBufferRange

    /// Unmaps the buffer.
    /** @see glUnmapBuffer */
    ~MappedBuffer() {
      gl(UnmapBuffer(target_));
    }

    // MappedBuffer shouldn't be copied or dynamically allocated
    MappedBuffer(const MappedBuffer&) = delete;
    MappedBuffer& operator=(const MappedBuffer&) = delete;
    static void* operator new(size_t size) = delete;

    /// Returns the size of the mapped buffer in bytes
    GLint size() const { return size_; }

    /// Returns a pointer to the data
    const GLbyte* data() const {return reinterpret_cast<const GLbyte*>(data_);}

    /// Returns a pointer to the data
    GLbyte* data() { return reinterpret_cast<GLbyte*>(data_); }

   private:
    void *data_;  // The pointer to the data fetched from the buffer.
    GLint size_;  // The size of the data fetched from the buffer.
    const GLenum target_;
};
#endif  // glMapBuffer && glUnmapBuffer

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
/// A Buffer that stores vertex attribute data.
/** The buffer will be used as a source for vertex data,
  * but only when VertexAttribArray::Pointer​ is called.
  * @see GL_ARRAY_BUFFER */
struct ArrayBuffer : public Buffer {
  explicit ArrayBuffer() : Buffer(BufferTarget::kArrayBuffer) { }
};
#endif  // GL_ARRAY_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
/// A buffer that stores the order of the vertices for a draw call.
/** All rendering functions of the form gl*Draw*Elements*​ will use the pointer
  * field as a byte offset from the beginning of the buffer object bound to this
  * target. The indices used for indexed rendering will be taken from the buffer
  * object. Note that this binding target is part of a Vertex Array Objects
  * state, so a VAO must be bound before binding a buffer here.
  * @see GL_ELEMENT_ARRAY_BUFFER */
struct IndexBuffer : public Buffer {
  explicit IndexBuffer() : Buffer(BufferTarget::kElementArrayBuffer) { }
};
#endif  // GL_ELEMENT_ARRAY_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
/// A Buffer that stores texture pixels.
/** This buffer has no special semantics, it is intended to use as a buffer
  * object for Buffer Textures.
  * @see GL_TEXTURE_BUFFER */
struct TextureBuffer : public Buffer {
  explicit TextureBuffer() : Buffer(BufferTarget::kTextureBuffer) { }
};
#endif  // GL_TEXTURE_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
/// An indexed buffer binding for buffers used as storage for uniform blocks.
/** @see GL_UNIFORM_BUFFER */
struct UniformBuffer : public Buffer {
  explicit UniformBuffer() : Buffer(BufferTarget::kUniformBuffer) { }
};
#endif  // GL_UNIFORM_BUFFER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
/// An indexed buffer binding for buffers used in Transform Feedback operations.
/** @see GL_TRANSFORM_FEEDBACK_BUFFER */
struct TransformFeedbackBuffer : public Buffer {
  explicit TransformFeedbackBuffer() : Buffer(BufferTarget::kTransformFeedbackBuffer) { }
};
#endif  // GL_TRANSFORM_FEEDBACK_BUFFER

#endif  // glGenBuffers && glDeleteBuffers && glBindBuffer

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_BUFFER_H_
