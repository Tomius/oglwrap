#ifndef TEXUTRE_2D_HPP
#define TEXTURE_2D_HPP

#include <string>
#include <GL/glew.h>

#include "../error.hpp"
#include "../enums.hpp"
#include "../general.hpp"
#include "texture_base.hpp"

#ifndef OGLWRAP_IMAGEMAGICK
#define OGLWRAP_IMAGEMAGICK 0
#endif
#if OGLWRAP_IMAGEMAGICK
#include <ImageMagick/Magick++.h>
#endif

namespace oglwrap {

// -------======{[ 2D Textures' declaration ]}======-------

template<Tex2DType texture_t>
/// The base class describing functionality for all 2D textures.
/// You should rather use the typedefed versions than this template.
class _Texture2D : public TextureBase<TexType(texture_t)> {
public:
    /// Uploads the base image.
    /// @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    /// @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    /// @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexImage2D
    static void Upload(
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage2D(
            texture_t, 0, internalFormat, width, height, 0, format, type, data
        );
        oglwrap_CheckError();
    }

    /// Uploads a mipmap of the image.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    /// @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    /// @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexImage2D
    static void Upload_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage2D(
            texture_t, level, internalFormat, width, height, 0, format, type, data
        );
        oglwrap_CheckError();
    }

    /// Updates a part of the base image.
    /// @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    /// @param width/height - Specifies the width/height of the texture subimage.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexSubImage2D
    static void SubUpload(
        GLint xOffset,
        GLint yOffset,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexSubImage2D(
            texture_t, 0, xOffset, yOffset, width, height, format, type, data
        );
        oglwrap_CheckError();
    }

    /// Updates a part of a mipmap image.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    /// @param width/height - Specifies the width/height of the texture subimage.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexSubImage2D
    static void SubUpload_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexSubImage2D(
            texture_t, level, xOffset, yOffset, width, height, format, type, data
        );
        oglwrap_CheckError();
    }

    /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of this texture.
    /// @param internalFormat - Specifies the internal format of the texture.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexImage2D
    static void Copy(
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexImage2D(texture_t, 0, internalFormat, x, y, width, height, 0);
        oglwrap_CheckError();
    }

    /// Copies pixels from the current GL_READ_BUFFER into a mipmap of this texture.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param internalFormat - Specifies the internal format of the texture.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexImage2D
    static void Copy_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexImage2D(texture_t, level, internalFormat, x, y, width, height, 0);
        oglwrap_CheckError();
    }

    /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
    /// @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexSubImage2D
    static void CopySub(
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexSubImage2D(texture_t, 0, xOffset, yOffset, x, y, width, height);
        oglwrap_CheckError();
    }

    /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture.
    /// @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexSubImage2D
    static void CopySub_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexSubImage2D(texture_t, level, xOffset, yOffset, x, y, width, height);
        oglwrap_CheckError();
    }

    /// Returns the width of a mipmap of the currently bound texture of this class.
    /// @param level - Specifies the mipmap whose size should be queried.
    /// @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH
    static GLsizei Width(GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_WIDTH, &data);
        oglwrap_CheckError();
        return data;
    }

    /// Returns the height of a mipmap of the currently bound texture of this class.
    /// @param level - Specifies the mipmap whose size should be queried.
    /// @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT
    static GLsizei Height(GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_HEIGHT, &data);
        oglwrap_CheckError();
        return data;
    }

    /// Return a compressed texture image
    /// @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param img - Returns the compressed texture image.
    /// @see glGetCompressedTexImage
    static void GetCompressedImage(GLint level, GLvoid* img) {
        glGetCompressedTexImage(TexType::Tex2D, level, img);
        oglwrap_CheckError();
    }

#if OGLWRAP_IMAGEMAGICK
    /// Loads in, and uploads an image from a file using Magick++.
    /// @param file - Path to the image file.
    /// @param formatString - Specifies the number and order of components to be read.
    /// @see glTexImage2D
    static void LoadTexture(const std::string& file, const std::string& formatString = "RGBA") {
        try {
            Magick::Image image = Magick::Image(file);
            Magick::Blob blob;
            image.write(&blob, formatString);

            Upload(
                PixelDataInternalFormat::SRGBA8,
                image.columns(),
                image.rows(),
                PixelDataFormat::RGBA,
                PixelDataType::UnsignedByte,
                blob.data()
            );
        } catch(Magick::Error& Error) {
            std::cerr << "Error loading texture: " << Error.what() << std::endl;
        }
    }
#endif
};

typedef _Texture2D<Tex2DType::Tex2D> Texture2D;
/// The most commonly used two-dimensional texture type.

typedef _Texture2D<Tex2DType::TexRect> TextureRect;
/// A rectangle texture is a texture that contains a single 2D image with no mipmaps.
/// It has no power-of-two restrictions on its size. Texture coordinates for accessing
/// this texture must be texel values (floating-point), representing texels within the
/// texture, rather than normalized texture coordinates.

typedef _Texture2D<Tex2DType::Tex1DArray> Texture1D_Array;
/// An array of one-dimensional textures.

} // namespace oglwrap

#endif // TEXTURE_2D
