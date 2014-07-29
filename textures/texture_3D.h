// Copyright (c) 2014, Tamas Csala

/** @file texture_3D.h
    @brief Implements three-dimensional textures.
*/

#ifndef OGLWRAP_TEXTURES_TEXTURE_3D_H_
#define OGLWRAP_TEXTURES_TEXTURE_3D_H_

#include "./texture_base.h"
#include "../enums/texture3D_type.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
template<Texture3DType texture_t>
/// The base class describing functionality for all 2D textures.
/** You should rather use the typedefed versions than this template. */
class Texture3DBase : public TextureBase<TextureType(texture_t)> {
 public:
#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexImage3D)
  /// Uploads the base image.
  /** @param internal_format - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param depth - Specifies the depth of the texture image, or the number of layers in a texture array. All implementations support 3D texture images that are at least 256 texels deep, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage3D */
  void upload(PixelDataInternalFormat internal_format, GLsizei width,
              GLsizei height, GLsizei depth, PixelDataFormat format,
              PixelDataType type, const void *data);

  /// Uploads a mipmap of the image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internal_format - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param depth - Specifies the depth of the texture image, or the number of layers in a texture array. All implementations support 3D texture images that are at least 256 texels deep, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage3D */
  void uploadMipmap(GLint level, PixelDataInternalFormat internal_format,
                    GLsizei width, GLsizei height, GLsizei depth,
                    PixelDataFormat format, PixelDataType type,
                    const void *data);
#endif  // glTexImage3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexSubImage3D)
  /// Updates a part of the base image.
  /** @param x_offset/y_offset/z_offset - Specifies a texel offset in the x/y/z direction within the texture array.
    * @param width/height/depth - Specifies the width/height/depth of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage3D */
  void subUpload(GLint x_offset, GLint y_offset, GLint z_offset, GLsizei width,
                 GLsizei height, GLsizei depth, PixelDataFormat format,
                 PixelDataType type, const void *data);


  /// Updates a part of a mipmap image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param x_offset/y_offset/z_offset - Specifies a texel offset in the x/y/z direction within the texture array.
    * @param width/height/depth - Specifies the width/height/depth of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage3D */
  void subUploadMipmap(GLint level, GLint x_offset, GLint y_offset, GLint z_offset,
                       GLsizei width, GLsizei height, GLsizei depth,
                       PixelDataFormat format, PixelDataType type,
                       const void *data);
#endif  // glTexSubImage3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCopyTexSubImage3D)
  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
  /** @param x_offset/y_offset/z_offset - Specifies the texel offset in the x/y/z direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage3D */
  void copySub(GLint x_offset, GLint y_offset, GLint z_offset, GLint x, GLint y,
               GLsizei width, GLsizei height);

  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param x_offset/y_offset/z_offset - Specifies the texel offset in the x/y/z direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage3D */
  void copySubMipmap(GLint level, GLint x_offset, GLint y_offset, GLint z_offset,
                     GLint x, GLint y, GLsizei width, GLsizei height);
#endif  // glCopyTexSubImage3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage3D)
  /// Simultaneously specify storage for all levels of a three-dimensional, two-dimensional array or cube-map array texture.
  /** @param levels - Specify the number of texture levels.
    * @param internal_format - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels.
    * @param height - Specifies the height of the texture, in texels.
    * @param depth - Specifies the depth of the texture, in texels. */
  void storage(GLsizei levels, PixelDataInternalFormat internal_format,
               GLsizei width, GLsizei height, GLsizei depth);
#endif  // glTexStorage3D

  /// Returns the width of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  GLsizei width(GLint level = 0) const;

  /// Returns the height of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT */
  GLsizei height(GLint level = 0) const;

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_DEPTH)
  /// Returns the depth of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_DEPTH */
  GLsizei depth(GLint level = 0) const;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
  /// Return a compressed texture image
  /** @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  void getCompressedImage(GLint level, GLvoid* img) const;
#endif
};

/// Three-dimensional texture.
/** @see GL_TEXTURE_3D */
using Texture3D = Texture3DBase<Texture3DType::kTexture3D>;

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
/// An array of two dimensional textures
/** @see GL_TEXTURE_2D_ARRAY */
using Texture2DArray = Texture3DBase<Texture3DType::kTexture2DArray>;
#endif  // GL_TEXTURE_2D_ARRAY

#endif  // GL_TEXTURE_3D

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_3D_H_
