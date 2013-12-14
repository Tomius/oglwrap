/** @file uniform.hpp
    @brief Implements GLSL uniform uploaders.
*/

#ifndef OGLWRAP_UNIFORM_HPP_
#define OGLWRAP_UNIFORM_HPP_

#include <stdexcept>

#include "config.hpp"
#include "enums.hpp"
#include "shader.hpp"

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/type_ptr.hpp"

namespace oglwrap {

// -------======{[ UniformObject ]}======-------
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glGetUniformLocation)
template<class GLtype>
/// An object implementing the base features Uniforms.
/** You shouldn't use this class directly. Rather use Uniform or LazyUniform. */
class UniformObject {
protected:
  GLuint location_; ///< The C handle for the uniform's location

  /// The handle defaults to INVALID_LOCATION
  UniformObject()
    : location_(INVALID_LOCATION) { }

  /// Sets the location handle.
  UniformObject(GLuint location)
    : location_(location) { }

  /// Sets the uniform to a GLtype variable's value.
  /** It finds the appropriate glUniform* using template specialization.
    * If it is called with not an OpenGL type, it throws std::invalid argument.
    * @param value - The value to set the uniform.
    * @see glUniform* */
  void set(const GLtype& value) { // See the specializations at the end of this file.
    throw std::invalid_argument("Trying to set a uniform to a value that is not an OpenGL type.");
  }

  /// Sets the uniform to a GLtype variable's value.
  /** It finds the appropriate glUniform* using template specialization.
    * If it is called with not an OpenGL type, it throws std::invalid argument.
    * @param value - The value to set the uniform.
    * @see glUniform* */
  void operator=(const GLtype& value) {
    set(value);
  }

public:
  /// Returns the C OpenGL handle for the uniform's location.
  GLuint expose() const {
    return location_;
  }
};

// -------======{[ Uniform ]}======-------

template<typename GLtype>
/// Uniform is used to set a uniform variable's value in a specified program.
/** It queries the location of the uniform in the constructor and also notifies on the
  * stderr, if getting the location of the variable, or setting it didn't work. */
class Uniform : public UniformObject<GLtype> {
  const std::string identifier_;
public:
  /// Queries a variable named 'identifier' in the 'program', and stores it's location.
  /** It writes to stderr if the query didn't work.
    * @param program - The program to seek the uniform in. Will call program.use().
    * @param identifier - The name of the uniform that is to be set.
    * @see glGetUniformLocation */
  Uniform(Program& program, const std::string& identifier)
    :identifier_(identifier) {
    CHECK_ACTIVE_PROGRAM(program);

    UniformObject<GLtype>::location_ = gl(GetUniformLocation(program.expose(), identifier_.c_str()));

    if(UniformObject<GLtype>::location_ == INVALID_LOCATION) {
      debug_output.callback("Error getting the location of uniform '" + identifier_ + "'");
    }
  }

  /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
  /** It throws std::invalid_argument if it is an unrecognized type.
    * @param value - Specifies the new value to be used for the uniform variable.
    * @see glUniform* */
  void set(const GLtype& value) {
    glfunc(UniformObject<GLtype>::set(value));

    OGLWRAP_PRINT_ERROR(
      GL_INVALID_OPERATION,
      "Uniform::set is called for uniform '" + identifier_ + "' but the uniform"
      " template parameter and the actual uniform type mismatches, "
      "or there is no current program object."
    )
  }

  /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
  /** It throws std::invalid_argument if it is an unrecognized type.
    * @param value - Specifies the new value to be used for the uniform variable.
    * @see glUniform* */
  void operator=(const GLtype& value) {
    set(value);
  }
};

/// A Uniform that sets a sampler.
typedef Uniform<GLint> UniformSampler;

// -------======{[ IndexedUniform ]}======-------

template<typename GLtype>
/// IndexedUniform is used to set an element of a uniform array in a specified program.
/** It queries the location of the uniform in the constructor and also notifies on the
    stderr, if getting the location of the variable, or setting it didn't work. */
