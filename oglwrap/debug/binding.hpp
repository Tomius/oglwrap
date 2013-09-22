/** @file binding.hpp
    @brief Implements enums casts to help binding checks.
*/

#pragma once

namespace oglwrap {

static std::string OGLWRAP_LAST_BIND_TARGET;

#if OGLWRAP_BINDCHECK
    /// Calls the isBound() member function, and prints an error and calls bind() if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING() \
        if(!isBound()) { \
            __print_another_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
            bind(); \
        }

    /// Calls the isBound() member function, and prints an error if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING2() \
        if(!isBound()) { \
            __print_another_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
        }

    /// Calls the isBoundFunc function, and prints an error and calls bindFunc if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING_EXPLICIT(isBoundFunc, bindFunc) \
        if(!isBoundFunc) { \
            __print_another_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
            bindFunc; \
        }

    /// Calls the isBoundFunc function, and prints an error if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING2_EXPLICIT(isBoundFunc) \
        if(!isBoundFunc) { \
            __print_another_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
        }

    /// Checks if the object name '0' is bound to the given target, and prints error if it is.
    /** Only if OGLWRAP_BINDCHECK is defined true
      * @param bindTarget - The target to check. Expected to be a value returned by getBindingTarget(); */
    #define CHECK_FOR_DEFAULT_BINDING(bindTarget) \
        GLint __currently_bound_target; \
        glGetIntegerv(bindTarget, &__currently_bound_target); \
        if(__currently_bound_target == 0) \
            __print_default_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__);

    /// Checks if the object name '0' is bound to the target explicitly given by its name, and prints error if it is.
    /** Only if OGLWRAP_BINDCHECK is defined true
      * @param bindTarget - The target to check. Expected to be an explicit OpenGL macro name. */
    #define CHECK_FOR_DEFAULT_BINDING_EXPLICIT(bindTarget) \
        OGLWRAP_LAST_BIND_TARGET = #bindTarget; \
        GLint __currently_bound_target_for_##bindTarget; \
        glGetIntegerv(bindTarget, &__currently_bound_target_for_##bindTarget); \
        if(__currently_bound_target_for_##bindTarget == 0) \
            __print_default_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__);

    /// A function used by CHECK_FOR_DEFAULT_BINDING() macro
    inline void __print_another_object_is_bound_error(const char *file, const char *func, int line) {
        std::stringstream sstream;
        sstream << "\n---------========={[ BIND CHECK FAILURE ]}=========---------\n" << std::endl;
        sstream << "In function: " << cut_end_of_pretty_func(func) << std::endl;
        sstream << "In '" << file << "' at line " << line << "\n\n";
        sstream << "The function is called through an object that is different ";
        sstream << "than the one, currently bound to " << OGLWRAP_LAST_BIND_TARGET << ".\n";
        sstream << "Did you forget to call .bind() on the object? \n\n";
        for(size_t i = 0; i < strlen("---------========={[ BIND CHECK FAILURE ]}=========---------"); i++)
            sstream << '-';
        sstream << std::endl;

        debug_output.callback(sstream.str());
    }

    /// A function used by CHECK_FOR_DEFAULT_BINDING_EXPLICIT() macro
    inline void __print_default_object_is_bound_error(const char *file, const char *func, int line) {
        std::stringstream sstream;
        sstream << "\n---------========={[ BIND CHECK FAILURE ]}=========---------\n" << std::endl;
        sstream << "In function: " << cut_end_of_pretty_func(func) << std::endl;
        sstream << "In '" << file << "' at line " << line << "\n\n";
        sstream << "The function requires an object to be bound to " << OGLWRAP_LAST_BIND_TARGET;
        sstream << " but only the default object '0' is bound to that target.\n\n";
        for(size_t i = 0; i < strlen("---------========={[ BIND CHECK FAILURE ]}=========---------"); i++)
            sstream << '-';
        sstream << std::endl;

        debug_output.callback(sstream.str());
    }

    /// Checks if the program is the currently active one, and if not, it returns prints out an error, and calls use on that program.
    /** @param program - The shader program to check if is active. */
    #define CHECK_ACTIVE_PROGRAM(program) \
        if(!program.isActive()) { \
            __print_another_program_is_active_error(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
            program.use(); \
        }

    /// A function used by the CHECK_ACTIVE_PROGRAM() macro
    inline void __print_another_program_is_active_error(const char *file, const char *func, int line) {
        std::stringstream sstream;
        sstream << "\n---------========={[ ACTIVE PROGRAM CHECK FAILURE ]}=========---------\n" << std::endl;
        sstream << "In function: " << cut_end_of_pretty_func(func) << std::endl;
        sstream << "In '" << file << "' at line " << line << "\n\n";
        sstream << "The currently active program is different than "
                  << "the one, this function is supposed to operate on.\n";
        sstream << "Did you forget to call .use() on the program? \n\n";
        for(size_t i = 0; i < strlen("---------========={[ ACTIVE PROGRAM CHECK FAILURE ]}=========---------"); i++)
            sstream << '-';
        sstream << std::endl;

        debug_output.callback(sstream.str());
    }
#else
    /// Calls the isBound() member function, and prints an error, and binds it, if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING()

    /// Calls the isBound() member function, and prints an error if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING2()

    /// Calls the isBoundFunc function, and prints an error, and calls bindFunc, if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING_EXPLICIT(isBoundFunc, bindFunc)

    /// Calls the isBoundFunc function, and prints an error if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING2_EXPLICIT(isBoundFunc)

    /// Checks if the object name '0' is bound to the given target, and prints error if it is.
    /** Only if OGLWRAP_BINDCHECK is defined true
      * @param bindTarget - The target to check. Expected to be a value returned by getBindingTarget(); */
    #define CHECK_FOR_DEFAULT_BINDING(bindTarget)

    /// Checks if the object name '0' is bound to the target explicitly given by its name, and prints error if it is.
    /** Only if OGLWRAP_BINDCHECK is defined true
      * @param bindTarget - The target to check. Expected to be an explicit OpenGL macro name. */
    #define CHECK_FOR_DEFAULT_BINDING_EXPLICIT(bindTarget)

    /// Checks if the program is the currently active one, and if not, it prints out an error, and calls use() on that program.
    /** Only if OGLWRAP_BINDCHECK is defined true
      * @param program - The shader program to check if is active. */
    #define CHECK_ACTIVE_PROGRAM(program)
#endif

/// Returns the buffer binding point's GLenum for the given buffer target.
/** @param buffer_t - The buffer target. */
inline BufferBinding getBindingTarget(BufferType buffer_t) {
    BufferBinding target;

    switch(buffer_t) {
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ARRAY_BUFFER_BINDING)
        case BufferType::Array:
            target = BufferBinding::Array;
            OGLWRAP_LAST_BIND_TARGET = "GL_ARRAY_BUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
        case BufferType::AtomicCounter:
            target = BufferBinding::AtomicCounter;
            OGLWRAP_LAST_BIND_TARGET = "GL_ATOMIC_COUNTER_BUFFER_BINDING";
            break;
        #endif

        // Note: these two do not end with _BINDING
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COPY_READ_BUFFER)
        case BufferType::CopyRead:
            target = BufferBinding::CopyRead;
            OGLWRAP_LAST_BIND_TARGET = "GL_COPY_READ_BUFFER";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COPY_WRITE_BUFFER)
        case BufferType::CopyWrite:
            target = BufferBinding::CopyWrite;
            OGLWRAP_LAST_BIND_TARGET = "GL_COPY_WRITE_BUFFER";
            break;
        #endif

        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DISPATCH_INDIRECT_BUFFER_BINDING)
        case BufferType::DispatchIndirect:
            target = BufferBinding::DispatchIndirect;
            OGLWRAP_LAST_BIND_TARGET = "GL_DISPATCH_INDIRECT_BUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DRAW_INDIRECT_BUFFER_BINDING)
        case BufferType::DrawIndirect:
            target = BufferBinding::DrawIndirect;
            OGLWRAP_LAST_BIND_TARGET = "GL_DRAW_INDIRECT_BUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ELEMENT_ARRAY_BUFFER_BINDING)
        case BufferType::ElementArray:
            target = BufferBinding::ElementArray;
            OGLWRAP_LAST_BIND_TARGET = "GL_ELEMENT_ARRAY_BUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_PIXEL_PACK_BUFFER_BINDING)
        case BufferType::PixelPack:
            target = BufferBinding::PixelPack;
            OGLWRAP_LAST_BIND_TARGET = "GL_PIXEL_PACK_BUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_PIXEL_UNPACK_BUFFER_BINDING)
        case BufferType::PixelUnpack:
            target = BufferBinding::PixelUnpack;
            OGLWRAP_LAST_BIND_TARGET = "GL_PIXEL_UNPACK_BUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
        case BufferType::ShaderStorage:
            target = BufferBinding::ShaderStorage;
            OGLWRAP_LAST_BIND_TARGET = "GL_SHADER_STORAGE_BUFFER_BINDING";
            break;
        #endif
        // Note: It's not BUFFER_BINDING but BINDING_BUFFER.
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_BUFFER)
        case BufferType::Texture:
            target = BufferBinding::Texture;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_BUFFER";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
        case BufferType::TransformFeedback:
            target = BufferBinding::TransformFeedback;
            OGLWRAP_LAST_BIND_TARGET = "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNIFORM_BUFFER_BINDING)
        case BufferType::Uniform:
            target = BufferBinding::Uniform;
            OGLWRAP_LAST_BIND_TARGET = "GL_UNIFORM_BUFFER_BINDING";
            break;
        #endif
        default:
            abort();
    }

    return target;
}

