/** @file shader.hpp
    @brief Implements GLSL shaders related classes.
*/

#pragma once

namespace oglwrap {

// -------======{[ ShaderStorage ]}======-------

/// A class that can load shader sources in from files, and do some preprocessing on them
class ShaderSource {
    std::string src; /// The source
    std::string filename; /// The file's name stored to make debugging easier.
public:
    /// Default constructor.
    ShaderSource() : filename("Unnamed shader") { }

    /// Loads in the shader from a file.
    /** @param file - The path to the file. */
    ShaderSource(const std::string& file) {
        source_file(file);
    }

    /// Adds a string as the shader source.
    /** @param source_string - The source string. */
    void source(const std::string& source_string) {
        src = source_string;
    }

    /// Loads in the shader from a file.
    /** @param file - The path to the file. */
    void source_file(const std::string& file) {
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
        src = shaderString.str();
        if(src[src.length() - 1] == EOF)
            src.pop_back();
    }

    template<typename T>
    /// Inserts a value for a defined preprocessor in the shader.
    /** @param macro_name - The name of the macro.
      * @param value - The value to insert. */
    void insert_macro_value(const std::string& macro_name, const T& value) {
        size_t macro_pos = src.find("#define " + macro_name);
        if(macro_pos == std::string::npos) {
            throw std::invalid_argument(
                "ShaderSource::insert_macro_value is called for '" + filename +
                "', but the shader doesn't have any macro named " + macro_name
            );
        }

        size_t macro_end = src.find('\n', macro_pos);

        std::stringstream sstream;
        sstream << src.substr(0, macro_pos + strlen("#define ") + macro_name.length());
        sstream << ' ' << value << src.substr(macro_end);
        src = sstream.str();
    }

    /// Returns the file's name that was loaded in.
    std::string const& get_file_name() const {
        return filename;
    }

    /// Returns the source.
    std::string const& get_source() const {
        return src;
    }
};

// -------======{[ ShaderObject ]}======-------

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glCreateShader) && defined(glDeleteShader))
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

// -------======{[ Shader ]}======-------

template<ShaderType shader_t>
/// A GLSL shader object used to control the drawing process.
/** @see glCreateShader, glDeleteShader */
class Shader {
    ShaderObject<shader_t> shader; ///< The handle for the buffer.
    bool compiled; ///< Stores if the shader is compiled.
    std::string filename;  ///< Stores the source file's name if the shader was initialized from file.
public:
    /// Creates the an empty shader object.
    Shader() : compiled(false) { }

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glShaderSource)
    /// Creates a shader and sets the file as the shader source.
    /** @param file - The file to load and set as shader source.
      * @see glShaderSource */
    Shader(const std::string& file)
            : compiled(false), filename(file) {
        sourceFile(file);
    }
    #endif // glShaderSource

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glShaderSource)
    /// Uploads a string as the shader's source.
    /** @param source - string containing the shader code.
      * @see glShaderSource */
    void source(const std::string& source)  {
        const char *str = source.c_str();
        gl( ShaderSource(shader, 1, &str, nullptr) );
    }
    #endif // glShaderSource

        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glShaderSource)
    /// Uploads a ShaderSource as the shader's source.
    /** @param source - string containing the shader code.
      * @see glShaderSource */
    void source(const ShaderSource& source)  {
        const char *str = source.get_source().c_str();
        filename = source.get_file_name();
        gl( ShaderSource(shader, 1, &str, nullptr) );
    }
    #endif // glShaderSource

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glShaderSource)
    /// Loads a file and uploads it as shader source
    /** @param file - the shader file's path
      * @see glShaderSource */
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
    #endif // glShaderSource

    #if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glCompileShader) && defined(glGetShaderiv) && defined(glGetShaderInfoLog))
    /// Compiles the shader code.
    /** If the compilation fails, it throws a std::runtime_error, containing the
      * compilation info as .what(). The compilation happens automatically
      * when the shader gets attached a program.
      * @see glCompileShader, glGetShaderiv, glGetShaderInfoLog */
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
            str << filename << "' :" << std::endl << strInfoLog << std::endl;
            delete[] strInfoLog;

            throw std::runtime_error(str.str());
        }
    }
    #endif // glCompileShader && glGetShaderInfoLog && glGetShaderiv

    /// Returns the C OpenGL handle for the shader.
    const ShaderObject<shader_t>& expose() const  {
        return shader;
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
#endif // GL_VERTEX_SHADER

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_GEOMETRY_SHADER)
/// A Shader that governs the processing of Primitives.
/** A Geometry Shader is a Shader program written in GLSL that governs the processing of Primitives.
  * Geometry shaders reside between the Vertex Shaders (or the optional Tessellation stage) and the
  * fixed-function Vertex Post-Processing stage. A geometry shader is optional and does not have to be used.
  * @version It is core since OpenGL 3.2
  * @see GL_GEOMETRY_SHADER */
