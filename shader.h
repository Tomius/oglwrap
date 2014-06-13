// Copyright (c) 2014, Tamas Csala

/** @file shader.h
    @brief Implements GLSL shaders related classes.
*/

#ifndef OGLWRAP_SHADER_H_
#define OGLWRAP_SHADER_H_

#include <cstring>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "./config.h"
#include "./globjects.h"
#include "./general.h"
#include "debug/binding.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

// -------======{[ ShaderSource ]}======-------

/**
 * @brief A class that can load shader sources in from files, and do some
 *        preprocessing on them.
 */
class ShaderSource {
  std::string src_; /// The source

  #if OGLWRAP_DEBUG
    std::string filename_; /// The file's name stored to make debugging easier.
  #endif

public:
  /// Default constructor.
  #if OGLWRAP_DEBUG
    ShaderSource() : filename_("Unnamed shader") { }
  #else
    ShaderSource() = default;
  #endif

  /// Loads in the shader from a file.
  /** @param file - The path to the file. */
  ShaderSource(const std::string& file) {
    sourceFile(file);
  }

  /// Adds a string as the shader source.
  /** @param source_string - The source string. */
  void source(const std::string& source_string) {
    src_ = source_string;
  }

  /// Loads in the shader from a file.
  /** @param file - The path to the file. */
  void sourceFile(const std::string& file) {
    #if OGLWRAP_DEBUG
      filename_ = file;
    #endif
    std::ifstream shaderFile((OGLWRAP_DEFAULT_SHADER_PATH + file).c_str());
    if (!shaderFile.is_open()) {
      throw std::runtime_error("Shader file '" + file + "' not found.");
    }
    std::stringstream shaderString;
    shaderString << shaderFile.rdbuf();

    // Remove the EOF from the end of the string.
    src_ = shaderString.str();
    if (src_[src_.length() - 1] == EOF) {
      src_.pop_back();
    }
  }

  template<typename T>
  /// Inserts a value for a defined preprocessor in the shader.
  /** @param macro_name - The name of the macro.
    * @param value - The value to insert. */
  void insertMacroValue(const std::string& macro_name, const T& value) {
    size_t macro_pos = src_.find("#define " + macro_name);
    #if OGLWRAP_DEBUG
      if (macro_pos == std::string::npos) {
        throw std::invalid_argument(
          "ShaderSource::insert_macro_value is called for '" + filename_ +
          "', but the shader doesn't have any macro named " + macro_name
        );
      }
    #endif

    size_t macro_end = src_.find('\n', macro_pos);

    std::stringstream sstream;
    sstream << src_.substr(0, macro_pos + strlen("#define ") + macro_name.length());
    sstream << ' ' << value << src_.substr(macro_end);
    src_ = sstream.str();
  }

  #if OGLWRAP_DEBUG
    /// Returns the file's name that was loaded in.
    std::string const& getFileName() const {
      return filename_;
    }
  #endif

  /// Returns the source.
  std::string const& getSource() const {
    return src_;
  }
};

// -------======{[ Shader ]}======-------

#if OGLWRAP_DEFINE_EVERYTHING || \
  (defined(glCreateShader) && defined(glDeleteShader) && defined(glShaderSource))
/// A GLSL shader object used to control the drawing process.
/** @see glCreateShader, glDeleteShader */
class Shader {
  globjects::Shader shader_; ///< The handle for the buffer.
  bool compiled_; ///< Stores if the shader is compiled.

  #if OGLWRAP_DEBUG
    /// Stores the source file's name if the shader was initialized from file.
    std::string filename_;
  #endif

 public:
  /// Creates the an empty shader object.
  #if OGLWRAP_DEBUG
    Shader(ShaderType shader_t)
        : shader_(shader_t), compiled_(false), filename_("Unnamed shader") { }
  #else
    Shader(ShaderType shader_t)
        : shader_(shader_t), compiled_(false) { }
  #endif

  /// Creates a shader and sets the file as the shader source.
  /** @param file - The file to load and set as shader source.
    * @see glShaderSource */
  Shader(ShaderType shader_t, const std::string& file)
    : shader_(shader_t)
    , compiled_(false) {
    sourceFile(file);
  }

  /// Creates a shader and sets the file as the shader source.
  /** @param src - The source of the shader code.
    * @see glShaderSource */
  Shader(ShaderType shader_t, const ShaderSource& src)
    : shader_(shader_t)
    , compiled_(false) {
    source(src);
  }

  /// Uploads a string as the shader's source.
  /** @param source - string containing the shader code.
    * @see glShaderSource */
  void source(const std::string& source) {
    const char *str = source.c_str();
    gl(ShaderSource(shader_, 1, &str, nullptr));
  }

