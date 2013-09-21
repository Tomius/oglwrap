/** @file buffer.hpp
    @brief Implements wrappers around OpenGL Buffer Object.
*/

#pragma once

namespace oglwrap {

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glGenBuffers) && defined(glDeleteBuffers))
template<BufferType buffer_t>
/// Buffer Objects are OpenGL data stores, arrays on the server memory.
/** Buffer Objects are OpenGL Objects that store an array
  * of unformatted memory allocated by the OpenGL context (aka: the GPU).
  * These can be used to store vertex data, pixel data retrieved from
  * images or the framebuffer, and a variety of other things. */
/// @see glGenBuffers, glDeleteBuffers
class BufferObject {
protected:
    /// The handle for the buffer.
    ObjectExt<glGenBuffers, glDeleteBuffers> buffer;
public:
    /// Default constructor.
    BufferObject() {}

    template<BufferType another_buffer_t>
    /// Creates a copy of the buffer, or casts it to another type.
    /** Important: if you use this to change the type of the active buffer,
      * don't forget to unbind the old one, and bind the new one */
    BufferObject(const BufferObject<another_buffer_t> src)
        : buffer(src.Expose())
    { }

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindBuffer)
    /// Binds a buffer object to its default target.
    /** @see glBindBuffer */
    void bind() const {
        gl( BindBuffer(buffer_t, buffer) );
    }
    #endif // glBindBuffer

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindBuffer)
    /// Unbinds a buffer object from its default target.
    /** @see glBindBuffer */
    static void Unbind() {
        gl( BindBuffer(buffer_t, 0) );
    }
    #endif // glBindBuffer

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindBuffer)
    /// Unbinds a buffer object from its default target.
    /** @see glBindBuffer */
    void unbind() const {
        Unbind();
    }
    #endif // glBindBuffer

    /// Returns if this is the currently bound buffer for its target.
    /** @see glGetIntegerv */
    bool isBound() const {
        GLint currentlyBoundBuffer;
        gl( GetIntegerv(getBindingTarget(buffer_t), &currentlyBoundBuffer) );
        return buffer == GLuint(currentlyBoundBuffer);
    }

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBufferData)
    template<typename GLtype>
    /// Creates and initializes a buffer object's data store.
    /** @param size - Specifies the size in bytes of the buffer object's new data store.
      * @param data - Specifies a pointer to data that will be copied into the data store for initialization, or NULL if no data is to be copied.
      * @param usage - Specifies the expected usage pattern of the data store.
      * @see glBufferData */
    static void Data(GLsizei size, const GLtype* data,
                     BufferUsage usage = BufferUsage::StaticDraw) {
        gl( BufferData(buffer_t, size, data, usage) );
    }
    #endif // glBufferData

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBufferData)
    template<typename GLtype>
    /// Creates and initializes a buffer object's data store.
    /** @param size - Specifies the size in bytes of the buffer object's new data store.
      * @param data - Specifies a pointer to data that will be copied into the data store for initialization, or NULL if no data is to be copied.
      * @param usage - Specifies the expected usage pattern of the data store.
      * @see glBufferData */
    void data(GLsizei size, const GLtype* data,
                     BufferUsage usage = BufferUsage::StaticDraw) const {
        CHECK_BINDING();
        if(buffer_t == BufferType::Array)
            CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);

        Data(size, data, usage);
    }
    #endif // glBufferData

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBufferData)
    template<typename GLtype>
    /// @brief Creates and initializes a buffer object's data store.
    /** @param data - Specifies a vector of data to upload.
      * @param usage - Specifies the expected usage pattern of the data store.
      * @see glBufferData */
    static void Data(const std::vector<GLtype>& data,
                     BufferUsage usage = BufferUsage::StaticDraw) {
        gl( BufferData(buffer_t, data.size() * sizeof(GLtype), data.data(), usage) );
    }
    #endif // glBufferData

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBufferData)
    template<typename GLtype>
    /// @brief Creates and initializes a buffer object's data store.
    /** @param data - Specifies a vector of data to upload.
      * @param usage - Specifies the expected usage pattern of the data store.
      * @see glBufferData */
    void data(const std::vector<GLtype>& data,
                     BufferUsage usage = BufferUsage::StaticDraw) const {
        CHECK_BINDING();
        if(buffer_t == BufferType::Array)
            CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);

        Data(data, usage);
    }
    #endif // glBufferData

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBufferSubData)
    template<typename GLtype>
    /// @brief Updates a subset of a buffer object's data store.
    /** @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
      * @param size - Specifies the size in bytes of the data store region being replaced.
      * @param data - Specifies a pointer to the new data that will be copied into the data store.
      * @see glBufferSubData */
    static void SubData(GLintptr offset, GLsizei size, const GLtype* data) {
        gl( BufferSubData(buffer_t, offset, size, data) );
    }
    #endif // glBufferSubData

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBufferSubData)
    template<typename GLtype>
    /// @brief Updates a subset of a buffer object's data store.
    /** @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
      * @param size - Specifies the size in bytes of the data store region being replaced.
      * @param data - Specifies a pointer to the new data that will be copied into the data store.
      * @see glBufferSubData */
    void subData(GLintptr offset, GLsizei size, const GLtype* data) const {
        CHECK_BINDING();
        if(buffer_t == BufferType::Array)
            CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);

        SubData(offset, size, data);
    }
    #endif // glBufferSubData


    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBufferSubData)
    template<typename GLtype>
    /// Updates a subset of a buffer object's data store.
    /** @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
      * @param data - Specifies a vector containing the new data that will be copied into the data store.
      * @see glBufferSubData */
    static void SubData(GLintptr offset, const std::vector<GLtype>& data) {
        gl( BufferSubData(buffer_t, offset, data.size() * sizeof(GLtype), data.data()) );
    }
    #endif // glBufferSubData

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBufferSubData)
    template<typename GLtype>
    /// Updates a subset of a buffer object's data store.
    /** @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
      * @param data - Specifies a vector containing the new data that will be copied into the data store.
      * @see glBufferSubData */
    void subData(GLintptr offset, const std::vector<GLtype>& data) const {
        CHECK_BINDING();
        if(buffer_t == BufferType::Array)
            CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);

        SubData(offset, data);
    }
    #endif // glBufferSubData

    #if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glGetBufferParameteriv) && defined(GL_BUFFER_SIZE))
    /// A getter for the buffer's size.
    /** @return The size of the buffer currently bound to the buffer objects default target in bytes.
      * @see glGetBufferParameteriv, GL_BUFFER_SIZE */
    static size_t Size() {
        GLint data;
        gl( GetBufferParameteriv(buffer_t, GL_BUFFER_SIZE, &data) );
        return data;
    }
    #endif // glGetBufferParameteriv && GL_BUFFER_SIZE

    #if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glGetBufferParameteriv) && defined(GL_BUFFER_SIZE))
    /// A getter for the buffer's size.
    /** @return The size of the buffer currently bound to the buffer objects default target in bytes.
      * @see glGetBufferParameteriv, GL_BUFFER_SIZE */
    size_t size() const {
        CHECK_BINDING();
        return Size();
    }
    #endif // glGetBufferParameteriv && GL_BUFFER_SIZE

    /// Returns the handle for the buffer.
    const ObjectExt<glGenBuffers, glDeleteBuffers>& expose() const {
        return buffer;
    }

    #if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glMapBuffer) && defined(glUnmapBuffer) && defined(glMapBufferRange))
    template <class T>
    /// Mapping moves the data of the buffer to the client address space.
    class TypedMap {
        void *m_data; ///< The pointer to the data fetched from the buffer.
        size_t m_size; ///< The size of the data fetched from the buffer.
    public:
        /// Maps the whole buffer.
        /** @param access - Specifies the access policy (R, W, R/W).
          * @see glMapBuffer */
        TypedMap(BufferMapAccess access = BufferMapAccess::ReadWrite) {
            CHECK_FOR_DEFAULT_BINDING(getBindingTarget(buffer_t));

            m_data = gl( MapBuffer(buffer_t, access) );
            m_size = BufferObject<buffer_t>::Size();
        }

        /// Maps a range of the buffer.
        /** @param length - Specifies a length of the range to be mapped (in bytes).
          * @param offset - Specifies a the starting offset within the buffer of the range to be mapped (in bytes).
          * @param access - Specifies a combination of access flags indicating the desired access to the range.
          * @see glMapBufferRange */
        TypedMap(GLintptr offset,
                 GLsizeiptr length,
                 GLbitfield access = BufferMapAccessFlags::Read_Bit | BufferMapAccessFlags::Write_Bit) {

            CHECK_FOR_DEFAULT_BINDING(getBindingTarget(buffer_t));

            m_data = gl( MapBufferRange(buffer_t, offset, length, access) );
            m_size = BufferObject<buffer_t>::Size();
        }

        /// Unmaps the buffer.
        /** @see glUnmapBuffer */
        ~TypedMap() {
            CHECK_FOR_DEFAULT_BINDING(getBindingTarget(buffer_t));

            gl( UnmapBuffer(buffer_t) );
        }

        /// Returns the size of the mapped buffer in bytes
        size_t size() const {
            return m_size;
        }

        /// Returns the size of the mapped buffer in elements
        size_t count() const {
            return m_size / sizeof(T);
        }

        /// Returns a pointer to the data
        T* data() const {
            return static_cast<T*>(m_data);
        }

    }; // class Map

    typedef TypedMap<GLbyte> Map;

    #endif // glMapBuffer && glUnmapBuffer && glMapBufferRange
};

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ARRAY_BUFFER)
/// A Buffer that stores vertex attribute data.
/** The buffer will be used as a source for vertex data,
  * but only when VertexAttribArray::Pointer​ is called. */
