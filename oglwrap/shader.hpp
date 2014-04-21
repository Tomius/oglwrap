/** @file shader.hpp
    @brief Implements GLSL shaders related classes.
*/

#ifndef OGLWRAP_SHADER_HPP_
#define OGLWRAP_SHADER_HPP_

#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdexcept>

#include "config.hpp"
#include "enums.hpp"
#include "general.hpp"
#include "debug/error.hpp"
#include "debug/binding.hpp"

#include "define_internal_macros.hpp"

namespace oglwrap {

// -------======{[ ShaderStorage ]}======-------

/// A class that can load shader sources in from files, and do some preprocessing on them
class ShaderSource {
  std::string src_; /// The source
  std::string filename_; /// The file's name stored to make debugging easier.
public:
  /// Default constructor.
  ShaderSource() : filename_("Unnamed shader") { }

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
    filename_ = file;
    std::ifstream shaderFile(file.c_str());
    if(!shaderFile.is_open()) {
      shaderFile.open("shaders/" + file);
    }
    if(!shaderFile.is_open()) {
      throw std::runtime_error("Shader file '" + file + "' not found.");
    }
    std::stringstream shaderString;
    shaderString << shaderFile.rdbuf();

    // Remove the EOF from the end of the string.
    src_ = shaderString.str();
    if(src_[src_.length() - 1] == EOF) {
      src_.pop_back();
    }
  }

  template<typename T>
  /// Inserts a value for a defined preprocessor in the shader.
  /** @param macro_name - The name of the macro.
    * @param value - The value to insert. */
  void insertMacroValue(const std::string& macro_name, const T& value) {
    size_t macro_pos = src_.find("#define " + macro_name);
    if(macro_pos == std::string::npos) {
      throw std::invalid_argument(
        "ShaderSource::insert_macro_value is called for '" + filename_ +
        "', but the shader doesn't have any macro named " + macro_name
      );
    }

    size_t macro_end = src_.find('\n', macro_pos);

    std::stringstream sstream;
    sstream << src_.substr(0, macro_pos + strlen("#define ") + macro_name.length());
    sstream << ' ' << value << src_.substr(macro_end);
    src_ = sstream.str();
  }

  /// Returns the file's name that was loaded in.
  std::string const& getFileName() const {
    return filename_;
  }

  /// Returns the source.
  std::string const& getSource() const {
    return src_;
  }
};

// -------======{[ ShaderObject ]}======-------

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glCreateShader) && defined(glDeleteShader))
namespace glObject {
  template<ShaderType shader_t>
  class Shader : public Object {
    void constructor() const { *handle_ = gl(CreateShader(shader_t)); }
  public:
    ~Shader() { if(isDeletable() && *inited_) gl(DeleteShader(*handle_)); }
  };
}

// -------======{[ Shader ]}======-------

template<ShaderType shader_t>
/// A GLSL shader object used to control the drawing process.
/** @see glCreateShader, glDeleteShader */
class Shader {
  glObject::Shader<shader_t> shader_; ///< The handle for the buffer.
  bool compiled_; ///< Stores if the shader is compiled.
  std::string filename_;  ///< Stores the source file's name if the shader was initialized from file.
public:

  /// Creates the an empty shader object.
  Shader() : compiled_(false) { }

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glShaderSource)
  /// Creates a shader and sets the file as the shader source.
  /** @param file - The file to load and set as shader source.
    * @see glShaderSource */
  Shader(const std::string& file)
    : compiled_(false), filename_(file) {
    sourceFile(file);
  }
#endif // glShaderSource

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glShaderSource)
  /// Creates a shader and sets the file as the shader source.
  /** @param source - The source of the shader code.
    * @see glShaderSource */
  Shader(const ShaderSource& source)
    : compiled_(false) {
    const char *str = source.getSource().c_str();
    filename_ = source.getFileName();
    gl(ShaderSource(shader_, 1, &str, nullptr));
  }
#endif // glShaderSource

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glShaderSource)
  /// Uploads a string as the shader's source.
  /** @param source - string containing the shader code.
    * @see glShaderSource */
  void source(const std::string& source) {
    const char *str = source.c_str();
    gl(ShaderSource(shader_, 1, &str, nullptr));
  }
