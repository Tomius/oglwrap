/** @file vertexAttrib.hpp
    @brief Implements the VAO and the VertexAttributeArray.
*/

#ifndef OGLWRAP_VERTEXATTRIB_HPP_
#define OGLWRAP_VERTEXATTRIB_HPP_

#include <stdexcept>

#include "shader.hpp"
#include "config.hpp"
#include "general.hpp"
#include "debug/error.hpp"
#include "debug/binding.hpp"
#include "enums.hpp"

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/type_ptr.hpp"

namespace oglwrap {

namespace glObject {
  class VertexArray : public Object {
    void constructor() const { gl(GenVertexArrays(1, handle_)); }
    void destructor() const { gl(DeleteVertexArrays(1, handle_)); }
  };
}

// -------======{[ Vertex Array declaration ]}======-------
#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glGenVertexArrays) && defined(glDeleteVertexArrays))
/// VAO is an object that remembers which ArrayBuffers to use for a draw call.
/** A Vertex Array Object (VAO) is an object that encapsulates all of the
  * state needed to specify vertex data. They define the format of the vertex
  * data as well as the sources for the vertex arrays. Note that VAOs do not
  * contain the arrays themselves, the arrays are stored in ArrayBuffer Objects.
  * The VAOs simply reference already existing buffer objects.
  * @see glGenVertexArrays, glDeleteVertexArrays */
class VertexArray {
  glObject::VertexArray vao_; ///< The handle for the VAO
public:
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindVertexArray)
  /// Binds the Vertex Array object, so that it will be used for the further draw calls.
  /** @see glBindVertexArray */
  void bind() {
    gl(BindVertexArray(vao_));
  }
#endif

  /// Returns if this is the currently VAO
  /** @see glGetIntegerv */
  bool isBound() const {
    GLint currentlyBoundVAO;
    gl(GetIntegerv(GL_VERTEX_ARRAY_BINDING, &currentlyBoundVAO));
    OGLWRAP_LAST_BIND_TARGET = "GL_VERTEX_ARRAY_BINDING";
    return vao_ == GLuint(currentlyBoundVAO);
  }

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindVertexArray)
  /// Unbinds the currently active VAO.
  /** @see glBindVertexArray */
  static void Unbind() {
    gl(BindVertexArray(0));
  }
#endif

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindVertexArray)
  /// Unbinds the currently active VAO.
  /** @see glBindVertexArray */
  BIND_CHECKED void unbind() const {
    CHECK_BINDING2();
    Unbind();
  }
#endif

  /// Returns the handle for the VertexArray.
  const Object& expose() const {
    return vao_;
  }
};
#endif // glGenVertexArrays && glDeleteVertexArrays

// -------======{[ Vertex Attribute Array ]}======-------

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glGetAttribLocation)
/// Is used to set up an attribute.
/** VertexAttribArrayObject is used to setup the way data is uploaded to
  * the vertex shader attributes (the 'in' variables in the VS).
  * When the setup is called, the VAO will remember the currently
  * active ArrayBuffer and will use that for the draw calls */
class VertexAttribArrayObject {
protected:
  GLuint location_; /// < The vertexAttribSlot
  bool inited_; /// < For the LazyVertexAttribArray

  /// Init function for the for the LazyVertexAttribArray
  virtual void init() {
    inited_ = true;
  }
public:
  /// Default constructor, sets the location to invalid.
  VertexAttribArrayObject() : location_(INVALID_LOCATION), inited_(false) {}

  /// You can specify the attribute slot you use for the attribute.
  VertexAttribArrayObject(GLuint vertexAttribSlot) : location_(vertexAttribSlot), inited_(false) {}

private:
  template <class GLtype>
  /// A helper function for static setup
  /** @param value - The default value to be used for this attribute. */
  void static_setup_helper(const GLtype value) {
    throw std::invalid_argument(
      "Unrecognized OpenGL type for VertexAttribArrayObject static setup"
    );
  }

public:
  template <class GLtype>
  /// static setup of the Vertex Array (all of the values will be the same).
  /** Ints and doubles won't be converted to floats.
    * If you need a GLfixed value, use glVertexAttrib directly
    * @param value - The default value to be used for this attribute.
    * @see glVertexAttrib* */
  void static_setup(const GLtype value) {
    if(!inited_) {
      init();
    }

    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    static_setup_helper(value);
  }

