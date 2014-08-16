// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_UNIFORM_H_
#define OGLWRAP_UNIFORM_H_

#include <stdexcept>

#include "./config.h"
#include "./program.h"
#include "context/binding.h"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

// -------======{[ UniformObject ]}======-------

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetUniformLocation)
template<typename GLtype>
/// An object implementing the base features Uniforms.
class UniformObject {
 protected:
  GLuint location_;  // The C handle for the uniform's location
  const Program& program_;  // The program the uniform is in.

  static const GLuint kInvalidLocation = ~GLuint(0);

  UniformObject(const Program& program, GLuint location = kInvalidLocation)
    : location_(location), program_(program) { }

 public:
  virtual ~UniformObject() {}

  /// Sets the uniform to a GLtype variable's value.
  virtual void set(const GLtype& value) { // See the specializations at the end of this file.
    static_assert((sizeof(GLtype), false),
        "Trying to set a uniform to a value that is not an OpenGL type.");
  }

  /// Sets the uniform to a GLtype variable's value.
  void operator=(const GLtype& value) {
    set(value);
  }

  /// Gets the current value of the uniform.
  virtual GLtype get() {
    static_assert((sizeof(GLtype), false),
        "Trying to get a uniform to a value that is not an OpenGL type.");
  }

  /// Gets the current value of the uniform.
  operator GLtype() {
    return get();
  }

  /// Returns the C OpenGL handle for the uniform's location.
  GLuint expose() const {
    return location_;
  }
};

// -------======{[ Uniform ]}======-------

template<typename GLtype>
/// Uniform is used to set a uniform variable's value in a specified program.
class Uniform : public UniformObject<GLtype> {
  const std::string identifier_;

 public:
  /// Queries a variable named 'identifier' in the 'program', and stores it's location.
  Uniform(const Program& program, const std::string& identifier)
      : UniformObject<GLtype>(program)
      , identifier_(identifier) {
    OGLWRAP_CHECK_BINDING_EXPLICIT(program);

    this->location_ =
      gl(GetUniformLocation(program.expose(), identifier_.c_str()));

    #if OGLWRAP_DEBUG
      if (this->location_ == this->kInvalidLocation) {
        OGLWRAP_PRINT_ERROR(
          "Error getting uniform location",
          "Error getting the location of uniform '" + identifier_ +
          "' in the program using the following shaders:\n" +
          program.getShaderNames());
      }
    #endif
  }

  /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
  virtual void set(const GLtype& value) override {
    glfunc(UniformObject<GLtype>::set(value));

    #if OGLWRAP_DEBUG
      OGLWRAP_PRINT_IF_ERROR(
        ErrorType::kInvalidOperation,
        "Error setting uniform value",
        "Uniform::set is called for uniform '" + identifier_ +
        "' but the uniform template parameter and the actual uniform "
        "type mismatches. \n"
        "The error happened in the program using the following shaders:\n" +
        this->program_.getShaderNames());
    #endif
  }

  /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
  void operator=(const GLtype& value) {
    set(value);
  }

  /// Gets the current value of the uniform.
  virtual GLtype get() override {
    GLtype val = glfunc(UniformObject<GLtype>::get());

    #if OGLWRAP_DEBUG
      OGLWRAP_PRINT_IF_ERROR(
        ErrorType::kInvalidOperation,
        "Error getting uniform value",
        "Uniform::get is called for uniform '" + identifier_ +
        "' but the uniform template parameter and the actual uniform "
        "type mismatches. \n"
        "The error happened in the program using the following shaders:\n" +
        this->program_.getShaderNames());
    #endif

    return val;
  }

  /// Gets the current value of the uniform.
  operator GLtype() {
    return get();
  }
};

/// A Uniform that sets a sampler.
typedef Uniform<GLint> UniformSampler;

// -------======{[ IndexedUniform ]}======-------

template<typename GLtype>
/// IndexedUniform is used to set an element of a uniform array in a specified program.
class IndexedUniform : public UniformObject<GLtype> {
  std::string identifier_;

 public:
  /// Queries a variable named 'identifier' in the 'program', and stores it's location.
  IndexedUniform(const Program& program, const std::string& identifier, size_t idx)
      : UniformObject<GLtype>(program) {
    std::stringstream id;
    id << identifier << '[' << idx << ']';
    identifier_ = id.str();

    OGLWRAP_CHECK_BINDING_EXPLICIT(program);

    this->location_ =
      gl(GetUniformLocation(program.expose(), id.str().c_str()));

    #if OGLWRAP_DEBUG
      if (this->location_ == this->kInvalidLocation) {
        OGLWRAP_PRINT_ERROR(
          "Error getting uniform location",
          "Error getting the location of uniform '" + identifier_ +
          "' in the program using the following shaders:\n" +
          program.getShaderNames());
      }
    #endif
  }

