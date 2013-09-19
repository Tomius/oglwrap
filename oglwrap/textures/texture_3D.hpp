/** @file texture_3D.hpp
    @brief Implements three-dimensional textures.
*/

#pragma once

#define CHECK_BINDING_TEXTURE3D() \
    CHECK_BINDING_EXPLICIT(Texture3D_Base<texture_t>::isBound, Texture3D_Base<texture_t>::bind);

namespace oglwrap {

// -------======{[ 3D Textures' declaration ]}======-------
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_3D)
template<Tex3DType texture_t>
/// The base class describing functionality for all 2D textures.
/** You should rather use the typedefed versions than this template. */
class Texture3D_Base : public TextureBase<TexType(texture_t)> {
public:
    /// @brief Generates an empty texture.
    /// @see glGenTextures
    Texture3D_Base() {}

    template <Tex3DType another_texture_t>
    /// @brief Copies a 3D texture or casts a three-dimensional texture to another 3d tex type.
    /// @param src - The texture to copy or cast.
    Texture3D_Base(const TextureBase<another_texture_t>& src)
        :TextureBase<texture_t>(src) {}

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexImage3D)
    /// @brief Uploads the base image.
    /// @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    /// @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    /// @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    /// @param depth - Specifies the depth of the texture image, or the number of layers in a texture array. All implementations support 3D texture images that are at least 256 texels deep, and texture arrays that are at least 256 layers deep.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexImage3D
    void upload(
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        CHECK_BINDING_TEXTURE3D();

        gl( TexImage3D(
            texture_t, 0, internalFormat, width, height, depth, 0, format, type, data
        ));
    }
    #endif // glTexImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexImage3D)
    /// @brief Uploads a mipmap of the image.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    /// @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    /// @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    /// @param depth - Specifies the depth of the texture image, or the number of layers in a texture array. All implementations support 3D texture images that are at least 256 texels deep, and texture arrays that are at least 256 layers deep.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexImage3D
    void upload_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        CHECK_BINDING_TEXTURE3D();

        gl( TexImage3D(
            texture_t, level, internalFormat, width, height, depth, 0, format, type, data
        ));
    }
    #endif // glTexImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexSubImage3D)
    /// @brief Updates a part of the base image.
    /// @param xOffset/yOffset/zOffset - Specifies a texel offset in the x/y/z direction within the texture array.
    /// @param width/height/depth - Specifies the width/height/depth of the texture subimage.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexSubImage3D
    void subUpload(
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        CHECK_BINDING_TEXTURE3D();

        gl( TexSubImage3D(
            texture_t, 0, xOffset, yOffset, zOffset, width, height, depth, format, type, data
        ));
    }
    #endif // glTexSubImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexSubImage3D)
    /// @brief Updates a part of a mipmap image.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param xOffset/yOffset/zOffset - Specifies a texel offset in the x/y/z direction within the texture array.
    /// @param width/height/depth - Specifies the width/height/depth of the texture subimage.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexSubImage3D
    void subUpload_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        CHECK_BINDING_TEXTURE3D();

        gl( TexSubImage3D(
            texture_t, level, xOffset, yOffset, zOffset, width, height, depth, format, type, data
        ));
    }
    #endif // glTexSubImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glCopyTexSubImage3D)
    /// @brief Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
    /// @param xOffset/yOffset/zOffset - Specifies the texel offset in the x/y/z direction within the destination texture array.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexSubImage3D
    void copySub(
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        CHECK_BINDING_TEXTURE3D();

        gl( CopyTexSubImage3D(texture_t, 0, xOffset, yOffset, zOffset, x, y, width, height) );
    }
    #endif // glCopyTexSubImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glCopyTexSubImage3D)
    /// @brief Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param xOffset/yOffset/zOffset - Specifies the texel offset in the x/y/z direction within the destination texture array.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexSubImage3D
    void copySub_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        CHECK_BINDING_TEXTURE3D();

        gl( CopyTexSubImage3D(texture_t, level, xOffset, yOffset, zOffset, x, y, width, height) );
    }
    #endif // glCopyTexSubImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexStorage3D)
    /// Simultaneously specify storage for all levels of a three-dimensional, two-dimensional array or cube-map array texture.
    /** @param levels - Specify the number of texture levels.
      * @param internalformat - Specifies the sized internal format to be used to store texture image data.
      * @param width - Specifies the width of the texture, in texels.
      * @param height - Specifies the height of the texture, in texels.
      * @param depth - Specifies the depth of the texture, in texels. */
    void Storage(GLsizei levels,
                 GLenum internalformat,
                 GLsizei width,
                 GLsizei height,
                 GLsizei depth) {
        CHECK_BINDING_TEXTURE3D();

        gl( TexStorage3D(texture_t, levels, internalformat, width, height, depth) );
    }
    #endif // glTexStorage3D

    /// @brief Returns the width of a mipmap of the currently bound texture of this class.
    /// @param level - Specifies the mipmap whose size should be queried.
    /// @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH
    GLsizei width(GLint level = 0) {
        CHECK_BINDING_TEXTURE3D();

        GLsizei data;
        gl( GetTexLevelParameteriv(texture_t, level, GL_TEXTURE_WIDTH, &data) );
        return data;
    }

    /// @brief Returns the height of a mipmap of the currently bound texture of this class.
    /// @param level - Specifies the mipmap whose size should be queried.
    /// @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT
    GLsizei height(GLint level = 0) {
        CHECK_BINDING_TEXTURE3D();

        GLsizei data;
        gl( GetTexLevelParameteriv(texture_t, level, GL_TEXTURE_HEIGHT, &data) );
        return data;
    }

    /// @brief Returns the depth of a mipmap of the currently bound texture of this class.
    /// @param level - Specifies the mipmap whose size should be queried.
    /// @see glGetTexLevelParameteriv, GL_TEXTURE_DEPTH
    GLsizei depth(GLint level = 0) {
        CHECK_BINDING_TEXTURE3D();

        GLsizei data;
        gl( GetTexLevelParameteriv(texture_t, level, GL_TEXTURE_DEPTH, &data) );
        return data;
    }

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glGetCompressedTexImage)
    /// @brief Return a compressed texture image
    /// @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param img - Returns the compressed texture image.
    /// @see glGetCompressedTexImage
    void getCompressedImage(GLint level, GLvoid* img) {
        CHECK_BINDING_TEXTURE3D();
        gl( GetCompressedTexImage(TexType::Tex3D, level, img) );
    }
    #endif
};

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_3D)
/// @brief Three-dimensional texture.
/// @see GL_TEXTURE_3D
typedef Texture3D_Base<Tex3DType::Tex3D> Texture3D;
#endif // GL_TEXTURE_3D

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_2D_ARRAY)
/// An array of two dimensional textures
/// @see GL_TEXTURE_2D_ARRAY
typedef Texture3D_Base<Tex3DType::Tex2DArray> Texture2D_Array;
#endif // GL_TEXTURE_2D_ARRAY

#endif // GL_TEXTURE_3D

} // namespace oglwrap

