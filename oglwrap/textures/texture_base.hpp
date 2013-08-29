/** @file texture_base.hpp
    @brief Implements the base functionality for textures.
*/

#pragma once
#ifndef TEXUTRE_BASE_HPP
#define TEXTURE_BASE_HPP

namespace oglwrap {

// -------======{[ TextureBase declaration ]}======-------

template <TexType texture_t>
/// @brief This class is implementing the base functions for textures.
/** You shouldn't use this class directly. **/
/// @see glGenTextures, glDeleteTextures
class TextureBase {
protected:
    Object<glGenTextures, glDeleteTextures> texture; ///< The handle for the texture.
public:
    /// Generates an empty texture.
    TextureBase() {}

    template <TexType another_texture_t>
    /// @brief Creates a copy from an already existing texture. Can also change it's default target.
    /** You can use it to cast for example Texture2D to TextureRect. */
    TextureBase(const TextureBase<another_texture_t>& srctexture)
        : texture(srctexture.expose()) {
    }

    /// @brief Binds the texture to this texture class's target.
    /// @see glBindTexture
    void bind() const {
        gl( BindTexture(texture_t, texture) );

        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "TextureBase::Bind is called, but the texture was previously created "
            "for another target, and can not be bound for this target."
        );
    }

    /// @brief Unbinds the texture from this texture class's target.
    /// @see glBindTexture
    static void unbind() {
        gl( BindTexture(texture_t, 0) );
    }

    /// @brief Sets a specific texture unit to be the active texUnit.
    /// @param texUnit - The ID of the texture unit as an integer. Tex unit 1 is simply 1, not GL_TEXTURE0 + 1.
    /// @see glActiveTexture
    static void active(GLuint texUnit) {
        gl( ActiveTexture(GL_TEXTURE0 + texUnit) );

        oglwrap_PrintError(
            GL_INVALID_ENUM,
            "TextureBase::Active is called for a texUnit ID that is either negative or "
            "greater than GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS - 1"
        );
    }

    /// @brief Generates mipmaps for the currently uploaded image to this texture class.
    /// @see glGenerateMipmap
    static void generateMipmap() {
        gl( GenerateMipmap(texture_t) );

        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "TextureCube::GenerateMipmap is called but the bound cube map is not complete."
        );
    }

    /// @brief Sets the border color for this texture class.
    /// @param color - Specifies the value, the border color should be set to.
    /// @see glTexParameterfv, GL_TEXTURE_BORDER_COLOR
    static void borderColor(glm::vec4 color) {
        gl( TexParameterfv(texture_t, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color)) );
    }

    /// @brief Sets the minification filter for this texture class.
    /// @param filtermode - The desired minification filter mode.
    /// @see glTexParameteri, GL_TEXTURE_MIN_FILTER
    static void minFilter(MinF filtermode) {
        gl( TexParameteri(texture_t, GL_TEXTURE_MIN_FILTER, filtermode) );
    }

    /// @brief Sets the magnification filter for this texture class.
    /// @param filtermode - The desired magnification filter mode.
    /// @see glTexParameteri, GL_TEXTURE_MAG_FILTER
    static void magFilter(MagF filtermode) {
        gl( TexParameteri(texture_t, GL_TEXTURE_MAG_FILTER, filtermode) );
    }

    /// @brief Sets the way, OpenGL should handle if the texture coordinate's 's' (first) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_S
    static void wrapS(Wrap wrapmode) {
        gl( TexParameteri(texture_t, GL_TEXTURE_WRAP_S, wrapmode) );
    }

    /// @brief Sets the way, OpenGL should handle if the texture coordinate's 't' (second) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_T
    static void wrapT(Wrap wrapmode) {
        gl( TexParameteri(texture_t, GL_TEXTURE_WRAP_T, wrapmode) );
    }

    /// @brief Sets the way, OpenGL should handle if the texture coordinate's 'p' (third) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_R
    static void wrapR(Wrap wrapmode) {
        gl( TexParameteri(texture_t, GL_TEXTURE_WRAP_R, wrapmode) );
    }

    /// @brief Sets what OpenGL should do if you write texture.r for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_R
    static void swizzleR(Swizzle swizzlemode) {
        gl( TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_R, swizzlemode) );
    }

    /// @brief Sets what OpenGL should do if you write texture.g for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_G
    static void swizzleG(Swizzle swizzlemode) {
        gl( TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_G, swizzlemode) );
    }

    /// @brief Sets what OpenGL should do if you write texture.b for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_B
    static void swizzleB(Swizzle swizzlemode) {
        gl( TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_B, swizzlemode) );
    }

    /// @brief Sets what OpenGL should do if you write texture.a for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_A
    static void swizzleA(Swizzle swizzlemode) {
        gl( TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_A, swizzlemode) );
    }

    /// @brief Sets what OpenGL should do if you use the swizzle operator to select either of the 4 components from a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_RGBA
    static void swizzleRGBA(Swizzle swizzlemode) {
        gl( TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_RGBA, swizzlemode) );
    }

    /// @brief Sets the anisotropy extension to a desired value.
    /// @param value - The desired anisotropy value.
    /// @see glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT
    static void anisotropy(float value) {
        gl( TexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, value) );
    }

    /// @brief Sets the anisotropy extension to the maximum value possible on this hardware.
    /// @see glGetFloatv, glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT
    static void maxAnisotropy() {
        GLfloat maxAniso = 0.0f;
        gl( GetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAniso) );
        gl( TexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAniso) );
    }

    /// @brief Assigns a buffer storing the texel data to the texture.
    /// @param internalFormat - Specifies the internal format of the data in the store belonging to buffer. It must be a sized, uncompressed internal format.
    /// @param buffer - Specifies the name of the buffer object whose storage to attach to the active buffer texture.
    /// @see glTexBuffer
    static void buffer(PixelDataInternalFormat internalFormat, const TextureBuffer& buffer) {
        gl( TexBuffer(texture_t, internalFormat, buffer.Expose()) );
    }

    /// @brief Sets the compare mode.
    /// @param mode - The desired compare mode.
    /// @see glTexParameteri, GL_TEXTURE_COMPARE_MODE
    static void compareMode (CompMode mode) {
        gl( TexParameteri(texture_t, GL_TEXTURE_COMPARE_MODE, mode) );
    }

    /// @brief Sets the compare function.
    /// @param mode - The desired compare function.
    /// @see glTexParameteri, GL_TEXTURE_COMPARE_FUNC
    static void compareFunc (CompFunc func) {
        gl( TexParameteri(texture_t, GL_TEXTURE_COMPARE_FUNC, func) );
    }

    /// Returns the handle for the texture.
    const Object<glGenTextures, glDeleteTextures>& expose() const {
        return texture;
    }
};

} // namespace oglwrap

#endif // TEXUTRE_BASE

