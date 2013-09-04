/** @file binding.hpp
    @brief Implements enums casts to help binding checks.
*/

#pragma once

namespace oglwrap {

static std::string OGLWRAP_LAST_BIND_TARGET;

#if OGLWRAP_BINDCHECK
    /// @brief Calls the isBound() member function, and prints an error and calls bind() if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING() \
        if(!isBound()) { \
            __print_another_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
            bind(); \
        }

    /// @brief Calls the isBoundFunc function, and prints an error and calls bindFunc if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING_EXPLICIT(isBoundFunc, bindFunc) \
        if(!isBoundFunc()) { \
            __print_another_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
            bindFunc(); \
        }

    /// Checks if the object name '0' is bound to the given target, and prints error if it is.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    /// @param bindTarget - The target to check. Expected to be a value returned by getBindingTarget();
    #define CHECK_FOR_DEFAULT_BINDING(bindTarget) \
        GLint __currently_bound_target; \
        glGetIntegerv(bindTarget, &__currently_bound_target); \
        if(__currently_bound_target == 0) \
            __print_default_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__);

    /// @brief Checks if the object name '0' is bound to the target explicitly given by its name, and prints error if it is.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    /// @param bindTarget - The target to check. Expected to be an explicit OpenGL macro name.
    #define CHECK_FOR_DEFAULT_BINDING_EXPLICIT(bindTarget) \
        OGLWRAP_LAST_BIND_TARGET = #bindTarget; \
        GLint __currently_bound_target; \
        glGetIntegerv(bindTarget, &__currently_bound_target); \
        if(__currently_bound_target == 0) \
            __print_default_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__);
#else
    /// @brief Calls the isBound() member function, and prints error if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING()

    /// @brief Calls the isBoundFunc function, and prints an error and calls bindFunc if it returns false.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    #define CHECK_BINDING_EXPLICIT(isBoundFunc, bindFunc)

    /// Checks if the object name '0' is bound to the given target, and prints error if it is.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    /// @param bindTarget - The target to check. Expected to be a value returned by getBindingTarget();
    #define CHECK_FOR_DEFAULT_BINDING(bindTarget)

    /// @brief Checks if the object name '0' is bound to the target explicitly given by its name, and prints error if it is.
    /** Only if OGLWRAP_BINDCHECK is defined true */
    /// @param bindTarget - The target to check. Expected to be an explicit OpenGL macro name.
    #define CHECK_FOR_DEFAULT_BINDING_EXPLICIT(bindTarget)
#endif

/// A function used by CHECK_FOR_DEFAULT_BINDING() macro
inline void __print_another_object_is_bound_error(const char *file, const char *func, int line) {
    std::cerr << "\n---------========={[ BIND CHECK FAILURE ]}=========---------\n" << std::endl;
    std::cerr << "In function: " << cut_end_of_pretty_func(func) << std::endl;
    std::cerr << "In '" << file << "' at line " << line << "\n\n";
    std::cerr << "The function is called through an object that is different ";
    std::cerr << "than the one, currently bound to " << OGLWRAP_LAST_BIND_TARGET << ".\n";
    std::cerr << "Did you forget to call .bind()? \n\n";
    for(size_t i = 0; i < strlen("---------========={[ BIND CHECK FAILURE ]}=========---------"); i++)
        std::cerr << '-';
    std::cerr << std::endl;
}

/// A function used by CHECK_FOR_DEFAULT_BINDING_EXPLICIT() macro
inline void __print_default_object_is_bound_error(const char *file, const char *func, int line) {
    std::cerr << "\n---------========={[ BIND CHECK FAILURE ]}=========---------\n" << std::endl;
    std::cerr << "In function: " << cut_end_of_pretty_func(func) << std::endl;
    std::cerr << "In '" << file << "' at line " << line << "\n\n";
    std::cerr << "The function requires an object to be bound to " << OGLWRAP_LAST_BIND_TARGET;
    std::cerr << " but only the default object '0' is bound to that target.\n\n";
    for(size_t i = 0; i < strlen("---------========={[ BIND CHECK FAILURE ]}=========---------"); i++)
        std::cerr << '-';
    std::cerr << std::endl;
}

