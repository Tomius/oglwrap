// Copyright (c) 2014, Tamas Csala

/** @file vertex_attrib.h
    @brief Implements the VAO and the VertexAttributeArray.
*/

#ifndef OGLWRAP_VERTEX_ATTRIB_H_
#define OGLWRAP_VERTEX_ATTRIB_H_

#include <stdexcept>

#include "shader.h"
#include "config.h"
#include "general.h"
#include "globjects.h"
#include "debug/binding.h"

#include "enums/data_type.h"
#include "enums/whole_data_type.h"

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/type_ptr.hpp"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

// -------======{[ Vertex Array declaration ]}======-------

#if OGLWRAP_DEFINE_EVERYTHING \
    || (defined(glGenVertexArrays) && defined(glDeleteVertexArrays))
/**
 * @brief VAO is an object that remembers which ArrayBuffers to use for a
 *        draw call.
 *
 * A Vertex Array glObject (VAO) is an object that encapsulates all of the
 * state needed to specify vertex data. They define the format of the vertex
 * data as well as the sources for the vertex arrays. Note that VAOs do not
 * contain the arrays themselves, the arrays are stored in ArrayBuffer Objects.
 * The VAOs simply reference already existing buffer objects.
 * @see glGenVertexArrays, glDeleteVertexArrays
 */
class VertexArray {
  globjects::VertexArray vao_; ///< The handle for the VAO
public:
#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindVertexArray)
  /**
   * @brief Binds the Vertex Array object, so that it will be used for the
   *        further draw calls.
   * @see glBindVertexArray
   */
  void bind() const {
    gl(BindVertexArray(vao_));
  }
#endif

  /// Returns if this is the currently VAO
  /** @see glGetIntegerv */
  bool isBound() const {
    GLint currentlyBoundVAO;
    gl(GetIntegerv(GL_VERTEX_ARRAY_BINDING, &currentlyBoundVAO));

    #if OGLWRAP_DEBUG
      DebugOutput::LastUsedBindTarget() = "GL_VERTEX_ARRAY_BINDING";
    #endif

    return vao_ == GLuint(currentlyBoundVAO);
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindVertexArray)
  /// Unbinds the currently active VAO.
  /** @see glBindVertexArray */
  static void Unbind() {
    gl(BindVertexArray(0));
  }
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindVertexArray)
  /// Unbinds the currently active VAO.
  /** @see glBindVertexArray */
  BIND_CHECKED void unbind() const {
    OGLWRAP_CHECK_BINDING2();
    Unbind();
  }
#endif

  /// Returns the handle for the VertexArray.
  const glObject& expose() const {
    return vao_;
  }
};
#endif // glGenVertexArrays && glDeleteVertexArrays

// -------======{[ Vertex Attribute Array ]}======-------

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetAttribLocation)
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

  static constexpr GLuint kInvalidLocation = ~GLuint(0);

public:
  /// Default constructor, sets the location to invalid.
  VertexAttribArrayObject()
    : location_(this->kInvalidLocation), inited_(false) {}

  /// You can specify the attribute slot you use for the attribute.
  VertexAttribArrayObject(GLuint vertexAttribSlot)
    : location_(vertexAttribSlot), inited_(false) {}

private:
  template <typename GLtype>
  /// A helper function for static setup
  /** @param value The default value to be used for this attribute. */
  void static_setup_helper(const GLtype value) {
   static_assert((sizeof(GLtype), false),
    "Unrecognized OpenGL type for VertexAttribArrayObject::static_setup"
    );
  }

public:
  template <typename GLtype>
  /// static setup of the Vertex Array (all of the values will be the same).
  /** Ints and doubles won't be converted to floats.
    * If you need a GLfixed value, use glVertexAttrib directly
    * @param value The default value to be used for this attribute.
    * @see glVertexAttrib* */
  void static_setup(const GLtype value) {
    if (!inited_) {
      init();
    }

    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    static_setup_helper(value);
  }

  template <typename GLtype>
  /// static setup of the Vertex Array (all of the values will be the same).
  /** Ints and doubles won't be converted to floats.
    * If you need a GLfixed value, use glVertexAttrib directly
    * @param value The default value to be used for this attribute.
    * @see glVertexAttrib* */
  void operator=(const GLtype value) {
    static_setup(value);
  }

  template <typename GLtype>
  /**
   * @brief Sets up an attribute. It can be templated with any OpenGL type or
   *        glm vector.
   *
   * Integers and doubles won't be converted to floats, if you want that call
   * pointer(). So you can write setup<ivec3>(); instead of
   * IPointer(3, WholeDataType::Int); but if you want
   * Pointer(3, DataType::Int) you explicitly have to call that function.
   * @param values_per_vertex The dimension of the attribute data divided by
   *                          the dimension of the template parameter.
   * @see glVertexAttribPointer, glVertexAttribIPointer, glVertexAttribLPointer
   */
  VertexAttribArrayObject& setup(GLuint values_per_vertex = 1) {
    static_assert((sizeof(GLtype), false),
      "Unrecognized OpenGL type for VertexAttribArrayObject::setup"
    );
    return *this;
  }

