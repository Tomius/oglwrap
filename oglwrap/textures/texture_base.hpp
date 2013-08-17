/** @file texture_base.hpp
    @brief Implements the base functionality for textures.
*/

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
/// @brief This class is implementing the base functions for textures.
/** You shouldn't use this class directly. **/
class TextureBase : public RefCounted {
protected:
    GLuint texture; ///< The C handle for the texture.
public:
    /// Generates an empty texture.
    /// @see glGenTextures
    TextureBase() {
        oglwrap_PreCheckError();

        glGenTextures(1, &texture);
    }

    template <TexType another_texture_t>
    /// Creates a copy from an already existing texture. Can also change it's default target.
    /** You can use it to cast for example Texture2D to TextureRect. */
    TextureBase(const TextureBase<another_texture_t>& srctexture)
        : RefCounted(srctexture)
        , texture(srctexture.Expose()) {
        oglwrap_PreCheckError();
    }

    /// If only one instance of this object exists, deletes the texture.
    /// @see glDeleteTextures
    ~TextureBase() {
        oglwrap_PreCheckError();

        if(!isDeletable()) {
            return;
        }
        glDeleteTextures(1, &texture);
    }

    /// Binds the texture to this texture class's target.
    /// @see glBindTexture
    void Bind() {
        oglwrap_PreCheckError();

        glBindTexture(texture_t, texture);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_OPERATION
            "TextureBase::Bind is called, but the texture was previously created "
            "for another target, and can not be bound for this target."
        );
    }

    /// Unbinds the texture from this texture class's target.
    /// @see glBindTexture
    static void Unbind() {
        oglwrap_PreCheckError();

        glBindTexture(texture_t, 0);
    }

    /// Sets a specific texture unit to be the active texUnit.
    /// @param texUnit - The ID of the texture unit as an integer. Tex unit 1 is simply 1, not GL_TEXTURE0 + 1.
    /// @see glActiveTexture
    static void Active(GLuint texUnit) {
        oglwrap_PreCheckError();

        glActiveTexture(GL_TEXTURE0 + texUnit);
        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_ENUM,
            "TextureBase::Active is called for a texUnit ID that is either negative or
            "greater than GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS - 1"
        );
    }

    /// Generates mipmaps for the currently uploaded image to this texture class.
    /// @see glGenerateMipmap
    static void GenerateMipmap() {
        oglwrap_PreCheckError();

        glGenerateMipmap(texture_t);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "TextureCube::GenerateMipmap is called but the bound cube map is not complete."
        );
    }

    /// Sets the border color for this texture class.
    /// @param color - Specifies the value, the border color should be set to.
    /// @see glTexParameterfv, GL_TEXTURE_BORDER_COLOR
    static void BorderColor(glm::vec4 color) {
        oglwrap_PreCheckError();

        glTexParameterfv(texture_t, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color));
    }

    /// Sets the minification filter for this texture class.
    /// @param filtermode - The desired minification filter mode.
    /// @see glTexParameteri, GL_TEXTURE_MIN_FILTER
    static void MinFilter(MinF filtermode) {
        oglwrap_PreCheckError();

        glTexParameteri(texture_t, GL_TEXTURE_MIN_FILTER, filtermode);
    }

    /// Sets the magnification filter for this texture class.
    /// @param filtermode - The desired magnification filter mode.
    /// @see glTexParameteri, GL_TEXTURE_MAG_FILTER
    static void MagFilter(MagF filtermode) {
        oglwrap_PreCheckError();

        glTexParameteri(texture_t, GL_TEXTURE_MAG_FILTER, filtermode);
    }

    /// Sets the way, OpenGL should handle if the texture coordinate's
    /// 's' (first) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_S
    static void WrapS(Wrap wrapmode) {
        oglwrap_PreCheckError();

        glTexParameteri(texture_t, GL_TEXTURE_WRAP_S, wrapmode);
    }

    /// Sets the way, OpenGL should handle if the texture coordinate's
    /// 't' (second) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_T
    static void WrapT(Wrap wrapmode) {
        oglwrap_PreCheckError();

        glTexParameteri(texture_t, GL_TEXTURE_WRAP_T, wrapmode);
    }

    /// Sets the way, OpenGL should handle if the texture coordinate's
    /// 'p' (third) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_R
    static void WrapR(Wrap wrapmode) {
        oglwrap_PreCheckError();

        glTexParameteri(texture_t, GL_TEXTURE_WRAP_R, wrapmode);
    }

    /// Sets what OpenGL should do if you write texture.r
    /// for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_R
    static void SwizzleR(Swizzle swizzlemode) {
        oglwrap_PreCheckError();

        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_R, swizzlemode);
    }

    /// Sets what OpenGL should do if you write texture.g
    /// for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_G
    static void SwizzleG(Swizzle swizzlemode) {
        oglwrap_PreCheckError();

        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_G, swizzlemode);
    }

    /// Sets what OpenGL should do if you write texture.b
    /// for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_B
    static void SwizzleB(Swizzle swizzlemode) {
        oglwrap_PreCheckError();

        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_B, swizzlemode);
    }

    /// Sets what OpenGL should do if you write texture.a
    /// for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_A
    static void SwizzleA(Swizzle swizzlemode) {
        oglwrap_PreCheckError();

        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_A, swizzlemode);
    }

    /// Sets what OpenGL should do if you use the swizzle operator to
    /// select either of the 4 components from a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_RGBA
    static void SwizzleRGBA(Swizzle swizzlemode) {
        oglwrap_PreCheckError();

        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_RGBA, swizzlemode);
    }

    /// Sets the anisotropy extension to a desired value.
    /// @param value - The desired anisotropy value.
    /// @see glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT
    static void Anisotropy(float value) {
        oglwrap_PreCheckError();

        glTexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, value);
    }

    /// Sets the anisotropy extension to the maximum value possible on this hardware.
    /// @see glGetFloatv, glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT
    static void MaxAnisotropy() {
        oglwrap_PreCheckError();

        GLfloat maxAniso = 0.0f;
        glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAniso);
        glTexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAniso);
    }

    /// Assigns a buffer storing the texel data to the texture.
    /// @param internalFormat - Specifies the internal format of the data in the store belonging to buffer. It must be a sized, uncompressed internal format.
    /// @param buffer - Specifies the name of the buffer object whose storage to attach to the active buffer texture.
    /// @see glTexBuffer
    static void Buffer(PixelDataInternalFormat internalFormat, const TextureBuffer& buffer) {
        oglwrap_PreCheckError();

        glTexBuffer(texture_t, internalFormat, buffer.Expose());
    }

    /// Returns the C handle for the texture.
    GLuint Expose() const {
        oglwrap_PreCheckError();

        return texture;
    }
};

} // namespace oglwrap

#endif // TEXUTRE_BASE
