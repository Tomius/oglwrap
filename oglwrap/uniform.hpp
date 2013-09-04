/** @file uniform.hpp
    @brief Implements GLSL uniform uploaders.
*/

#pragma once

namespace oglwrap {

// -------======{[ UniformObject ]}======-------
#ifdef glGetUniformLocation
template<class GLtype>
/// An object implementing the base features Uniforms.
/** You shouldn't use this class directly. Rather use Uniform or LazyUniform. */
class UniformObject {
protected:
    GLuint location; ///< The C handle for the uniform's location

    /// The handle defaults to INVALID_LOCATION
    UniformObject()
        : location(INVALID_LOCATION) { }

    /// Sets the location handle.
    UniformObject(GLuint location)
        : location(location) { }

    /// Sets the uniform to a GLtype variable's value. It finds the appropriate glUniform*
    /// using template specialization. If it is called with not an OpenGL type, it throws
    /// std::invalid argument.
    /// @see glUniform*
    void set(const GLtype& value) { // See the specializations at the end of this file.
        throw std::invalid_argument("Trying to set a uniform to a value that is not an OpenGL type.");
    }

    /// Sets the uniform to 'value', via the set() function.
    /// @see set
    void operator=(const GLtype& value) {
        set(value);
    }

public:
    /// Returns the C OpenGL handle for the uniform's location.
    GLuint expose() const {
        return location;
    }
};

// -------======{[ Uniform ]}======-------

template<typename GLtype>
/// Uniform is used to set a uniform variable's value in a specified program.
/** It queries the location of the uniform in the constructor and also notifies on the
  * stderr, if getting the location of the variable, or setting it didn't work. */
class Uniform : public UniformObject<GLtype> {
    #if OGLWRAP_DEBUG
    const std::string identifier;
    #endif
public:
    /// Queries a variable named 'identifier' in the 'program', and stores it's location.
    /** It writes to stderr if the query didn't work. Also changes the currently active
      * program to the program given as a parameter. */
    /// @param program - The program to seek the uniform in. Will call program.use().
    /// @param identifier - The name of the uniform that is to be set.
    /// @see glGetUniformLocation
    Uniform(Program& program, const std::string& identifier)
    #if OGLWRAP_DEBUG
    :identifier(identifier)
    #endif
    {
        program.use();
        UniformObject<GLtype>::location = gl( GetUniformLocation(program.expose(), identifier.c_str()) );

        if(UniformObject<GLtype>::location == INVALID_LOCATION) {
            std::cerr << "Error getting the location of uniform '" << identifier << "'" << std::endl;
        }
    }

    /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
    /** It throws std::invalid_argument if it is an unrecognized type. */
    /// @param value - Specifies the new value to be used for the uniform variable.
    /// @see glUniform*
    void set(const GLtype& value) {
        glfunc( UniformObject<GLtype>::set(value) );

        OGLWRAP_PRINT_ERROR(
            GL_INVALID_OPERATION,
            std::string("Uniform::set is called ") +
            #if OGLWRAP_DEBUG
            "for uniform '" + identifier + "'" +
            #endif
            " but the uniform template parameter and the actual uniform type mismatches, "
            "or there is no current program object."
        )
    }

    /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
    /** It throws std::invalid_argument if it is an unrecognized type. */
    /// @param value - Specifies the new value to be used for the uniform variable.
    /// @see glUniform*
    void operator=(const GLtype& value) {
        set(value);
    }
};

/// @brief A Uniform that sets a sampler.
typedef Uniform<GLint> UniformSampler;

// -------======{[ IndexedUniform ]}======-------

template<typename GLtype>
/// IndexedUniform is used to set an element of a uniform array in a specified program.
/** It queries the location of the uniform in the constructor and also notifies on the
    stderr, if getting the location of the variable, or setting it didn't work. */
class IndexedUniform : public UniformObject<GLtype> {
    #if OGLWRAP_DEBUG
    std::string identifier;
    #endif
public:
    /// Queries a variable named 'identifier' in the 'program', and stores it's location.
    /** It writes to stderr if the query didn't work. Also changes the currently active
      * program to the program given as a parameter. */
    /// @param program - The program to seek the uniform in. Will call program.use().
    /// @param _identifier - The name of the uniform that is to be set.
    /// @param idx - The index of the element in the uniform array.
    /// @see glGetUniformLocation
    IndexedUniform(Program& program, const std::string& _identifier, size_t idx)
    {
        std::stringstream id;
        id << _identifier << '[' << idx << ']';
        #if OGLWRAP_DEBUG
            identifier = id.str();
        #endif

        program.use();
        UniformObject<GLtype>::location = gl( GetUniformLocation(program.expose(), id.str().c_str()) );

        if(UniformObject<GLtype>::location == INVALID_LOCATION) {
            std::cerr << "Error getting the location of uniform '" << id.str() << "'" << std::endl;
        }
    }