#if OGLWRAP_DEFINE_EVERYTHING \
    || (defined(glVertexAttribPointer) && defined(glVertexAttribIPointer))
  /**
   * @brief Sets up an attribute for arbitrary data type.
   *
   * Integers and doubles won't be converted to floats, if you want that call
   * pointer(). So you can write setup<ivec3>(); instead of
   * IPointer(3, WholeDataType::Int); but if you want Pointer(3, DataType::Int)
   * you explicitly have to call that function.
   *
   * @param values_per_vertex  The dimension of the attribute data. For example
   *                           is 3 for a vec3. The initial value is 4.
   * @param type               The data type of each component in the array.
   * @param stride             Specifies the byte offset between consecutive
   *                           generic vertex attributes. If stride is 0, the
   *                           generic vertex attributes are understood to be
   *                           tightly packed in the array. The initial value
   *                           is 0.
   * @param offset_pointer     Specifies a offset of the first component of the
   *                           first generic vertex attribute in the array in
   *                           the data store of the buffer currently bound to
   *                           the GL_ARRAY_BUFFER target. The initial value
   *                           is 0.
   * @see glVertexAttribPointer, glVertexAttribIPointer, glVertexAttribLPointer
   */
  VertexAttribArrayObject setup(GLuint values_per_vertex,
                                DataType type,
                                GLsizei stride = 0,
                                const void *offset_pointer = nullptr) {
    switch (type) {
      case DataType::kFloat:
      case DataType::kHalfFloat:
      case DataType::kFixed:
        pointer(values_per_vertex, type, false, stride, offset_pointer);
        break;
      case DataType::kDouble:
#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribLPointer)
        lpointer(values_per_vertex, stride, nullptr);
#else
        throw std::runtime_error(
          "VertexAttribArrayObject::setup() is called with DataType::double, "
          "but the glVertexAttribLPointer symbol is missing."
        );
#endif // glVertexAttribLPointer
        break;
      default:
        ipointer(
          values_per_vertex, WholeDataType(type), stride, offset_pointer
        );
        break;
    }
    return *this;
  }
#endif // glVertexAttribPointer && glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribPointer)
  /**
   * @brief Sets up an attribute for float type data. You can upload any data
   *        type to it, but it will be converted to float.
   *
   * @param values_per_vertex   The dimension of the attribute data. For example
   *                            is 3 for a vec3. The initial value is 4.
   * @param type                The data type of each component in the array.
   * @param normalized          Specifies whether fixed-point data values should
   *                            be normalized (GL_TRUE) or converted directly as
   *                            fixed-point values (GL_FALSE) when they are
   *                            accessed.
   * @param stride              Specifies the byte offset between consecutive
   *                            generic vertex attributes. If stride is 0, the
   *                            generic vertex attributes are understood to be
   *                            tightly packed in the array. The initial value
   *                            is 0.
   * @param offset_pointer      Specifies a offset of the first component of the
   *                            first generic vertex attribute in the array in
   *                            the data store of the buffer currently bound to
   *                            the GL_ARRAY_BUFFER target. The initial value
   *                            is 0.
   * @see glVertexAttribPointer
   */
  VertexAttribArrayObject& pointer(GLuint values_per_vertex = 4,
                                   DataType type = DataType::kFloat,
                                   bool normalized = false,
                                   GLsizei stride = 0,
                                   const void *offset_pointer = nullptr) {
    if (!inited_) {
      init();
    }

    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_ARRAY_BUFFER_BINDING);

    gl(VertexAttribPointer(
      location_, values_per_vertex, GLenum(type),
      normalized, stride, offset_pointer
    ));
    return *this;
  }
