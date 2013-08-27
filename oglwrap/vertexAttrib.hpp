/** @file vertexAttrib.hpp
    @brief Implements the VAO and the VertexAttributeArray.
*/

#ifndef VERTEXATTRIB_HPP
#define VERTEXATTRIB_HPP

namespace oglwrap {

// -------======{[ Vertex Array declaration ]}======-------

/// VAO is an object that remembers which ArrayBuffers to use for a draw call.
/** A Vertex Array Object (VAO) is an object that encapsulates all of the
  * state needed to specify vertex data. They define the format of the vertex
  * data as well as the sources for the vertex arrays. Note that VAOs do not
  * contain the arrays themselves, the arrays are stored in ArrayBuffer Objects.
  * The VAOs simply reference already existing buffer objects. */
/// @see glGenVertexArrays, glDeleteVertexArrays
class VertexArray {
    ObjectExt<glGenVertexArrays, glDeleteVertexArrays> vao; ///< The handle for the VAO
public:
    /// Binds the Vertex Array object, so that it will be used for the further draw calls.
    /// @see glBindVertexArray
    void Bind() {
        gl( BindVertexArray(vao) );
    }

    /// Unbinds the currently active VAO.
    /// @see glBindVertexArray
    static void Unbind() {
        gl( BindVertexArray(0) );
    }

    /// Returns the handle for the VertexArray.
    const ObjectExt<glGenVertexArrays, glDeleteVertexArrays>& Expose() const {
        return vao;
    }
};

// -------======{[ Vertex Attribute Array ]}======-------

/// Is used to set up an attribute.
/** VertexAttribArrayObject is used to setup the way data is uploaded to
  * the vertex shader attributes (the 'in' variables in the VS).
  * When the setup is called, the VAO will remember the currently
  * active ArrayBuffer and will use that for the draw calls */
class VertexAttribArrayObject {
protected:
    GLuint location; /// < The vertexAttribSlot
    bool inited; /// < For the LazyVertexAttribArray
    /// Init function for the for the LazyVertexAttribArray
    virtual void Init() {
        inited = true;
    }
public:
    /// Default constructor, sets the location to invalid.
    VertexAttribArrayObject() : location(INVALID_LOCATION) ,inited(false) {}
    /// @brief You can specify the attribute slot you use for the attribute.
    VertexAttribArrayObject(GLuint vertexAttribSlot) : location(vertexAttribSlot) ,inited(false) {}

    template <class GLtype>
    /// @brief Sets up an attribute. It can be templated with any OpenGL type or glm vector.
    /** So you can write Setup<ivec3>(); instead of IPointer(3, WholeDataType::Int); */
    /// @param values_per_vertex - The dimension of the attribute data divided by the dimension of the template parameter.
    /// @see glVertexAttribPointer, glVertexAttribIPointer, glVertexAttribLPointer
    VertexAttribArrayObject& Setup(GLuint values_per_vertex = 1) {
        throw std::invalid_argument("Unrecognized OpenGL type for VertexAttribArrayObject::Setup");
        return *this;
    }

    /// @brief Sets up an attribute for arbitrary data type.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param type - The data type of each component in the array.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribPointer, glVertexAttribIPointer, glVertexAttribLPointer
    VertexAttribArrayObject Setup(GLuint values_per_vertex,
                                   DataType type,
                                   GLsizei stride = 0,
                                   const void *offset_pointer = nullptr) {
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

    /// @brief Sets up an attribute for float type data.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param type - The data type of each component in the array.
    /// @param normalized - specifies whether fixed-point data values should be normalized (GL_TRUE) or converted directly as fixed-point values (GL_FALSE) when they are accessed.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribPointer
    VertexAttribArrayObject& Pointer(GLuint values_per_vertex = 4,
                                     FloatDataType type = FloatDataType::Float,
                                     bool normalized = false,
                                     GLsizei stride = 0,
                                     const void *offset_pointer = nullptr) {
        if(!inited)
            Init();

        gl( VertexAttribPointer(location, values_per_vertex, type, normalized, stride, offset_pointer) );

        oglwrap_PrintError(
            GL_INVALID_VALUE,
            "VertexAttribArrayObject::Pointer is called with an attribute index greater than "
            "or equal to GL_MAX_VERTEX_ATTRIBS, or size is different than 1, 2, 3, 4, or stride is negative."
        );
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "VertexAttribArrayObject::Pointer is called, but type and values_per_vertex mismatch."
        );
        return *this;
    }

    /// @brief Sets up an attribute for integral type data.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param type - The data type of each component in the array.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribIPointer
    VertexAttribArrayObject& IPointer(GLuint values_per_vertex = 4,
                                      WholeDataType type = WholeDataType::Int,
                                      GLsizei stride = 0,
                                      const void *offset_pointer = nullptr) {
        if(!inited)
            Init();

        gl( VertexAttribIPointer(location, values_per_vertex, type, stride, offset_pointer) );

        oglwrap_PrintError(
            GL_INVALID_VALUE,
            "VertexAttribArrayObject::IPointer is called with an attribute index greater than "
            "or equal to GL_MAX_VERTEX_ATTRIBS, or size is different than 1, 2, 3, 4, or stride is negative."
        );
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "VertexAttribArrayObject::IPointer is called, but type and values_per_vertex mismatch."
        );
        return *this;
    }

