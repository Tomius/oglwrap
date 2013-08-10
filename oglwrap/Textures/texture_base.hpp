#ifndef TEXUTRE_BASE_HPP
#define TEXTURE_BASE_HPP

#pragma once

#include <string>
#include <GL/glew.h>

#include "../error.hpp"
#include "../enums.hpp"
#include "../general.hpp"

#ifndef OGLWRAP_IMAGEMAGICK
#define OGLWRAP_IMAGEMAGICK 0
#endif

#if OGLWRAP_IMAGEMAGICK
#include <ImageMagick/Magick++.h>
#endif

namespace oglwrap {

// -------======{[ TextureBase declaration ]}======-------

template <TexType texture_t>
/// It's a class implementing the base functions for textures.
/// You shouldn't use this class directly.
class TextureBase : protected RefCounted {
protected:
    GLuint texture; ///< The C handle for the texture.
public:
    /// Generates an empty texture.
    /// @see glGenTextures
    TextureBase() {
        glGenTextures(1, &texture);
        oglwrap_CheckError();
    }

    /// If only one instance of this object exists, deletes the texture.
    /// @see glDeleteTextures
    ~TextureBase() {
        if(!isDeletable())
            return;
        glDeleteTextures(1, &texture);
        oglwrap_CheckError();
    }

    /// Binds the texture to this texture class's target.
    /// @see glBindTexture
    void Bind() {
        glBindTexture(texture_t, texture);
        oglwrap_CheckError();
    }

    /// Unbinds the texture from this texture class's target.
    /// @see glBindTexture
    static void Unbind() {
        glBindTexture(texture_t, 0);
        oglwrap_CheckError();
    }

    /// Sets a specific texture unit to be the active texUnit.
    /// @param texUnit - The ID of the texture unit as an integer. Tex unit 1 is simply 1, not GL_TEXTURE0 + 1.
    /// @see glActiveTexture
    static void Active(GLuint texUnit) {
        glActiveTexture(GL_TEXTURE0 + texUnit);
        oglwrap_CheckError();
    }

    /// Generates mipmaps for the currently uploaded image to this texture class.
    /// @see glGenerateMipmap
    static void GenerateMipmap() {
        glGenerateMipmap(texture_t);
        oglwrap_CheckError();
    }

    /// Sets the border color for this texture class.
    /// @param color - Specifies the value, the border color should be set to.
    /// @see glTexParameterfv, GL_TEXTURE_BORDER_COLOR
    static void BorderColor(glm::vec4 color) {
        glTexParameterfv(texture_t, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color));
        oglwrap_CheckError();
    }

    /// Sets the minification filter for this texture class.
    /// @param filtermode - The desired minification filter mode.
    /// @see glTexParameteri, GL_TEXTURE_MIN_FILTER
    static void MinFilter(MinF filtermode) {
        glTexParameteri(texture_t, GL_TEXTURE_MIN_FILTER, filtermode);
        oglwrap_CheckError();
    }

    /// Sets the magnification filter for this texture class.
    /// @param filtermode - The desired magnification filter mode.
    /// @see glTexParameteri, GL_TEXTURE_MAG_FILTER
    static void MagFilter(MagF filtermode){
        glTexParameteri(texture_t, GL_TEXTURE_MAG_FILTER, filtermode);
        oglwrap_CheckError();
    }

    /// Sets the way, OpenGL should handle if the texture coordinate's
    /// 's' (first) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_S
    static void WrapS(Wrap wrapmode) {
        glTexParameteri(texture_t, GL_TEXTURE_WRAP_S, wrapmode);
        oglwrap_CheckError();
    }

    /// Sets the way, OpenGL should handle if the texture coordinate's
    /// 't' (second) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_T
    static void WrapT(Wrap wrapmode) {
        glTexParameteri(texture_t, GL_TEXTURE_WRAP_T, wrapmode);
        oglwrap_CheckError();
    }

    /// Sets the way, OpenGL should handle if the texture coordinate's
    /// 'p' (third) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_R
    static void WrapR(Wrap wrapmode) {
        glTexParameteri(texture_t, GL_TEXTURE_WRAP_R, wrapmode);
        oglwrap_CheckError();
    }

    /// Sets what OpenGL should do if you write texture.r
    /// for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_R
    static void SwizzleR(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_R, swizzlemode);
        oglwrap_CheckError();
    }

    /// Sets what OpenGL should do if you write texture.g
    /// for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_G
    static void SwizzleG(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_G, swizzlemode);
        oglwrap_CheckError();
    }

    /// Sets what OpenGL should do if you write texture.b
    /// for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_B
    static void SwizzleB(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_B, swizzlemode);
        oglwrap_CheckError();
    }

    /// Sets what OpenGL should do if you write texture.a
    /// for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_A
    static void SwizzleA(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_A, swizzlemode);
        oglwrap_CheckError();
    }

    /// Sets what OpenGL should do if you use the swizzle operator to
    /// select either of the 4 components from a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_RGBA
    static void SwizzleRGBA(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_RGBA, swizzlemode);
        oglwrap_CheckError();
    }

    /// Sets the anisotropy extension to a desired value.
    /// @param value - The desired anisotropy value.
    /// @see glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT
    static void Anisotropy(float value) {
        glTexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, value);
        oglwrap_CheckError();
    }

    /// Sets the anisotropy extension to the maximum value possible on this hardware.
    /// @see glGetFloatv, glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT
    static void MaxAnisotropy() {
        GLfloat maxAniso = 0.0f;
        glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAniso);
        glTexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAniso);
        oglwrap_CheckError();
    }

    /// Assigns a buffer storing the texel data to the texture.
    /// @param internalFormat - Specifies the internal format of the data in the store belonging to buffer. It must be a sized, uncompressed internal format.
    /// @param buffer - Specifies the name of the buffer object whose storage to attach to the active buffer texture.
    static void Buffer(PixelDataInternalFormat internalFormat, const TextureBuffer& buffer) {
        glTexBuffer(texture_t, internalFormat, buffer.Expose());
        oglwrap_CheckError();
    }
};

} // namespace oglwrap

#endif // TEXUTRE_BASE
