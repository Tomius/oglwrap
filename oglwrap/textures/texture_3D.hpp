/** @file texture_3D.hpp
    @brief Implements three-dimensional textures.
*/

#ifndef TEXUTRE_3D_HPP
#define TEXTURE_3D_HPP

#include "texture_base.hpp"

namespace oglwrap {

// -------======{[ 3D Textures' declaration ]}======-------

template<Tex3DType texture_t>
/// The base class describing functionality for all 2D textures.
/** You should rather use the typedefed versions than this template. */
class Texture3D_Base : public TextureBase<TexType(texture_t)> {
public:

    /// Generates an empty texture.
    /// @see glGenTextures
    Texture3D_Base() {}

    template <TexType another_texture_t>
    /// Copies a 3D texture or changes the type of a texture to Texture3D
    /// @param src - The texture to copy or cast to Texture3D
    Texture3D_Base(const TextureBase<another_texture_t>& src)
        :TextureBase<texture_t>(src) {}

    /// Uploads the base image.
    /// @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    /// @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    /// @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    /// @param depth - Specifies the depth of the texture image, or the number of layers in a texture array. All implementations support 3D texture images that are at least 256 texels deep, and texture arrays that are at least 256 layers deep.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexImage3D
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

    /// Uploads a mipmap of the image.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    /// @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    /// @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    /// @param depth - Specifies the depth of the texture image, or the number of layers in a texture array. All implementations support 3D texture images that are at least 256 texels deep, and texture arrays that are at least 256 layers deep.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexImage3D
    static void Upload_Mipmap(
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

    /// Updates a part of the base image.
    /// @param xOffset/yOffset/zOffset - Specifies a texel offset in the x/y/z direction within the texture array.
    /// @param width/height/depth - Specifies the width/height/depth of the texture subimage.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexSubImage3D
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

    /// Updates a part of a mipmap image.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param xOffset/yOffset/zOffset - Specifies a texel offset in the x/y/z direction within the texture array.
    /// @param width/height/depth - Specifies the width/height/depth of the texture subimage.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexSubImage3D
    static void SubUpload_Mipmap(
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

    /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
    /// @param xOffset/yOffset/zOffset - Specifies the texel offset in the x/y/z direction within the destination texture array.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexSubImage3D
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

    /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param xOffset/yOffset/zOffset - Specifies the texel offset in the x/y/z direction within the destination texture array.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexSubImage3D
    static void CopySub_Mipmap(
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

    /// Returns the width of a mipmap of the currently bound texture of this class.
    /// @param level - Specifies the mipmap whose size should be queried.
    /// @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH
    static GLsizei Width(GLint level = 0) {
        GLsizei data;
        gl( GetTexLevelParameteriv(texture_t, level, GL_TEXTURE_WIDTH, &data) );
        return data;
    }

    /// Returns the height of a mipmap of the currently bound texture of this class.
    /// @param level - Specifies the mipmap whose size should be queried.
    /// @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT
    static GLsizei Height(GLint level = 0) {
        GLsizei data;
        gl( GetTexLevelParameteriv(texture_t, level, GL_TEXTURE_HEIGHT, &data) );
        return data;
    }

    /// Returns the depth of a mipmap of the currently bound texture of this class.
    /// @param level - Specifies the mipmap whose size should be queried.
    /// @see glGetTexLevelParameteriv, GL_TEXTURE_DEPTH
    static GLsizei Depth(GLint level = 0) {
        GLsizei data;
        gl( GetTexLevelParameteriv(texture_t, level, GL_TEXTURE_DEPTH, &data) );
        return data;
    }

    // compressed image getter
    /// Return a compressed texture image
    /// @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param img - Returns the compressed texture image.
    /// @see glGetCompressedTexImage
    static void GetCompressedImage(GLint level, GLvoid* img) {
        gl( GetCompressedTexImage(TexType::Tex3D, level, img) );
    }
};

typedef Texture3D_Base<Tex3DType::Tex3D> Texture3D;
typedef Texture3D_Base<Tex3DType::Tex2DArray> Texture2D_Array;

} // namespace oglwrap

#endif // TEXTURE_3D
