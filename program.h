// Copyright (c) 2014, Tamas Csala

/** @file program.h
    @brief Implements a wrapper for GLSL programs.
*/

#ifndef OGLWRAP_PROGRAM_H_
#define OGLWRAP_PROGRAM_H_

#include <vector>
#include "./shader.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCreateProgram)
/**
 * @brief The program object can combine multiple shader stages (built from
 *        shader objects) into a single, linked whole.
 * @see glCreateProgram, glDeleteProgram
 */
class Program {
 public:
  enum State { kNotLinked, kLinkFailure, kLinkSuccesful, kValidationFailure };

  /// Creates an empty program object.
  Program() {}

  template <typename... Shaders>
  explicit Program(const Shader& shader, Shaders&&... shaders) {
    attachShaders(shader, shaders...);
    link();
  }

  /**
   * @brief Detaches all the shader objects currently attached to this program,
   * and deletes the program.
   *
   * @see glDetachShader, glDeleteShader
   */
  ~Program() {
    for (size_t i = 0; i < shaders_.size(); i++) {
      gl(DetachShader(program_, shaders_[i]));
    }
  }

  /// Attaches a shader to this program object.
  /** @param shader Specifies the shader object that is to be attached.
    * @see glAttachShader */
  template<typename... Rest>
  Program& attachShaders(const Shader& shader, Rest&&... rest) {
    attachShader(shader);
    attachShaders(rest...);

    return *this;
  }

  /// Doesn't do anything.
  Program& attachShaders() {
    return *this;
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glAttachShader)
  /// Attaches a shader to this program object.
  /** @param shader Specifies the shader object that is to be attached.
    * @see glAttachShader */
  Program& attachShader(const Shader& shader) {
    if (state_ == kNotLinked) {
      shader.compile();
      shaders_.push_back(shader.expose());

      #if OGLWRAP_DEBUG
        filenames_.push_back(shader.source_file());
      #endif

      gl(AttachShader(program_, shader.expose()));
    } else {
      throw new std::logic_error{
        "Program::attachShader called on an already linked program."};
    }

    return *this;
  }
#endif  // glAttachShader

  /// Attaching rvalue reference shaders to programs only work correctly on NVIDIA.
  Program& attachShader(Shader&& shader) = delete;

#if OGLWRAP_DEFINE_EVERYTHING || defined(glAttachShader)
  /// Attaches a shader object to the program.
  /** @param shader Specifies the shader object that is to be attached.
    * @see glAttachShader */
  Program& operator<<(Shader& shader) {
    attachShader(shader);
    return *this;
  }
#endif  // glAttachShader

#if OGLWRAP_DEFINE_EVERYTHING || defined(glAttachShader)
  /// Attaches a shader object to the program, and compiles it, if needed.
  /** @param shader Specifies the shader object that is to be attached.
    * @see glAttachShader */
  Program& operator<<(const Shader& shader) {
    attachShader(shader);
    return *this;
  }
#endif  // glAttachShader

  /// Attaching rvalue reference shaders to a programs only work correctly on NVIDIA.
  Program& operator<<(Shader&& shader) = delete;

#if OGLWRAP_DEBUG
  /// Returns a formatted list of the names of the shaders that this program uses.
  std::string getShaderNames() const {
    std::string str;
    for (size_t i = 0; i < filenames_.size(); i++) {
        str += " - " + filenames_[i] + "\n";
    }
    return str;
  }
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glLinkProgram)
  /// Links the program and checks for error if OGLWRAP_DEBUG is defined.
  /** If the linking fails, it throws an
    * std::runtime_error containing the linking info.
    * @see glLinkProgram, glGetProgramiv, glGetProgramInfoLog */
  virtual const Program& link() {
    if (state_ == kNotLinked) {
      gl(LinkProgram(program_));

      GLint status;
      gl(GetProgramiv(program_, GL_LINK_STATUS, &status));
      if (status == GL_FALSE) {
        state_ = kLinkFailure;

        #if OGLWRAP_DEBUG
        GLint info_log_length;
        gl(GetProgramiv(program_, GL_INFO_LOG_LENGTH, &info_log_length));

        std::unique_ptr<GLchar> str_info_log{ new GLchar[info_log_length + 1] };
        gl(GetProgramInfoLog(program_, info_log_length, NULL, str_info_log.get()));
        std::stringstream str;
        str << "OpenGL failed to link the following shaders together: " << std::endl;
        str << getShaderNames() << std::endl;
        str << "The error message: \n" << str_info_log.get();

        OGLWRAP_PRINT_ERROR(
          "Program link failure",
          str.str()
        )
        #endif  // OGLWRAP_DEBUG
      } else {
        state_ = kLinkSuccesful;
      }
    }

    return *this;
  }

#endif  // glLinkProgram

#if OGLWRAP_DEFINE_EVERYTHING || defined(glValidateProgram)
  /// Validates the program if OGLWRAP_DEBUG is defined.
  /** @see glLinkProgram, glGetProgramiv, glGetProgramInfoLog */
  void validate() {
    if (state_ == kNotLinked) {
      link();
    }

    GLint status;
    gl(ValidateProgram(program_));
    gl(GetProgramiv(program_, GL_VALIDATE_STATUS, &status));
    if (status == GL_FALSE) {
      state_ = kValidationFailure;

      #if OGLWRAP_DEBUG
      GLint info_log_length;
      gl(GetProgramiv(program_, GL_INFO_LOG_LENGTH, &info_log_length));

      std::unique_ptr<GLchar> str_info_log{ new GLchar[info_log_length + 1] };
      gl(GetProgramInfoLog(program_, info_log_length, NULL, str_info_log.get()));
      std::stringstream str;
      str << "The validation of the program containing the "
      "following shaders failed:\n" << getShaderNames() << std::endl;

      str << "This program might generate GL_INVALID_OPERATION "
      "when used for rendering \nThe validation info: " << str_info_log.get();

      OGLWRAP_PRINT_ERROR(
        "Program validation failure",
        str.str()
      )
      #endif
    }
  }
#endif  // glValidateProgram

  State state() const {
    return state_;
  }

  /// Returns the C OpenGL handle for the program.
  const glObject& expose() const {
    return program_;
  }

 private:
  globjects::Program program_;  // The C OpenGL handle for the program.
  std::vector<GLuint> shaders_;  // IDs of the shaders attached to the program

  #if OGLWRAP_DEBUG
    /// The names of the shaders are stored to help debugging.
    std::vector<std::string> filenames_;
  #endif

  mutable State state_ = kNotLinked;
};

#endif  // glCreateProgram

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_PROGRAM_H_
