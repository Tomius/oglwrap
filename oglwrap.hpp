#ifndef HEADER_726CDFFDFC4FE53D
#define HEADER_726CDFFDFC4FE53D

#include <vector>
#include <string>
#include <cstdarg>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "oglwrap_enums.hpp"

#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

namespace oglwrap {

// -------======{[ Shaders ]}======-------
template<ShaderType shader_t>
class Shader {
#ifdef _DEBUG
    std::string filename;  // helps debugging a lot if you know in which file was the error
#endif
    GLuint shader;
    bool compiled;
public:
    Shader() : compiled(false) {
        shader = glCreateShader(shader_t);
    }
    Shader(const std::string& file)
        : compiled(false)
#ifdef _DEBUG
        , filename(file)
#endif
    {
        shader = glCreateShader(shader_t);
        SourceFile(file);
    }
    void Source(const std::string& source) {
        const char *str = source.c_str();
        glShaderSource(shader, 1, &str, NULL);
    }
    void SourceFile(const std::string& file) {
#ifdef _DEBUG
        filename = file;
#endif
        std::ifstream shaderFile(file.c_str());
        if(!shaderFile.is_open()) {
            shaderFile.open("shaders/" + file);
        }
        if(!shaderFile.is_open()) {
            throw std::runtime_error("File: " + file + " not found.");
        }
        std::stringstream shaderString;
        shaderString << shaderFile.rdbuf();

        // Add the shader source & compile
        const char *strFileData = shaderString.str();
        glShaderSource(shader, 1, &strFileData, NULL);
    }
    void Compile() {
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
            glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

            const char * strShaderType = NULL;
            switch(shader_t) {
                case GL_VERTEX_SHADER:
                    strShaderType = "vertex";
                    break;
                case GL_GEOMETRY_SHADER:
                    strShaderType = "geometry";
                    break;
                case GL_FRAGMENT_SHADER:
                    strShaderType = "fragment";
                    break;
            }

            std::stringstream str;
            str << "Compile failure in " << strShaderType << "shader '";
#ifdef _DEBUG
            str << filename
#endif
                str << "' :" << strInfoLog << std::endl;
            delete[] strInfoLog;

            throw std::runtime_error(str.str());
        }
    }
    ~Shader() {
        glDeleteShader(shader);
    }
    operator GLint() const {
        Compile();
        return shader;
    }
};

typedef Shader<ShaderType::Compute> ComputeShader;
typedef Shader<ShaderType::Vertex> VertexShader;
typedef Shader<ShaderType::Geometry> GeometryShader;
typedef Shader<ShaderType::Fragment> FragmentShader;
typedef Shader<ShaderType::TessControl> TessControlShader;
typedef Shader<ShaderType::TessEval> TessEvalShader;

// -------======{[ Shader programs ]}======-------

