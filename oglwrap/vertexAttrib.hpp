/** @file vertexAttrib.hpp
    @brief Implements the VAO and the VertexAttributeArray.
*/

#pragma once

namespace oglwrap {

// -------======{[ Vertex Array declaration ]}======-------
#ifdef glGenVertexArrays
#ifdef glDeleteVertexArrays
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
    #ifdef glBindVertexArray
    /// Binds the Vertex Array object, so that it will be used for the further draw calls.
    /// @see glBindVertexArray
    void bind() {
        gl( BindVertexArray(vao) );
    }
    #endif

    #ifdef glBindVertexArray
    /// Unbinds the currently active VAO.
    /// @see glBindVertexArray
    static void unbind() {
        gl( BindVertexArray(0) );
    }
    #endif

    /// Returns the handle for the VertexArray.
    const ObjectExt<glGenVertexArrays, glDeleteVertexArrays>& expose() const {
        return vao;
    }
};
#endif // glDeleteVertexArrays
#endif // glGenVertexArrays

// -------======{[ Vertex Attribute Array ]}======-------

#ifdef glGetAttribLocation
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
    /** So you can write setup<ivec3>(); instead of IPointer(3, WholeDataType::Int); */
    /// @param values_per_vertex - The dimension of the attribute data divided by the dimension of the template parameter.
    /// @see glVertexAttribPointer, glVertexAttribIPointer, glVertexAttribLPointer
    VertexAttribArrayObject& setup(GLuint values_per_vertex = 1) {
        throw std::invalid_argument("Unrecognized OpenGL type for VertexAttribArrayObject::setup");
        return *this;
    }

    #ifdef glVertexAttribPointer
    #ifdef glVertexAttribIPointer
    /// @brief Sets up an attribute for arbitrary data type.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param type - The data type of each component in the array.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribPointer, glVertexAttribIPointer, glVertexAttribLPointer
    VertexAttribArrayObject setup(GLuint values_per_vertex,
                                   DataType type,
                                   GLsizei stride = 0,
                                   const void *offset_pointer = nullptr) {
        switch (type) {
            case DataType::Float:
            case DataType::HalfFloat:
            case DataType::Fixed:
                pointer(values_per_vertex, FloatDataType(type), false, stride, offset_pointer);
                break;
            case DataType::Double:
                #ifdef glVertexAttribLPointer
                lpointer(values_per_vertex, stride, nullptr);
                #else
                throw std::runtime_error(
                    "VertexAttribArrayObject::setup() is called with DataType::double, "
                    "but the glVertexAttribLPointer symbol is missing."
                );
                #endif // glVertexAttribLPointer
                break;
            default:
                ipointer(values_per_vertex, WholeDataType(type), stride, offset_pointer);
                break;
        }
        return *this;
    }
    #endif // glVertexAttribIPointer
    #endif // glVertexAttribPointer

    #ifdef glVertexAttribPointer
    /// @brief Sets up an attribute for float type data.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param type - The data type of each component in the array.
    /// @param normalized - specifies whether fixed-point data values should be normalized (GL_TRUE) or converted directly as fixed-point values (GL_FALSE) when they are accessed.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribPointer
    VertexAttribArrayObject& pointer(GLuint values_per_vertex = 4,
                                     FloatDataType type = FloatDataType::Float,
                                     bool normalized = false,
                                     GLsizei stride = 0,
                                     const void *offset_pointer = nullptr) {
        if(!inited)
            Init();

        gl( VertexAttribPointer(location, values_per_vertex, type, normalized, stride, offset_pointer) );
        return *this;
    }
    #endif // glVertexAttribPointer

    #ifdef glVertexAttribIPointer
    /// @brief Sets up an attribute for integral type data.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param type - The data type of each component in the array.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribIPointer
    VertexAttribArrayObject& ipointer(GLuint values_per_vertex = 4,
                                      WholeDataType type = WholeDataType::Int,
                                      GLsizei stride = 0,
                                      const void *offset_pointer = nullptr) {
        if(!inited)
            Init();

        gl( VertexAttribIPointer(location, values_per_vertex, type, stride, offset_pointer) );
        return *this;
    }
    #endif // glVertexAttribIPointer

    #ifdef glVertexAttribLPointer
    /// @brief Sets up an attribute for double type data.
    /// @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    /// @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    /// @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    /// @see glVertexAttribLPointer
    VertexAttribArrayObject& lpointer(GLuint values_per_vertex = 4,
                                      GLsizei stride = 0,
                                      const void *offset_pointer = nullptr) {
        if(!inited)
            Init();

        gl( VertexAttribLPointer(location, values_per_vertex, DataType::Double, stride, offset_pointer) );
        return *this;
    }
    #endif // glVertexAttribLPointer

    #ifdef glEnableVertexAttribArray
    /// @brief Enables the attribute array slot
    /// @see glEnableVertexAttribArray
    VertexAttribArrayObject& enable() {
        if(!inited)
            Init();

        gl( EnableVertexAttribArray(location) );
        return *this;
    }
    #endif // glEnableVertexAttribArray

    #ifdef glDisableVertexAttribArray
    /// @brief Disables the attribute array slot
    /// @see glDisableVertexAttribArray
    VertexAttribArrayObject& disable() {
        if(!inited)
            Init();

        gl( DisableVertexAttribArray(location) );
        return *this;
    }
    #endif // glDisableVertexAttribArray

    #ifdef glVertexAttribDivisor
    /// @brief Modify the rate at which generic vertex attributes advance during instanced rendering
    /// @param divisor - Specify the number of instances that will pass between updates of the attribute.
    /// @see glVertexAttribDivisor
    VertexAttribArrayObject& divisor(GLuint divisor) {
        if(!inited)
            Init();

        gl( VertexAttribDivisor(location, divisor) );
        return *this;
    }
    #endif // glVertexAttribDivisor
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
        location = gl( GetAttribLocation(program.expose(), identifier.c_str()) );
        if(location == INVALID_LOCATION) {
            std::cerr << "Unable to get location of attribute '" << identifier << "'" << std::endl;
        }
    }
};

