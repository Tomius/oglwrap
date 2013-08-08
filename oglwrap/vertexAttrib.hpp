#ifndef VERTEXATTRIB_HPP
#define VERTEXATTRIB_HPP

#include <string>
#include <GL/glew.h>

#include "error.hpp"
#include "enums.hpp"
#include "general.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace oglwrap {

// -------======{[ Vertex Array declaration ]}======-------

/// A Vertex Array Object (VAO) is an object that encapsulates all of the
/// state needed to specify vertex data. They define the format of the vertex
/// data as well as the sources for the vertex arrays. Note that VAOs do not
/// contain the arrays themselves; the arrays are stored in Buffer Objects.
/// The VAOs simply reference already existing buffer objects.
class VertexArray : protected RefCounted {
    GLuint vao; ///< The C handle for the VAO
public:
    /// Generates a VAO.
    /// @see glGenVertexArrays
    VertexArray() {
        glGenVertexArrays(1, &vao);
        oglwrap_CheckError();
    }

    /// If only one instance of this object
    /// exists, deletes the VAO it has created.
    /// @see glDeleteVertexArrays
    ~VertexArray() {
        if(!isDeletable())
            return;
        glDeleteVertexArrays(1, &vao);
        oglwrap_CheckError();
    }

    /// Binds the Vertex Array object, so that it will be used for the further draw calls.
    /// @see glBindVertexArray
    void Bind() {
        glBindVertexArray(vao);
        oglwrap_CheckError();
    }

    /// Unbinds the currently active VAO.
    /// @see glBindVertexArray
    static void Unbind() {
        glBindVertexArray(0);
        oglwrap_CheckError();
    }
};

// -------======{[ Vertex Attribute Array ]}======-------
/// VertexAttribArray is used to setup the way data is uploaded to
/// the vertex shader attributes (the 'in' variables in the VS).
class VertexAttribArray {
    GLuint location; /// < The vertexAttribSlot
public:
    // Constructors
    /// You can specify the attribute slot you use for the attribute, if you
    /// manually wrote layout(location = x) in ... into the vertex shader.
    VertexAttribArray(GLuint vertexAttribSlot) : location(vertexAttribSlot) {}

    /// You can query the location of the attribute using the attribute's name
    /// @param program - Specifies the program in which you want to setup an attribute.
    /// @param identifier - Specifies the attribute's name you want to setup.
    /// @see glGetAttribLocation
    VertexAttribArray(Program& program, const std::string& identifier) {
        location = glGetAttribLocation(program.Expose(), identifier.c_str());
        if(location == INVALID_LOCATION) {
            std::cerr << "Unable to get VertexAttribArray location of '" << identifier << "'" << std::endl;
        }
        oglwrap_CheckError();
    }

    // Setup functions
    template <class GLtype>
    /// Sets up an attribute. It can be templated with any OpenGL type or glm vector.
    /// So you can write Setup<ivec3>(); instead of IPointer(3, WholeDataType::Int);
    /// @param values_per_vertex - The dimension of the attribute data divided by the dimension of the template parameter.
    /// @see glVertexAttribPointer, glVertexAttribIPointer, glVertexAttribLPointer
    const VertexAttribArray& Setup(GLuint values_per_vertex = 1) const {
        throw std::invalid_argument("Unrecognized OpenGL type for VertexAttribArray::Setup");
        return *this;
    }

    /// Sets up an attribute for arbitrary data type.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param type - The data type of each component in the array.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribPointer, glVertexAttribIPointer, glVertexAttribLPointer
    const VertexAttribArray& Setup(GLuint values_per_vertex,
                                   DataType type,
                                   GLsizei stride = 0,
                                   void *offset_pointer = nullptr) const {
        switch (type) {
            case DataType::Float:
            case DataType::HalfFloat:
            case DataType::Fixed:
                Pointer(values_per_vertex, FloatDataType(type), false, stride, offset_pointer);
                break;
            case DataType::Double:
                LPointer(values_per_vertex, stride, nullptr);
                break;
            default:
                IPointer(values_per_vertex, WholeDataType(type), stride, offset_pointer);
                break;
        }
        return *this;
    }

