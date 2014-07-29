// Copyright (c) 2014, Tamas Csala

/** @file texture_2D.h
    @brief Implements two-dimensional, non-cubemap textures.
*/

#ifndef OGLWRAP_TEXTURES_TEXTURE_2D_H_
#define OGLWRAP_TEXTURES_TEXTURE_2D_H_

#include "./texture_base.h"
#include "../enums/texture2D_type.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

template<Texture2DType texture_t>
/// The base class describing functionality for all 2D textures.
/** You should rather use the typedefed versions than this template. */
class Texture2DBase : public TextureBase<TextureType(texture_t)> {
 public:
  /// Uploads the base image.
  /** @param internal_format - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  void upload(PixelDataInternalFormat internal_format, GLsizei width,
              GLsizei height, PixelDataFormat format, PixelDataType type,
              const void *data);

  /// Uploads a mipmap of the image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internal_format - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  void uploadMipmap(GLint level, PixelDataInternalFormat internal_format,
                    GLsizei width, GLsizei height, PixelDataFormat format,
                    PixelDataType type, const void *data);

  /// Updates a part of the base image.
  /** @param x_offset, y_offset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width, height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  void subUpload(GLint x_offset, GLint y_offset, GLsizei width, GLsizei height,
                 PixelDataFormat format, PixelDataType type,
                 const void *data);

  /// Updates a part of a mipmap image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param x_offset, y_offset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width, height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  void subUploadMipmap(GLint level, GLint x_offset, GLint y_offset, GLsizei width,
                       GLsizei height, PixelDataFormat format,
                       PixelDataType type, const void *data);

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage2D)
  /// Simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
  /** @param levels - Specify the number of texture levels.
    * @param internal_format - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels.
    * @param height - Specifies the height of the texture, in texels. */
  void storage(GLsizei levels, GLenum internal_format, GLsizei width,
               GLsizei height);
#endif  // glTexStorage2D

  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of this texture.
  /** @param internal_format - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  void copy(PixelDataInternalFormat internal_format, GLint x, GLint y,
            GLsizei width, GLsizei height);

  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of this texture.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internal_format - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  void copyMipmap(GLint level, PixelDataInternalFormat internal_format,
                  GLint x, GLint y, GLsizei width, GLsizei height);

  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
  /** @param x_offset, y_offset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  void copySub(GLint x_offset, GLint y_offset, GLint x, GLint y,
               GLsizei width, GLsizei height);

  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param x_offset/y_offset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  void copySubMipmap(GLint level, GLint x_offset, GLint y_offset,
                     GLint x, GLint y, GLsizei width, GLsizei height);

  /// Returns the width of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  GLsizei width(GLint level = 0) const;

  /// Returns the height of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT */
  GLsizei height(GLint level = 0) const;

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
  /// Return a compressed texture image
  /** @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  void getCompressedImage(GLint level, GLvoid* img) const;
#endif  // glGetCompressedTexImage

#if OGLWRAP_USE_IMAGEMAGICK
  /// Loads in, and uploads an image from a file using Magick++.
  /** @param file - Path to the image file.
    * @param format_string - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  void loadTexture(const std::string& file, std::string format_string = "CSRGBA");
#endif
};

/// The most commonly used two-dimensional texture type.
/** @see GL_TEXTURE_2D */
typedef Texture2DBase<Texture2DType::kTexture2D> Texture2D;

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
/// A rectangle texture is a texture that contains a single 2D image with no mipmaps.
/** It has no power-of-two restrictions on its size. Texture coordinates for accessing
  * this texture must be texel values (floating-point), representing texels within the
  * texture, rather than normalized texture coordinates.
  * @see GL_TEXTURE_RECTANGLE */
typedef Texture2DBase<Texture2DType::kTextureRectangle> TextureRect;
#endif  // GL_TEXTURE_RECTANGLE

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
/// An array of one-dimensional textures.
/** @see GL_TEXTURE_1D_ARRAY */
typedef Texture2DBase<Texture2DType::kTexture1DArray> Texture1DArray;
#endif  // GL_TEXTURE_1D_ARRAY

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_2D_H_