class LazyVertexAttribArray : public VertexAttribArrayObject {
    const Program& program;
    const std::string identifier;
    /// @brief Queries the location of the attribute using the attribute's name
    /// @see glGetAttribLocation
    void Init() {
        location = gl( GetAttribLocation(program.expose(), identifier.c_str()) );
        if(location == INVALID_LOCATION) {
            std::cerr << "Unable to get location of attribute '" << identifier << "'" << std::endl;
        }

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



// -------======{[ VertexAttribArrayObject::setup specializations ]}======-------
#ifdef glVertexAttribPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<float>(GLuint values_per_vertex) {
    pointer(values_per_vertex, FloatDataType::Float);
    return *this;
}
#endif // glVertexAttribPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<char>(GLuint values_per_vertex) {
    ipointer(values_per_vertex, WholeDataType::Byte);
    return *this;
}
#endif // glVertexAttribIPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<unsigned char>(GLuint values_per_vertex) {
    ipointer(values_per_vertex, WholeDataType::UnsignedByte);
    return *this;
}
#endif // glVertexAttribIPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<short>(GLuint values_per_vertex) {
    ipointer(values_per_vertex, WholeDataType::Short);
    return *this;
}
#endif // glVertexAttribIPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<unsigned short>(GLuint values_per_vertex) {
    ipointer(values_per_vertex, WholeDataType::UnsignedShort);
    return *this;
}
#endif // glVertexAttribIPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<int>(GLuint values_per_vertex) {
    ipointer(values_per_vertex, WholeDataType::Int);
    return *this;
}
#endif // glVertexAttribIPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<unsigned int>(GLuint values_per_vertex) {
    ipointer(values_per_vertex, WholeDataType::UnsignedInt);
    return *this;
}
#endif // glVertexAttribIPointer

#ifdef glVertexAttribPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::vec2>(GLuint) {
    pointer(2, FloatDataType::Float);
    return *this;
}
#endif // glVertexAttribPointer

#ifdef glVertexAttribLPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::dvec2>(GLuint) {
    lpointer(2);
    return *this;
}
#endif // glVertexAttribLPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::ivec2>(GLuint) {
    ipointer(2, WholeDataType::Int);
    return *this;
}
#endif // glVertexAttribIPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::uvec2>(GLuint) {
    ipointer(2, WholeDataType::UnsignedInt);
    return *this;
}
#endif // glVertexAttribIPointer

#ifdef glVertexAttribPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::vec3>(GLuint) {
    pointer(3, FloatDataType::Float);
    return *this;
}
#endif // glVertexAttribPointer

#ifdef glVertexAttribLPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::dvec3>(GLuint) {
    lpointer(3);
    return *this;
}
#endif // glVertexAttribLPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::ivec3>(GLuint) {
    ipointer(3, WholeDataType::Int);
    return *this;
}
#endif // glVertexAttribIPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::uvec3>(GLuint) {
    ipointer(3, WholeDataType::UnsignedInt);
    return *this;
}
#endif // glVertexAttribIPointer

#ifdef glVertexAttribPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::vec4>(GLuint) {
    pointer(4, FloatDataType::Float);
    return *this;
}
#endif // glVertexAttribPointer

#ifdef glVertexAttribLPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::dvec4>(GLuint) {
    lpointer(4);
    return *this;
}
#endif // glVertexAttribLPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::ivec4>(GLuint) {
    ipointer(4, WholeDataType::Int);
    return *this;
}
#endif // glVertexAttribIPointer

#ifdef glVertexAttribIPointer
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::uvec4>(GLuint) {
    ipointer(4, WholeDataType::UnsignedInt);
    return *this;
}
#endif // glVertexAttribIPointer

#endif // glGetAttribLocation

} // namespace oglwrap