#endif // glShaderSource

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glShaderSource)
  /// Uploads a ShaderSource as the shader's source.
  /** @param source - The source of the shader code.
    * @see glShaderSource */
  void source(const ShaderSource& source) {
    const char *str = source.getSource().c_str();
    filename_ = source.getFileName();
    gl(ShaderSource(shader_, 1, &str, nullptr));
  }
#endif // glShaderSource

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glShaderSource)
  /// Loads a file and uploads it as shader source
  /** @param file - the shader file's path
    * @see glShaderSource */
  void sourceFile(const std::string& file)  {
    filename_ = file;
    std::ifstream shaderFile(file.c_str());
    if(!shaderFile.is_open()) {
      shaderFile.open("shaders/" + file);
    }
    if(!shaderFile.is_open()) {
      throw std::runtime_error("Shader file '" + file + "' not found.");
    }
    std::stringstream shaderString;
    shaderString << shaderFile.rdbuf();

    // Remove the EOF from the end of the string.
    std::string fileData = shaderString.str();
    if(fileData[fileData.length() - 1] == EOF) {
      fileData.pop_back();
    }

    // Add the shader source & compile
    const char *strFileData = fileData.c_str();
    gl(ShaderSource(shader_, 1, &strFileData, nullptr));
  }
#endif // glShaderSource

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glCompileShader) && defined(glGetShaderiv) && defined(glGetShaderInfoLog))
  /// Compiles the shader code.
  /** If the compilation fails, it throws a std::runtime_error, containing the
    * compilation info as .what(). The compilation happens automatically
    * when the shader gets attached a program.
    * @see glCompileShader, glGetShaderiv, glGetShaderInfoLog */
  void compile()  {
    if(compiled_) {
      return;
    }
    gl(CompileShader(shader_));
    compiled_ = true;

    // Get compilation status
    GLint status;
    gl(GetShaderiv(shader_, GL_COMPILE_STATUS, &status));
    if(status == GL_FALSE) {
      GLint infoLogLength;
      gl(GetShaderiv(shader_, GL_INFO_LOG_LENGTH, &infoLogLength));

      GLchar *strInfoLog = new GLchar[infoLogLength + 1];
      gl(GetShaderInfoLog(shader_, infoLogLength, nullptr, strInfoLog));

      const char * strShaderType = nullptr;
      switch(shader_t) {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPUTE_SHADER)
        case ShaderType::Compute:
          strShaderType = "compute";
          break;
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_VERTEX_SHADER)
        case ShaderType::Vertex:
          strShaderType = "vertex";
          break;
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_GEOMETRY_SHADER)
        case ShaderType::Geometry:
          strShaderType = "geometry";
          break;
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAGMENT_SHADER)
        case ShaderType::Fragment:
          strShaderType = "fragment";
          break;
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TESS_CONTROL_SHADER)
        case ShaderType::TessControl:
          strShaderType = "tessellation control";
          break;
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TESS_EVALUATION_SHADER)
        case ShaderType::TessEval:
          strShaderType = "tessellation evaluation";
          break;
#endif
      }

      std::stringstream str;
      str << "Compile failure in " << strShaderType << "shader '";
      str << filename_ << "' :" << std::endl << strInfoLog << std::endl;
      delete[] strInfoLog;

      throw std::runtime_error(str.str());
    }
  }
#endif // glCompileShader && glGetShaderInfoLog && glGetShaderiv

  /// Returns the file's name that was loaded in.
  const std::string& filename() const {
    return filename_;
  }

  /// Returns the C OpenGL handle for the shader.
  const Object& expose() const  {
    return shader_;
  }
};


#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPUTE_SHADER)
/// A Shader that is used for computing arbitrary information.
/** A Compute Shader is a Shader Stage that is used entirely for computing arbitrary information.
  * While it can do rendering, it is generally used for tasks not directly related to drawing
  * triangles and pixels.
  * @version It is core since OpenGL 4.3.
  * @see GL_COMPUTE_SHADER */
typedef Shader<ShaderType::Compute> ComputeShader;

#if OGLWRAP_INSTATIATE_TEMPLATES
  template class glObject::Shader<ShaderType::Compute>;
  template class Shader<ShaderType::Compute>;
