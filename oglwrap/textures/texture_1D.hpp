/** @file texture_1D.hpp
    @brief Implements one-dimensional textures.
*/

#pragma once

namespace oglwrap {

// -------======{[ Texture1D declaration ]}======-------

/// @brief A one dimensional texture class
/// @see GL_TEXTURE_1D
class Texture1D : public TextureBase<TexType::Tex1D> {
public:
    /// Uploads the base image.
    /// @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    /// @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexImage1D
    void upload(
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        CHECK_BINDING();

        gl( TexImage1D(
            TexType::Tex1D, 0, internalFormat, width, 0, format, type, data
        ));
    }

    /// Uploads a mipmap of the image.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    /// @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexImage1D
    void upload_mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        CHECK_BINDING();

        gl( TexImage1D(
            TexType::Tex1D, level, internalFormat, width, 0, format, type, data
        ));
    }

    /// Updates a part of the base image.
    /// @param xOffset - Specifies a texel offset in the x direction within the texture array.
    /// @param width - Specifies the width of the texture subimage.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexSubImage1D
    void subUpload(
        GLint xOffset,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        CHECK_BINDING();

        gl( TexSubImage1D(
            TexType::Tex1D, 0, xOffset, width, format, type, data
        ));
    }

    /// Updates a part of a mipmap image.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param xOffset - Specifies a texel offset in the x direction within the texture array.
    /// @param width - Specifies the width of the texture subimage.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexSubImage1D
    void subUpload_mipmap(
        GLint level,
        GLint xOffset,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        CHECK_BINDING();

        gl( TexSubImage1D(
            TexType::Tex1D, level, xOffset, width, format, type, data
        ));
    }

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexStorage1D)
    /// Simultaneously specify storage for all levels of a one-dimensional texture
    /** @param levels - Specify the number of texture levels.
      * @param internalFormat - Specifies the sized internal format to be used to store texture image data.
      * @param width - Specifies the width of the texture, in texels. */
    void storage(GLsizei levels,
                 GLenum internalFormat,
                 GLsizei width) {
        CHECK_BINDING();

        gl( TexStorage1D(TexType::Tex1D, levels, internalFormat, width) );
    }
    #endif // glTexStorage1D

    /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of this texture.
    /// @param internalFormat - Specifies the internal format of the texture.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width - Specifies the number of texels to copy.
    /// @see glCopyTexImage1D
    void copy(
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width
    ) {
        CHECK_BINDING();

        gl( CopyTexImage1D(
            TexType::Tex1D, 0, internalFormat, x, y, width, 0
        ));
    }

    /// Copies pixels from the current GL_READ_BUFFER into a mipmap of this texture.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param internalFormat - Specifies the internal format of the texture.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width - Specifies the number of texels to copy.
    /// @see glCopyTexImage1D
    void copy_mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width
    ) {
        CHECK_BINDING();

        gl( CopyTexImage1D(
            TexType::Tex1D, level, internalFormat, x, y, width, 0
        ));
    }

    /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
    /// @param xOffset - Specifies the texel offset within the destination texture array.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width - Specifies the number of texels to copy.
    /// @see glCopyTexSubImage1D
    void copySub(
        GLint xOffset,
        GLint x,
        GLint y,
        GLsizei width
    ) {
        CHECK_BINDING();

        gl( CopyTexSubImage1D(
            TexType::Tex1D, 0, xOffset, x, y, width
        ));
    }

    /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture with them.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param xOffset - Specifies the texel offset within the destination texture array.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width - Specifies the number of texels to copy.
    /// @see glCopyTexSubImage1D
    void copySub_mipmap(
        GLint level,
        GLint xOffset,
        GLint x,
        GLint y,
        GLsizei width
    ) {
        CHECK_BINDING();

        gl( CopyTexSubImage1D(
            TexType::Tex1D, level, xOffset, x, y, width
        ));
    }

    /// Returns the width of a mipmap of the currently bound texture of this class.
    /// @param level - Specifies the mipmap whose size should be queried.
    /// @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH
    GLsizei width(GLint level = 0) {
        CHECK_BINDING();

        GLsizei w;
        gl( GetTexLevelParameteriv(TexType::Tex1D, level, GL_TEXTURE_WIDTH, &w) );
        return w;
    }

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glGetCompressedTexImage)
    /// Return a compressed texture image
    /// @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param img - Returns the compressed texture image.
    /// @see glGetCompressedTexImage
    void getCompressedImage(GLint level, GLvoid* img) {
        CHECK_BINDING();
        gl( GetCompressedTexImage(TexType::Tex1D, level, img) );
    }
    #endif // glGetCompressedTexImage
};

} // namespace oglwrap