  template <class GLtype>
  /// static setup of the Vertex Array (all of the values will be the same).
  /** Ints and doubles won't be converted to floats.
    * If you need a GLfixed value, use glVertexAttrib directly
    * @param value - The default value to be used for this attribute.
    * @see glVertexAttrib* */
  void operator=(const GLtype value) {
    static_setup(value);
  }

  template <class GLtype>
  /// Sets up an attribute. It can be templated with any OpenGL type or glm vector.
  /** Integers and doubles won't be converted to floats, if you want that call pointer()
    * So you can write setup<ivec3>(); instead of IPointer(3, WholeDataType::Int);
    * but if you want Pointer(3, DataType::Int) you explicitly have to call that function.
    * @param values_per_vertex - The dimension of the attribute data divided by the dimension of the template parameter.
    * @see glVertexAttribPointer, glVertexAttribIPointer, glVertexAttribLPointer */
  VertexAttribArrayObject& setup(GLuint values_per_vertex = 1) {
    throw std::invalid_argument("Unrecognized OpenGL type for VertexAttribArrayObject::setup");
    return *this;
  }

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glVertexAttribPointer) && defined(glVertexAttribIPointer))
  /// Sets up an attribute for arbitrary data type.
  /** Integers and doubles won't be converted to floats, if you want that call pointer()
    * So you can write setup<ivec3>(); instead of IPointer(3, WholeDataType::Int);
    * but if you want Pointer(3, DataType::Int) you explicitly have to call that function.
    * @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    * @param type - The data type of each component in the array.
    * @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    * @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    * @see glVertexAttribPointer, glVertexAttribIPointer, glVertexAttribLPointer */
  VertexAttribArrayObject setup(GLuint values_per_vertex,
                                DataType type,
                                GLsizei stride = 0,
                                const void *offset_pointer = nullptr) {
    switch(type) {
      case DataType::Float:
      case DataType::HalfFloat:
      case DataType::Fixed:
        pointer(values_per_vertex, type, false, stride, offset_pointer);
        break;
      case DataType::Double:
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribLPointer)
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
#endif // glVertexAttribPointer && glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribPointer)
  /// Sets up an attribute for float type data. You can upload any data type to it, but it will be converted to float.
  /** @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    * @param type - The data type of each component in the array.
    * @param normalized - specifies whether fixed-point data values should be normalized (GL_TRUE) or converted directly as fixed-point values (GL_FALSE) when they are accessed.
    * @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    * @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    * @see glVertexAttribPointer */
  VertexAttribArrayObject& pointer(GLuint values_per_vertex = 4,
                                   DataType type = DataType::Float,
                                   bool normalized = false,
                                   GLsizei stride = 0,
                                   const void *offset_pointer = nullptr) {
    if(!inited_) {
      init();
    }

    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_ARRAY_BUFFER_BINDING);

    gl(VertexAttribPointer(location_, values_per_vertex, type, normalized, stride, offset_pointer));
    return *this;
  }