#endif // glVertexAttribPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
  /**
   * @brief Sets up an attribute for integral type data.
   *
   * @param values_per_vertex   The dimension of the attribute data. For example
   *                            is 3 for a vec3. The initial value is 4.
   * @param type                The data type of each component in the array.
   * @param stride              Specifies the byte offset between consecutive
   *                            generic vertex attributes. If stride is 0, the
   *                            generic vertex attributes are understood to be
   *                            tightly packed in the array. The initial value
   *                            is 0.
   * @param offset_pointer      Specifies a offset of the first component of the
   *                            first generic vertex attribute in the array in
   *                            the data store of the buffer currently bound to
   *                            the GL_ARRAY_BUFFER target. The initial value
   *                            is 0.
   * @see glVertexAttribIPointer
   */
  VertexAttribArrayObject& ipointer(GLuint values_per_vertex = 4,
                                    WholeDataType type = WholeDataType::kInt,
                                    GLsizei stride = 0,
                                    const void *offset_pointer = nullptr) {
    if (!inited_) {
      init();
    }

    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_ARRAY_BUFFER_BINDING);
    gl(VertexAttribIPointer(
      location_, values_per_vertex, GLenum(type),
      stride, offset_pointer
    ));
    return *this;
  }
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribLPointer)
  /**
   * @brief Sets up an attribute for double type data.
   *
   * @param values_per_vertex   The dimension of the attribute data. For example
   *                            is 3 for a vec3. The initial value is 4.
   * @param stride              Specifies the byte offset between consecutive
   *                            generic vertex attributes. If stride is 0, the
   *                            generic vertex attributes are understood to be
   *                            tightly packed in the array. The initial value
   *                            is 0.
   * @param offset_pointer      Specifies a offset of the first component of the
   *                            first generic vertex attribute in the array in
   *                            the data store of the buffer currently bound to
   *                            the GL_ARRAY_BUFFER target. The initial value
   *                            is 0.
   * @see glVertexAttribLPointer
   */
  VertexAttribArrayObject& lpointer(GLuint values_per_vertex = 4,
                                    GLsizei stride = 0,
                                    const void *offset_pointer = nullptr) {
    if (!inited_) {
      init();
    }

    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_ARRAY_BUFFER_BINDING);
    gl(VertexAttribLPointer(
      location_, values_per_vertex, GL_DOUBLE, stride, offset_pointer
    ));
    return *this;
  }
#endif // glVertexAttribLPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribFormat)
  /**
   * @brief Specify the organization of vertex arrays.
   *
   * @param values_per_vertex   The number of values per vertex that are stored
   *                            in the array.
   * @param type                The type of the data stored in the array.
   * @param normalized          Specifies whether fixed-point data values should
   *                            be normalized (GL_TRUE) or converted directly as
   *                            fixed-point values (GL_FALSE) when they are
   *                            accessed.
   * @param stride              Specifies the byte offset between consecutive
   *                            generic vertex attributes. If stride is 0, the
   *                            generic vertex attributes are understood to be
   *                            tightly packed in the array. The initial value
   *                            is 0.
   * @see glVertexAttribFormat
   */
  VertexAttribArrayObject& format(GLuint values_per_vertex = 4,
                                  DataType type = DataType::kFloat,
                                  GLboolean normalized = false,
                                  GLsizei stride = 0) {
    if (!inited_) {
      init();
    }

    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(VertexAttribFormat(
      location_, values_per_vertex, GLenum(type), normalized, stride
    ));
    return *this;
  }
#endif // glVertexAttribFormat

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIFormat)
  ///
  /**
   * @brief Specify the organization of vertex arrays. Should be used for
   *        integer values.
   *
   * @param values_per_vertex   The number of values per vertex that are stored
   *                            in the array.
   * @param type                The type of the data stored in the array.
   * @param stride              Specifies the byte offset between consecutive
   *                            generic vertex attributes. If stride is 0, the
   *                            generic vertex attributes are understood to be
   *                            tightly packed in the array. The initial value
   *                            is 0.
   * @see glVertexAttribIFormat
   */
  VertexAttribArrayObject& iformat(GLuint values_per_vertex = 4,
                                   WholeDataType type = WholeDataType::kInt,
                                   GLsizei stride = 0) {
    if (!inited_) {
      init();
    }

    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(VertexAttribIFormat(
      location_, values_per_vertex, GLenum(type), stride
    ));
    return *this;
  }
#endif // glVertexAttribIFormat

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribLFormat)
  /**
   * @brief Specify the organization of vertex arrays. Should be used for
   *        double values.
   *
   * @param values_per_vertex   The number of values per vertex that are stored
   *                            in the array.
   * @param stride              Specifies the byte offset between consecutive
   *                            generic vertex attributes. If stride is 0, the
   *                            generic vertex attributes are understood to be
   *                            tightly packed in the array. The initial value
   *                            is 0.
   * @see glVertexAttribLFormat
   */
  VertexAttribArrayObject& lformat(GLuint values_per_vertex = 4,
                                   GLsizei stride = 0) {
    if (!inited_) {
      init();
    }

    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(VertexAttribLFormat(
      location_, values_per_vertex, GL_DOUBLE, stride
    ));
    return *this;
  }