    /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
    /** It throws std::invalid_argument if it is an unrecognized type. */
    /// @param value - Specifies the new value to be used for the uniform variable.
    /// @see glUniform*
    void set(const GLtype& value) {
        glfunc( UniformObject<GLtype>::set(value) );

        OGLWRAP_PRINT_ERROR(
            GL_INVALID_OPERATION,
            std::string("Uniform::set is called ") +
            #if OGLWRAP_DEBUG
            "for uniform '" + identifier + "'" +
            #endif
            " but the uniform template parameter and the actual uniform type mismatches, "
            "or there is no current program object."
        )
    }

    /// Sets the uniform to value if it is an OpenGL type or a glm vector or matrix.
    /** It throws std::invalid_argument if it is an unrecognized type. */
    /// @param value - Specifies the new value to be used for the uniform variable.
    /// @see glUniform*
    void operator=(const GLtype& value) {
        set(value);
    }
};

/// @brief An IndexedUniform that sets a value of an element of a sampler array.
typedef IndexedUniform<GLint> IndexedUniformSampler;

// -------======{[ LazyUniform ]}======-------

template<typename GLtype>
/// LazyUniform is used to set uniform variables in shaders in a lazy way.
/** It takes a program reference and the uniform's name as a constructor,
  * but the program doesn't have to be valid at that time. The variable's
  * locations will only be queried at the first set call (or op=), so
  * it have to query the location all the time, like how the normal
  * Uniform class works. It also has the advantage, that you only have
  * to write program's and the uniform's name once, no matter how many
  * times you set it. */
class LazyUniform : public UniformObject<GLtype> {
    Program& program; ///< The program in which the uniform should be set.
    const std::string identifier; ///< The uniform's name.
    bool firstCall;
public:
    /// Stores the uniform's information.
    /** It will only be used at the first set() or op=() call, so the program
      * doesn't have to be valid at the time this constructor is called. */
    /// @param program - The program in which the uniform is to be set.
    /// @param identifier - The uniform's name.
    LazyUniform(Program& program, const std::string& identifier)
        : UniformObject<GLtype>(INVALID_LOCATION)
        , program(program)
        , identifier(identifier)
        , firstCall(true) {
    }

    /// Sets the uniforms value.
    /** At the first call, queries the uniform's location. It writes to stderr if it was unable to get it.
      * At every call it sets the uniform to the specified value. It also changes the active program
      * to the one specified in the constructor. */
    /// @param value - Specifies the new value to be used for the uniform variable.
    void set(const GLtype& value) {
        program.use();

        // Get the uniform's location only at the first set call.
        if(firstCall) {
            UniformObject<GLtype>::location = gl( GetUniformLocation(program.expose(), identifier.c_str()) );

            // Check if it worked.
            if(UniformObject<GLtype>::location == INVALID_LOCATION) {
                std::cerr << "Error getting the location of uniform '" << identifier << "'" << std::endl;
            }

            firstCall = false;
        }

        glfunc( UniformObject<GLtype>::set(value) );

        OGLWRAP_PRINT_ERROR(
            GL_INVALID_OPERATION,
            "Uniform::set is called for uniform '" + identifier + "' but the "
            "uniform template parameter and the actual uniform type mismatches, "
            "or there is no current program object."
        )
    }

    /// Sets the uniforms value.
    /** At the first call, queries the uniform's location. It writes to stderr if it was unable to get it.
      * At every call it sets the uniform to the specified value. It also changes the active program
      * to the one specified in the constructor. */
    /// @param value - Specifies the new value to be used for the uniform variable.
    void operator=(const GLtype& value) {
        set(value);
    }

