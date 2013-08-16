/** @file texture_cube.hpp
    @brief Implements two-dimensional cubeMap textures.
*/

#pragma once
#ifndef TEXUTRE_CUBE_HPP
#define TEXTURE_CUBE_HPP

#include "texture_base.hpp"

namespace oglwrap {

// -------======{[ TextureCube declaration ]}======-------

/// @brief A set of 6 2D textures, that is used to be sampled with 3D direction vectors.
/// @see GL_TEXTURE_CUBE_MAP
class TextureCube : public TextureBase<TexType::TexCubeMap> {
public:
    /// Generates an empty texture.
    /// @see glGenTextures
    TextureCube() {}

    template <TexType texture_t>
    /// Copies a 2D texture or changes the type of a texture to Texture2D
    /// @param src - The texture to copy or cast to Texture2D
    TextureCube(const TextureBase<texture_t>& src)
        :TextureBase<TexType::TexCubeMap>(src) {}

    /// Uploads one a base image for one side of the cube.
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    /// @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    /// @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexImage2D
    static void Upload(
        CubeTarget target,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage2D(
            target, 0, internalFormat, width, height, 0, format, type, data
        );
        oglwrap_CheckError();
    }

    /// Uploads a mipmap for one side of the cube.
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    /// @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    /// @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexImage2D
    static void Upload_Mipmap(
        CubeTarget target,
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexImage2D(
            target, level, internalFormat, width, height, 0, format, type, data
        );
        oglwrap_CheckError();
    }


    /// Updates a part of the base image for one side of the cube.
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    /// @param width/height - Specifies the width/height of the texture subimage.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexSubImage2D
    static void SubUpload(
        CubeTarget target,
        GLint xOffset,
        GLint yOffset,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    ) {
        glTexSubImage2D(
            target, 0, xOffset, yOffset, width, height, format, type, data
        );
        oglwrap_CheckError();
    }

    /// Updates a part of a mipmap image for one side of the cube.
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    /// @param width/height - Specifies the width/height of the texture subimage.
    /// @param format - Specifies the format of the pixel data.
    /// @param type - Specifies the data type of the pixel data.
    /// @param data - Specifies a pointer to the image data in memory.
    /// @see glTexSubImage2D
    static void SubUpload_Mipmap(
        CubeTarget target,
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
            target, level, xOffset, yOffset, width, height, format, type, data
        );
        oglwrap_CheckError();
    }

    /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of one side of the cube.
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param internalFormat - Specifies the internal format of the texture.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexImage2D
    static void Copy(
        CubeTarget target,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexImage2D(target, 0, internalFormat, x, y, width, height, 0);
        oglwrap_CheckError();
    }

    /// Copies pixels from the current GL_READ_BUFFER into a mipmap of one side of the cube.
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param internalFormat - Specifies the internal format of the texture.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexImage2D
    static void Copy_Mipmap(
        CubeTarget target,
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexImage2D(target, level, internalFormat, x, y, width, height, 0);
        oglwrap_CheckError();
    }

    /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of one side with them.
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexSubImage2D
    static void CopySub(
        CubeTarget target,
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexSubImage2D(target, 0, xOffset, yOffset, x, y, width, height);
        oglwrap_CheckError();
    }

    /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of one side.
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    /// @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    /// @param width/height - Specifies the width/height of the texture to copy.
    /// @see glCopyTexSubImage2D
    static void CopySub_Mipmap(
        CubeTarget target,
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    ) {
        glCopyTexSubImage2D(target, level, xOffset, yOffset, x, y, width, height);
        oglwrap_CheckError();
    }

    /// Returns the width of a mipmap of one side.
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param level - Specifies the mipmap whose size should be queried.
    /// @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH
    static GLsizei Width(CubeTarget target, GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(target, level, GL_TEXTURE_WIDTH, &data);
        oglwrap_CheckError();
        return data;
    }

    /// Returns the height of a mipmap of one side.
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param level - Specifies the mipmap whose size should be queried.
    /// @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT
    static GLsizei Height(CubeTarget target, GLint level = 0) {
        GLsizei data;
        glGetTexLevelParameteriv(target, level, GL_TEXTURE_HEIGHT, &data);
        oglwrap_CheckError();
        return data;
    }

    /// Returns the i-th element of the cube sides in alphabetic order.
    /// @param i - The index of the CubeTarget to return
    static CubeTarget CubeFace(int i) {
        switch(i) {
            case 0:
                return CubeTarget::PosX;
            case 1:
                return CubeTarget::NegX;
            case 2:
                return CubeTarget::PosY;
            case 3:
                return CubeTarget::NegY;
            case 4:
                return CubeTarget::PosZ;
            case 5:
                return CubeTarget::NegZ;
            default:
                throw std::invalid_argument("CubeFace argument must be between 0 and 5");
        }
    }

    /// Return the compressed texture image of one side
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    /// @param img - Returns the compressed texture image.
    /// @see glGetCompressedTexImage
    static void GetCompressedImage(CubeTarget target, GLint level, GLvoid* img) {
        glGetCompressedTexImage(target, level, img);
        oglwrap_CheckError();
    }

#if OGLWRAP_IMAGEMAGICK
    /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
    /// @param target - Specifies which one of the six sides of the cube to use as target.
    /// @param file - Path to the image file.
    /// @param formatString - Specifies the number and order of components to be read.
    /// @see glTexImage2D
    static void LoadTexture(CubeTarget target,
                            const std::string& file,
                            const std::string& formatString = "RGBA") {
        try {
            Magick::Image image = Magick::Image(file);
            Magick::Blob blob;
            image.write(&blob, formatString);

            Upload(
                target,
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

    /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
    /// @param faceID - Specifies the index of the side to upload. It is usefully to upload all six sides in a for loop.
    /// @param file - Path to the image file.
    /// @param formatString - Specifies the number and order of components to be read.
    /// @see glTexImage2D
    static void LoadTexture(GLuint faceID,
                            const std::string& file,
                            const std::string& formatString = "RGBA") {
        try {
            Magick::Image image = Magick::Image(file);
            Magick::Blob blob;
            image.write(&blob, formatString);

            Upload(
                CubeFace(faceID),
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
}; // End of TextureCube definition

} // namespace oglwrap

#endif // TEXTURE_CUBE

