/** @file texture_1D.h
    @brief Implements one-dimensional textures.
*/

#ifndef OGLWRAP_TEXTURES_TEXTURE_1D_H_
#define OGLWRAP_TEXTURES_TEXTURE_1D_H_

#include "texture_base.h"

#include "../define_internal_macros.h"

namespace oglwrap {

// -------======{[ Texture1D declaration ]}======-------

/// A one dimensional texture class
/** @see GL_TEXTURE_1D */
class Texture1D : public TextureBase<TextureType::Tex1D> {
public:
  /// Uploads the base image.
  /** @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage1D */
  static void Upload(
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) {
    gl(TexImage1D(
      GL_TEXTURE_1D, 0, GLenum(internalFormat), width,
      0, GLenum(format), GLenum(type), data
    ));
  }
  /// Uploads the base image.
  /** @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage1D */
  BIND_CHECKED void upload(
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    OGLWRAP_CHECK_BINDING();
    Upload(internalFormat, width, format, type, data);
  }

  /// Uploads a mipmap of the image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage1D */
  static void UploadMipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) {
    gl(TexImage1D(
      GL_TEXTURE_1D, level, GLenum(internalFormat), width,
      0, GLenum(format), GLenum(type), data
    ));
  }
  /// Uploads a mipmap of the image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage1D */
  BIND_CHECKED void uploadMipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    OGLWRAP_CHECK_BINDING();
    UploadMipmap(level, internalFormat, width, format, type, data);
  }

  /// Updates a part of the base image.
  /** @param xOffset - Specifies a texel offset in the x direction within the texture array.
    * @param width - Specifies the width of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage1D */
  static void SubUpload(
    GLint xOffset,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) {
    gl(TexSubImage1D(
      GL_TEXTURE_1D, 0, xOffset, width, GLenum(format), GLenum(type), data
    ));
  }
  /// Updates a part of the base image.
  /** @param xOffset - Specifies a texel offset in the x direction within the texture array.
    * @param width - Specifies the width of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage1D */
  BIND_CHECKED void subUpload(
    GLint xOffset,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    OGLWRAP_CHECK_BINDING();
    SubUpload(xOffset, width, format, type, data);
  }

  /// Updates a part of a mipmap image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset - Specifies a texel offset in the x direction within the texture array.
    * @param width - Specifies the width of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage1D */
  static void SubUploadMipmap(
    GLint level,
    GLint xOffset,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) {
    gl(TexSubImage1D(
      GL_TEXTURE_1D, level, xOffset, width, GLenum(format), GLenum(type), data
    ));
  }
  /// Updates a part of a mipmap image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset - Specifies a texel offset in the x direction within the texture array.
    * @param width - Specifies the width of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage1D */
  BIND_CHECKED void subUploadMipmap(
    GLint level,
    GLint xOffset,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    OGLWRAP_CHECK_BINDING();
    SubUploadMipmap(level, xOffset, width, format, type, data);
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage1D)
  /// Simultaneously specify storage for all levels of a one-dimensional texture
  /** @param levels - Specify the number of texture levels.
    * @param internalFormat - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels. */
  static void Storage(GLsizei levels,
                      GLenum internalFormat,
                      GLsizei width) {
    gl(TexStorage1D(GL_TEXTURE_1D, levels, GLenum(internalFormat), width));
  }
  /// Simultaneously specify storage for all levels of a one-dimensional texture
  /** @param levels - Specify the number of texture levels.
    * @param internalFormat - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels. */
  BIND_CHECKED void storage(GLsizei levels,
                            GLenum internalFormat,
                            GLsizei width) const {
    OGLWRAP_CHECK_BINDING();
    Storage(levels, internalFormat, width);
  }
#endif // glTexStorage1D

  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of this texture.
  /** @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexImage1D */
  static void Copy(
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width
  ) {
    gl(CopyTexImage1D(
      GL_TEXTURE_1D, 0, GLenum(internalFormat), x, y, width, 0
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of this texture.
  /** @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexImage1D */
  BIND_CHECKED void copy(
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width
  ) const {
    Copy(internalFormat, x, y, width);
  }

  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of this texture.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexImage1D */
  static void CopyMipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width
  ) {
    gl(CopyTexImage1D(
      GL_TEXTURE_1D, level, GLenum(internalFormat), x, y, width, 0
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of this texture.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexImage1D */
  BIND_CHECKED void copyMipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width
  ) const {
    OGLWRAP_CHECK_BINDING();
    CopyMipmap(level, internalFormat, x, y, width);
  }

  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
  /** @param xOffset - Specifies the texel offset within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexSubImage1D */
  static void CopySub(
    GLint xOffset,
    GLint x,
    GLint y,
    GLsizei width
  ) {
    gl(CopyTexSubImage1D(
      GL_TEXTURE_1D, 0, xOffset, x, y, width
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
  /** @param xOffset - Specifies the texel offset within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexSubImage1D */
  BIND_CHECKED void copySub(
    GLint xOffset,
    GLint x,
    GLint y,
    GLsizei width
  ) const {
    OGLWRAP_CHECK_BINDING();
    CopySub(xOffset, x, y, width);
  }

  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture with them.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset - Specifies the texel offset within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexSubImage1D */
  static void CopySub_mipmap(
    GLint level,
    GLint xOffset,
    GLint x,
    GLint y,
    GLsizei width
  ) {
    gl(CopyTexSubImage1D(
      GL_TEXTURE_1D, level, xOffset, x, y, width
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture with them.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset - Specifies the texel offset within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width - Specifies the number of texels to copy.
    * @see glCopyTexSubImage1D */
  BIND_CHECKED void copySub_mipmap(
    GLint level,
    GLint xOffset,
    GLint x,
    GLint y,
    GLsizei width
  ) const {
    OGLWRAP_CHECK_BINDING();
    CopySub_mipmap(level, xOffset, x, y, width);
  }

  /// Returns the width of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  static GLsizei Width(GLint level = 0) {
    GLsizei w;
    gl(GetTexLevelParameteriv(GL_TEXTURE_1D, level, GL_TEXTURE_WIDTH, &w));
    return w;
  }
  /// Returns the width of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  BIND_CHECKED GLsizei width(GLint level = 0) const {
    OGLWRAP_CHECK_BINDING();
    return Width(level);
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
  /// Return a compressed texture image
  /** @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  static void GetCompressedImage(GLint level, GLvoid* img) {
    gl(GetCompressedTexImage(GL_TEXTURE_1D, level, img));
  }
  /// Return a compressed texture image
  /** @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  BIND_CHECKED void getCompressedImage(GLint level, GLvoid* img) const {
    OGLWRAP_CHECK_BINDING();
    GetCompressedImage(level, img);
  }
#endif // glGetCompressedTexImage
};

} // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif // OGLWRAP_TEXTURES_TEXTURE_1D_H_
