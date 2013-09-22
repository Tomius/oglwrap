/** @file texture_3D.hpp
    @brief Implements three-dimensional textures.
*/

#pragma once

namespace oglwrap {

// -------======{[ 3D Textures' declaration ]}======-------
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_3D)
template<Tex3DType texture_t>
/// The base class describing functionality for all 2D textures.
/** You should rather use the typedefed versions than this template. */
class Texture3D_Base : public TextureBase<TexType(texture_t)> {
public:

    using TextureBase<TexType(texture_t)>::isBound;
    using TextureBase<TexType(texture_t)>::bind;

    /// Generates an empty texture.
    /** @see glGenTextures */
    Texture3D_Base() {}

    template <Tex3DType another_texture_t>
    /// Copies a 3D texture or casts a three-dimensional texture to another 3d tex type.
    /** @param src - The texture to copy or cast. */
    Texture3D_Base(const TextureBase<another_texture_t>& src)
        :TextureBase<texture_t>(src) {}

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexImage3D)
    /// Uploads the base image.
    /** @param internalFormat - Specifies the number, order, and size of the color components in the texture.
      * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
      * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
      * @param depth - Specifies the depth of the texture image, or the number of layers in a texture array. All implementations support 3D texture images that are at least 256 texels deep, and texture arrays that are at least 256 layers deep.
      * @param format - Specifies the format of the pixel data.
      * @param type - Specifies the data type of the pixel data.
      * @param data - Specifies a pointer to the image data in memory.
      * @see glTexImage3D */
    static void Upload(
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        gl( TexImage3D(
            texture_t, 0, internalFormat, width, height, depth, 0, format, type, data
        ));
    }
    /// Uploads the base image.
    /** @param internalFormat - Specifies the number, order, and size of the color components in the texture.
      * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
      * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
      * @param depth - Specifies the depth of the texture image, or the number of layers in a texture array. All implementations support 3D texture images that are at least 256 texels deep, and texture arrays that are at least 256 layers deep.
      * @param format - Specifies the format of the pixel data.
      * @param type - Specifies the data type of the pixel data.
      * @param data - Specifies a pointer to the image data in memory.
      * @see glTexImage3D */
    BIND_CHECKED void upload(
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) const {
        CHECK_BINDING();
        Upload(internalFormat, width, height, depth, format, type, data);
    }
    #endif // glTexImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexImage3D)
    /// Uploads a mipmap of the image.
    /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
      * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
      * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
      * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
      * @param depth - Specifies the depth of the texture image, or the number of layers in a texture array. All implementations support 3D texture images that are at least 256 texels deep, and texture arrays that are at least 256 layers deep.
      * @param format - Specifies the format of the pixel data.
      * @param type - Specifies the data type of the pixel data.
      * @param data - Specifies a pointer to the image data in memory.
      * @see glTexImage3D */
    static void Upload_mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        gl( TexImage3D(
            texture_t, level, internalFormat, width, height, depth, 0, format, type, data
        ));
    }
    /// Uploads a mipmap of the image.
    /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
      * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
      * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
      * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
      * @param depth - Specifies the depth of the texture image, or the number of layers in a texture array. All implementations support 3D texture images that are at least 256 texels deep, and texture arrays that are at least 256 layers deep.
      * @param format - Specifies the format of the pixel data.
      * @param type - Specifies the data type of the pixel data.
      * @param data - Specifies a pointer to the image data in memory.
      * @see glTexImage3D */
    BIND_CHECKED void upload_mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) const {
        CHECK_BINDING();
        Upload_mipmap(level, internalFormat, width, height, depth, format, type, data);
    }
    #endif // glTexImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexSubImage3D)
    /// Updates a part of the base image.
    /** @param xOffset/yOffset/zOffset - Specifies a texel offset in the x/y/z direction within the texture array.
      * @param width/height/depth - Specifies the width/height/depth of the texture subimage.
      * @param format - Specifies the format of the pixel data.
      * @param type - Specifies the data type of the pixel data.
      * @param data - Specifies a pointer to the image data in memory.
      * @see glTexSubImage3D */
    static void SubUpload(
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
        gl( TexSubImage3D(
            texture_t, 0, xOffset, yOffset, zOffset, width, height, depth, format, type, data
        ));
    }
    /// Updates a part of the base image.
    /** @param xOffset/yOffset/zOffset - Specifies a texel offset in the x/y/z direction within the texture array.
      * @param width/height/depth - Specifies the width/height/depth of the texture subimage.
      * @param format - Specifies the format of the pixel data.
      * @param type - Specifies the data type of the pixel data.
      * @param data - Specifies a pointer to the image data in memory.
      * @see glTexSubImage3D */
    BIND_CHECKED void subUpload(
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) const {
        CHECK_BINDING();
        SubUpload(xOffset, yOffset, zOffset, width, height, depth, format, type, data);
    }
    #endif // glTexSubImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexSubImage3D)
    /// Updates a part of a mipmap image.
    /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
      * @param xOffset/yOffset/zOffset - Specifies a texel offset in the x/y/z direction within the texture array.
      * @param width/height/depth - Specifies the width/height/depth of the texture subimage.
      * @param format - Specifies the format of the pixel data.
      * @param type - Specifies the data type of the pixel data.
      * @param data - Specifies a pointer to the image data in memory.
      * @see glTexSubImage3D */
    static void SubUpload_mipmap(
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
        gl( TexSubImage3D(
            texture_t, level, xOffset, yOffset, zOffset, width, height, depth, format, type, data
        ));
    }
    /// Updates a part of a mipmap image.
    /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
      * @param xOffset/yOffset/zOffset - Specifies a texel offset in the x/y/z direction within the texture array.
      * @param width/height/depth - Specifies the width/height/depth of the texture subimage.
      * @param format - Specifies the format of the pixel data.
      * @param type - Specifies the data type of the pixel data.
      * @param data - Specifies a pointer to the image data in memory.
      * @see glTexSubImage3D */
    BIND_CHECKED void subUpload_mipmap(
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
    ) const {
        CHECK_BINDING();
        SubUpload_mipmap(level, xOffset, yOffset, zOffset, width, height, depth, format, type, data);
    }
    #endif // glTexSubImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glCopyTexSubImage3D)
    /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
    /** @param xOffset/yOffset/zOffset - Specifies the texel offset in the x/y/z direction within the destination texture array.
      * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
      * @param width/height - Specifies the width/height of the texture to copy.
      * @see glCopyTexSubImage3D */
    static void CopySub(
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        gl( CopyTexSubImage3D(texture_t, 0, xOffset, yOffset, zOffset, x, y, width, height) );
    }
    /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
    /** @param xOffset/yOffset/zOffset - Specifies the texel offset in the x/y/z direction within the destination texture array.
      * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
      * @param width/height - Specifies the width/height of the texture to copy.
      * @see glCopyTexSubImage3D */
    BIND_CHECKED void copySub(
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) const {
        CHECK_BINDING();
        CopySub(xOffset, yOffset, zOffset, x, y, width, height);
    }
    #endif // glCopyTexSubImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glCopyTexSubImage3D)
    /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture.
    /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
      * @param xOffset/yOffset/zOffset - Specifies the texel offset in the x/y/z direction within the destination texture array.
      * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
      * @param width/height - Specifies the width/height of the texture to copy.
      * @see glCopyTexSubImage3D */
    static void CopySub_mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        gl( CopyTexSubImage3D(texture_t, level, xOffset, yOffset, zOffset, x, y, width, height) );
    }
    /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture.
    /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
      * @param xOffset/yOffset/zOffset - Specifies the texel offset in the x/y/z direction within the destination texture array.
      * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
      * @param width/height - Specifies the width/height of the texture to copy.
      * @see glCopyTexSubImage3D */
    BIND_CHECKED void copySub_mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) const {
        CHECK_BINDING();
        CopySub_mipmap(level, xOffset, yOffset, zOffset, x, y, width, height);
    }
    #endif // glCopyTexSubImage3D

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexStorage3D)
    /// Simultaneously specify storage for all levels of a three-dimensional, two-dimensional array or cube-map array texture.
    /** @param levels - Specify the number of texture levels.
      * @param internalFormat - Specifies the sized internal format to be used to store texture image data.
      * @param width - Specifies the width of the texture, in texels.
      * @param height - Specifies the height of the texture, in texels.
      * @param depth - Specifies the depth of the texture, in texels. */
    static void Storage(GLsizei levels,
                 GLenum internalFormat,
                 GLsizei width,
                 GLsizei height,
                 GLsizei depth) {
        gl( TexStorage3D(texture_t, levels, internalFormat, width, height, depth) );
    }
    /// Simultaneously specify storage for all levels of a three-dimensional, two-dimensional array or cube-map array texture.
    /** @param levels - Specify the number of texture levels.
      * @param internalFormat - Specifies the sized internal format to be used to store texture image data.
      * @param width - Specifies the width of the texture, in texels.
      * @param height - Specifies the height of the texture, in texels.
      * @param depth - Specifies the depth of the texture, in texels. */
    BIND_CHECKED void storage(
        GLsizei levels,
        GLenum internalFormat,
        GLsizei width,
        GLsizei height,
        GLsizei depth
    ) const {
        CHECK_BINDING();
        Storage(levels, internalFormat, width, height, depth);
    }
    #endif // glTexStorage3D

    /// Returns the width of a mipmap of the currently bound texture of this class.
    /** @param level - Specifies the mipmap whose size should be queried.
      * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
    static GLsizei Width(GLint level = 0) {
        GLsizei data;
        gl( GetTexLevelParameteriv(texture_t, level, GL_TEXTURE_WIDTH, &data) );
        return data;
    }
    /// Returns the width of a mipmap of the currently bound texture of this class.
    /** @param level - Specifies the mipmap whose size should be queried.
      * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
    BIND_CHECKED GLsizei width(GLint level = 0) const {
        CHECK_BINDING();
        return Width(level);
    }

    /// Returns the height of a mipmap of the currently bound texture of this class.
    /** @param level - Specifies the mipmap whose size should be queried.
      * @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT */
    static GLsizei Height(GLint level = 0) {
        GLsizei data;
        gl( GetTexLevelParameteriv(texture_t, level, GL_TEXTURE_HEIGHT, &data) );
        return data;
    }
    /// Returns the height of a mipmap of the currently bound texture of this class.
    /** @param level - Specifies the mipmap whose size should be queried.
      * @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT */
    BIND_CHECKED GLsizei height(GLint level = 0) const {
        CHECK_BINDING();
        return Height(level);
    }

    /// Returns the depth of a mipmap of the currently bound texture of this class.
    /** @param level - Specifies the mipmap whose size should be queried.
      * @see glGetTexLevelParameteriv, GL_TEXTURE_DEPTH */
    static GLsizei Depth(GLint level = 0) {
        GLsizei data;
        gl( GetTexLevelParameteriv(texture_t, level, GL_TEXTURE_DEPTH, &data) );
        return data;
    }
    /// Returns the depth of a mipmap of the currently bound texture of this class.
    /** @param level - Specifies the mipmap whose size should be queried.
      * @see glGetTexLevelParameteriv, GL_TEXTURE_DEPTH */
    BIND_CHECKED GLsizei depth(GLint level = 0) const {
        CHECK_BINDING();
        return Depth(level);
    }

    #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glGetCompressedTexImage)
    /// Return a compressed texture image
    /** @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
      * @param img - Returns the compressed texture image.
      * @see glGetCompressedTexImage */
    static void GetCompressedImage(GLint level, GLvoid* img) {
        gl( GetCompressedTexImage(TexType::Tex3D, level, img) );
    }
    /// Return a compressed texture image
    /** @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
      * @param img - Returns the compressed texture image.
      * @see glGetCompressedTexImage */
    BIND_CHECKED void getCompressedImage(GLint level, GLvoid* img) const {
        CHECK_BINDING();
        GetCompressedImage(level, img);
    }
    #endif
};

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_3D)
/// Three-dimensional texture.
/** @see GL_TEXTURE_3D */
typedef Texture3D_Base<Tex3DType::Tex3D> Texture3D;
#endif // GL_TEXTURE_3D

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_2D_ARRAY)
/// An array of two dimensional textures
/** @see GL_TEXTURE_2D_ARRAY */
typedef Texture3D_Base<Tex3DType::Tex2DArray> Texture2D_Array;
#endif // GL_TEXTURE_2D_ARRAY

#endif // GL_TEXTURE_3D

} // namespace oglwrap