#endif // glVertexAttribPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
  /// Sets up an attribute for integral type data.
  /** @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    * @param type - The data type of each component in the array.
    * @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    * @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    * @see glVertexAttribIPointer */
  VertexAttribArrayObject& ipointer(GLuint values_per_vertex = 4,
                                    WholeDataType type = WholeDataType::Int,
                                    GLsizei stride = 0,
                                    const void *offset_pointer = nullptr) {
    if(!inited_) {
      init();
    }

    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_ARRAY_BUFFER_BINDING);
    gl(VertexAttribIPointer(location_, values_per_vertex, type, stride, offset_pointer));
    return *this;
  }
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribLPointer)
  /// Sets up an attribute for double type data.
  /** @param values_per_vertex - The dimension of the attribute data. For example is 3 for a vec3. The initial value is 4.
    * @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    * @param offset_pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value is 0.
    * @see glVertexAttribLPointer */
  VertexAttribArrayObject& lpointer(GLuint values_per_vertex = 4,
                                    GLsizei stride = 0,
                                    const void *offset_pointer = nullptr) {
    if(!inited_) {
      init();
    }

    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_ARRAY_BUFFER_BINDING);
    gl(VertexAttribLPointer(location_, values_per_vertex, DataType::Double, stride, offset_pointer));
    return *this;
  }
#endif // glVertexAttribLPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribFormat)
  /// Specify the organization of vertex arrays.
  /** @param values_per_vertex - The number of values per vertex that are stored in the array.
    * @param type - The type of the data stored in the array.
    * @param normalized - Specifies whether fixed-point data values should be normalized (GL_TRUE) or converted directly as fixed-point values (GL_FALSE) when they are accessed.
    * @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    * @see glVertexAttribFormat */
  VertexAttribArrayObject& format(GLuint values_per_vertex = 4,
                                  DataType type = DataType::Float,
                                  GLboolean normalized = false,
                                  GLsizei stride = 0) {
    if(!inited_) {
      init();
    }

    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(VertexAttribFormat(location_, values_per_vertex, type, normalized, stride));
    return *this;
  }
#endif // glVertexAttribFormat

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIFormat)
  /// Specify the organization of vertex arrays. Should be used for integer values.
  /** @param values_per_vertex - The number of values per vertex that are stored in the array.
    * @param type - The type of the data stored in the array.
    * @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    * @see glVertexAttribIFormat */
  VertexAttribArrayObject& iformat(GLuint values_per_vertex = 4,
                                   WholeDataType type = WholeDataType::Int,
                                   GLsizei stride = 0) {
    if(!inited_) {
      init();
    }

    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(VertexAttribIFormat(location_, values_per_vertex, type, stride));
    return *this;
  }
#endif // glVertexAttribIFormat

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribLFormat)
  /// Specify the organization of vertex arrays. Should be used for double values.
  /** @param values_per_vertex - The number of values per vertex that are stored in the array.
    * @param stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
    * @see glVertexAttribLFormat */
  VertexAttribArrayObject& lformat(GLuint values_per_vertex = 4,
                                   GLsizei stride = 0) {
    if(!inited_) {
      init();
    }

    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(VertexAttribLFormat(location_, values_per_vertex, DataType::Double, stride));
    return *this;
  }
#endif // glVertexAttribLFormat

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glEnableVertexAttribArray)
  /// Enables the attribute array slot
  /** @see glEnableVertexAttribArray */
  VertexAttribArrayObject& enable() {
    if(!inited_) {
      init();
    }

    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(EnableVertexAttribArray(location_));
    return *this;
  }
#endif // glEnableVertexAttribArray

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDisableVertexAttribArray)
  /// Disables the attribute array slot
  /** @see glDisableVertexAttribArray */
  VertexAttribArrayObject& disable() {
    if(!inited_) {
      init();
    }

    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(DisableVertexAttribArray(location_));
    return *this;
  }
#endif // glDisableVertexAttribArray

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribDivisor)
  /// Modify the rate at which generic vertex attributes advance during instanced rendering
  /** @param divisor - Specify the number of instances that will pass between updates of the attribute.
    * @see glVertexAttribDivisor */
  VertexAttribArrayObject& divisor(GLuint divisor) {
    if(!inited_) {
      init();
    }

    CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(VertexAttribDivisor(location_, divisor));
    return *this;
  }
