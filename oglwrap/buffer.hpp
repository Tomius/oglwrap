#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <vector>
#include <string>
#include <GL/glew.h>

#include "error.hpp"
#include "enums.hpp"
#include "general.hpp"

namespace oglwrap {

template<BufferType buffer_t>
/** Buffer Objects are OpenGL Objects that store an array
    of unformatted memory allocated by the OpenGL context (aka: the GPU).
    These can be used to store vertex data, pixel data retrieved from
    images or the framebuffer, and a variety of other things.
**/
class BufferObject : protected RefCounted {
protected:
    GLuint buffer; ///< The C API handle for the buffer.
public:
    /// Generates a buffer object.
    /// @see glGenBuffers
    BufferObject() {
        glGenBuffers(1, &buffer);
        oglwrap_CheckError();
    }

    /// Deletes the buffer generated in the constructor.
    /// @see glDeleteBuffers
    ~BufferObject() {
        if(!isDeletable())
            return;
        glDeleteBuffers(1, &buffer);
        oglwrap_CheckError();
    }

    // Binds
    /// Bind a buffer object to its default target.
    /// @see glBindBuffer
    void Bind() {
        glBindBuffer(buffer_t, buffer);
        oglwrap_CheckError();
    }

    // Unbinds
    /// Unbind a buffer object from its default target.
    /// @see glBindBuffer
    static void Unbind() {
        glBindBuffer(buffer_t, 0);
        oglwrap_CheckError();
    }

    // Data uploads
    /// Creates and initializes a buffer object's data store.
    /// @param size - Specifies the size in bytes of the buffer object's new data store.
    /// @param data - Specifies a pointer to data that will be copied into the data store for initialization, or NULL if no data is to be copied.
    /// @param usage - Specifies the expected usage pattern of the data store.
    /// @see glBufferData
    template<typename GLtype>
    static void Data(GLsizei size, const GLtype* data,
                     BufferUsage usage = BufferUsage::StaticDraw) {
        glBufferData(buffer_t, size, data, usage);
        oglwrap_CheckError();
    }

    /// Creates and initializes a buffer object's data store.
    /// @param data - Specifies a vector of data to upload.
    /// @param usage - Specifies the expected usage pattern of the data store.
    /// @see glBufferData
    template<typename GLtype>
    static void Data(const std::vector<GLtype>& data,
                     BufferUsage usage = BufferUsage::StaticDraw) {
        glBufferData(buffer_t, data.size() * sizeof(GLtype), data.data(), usage);
        oglwrap_CheckError();
    }

    /// Updates a subset of a buffer object's data store.
    /// @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
    /// @param size - Specifies the size in bytes of the data store region being replaced.
    /// @param data - Specifies a pointer to the new data that will be copied into the data store.
    /// @see glBufferSubData
    template<typename GLtype>
    static void SubData(GLintptr offset, GLsizei size, const GLtype* data) {
        glBufferSubData(buffer_t, offset, size, data);
        oglwrap_CheckError();
    }

    /// Updates a subset of a buffer object's data store.
    /// @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
    /// @param data - Specifies a vector containing the new data that will be copied into the data store.
    /// @see glBufferSubData
    template<typename GLtype>
    static void SubData(GLintptr offset, const std::vector<GLtype>& data) {
        glBufferSubData(buffer_t, offset, data.size() * sizeof(GLtype), data.data());
        oglwrap_CheckError();
    }

    // Size
    /// A getter for the buffer's size.
    /// @return The size of the buffer currently bound to the buffer objects default target in bytes.
    /// @see glGetBufferParameteriv, GL_BUFFER_SIZE
    static size_t Size() {
        GLint data;
        glGetBufferParameteriv(buffer_t, GL_BUFFER_SIZE, &data);
        oglwrap_CheckError();
        return data;
    }
    /// Returns the GLint handle for the buffer used by the C OpenGL API.
    GLint Expose() const {
        return buffer;
    }
};

typedef BufferObject<BufferType::Array>          Buffer;
/// The buffer will be used as a source for vertex data, but only when VertexAttribArray::Pointer​ is called.
/// @see GL_ARRAY_BUFFER

typedef BufferObject<BufferType::ElementArray>   IndexBuffer;
/// All rendering functions of the form gl*Draw*Elements*​ will use the pointer field as a byte offset from
/// the beginning of the buffer object bound to this target. The indices used for indexed rendering will be
/// taken from the buffer object. Note that this binding target is part of a Vertex Array Objects state, so a
/// VAO must be bound before binding a buffer here.
/// @see GL_ELEMENT_ARRAY_BUFFER

typedef BufferObject<BufferType::Texture>        TextureBuffer;
/// This buffer has no special semantics, it is intended to use as a buffer object for Buffer Textures.
/// @see GL_TEXTURE_BUFFER


template<IndexedBufferType buffer_t>
/** Buffer Objects are OpenGL Objects that store an array
    of unformatted memory allocated by the OpenGL context (aka: the GPU).
    IndexBufferObject is a buffer that is bound to an indexed target.
**/
class IndexedBufferObject : public BufferObject<BufferType(buffer_t)> {
public:
    /// Bind a buffer object to an index.
    /// @param index - Specify the index of the binding point within the array.
    /// @see glBindBufferBase
    void BindBase(GLuint index) {
        glBindBufferBase(buffer_t, index, BufferObject<buffer_t>::buffer);
        oglwrap_CheckError();
    }

    /// Bind a range within a buffer object to an index.
    /// @param index - Specify the index of the binding point within the array.
    /// @param offset - The starting offset in basic machine units into the buffer object.
    /// @param size - The amount of data in machine units that can be read from the buffet object while used as an indexed target.
    /// @see glBindBufferRange
    void BindRange(GLuint index, GLintptr offset, GLsizeiptr size) {
        glBindBufferRange(buffer_t, index, offset, size, BufferObject<buffer_t>::buffer);
        oglwrap_CheckError();
    }

    /// Unbind a buffer object from an index.
    /// @param index - Specify the index of the binding point within the array.
    /// @see glBindBufferBase
    static void UnbindBase(GLuint index) {
        glBindBufferBase(buffer_t, index, 0);
        oglwrap_CheckError();
    }
};

typedef IndexedBufferObject<IndexedBufferType::Uniform>             UniformBuffer;
/// An indexed buffer binding for buffers used as storage for uniform blocks.
/// @see GL_UNIFORM_BUFFER

typedef IndexedBufferObject<IndexedBufferType::TransformFeedback>   TransformFeedbackBuffer;
/// An indexed buffer binding for buffers used in Transform Feedback operations.
/// @see GL_TRANSFORM_FEEDBACK_BUFFER


} // namespace oglwrap

#endif // BUFFER_HPP