    /// @brief Sets up an attribute for double type data.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribLPointer
    VertexAttribArrayObject& LPointer(GLuint values_per_vertex = 4,
                                      GLsizei stride = 0,
                                      const void *offset_pointer = nullptr) {
        if(!inited)
            Init();

        gl( VertexAttribLPointer(location, values_per_vertex, DataType::Double, stride, offset_pointer) );

        oglwrap_PrintError(
            GL_INVALID_VALUE,
            "VertexAttribArrayObject::LPointer is called with an attribute index greater than "
            "or equal to GL_MAX_VERTEX_ATTRIBS, or size is different than 1, 2, 3, 4, or stride is negative."
        );
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "VertexAttribArrayObject::LPointer is called, but type and values_per_vertex mismatch."
        );
        return *this;
    }

    /// @brief Enables the attribute array slot
    /// @see glEnableVertexAttribArray
    VertexAttribArrayObject& Enable() {
        if(!inited)
            Init();

        gl( EnableVertexAttribArray(location) );
        return *this;
    }

    /// @brief Disables the attribute array slot
    /// @see glDisableVertexAttribArray
    VertexAttribArrayObject& Disable() {
        if(!inited)
            Init();

        gl( DisableVertexAttribArray(location) );
        return *this;
    }

    /// @brief Modify the rate at which generic vertex attributes advance during instanced rendering
    /// @param divisor - Specify the number of instances that will pass between updates of the attribute.
    /// @see glVertexAttribDivisor
    VertexAttribArrayObject& Divisor(GLuint divisor) {
        if(!inited)
            Init();

        gl( VertexAttribDivisor(location, divisor) );
        return *this;
    }
};

class VertexAttribArray : public VertexAttribArrayObject {
public:
    /// @brief You can specify the attribute slot you use for the attribute
    VertexAttribArray(GLuint vertexAttribSlot) : VertexAttribArrayObject(vertexAttribSlot) {}

    /// @brief You can query the location of the attribute using the attribute's name
    /// @param program - Specifies the program in which you want to setup an attribute.
    /// @param identifier - Specifies the attribute's name you want to setup.
    /// @see glGetAttribLocation
    VertexAttribArray(const Program& program, const std::string& identifier) {
        location = gl( GetAttribLocation(program.Expose(), identifier.c_str()) );
        if(location == INVALID_LOCATION) {
            std::cerr << "Unable to get location of attribute '" << identifier << "'" << std::endl;
        }

        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "VertexAttribArray constructor is called with a program, that isn't linked successfully."
        );
    }
};

class LazyVertexAttribArray : public VertexAttribArrayObject {
    const Program& program;
    const std::string identifier;
    /// @brief Queries the location of the attribute using the attribute's name
    /// @see glGetAttribLocation
    void Init() {
        location = gl( GetAttribLocation(program.Expose(), identifier.c_str()) );
        if(location == INVALID_LOCATION) {
            std::cerr << "Unable to get location of attribute '" << identifier << "'" << std::endl;
        }

        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "LazyVertexAttribArray isn't able to query the attribute location, "
            "because the program it is called with isn't linked successfully."
        );
        inited = true;
    }
public:
    /// @brief Saves the details of the vertex attribute, but will only query the location at the first use.
    /// @param program - Specifies the program in which you want to setup an attribute.
    /// @param identifier - Specifies the attribute's name you want to setup.
    /// @see glGetAttribLocation
    LazyVertexAttribArray(const Program& program, const std::string& identifier)
        : program(program)
        , identifier(identifier)
    {}

    LazyVertexAttribArray operator[](unsigned char idx) {
        return LazyVertexAttribArray(program, identifier + '[' + (const char)(idx + '0') + ']');
    }

    operator VertexAttribArray() {
        return VertexAttribArray(program, identifier);
    }
};



// -------======{[ VertexAttribArrayObject::Setup specializations ]}======-------

template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<float>(GLuint values_per_vertex) {
    Pointer(values_per_vertex, FloatDataType::Float);
    return *this;
}

template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<char>(GLuint values_per_vertex) {
    IPointer(values_per_vertex, WholeDataType::Byte);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<unsigned char>(GLuint values_per_vertex) {
    IPointer(values_per_vertex, WholeDataType::UnsignedByte);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<short>(GLuint values_per_vertex) {
    IPointer(values_per_vertex, WholeDataType::Short);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<unsigned short>(GLuint values_per_vertex) {
    IPointer(values_per_vertex, WholeDataType::UnsignedShort);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<int>(GLuint values_per_vertex) {
    IPointer(values_per_vertex, WholeDataType::Int);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<unsigned int>(GLuint values_per_vertex) {
    IPointer(values_per_vertex, WholeDataType::UnsignedInt);
    return *this;
}

template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::vec2>(GLuint) {
    Pointer(2, FloatDataType::Float);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::dvec2>(GLuint) {
    LPointer(2);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::ivec2>(GLuint) {
    IPointer(2, WholeDataType::Int);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::uvec2>(GLuint) {
    IPointer(2, WholeDataType::UnsignedInt);
    return *this;
}

template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::vec3>(GLuint) {
    Pointer(3, FloatDataType::Float);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::dvec3>(GLuint) {
    LPointer(3);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::ivec3>(GLuint) {
    IPointer(3, WholeDataType::Int);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::uvec3>(GLuint) {
    IPointer(3, WholeDataType::UnsignedInt);
    return *this;
}

template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::vec4>(GLuint) {
    Pointer(4, FloatDataType::Float);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::dvec4>(GLuint) {
    LPointer(4);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::ivec4>(GLuint) {
    IPointer(4, WholeDataType::Int);
    return *this;
}
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::Setup<glm::uvec4>(GLuint) {
    IPointer(4, WholeDataType::UnsignedInt);
    return *this;
}


} // namespace oglwrap

#endif // VERTEXATTRIB_HPP