#endif // glVertexAttribDivisor

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindAttribLocation)
  /// Associates a generic vertex attribute index with a named attribute variable
  /** @param prog - Specifies the handle of the program object in which the association is to be made.
    * @param identifier - Specifies a null terminated string containing the name of the vertex shader attribute variable to which index is to be bound.
    * @see glBindAttribLocation */
  void bindLocation(const Program& prog, const std::string& identifier) const {
    gl(BindAttribLocation(prog.expose(), location_, identifier.c_str()));
  }
#endif

  /// Returns the locations of the VertexAttribArray
  GLuint expose() const {
    return location_;
  }
};

/// Is used to set up an attribute.
/** VertexAttribArrayObject is used to setup the way data is uploaded to
  * the vertex shader attributes (the 'in' variables in the VS).
  * When the setup is called, the VAO will remember the currently
  * active ArrayBuffer and will use that for the draw calls */
class VertexAttribArray : public VertexAttribArrayObject {
public:
  /// You can specify the attribute slot you use for the attribute
  VertexAttribArray(GLuint vertexAttribSlot) : VertexAttribArrayObject(vertexAttribSlot) {}

  /// You can query the location of the attribute using the attribute's name
  /** @param program - Specifies the program in which you want to setup an attribute.
    * @param identifier - Specifies the attribute's name you want to setup.
    * @see glGetAttribLocation */
  VertexAttribArray(const Program& program, const std::string& identifier) {
    location_ = gl(GetAttribLocation(program.expose(), identifier.c_str()));
    if(location_ == INVALID_LOCATION) {
      debug_output.callback("Unable to get location of attribute '" + identifier + "'");
    }
  }
};

/// Is used to set up an attribute.
/** VertexAttribArrayObject is used to setup the way data is uploaded to
  * the vertex shader attributes (the 'in' variables in the VS).
  * When the setup is called, the VAO will remember the currently
  * active ArrayBuffer and will use that for the draw calls */
class LazyVertexAttribArray : public VertexAttribArrayObject {
  const Program& program_;
  const std::string identifier_;
  const bool isArray_;

  /// Queries the location of the attribute using the attribute's name
  /** @see glGetAttribLocation */
  void init() {
    CHECK_ACTIVE_PROGRAM(program_);

    location_ = gl(GetAttribLocation(program_.expose(), identifier_.c_str()));
    if(location_ == INVALID_LOCATION) {
      debug_output.callback("Unable to get location of attribute '" + identifier_ + "'");
    }

    inited_ = true;
  }
public:
  /// Saves the details of the vertex attribute, but will only query the location at the first use.
  /** @param program - Specifies the program in which you want to setup an attribute.
    * @param identifier - Specifies the attribute's name you want to setup.
    * @param isArray - Specifies if the attribute is an array.
    * @see glGetAttribLocation */
  LazyVertexAttribArray(const Program& program, const std::string& identifier, bool isArray = true)
    : program_(program)
    , identifier_(identifier)
    , isArray_(isArray)
  {}

  LazyVertexAttribArray operator[](unsigned char idx) {
    if(isArray_) {
      return LazyVertexAttribArray(program_, identifier_ + '[' + static_cast<const char>(idx + '0') + ']', isArray_);
    } else {
      return LazyVertexAttribArray(program_, identifier_ + static_cast<const char>(idx + '0'), isArray_);
    }
  }

  operator VertexAttribArray() {
    return VertexAttribArray(program_, identifier_);
  }

  /// Associates a generic vertex attribute index with a named attribute variable
  /** @param index - Specifies the index of the generic vertex attribute to be bound.
    * @see glBindAttribLocation */
  void bindLocation(GLuint index) const {
    gl(BindAttribLocation(program_.expose(), index, identifier_.c_str()));
  }
};



