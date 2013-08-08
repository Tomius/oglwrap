#ifndef SHADER_HPP
#define SHADER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <GL/glew.h>

#include "enums.hpp"
#include "error.hpp"
#include "general.hpp"

namespace oglwrap {

// -------======{[ Shader declaration ]}======-------

template<ShaderType shader_t>
/// A GLSL shader object used to control the drawing process.
class Shader : protected RefCounted {
    GLuint shader; ///< The C API handle for the buffer.
    bool compiled; ///< Stores if the shader is compiled.
    std::string filename;  ///< Stores the source file's name if the shader was initialized from file.
public:
    /// Creates the an empty shader object.
    /// @see glCreateShader
    Shader();

    /// Creates the a shader and sets the file as the shader source.
    /// @param file - The file to load and set as shader source.
    /// @see glCreateShader, glShaderSource
    Shader(const std::string& file);

    /// Uploads a string as the shader's source.
    /// @param source - string containing the shader code.
    /// @see glShaderSource
    void Source(const std::string& source);

    /// Loads a file and uploads it as shader source
    /// @param file - the shader file's path
    /// @see glShaderSource
    void SourceFile(const std::string& file);

    /// Compiles the shader code. If the compilation fails, it throws a std::runtime_error,
    /// containing the compilation info as .what(). The compilation happens automatically
    /// when the shader gets attached a program.
    /// @see glCompileShader
    void Compile();

    /// If only one instance of this shader exists, marks the shader for deletion. The shader
    /// won't be deleted until the shader is attached to at least one program.
    /// @see glDeleteShader
    ~Shader();

    /// Returns the C OpenGL handle for the shader.
    GLuint Expose() const;
};


typedef Shader<ShaderType::Compute> ComputeShader;
/// A Compute Shader is a Shader Stage that is used entirely for computing arbitrary information.
/// While it can do rendering, it is generally used for tasks not directly related to drawing
/// triangles and pixels.
/// @version It is core since OpenGL 4.3.
/// @see GL_COMPUTE_SHADER

typedef Shader<ShaderType::Vertex> VertexShader;
/// The Vertex Shader is the programmable Shader stage in the rendering pipeline that handles the
/// processing of individual vertices. Vertex shaders are fed Vertex Attribute data, as specified
/// from a vertex array object by a rendering command. A vertex shader receives a single vertex from
/// the vertex stream and generates a single vertex to the output vertex stream.
/// @version It is core since OpenGL 2.1
/// @see GL_VERTEX_SHADER

typedef Shader<ShaderType::Geometry> GeometryShader;
///  A Geometry Shader is a Shader program written in GLSL that governs the processing of Primitives.
/// Geometry shaders reside between the Vertex Shaders (or the optional Tessellation stage) and the
/// fixed-function Vertex Post-Processing stage. A geometry shader is optional and does not have to be used.
/// @version It is core since OpenGL 3.2
/// @see GL_GEOMETRY_SHADER

typedef Shader<ShaderType::Fragment> FragmentShader;
/// A Fragment Shader is a user-supplied program that, when executed, will process a Fragment from the
/// rasterization process into a set of colors and a single depth value. The fragment shader is the OpenGL
/// pipeline stage after a primitive is rasterized. For each sample of the pixels covered by a primitive,
/// a "fragment" is generated. Each fragment has a Window Space position, a few other values, and it contains
/// all of the interpolated per-vertex output values from the last Vertex Processing stage. The output of a
/// fragment shader is a depth value, a possible stencil value (unmodified by the fragment shader), and zero
/// or more color values to be potentially written to the buffers in the current framebuffers. Fragment
/// shaders take a single fragment as input and produce a single fragment as output.
/// @version It is core since OpenGL 2.1
/// @see GL_FRAGMENT_SHADER

typedef Shader<ShaderType::TessControl> TessControlShader;
/// The Tessellation Control Shader (TCS) is a Shader program written in GLSL. It sits between the Vertex
/// Shader and the Tessellation Evaluation Shader. The TCS controls how much tessellation a particular patch
/// gets; it also defines the size of a patch, thus allowing it to augment data. It can also filter vertex
/// data taken from the vertex shader. The main purpose of the TCS is to feed the tessellation levels to the
/// Tessellation primitive generator stage, as well as to feed patch data (as its output values) to the
/// Tessellation Evaluation Shader stage.
/// @version It is core since OpenGL 4.0.
/// @see GL_TESS_CONTROL_SHADER

typedef Shader<ShaderType::TessEval> TessEvalShader;
/// The Tessellation Evaluation Shader (TES) is a Shader program written in GLSL that takes the results
/// of a Tessellation operation and computes the interpolated positions and other per-vertex data from them.
/// These values are passed on to the next stage in the pipeline. The (TES) takes the abstract patch generated
/// by the tessellation primitive generation stage, as well as the actual vertex data for the entire patch,
/// and generates a particular vertex from it. Each TES invocation generates a single vertex. It can also take
/// per-patch data provided by the Tessellation Control Shader.
/// @version It is core since OpenGL 4.0.
/// @see GL_TESS_EVALUATION_SHADER

// -------======{[ Shader Program declaration ]}======-------

/// The program object can combine multiple shader stages
/// (built from shader objects) into a single, linked whole.
class Program : protected RefCounted {
    std::vector<GLuint> shaders; ///< IDs of the shaders attached to the program
    GLuint program; ///< The C OpenGL handle for the program.
    bool linked; ///< Stores if the program is linked.
public:
    /// Generates an empty program object.
    /// @see glCreateProgram
    Program();

