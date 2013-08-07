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

template<BufferType buffer_t>
class BufferObject : protected RefCounted {
    GLuint buffer;
public:
    BufferObject();
    ~BufferObject();

    // Binds
    void Bind();
    void BindBase(GLuint index);
    void BindRange(GLuint index, GLintptr offset, GLsizeiptr size);

    // Unbinds
    static void Unbind();
    static void UnbindBase(GLuint index);

    // Data uploads
    template<typename GLtype>
    static void Data(GLsizei count, const GLtype* data,
                     BufferUsage usage = BufferUsage::StaticDraw);
    template<typename GLtype>
    static void Data(const std::vector<GLtype>& data,
                     BufferUsage usage = BufferUsage::StaticDraw);
    template<typename GLtype>
    static void SubData(GLsizei count, GLintptr offset, const GLtype* data,
                        BufferUsage usage = BufferUsage::StaticDraw);
    template<typename GLtype>
    static void SubData(const std::vector<GLtype>& data, GLintptr offset,
                        BufferUsage usage = BufferUsage::StaticDraw);

    // Size
    static size_t Size(GLuint target = buffer_t);
    GLint Expose() const;
};

typedef BufferObject<BufferType::Array>               Buffer;
typedef BufferObject<BufferType::ElementArray>        IndexBuffer;
typedef BufferObject<BufferType::Uniform>             UniformBuffer;
typedef BufferObject<BufferType::Texture>             TextureBuffer;
typedef BufferObject<BufferType::TransformFeedback>   TransformFeedbackBuffer;



//         //=====:==-==-==:=====\\                                   //=====:==-==-==:=====\\
//  <---<}>==~=~=~==--==--==~=~=~==<{>----- Class definitions -----<}>==~=~=~==--==--==~=~=~==<{>--->
//         \\=====:==-==-==:=====//                                   \\=====:==-==-==:=====//



// -------======{[ Buffer definitions ]}======-------

template<BufferType buffer_t>
BufferObject<buffer_t>::BufferObject() {
    glGenBuffers(1, &buffer);
    oglwrap_CheckError();
}

template<BufferType buffer_t>
BufferObject<buffer_t>::~BufferObject() {
    if(!isDeleteable())
        return;
    glDeleteBuffers(1, &buffer);
    oglwrap_CheckError();
}

// Binds
template<BufferType buffer_t>
void BufferObject<buffer_t>::Bind() {
    glBindBuffer(buffer_t, buffer);
    oglwrap_CheckError();
}

template<BufferType buffer_t>
void BufferObject<buffer_t>::BindBase(GLuint index) {
    glBindBufferBase(buffer_t, index, buffer);
    oglwrap_CheckError();
}

template<BufferType buffer_t>
void BufferObject<buffer_t>::BindRange(GLuint index, GLintptr offset, GLsizeiptr size) {
    glBindBufferRange(buffer_t, index, offset, size, buffer);
    oglwrap_CheckError();
}

// Unbinds
template<BufferType buffer_t>
void BufferObject<buffer_t>::Unbind() {
    glBindBuffer(buffer_t, 0);
    oglwrap_CheckError();
}

template<BufferType buffer_t>
void BufferObject<buffer_t>::UnbindBase(GLuint index) {
    glBindBufferBase(buffer_t, index, 0);
    oglwrap_CheckError();
}

// Data uploads
template<BufferType buffer_t>
template<typename GLtype>
void BufferObject<buffer_t>::Data(GLsizei count, const GLtype* data, BufferUsage usage) {
    glBufferData(buffer_t, count * sizeof(GLtype), data, usage);
    oglwrap_CheckError();
}

template<BufferType buffer_t>
template<typename GLtype>
void BufferObject<buffer_t>::Data(const std::vector<GLtype>& data, BufferUsage usage) {
    glBufferData(buffer_t, data.size() * sizeof(GLtype), data.data(), usage);
    oglwrap_CheckError();
}

template<BufferType buffer_t>
template<typename GLtype>
void BufferObject<buffer_t>::SubData(GLsizei count, GLintptr offset, const GLtype* data, BufferUsage usage) {
    glBufferSubData(buffer_t, offset, count * sizeof(GLtype), data, usage);
    oglwrap_CheckError();
}

template<BufferType buffer_t>
template<typename GLtype>
void BufferObject<buffer_t>::SubData(const std::vector<GLtype>& data, GLintptr offset, BufferUsage usage) {
    glBufferData(buffer_t, offset, data.size() * sizeof(GLtype), data.data(), usage);
    oglwrap_CheckError();
}

// Size
template<BufferType buffer_t>
size_t BufferObject<buffer_t>::Size(GLuint target) {
    GLint data;
    glGetBufferParameteriv(target, GL_BUFFER_SIZE, &data);
    oglwrap_CheckError();
    return data;
}

template<BufferType buffer_t>
GLint BufferObject<buffer_t>::Expose() const {
    return buffer;
}

}

#endif // BUFFER_HPP