/// @see GL_ARRAY_BUFFER
typedef BufferObject<BufferType::Array> ArrayBuffer;
#endif // GL_ARRAY_BUFFER

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ELEMENT_ARRAY_BUFFER)
/// A buffer that stores the order of the vertices for a draw call.
/** All rendering functions of the form gl*Draw*Elements*​ will use the pointer field as a byte offset from
  * the beginning of the buffer object bound to this target. The indices used for indexed rendering will be
  * taken from the buffer object. Note that this binding target is part of a Vertex Array Objects state, so a
  * VAO must be bound before binding a buffer here. */
/// @see GL_ELEMENT_ARRAY_BUFFER
typedef BufferObject<BufferType::ElementArray> IndexBuffer;
#endif // GL_ELEMENT_ARRAY_BUFFER

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BUFFER)
/// A Buffer that stores texture pixels.
/** This buffer has no special semantics, it is intended to use as a buffer object for Buffer Textures. */
/// @see GL_TEXTURE_BUFFER
typedef BufferObject<BufferType::Texture> TextureBuffer;
#endif // GL_TEXTURE_BUFFER

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glBindBufferBase) && defined(glBindBufferRange))
template<IndexedBufferType buffer_t>
/// Buffer objects that have an array of binding targets, like UniformBuffers.
/** Buffer Objects are OpenGL Objects that store an array
  * of unformatted memory allocated by the OpenGL context (aka: the GPU).
  * IndexBufferObject is a buffer that is bound to an indexed target. */