typedef Shader<ShaderType::Geometry> GeometryShader;
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
#endif // GL_TESS_EVALUATION_SHADER

#endif // glCreateShader && glDeleteShader

// -------======{[ Shader Program ]}======-------

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glCreateProgram) && defined(glDeleteProgram))
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

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDetachShader)
/// The program object can combine multiple shader stages (built from shader objects) into a single, linked whole.
/** @see glCreateProgram, glDeleteProgram */
class Program {
    ProgramObject program; ///< The C OpenGL handle for the program.
    std::vector<GLuint> shaders; ///< IDs of the shaders attached to the program
    bool *linked; ///< Stores if the program is linked. Its a pointer, so .use() can be const.
public:
    /// Creates an empty program object.
    Program() : linked(new bool) {
        *linked = false;
    }

    /// Detaches all the shader objects currently attached to this program, and deletes the program.
    /** @see glDetachShader, glDeleteShader */
    ~Program() {
        if(program.isDeletable()) {
            for(size_t i = 0; i < shaders.size(); i++) {
                gl( DetachShader(program, shaders[i]) );
            }
            delete linked;
        }
    }

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glAttachShader)
    template<ShaderType shader_t>
    /// Attaches a shader to this program object.
    /** @param shader Specifies the shader object that is to be attached.
      * @see glAttachShader */
    void attachShader(Shader<shader_t>& shader) {
        shader.compile();
        shaders.push_back(shader.expose());
        gl( AttachShader(program, shader.expose()) );
    }
    #endif // glAttachShader

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

    #if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glLinkProgram) && defined(glGetProgramiv) && defined(glGetProgramInfoLog))
    /// Links the program.
    /** If the linking fails, it throws a std::runtime_error containing the linking info.
      * @see glLinkProgram, glGetProgramiv, glGetProgramInfoLog */
    const Program& link() const {
        gl( LinkProgram(program) );
        *linked = true;

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

        return *this;
    }
    #endif // glLinkProgram && glGetProgramiv && glGetProgramInfoLog

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUseProgram)
    /// Installs the program as a part of the current rendering state.
    /** @see glUseProgram */
    const Program& use() const {
        if(!*linked) {
            link();
        }
        gl( UseProgram(program) );
        return *this;
    }
    #endif

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUseProgram)
    /// Installs the default OpenGL shading program to the current rendering state.
    /** @see glUseProgram */
    static void Unuse() {
        gl( UseProgram(0) );
    }
    #endif

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glUseProgram)
    /// Installs the default OpenGL shading program to the current rendering state.
    /** @see glUseProgram */
    void unuse() const {
        Unuse();
    }
    #endif

    /// Returns if this program is the currently active one.
    /** @see glGetIntegerv */
    bool isActive() const {
        GLint currentProgram;
        gl( GetIntegerv(GL_CURRENT_PROGRAM, &currentProgram) );
        return program == GLuint(currentProgram);
    }

    /// Returns the C OpenGL handle for the program.
    const ProgramObject& expose() const {
        return program;
    }
};
#endif // glDetachShader
#endif // glCreateProgram && glDeleteProgram

} // namespace oglwrap