  /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
  virtual void set(const GLtype& value) override {
    glfunc(UniformObject<GLtype>::set(value));

    #if OGLWRAP_DEBUG
      OGLWRAP_PRINT_IF_ERROR(
        ErrorType::kInvalidOperation,
        "Error setting uniform value",
        "Uniform::get is called for uniform '" + identifier_ +
        "' but the uniform template parameter and the actual uniform "
        "type mismatches. \n"
        "The error happened in the program using the following shaders:\n" +
        this->program_.getShaderNames());
    #endif
  }

  /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
  void operator=(const GLtype& value) {
    set(value);
  }

  /// Gets the current value of the uniform.
  virtual GLtype get() override {
    GLtype val = glfunc(UniformObject<GLtype>::get());

    #if OGLWRAP_DEBUG
      OGLWRAP_PRINT_IF_ERROR(
        ErrorType::kInvalidOperation,
        "Error getting uniform value",
        "Uniform::get is called for uniform '" + identifier_ +
        "' but the uniform template parameter and the actual uniform "
        "type mismatches. \n"
        "The error happened in the program using the following shaders:\n" +
        this->program_.getShaderNames());
    #endif
    return val;
  }

  /// Gets the current value of the uniform.
  operator GLtype() {
    return get();
  }
};

/// An IndexedUniform that sets a value of an element of a sampler array.
typedef IndexedUniform<GLint> IndexedUniformSampler;

// -------======{[ LazyUniform ]}======-------

template<typename GLtype>
/// LazyUniform is used to set uniform variables in shaders in a lazy way.
class LazyUniform : public UniformObject<GLtype> {
  const std::string identifier_;  // The uniform's name.
  bool firstCall_;

 public:
  /// Stores the uniform's information.
  LazyUniform(const Program& program, const std::string& identifier)
    : UniformObject<GLtype>(program)
    , identifier_(identifier)
    , firstCall_(true) {
  }

  /// Sets the uniforms value.
  virtual void set(const GLtype& value) override {
    OGLWRAP_CHECK_BINDING_EXPLICIT(this->program_);

    // Get the uniform's location only at the first set call.
    if (firstCall_) {
      this->location_ =
        gl(GetUniformLocation(this->program_.expose(), identifier_.c_str()));

      #if OGLWRAP_DEBUG
        // Check if it worked.
        if (this->location_ == this->kInvalidLocation) {
          OGLWRAP_PRINT_ERROR(
            "Error getting uniform location",
            "Error getting the location of uniform '" + identifier_ +
            "' in the program using the following shaders:\n" +
            this->program_.getShaderNames());
        }
      #endif

      firstCall_ = false;
    }

    glfunc(UniformObject<GLtype>::set(value));

    #if OGLWRAP_DEBUG
      OGLWRAP_PRINT_IF_ERROR(
        ErrorType::kInvalidOperation,
        "Error setting uniform location",
        "Uniform::set is called for uniform '" + identifier_ +
        "' but the uniform template parameter and the actual uniform "
        "type mismatches. \n"
        "The error happened in the program using the following shaders:\n" +
        this->program_.getShaderNames());
    #endif
  }

  /// Sets the uniforms value.
  void operator=(const GLtype& value) {
    set(value);
  }

  /// Gets the current value of the uniform.
  GLtype get() {
    OGLWRAP_CHECK_BINDING_EXPLICIT(this->program_);

    // Get the uniform's location only at the first set call.
    if (firstCall_) {
      this->location_ = gl(GetUniformLocation(
          this->program_.expose(), identifier_.c_str()));

      #if OGLWRAP_DEBUG
        // Check if it worked.
        if (this->location_ == this->kInvalidLocation) {
          OGLWRAP_PRINT_ERROR(
            "Error getting uniform location",
            "Error getting the location of uniform '" + identifier_ +
            "' in the program using the following shaders:\n" +
            this->program_.getShaderNames());
        }
      #endif

      firstCall_ = false;
    }

    GLtype val = glfunc(UniformObject<GLtype>::get());

    #if OGLWRAP_DEBUG
      OGLWRAP_PRINT_IF_ERROR(
        ErrorType::kInvalidOperation,
        "Error getting uniform location",
        "Uniform::get is called for uniform '" + identifier_ +
        "' but the uniform template parameter and the actual uniform "
        "type mismatches. \n"
        "The error happened in the program using the following shaders:\n" +
        this->program_.getShaderNames());
    #endif
    return val;
  }