class IndexedUniform : public UniformObject<GLtype> {
  std::string identifier_;
public:
  /// Queries a variable named 'identifier' in the 'program', and stores it's location.
  /** It writes to stderr if the query didn't work.
    * @param program - The program to seek the uniform in. Will call program.use().
    * @param identifier - The name of the uniform that is to be set.
    * @param idx - The index of the element in the uniform array.
    * @see glGetUniformLocation */
  IndexedUniform(Program& program, const std::string& identifier, size_t idx) {
    std::stringstream id;
    id << identifier << '[' << idx << ']';
    identifier_ = id.str();

    CHECK_ACTIVE_PROGRAM(program);

    UniformObject<GLtype>::location_ = gl(GetUniformLocation(program.expose(), id.str().c_str()));

    if(UniformObject<GLtype>::location_ == INVALID_LOCATION) {
      debug_output.callback("Error getting the location of uniform '" + id.str() + "'");
    }
  }

  /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
  /** It throws std::invalid_argument if it is an unrecognized type.
    * @param value - Specifies the new value to be used for the uniform variable.
    * @see glUniform* */
  void set(const GLtype& value) {
    glfunc(UniformObject<GLtype>::set(value));

    OGLWRAP_PRINT_ERROR(
      GL_INVALID_OPERATION,
      "Uniform::set is called for uniform '" + identifier_ + "' but the uniform"
      " template parameter and the actual uniform type mismatches, "
      "or there is no current program object."
    )
  }

  /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
  /** It throws std::invalid_argument if it is an unrecognized type.
    * @param value - Specifies the new value to be used for the uniform variable.
    * @see glUniform* */
  void operator=(const GLtype& value) {
    set(value);
  }
};

/// An IndexedUniform that sets a value of an element of a sampler array.
typedef IndexedUniform<GLint> IndexedUniformSampler;

// -------======{[ LazyUniform ]}======-------

template<typename GLtype>
/// LazyUniform is used to set uniform variables in shaders in a lazy way.
/** It takes a program reference and the uniform's name as a constructor,
  * but the program doesn't have to be valid at that time. The variable's
  * locations will only be queried at the first set call (or op=), so
  * it have to query the location all the time, like how the normal
  * Uniform class works. It also has the advantage, that you only have
  * to write program's and the uniform's name once, no matter how many
  * times you set it. */
class LazyUniform : public UniformObject<GLtype> {
  Program& program_; ///< The program in which the uniform should be set.
  const std::string identifier_; ///< The uniform's name.
  bool firstCall_;
public:
  /// Stores the uniform's information.
  /** It will only be used at the first set() or op=() call, so the program
    * doesn't have to be valid at the time this constructor is called.
    * @param program - The program in which the uniform is to be set.
    * @param identifier - The uniform's name. */
  LazyUniform(Program& program, const std::string& identifier)
    : UniformObject<GLtype>(INVALID_LOCATION)
    , program_(program)
    , identifier_(identifier)
    , firstCall_(true) {
  }

  /// Sets the uniforms value.
  /** At the first call, queries the uniform's location. It writes to stderr if it was unable to get it.
    * At every call it sets the uniform to the specified value.
    * @param value - Specifies the new value to be used for the uniform variable. */
  void set(const GLtype& value) {
    CHECK_ACTIVE_PROGRAM(program_);

    // Get the uniform's location only at the first set call.
    if(firstCall_) {
      UniformObject<GLtype>::location_ = gl(GetUniformLocation(program_.expose(), identifier_.c_str()));

      // Check if it worked.
      if(UniformObject<GLtype>::location_ == INVALID_LOCATION) {
        debug_output.callback("Error getting the location of uniform '" + identifier_ + "'");
      }

      firstCall_ = false;
    }

    glfunc(UniformObject<GLtype>::set(value));

    OGLWRAP_PRINT_ERROR(
      GL_INVALID_OPERATION,
      "Uniform::set is called for uniform '" + identifier_ + "' but the "
      "uniform template parameter and the actual uniform type mismatches, "
      "or there is no current program object."
    )
  }

  /// Sets the uniforms value.
  /** At the first call, queries the uniform's location. It writes to stderr if it was unable to get it.
    * At every call it sets the uniform to the specified value. It also changes the active program
    * to the one specified in the constructor.
    * @param value - Specifies the new value to be used for the uniform variable. */
  void operator=(const GLtype& value) {
    set(value);
  }

