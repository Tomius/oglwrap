// Copyright (c) 2014, Tamas Csala

/** @file shader.h
    @brief Implements GLSL shaders related classes.
*/

#ifndef OGLWRAP_SHADER_H_
#define OGLWRAP_SHADER_H_

#include "./config.h"
#include "./globjects.h"
#include "./shader_source.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCreateShader)
/// A GLSL shader object used to control the drawing process.
/** @see glCreateShader, glDeleteShader */
class Shader {
 public:
  enum State { kNotCompiled, kCompileFailure, kCompileSuccessful };

 private:
  globjects::Shader shader_;  // The handle for the buffer.

  /// Stores the source file's name if the shader was initialized from file.
  std::string filename_;

 protected:
  mutable State state_ = kNotCompiled;

 public:
  /// Creates the an empty shader object.
  explicit Shader(ShaderType shader_t)
      : shader_(shader_t), filename_("Unnamed shader") { }

  /// Creates a shader and sets the file as the shader source.
  /** @param file - The file to load and set as shader source.
    * @see glShaderSource */
  Shader(ShaderType shader_t, const std::string& file)
      : shader_(shader_t) {
    set_source(ShaderSource{file});
  }

  /// Creates a shader and sets the file as the shader source.
  /** @param src - The source of the shader code.
    * @see glShaderSource */
  Shader(ShaderType shader_t, const ShaderSource& src)
      : shader_(shader_t) {
    set_source(src);
  }

  /// Uploads a string as the shader's source.
  /** @param source - string containing the shader code.
    * @see glShaderSource */
  void set_source(const std::string& source) {
    const char *str = source.c_str();
    gl(ShaderSource(shader_, 1, &str, nullptr));
  }

  /// Uploads a ShaderSource as the shader's source.
  /** @param source - The source of the shader code.
    * @see glShaderSource */
  void set_source(const ShaderSource& source) {
    const char *str = source.source().c_str();
    filename_ = source.source_file();
    gl(ShaderSource(shader_, 1, &str, nullptr));
  }

  /// Returns the file's name that was loaded in.
  const std::string& source_file() const {
    return filename_;
  }

  void set_source_file(const std::string& filename)  {
    filename_ = filename;
  }

#if OGLWRAP_DEFINE_EVERYTHING || ( \
  defined(glCompileShader) && \
  defined(glGetShaderiv) && \
  defined(glGetShaderInfoLog) \
)
  /// Compiles the shader code.
  /** @see glCompileShader, glGetShaderiv, glGetShaderInfoLog */
  void compile() const {
    if (state_ != kNotCompiled) {
      return;
    }
    gl(CompileShader(shader_));

    // Get compilation status
    GLint status;
    gl(GetShaderiv(shader_, GL_COMPILE_STATUS, &status));
    if (status == GL_TRUE) {
      state_ = kCompileSuccessful;
    } else {
      state_ = kCompileFailure;
    }

    #if OGLWRAP_DEBUG
    if (status == GL_FALSE) {
      GLint info_log_length;
      gl(GetShaderiv(shader_, GL_INFO_LOG_LENGTH, &info_log_length));

      std::unique_ptr<GLchar> str_info_log{ new GLchar[info_log_length + 1] };
      gl(GetShaderInfoLog(shader_, info_log_length, nullptr, str_info_log.get()));

      std::stringstream str;
        str << "Compile failure in shader '";
        str << filename_ << "' :" << std::endl << str_info_log.get();

      OGLWRAP_PRINT_ERROR(
        "Shader compile failure",
        str.str()
      )
    }
    #endif
  }
#endif  // glCompileShader && glGetShaderInfoLog && glGetShaderiv

  /// Returns if the shader is compiled
  State state() const { return state_; }

  /// Returns the C OpenGL handle for the shader.
  const glObject& expose() const  {
    return shader_;
  }
};


#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
/**
 * @brief A Shader that is used for computing arbitrary information.
 *
 * A Compute Shader is a Shader Stage that is used entirely for computing
 * arbitrary information.
 *
 * While it can do rendering, it is generally used for tasks not directly
 * related to drawing triangles and pixels.
 *
 * @version OpenGL 4.3
 * @see GL_COMPUTE_SHADER
 */
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
/**
 * @brief A Shader that handles the processing of individual vertices.
 *
 * The Vertex Shader is the programmable Shader stage in the rendering pipeline
 * that handles the processing of individual vertices. Vertex shaders are fed
 * Vertex Attribute data, as specified from a vertex array object by a rendering
 * command. A vertex shader receives a single vertex from the vertex stream and
 * generates a single vertex to the output vertex stream.
 *
 * @version OpenGL 2.1
 * @see GL_VERTEX_SHADER
 */
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
/**
 * @brief A Shader that governs the processing of Primitives.
 *
 * A Geometry Shader is a Shader program written in GLSL that governs the
 * processing of Primitives. Geometry shaders reside between the Vertex Shaders
 * (or the optional Tessellation stage) and the fixed-function Vertex
 * Post-Processing stage. A geometry shader is optional and does not have to
 * be used.
 *
 * @version OpenGL 3.2
 * @see GL_GEOMETRY_SHADER
 */
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
/**
 * @brief A Shader that processes a Fragment from the rasterization process
 * into a set of colors and a single depth value.
 *
 * A Fragment Shader is a user-supplied program that, when executed, will
 * process a Fragment from the rasterization process into a set of colors and a
 * single depth value. The fragment shader is the OpenGL pipeline stage after a
 * primitive is rasterized. For each sample of the pixels covered by a primitive,
 * a "fragment" is generated. Each fragment has a Window Space position, a few
 * other values, and it contains all of the interpolated per-vertex output
 * values from the last Vertex Processing stage. The output of a fragment shader
 * is a depth value, a possible stencil value (unmodified by the fragment shader),
 * and zero or more color values to be potentially written to the buffers in the
 * current framebuffers. Fragment shaders take a single fragment as input and
 * produce a single fragment as output.
 *
 * @version OpenGL 2.1
 * @see GL_FRAGMENT_SHADER
 */
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
/**
 * @brief A shader that controls how much tessellation a particular patch gets
 * and also defines the size of a patch.
 *
 * The Tessellation Control Shader (TCS) is a Shader program written in GLSL.
 * It sits between the Vertex Shader and the Tessellation Evaluation Shader.
 * The TCS controls how much tessellation a particular patch gets; it also
 * defines the size of a patch, thus allowing it to augment data. It can also
 * filter vertex data taken from the vertex shader. The main purpose of the TCS
 * is to feed the tessellation levels to the Tessellation primitive generator
 * stage, as well as to feed patch data (as its output values) to the
 * Tessellation Evaluation Shader stage.
 *
 * @version OpenGL 4.0
 * @see GL_TESS_CONTROL_SHADER
 */
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
/**
 * @brief A shader that generates vertices from the patch data.
 *
 * The Tessellation Evaluation Shader (TES) is a Shader program written in GLSL
 * that takes the results of a Tessellation operation and computes the
 * interpolated positions and other per-vertex data from them. These values are
 * passed on to the next stage in the pipeline. The (TES) takes the abstract
 * patch generated by the tessellation primitive generation stage, as well as
 * the actual vertex data for the entire patch, and generates a particular
 * vertex from it. Each TES invocation generates a single vertex. It can also
 * take per-patch data provided by the Tessellation Control Shader.
 *
 * @version It is core since OpenGL 4.0.
 * @see GL_TESS_EVALUATION_SHADER
 */
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