#else
  #if !OGLWRAP_HEADER_ONLY
    extern template class glObject::Shader<ShaderType::Compute>;
    extern template class Shader<ShaderType::Compute>;
  #endif
#endif

#endif // GL_COMPUTE_SHADER

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_VERTEX_SHADER)
/// A Shader that handles the processing of individual vertices.
/** The Vertex Shader is the programmable Shader stage in the rendering pipeline that handles the
  * processing of individual vertices. Vertex shaders are fed Vertex Attribute data, as specified
  * from a vertex array object by a rendering command. A vertex shader receives a single vertex from
  * the vertex stream and generates a single vertex to the output vertex stream.
  * @version It is core since OpenGL 2.1
  * @see GL_VERTEX_SHADER */
typedef Shader<ShaderType::Vertex> VertexShader;

#if OGLWRAP_INSTATIATE_TEMPLATES
  template class glObject::Shader<ShaderType::Vertex>;
  template class Shader<ShaderType::Vertex>;
#else
  #if !OGLWRAP_HEADER_ONLY
    extern template class glObject::Shader<ShaderType::Vertex>;
    extern template class Shader<ShaderType::Vertex>;
  #endif
#endif

#endif // GL_VERTEX_SHADER

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_GEOMETRY_SHADER)
/// A Shader that governs the processing of Primitives.
/** A Geometry Shader is a Shader program written in GLSL that governs the processing of Primitives.
  * Geometry shaders reside between the Vertex Shaders (or the optional Tessellation stage) and the
  * fixed-function Vertex Post-Processing stage. A geometry shader is optional and does not have to be used.
  * @version It is core since OpenGL 3.2
  * @see GL_GEOMETRY_SHADER */
typedef Shader<ShaderType::Geometry> GeometryShader;

#if OGLWRAP_INSTATIATE_TEMPLATES
  template class glObject::Shader<ShaderType::Geometry>;
  template class Shader<ShaderType::Geometry>;
#else
  #if !OGLWRAP_HEADER_ONLY
    extern template class glObject::Shader<ShaderType::Geometry>;
    extern template class Shader<ShaderType::Geometry>;
  #endif
#endif

#endif // GL_GEOMETRY_SHADER

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAGMENT_SHADER)
/// A Shader that processes a Fragment from the rasterization process into a set of colors and a single depth value.
/** A Fragment Shader is a user-supplied program that, when executed, will process a Fragment from the
  * rasterization process into a set of colors and a single depth value. The fragment shader is the OpenGL
  * pipeline stage after a primitive is rasterized. For each sample of the pixels covered by a primitive,
  * a "fragment" is generated. Each fragment has a Window Space position, a few other values, and it contains
  * all of the interpolated per-vertex output values from the last Vertex Processing stage. The output of a
  * fragment shader is a depth value, a possible stencil value (unmodified by the fragment shader), and zero
  * or more color values to be potentially written to the buffers in the current framebuffers. Fragment
  * shaders take a single fragment as input and produce a single fragment as output.
  * @version It is core since OpenGL 2.1
  * @see GL_FRAGMENT_SHADER */
typedef Shader<ShaderType::Fragment> FragmentShader;

#if OGLWRAP_INSTATIATE_TEMPLATES
  template class glObject::Shader<ShaderType::Fragment>;
  template class Shader<ShaderType::Fragment>;
#else
  #if !OGLWRAP_HEADER_ONLY
    extern template class glObject::Shader<ShaderType::Fragment>;
    extern template class Shader<ShaderType::Fragment>;
  #endif
#endif

#endif // GL_FRAGMENT_SHADER

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TESS_CONTROL_SHADER)
/// A shader that controls how much tessellation a particular patch gets and also defines the size of a patch.
/** The Tessellation Control Shader (TCS) is a Shader program written in GLSL. It sits between the Vertex
  * Shader and the Tessellation Evaluation Shader. The TCS controls how much tessellation a particular patch
  * gets; it also defines the size of a patch, thus allowing it to augment data. It can also filter vertex
  * data taken from the vertex shader. The main purpose of the TCS is to feed the tessellation levels to the
  * Tessellation primitive generator stage, as well as to feed patch data (as its output values) to the
  * Tessellation Evaluation Shader stage.
  * @version It is core since OpenGL 4.0.
  * @see GL_TESS_CONTROL_SHADER */
