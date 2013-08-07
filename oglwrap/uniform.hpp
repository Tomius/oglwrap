#ifndef UNIFORM_HPP
#define UNIFORM_HPP

#include <string>
#include <GL/glew.h>

#include "error.h"
#include "enums.hpp"
#include "shader.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace oglwrap {

// -------======{[ UniformObject declaration ]}======-------

template<class GLtype>
class UniformObject {
protected:
    GLuint location;
public:
    UniformObject();
    UniformObject(GLuint location);
    void Set(const GLtype& value);
    void operator=(const GLtype& value);
    GLuint Expose() const;
};

// -------======{[ Uniform declaration ]}======-------

template<typename GLtype>
class Uniform : public UniformObject<GLtype> {
public:
    Uniform(Program& program, const std::string& identifier);
    void Set(const GLtype& value);
    void operator=(const GLtype& value);
};

typedef Uniform<GLint> UniformSampler;


// -------======{[ LazyUniform declaration ]}======-------

template<typename GLtype>
class LazyUniform : public UniformObject<GLtype> {
    Program& program;
    const std::string identifier;
public:
    LazyUniform(Program& program, const std::string& identifier);
    void Set(const GLtype& value);
    void operator=(const GLtype& value);
};

typedef LazyUniform<GLint> LazyUniformSampler;



//         //=====:==-==-==:=====\\                                   //=====:==-==-==:=====\\
//  <---<}>==~=~=~==--==--==~=~=~==<{>----- Class definitions -----<}>==~=~=~==--==--==~=~=~==<{>--->
//         \\=====:==-==-==:=====//                                   \\=====:==-==-==:=====//



// -------======{[ Uniform object definition ]}======-------

template<class GLtype>
UniformObject<GLtype>::UniformObject() : location(INVALID_LOCATION) { }

template<class GLtype>
UniformObject<GLtype>::UniformObject(GLuint loc) : location(loc) { }

template<class GLtype>
void UniformObject<GLtype>::Set(const GLtype& value) {
    throw std::invalid_argument("Trying to set a uniform to a value that is not an OpenGL type.");
}

template<class GLtype>
void UniformObject<GLtype>::operator=(const GLtype& value) {
    Set(value);
}

template<class GLtype>
GLuint UniformObject<GLtype>::Expose() const {
    return location;
}

// -------======{[ UniformObject::Set specializations ]}======-------

template<>
inline void UniformObject<GLfloat>::Set(const GLfloat& value) {
    glUniform1f(location, value);
};

template<>
inline void UniformObject<GLdouble>::Set(const GLdouble& value) {
    glUniform1d(location, value);
};

template<>
inline void UniformObject<GLint>::Set(const GLint& value) {
    glUniform1i(location, value);
};

template<>
inline void UniformObject<GLuint>::Set(const GLuint& value) {
    glUniform1ui(location, value);
};

template<>
inline void UniformObject<glm::vec2>::Set(const glm::vec2& vec) {
    glUniform2fv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::dvec2>::Set(const glm::dvec2& vec) {
    glUniform2dv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::ivec2>::Set(const glm::ivec2& vec) {
    glUniform2iv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::uvec2>::Set(const glm::uvec2& vec) {
    glUniform2uiv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::vec3>::Set(const glm::vec3& vec) {
    glUniform3fv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::dvec3>::Set(const glm::dvec3& vec) {
    glUniform3dv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::ivec3>::Set(const glm::ivec3& vec) {
    glUniform3iv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::uvec3>::Set(const glm::uvec3& vec) {
    glUniform3uiv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::vec4>::Set(const glm::vec4& vec) {
    glUniform4fv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::dvec4>::Set(const glm::dvec4& vec) {
    glUniform4dv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::ivec4>::Set(const glm::ivec4& vec) {
    glUniform4iv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::uvec4>::Set(const glm::uvec4& vec) {
    glUniform4uiv(location, 1, glm::value_ptr(vec));
};

template<>
inline void UniformObject<glm::mat2>::Set(const glm::mat2& mat) {
    glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

template<>
inline void UniformObject<glm::dmat2>::Set(const glm::dmat2& mat) {
    glUniformMatrix2dv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

template<>
inline void UniformObject<glm::mat3>::Set(const glm::mat3& mat) {
    glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

template<>
inline void UniformObject<glm::dmat3>::Set(const glm::dmat3& mat) {
    glUniformMatrix3dv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

template<>
inline void UniformObject<glm::mat4>::Set(const glm::mat4& mat) {
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

template<>
inline void UniformObject<glm::dmat4>::Set(const glm::dmat4& mat) {
    glUniformMatrix4dv(location, 1, GL_FALSE, glm::value_ptr(mat));
};

// -------======{[ Uniform ]}======-------

template<typename GLtype>
Uniform<GLtype>::Uniform(Program& program, const std::string& identifier)
        : UniformObject<GLtype>(glGetUniformLocation(program.Expose(), identifier.c_str())) {
    if(UniformObject<GLtype>::location == INVALID_LOCATION) {
        std::cerr << "Error getting the location of uniform '" << identifier << "'" << std::endl;
    }
    oglwrap_CheckError();
}

template<typename GLtype>
void Uniform<GLtype>::Set(const GLtype& value) {
    UniformObject<GLtype>::Set(value);
    oglwrap_CheckError();
}

template<typename GLtype>
void Uniform<GLtype>::operator=(const GLtype& value) {
    Set(value);
}

// -------======{[ LazyUniform ]}======-------

template<typename GLtype>
LazyUniform<GLtype>::LazyUniform(Program& program, const std::string& identifier)
        : UniformObject<GLtype>(INVALID_LOCATION)
        , program(program)
        , identifier(identifier)
    { }

template<typename GLtype>
void LazyUniform<GLtype>::Set(const GLtype& value) {
    // Use the program first. C'mon it's called LazyUniform,
    // caller will forget to do this anyway :)
    program.Use();

    // Get the uniform's location only at the first Set call.
    static bool firstCall = true;
    if(firstCall) {
        UniformObject<GLtype>::location = glGetUniformLocation(program.Expose(), identifier.c_str());
        firstCall == true;
    }

    // Check if it worked.
    if(UniformObject<GLtype>::location == INVALID_LOCATION) {
        std::cerr << "Error getting the location of uniform '" << identifier << "'" << std::endl;
    }

    UniformObject<GLtype>::Set(value);
    oglwrap_CheckError();
}

template<typename GLtype>
void LazyUniform<GLtype>::operator=(const GLtype& value) {
    Set(value);
}

} // namespace oglwrap

#endif // UNIFORM_HPP
