#ifndef VERTEXATTRIB_HPP
#define VERTEXATTRIB_HPP

#include <string>
#include <GL/glew.h>

#include "error.h"
#include "enums.hpp"
#include "general.hpp"

namespace oglwrap {

// -------======{[ Vertex Array declaration ]}======-------

class VertexArray : protected RefCounted {
    GLuint vao;
public:
    VertexArray();
    ~VertexArray();
    void Bind();
    static void Unbind();
};

// -------======{[ Vertex Attribute Array declaration ]}======-------

class VertexAttribArray {
    GLuint location;
public:
    // Constructors
    VertexAttribArray(GLuint vertexAttribSlot);
    VertexAttribArray(Program& program, const std::string& identifier);

    // Setup functions
    const VertexAttribArray& Pointer(GLuint values_per_vertex,
                                     DataType type = DataType::Float,
                                     bool normalized = false,
                                     GLsizei stride = 0,
                                     void *offset_pointer = nullptr) const;
    const VertexAttribArray& IPointer(GLuint values_per_vertex,
                                      DataType type = DataType::Int,
                                      GLsizei stride = 0,
                                      void *offset_pointer = nullptr) const;
    const VertexAttribArray& LPointer(GLuint values_per_vertex,
                                      GLsizei stride = 0,
                                      void *offset_pointer = nullptr) const;
    // Enable & Disable
    const VertexAttribArray& Enable() const;
    const VertexAttribArray& Disable() const;

    // Divisor
    const VertexAttribArray& Divisor(GLuint divisor) const;
};



//         //=====:==-==-==:=====\\                                   //=====:==-==-==:=====\\
//  <---<}>==~=~=~==--==--==~=~=~==<{>----- Class definitions -----<}>==~=~=~==--==--==~=~=~==<{>--->
//         \\=====:==-==-==:=====//                                   \\=====:==-==-==:=====//



// -------======{[ VertexArray definition ]}======-------

inline VertexArray::VertexArray() {
    glGenVertexArrays(1, &vao);
    oglwrap_CheckError();
}
inline VertexArray::~VertexArray() {
    if(!isDeleteable())
        return;
    glDeleteVertexArrays(1, &vao);
    oglwrap_CheckError();
}
inline void VertexArray::Bind() {
    glBindVertexArray(vao);
    oglwrap_CheckError();
}
inline void VertexArray::Unbind() {
    glBindVertexArray(0);
    oglwrap_CheckError();
}


// -------======{[ Vertex Attribute Array definition ]}======-------

// Constructors
inline VertexAttribArray::VertexAttribArray(GLuint vertexAttribSlot) : location(vertexAttribSlot) {}

inline VertexAttribArray::VertexAttribArray(Program& program, const std::string& identifier) {
    location = glGetAttribLocation(program.Expose(), identifier.c_str());
    if(location == INVALID_LOCATION) {
        std::cerr << "Unable to get VertexAttribArray location of '" << identifier << "'" << std::endl;
    }
    oglwrap_CheckError();
}

// Setup functions
inline const VertexAttribArray& VertexAttribArray::Pointer(GLuint values_per_vertex,
                                 DataType type,
                                 bool normalized,
                                 GLsizei stride,
                                 void *offset_pointer) const {
    glVertexAttribPointer(location, values_per_vertex, type, normalized, stride, offset_pointer);
    oglwrap_CheckError();
    return *this;
}

inline const VertexAttribArray& VertexAttribArray::IPointer(GLuint values_per_vertex,
                                  DataType type,
                                  GLsizei stride,
                                  void *offset_pointer) const {
    glVertexAttribIPointer(location, values_per_vertex, type, stride, offset_pointer);
    oglwrap_CheckError();
    return *this;
}

inline const VertexAttribArray& VertexAttribArray::LPointer(GLuint values_per_vertex,
                                  GLsizei stride,
                                  void *offset_pointer) const {
    glVertexAttribLPointer(location, values_per_vertex, DataType::Double, stride, offset_pointer);
    oglwrap_CheckError();
    return *this;
}

// Enable & Disable
inline const VertexAttribArray& VertexAttribArray::Enable() const {
    glEnableVertexAttribArray(location);
    oglwrap_CheckError();
    return *this;
}

inline const VertexAttribArray& VertexAttribArray::Disable() const {
    glDisableVertexAttribArray(location);
    oglwrap_CheckError();
    return *this;
}

// Divisor
inline const VertexAttribArray& VertexAttribArray::Divisor(GLuint divisor) const {
    glVertexAttribDivisor(location, divisor);
    oglwrap_CheckError();
    return *this;
}

} // namespace oglwrap

#endif // VERTEXATTRIB_HPP