  /// Uploads a ShaderSource as the shader's source.
  /** @param source - The source of the shader code.
    * @see glShaderSource */
  void source(const ShaderSource& source) {
    const char *str = source.getSource().c_str();
    #if OGLWRAP_DEBUG
      filename_ = source.getFileName();
    #endif
    gl(ShaderSource(shader_, 1, &str, nullptr));
  }

  /// Loads a file and uploads it as shader source
  /** @param file - the shader file's path
    * @see glShaderSource */
  void sourceFile(const std::string& file)  {
    source(ShaderSource(file));
  }

#if OGLWRAP_DEFINE_EVERYTHING || ( \
  defined(glCompileShader) && \
  defined(glGetShaderiv) && \
  defined(glGetShaderInfoLog) \
)
  /// Compiles the shader code.
  /** If the compilation fails, it throws a std::runtime_error, containing the
    * compilation info as .what(). The compilation happens automatically
    * when the shader gets attached a program.
    * @see glCompileShader, glGetShaderiv, glGetShaderInfoLog */
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
      GLint infoLogLength;
      gl(GetShaderiv(shader_, GL_INFO_LOG_LENGTH, &infoLogLength));

      std::unique_ptr<GLchar> strInfoLog{ new GLchar[infoLogLength + 1] };
      gl(GetShaderInfoLog(shader_, infoLogLength, nullptr, strInfoLog.get()));

      std::stringstream str;
        str << "Compile failure in shader '";
        str << filename_ << "' :" << std::endl << strInfoLog.get();

      OGLWRAP_PRINT_FATAL_ERROR(
        "Shader compile failure",
        str.str()
      )
    }
    #endif
  }
#endif  // glCompileShader && glGetShaderInfoLog && glGetShaderiv

  #if OGLWRAP_DEBUG
    /// Returns the file's name that was loaded in.
    const std::string& filename() const {
      return filename_;
    }
  #endif

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
  ComputeShader(const std::string& file)
    : Shader(ShaderType::kComputeShader, file) {}
  ComputeShader(const ShaderSource& src)
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
  VertexShader(const std::string& file)
    : Shader(ShaderType::kVertexShader, file) {}
  VertexShader(const ShaderSource& src)
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
  GeometryShader(const std::string& file)
    : Shader(ShaderType::kGeometryShader, file) {}
  GeometryShader(const ShaderSource& src)
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
  FragmentShader(const std::string& file)
    : Shader(ShaderType::kFragmentShader, file) {}
  FragmentShader(const ShaderSource& src)
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
  TessControlShader(const std::string& file)
    : Shader(ShaderType::kTessControlShader, file) {}
  TessControlShader(const ShaderSource& src)
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
  TessEvaluationShader(const std::string& file)
    : Shader(ShaderType::kTessEvaluationShader, file) {}
  TessEvaluationShader(const ShaderSource& src)
    : Shader(ShaderType::kTessEvaluationShader, src) {}
};
#endif  // GL_TESS_EVALUATION_SHADER

#endif  // glCreateShader && glDeleteShader

#if OGLWRAP_DEFINE_EVERYTHING || \
  (defined(glCreateProgram) && defined(glDeleteProgram) && defined(glDetachShader))
/**
 * @brief The program object can combine multiple shader stages (built from
 *        shader objects) into a single, linked whole.
 * @see glCreateProgram, glDeleteProgram
 */
class Program {
  globjects::Program program_; ///< The C OpenGL handle for the program.
  std::vector<GLuint> shaders_; ///< IDs of the shaders attached to the program

  #if OGLWRAP_DEBUG
    /// The names of the shaders are stored to help debugging.
    std::vector<std::string> filenames_;
  #endif

  /// Stores if the program is linked. Its a pointer, so .use() can be const.
  const std::shared_ptr<bool> linked_;

public:
  /// Creates an empty program object.
  Program() : linked_(new bool{false}) {}

  // The copies aren't special, thanks to std::shared_ptr,
  // even though i had to write destructor.
  Program(const Program&) = default;
  Program& operator=(const Program&) = default;