class Program {
    std::vector<GLuint> shaders;
    GLuint program;
    bool linked;
public:
    Program()
        : program(glCreateProgram()), linked(false)
    {}
    ~Program() {
        for(size_t i = 0; i < shaders.size(); i++) {
            glDetachShader(program, shaders[i]);
        }
        glDeleteProgram(program);
    }
    template<GLenum ShaderType>
    Program& operator<<(Shader<ShaderType> shader) {
        shaders.push_back(shader);
        glAttachShader(shader);
        return *this;
    }
    template<GLenum ShaderType>
    void AttachShader(Shader<ShaderType> shader) {
        shaders.push_back(shader);
        glAttachShader(shader);
    }
    void Link() {
        if(linked) {
            return;
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
    }
    void Use() const {
        glUseProgram(program);
    }
    operator GLint() {
        Link();
        return program;
    }
};

// -------======{[ Uniforms ]}======-------
#define INVALID_LOCATION 0xFFFFFFFF
template<class GLtype>
class UniformObject {
protected:
    GLuint location;
public:
    UniformObject() : location(INVALID_LOCATION) { }
    UniformObject(GLint loc) : location(loc) { }
    void Set(const GLtype& value) {
        throw std::invalid_argument("Trying to set a uniform to a value that is not an OpenGL type.");
    }
    void operator=(const GLtype& value) {
        Set(value);
    }
    operator GLuint() {
        return location;
    }
};

template<>
void UniformObject<GLfloat>::Set(const GLfloat& value) {
    glUniform1f(location, value);
};

template<>
void UniformObject<GLdouble>::Set(const GLdouble& value) {
    glUniform1d(location, value);
};

template<>
void UniformObject<GLint>::Set(const GLint& value) {
    glUniform1i(location, value);
};

template<>
void UniformObject<GLuint>::Set(const GLuint& value) {
    glUniform1ui(location, value);
};

template<>
void UniformObject<glm::vec2>::Set(const glm::vec2& vec) {
    glUniform2fv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::dvec2>::Set(const glm::dvec2& vec) {
    glUniform2dv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::ivec2>::Set(const glm::ivec2& vec) {
    glUniform2iv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::uvec2>::Set(const glm::uvec2& vec) {
    glUniform2uiv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::vec3>::Set(const glm::vec3& vec) {
    glUniform3fv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::dvec3>::Set(const glm::dvec3& vec) {
    glUniform3dv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::ivec3>::Set(const glm::ivec3& vec) {
    glUniform3iv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::uvec3>::Set(const glm::uvec3& vec) {
    glUniform3uiv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::vec4>::Set(const glm::vec4& vec) {
    glUniform4fv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::dvec4>::Set(const glm::dvec4& vec) {
    glUniform4dv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::ivec4>::Set(const glm::ivec4& vec) {
    glUniform4iv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::uvec4>::Set(const glm::uvec4& vec) {
    glUniform4uiv(location, 1, glm::value_ptr(vec));
};

template<>
void UniformObject<glm::mat2>::Set(const glm::mat2& mat) {
    glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

template<>
void UniformObject<glm::dmat2>::Set(const glm::dmat2& mat) {
    glUniformMatrix2dv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

template<>
void UniformObject<glm::mat3>::Set(const glm::mat3& mat) {
    glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

template<>
void UniformObject<glm::dmat3>::Set(const glm::dmat3& mat) {
    glUniformMatrix3dv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

template<>
void UniformObject<glm::mat4>::Set(const glm::mat4& mat) {
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

template<>
void UniformObject<glm::dmat4>::Set(const glm::dmat4& mat) {
    glUniformMatrix4dv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

template<typename GLtype>
class Uniform : public UniformObject<GLtype> {
public:
    Uniform(Program& program, const std::string& identifier)
        : UniformObject<GLtype>(glGetUniformLocation(program, identifier.c_str())) {
        if(UniformObject<GLtype>::location == INVALID_LOCATION) {
            std::cerr << "Error getting the location of uniform '" << identifier << "'" << std::endl;
        }
    }
    void Set(const GLtype& value) {
        UniformObject<GLtype>::Set(value);
    }
    void operator=(const GLtype& value) {
        Set(value);
    }
};

template<typename GLtype>
class LazyUniform : public UniformObject<GLtype> {
    const std::string identifier;
    const GLuint program;
public:
    LazyUniform(const Program& program, const std::string& identifier)
        : program(program)
        , identifier(identifier)
        , UniformObject<GLtype>(INVALID_LOCATION)
    { }
    void Set(const GLtype& value) {
        // Use the program first. C'mon it's called LazyUniform, caller will forget to do this anyway :)
        glUseProgram(program);

        // Get the uniform's location at the first set call.
        if(UniformObject<GLtype>::location == INVALID_LOCATION) {
            UniformObject<GLtype>::location = glGetUniformLocation(program, identifier.c_str());
        }
        if(UniformObject<GLtype>::location == INVALID_LOCATION) {
            std::cerr << "Error getting the location of uniform '" << identifier << "'" << std::endl;
        }

        UniformObject<GLtype>::Set(value);
    }
    void operator=(const GLtype& value) {
        Set(value);
    }
};

// -------======{[ VertexArray ]}======-------

class VertexArray {
    GLuint vao;
public:
    VertexArray() {
        glGenVertexArrays(1, &vao);
    }
    ~VertexArray() {
        glDeleteVertexArrays(1, &vao);
    }
    void Bind() {
        glBindVertexArray(vao);
    }
    static void Unbind() {
        glBindVertexArray(0);
    }
};

// -------======{[ Vertex Attribute Arrays ]}======-------

class VertexAttribArray {
    GLuint location;
public:
    // Constructors
    VertexAttribArray(GLuint vertexAttribSlot) : location(vertexAttribSlot) {}
    VertexAttribArray(Program& program, const std::string& identifier) {
        location = glGetAttribLocation(program, identifier.c_str());
        if(location == INVALID_LOCATION) {
            std::cerr << "Unable to get VertexAttribArray location of '" << identifier << "'" << std::endl;
        }
    }

    // Setup functions
    const VertexAttribArray& Pointer(GLuint values_per_vertex,
                                     DataType type = DataType::Float,
                                     bool normalized = false,
                                     GLsizei stride = 0,
                                     void *offset_pointer = nullptr) const {
        glVertexAttribPointer(location, values_per_vertex, type, normalized, stride, offset_pointer);
        return *this;
    }
    const VertexAttribArray& IPointer(GLuint values_per_vertex,
                                      DataType type = DataType::Int,
                                      GLsizei stride = 0,
                                      void *offset_pointer = nullptr) const {
        glVertexAttribIPointer(location, values_per_vertex, type, stride, offset_pointer);
        return *this;
    }
    const VertexAttribArray& LPointer(GLuint values_per_vertex,
                                      GLsizei stride = 0,
                                      void *offset_pointer = nullptr) const {
        glVertexAttribLPointer(location, values_per_vertex, DataType::Double, stride, offset_pointer);
        return *this;
    }
    const VertexAttribArray& Format(GLuint values_per_vertex,
                                    DataType type = DataType::Float,
                                    bool normalized = false,
                                    GLuint relative_offset = 0) const {
        glVertexAttribFormat(location, values_per_vertex, type, normalized, relative_offset);
        return *this;
    }
    const VertexAttribArray& IFormat(GLuint values_per_vertex,
                                     DataType type = DataType::Int,
                                     GLuint relative_offset = 0) const {
        glVertexAttribIFormat(location, values_per_vertex, type, relative_offset);
        return *this;
    }
    const VertexAttribArray& LFormat(GLuint values_per_vertex,
                                     GLuint relative_offset = 0) const {
        glVertexAttribLFormat(location, values_per_vertex, DataType::Double, relative_offset);
        return *this;
    }

    // Enable & Disable
    const VertexAttribArray& Enable() const {
        glEnableVertexAttribArray(location);
        return *this;
    }

    const VertexAttribArray& Disable() const {
        glDisableVertexAttribArray(location);
        return *this;
    }

    // Divisor
    const VertexAttribArray& Divisor(GLuint divisor) const {
        glVertexAttribDivisor(location, divisor);
        return *this;
    }
};

// -------======{[ Buffers ]}======-------
template<BufferType buffer_t>
class BufferObject {
    GLuint buffer;
public:
    BufferObject() {
        glGenBuffers(1, &buffer);
    }
    ~BufferObject() {
        glDeleteBuffers(1, &buffer);
    }

    // Binds
    void Bind() {
        glBindBuffer(buffer_t, buffer);
    }
    void BindBase(GLuint index) {
        glBindBufferBase(buffer_t, index, buffer);
    }
    void BindRange(GLuint index, GLintptr offset, GLsizeiptr size) {
        glBindBufferRange(buffer_t, index, offset, size, buffer);
    }

    // Unbinds
    static void Unbind() {
        glBindBuffer(buffer_t, 0);
    }
    static void UnbindBase(GLuint index) {
        glBindBufferBase(buffer_t, index, 0);
    }

    // Data uploads
    template<typename GLtype>
    static void Data(GLsizei count, const GLtype* data,
                     BufferUsage usage = BufferUsage::StaticDraw) {
        glBufferData(buffer_t, count * sizeof(GLtype), data, usage);
    }
    template<typename GLtype>
    static void Data(const std::vector<GLtype>& data,
                     BufferUsage usage = BufferUsage::StaticDraw) {
        glBufferData(buffer_t, data.size() * sizeof(GLtype), data.data(), usage);
    }
    template<typename GLtype>
    static void SubData(GLsizei count, GLintptr offset, const GLtype* data,
                        BufferUsage usage = BufferUsage::StaticDraw) {
        glBufferSubData(buffer_t, offset, count * sizeof(GLtype), data, usage);
    }
    template<typename GLtype>
    static void SubData(const std::vector<GLtype>& data, GLintptr offset,
                        BufferUsage usage = BufferUsage::StaticDraw) {
        glBufferData(buffer_t, offset, data.size() * sizeof(GLtype), data.data(), usage);
    }

    // Size
    static size_t Size(GLuint target = buffer_t) {
        GLint data;
        glGetBufferParameteriv(target, GL_BUFFER_SIZE, &data);
        return data;
    }

    operator GLint() const{
        return buffer;
    }
};

typedef BufferObject<BufferType::Array>               Buffer;
typedef BufferObject<BufferType::ElementArray>        IndexBuffer;
typedef BufferObject<BufferType::Uniform>             UniformBuffer;
typedef BufferObject<BufferType::Texture>             TextureBuffer;
typedef BufferObject<BufferType::TransformFeedback>   TransformFeedbackBuffer;

// -------======{[ Texture ]}======-------

template <TexType texture_t>
class TextureBase {
    GLuint texture;
public:
    TextureBase() {
        glGenTextures(1, &texture);
    }
    virtual ~TextureBase() {
        glDeleteTextures(1, &texture);
    }
    void Bind() {
        glBindTexture(texture_t, texture);
    }
    static void Unbind() {
        glBindTexture(texture_t, 0);
    }
    static void Active(GLuint texUnit) {
        glActiveTexture(texUnit);
    }
    static void WrapS(Wrap wrapmode) {
        glTexParameteri(texture_t, GL_TEXTURE_WRAP_S, wrapmode);
    }
    static void WrapT(Wrap wrapmode) {
        glTexParameteri(texture_t, GL_TEXTURE_WRAP_T, wrapmode);
    }
    static void WrapR(Wrap wrapmode) {
        glTexParameteri(texture_t, GL_TEXTURE_WRAP_R, wrapmode);
    }
    static void MinF(MinFilter filtermode) {
        glTexParameteri(texture_t, GL_TEXTURE_MIN_FILTER, filtermode);
    }
    static void MagF(MagFilter filtermode) {
        glTexParameteri(texture_t, GL_TEXTURE_MAG_FILTER, filtermode);
    }
    static void GenerateMipmap() {
        glGenerateMipmap(texture_t);
    }
    static void SwizzleR(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_R, swizzlemode);
    }
    static void SwizzleG(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_G, swizzlemode);
    }
    static void SwizzleB(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_B, swizzlemode);
    }
    static void SwizzleA(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_A, swizzlemode);
    }
    static void SwizzleRGBA(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_RGBA, swizzlemode);
    }
    static void BorderColor(glm::vec4 color) {
        glTexParameterfv(texture_t, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color));
    }
    static CubeTarget CubeFace(int i) {
        switch(i) {
            case 0:
                return CubeTarget::PosX;
            case 1:
                return CubeTarget::NegX;
            case 2:
                return CubeTarget::PosY;
            case 3:
                return CubeTarget::NegY;
            case 4:
                return CubeTarget::PosZ;
            case 5:
                return CubeTarget::NegZ;
            default:
                throw std::invalid_argument("CubeFace argument must be between 0 and 5");
        }
    }

    static void Buffer(PixelDataInternalFormat internalFormat, const TextureBuffer& buffer) {
        glTexBuffer(texture_t, internalFormat, buffer);
    }
};

class Image1D : public TextureBase<TexType::Tex1D> {
public:
    // Uploads
    static void Upload(
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage1D(
            TexType::Tex1D, 0, internalFormat, width, 0, format, type, data
        );
    }
    static void Upload_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage1D(
            TexType::Tex1D, level, internalFormat, width, 0, format, type, data
        );
    }
    static void SubUpload(
        GLint xOffset,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexSubImage1D(
            TexType::Tex1D, 0, xOffset, width, format, type, data
        );
    }
    static void SubUpload_Mipmap(
        GLint level,
        GLint xOffset,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexSubImage1D(
            TexType::Tex1D, level, xOffset, width, format, type, data
        );
    }

    // Copies
    static void Copy(
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width
    ) {
        glCopyTexImage1D(
            TexType::Tex1D, 0, internalFormat, x, y, width, 0
        );
    }
    static void Copy_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width
    ) {
        glCopyTexImage1D(
            TexType::Tex1D, level, internalFormat, x, y, width, 0
        );
    }
    static void CopySub(
        GLint xOffset,
        GLint x,
        GLint y,
        GLsizei width
    ) {
        glCopyTexSubImage1D(
            TexType::Tex1D, 0, xOffset, x, y, width
        );
    }
    static void CopySub_Mipmap(
        GLint level,
        GLint xOffset,
        GLint x,
        GLint y,
        GLsizei width
    ) {
        glCopyTexSubImage1D(
            TexType::Tex1D, level, xOffset, x, y, width
        );
    }

    // Size getter
    static GLsizei Width(GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(TexType::Tex1D, level, GL_TEXTURE_WIDTH, &data);
        return data;
    }

    // Get compressed image
    static void GetCompressedImage(GLint level, GLvoid* img) {
        glGetCompressedTexImage(TexType::Tex1D, level, img);
    }
};

template<Tex2DType texture_t>
class Image2D : public TextureBase<TexType(texture_t)> {
public:
    // Uploads
    static void Upload(
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage2D(
            texture_t, 0, internalFormat, width, height, 0, format, type, data
        );
    }
    static void Upload_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage2D(
            texture_t, level, internalFormat, width, height, 0, format, type, data
        );
    }
    static void SubUpload(
        GLint xOffset,
        GLint yOffset,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexSubImage2D(
            texture_t, 0, xOffset, yOffset, width, height, format, type, data
        );
    }
    static void SubUpload_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexSubImage2D(
            texture_t, level, xOffset, yOffset, width, height, format, type, data
        );
    }

    // Copies
    static void Copy(
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexImage2D(texture_t, 0, internalFormat, x, y, width, height, 0);
    }
    static void Copy_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexImage2D(texture_t, level, internalFormat, x, y, width, height, 0);
    }
    static void CopySub(
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexSubImage2D(texture_t, 0, xOffset, yOffset, x, y, width, height);
    }
    static void CopySub_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexSubImage2D(texture_t, level, xOffset, yOffset, x, y, width, height);
    }

    // Size getters
    static GLsizei Width(GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_WIDTH, &data);
        return data;
    }
    static GLsizei Height(GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_HEIGHT, &data);
        return data;
    }

    // Get compressed image
    static void GetCompressedImage(GLint level, GLvoid* img) {
        glGetCompressedTexImage(TexType::Tex2D, level, img);
    }
};

class ImageCube : public TextureBase<TexType::TexCubeMap> {
public:
    // uploads
    static void Upload(
        CubeTarget target,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage2D(
            target, 0, internalFormat, width, height, 0, format, type, data
        );
    }
    static void Upload_Mipmap(
        CubeTarget target,
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage2D(
            target, level, internalFormat, width, height, 0, format, type, data
        );
    }
    static void SubUpload(
        CubeTarget target,
        GLint xOffset,
        GLint yOffset,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexSubImage2D(
            target, 0, xOffset, yOffset, width, height, format, type, data
        );
    }
    static void SubUpload_Mipmap(
        CubeTarget target,
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexSubImage2D(
            target, level, xOffset, yOffset, width, height, format, type, data
        );
    }

    // Copies
    static void Copy(
        CubeTarget target,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexImage2D(target, 0, internalFormat, x, y, width, height, 0);
    }
    static void Copy_Mipmap(
        CubeTarget target,
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexImage2D(target, level, internalFormat, x, y, width, height, 0);
    }
    static void CopySub(
        CubeTarget target,
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexSubImage2D(target, 0, xOffset, yOffset, x, y, width, height);
    }
    static void CopySub_Mipmap(
        CubeTarget target,
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexSubImage2D(target, level, xOffset, yOffset, x, y, width, height);
    }

    // Size getters
    static GLsizei Width(CubeTarget target, GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(target, level, GL_TEXTURE_WIDTH, &data);
        return data;
    }
    static GLsizei Height(CubeTarget target, GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(target, level, GL_TEXTURE_HEIGHT, &data);
        return data;
    }

    // compressed image getter
    static void GetCompressedImage(CubeTarget target, GLint level, GLvoid* img) {
        glGetCompressedTexImage(target, level, img);
    }
};

template<Tex3DType texture_t>
class Image3D : public TextureBase<TexType(texture_t)> {
public:
    // Uploads
    static void Upload(
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage3D(
            texture_t, 0, internalFormat, width, height, depth, 0, format, type, data
        );
    }
    static void Upload_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage3D(
            texture_t, level, internalFormat, width, height, depth, 0, format, type, data
        );
    }
    static void SubUpload(
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexSubImage3D(
            texture_t, 0, xOffset, yOffset, zOffset, width, height, depth, format, type, data
        );
    }
    static void SubUpload_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexSubImage3D(
            texture_t, level, xOffset, yOffset, zOffset, width, height, depth, format, type, data
        );
    }

    // Copies
    static void CopySub(
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexSubImage3D(texture_t, 0, xOffset, yOffset, zOffset, x, y, width, height);
    }
    static void CopySub_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexSubImage3D(texture_t, level, xOffset, yOffset, zOffset, x, y, width, height);
    }

    // Size getters
    static GLsizei Width(GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_WIDTH, &data);
        return data;
    }
    static GLsizei Height(GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_HEIGHT, &data);
        return data;
    }
    static GLsizei Depth(GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_DEPTH, &data);
        return data;
    }

    // compressed image getter
    static void GetCompressedImage(GLint level, GLvoid* img) {
        glGetCompressedTexImage(TexType::Tex3D, level, img);
    }
};

} // Namespace oglwrap


#endif // header guard

