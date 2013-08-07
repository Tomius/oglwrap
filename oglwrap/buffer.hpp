#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <vector>
#include <string>
#include <GL/glew.h>

#include "error.h"
#include "enums.hpp"
#include "general.hpp"

namespace oglwrap {

// -------======{[ Buffer definitions ]}======-------

/** Buffer Objects are OpenGL Objects that store an array
    of unformatted memory allocated by the OpenGL context (aka: the GPU).
    These can be used to store vertex data, pixel data retrieved from
    images or the framebuffer, and a variety of other things.
**/
template<BufferType buffer_t>
class GeneralBufferObject : protected RefCounted {
protected:
    GLuint buffer;
public:
    /// Generates a buffer object.
    /// @see glGenBuffers
    GeneralBufferObject();

    /// Deletes the buffer generated in the constructor.
    /// @see glDeleteBuffers
    ~GeneralBufferObject();

    // Binds
    /// Bind a buffer object to its default target.
    /// @see glBindBuffer
    void Bind();

    // Unbinds
    /// Unbind a buffer object from its default target.
    /// @see glBindBuffer
    static void Unbind();

    // Data uploads
    /// Creates and initializes a buffer object's data store.
    /// @param size - Specifies the size in bytes of the buffer object's new data store.
    /// @param data - Specifies a pointer to data that will be copied into the data store for initialization, or NULL if no data is to be copied.
    /// @param usage - Specifies the expected usage pattern of the data store.
    /// @see glBufferData
    template<typename GLtype>
    static void Data(GLsizei size, const GLtype* data,
                     BufferUsage usage = BufferUsage::StaticDraw);

    /// Creates and initializes a buffer object's data store.
    /// @param data - Specifies a vector of data to upload.
    /// @param usage - Specifies the expected usage pattern of the data store.
    /// @see glBufferData
    template<typename GLtype>
    static void Data(const std::vector<GLtype>& data,
                     BufferUsage usage = BufferUsage::StaticDraw);

    /// Updates a subset of a buffer object's data store.
    /// @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
    /// @param size - Specifies the size in bytes of the data store region being replaced.
    /// @param data - Specifies a pointer to the new data that will be copied into the data store.
    /// @see glBufferSubData
    template<typename GLtype>
    static void SubData(GLintptr offset, GLsizei size, const GLtype* data);

    /// Updates a subset of a buffer object's data store.
    /// @param offset - Specifies the offset into the buffer object's data store where data replacement will begin, measured in bytes.
    /// @param data - Specifies a vector containing the new data that will be copied into the data store.
    /// @see glBufferSubData
    template<typename GLtype>
    static void SubData(GLintptr offset, const std::vector<GLtype>& data);

    // Size
    /// A getter for the buffer's size.
    /// @return The size of the buffer currently bound to the buffer objects default target in bytes.
    /// @see glGetBufferParameteriv, GL_BUFFER_SIZE
    static size_t Size();
    /// Returns the GLint handle for the buffer used by the C OpenGL API.
    GLint Expose() const;
};

/** Buffer Objects are OpenGL Objects that store an array
    of unformatted memory allocated by the OpenGL context (aka: the GPU).
    These can be used to store vertex data, pixel data retrieved from
    images or the framebuffer, and a variety of other things.
**/
template<NotIndexedBufferType buffer_t>
class BufferObject : public GeneralBufferObject<BufferType(buffer_t)>
{};


/** Buffer Objects are OpenGL Objects that store an array
    of unformatted memory allocated by the OpenGL context (aka: the GPU).
    IndexBufferObject is a buffer that is bound to an indexed target.
**/
template<IndexedBufferType buffer_t>
class IndexedBufferObject : public GeneralBufferObject<BufferType(buffer_t)> {
public:
    /// Bind a buffer object to an index.
    /// @param index - Specify the index of the binding point within the array.
    /// @see glBindBufferBase
    void BindBase(GLuint index);

    /// Bind a range within a buffer object to an index.
    /// @param index - Specify the index of the binding point within the array.
    /// @param offset - The starting offset in basic machine units into the buffer object.
    /// @param size - The amount of data in machine units that can be read from the buffet object while used as an indexed target.
    /// @see glBindBufferRange
    void BindRange(GLuint index, GLintptr offset, GLsizeiptr size);