  /**
   * @brief Detaches all the shader objects currently attached to this program,
   * and deletes the program.
   *
   * @see glDetachShader, glDeleteShader
   */
  ~Program() {
    if (program_.unique()) {
      for (size_t i = 0; i < shaders_.size(); i++) {
        gl(DetachShader(program_, shaders_[i]));
      }
    }
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glAttachShader)
  /// Attaches a shader to this program object, and compiles it, if needed.
  /** @param shader Specifies the shader object that is to be attached.
    * @see glAttachShader */
  void attachShader(Shader& shader) {
    shader.compile();
    shaders_.push_back(shader.expose());

    #if OGLWRAP_DEBUG
      filenames_.push_back(shader.filename());
    #endif

    gl(AttachShader(program_, shader.expose()));
  }
#endif  // glAttachShader

#if OGLWRAP_DEFINE_EVERYTHING || defined(glAttachShader)
  /// Attaches a shader to this program object.
  /** @param shader Specifies the shader object that is to be attached.
    * @see glAttachShader */
  void attachShader(const Shader& shader) {
    shaders_.push_back(shader.expose());

    #if OGLWRAP_DEBUG
      filenames_.push_back(shader.filename());
    #endif

    gl(AttachShader(program_, shader.expose()));
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

#if OGLWRAP_DEFINE_EVERYTHING || ( \
  defined(glLinkProgram) &&          \
  defined(glGetProgramiv) &&         \
  defined(glGetProgramInfoLog)       \
)
  /// Links the program and checks for error if OGLWRAP_DEBUG is defined.
  /** If the linking fails, it throws an
    * std::runtime_error containing the linking info.
    * @see glLinkProgram, glGetProgramiv, glGetProgramInfoLog */
  const Program& link() const {
    gl(LinkProgram(program_));
    *linked_ = true;

    #if OGLWRAP_DEBUG
    GLint status;
    gl(GetProgramiv(program_, GL_LINK_STATUS, &status));
    if (status == GL_FALSE) {
      GLint infoLogLength;
      gl(GetProgramiv(program_, GL_INFO_LOG_LENGTH, &infoLogLength));

      std::unique_ptr<GLchar> strInfoLog{ new GLchar[infoLogLength + 1] };
      gl(GetProgramInfoLog(program_, infoLogLength, NULL, strInfoLog.get()));
      std::stringstream str;
      str << "OpenGL failed to link the following shaders together: " << std::endl;
      str << getShaderNames() << std::endl;
      str << "The error message: \n" << strInfoLog.get();

      OGLWRAP_PRINT_FATAL_ERROR(
        "Program link failure",
        str.str()
      )
    }
    #endif  // OGLWRAP_DEBUG

    return *this;
  }
#endif  // glLinkProgram && glGetProgramiv && glGetProgramInfoLog

#if OGLWRAP_DEFINE_EVERYTHING || ( \
  defined(glValidateProgram) &&      \
  defined(glGetProgramiv) &&         \
  defined(glGetProgramInfoLog)       \
)
  /// Validates the program if OGLWRAP_DEBUG is defined.
  /** @see glLinkProgram, glGetProgramiv, glGetProgramInfoLog */
  void validate() const {
    #if OGLWRAP_DEBUG
    GLint status;
    gl(ValidateProgram(program_));
    gl(GetProgramiv(program_, GL_VALIDATE_STATUS, &status));
    if (status == GL_FALSE) {
      GLint infoLogLength;
      gl(GetProgramiv(program_, GL_INFO_LOG_LENGTH, &infoLogLength));

      std::unique_ptr<GLchar> strInfoLog{ new GLchar[infoLogLength + 1] };
      gl(GetProgramInfoLog(program_, infoLogLength, NULL, strInfoLog.get()));
      std::stringstream str;
      str << "The validation of the program containing the "
      "following shaders failed:\n" << getShaderNames() << std::endl;

      str << "This program might generate GL_INVALID_OPERATION "
      "when used for rendering \nThe validation info: " << strInfoLog.get();

      OGLWRAP_PRINT_ERROR(
        "Program validation failure",
        str.str()
      )
    }
    #endif
  }
#endif  // glValidateProgram && glGetProgramiv && glGetProgramInfoLog

#if OGLWRAP_DEFINE_EVERYTHING || defined(glUseProgram)
  /// Installs the program as a part of the current rendering state.
  /** @see glUseProgram */
  const Program& use() const {
    if (!*linked_) {
      link();
    }
    gl(UseProgram(program_));
    return *this;
  }
#endif


#if OGLWRAP_DEFINE_EVERYTHING || defined(glUseProgram)
  /// Installs the default OpenGL shading program to the current rendering state.
  /** @see glUseProgram */
  static void Unuse() {
    gl(UseProgram(0));
  }
  /// Installs the default OpenGL shading program to the current rendering state.
  /** @see glUseProgram */
  BIND_CHECKED void unuse() const {
    OGLWRAP_CHECK_BINDING2_EXPLICIT(isActive());
    Unuse();
  }
#endif

  /// Returns if this program is the currently active one.
  /** @see glGetIntegerv */
  bool isActive() const {
    GLint currentProgram;
    gl(GetIntegerv(GL_CURRENT_PROGRAM, &currentProgram));

    #if OGLWRAP_DEBUG
      DebugOutput::LastUsedBindTarget() = "GL_CURRENT_PROGRAM";
    #endif

    return program_ == GLuint(currentProgram);
  }

  /// Returns the C OpenGL handle for the program.
  const glObject& expose() const {
    return program_;
  }
};

#endif  // glCreateProgram && glDeleteProgram && glDetachShader

} // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_SHADER_H_