typedef Shader<ShaderType::TessControl> TessControlShader;

#if OGLWRAP_INSTATIATE_TEMPLATES
  template class glObject::Shader<ShaderType::TessControl>;
  template class Shader<ShaderType::TessControl>;
#else
  #if !OGLWRAP_HEADER_ONLY
    extern template class glObject::Shader<ShaderType::TessControl>;
    extern template class Shader<ShaderType::TessControl>;
  #endif
#endif

#endif // GL_TESS_CONTROL_SHADER

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TESS_EVALUATION_SHADER)
/// A shader that generates vertices from the patch data.
/** The Tessellation Evaluation Shader (TES) is a Shader program written in GLSL that takes the results
  * of a Tessellation operation and computes the interpolated positions and other per-vertex data from them.
  * These values are passed on to the next stage in the pipeline. The (TES) takes the abstract patch generated
  * by the tessellation primitive generation stage, as well as the actual vertex data for the entire patch,
  * and generates a particular vertex from it. Each TES invocation generates a single vertex. It can also take
  * per-patch data provided by the Tessellation Control Shader.
  * @version It is core since OpenGL 4.0.
  * @see GL_TESS_EVALUATION_SHADER */
typedef Shader<ShaderType::TessEval> TessEvalShader;

#if OGLWRAP_INSTATIATE_TEMPLATES
  template class glObject::Shader<ShaderType::TessEval>;
  template class Shader<ShaderType::TessEval>;
#else
  #if !OGLWRAP_HEADER_ONLY
    extern template class glObject::Shader<ShaderType::TessEval>;
    extern template class Shader<ShaderType::TessEval>;
  #endif
#endif

#endif // GL_TESS_EVALUATION_SHADER

#endif // glCreateShader && glDeleteShader



// -------======{[ Shader Program ]}======-------

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glCreateProgram) && defined(glDeleteProgram))
namespace glObject {
  class Program : public Object {
    void constructor() const { *handle_ = gl(CreateProgram()); }
  public:
    ~Program() { if(isDeletable() && *inited_) gl(DeleteProgram(*handle_)); }
  };
}

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDetachShader)
/// The program object can combine multiple shader stages (built from shader objects) into a single, linked whole.
/** @see glCreateProgram, glDeleteProgram */
class Program {
  glObject::Program program_; ///< The C OpenGL handle for the program.
  std::vector<GLuint> shaders_; ///< IDs of the shaders attached to the program
  std::vector<std::string> filenames_; ///< The names of the shaders are stored to help debugging.
  bool *linked_; ///< Stores if the program is linked. Its a pointer, so .use() can be const.
public:
  /// Creates an empty program object.
  Program() : linked_(new bool) {
    *linked_ = false;
  }

  /// Detaches all the shader objects currently attached to this program, and deletes the program.
  /** @see glDetachShader, glDeleteShader */
  ~Program() {
    if(program_.isDeletable()) {
      for(size_t i = 0; i < shaders_.size(); i++) {
        gl(DetachShader(program_, shaders_[i]));
      }
      delete linked_;
    }
  }

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glAttachShader)
  template<ShaderType shader_t>
  /// Attaches a shader to this program object, and compiles it, if needed.
  /** @param shader Specifies the shader object that is to be attached.
    * @see glAttachShader */
  void attachShader(Shader<shader_t>& shader) {
    shader.compile();
    shaders_.push_back(shader.expose());
    filenames_.push_back(shader.filename());
    gl(AttachShader(program_, shader.expose()));
  }
#endif // glAttachShader

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glAttachShader)
  template<ShaderType shader_t>
  /// Attaches a shader to this program object.
  /** @param shader Specifies the shader object that is to be attached.
    * @see glAttachShader */
  void attachShader(const Shader<shader_t>& shader) {
    shaders_.push_back(shader.expose());
    filenames_.push_back(shader.filename());
    gl(AttachShader(program_, shader.expose()));
  }
