/** @file shader.hpp
    @brief Implements GLSL shaders related classes.
*/

#ifndef SHADER_HPP
#define SHADER_HPP

namespace oglwrap {

// -------======{[ Shader ]}======-------

/// A specialization of the ObjectExt class for Shaders (they aren't created with glGen*)
template<ShaderType shader_t>
class ShaderObject : public RefCounted {
    /// The C handle for the object.
    GLuint *handle;
    /// The boolean for the object being initialized.
    /** It is a pointer because it is shared between the copies. If one inits
      * the handle, then all instances will have the inited handle */
    bool *inited;
public:
    /// Creates the object, but does not allocate any resource yet.
    ShaderObject()
        : handle(new GLuint)
        , inited(new bool) {

        *inited = false;
    }

    /// @brief Deletes the object.
    /** Deletes the resource if only one instance of
      * this object exists, and it is initialized. */
    ~ShaderObject() {
        if(isDeletable()) {
            if(*inited) {
                gl( DeleteShader(*handle) )
            }
            delete inited;
            delete handle;
        }
    }

    /// Allocates the resource. It only happens upon the first use.
    void init() const {
        *inited = true;
        *handle = gl( CreateShader(shader_t) );
    }

    /// Returns if there's allocated memory for this class.
    bool isInited() const {
        return *inited;
    }

    /// Returns a self-pointer, useful for inheritance
    const ShaderObject& getHandle() const {
        return *this;
    }

    /// Returns the C handle for the object. Inits it, if this is the first call for it.
    operator GLuint() const {
        if(!*inited)
            init();

        return *handle;
    }
};

template<ShaderType shader_t>
/// A GLSL shader object used to control the drawing process.
/// @see glCreateShader, glDeleteShader
class Shader {
    ShaderObject<shader_t> shader; ///< The handle for the buffer.
    bool compiled; ///< Stores if the shader is compiled.
    std::string filename;  ///< Stores the source file's name if the shader was initialized from file.
public:
    /// Creates the an empty shader object.
    Shader() : compiled(false) { }

    /// Creates a shader and sets the file as the shader source.
    /// @param file - The file to load and set as shader source.
    /// @see glCreateShader, glShaderSource
    Shader(const std::string& file)
            : compiled(false), filename(file) {
        sourceFile(file);
    }

    /// Uploads a string as the shader's source.
    /// @param source - string containing the shader code.
    /// @see glShaderSource
    void source(const std::string& source)  {
        const char *str = source.c_str();
        gl( ShaderSource(shader, 1, &str, nullptr) );
    }

    /// Loads a file and uploads it as shader source
    /// @param file - the shader file's path
    /// @see glShaderSource
    void sourceFile(const std::string& file)  {
        filename = file;
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
        if(fileData[fileData.length() - 1] == EOF)
            fileData.pop_back();

        // Add the shader source & compile
        const char *strFileData = fileData.c_str();
        gl( ShaderSource(shader, 1, &strFileData, nullptr) );
    }

    /// Compiles the shader code.
    /** If the compilation fails, it throws a std::runtime_error, containing the
      * compilation info as .what(). The compilation happens automatically
      * when the shader gets attached a program. */
    /// @see glCompileShader
    void compile()  {
        if(compiled) {
            return;
        }
        gl( CompileShader(shader) );
        compiled = true;

        // Get compilation status
        GLint status;
        gl( GetShaderiv(shader, GL_COMPILE_STATUS, &status) );
        if(status == GL_FALSE) {
            GLint infoLogLength;
            gl( GetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength) );

            GLchar *strInfoLog = new GLchar[infoLogLength + 1];
            gl( GetShaderInfoLog(shader, infoLogLength, nullptr, strInfoLog) );

            const char * strShaderType = nullptr;
            switch(shader_t) {
                #if !OGLWRAP_COREONLY
                case ShaderType::Compute:
                    strShaderType = "compute";
                    break;
                #endif
                case ShaderType::Vertex:
                    strShaderType = "vertex";
                    break;
                case ShaderType::Geometry:
                    strShaderType = "geometry";
                    break;
                case ShaderType::Fragment:
                    strShaderType = "fragment";
                    break;
                #if !OGLWRAP_COREONLY
                case ShaderType::TessControl:
                    strShaderType = "tessellation control";
                    break;
                case ShaderType::TessEval:
                    strShaderType = "tessellation evaluation";
                    break;
                #endif
            }

            std::stringstream str;
            str << "Compile failure in " << strShaderType << "shader '";
            str << filename << "' :" << std::endl << strInfoLog << std::endl;
            delete[] strInfoLog;

            throw std::runtime_error(str.str());
        }
    }