/// Returns the buffer binding point's GLenum for the given buffer target.
/// @param buffer_t - The buffer target.
inline BufferBinding getBindingTarget(BufferType buffer_t) {
    BufferBinding target;

    switch(buffer_t) {
        #ifdef GL_ARRAY_BUFFER_BINDING
        case BufferType::Array:
            target = BufferBinding::Array;
            OGLWRAP_LAST_BIND_TARGET = "GL_ARRAY_BUFFER_BINDING";
            break;
        #endif
        #ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
        case BufferType::AtomicCounter:
            target = BufferBinding::AtomicCounter;
            OGLWRAP_LAST_BIND_TARGET = "GL_ATOMIC_COUNTER_BUFFER_BINDING";
            break;
        #endif

        // Note: these two do not end with _BINDING
        #ifdef GL_COPY_READ_BUFFER
        case BufferType::CopyRead:
            target = BufferBinding::CopyRead;
            OGLWRAP_LAST_BIND_TARGET = "GL_COPY_READ_BUFFER";
            break;
        #endif
        #ifdef GL_COPY_WRITE_BUFFER
        case BufferType::CopyWrite:
            target = BufferBinding::CopyWrite;
            OGLWRAP_LAST_BIND_TARGET = "GL_COPY_WRITE_BUFFER";
            break;
        #endif

        #ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
        case BufferType::DispatchIndirect:
            target = BufferBinding::DispatchIndirect;
            OGLWRAP_LAST_BIND_TARGET = "GL_DISPATCH_INDIRECT_BUFFER_BINDING";
            break;
        #endif
        #ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
        case BufferType::DrawIndirect:
            target = BufferBinding::DrawIndirect;
            OGLWRAP_LAST_BIND_TARGET = "GL_DRAW_INDIRECT_BUFFER_BINDING";
            break;
        #endif
        #ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
        case BufferType::ElementArray:
            target = BufferBinding::ElementArray;
            OGLWRAP_LAST_BIND_TARGET = "GL_ELEMENT_ARRAY_BUFFER_BINDING";
            break;
        #endif
        #ifdef GL_PIXEL_PACK_BUFFER_BINDING
        case BufferType::PixelPack:
            target = BufferBinding::PixelPack;
            OGLWRAP_LAST_BIND_TARGET = "GL_PIXEL_PACK_BUFFER_BINDING";
            break;
        #endif
        #ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
        case BufferType::PixelUnpack:
            target = BufferBinding::PixelUnpack;
            OGLWRAP_LAST_BIND_TARGET = "GL_PIXEL_UNPACK_BUFFER_BINDING";
            break;
        #endif
        #ifdef GL_SHADER_STORAGE_BUFFER_BINDING
        case BufferType::ShaderStorage:
            target = BufferBinding::ShaderStorage;
            OGLWRAP_LAST_BIND_TARGET = "GL_SHADER_STORAGE_BUFFER_BINDING";
            break;
        #endif
        // Note: It's not BUFFER_BINDING but BINDING_BUFFER.
        #ifdef GL_TEXTURE_BINDING_BUFFER
        case BufferType::Texture:
            target = BufferBinding::Texture;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_BUFFER";
            break;
        #endif
        #ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
        case BufferType::TransformFeedback:
            target = BufferBinding::TransformFeedback;
            OGLWRAP_LAST_BIND_TARGET = "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
            break;
        #endif
        #ifdef GL_UNIFORM_BUFFER_BINDING
        case BufferType::Uniform:
            target = BufferBinding::Uniform;
            OGLWRAP_LAST_BIND_TARGET = "GL_UNIFORM_BUFFER_BINDING";
            break;
        #endif
    }

    return target;
}

/// Returns the framebuffer binding point's GLenum for the given framebuffer target.
/// @param buffer_t - The buffer target.
inline FramebufferBinding getBindingTarget(FramebufferType fbo_t) {
    FramebufferBinding target;

    switch(fbo_t) {
        #ifdef GL_READ_FRAMEBUFFER_BINDING
        case FramebufferType::Read:
            target = FramebufferBinding::Read;
            OGLWRAP_LAST_BIND_TARGET = "GL_READ_FRAMEBUFFER_BINDING";
            break;
        #endif
        #ifdef GL_DRAW_FRAMEBUFFER_BINDING
        case FramebufferType::Draw:
            target = FramebufferBinding::Draw;
            OGLWRAP_LAST_BIND_TARGET = "GL_DRAW_FRAMEBUFFER_BINDING";
            break;
        #endif
        #ifdef GL_FRAMEBUFFER_BINDING
        case FramebufferType::Read_Draw:
            target = FramebufferBinding::Read_Draw;
            OGLWRAP_LAST_BIND_TARGET = "GL_FRAMEBUFFER_BINDING";
            break;
        #endif
    }

    return target;
}


/// Returns the texture binding point's GLenum for the given texture target.
/// @param buffer_t - The buffer target.
inline TexBinding getBindingTarget(TexType fbo_t) {
    TexBinding target;

    switch(fbo_t) {
        #ifdef GL_TEXTURE_BINDING_1D
        case TexType::Tex1D:
            target = TexBinding::Tex1D;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_1D";
            break;
        #endif
        #ifdef GL_TEXTURE_BINDING_2D
        case TexType::Tex2D:
            target = TexBinding::Tex2D;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_2D";
            break;
        #endif
        #ifdef GL_TEXTURE_BINDING_3D
        case TexType::Tex3D:
            target = TexBinding::Tex3D;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_3D";
            break;
        #endif
        #ifdef GL_TEXTURE_BINDING_RECTANGLE
        case TexType::TexRect:
            target = TexBinding::TexRect;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_RECTANGLE";
            break;
        #endif
        #ifdef GL_TEXTURE_BINDING_1D_ARRAY
        case TexType::Tex1DArray:
            target = TexBinding::Tex1DArray;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_1D_ARRAY";
            break;
        #endif
        #ifdef GL_TEXTURE_BINDING_2D_ARRAY
        case TexType::Tex2DArray:
            target = TexBinding::Tex2DArray;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_2D_ARRAY";
            break;
        #endif
        #ifdef GL_TEXTURE_BINDING_CUBE_MAP
        case TexType::TexCubeMap:
            target = TexBinding::TexCubeMap;
            OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_CUBE_MAP";
            break;
        #endif
    }

    return target;
}

} // namespace oglwarp