  /// Is used to set an element of a uniform array.
  /** For example if you have a mat4 myMatrix[10]; and you created a lazyUniform
    * myMatUnif(prog, "myMatrix), you can call myMatUnif[5].set() to set myMatrix[5]. */
  IndexedUniform<GLtype> operator[](size_t idx) const {
    return IndexedUniform<GLtype>(program_, identifier_, idx);
  }
};

/// A LazyUniform that sets a sampler.
typedef LazyUniform<GLint> LazyUniformSampler;


// -------======{[ UniformObject::set specializations ]}======-------
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform1f)
template<>
inline void UniformObject<GLfloat>::set(const GLfloat& value) {
  glUniform1f(location_, value);
}
#endif // glUniform1f

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform1d)
template<>
inline void UniformObject<GLdouble>::set(const GLdouble& value) {
  glUniform1d(location_, value);
}
#endif // glUniform1d

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform1i)
template<>
inline void UniformObject<GLint>::set(const GLint& value) {
  glUniform1i(location_, value);
}
#endif // glUniform1i

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform1ui)
template<>
inline void UniformObject<GLuint>::set(const GLuint& value) {
  glUniform1ui(location_, value);
}
#endif // glUniform1ui

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform2fv)
template<>
inline void UniformObject<glm::vec2>::set(const glm::vec2& vec) {
  glUniform2fv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform2fv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform2dv)
template<>
inline void UniformObject<glm::dvec2>::set(const glm::dvec2& vec) {
  glUniform2dv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform2dv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform2iv)
template<>
inline void UniformObject<glm::ivec2>::set(const glm::ivec2& vec) {
  glUniform2iv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform2iv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform2uiv)
template<>
inline void UniformObject<glm::uvec2>::set(const glm::uvec2& vec) {
  glUniform2uiv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform2uiv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform3fv)
template<>
inline void UniformObject<glm::vec3>::set(const glm::vec3& vec) {
  glUniform3fv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform3fv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform3dv)
template<>
inline void UniformObject<glm::dvec3>::set(const glm::dvec3& vec) {
  glUniform3dv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform3dv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform3iv)
template<>
inline void UniformObject<glm::ivec3>::set(const glm::ivec3& vec) {
  glUniform3iv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform3iv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform3uiv)
template<>
inline void UniformObject<glm::uvec3>::set(const glm::uvec3& vec) {
  glUniform3uiv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform3uiv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform4fv)
template<>
inline void UniformObject<glm::vec4>::set(const glm::vec4& vec) {
  glUniform4fv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform4fv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform4dv)
template<>
inline void UniformObject<glm::dvec4>::set(const glm::dvec4& vec) {
  glUniform4dv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform4dv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform4iv)
template<>
inline void UniformObject<glm::ivec4>::set(const glm::ivec4& vec) {
  glUniform4iv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform4iv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniform4uiv)
template<>
inline void UniformObject<glm::uvec4>::set(const glm::uvec4& vec) {
  glUniform4uiv(location_, 1, glm::value_ptr(vec));
}
#endif // glUniform4uiv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniformMatrix2fv)
template<>
inline void UniformObject<glm::mat2>::set(const glm::mat2& mat) {
  glUniformMatrix2fv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif // glUniformMatrix2fv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniformMatrix2dv)
template<>
inline void UniformObject<glm::dmat2>::set(const glm::dmat2& mat) {
  glUniformMatrix2dv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif // glUniformMatrix2dv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniformMatrix3fv)
template<>
inline void UniformObject<glm::mat3>::set(const glm::mat3& mat) {
  glUniformMatrix3fv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif // glUniformMatrix3fv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniformMatrix3dv)
template<>
inline void UniformObject<glm::dmat3>::set(const glm::dmat3& mat) {
  glUniformMatrix3dv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif // glUniformMatrix3dv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniformMatrix4fv)
template<>
inline void UniformObject<glm::mat4>::set(const glm::mat4& mat) {
  glUniformMatrix4fv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif // glUniformMatrix4fv

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUniformMatrix4dv)
template<>
inline void UniformObject<glm::dmat4>::set(const glm::dmat4& mat) {
  glUniformMatrix4dv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif // glUniformMatrix4dv

#endif // glGetUniformLocation
} // namespace oglwrap

#endif // OGLWRAP_UNIFORM_HPP_