    /// Returns the C OpenGL handle for the shader.
    const ShaderObject<shader_t>& expose() const  {
        return shader;
    }
};


#if !OGLWRAP_COREONLY
/// A Shader that is used for computing arbitrary information.
/** A Compute Shader is a Shader Stage that is used entirely for computing arbitrary information.
  * While it can do rendering, it is generally used for tasks not directly related to drawing
  * triangles and pixels. */
/// @version It is core since OpenGL 4.3.
/// @see GL_COMPUTE_SHADER
typedef Shader<ShaderType::Compute> ComputeShader;
#endif

/// A Shader that handles the processing of individual vertices.
/** The Vertex Shader is the programmable Shader stage in the rendering pipeline that handles the
  * processing of individual vertices. Vertex shaders are fed Vertex Attribute data, as specified
  * from a vertex array object by a rendering command. A vertex shader receives a single vertex from
  * the vertex stream and generates a single vertex to the output vertex stream. */
/// @version It is core since OpenGL 2.1
/// @see GL_VERTEX_SHADER
typedef Shader<ShaderType::Vertex> VertexShader;

/// A Shader that governs the processing of Primitives.
/** A Geometry Shader is a Shader program written in GLSL that governs the processing of Primitives.
  * Geometry shaders reside between the Vertex Shaders (or the optional Tessellation stage) and the
  * fixed-function Vertex Post-Processing stage. A geometry shader is optional and does not have to be used. */
/// @version It is core since OpenGL 3.2
/// @see GL_GEOMETRY_SHADER
typedef Shader<ShaderType::Geometry> GeometryShader;

/// A Shader that processes a Fragment from the rasterization process into a set of colors and a single depth value.
/** A Fragment Shader is a user-supplied program that, when executed, will process a Fragment from the
  * rasterization process into a set of colors and a single depth value. The fragment shader is the OpenGL
  * pipeline stage after a primitive is rasterized. For each sample of the pixels covered by a primitive,
  * a "fragment" is generated. Each fragment has a Window Space position, a few other values, and it contains
  * all of the interpolated per-vertex output values from the last Vertex Processing stage. The output of a
  * fragment shader is a depth value, a possible stencil value (unmodified by the fragment shader), and zero
  * or more color values to be potentially written to the buffers in the current framebuffers. Fragment
  * shaders take a single fragment as input and produce a single fragment as output. */
/// @version It is core since OpenGL 2.1
/// @see GL_FRAGMENT_SHADER
typedef Shader<ShaderType::Fragment> FragmentShader;

#if !OGLWRAP_COREONLY
/// A shader that controls how much tessellation a particular patch gets and also defines the size of a patch.
/** The Tessellation Control Shader (TCS) is a Shader program written in GLSL. It sits between the Vertex
  * Shader and the Tessellation Evaluation Shader. The TCS controls how much tessellation a particular patch
  * gets; it also defines the size of a patch, thus allowing it to augment data. It can also filter vertex
  * data taken from the vertex shader. The main purpose of the TCS is to feed the tessellation levels to the
  * Tessellation primitive generator stage, as well as to feed patch data (as its output values) to the
  * Tessellation Evaluation Shader stage. */
/// @version It is core since OpenGL 4.0.
/// @see GL_TESS_CONTROL_SHADER
typedef Shader<ShaderType::TessControl> TessControlShader;

/// A shader that generates vertices from the patch data.
/** The Tessellation Evaluation Shader (TES) is a Shader program written in GLSL that takes the results
  * of a Tessellation operation and computes the interpolated positions and other per-vertex data from them.
  * These values are passed on to the next stage in the pipeline. The (TES) takes the abstract patch generated
  * by the tessellation primitive generation stage, as well as the actual vertex data for the entire patch,
  * and generates a particular vertex from it. Each TES invocation generates a single vertex. It can also take
  * per-patch data provided by the Tessellation Control Shader. */
/// @version It is core since OpenGL 4.0.
/// @see GL_TESS_EVALUATION_SHADER
typedef Shader<ShaderType::TessEval> TessEvalShader;
#endif