    /// Is used to set an element of a uniform array.
    /** For example if you have a mat4 myMatrix[10]; and you created a lazyUniform
      * myMatUnif(prog, "myMatrix), you can call myMatUnif[5].set() to set myMatrix[5]. */
    IndexedUniform<GLtype> operator[](size_t idx) {
        return IndexedUniform<GLtype>(program, identifier, idx);
    }
};

/// @brief A LazyUniform that sets a sampler.
typedef LazyUniform<GLint> LazyUniformSampler;


// -------======{[ UniformObject::set specializations ]}======-------
#ifdef glUniform1f
template<>
inline void UniformObject<GLfloat>::set(const GLfloat& value) {
    glUniform1f(location, value);
};
#endif // glUniform1f

#ifdef glUniform1d
template<>
inline void UniformObject<GLdouble>::set(const GLdouble& value) {
    glUniform1d(location, value);
};
#endif // glUniform1d

#ifdef glUniform1i
template<>
inline void UniformObject<GLint>::set(const GLint& value) {
    glUniform1i(location, value);
};
#endif // glUniform1i

#ifdef glUniform1ui
template<>
inline void UniformObject<GLuint>::set(const GLuint& value) {
    glUniform1ui(location, value);
};
#endif // glUniform1ui

#ifdef glUniform2fv
template<>
inline void UniformObject<glm::vec2>::set(const glm::vec2& vec) {
    glUniform2fv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform2fv

#ifdef glUniform2dv
template<>
inline void UniformObject<glm::dvec2>::set(const glm::dvec2& vec) {
    glUniform2dv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform2dv

#ifdef glUniform2iv
template<>
inline void UniformObject<glm::ivec2>::set(const glm::ivec2& vec) {
    glUniform2iv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform2iv

#ifdef glUniform2uiv
template<>
inline void UniformObject<glm::uvec2>::set(const glm::uvec2& vec) {
    glUniform2uiv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform2uiv

#ifdef glUniform3fv
template<>
inline void UniformObject<glm::vec3>::set(const glm::vec3& vec) {
    glUniform3fv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform3fv

#ifdef glUniform3dv
template<>
inline void UniformObject<glm::dvec3>::set(const glm::dvec3& vec) {
    glUniform3dv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform3dv

#ifdef glUniform3iv
template<>
inline void UniformObject<glm::ivec3>::set(const glm::ivec3& vec) {
    glUniform3iv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform3iv

#ifdef glUniform3uiv
template<>
inline void UniformObject<glm::uvec3>::set(const glm::uvec3& vec) {
    glUniform3uiv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform3uiv

#ifdef glUniform4fv
template<>
inline void UniformObject<glm::vec4>::set(const glm::vec4& vec) {
    glUniform4fv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform4fv

#ifdef glUniform4dv
template<>
inline void UniformObject<glm::dvec4>::set(const glm::dvec4& vec) {
    glUniform4dv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform4dv

#ifdef glUniform4iv
template<>
inline void UniformObject<glm::ivec4>::set(const glm::ivec4& vec) {
    glUniform4iv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform4iv

#ifdef glUniform4uiv
template<>
inline void UniformObject<glm::uvec4>::set(const glm::uvec4& vec) {
    glUniform4uiv(location, 1, glm::value_ptr(vec));
};
#endif // glUniform4uiv

#ifdef glUniformMatrix2fv
template<>
inline void UniformObject<glm::mat2>::set(const glm::mat2& mat) {
    glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(mat));
};
#endif // glUniformMatrix2fv

#ifdef glUniformMatrix2dv
template<>
inline void UniformObject<glm::dmat2>::set(const glm::dmat2& mat) {
    glUniformMatrix2dv(location, 1, GL_FALSE, glm::value_ptr(mat));
};
#endif // glUniformMatrix2dv

#ifdef glUniformMatrix3fv
template<>
inline void UniformObject<glm::mat3>::set(const glm::mat3& mat) {
    glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(mat));
};
#endif // glUniformMatrix3fv

#ifdef glUniformMatrix3dv
template<>
inline void UniformObject<glm::dmat3>::set(const glm::dmat3& mat) {
    glUniformMatrix3dv(location, 1, GL_FALSE, glm::value_ptr(mat));
};
#endif // glUniformMatrix3dv

#ifdef glUniformMatrix4fv
template<>
inline void UniformObject<glm::mat4>::set(const glm::mat4& mat) {
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
};
#endif // glUniformMatrix4fv

#ifdef glUniformMatrix4dv
template<>
inline void UniformObject<glm::dmat4>::set(const glm::dmat4& mat) {
    glUniformMatrix4dv(location, 1, GL_FALSE, glm::value_ptr(mat));
};
#endif // glUniformMatrix4dv

#endif // glGetUniformLocation
} // namespace oglwrap