class IndexedBufferObject : public BufferObject<BufferType(buffer_t)> {
public:
    /// Bind a buffer object to an index.
    /** @param index - Specify the index of the binding point within the array.
      * @see glBindBufferBase */
    void bindBase(GLuint index) const {
        gl( BindBufferBase(buffer_t, index, BufferObject<buffer_t>::buffer) );
    }

    /// Bind a range within a buffer object to an index.
    /** @param index - Specify the index of the binding point within the array.
      * @param offset - The starting offset in basic machine units into the buffer object.
      * @param size - The amount of data in machine units that can be read from the buffet object while used as an indexed target.
      * @see glBindBufferRange */
    void bindRange(GLuint index, GLintptr offset, GLsizeiptr size) const {
        gl( BindBufferRange(buffer_t, index, offset, size, BufferObject<buffer_t>::buffer) );
    }

    /// Unbind a buffer object from an index.
    /** @param index - Specify the index of the binding point within the array.
      * @see glBindBufferBase */
    static void UnbindBase(GLuint index) {
        gl( BindBufferBase(buffer_t, index, 0) );
    }

    /// Unbind a buffer object from an index.
    /** @param index - Specify the index of the binding point within the array.
      * @see glBindBufferBase */
    void unbindBase(GLuint index) const {
        UnbindBase(index);
    }
};

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNIFORM_BUFFER)
/// @brief An indexed buffer binding for buffers used as storage for uniform blocks.
/// @see GL_UNIFORM_BUFFER
typedef IndexedBufferObject<IndexedBufferType::Uniform> UniformBuffer;
#endif // GL_UNIFORM_BUFFER

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
/// @brief An indexed buffer binding for buffers used in Transform Feedback operations.
/// @see GL_TRANSFORM_FEEDBACK_BUFFER
typedef IndexedBufferObject<IndexedBufferType::TransformFeedback> TransformFeedbackBuffer;
#endif // GL_TRANSFORM_FEEDBACK_BUFFER

#endif // glBindBufferRange && glBindBufferBase

#endif // glGenBuffers && glDeleteBuffers
} // namespace oglwrap