#endif // glVertexAttribLFormat

#if OGLWRAP_DEFINE_EVERYTHING || defined(glEnableVertexAttribArray)
  /// Enables the attribute array slot
  /** @see glEnableVertexAttribArray */
  VertexAttribArrayObject& enable() {
    if (!inited_) {
      init();
    }

    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(EnableVertexAttribArray(location_));
    return *this;
  }
#endif // glEnableVertexAttribArray

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDisableVertexAttribArray)
  /// Disables the attribute array slot
  /** @see glDisableVertexAttribArray */
  VertexAttribArrayObject& disable() {
    if (!inited_) {
      init();
    }

    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(DisableVertexAttribArray(location_));
    return *this;
  }
#endif // glDisableVertexAttribArray

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribDivisor)
  /**
   * @brief Modify the rate at which generic vertex attributes advance during
   *        instanced rendering.
   *
   * @param divisor Specify the number of instances that will pass between
   *                updates of the attribute.
   * @see glVertexAttribDivisor
   */
  VertexAttribArrayObject& divisor(GLuint divisor) {
    if (!inited_) {
      init();
    }

    OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(GL_VERTEX_ARRAY_BINDING);
    gl(VertexAttribDivisor(location_, divisor));
    return *this;
  }
#endif // glVertexAttribDivisor

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindAttribLocation)
  /**
   * @brief Associates a generic vertex attribute index with a named attribute
   *        variable.
   *
   * @param prog         Specifies the handle of the program object in which the
   *                     association is to be made.
   * @param identifier   Specifies a null terminated string containing the name
   *                     of the vertex shader attribute variable to which index
   *                     is to be bound.
   * @see glBindAttribLocation
   */
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
  VertexAttribArray(GLuint vertexAttribSlot)
    : VertexAttribArrayObject(vertexAttribSlot) {}

  /**
   * @brief You can query the location of the attribute using the attribute's
   *        name.
   *
   * @param program     Specifies the program in which you want to setup an
   *                    attribute.
   * @param identifier  Specifies the attribute's name you want to setup.
   * @see glGetAttribLocation
   */
  VertexAttribArray(const Program& program, const std::string& identifier) {
    location_ = gl(GetAttribLocation(program.expose(), identifier.c_str()));
    if (location_ == this->kInvalidLocation) {
      OGLWRAP_PRINT_ERROR(
        "Error getting attribute location",
        "Unable to get location of attribute '" + identifier + "'"
      );
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
    OGLWRAP_CHECK_ACTIVE_PROGRAM(program_);

    location_ = gl(GetAttribLocation(program_.expose(), identifier_.c_str()));
    if (location_ == this->kInvalidLocation) {
      OGLWRAP_PRINT_ERROR(
        "Error getting attribute location",
        "Unable to get location of attribute '" + identifier_ + "'"
      );
    }

    inited_ = true;
  }
public:
  /**
   * @brief Saves the details of the vertex attribute, but will only query the
   *        location at the first use.
   *
   * @param program     Specifies the program in which you want to setup an
   *                    attribute.
   * @param identifier  Specifies the attribute's name you want to setup.
   * @param isArray     Specifies if the attribute is an array.
   * @see glGetAttribLocation
   */
  LazyVertexAttribArray(const Program& program,
                        const std::string& identifier,
                        bool isArray = true)
    : program_(program)
    , identifier_(identifier)
    , isArray_(isArray)
  {}

  LazyVertexAttribArray operator[](unsigned char idx) {
    if (isArray_) {
      return LazyVertexAttribArray(
        program_, identifier_ +
        '[' + static_cast<const char>(idx + '0') + ']', isArray_
      );
    } else {
      return LazyVertexAttribArray(
        program_, identifier_ +
        static_cast<const char>(idx + '0'), isArray_
      );
    }
  }

  operator VertexAttribArray() {
    return VertexAttribArray(program_, identifier_);
  }

  /**
   * @brief Associates a generic vertex attribute index with a named attribute
   *        variable.
   *
   * @param index  Specifies the index of the generic vertex attribute to be
   *               bound.
   * @see glBindAttribLocation */
  void bindLocation(GLuint index) const {
    gl(BindAttribLocation(program_.expose(), index, identifier_.c_str()));
  }
};