  /// Gets the current value of the uniform.
  operator GLtype() {
    return get();
  }

  /// Is used to set an element of a uniform array.
  IndexedUniform<GLtype> operator[](size_t idx) const {
    return IndexedUniform<GLtype>(this->program_, identifier_, idx);
  }
};

/// A LazyUniform that sets a sampler.
typedef LazyUniform<GLint> LazyUniformSampler;


// -------======{[ UniformObject::set specializations ]}======-------
#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform1f)
template<>
inline void UniformObject<GLfloat>::set(const GLfloat& value) {
  glUniform1f(location_, value);
}
#endif  // glUniform1f

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform1d)
template<>
inline void UniformObject<GLdouble>::set(const GLdouble& value) {
  glUniform1d(location_, value);
}
#endif  // glUniform1d

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform1i)
template<>
inline void UniformObject<GLint>::set(const GLint& value) {
  glUniform1i(location_, value);
}
#endif  // glUniform1i

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform1ui)
template<>
inline void UniformObject<GLuint>::set(const GLuint& value) {
  glUniform1ui(location_, value);
}
#endif  // glUniform1ui

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform2fv)
template<>
inline void UniformObject<glm::vec2>::set(const glm::vec2& vec) {
  glUniform2fv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform2fv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform2dv)
template<>
inline void UniformObject<glm::dvec2>::set(const glm::dvec2& vec) {
  glUniform2dv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform2dv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform2iv)
template<>
inline void UniformObject<glm::ivec2>::set(const glm::ivec2& vec) {
  glUniform2iv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform2iv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform2uiv)
template<>
inline void UniformObject<glm::uvec2>::set(const glm::uvec2& vec) {
  glUniform2uiv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform2uiv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform3fv)
template<>
inline void UniformObject<glm::vec3>::set(const glm::vec3& vec) {
  glUniform3fv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform3fv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform3dv)
template<>
inline void UniformObject<glm::dvec3>::set(const glm::dvec3& vec) {
  glUniform3dv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform3dv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform3iv)
template<>
inline void UniformObject<glm::ivec3>::set(const glm::ivec3& vec) {
  glUniform3iv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform3iv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform3uiv)
template<>
inline void UniformObject<glm::uvec3>::set(const glm::uvec3& vec) {
  glUniform3uiv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform3uiv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform4fv)
template<>
inline void UniformObject<glm::vec4>::set(const glm::vec4& vec) {
  glUniform4fv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform4fv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform4dv)
template<>
inline void UniformObject<glm::dvec4>::set(const glm::dvec4& vec) {
  glUniform4dv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform4dv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform4iv)
template<>
inline void UniformObject<glm::ivec4>::set(const glm::ivec4& vec) {
  glUniform4iv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform4iv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniform4uiv)
