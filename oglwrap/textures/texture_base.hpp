/** @file texture_base.hpp
    @brief Implements the base functionality for textures.
*/

#pragma once

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
    /// Creates a copy of the texture, or casts it to another type.
    /** Important: if you use this to change the type of the active texture,
      * don't forget to unbind the old one, and bind the new one */
    TextureBase(const TextureBase<another_texture_t>& srctexture)
        : texture(srctexture.expose()) {
    }

    /// @brief Binds the texture to this texture class's target.
    /// @see glBindTexture
    void bind() const {
        gl( BindTexture(texture_t, texture) );
    }

    /// @brief Unbinds the texture from this texture class's target.
    /// @see glBindTexture
    static void unbind() {
        gl( BindTexture(texture_t, 0) );
    }

    /// @brief Returns if this is the currently bound texture for its target.
    /// @see glGetIntegerv
    bool isBound() const {
        GLint currentlyBoundTexture;
        gl( GetIntegerv(getBindingTarget(texture_t), &currentlyBoundTexture) );
        return texture == GLuint(currentlyBoundTexture);
    }

    /// @brief Sets a specific texture unit to be the active texUnit.
    /// @param texUnit - The ID of the texture unit as an integer. Tex unit 1 is simply 1, not GL_TEXTURE0 + 1.
    /// @see glActiveTexture
    static void active(GLuint texUnit) {
        gl( ActiveTexture(GL_TEXTURE0 + texUnit) );
    }

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glGenerateMipmap)
    /// @brief Generates mipmaps for the currently uploaded image to this texture class.
    /// @see glGenerateMipmap
    void generateMipmap() {
        CHECK_BINDING();
        gl( GenerateMipmap(texture_t) );
    }
    #endif

    /// @brief Sets the border color for this texture class.
    /// @param color - Specifies the value, the border color should be set to.
    /// @see glTexParameterfv, GL_TEXTURE_BORDER_COLOR
    void borderColor(glm::vec4 color) {
        CHECK_BINDING();
        gl( TexParameterfv(texture_t, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color)) );
    }

    /// @brief Sets the minification filter for this texture class.
    /// @param filtermode - The desired minification filter mode.
    /// @see glTexParameteri, GL_TEXTURE_MIN_FILTER
    void minFilter(MinF filtermode) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_MIN_FILTER, filtermode) );
    }

    /// @brief Sets the magnification filter for this texture class.
    /// @param filtermode - The desired magnification filter mode.
    /// @see glTexParameteri, GL_TEXTURE_MAG_FILTER
    void magFilter(MagF filtermode) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_MAG_FILTER, filtermode) );
    }

    /// @brief Sets the way, OpenGL should handle if the texture coordinate's 's' (first) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_S
    void wrapS(Wrap wrapmode) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_WRAP_S, wrapmode) );
    }

    /// @brief Sets the way, OpenGL should handle if the texture coordinate's 't' (second) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_T
    void wrapT(Wrap wrapmode) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_WRAP_T, wrapmode) );
    }

    /// @brief Sets the way, OpenGL should handle if the texture coordinate's 'p' (third) part is out of the [0, 1] range for this texture class.
    /// @param wrapmode - The desired wrapping mode.
    /// @see glTexParameteri, GL_TEXTURE_WRAP_R
    void wrapR(Wrap wrapmode) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_WRAP_R, wrapmode) );
    }

    /// @brief Sets what OpenGL should do if you write texture.r for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_R
    void swizzleR(Swizzle swizzlemode) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_R, swizzlemode) );
    }

    /// @brief Sets what OpenGL should do if you write texture.g for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_G
    void swizzleG(Swizzle swizzlemode) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_G, swizzlemode) );
    }

    /// @brief Sets what OpenGL should do if you write texture.b for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_B
    void swizzleB(Swizzle swizzlemode) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_B, swizzlemode) );
    }

    /// @brief Sets what OpenGL should do if you write texture.a for a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_A
    void swizzleA(Swizzle swizzlemode) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_A, swizzlemode) );
    }

    /// @brief Sets what OpenGL should do if you use the swizzle operator to select either of the 4 components from a texture of this class in a shader.
    /// @param swizzlemode - The desired swizzle mode.
    /// @see glTexParameteri, GL_TEXTURE_SWIZZLE_RGBA
    void swizzleRGBA(Swizzle swizzlemode) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_RGBA, swizzlemode) );
    }

    /// @brief Sets the anisotropy extension to a desired value.
    /** It doesn't do anything if anisotropy is not supported */
    /// @param value - The desired anisotropy value.
    /// @see glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT
    void anisotropy(float value) {
        CHECK_BINDING();
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_MAX_ANISOTROPY_EXT)
        gl( TexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, value) );
        #endif
    }

    /// @brief Sets the anisotropy extension to the maximum value possible on this hardware.
    /** It doesn't do anything if anisotropy is not supported */
    /// @see glGetFloatv, glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT
    void maxAnisotropy() {
        CHECK_BINDING();
        #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_MAX_ANISOTROPY_EXT)
        GLfloat maxAniso = 0.0f;
        gl( GetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAniso) );
        gl( TexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAniso) );
        #endif // GL_TEXTURE_MAX_ANISOTROPY_EXT
    }

    #if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glGenBuffers) && defined(glDeleteBuffers) && defined(GL_TEXTURE_BUFFER))
    /// @brief Assigns a buffer storing the texel data to the texture.
    /// @param internalFormat - Specifies the internal format of the data in the store belonging to buffer. It must be a sized, uncompressed internal format.
    /// @param buffer - Specifies the name of the buffer object whose storage to attach to the active buffer texture.
    /// @see glTexBuffer
    void buffer(PixelDataInternalFormat internalFormat, const TextureBuffer& buffer) {
        CHECK_BINDING();
        gl( TexBuffer(texture_t, internalFormat, buffer.Expose()) );
    }
    #endif

    /// @brief Sets the compare mode.
    /// @param mode - The desired compare mode.
    /// @see glTexParameteri, GL_TEXTURE_COMPARE_MODE
    void compareMode (CompMode mode) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_COMPARE_MODE, mode) );
    }

    /// @brief Sets the compare function.
    /// @param func - The desired compare function.
    /// @see glTexParameteri, GL_TEXTURE_COMPARE_FUNC
    void compareFunc (CompFunc func) {
        CHECK_BINDING();
        gl( TexParameteri(texture_t, GL_TEXTURE_COMPARE_FUNC, func) );
    }

    /// Returns the handle for the texture.
    const Object<glGenTextures, glDeleteTextures>& expose() const {
        return texture;
    }
};

} // namespace oglwrap