// -------======{[ VertexAttribArrayObject::setup specializations ]}======-------
#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<GLfloat>(GLuint values_per_vertex) {
  pointer(values_per_vertex, DataType::kFloat);
  return *this;
}
#endif // glVertexAttribPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<GLbyte>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::kByte);
  return *this;
}
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<GLubyte>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::kUnsignedByte);
  return *this;
}
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<GLshort>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::kShort);
  return *this;
}
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<GLushort>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::kUnsignedShort);
  return *this;
}
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<GLint>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::kInt);
  return *this;
}
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<GLuint>(GLuint values_per_vertex) {
  ipointer(values_per_vertex, WholeDataType::kUnsignedInt);
  return *this;
}
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::vec2>(GLuint) {
  pointer(2, DataType::kFloat);
  return *this;
}
#endif // glVertexAttribPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribLPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::dvec2>(GLuint) {
  lpointer(2);
  return *this;
}
#endif // glVertexAttribLPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::ivec2>(GLuint) {
  ipointer(2, WholeDataType::kInt);
  return *this;
}
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::uvec2>(GLuint) {
  ipointer(2, WholeDataType::kUnsignedInt);
  return *this;
}
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::vec3>(GLuint) {
  pointer(3, DataType::kFloat);
  return *this;
}
#endif // glVertexAttribPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribLPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::dvec3>(GLuint) {
  lpointer(3);
  return *this;
}
#endif // glVertexAttribLPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::ivec3>(GLuint) {
  ipointer(3, WholeDataType::kInt);
  return *this;
}
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::uvec3>(GLuint) {
  ipointer(3, WholeDataType::kUnsignedInt);
  return *this;
}
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::vec4>(GLuint) {
  pointer(4, DataType::kFloat);
  return *this;
}
#endif // glVertexAttribPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribLPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::dvec4>(GLuint) {
  lpointer(4);
  return *this;
}
#endif // glVertexAttribLPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::ivec4>(GLuint) {
  ipointer(4, WholeDataType::kInt);
  return *this;
}
#endif // glVertexAttribIPointer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribIPointer)
template<>
inline VertexAttribArrayObject&
VertexAttribArrayObject::setup<glm::uvec4>(GLuint) {
  ipointer(4, WholeDataType::kUnsignedInt);
  return *this;
}
#endif // glVertexAttribIPointer


// -------======{[ static setups ]}======-------


#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttrib1f)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const GLfloat value) {
  gl(VertexAttrib1f(location_, value));
}
#endif // glVertexAttrib1f

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttrib1s)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const GLshort value) {
  gl(VertexAttrib1s(location_, value));
}
#endif // glVertexAttrib1s

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribL1d)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const GLdouble value) {
  gl(VertexAttribL1d(location_, value));
}
#endif // glVertexAttribL1d

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribI1i)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const GLint value) {
  gl(VertexAttribI1i(location_, value));
}
#endif // glVertexAttribI1i

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribI1ui)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const GLuint value) {
  gl(VertexAttribI1ui(location_, value));
}
#endif // glVertexAttribI1ui


#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttrib2fv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::vec2 value) {
  gl(VertexAttrib2fv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttrib2fv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribL2dv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::dvec2 value) {
  gl(VertexAttribL2dv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribL2dv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribI2iv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::ivec2 value) {
  gl(VertexAttribI2iv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI2iv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribI2uiv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::uvec2 value) {
  gl(VertexAttribI2uiv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI2uiv


#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttrib3fv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::vec3 value) {
  gl(VertexAttrib3fv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttrib3fv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribL3dv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::dvec3 value) {
  gl(VertexAttribL3dv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribL3dv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribI3iv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::ivec3 value) {
  gl(VertexAttribI3iv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI3iv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribI3uiv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::uvec3 value) {
  gl(VertexAttribI3uiv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI3uiv


#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttrib4fv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::vec4 value) {
  gl(VertexAttrib4fv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttrib4fv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribL4dv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::dvec4 value) {
  gl(VertexAttribL4dv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribL4dv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribI4iv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::ivec4 value) {
  gl(VertexAttribI4iv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI4iv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glVertexAttribI4uiv)
template<>
inline void VertexAttribArrayObject::static_setup_helper(const glm::uvec4 value) {
  gl(VertexAttribI4uiv(location_, glm::value_ptr(value)));
}
#endif // glVertexAttribI4uiv

/// A global operator that is a VertexArray constructor with nicer syntax.
/** I think (prog | "Position") does look better than VertexAttribArray(prog, "Position") */
inline LazyVertexAttribArray operator|(const Program& prog,
                                       const std::string& file) {
  return LazyVertexAttribArray(prog, file);
}

#endif // glGetAttribLocation

} // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif // OGLWRAP_VERTEXATTRIB_H_