#endif // glAttachShader

  template<ShaderType shader_t>
  /// Attaching rvalue reference shaders to programs only work correctly on NVIDIA.
  Program& attachShader(Shader<shader_t>&& shader) = delete;

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glAttachShader)
  template<ShaderType shader_t>
  /// Attaches a shader object to the program.
  /** @param shader Specifies the shader object that is to be attached.
    * @see glAttachShader */
  Program& operator<<(Shader<shader_t>& shader) {
    attachShader(shader);
    return *this;
  }
#endif // glAttachShader

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glAttachShader)
  template<ShaderType shader_t>
  /// Attaches a shader object to the program, and compiles it, if needed.
  /** @param shader Specifies the shader object that is to be attached.
    * @see glAttachShader */
  Program& operator<<(const Shader<shader_t>& shader) {
    attachShader(shader);
    return *this;
  }
#endif // glAttachShader

  template<ShaderType shader_t>
  /// Attaching rvalue reference shaders to a programs only work correctly on NVIDIA.
  Program& operator<<(Shader<shader_t>&& shader) = delete;

  /// Returns a formatted list of the names of the shaders that this program uses.
  std::string getShaderNames() const {
    std::string str;
    for(size_t i = 0; i < filenames_.size(); i++) {
        str += " - " + filenames_[i] + "\n";
    }
    return str;
  }

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glLinkProgram) && defined(glGetProgramiv) && defined(glGetProgramInfoLog))
  /// Links the program.
  /** If the linking fails, it throws a std::runtime_error containing the linking info.
    * @see glLinkProgram, glGetProgramiv, glGetProgramInfoLog */
  const Program& link() const {
    gl(LinkProgram(program_));
    *linked_ = true;

    #ifdef OGLWRAP_DEBUG
    GLint status;
    gl(GetProgramiv(program_, GL_LINK_STATUS, &status));
    if(status == GL_FALSE) {
      GLint infoLogLength;
      gl(GetProgramiv(program_, GL_INFO_LOG_LENGTH, &infoLogLength));

      GLchar *strInfoLog = new GLchar[infoLogLength + 1];
      gl(GetProgramInfoLog(program_, infoLogLength, NULL, strInfoLog));
      std::stringstream str;
      str << "OpenGL failed to link the following shaders together: " << std::endl;
      str << getShaderNames() << std::endl;
      str << "The error message: \n" << strInfoLog << std::endl;
      delete[] strInfoLog;

      throw std::runtime_error(str.str());
    }

    gl(ValidateProgram(program_));
    gl(GetProgramiv(program_, GL_VALIDATE_STATUS, &status));
    if(status == GL_FALSE) {
      GLint infoLogLength;
      gl(GetProgramiv(program_, GL_INFO_LOG_LENGTH, &infoLogLength));

      GLchar *strInfoLog = new GLchar[infoLogLength + 1];
      gl(GetProgramInfoLog(program_, infoLogLength, NULL, strInfoLog));
      std::cout << "The validation of the program containing the following shaders failed: " << std::endl;
      std::cout << getShaderNames() << std::endl;
      std::cout << "This program might generate GL_INVALID_OPERATION when used for rendering" << std::endl;
      if(infoLogLength)
        std::cout << "The validation info: " << strInfoLog << std::endl;
      delete[] strInfoLog;
    }
    #endif // OGLWRAP_DEBUG

    return *this;
  }
#endif // glLinkProgram && glGetProgramiv && glGetProgramInfoLog

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUseProgram)
  /// Installs the program as a part of the current rendering state.
  /** @see glUseProgram */
  const Program& use() const {
    if(!*linked_) {
      link();
    }
    gl(UseProgram(program_));
    return *this;
  }
#endif


#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUseProgram)
  /// Installs the default OpenGL shading program to the current rendering state.
  /** @see glUseProgram */
  static void Unuse() {
    gl(UseProgram(0));
  }
  /// Installs the default OpenGL shading program to the current rendering state.
  /** @see glUseProgram */
  BIND_CHECKED void unuse() const {
    CHECK_BINDING2_EXPLICIT(isActive());
    Unuse();
  }