    /// Sets up an attribute for float type data.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param type - The data type of each component in the array.
    /// @param normalized - specifies whether fixed-point data values should be normalized (GL_TRUE) or converted directly as fixed-point values (GL_FALSE) when they are accessed.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribPointer
    const VertexAttribArray& Pointer(GLuint values_per_vertex = 4,
                                     FloatDataType type = FloatDataType::Float,
                                     bool normalized = false,
                                     GLsizei stride = 0,
                                     void *offset_pointer = nullptr) const {
        glVertexAttribPointer(location, values_per_vertex, type, normalized, stride, offset_pointer);
        oglwrap_CheckError();
        return *this;
    }

    /// Sets up an attribute for integral type data.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param type - The data type of each component in the array.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribIPointer
    const VertexAttribArray& IPointer(GLuint values_per_vertex = 4,
                                      WholeDataType type = WholeDataType::Int,
                                      GLsizei stride = 0,
                                      void *offset_pointer = nullptr) const {
        glVertexAttribIPointer(location, values_per_vertex, type, stride, offset_pointer);
        oglwrap_CheckError();
        return *this;
    }

    /// Sets up an attribute for double type data.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribLPointer
    const VertexAttribArray& LPointer(GLuint values_per_vertex = 4,
                                      GLsizei stride = 0,
                                      void *offset_pointer = nullptr) const {
        glVertexAttribLPointer(location, values_per_vertex, DataType::Double, stride, offset_pointer);
        oglwrap_CheckError();
        return *this;
    }

    // Enable & Disable
    /// Enables the attribute array slot
    /// @see glEnableVertexAttribArray
    const VertexAttribArray& Enable() const {
        glEnableVertexAttribArray(location);
        oglwrap_CheckError();
        return *this;
    }

    /// Disables the attribute array slot
    /// @see glDisableVertexAttribArray
    const VertexAttribArray& Disable() const {
        glDisableVertexAttribArray(location);
        oglwrap_CheckError();
        return *this;
    }

    // Divisor
    /// Modify the rate at which generic vertex attributes advance during instanced rendering
    /// @param divisor - Specify the number of instances that will pass between updates of the attribute.
    /// @see glVertexAttribDivisor
    const VertexAttribArray& Divisor(GLuint divisor) const {
        glVertexAttribDivisor(location, divisor);
        oglwrap_CheckError();
        return *this;
    }
};

// -------======{[ VertexAttribArray::Setup specializations ]}======-------

template<>
inline const VertexAttribArray& VertexAttribArray::Setup<float>(GLuint values_per_vertex) const{
    Pointer(values_per_vertex, FloatDataType::Float);
    return *this;
}

template<>
inline const VertexAttribArray& VertexAttribArray::Setup<char>(GLuint values_per_vertex) const {
    IPointer(values_per_vertex, WholeDataType::Byte);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<unsigned char>(GLuint values_per_vertex) const {
    IPointer(values_per_vertex, WholeDataType::UnsignedByte);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<short>(GLuint values_per_vertex) const {
    IPointer(values_per_vertex, WholeDataType::Short);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<unsigned short>(GLuint values_per_vertex) const {
    IPointer(values_per_vertex, WholeDataType::UnsignedShort);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<int>(GLuint values_per_vertex) const {
    IPointer(values_per_vertex, WholeDataType::Int);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<unsigned int>(GLuint values_per_vertex) const {
    IPointer(values_per_vertex, WholeDataType::UnsignedInt);
    return *this;
}

template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::vec2>(GLuint) const {
    Pointer(2, FloatDataType::Float);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::dvec2>(GLuint) const {
    LPointer(2);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::ivec2>(GLuint) const {
    IPointer(2, WholeDataType::Int);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::uvec2>(GLuint) const {
    IPointer(2, WholeDataType::UnsignedInt);
    return *this;
}

template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::vec3>(GLuint) const {
    Pointer(3, FloatDataType::Float);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::dvec3>(GLuint) const {
    LPointer(3);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::ivec3>(GLuint) const {
    IPointer(3, WholeDataType::Int);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::uvec3>(GLuint) const {
    IPointer(3, WholeDataType::UnsignedInt);
    return *this;
}

template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::vec4>(GLuint) const {
    Pointer(4, FloatDataType::Float);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::dvec4>(GLuint) const {
    LPointer(4);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::ivec4>(GLuint) const {
    IPointer(4, WholeDataType::Int);
    return *this;
}
template<>
inline const VertexAttribArray& VertexAttribArray::Setup<glm::uvec4>(GLuint) const {
    IPointer(4, WholeDataType::UnsignedInt);
    return *this;
}


} // namespace oglwrap

#endif // VERTEXATTRIB_HPP
