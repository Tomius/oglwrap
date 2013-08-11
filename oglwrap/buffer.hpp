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
        oglwrap_PreCheckError();

        glGenBuffers(1, &buffer);
    }

    /// Deletes the buffer generated in the constructor.
    /// @see glDeleteBuffers
    ~BufferObject() {
        oglwrap_PreCheckError();

        if(!isDeletable())
            return;
        glDeleteBuffers(1, &buffer);
    }

    // Binds
    /// Bind a buffer object to its default target.
    /// @see glBindBuffer
    void Bind() {
        oglwrap_PreCheckError();

        glBindBuffer(buffer_t, buffer);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_VALUE,
            "Was unable to create buffer object. Probably tried to initialize it \n"
            "before creating the OpenGL context. Did you declare the buffer global or \n"
            "static?"
        );
    }

    // Unbinds
    /// Unbind a buffer object from its default target.
    /// @see glBindBuffer
    static void Unbind() {
        oglwrap_PreCheckError();

        glBindBuffer(buffer_t, 0);
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
        oglwrap_PreCheckError();

        glBufferData(buffer_t, size, data, usage);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_VALUE,
            "BufferObject::Data was called with a negative size parameter."
        );
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "BufferObject::Data was called without a bound buffer for this target."
        );
        oglwrap_PrintError(
            GL_OUT_OF_MEMORY,
            "BufferObject::Data - GL was unable to create a data store with the specified size."
        );
    }

    /// Creates and initializes a buffer object's data store.
    /// @param data - Specifies a vector of data to upload.
    /// @param usage - Specifies the expected usage pattern of the data store.
    /// @see glBufferData
    template<typename GLtype>
    static void Data(const std::vector<GLtype>& data,
                     BufferUsage usage = BufferUsage::StaticDraw) {
        oglwrap_PreCheckError();

        glBufferData(buffer_t, data.size() * sizeof(GLtype), data.data(), usage);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "BufferObject::Data was called without a bound buffer for this target."
        );
        oglwrap_PrintError(
            GL_OUT_OF_MEMORY,
            "BufferObject::Data - GL was unable to create a data store with the specified size."
        );
    }

    /// Updates a subset of a buffer object's data store.
    /// @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
    /// @param size - Specifies the size in bytes of the data store region being replaced.
    /// @param data - Specifies a pointer to the new data that will be copied into the data store.
    /// @see glBufferSubData
    template<typename GLtype>
    static void SubData(GLintptr offset, GLsizei size, const GLtype* data) {
        oglwrap_PreCheckError();

        glBufferSubData(buffer_t, offset, size, data);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_VALUE,
            "BufferObject::Data was called with negative size or offset parameter."
        );
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "BufferObject::Data was either called without a bound buffer "
            "for this target, or the bound target was mapped."
        );
    }

    /// Updates a subset of a buffer object's data store.
    /// @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
    /// @param data - Specifies a vector containing the new data that will be copied into the data store.
    /// @see glBufferSubData
    template<typename GLtype>
    static void SubData(GLintptr offset, const std::vector<GLtype>& data) {
        oglwrap_PreCheckError();

        glBufferSubData(buffer_t, offset, data.size() * sizeof(GLtype), data.data());

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_VALUE,
            "BufferObject::Data was called with offset parameter."
        );
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "BufferObject::Data was either called without a bound buffer "
            "for this target, or the bound target was mapped."
        );
    }

    // Size
    /// A getter for the buffer's size.
    /// @return The size of the buffer currently bound to the buffer objects default target in bytes.
    /// @see glGetBufferParameteriv, GL_BUFFER_SIZE
    static size_t Size() {
        oglwrap_PreCheckError();

        GLint data;
        glGetBufferParameteriv(buffer_t, GL_BUFFER_SIZE, &data);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "BufferObject::Size was called without a bound buffer."
        );
        return data;
    }
    /// Returns the GLint handle for the buffer used by the C OpenGL API.
    GLint Expose() const {
        oglwrap_PreCheckError();

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
        oglwrap_PreCheckError();

        glBindBufferBase(buffer_t, index, BufferObject<buffer_t>::buffer);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_VALUE,
            "IndexedBufferObject::BindBase was called either with an index greater "
            "than the number of target-specific indexed binding points, or the "
            "buffer does not have an associated data store, or the size of that "
            "store is zero"
        );
    }

    /// Bind a range within a buffer object to an index.
    /// @param index - Specify the index of the binding point within the array.
    /// @param offset - The starting offset in basic machine units into the buffer object.
    /// @param size - The amount of data in machine units that can be read from the buffet object while used as an indexed target.
    /// @see glBindBufferRange
    void BindRange(GLuint index, GLintptr offset, GLsizeiptr size) {
        oglwrap_PreCheckError();

        glBindBufferRange(buffer_t, index, offset, size, BufferObject<buffer_t>::buffer);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_VALUE,
            "IndexedBufferObject::glBindBufferRange was called either with an index greater "
            "than the number of target-specific indexed binding points, or the "
            "buffer does not have an associated data store, or the size of that "
            "store is zero"
        );
    }

    /// Unbind a buffer object from an index.
    /// @param index - Specify the index of the binding point within the array.
    /// @see glBindBufferBase
    static void UnbindBase(GLuint index) {
        oglwrap_PreCheckError();

        glBindBufferBase(buffer_t, index, 0);
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