// -------======{[ VertexAttribArrayObject::setup specializations ]}======-------
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<GLfloat>(GLuint values_per_vertex) {
  pointer(values_per_vertex, DataType::Float);
  return *this;
}
#endif // glVertexAttribPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<GLbyte>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::Byte);
  return *this;
}
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<GLubyte>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::UnsignedByte);
  return *this;
}
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<GLshort>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::Short);
  return *this;
}
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<GLushort>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::UnsignedShort);
  return *this;
}
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<GLint>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::Int);
  return *this;
}
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<GLuint>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::UnsignedInt);
  return *this;
}
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::vec2>(GLuint) {
  pointer(2, DataType::Float);
  return *this;
}
#endif // glVertexAttribPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribLPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::dvec2>(GLuint) {
  lpointer(2);
  return *this;
}
#endif // glVertexAttribLPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::ivec2>(GLuint) {
  ipointer(2, WholeDataType::Int);
  return *this;
}
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::uvec2>(GLuint) {
  ipointer(2, WholeDataType::UnsignedInt);
  return *this;
}
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::vec3>(GLuint) {
  pointer(3, DataType::Float);
  return *this;
}
#endif // glVertexAttribPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribLPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::dvec3>(GLuint) {
  lpointer(3);
  return *this;
}
#endif // glVertexAttribLPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::ivec3>(GLuint) {
  ipointer(3, WholeDataType::Int);
  return *this;
}
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::uvec3>(GLuint) {
  ipointer(3, WholeDataType::UnsignedInt);
  return *this;
}
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::vec4>(GLuint) {
  pointer(4, DataType::Float);
  return *this;
}
#endif // glVertexAttribPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribLPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::dvec4>(GLuint) {
  lpointer(4);
  return *this;
}
#endif // glVertexAttribLPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::ivec4>(GLuint) {
  ipointer(4, WholeDataType::Int);
  return *this;
}
#endif // glVertexAttribIPointer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject& VertexAttribArrayObject::setup<glm::uvec4>(GLuint) {
  ipointer(4, WholeDataType::UnsignedInt);
  return *this;
}
#endif // glVertexAttribIPointer


// -------======{[ static setups ]}======-------


#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttrib1f)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const GLfloat value) {
  gl(VertexAttrib1f(location_, value));
}
#endif // glVertexAttrib1f

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttrib1s)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const GLshort value) {
  gl(VertexAttrib1s(location_, value));
}
#endif // glVertexAttrib1s

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribL1d)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const GLdouble value) {
  gl(VertexAttribL1d(location_, value));
}
#endif // glVertexAttribL1d

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribI1i)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const GLint value) {
  gl(VertexAttribI1i(location_, value));
}
#endif // glVertexAttribI1i

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribI1ui)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const GLuint value) {
  gl(VertexAttribI1ui(location_, value));
}
#endif // glVertexAttribI1ui


#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttrib2fv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::vec2 value) {
  gl(VertexAttrib2fv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttrib2fv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribL2dv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::dvec2 value) {
  gl(VertexAttribL2dv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribL2dv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribI2iv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::ivec2 value) {
  gl(VertexAttribI2iv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI2iv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribI2uiv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::uvec2 value) {
  gl(VertexAttribI2uiv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI2uiv


#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttrib3fv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::vec3 value) {
  gl(VertexAttrib3fv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttrib3fv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribL3dv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::dvec3 value) {
  gl(VertexAttribL3dv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribL3dv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribI3iv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::ivec3 value) {
  gl(VertexAttribI3iv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI3iv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribI3uiv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::uvec3 value) {
  gl(VertexAttribI3uiv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI3uiv


#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttrib4fv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::vec4 value) {
  gl(VertexAttrib4fv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttrib4fv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribL4dv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::dvec4 value) {
  gl(VertexAttribL4dv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribL4dv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribI4iv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::ivec4 value) {
  gl(VertexAttribI4iv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI4iv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glVertexAttribI4uiv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::uvec4 value) {
  gl(VertexAttribI4uiv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI4uiv

#endif // glGetAttribLocation

} // namespace oglwrap

#endif // OGLWRAP_VERTEXATTRIB_HPP_