    /// Unbind a buffer object from an index.
    /// @param index - Specify the index of the binding point within the array.
    /// @see glBindBufferBase
    static void UnbindBase(GLuint index);
};

/** Buffer Objects are OpenGL Objects that store an array
    of unformatted memory allocated by the OpenGL context (aka: the GPU).
    These can be used to store vertex data, pixel data retrieved from
    images or the framebuffer, and a variety of other things.
**/
typedef BufferObject<NotIndexedBufferType::Array>          Buffer;
/** Buffer Objects are OpenGL Objects that store an array
    of unformatted memory allocated by the OpenGL context (aka: the GPU).
    These can be used to store vertex data, pixel data retrieved from
    images or the framebuffer, and a variety of other things.
**/
typedef BufferObject<NotIndexedBufferType::ElementArray>   IndexBuffer;
/** Buffer Objects are OpenGL Objects that store an array
    of unformatted memory allocated by the OpenGL context (aka: the GPU).
    These can be used to store vertex data, pixel data retrieved from
    images or the framebuffer, and a variety of other things.
**/
typedef BufferObject<NotIndexedBufferType::Texture>        TextureBuffer;

/** Buffer Objects are OpenGL Objects that store an array
    of unformatted memory allocated by the OpenGL context (aka: the GPU).
    IndexBufferObject is a buffer that is bound to an indexed target.
**/
typedef IndexedBufferObject<IndexedBufferType::Uniform>             UniformBuffer;
/** Buffer Objects are OpenGL Objects that store an array
    of unformatted memory allocated by the OpenGL context (aka: the GPU).
    IndexBufferObject is a buffer that is bound to an indexed target.
**/
typedef IndexedBufferObject<IndexedBufferType::TransformFeedback>   TransformFeedbackBuffer;



//         //=====:==-==-==:=====\\                                   //=====:==-==-==:=====\\
//  <---<}>==~=~=~==--==--==~=~=~==<{>----- Class definitions -----<}>==~=~=~==--==--==~=~=~==<{>--->
//         \\=====:==-==-==:=====//                                   \\=====:==-==-==:=====//



// -------======{[ GeneralBufferObject definitions ]}======-------

template<BufferType buffer_t>
GeneralBufferObject<buffer_t>::GeneralBufferObject() {
    glGenBuffers(1, &buffer);
    oglwrap_CheckError();
}

template<BufferType buffer_t>
GeneralBufferObject<buffer_t>::~GeneralBufferObject() {
    if(!isDeleteable())
        return;
    glDeleteBuffers(1, &buffer);
    oglwrap_CheckError();
}

// Binds
template<BufferType buffer_t>
void GeneralBufferObject<buffer_t>::Bind() {
    glBindBuffer(buffer_t, buffer);
    oglwrap_CheckError();
}

// Unbinds
template<BufferType buffer_t>
void GeneralBufferObject<buffer_t>::Unbind() {
    glBindBuffer(buffer_t, 0);
    oglwrap_CheckError();
}

// Data uploads
template<BufferType buffer_t>
template<typename GLtype>
void GeneralBufferObject<buffer_t>::Data(GLsizei size, const GLtype* data, BufferUsage usage) {
    glBufferData(buffer_t, size, data, usage);
    oglwrap_CheckError();
}

template<BufferType buffer_t>
template<typename GLtype>
void GeneralBufferObject<buffer_t>::Data(const std::vector<GLtype>& data, BufferUsage usage) {
    glBufferData(buffer_t, data.size() * sizeof(GLtype), data.data(), usage);
    oglwrap_CheckError();
}

template<BufferType buffer_t>
template<typename GLtype>
void GeneralBufferObject<buffer_t>::SubData(GLintptr offset, GLsizei size, const GLtype* data) {
    glBufferSubData(buffer_t, offset, size, data);
    oglwrap_CheckError();
}

template<BufferType buffer_t>
template<typename GLtype>
void GeneralBufferObject<buffer_t>::SubData(GLintptr offset, const std::vector<GLtype>& data) {
    glBufferSubData(buffer_t, offset, data.size() * sizeof(GLtype), data.data());
    oglwrap_CheckError();
}

// Size
template<BufferType buffer_t>
size_t GeneralBufferObject<buffer_t>::Size() {
    GLint data;
    glGetBufferParameteriv(buffer_t, GL_BUFFER_SIZE, &data);
    oglwrap_CheckError();
    return data;
}

template<BufferType buffer_t>
GLint GeneralBufferObject<buffer_t>::Expose() const {
    return buffer;
}

// -------======{[ Index Buffers ]}======-------

template<IndexedBufferType buffer_t>
void IndexedBufferObject<buffer_t>::BindBase(GLuint index) {
    glBindBufferBase(buffer_t, index, GeneralBufferObject<buffer_t>::buffer);
    oglwrap_CheckError();
}

template<IndexedBufferType buffer_t>
void IndexedBufferObject<buffer_t>::BindRange(GLuint index, GLintptr offset, GLsizeiptr size) {
    glBindBufferRange(buffer_t, index, offset, size, GeneralBufferObject<buffer_t>::buffer);
    oglwrap_CheckError();
}

template<IndexedBufferType buffer_t>
void IndexedBufferObject<buffer_t>::UnbindBase(GLuint index) {
    glBindBufferBase(buffer_t, index, 0);
    oglwrap_CheckError();
}

}

#endif // BUFFER_HPP