    /// If only one instance of this program exists, detaches all the shader objects
    /// currently attached to this program, and deletes the program.
    /// @see glDetachShader, glDeleteShader
    ~Program();

    template<ShaderType shader_t>
    /// Attaches a shader to this program object.
    /// @param shader Specifies the shader object that is to be attached.
    /// @see glAttachShader
    void AttachShader(Shader<shader_t>& shader);

    template<ShaderType shader_t>
    /// Attaches a shader object to the program.
    /// @param shader Specifies the shader object that is to be attached.
    /// @see glAttachShader
    Program& operator<<(Shader<shader_t>& shader);

    /// Links the program. If the linking fails, it throws
    /// a std::runtime_error containing the linking info.
    /// @see glLinkProgram
    Program& Link();

    /// Installs the program as a part of the current rendering state
    /// @see glUseProgram
    Program& Use();

    /// Installs the default OpenGL shading program to the current rendering state
    /// @see glUseProgram
    Program& Unuse();

    /// Returns the C OpenGL handle for the program.
    GLuint Expose() const;
};


//         //=====:==-==-==:=====\\                                   //=====:==-==-==:=====\\
//  <---<}>==~=~=~==--==--==~=~=~==<{>----- Class definitions -----<}>==~=~=~==--==--==~=~=~==<{>--->
//         \\=====:==-==-==:=====//                                   \\=====:==-==-==:=====//



// -------======{[ Shader definition ]}======-------

template<ShaderType shader_t>
Shader<shader_t>::Shader() : compiled(false) {
    shader = glCreateShader(shader_t);
}

template<ShaderType shader_t>
Shader<shader_t>::Shader(const std::string& file)
        : compiled(false)
        , filename(file) {
    shader = glCreateShader(shader_t);
    SourceFile(file);
}

template<ShaderType shader_t>
void Shader<shader_t>::Source(const std::string& source) {
    const char *str = source.c_str();
    glShaderSource(shader, 1, &str, nullptr);
    oglwrap_CheckError();
}

template<ShaderType shader_t>
void Shader<shader_t>::SourceFile(const std::string& file) {
    filename = file;
    std::ifstream shaderFile(file.c_str());
    if(!shaderFile.is_open()) {
        shaderFile.open("shaders/" + file);
    }
    if(!shaderFile.is_open()) {
        throw std::runtime_error("File: " + file + " not found.");
    }
    std::stringstream shaderString;
    shaderString << shaderFile.rdbuf();

    // Remove the EOF from the end of the string
    std::string fileData = shaderString.str();
    fileData.pop_back();

    // Add the shader source & compile
    const char *strFileData = fileData.c_str();
    glShaderSource(shader, 1, &strFileData, nullptr);
    oglwrap_CheckError();
}

template<ShaderType shader_t>
void Shader<shader_t>::Compile() {
    if(compiled) {
        return;
    }
    glCompileShader(shader);
    compiled = true;

    // Get compilation status
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE) {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, nullptr, strInfoLog);

        const char * strShaderType = nullptr;
        switch(shader_t) {
            case ShaderType::Compute:
                strShaderType = "compute";
                break;
            case ShaderType::Vertex:
                strShaderType = "vertex";
                break;
            case ShaderType::Geometry:
                strShaderType = "geometry";
                break;
            case ShaderType::Fragment:
                strShaderType = "fragment";
                break;
            case ShaderType::TessControl:
                strShaderType = "tessellation control";
                break;
            case ShaderType::TessEval:
                strShaderType = "tessellation evaluation";
                break;
        }

        std::stringstream str;
        str << "Compile failure in " << strShaderType << "shader '";
        str << filename << "' :" << std::endl << strInfoLog << std::endl;
        delete[] strInfoLog;

        throw std::runtime_error(str.str());
    }
    oglwrap_CheckError();
}

template<ShaderType shader_t>
Shader<shader_t>::~Shader() {
    if(!isDeleteable())
        return;
    glDeleteShader(shader);
    oglwrap_CheckError();
}

template<ShaderType shader_t>
GLuint Shader<shader_t>::Expose() const {
    return shader;
}

// -------======{[ Shader program definition ]}======-------

inline Program::Program()
        : program(glCreateProgram()), linked(false) {
    oglwrap_CheckError();
}

inline Program::~Program() {
    if(!isDeleteable())
        return;
    for(size_t i = 0; i < shaders.size(); i++) {
        glDetachShader(program, shaders[i]);
    }
    glDeleteProgram(program);
    oglwrap_CheckError();
}

template<ShaderType shader_t>
void Program::AttachShader(Shader<shader_t>& shader) {
    shader.Compile();
    shaders.push_back(shader.Expose());
    glAttachShader(program, shader.Expose());
    oglwrap_CheckError();
}

template<ShaderType shader_t>
Program& Program::operator<<(Shader<shader_t>& shader) {
    AttachShader(shader);
    return *this;
}

inline Program& Program::Link() {
    if(linked) {
        return *this;
    }
    glLinkProgram(program);
    linked = true;

    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if(status == GL_FALSE) {
        GLint infoLogLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
        std::stringstream str;
        str << "OpenGL program linker failure: " << strInfoLog << std::endl;
        delete[] strInfoLog;

        throw std::runtime_error(str.str());
    }
    oglwrap_CheckError();
    return *this;
}

inline Program& Program::Use() {
    if(!linked)
        Link();
    glUseProgram(program);
    oglwrap_CheckError();
    return *this;
}

inline Program& Program::Unuse() {
    glUseProgram(0);
    oglwrap_CheckError();
    return *this;
}

inline GLuint Program::Expose() const {
    return program;
}

} // namespace oglwrap

#endif // SHADER_HPP
