// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_SHADER_H_
#define OGLWRAP_SHADER_H_

#include "./config.h"
#include "./globjects.h"
#include "./shader_source.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCreateShader)
/// A GLSL shader object used to control the drawing process.
class Shader {
  globjects::Shader shader_;  // The handle for the buffer.
  bool compiled_;  // Stores if the shader is compiled.

  #if OGLWRAP_DEBUG
    /// Stores the source file's name if the shader was initialized from file.
    std::string filename_;
  #endif

 public:
  /// Creates the an empty shader object.
  #if OGLWRAP_DEBUG
    explicit Shader(ShaderType shader_t)
        : shader_(shader_t), compiled_(false), filename_("Unnamed shader") { }
  #else
    explicit Shader(ShaderType shader_t)
        : shader_(shader_t), compiled_(false) { }
  #endif

  /// Creates a shader and sets the file as the shader source.
  Shader(ShaderType shader_t, const std::string& file)
      : shader_(shader_t), compiled_(false) {
    set_source_file(file);
  }

  /// Creates a shader and sets the file as the shader source.
  Shader(ShaderType shader_t, const ShaderSource& src)
      : shader_(shader_t), compiled_(false) {
    set_source(src);
  }

  /// Uploads a string as the shader's source.
  void set_source(const std::string& source) {
    const char *str = source.c_str();
    gl(ShaderSource(shader_, 1, &str, nullptr));
  }

  /// Uploads a ShaderSource as the shader's source.
  void set_source(const ShaderSource& source) {
    const char *str = source.source().c_str();
    #if OGLWRAP_DEBUG
      filename_ = source.source_file();
    #endif
    gl(ShaderSource(shader_, 1, &str, nullptr));
  }

#if OGLWRAP_DEBUG
  /// Returns the file's name that was loaded in.
  const std::string& source_file() const {
    return filename_;
  }
#endif

  /// Loads a file and uploads it as shader source
  void set_source_file(const std::string& file)  {
    set_source(ShaderSource(file));
  }

#if OGLWRAP_DEFINE_EVERYTHING || ( \
  defined(glCompileShader) && \
  defined(glGetShaderiv) && \
  defined(glGetShaderInfoLog) \
)
  /// Compiles the shader code.
  void compile()  {
    if (compiled_) {
      return;
    }
    gl(CompileShader(shader_));
    compiled_ = true;

    #if OGLWRAP_DEBUG
    // Get compilation status
    GLint status;
    gl(GetShaderiv(shader_, GL_COMPILE_STATUS, &status));
    if (status == GL_FALSE) {
      GLint info_log_length;
      gl(GetShaderiv(shader_, GL_INFO_LOG_LENGTH, &info_log_length));

      std::unique_ptr<GLchar> str_info_log{ new GLchar[info_log_length + 1] };
      gl(GetShaderInfoLog(shader_, info_log_length, nullptr, str_info_log.get()));

      std::stringstream str;
        str << "Compile failure in shader '";
        str << filename_ << "' :" << std::endl << str_info_log.get();

      OGLWRAP_PRINT_FATAL_ERROR(
        "Shader compile failure",
        str.str()
      )
    }
    #endif
  }
#endif  // glCompileShader && glGetShaderInfoLog && glGetShaderiv

  /// Returns if the shader is compiled
  bool compiled() { return compiled_; }

  /// Returns the C OpenGL handle for the shader.
  const glObject& expose() const  {
    return shader_;
  }
};


#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)

class ComputeShader : public Shader {
 public:
  ComputeShader() : Shader(ShaderType::kComputeShader) { }
  explicit ComputeShader(const std::string& file)
    : Shader(ShaderType::kComputeShader, file) {}
  explicit ComputeShader(const ShaderSource& src)
    : Shader(ShaderType::kComputeShader, src) {}
};
#endif  // GL_COMPUTE_SHADER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)

class VertexShader : public Shader {
 public:
  VertexShader() : Shader(ShaderType::kVertexShader) { }
  explicit VertexShader(const std::string& file)
    : Shader(ShaderType::kVertexShader, file) {}
  explicit VertexShader(const ShaderSource& src)
    : Shader(ShaderType::kVertexShader, src) {}
};
#endif  // GL_VERTEX_SHADER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)

class GeometryShader : public Shader {
 public:
  GeometryShader() : Shader(ShaderType::kGeometryShader) { }
  explicit GeometryShader(const std::string& file)
    : Shader(ShaderType::kGeometryShader, file) {}
  explicit GeometryShader(const ShaderSource& src)
    : Shader(ShaderType::kGeometryShader, src) {}
};
#endif  // GL_GEOMETRY_SHADER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)

class FragmentShader : public Shader {
 public:
  FragmentShader() : Shader(ShaderType::kFragmentShader) { }
  explicit FragmentShader(const std::string& file)
    : Shader(ShaderType::kFragmentShader, file) {}
  explicit FragmentShader(const ShaderSource& src)
    : Shader(ShaderType::kFragmentShader, src) {}
};
#endif  // GL_FRAGMENT_SHADER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)

class TessControlShader : public Shader {
 public:
  TessControlShader() : Shader(ShaderType::kTessControlShader) { }
  explicit TessControlShader(const std::string& file)
    : Shader(ShaderType::kTessControlShader, file) {}
  explicit TessControlShader(const ShaderSource& src)
    : Shader(ShaderType::kTessControlShader, src) {}
};
#endif  // GL_TESS_CONTROL_SHADER

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)

class TessEvaluationShader : public Shader {
 public:
  TessEvaluationShader() : Shader(ShaderType::kTessEvaluationShader) { }
  explicit TessEvaluationShader(const std::string& file)
    : Shader(ShaderType::kTessEvaluationShader, file) {}
  explicit TessEvaluationShader(const ShaderSource& src)
    : Shader(ShaderType::kTessEvaluationShader, src) {}
};
#endif  // GL_TESS_EVALUATION_SHADER

#endif  // glCreateShader

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_SHADER_H_
