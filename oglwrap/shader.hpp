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
class Shader : protected RefCounted {
    GLuint shader;
    bool compiled;
    std::string filename;  // helps debugging a lot if you know in which file was the error
public:
    Shader();
    Shader(const std::string& file);
    void Source(const std::string& source);
    void SourceFile(const std::string& file);
    void Compile();
    ~Shader();
    GLuint Expose() const;
};

typedef Shader<ShaderType::Compute> ComputeShader;
typedef Shader<ShaderType::Vertex> VertexShader;
typedef Shader<ShaderType::Geometry> GeometryShader;
typedef Shader<ShaderType::Fragment> FragmentShader;
typedef Shader<ShaderType::TessControl> TessControlShader;
typedef Shader<ShaderType::TessEval> TessEvalShader;

// -------======{[ Shader Program declaration ]}======-------

class Program : protected RefCounted {
    std::vector<GLuint> shaders;
    GLuint program;
    bool linked;
public:
    Program();
    ~Program();
    template<ShaderType shader_t>
        void AttachShader(Shader<shader_t>& shader);
    template<ShaderType shader_t>
        Program& operator<<(Shader<shader_t>& shader);
    Program& Link();
    Program& Use();
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

inline GLuint Program::Expose() const {
    return program;
}

} // namespace oglwrap

#endif // SHADER_HPP