/// Returns the indexed buffer binding point's GLenum for the given buffer target.
/** @param buffer_t - The buffer target. */
inline IndexedBufferBinding getBindingTarget(IndexedBufferType buffer_t) {
    IndexedBufferBinding target;

    switch(buffer_t) {
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
        case IndexedBufferType::AtomicCounter:
            target = IndexedBufferBinding::AtomicCounter;
            OGLWRAP_LAST_BIND_TARGET = "GL_ATOMIC_COUNTER_BUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
        case IndexedBufferType::ShaderStorage:
            target = IndexedBufferBinding::ShaderStorage;
            OGLWRAP_LAST_BIND_TARGET = "GL_SHADER_STORAGE_BUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
        case IndexedBufferType::TransformFeedback:
            target = IndexedBufferBinding::TransformFeedback;
            OGLWRAP_LAST_BIND_TARGET = "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNIFORM_BUFFER_BINDING)
        case IndexedBufferType::Uniform:
            target = IndexedBufferBinding::Uniform;
            OGLWRAP_LAST_BIND_TARGET = "GL_UNIFORM_BUFFER_BINDING";
            break;
        #endif
        default:
            abort();
    }

    return target;
}

/// Returns the framebuffer binding point's GLenum for the given framebuffer target.
/** @param fbo_t - The framebuffer target. */
inline FramebufferBinding getBindingTarget(FramebufferType fbo_t) {
    FramebufferBinding target;

    switch(fbo_t) {
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_READ_FRAMEBUFFER_BINDING)
        case FramebufferType::Read:
            target = FramebufferBinding::Read;
            OGLWRAP_LAST_BIND_TARGET = "GL_READ_FRAMEBUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DRAW_FRAMEBUFFER_BINDING)
        case FramebufferType::Draw:
            target = FramebufferBinding::Draw;
            OGLWRAP_LAST_BIND_TARGET = "GL_DRAW_FRAMEBUFFER_BINDING";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER_BINDING)
        case FramebufferType::Read_Draw:
            target = FramebufferBinding::Read_Draw;
            OGLWRAP_LAST_BIND_TARGET = "GL_FRAMEBUFFER_BINDING";
            break;
        #endif
        default:
            abort();
    }

    return target;
}


/// Returns the texture binding point's GLenum for the given texture target.
/** @param tex_t - The texture target.*/
inline TexBinding getBindingTarget(TexType tex_t) {
    TexBinding target;

    switch(tex_t) {
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_1D)
        case TexType::Tex1D:
            target = TexBinding::Tex1D;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_1D";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_2D)
        case TexType::Tex2D:
            target = TexBinding::Tex2D;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_2D";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_3D)
        case TexType::Tex3D:
            target = TexBinding::Tex3D;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_3D";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_RECTANGLE)
        case TexType::TexRect:
            target = TexBinding::TexRect;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_RECTANGLE";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_1D_ARRAY)
        case TexType::Tex1DArray:
            target = TexBinding::Tex1DArray;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_1D_ARRAY";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_2D_ARRAY)
        case TexType::Tex2DArray:
            target = TexBinding::Tex2DArray;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_2D_ARRAY";
            break;
        #endif
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_CUBE_MAP)
        case TexType::TexCubeMap:
            target = TexBinding::TexCubeMap;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_CUBE_MAP";
            break;
        #endif
        default:
            abort();
    }

    return target;
}

} // namespace oglwarp