template<>
inline void UniformObject<glm::uvec4>::set(const glm::uvec4& vec) {
  glUniform4uiv(location_, 1, glm::value_ptr(vec));
}
#endif  // glUniform4uiv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniformMatrix2fv)
template<>
inline void UniformObject<glm::mat2>::set(const glm::mat2& mat) {
  glUniformMatrix2fv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif  // glUniformMatrix2fv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniformMatrix2dv)
template<>
inline void UniformObject<glm::dmat2>::set(const glm::dmat2& mat) {
  glUniformMatrix2dv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif  // glUniformMatrix2dv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniformMatrix3fv)
template<>
inline void UniformObject<glm::mat3>::set(const glm::mat3& mat) {
  glUniformMatrix3fv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif  // glUniformMatrix3fv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniformMatrix3dv)
template<>
inline void UniformObject<glm::dmat3>::set(const glm::dmat3& mat) {
  glUniformMatrix3dv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif  // glUniformMatrix3dv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniformMatrix4fv)
template<>
inline void UniformObject<glm::mat4>::set(const glm::mat4& mat) {
  glUniformMatrix4fv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif  // glUniformMatrix4fv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUniformMatrix4dv)
template<>
inline void UniformObject<glm::dmat4>::set(const glm::dmat4& mat) {
  glUniformMatrix4dv(location_, 1, GL_FALSE, glm::value_ptr(mat));
}
#endif  // glUniformMatrix4dv


// -------======{[ UniformObject::get specializations ]}======-------

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetUniformfv)
template<>
inline GLfloat UniformObject<GLfloat>::get() {
  GLfloat value;
  glGetUniformfv(program_.expose(), location_, &value);
  return value;
}

template<>
inline glm::vec2 UniformObject<glm::vec2>::get() {
  glm::vec2 value;
  glGetUniformfv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::vec3 UniformObject<glm::vec3>::get() {
  glm::vec3 value;
  glGetUniformfv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::vec4 UniformObject<glm::vec4>::get() {
  glm::vec4 value;
  glGetUniformfv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::mat2 UniformObject<glm::mat2>::get() {
  glm::mat2 value;
  glGetUniformfv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::mat3 UniformObject<glm::mat3>::get() {
  glm::mat3 value;
  glGetUniformfv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::mat4 UniformObject<glm::mat4>::get() {
  glm::mat4 value;
  glGetUniformfv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}
#endif  // glGetUniformfv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetUniformdv)
template<>
inline GLdouble UniformObject<GLdouble>::get() {
  GLdouble value;
  glGetUniformdv(program_.expose(), location_, &value);
  return value;
}

template<>
inline glm::dvec2 UniformObject<glm::dvec2>::get() {
  glm::dvec2 value;
  glGetUniformdv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::dvec3 UniformObject<glm::dvec3>::get() {
  glm::dvec3 value;
  glGetUniformdv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::dvec4 UniformObject<glm::dvec4>::get() {
  glm::dvec4 value;
  glGetUniformdv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::dmat2 UniformObject<glm::dmat2>::get() {
  glm::dmat2 value;
  glGetUniformdv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::dmat3 UniformObject<glm::dmat3>::get() {
  glm::dmat3 value;
  glGetUniformdv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::dmat4 UniformObject<glm::dmat4>::get() {
  glm::dmat4 value;
  glGetUniformdv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}
#endif  // glGetUniformdv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetUniformiv)
template<>
inline GLint UniformObject<GLint>::get() {
  GLint value;
  glGetUniformiv(program_.expose(), location_, &value);
  return value;
}

template<>
inline glm::ivec2 UniformObject<glm::ivec2>::get() {
  glm::ivec2 value;
  glGetUniformiv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::ivec3 UniformObject<glm::ivec3>::get() {
  glm::ivec3 value;
  glGetUniformiv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::ivec4 UniformObject<glm::ivec4>::get() {
  glm::ivec4 value;
  glGetUniformiv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}
#endif  // glGetUniformiv

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetUniformuiv)
template<>
inline GLuint UniformObject<GLuint>::get() {
  GLuint value;
  glGetUniformuiv(program_.expose(), location_, &value);
  return value;
}

template<>
inline glm::uvec2 UniformObject<glm::uvec2>::get() {
  glm::uvec2 value;
  glGetUniformuiv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::uvec3 UniformObject<glm::uvec3>::get() {
  glm::uvec3 value;
  glGetUniformuiv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}

template<>
inline glm::uvec4 UniformObject<glm::uvec4>::get() {
  glm::uvec4 value;
  glGetUniformuiv(program_.expose(), location_, glm::value_ptr(value));
  return value;
}
#endif  // glGetUniformuiv

// Explicit instantiate just the common ones.
#if OGLWRAP_INSTANTIATE
  template class Uniform<GLint>;
  template class Uniform<glm::vec3>;
  template class Uniform<glm::vec4>;
  template class Uniform<glm::mat3>;
  template class Uniform<glm::mat4>;
  template class LazyUniform<GLint>;
  template class LazyUniform<glm::vec3>;
  template class LazyUniform<glm::vec4>;
  template class LazyUniform<glm::mat3>;
  template class LazyUniform<glm::mat4>;
#else
  extern template class Uniform<GLint>;
  extern template class Uniform<glm::vec3>;
  extern template class Uniform<glm::vec4>;
  extern template class Uniform<glm::mat3>;
  extern template class Uniform<glm::mat4>;
  extern template class LazyUniform<GLint>;
  extern template class LazyUniform<glm::vec3>;
  extern template class LazyUniform<glm::vec4>;
  extern template class LazyUniform<glm::mat3>;
  extern template class LazyUniform<glm::mat4>;
#endif

#endif  // glGetUniformLocation

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_UNIFORM_H_