#endif

  /// Returns if this program is the currently active one.
  /** @see glGetIntegerv */
  bool isActive() const {
    GLint currentProgram;
    gl(GetIntegerv(GL_CURRENT_PROGRAM, &currentProgram));
    OGLWRAP_LAST_BIND_TARGET = "GL_CURRENT_PROGRAM";
    return program_ == GLuint(currentProgram);
  }

  /// Returns the C OpenGL handle for the program.
  const Object& expose() const {
    return program_;
  }
};

// Explicit template instantiation (is ugly, but makes compilation a lot faster)
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glAttachShader)
  #if OGLWRAP_INSTATIATE_TEMPLATES
    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPUTE_SHADER)
      template void Program::attachShader(ComputeShader&);
      template void Program::attachShader(const ComputeShader&);
      template Program& Program::operator<<(ComputeShader&);
      template Program& Program::operator<<(const ComputeShader&);
    #endif
    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_VERTEX_SHADER)
      template void Program::attachShader(VertexShader&);
      template void Program::attachShader(const VertexShader&);
      template Program& Program::operator<<(VertexShader&);
      template Program& Program::operator<<(const VertexShader&);
    #endif
    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAGMENT_SHADER)
      template void Program::attachShader(FragmentShader&);
      template void Program::attachShader(const FragmentShader&);
      template Program& Program::operator<<(FragmentShader&);
      template Program& Program::operator<<(const FragmentShader&);
    #endif
    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_GEOMETRY_SHADER)
      template void Program::attachShader(GeometryShader&);
      template void Program::attachShader(const GeometryShader&);
      template Program& Program::operator<<(GeometryShader&);
      template Program& Program::operator<<(const GeometryShader&);
    #endif
    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TESS_CONTROL_SHADER)
      template void Program::attachShader(TessControlShader&);
      template void Program::attachShader(const TessControlShader&);
      template Program& Program::operator<<(TessControlShader&);
      template Program& Program::operator<<(const TessControlShader&);
    #endif
    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TESS_EVALUATION_SHADER)
      template void Program::attachShader(TessEvalShader&);
      template void Program::attachShader(const TessEvalShader&);
      template Program& Program::operator<<(TessEvalShader&);
      template Program& Program::operator<<(const TessEvalShader&);
    #endif
  #else
    #if !OGLWRAP_HEADER_ONLY
      #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPUTE_SHADER)
        extern template void Program::attachShader(ComputeShader&);
        extern template void Program::attachShader(const ComputeShader&);
        extern template Program& Program::operator<<(ComputeShader&);
        extern template Program& Program::operator<<(const ComputeShader&);
      #endif
      #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_VERTEX_SHADER)
        extern template void Program::attachShader(VertexShader&);
        extern template void Program::attachShader(const VertexShader&);
        extern template Program& Program::operator<<(VertexShader&);
        extern template Program& Program::operator<<(const VertexShader&);
      #endif
      #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAGMENT_SHADER)
        extern template void Program::attachShader(FragmentShader&);
        extern template void Program::attachShader(const FragmentShader&);
        extern template Program& Program::operator<<(FragmentShader&);
        extern template Program& Program::operator<<(const FragmentShader&);
      #endif
      #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_GEOMETRY_SHADER)
        extern template void Program::attachShader(GeometryShader&);
        extern template void Program::attachShader(const GeometryShader&);
        extern template Program& Program::operator<<(GeometryShader&);
        extern template Program& Program::operator<<(const GeometryShader&);
      #endif
      #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TESS_CONTROL_SHADER)
        extern template void Program::attachShader(TessControlShader&);
        extern template void Program::attachShader(const TessControlShader&);
        extern template Program& Program::operator<<(TessControlShader&);
        extern template Program& Program::operator<<(const TessControlShader&);
      #endif
      #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TESS_EVALUATION_SHADER)
        extern template void Program::attachShader(TessEvalShader&);
        extern template void Program::attachShader(const TessEvalShader&);
        extern template Program& Program::operator<<(TessEvalShader&);
        extern template Program& Program::operator<<(const TessEvalShader&);
      #endif
    #endif
  #endif
#endif

#endif // glDetachShader
#endif // glCreateProgram && glDeleteProgram

} // namespace oglwrap

#include "undefine_internal_macros.hpp"

#endif // OGLWRAP_SHADER_HPP_