// -------======{[ Shader Program ]}======-------

/// A specialization of the ObjectExt class for Programs (they aren't created with glGen*)
class ProgramObject : public RefCounted {
    /// The C handle for the object.
    GLuint *handle;
    /// The boolean for the object being initialized.
    /** It is a pointer because it is shared between the copies. If one inits
      * the handle, then all instances will have the inited handle */
    bool *inited;
public:
    /// Creates the object, but does not allocate any resource yet.
    ProgramObject()
        : handle(new GLuint)
        , inited(new bool) {

        *inited = false;
    }

    /// @brief Deletes the object.
    /** Deletes the resource if only one instance of
      * this object exists, and it is initialized. */
    ~ProgramObject() {
        if(isDeletable()) {
            if(*inited) {
                gl( DeleteProgram(*handle) )
            }
            delete inited;
            delete handle;
        }
    }

    /// Allocates the resource. It only happens upon the first use.
    void init() const {
        *inited = true;
        *handle = gl( CreateProgram() );
    }

    /// Returns if there's allocated memory for this class.
    bool isInited() const {
        return *inited;
    }

    /// Returns a self-pointer, useful for inheritance
    const ProgramObject& getHandle() const {
        return *this;
    }

    /// Returns the C handle for the object. Inits it, if this is the first call for it.
    operator GLuint() const {
        if(!*inited)
            init();

        return *handle;
    }
};

/// @brief The program object can combine multiple shader stages (built from shader objects) into a single, linked whole.
/// glCreateProgram, glDeleteProgram
class Program {
    ProgramObject program; ///< The C OpenGL handle for the program.
    std::vector<GLuint> shaders; ///< IDs of the shaders attached to the program
    bool linked; ///< Stores if the program is linked.
public:
    /// Creates an empty program object.
    Program() : linked(false) {
    }

    /// @brief Detaches all the shader objects currently attached to this program, and deletes the program.
    /// @see glDetachShader, glDeleteShader
    ~Program() {
        if(program.isDeletable()) {
            for(size_t i = 0; i < shaders.size(); i++) {
                gl( DetachShader(program, shaders[i]) );
            }
        }
    }

    template<ShaderType shader_t>
    /// Attaches a shader to this program object.
    /// @param shader Specifies the shader object that is to be attached.
    /// @see glAttachShader
    void attachShader(Shader<shader_t>& shader) {
        shader.compile();
        shaders.push_back(shader.expose());
        gl( AttachShader(program, shader.expose()) );

        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "Program::AttachShader called on the same shader twice."
        );
    }

    template<ShaderType shader_t>
    /// Attaches a shader object to the program.
    /// @param shader Specifies the shader object that is to be attached.
    /// @see glAttachShader
    Program& operator<<(Shader<shader_t>& shader) {
        attachShader(shader);
        return *this;
    }

    /// Links the program.
    /** If the linking fails, it throws a std::runtime_error containing the linking info. */
    /// @see glLinkProgram
    Program& link() {
        if(linked) {
            return *this;
        }
        gl( LinkProgram(program) );
        linked = true;

        GLint status;
        gl( GetProgramiv(program, GL_LINK_STATUS, &status) );
        if(status == GL_FALSE) {
            GLint infoLogLength;
            gl( GetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength) );

            GLchar *strInfoLog = new GLchar[infoLogLength + 1];
            gl( GetProgramInfoLog(program, infoLogLength, NULL, strInfoLog) );
            std::stringstream str;
            str << "OpenGL program linker failure: " << strInfoLog << std::endl;
            delete[] strInfoLog;

            throw std::runtime_error(str.str());
        }

        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "Program::Link is called on the currently active program "
            "object, and transform feedback mode is active."
        );
        return *this;
    }

    /// Installs the program as a part of the current rendering state.
    /// @see glUseProgram
    Program& use() {
        if(!linked) {
            link();
        }
        gl( UseProgram(program) );
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "Program::Use is called, but the program could not be made "
            "part of current state. (Is transform feedback mode active?) "
        );

        return *this;
    }

    /// Installs the default OpenGL shading program to the current rendering state.
    /// @see glUseProgram
    Program& unuse() {
        gl( UseProgram(0) );
        return *this;
    }

    /// Returns the C OpenGL handle for the program.
    const ProgramObject& expose() const {
        return program;
    }
};

} // namespace oglwrap

#endif // SHADER_HPP
