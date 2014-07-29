// Copyright (c) 2014, Tamas Csala

/** @file texture_1D.h
    @brief Implements one-dimensional textures.
*/

#ifndef OGLWRAP_TEXTURES_TEXTURE_1D_H_
#define OGLWRAP_TEXTURES_TEXTURE_1D_H_

#include "./texture_base.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/// A one dimensional texture class
/** @see GL_TEXTURE_1D */
class Texture1D : public TextureBase<TextureType::kTexture1D> {
 public:
  /// Uploads the base image.
  /** @param internal_format - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage1D */
  void upload(PixelDataInternalFormat internal_format, GLsizei width,
              PixelDataFormat format, PixelDataType type,
              const void *data);

  /// Uploads a mipmap of the image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internal_format - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage1D */
  void uploadMipmap(GLint level, PixelDataInternalFormat internal_format,
                    GLsizei width, PixelDataFormat format,
                    PixelDataType type, const void *data);

  /// Updates a part of the base image.
  /** @param x_offset - Specifies a texel offset in the x direction within the texture array.
    * @param width - Specifies the width of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage1D */
  void subUpload(GLint x_offset, GLsizei width, PixelDataFormat format,
                 PixelDataType type, const void *data);

  /// Updates a part of a mipmap image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param x_offset - Specifies a texel offset in the x direction within the texture array.
    * @param width - Specifies the width of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage1D */
  void subUploadMipmap(GLint level, GLint x_offset, GLsizei width,
                       PixelDataFormat format, PixelDataType type,
                       const void *data);

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage1D)
  /// Simultaneously specify storage for all levels of a one-dimensional texture
  /** @param levels - Specify the number of texture levels.
    * @param internal_format - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels. */
  void storage(GLsizei levels, GLenum internal_format, GLsizei width);
#endif  // glTexStorage1D

  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of this texture.
  /** @param internal_format - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexImage1D */
  void copy(PixelDataInternalFormat internal_format,
            GLint x, GLint y, GLsizei width);

  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of this texture.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internal_format - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexImage1D */
  void copyMipmap(GLint level, PixelDataInternalFormat internal_format,
                  GLint x, GLint y, GLsizei width);

  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
  /** @param x_offset - Specifies the texel offset within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexSubImage1D */
  void copySub(GLint x_offset, GLint x, GLint y, GLsizei width);

  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture with them.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param x_offset - Specifies the texel offset within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexSubImage1D */
  void copySubMipmap(GLint level, GLint x_offset, GLint x, GLint y,
                      GLsizei width);

  /// Returns the width of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  GLsizei width(GLint level = 0) const;

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
  /// Return a compressed texture image
  /** @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  void getCompressedImage(GLint level, GLvoid* img) const;
#endif  // glGetCompressedTexImage
};

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_1D_H_
