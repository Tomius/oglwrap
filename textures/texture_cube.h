// Copyright (c) 2014, Tamas Csala

/** @file texture_cube.h
    @brief Implements two-dimensional cubeMap textures.
*/

#ifndef OGLWRAP_TEXTURES_TEXTURE_CUBE_H_
#define OGLWRAP_TEXTURES_TEXTURE_CUBE_H_

#include "./texture_base.h"
#include "../enums/texture_cube_target.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
/// A set of 6 2D textures, that is used to be sampled with 3D direction vectors.
/** @see GL_TEXTURE_CUBE_MAP */
class TextureCube : public TextureBase<TextureType::kTextureCubeMap> {
 public:
  /// Uploads one a base image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param internal_format - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  void upload(TextureCubeTarget target, PixelDataInternalFormat internal_format,
              GLsizei width, GLsizei height, PixelDataFormat format,
              PixelDataType type, const void *data);

  /// Uploads a mipmap for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internal_format - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  void uploadMipmap(TextureCubeTarget target, GLint level,
                    PixelDataInternalFormat internal_format, GLsizei width,
                    GLsizei height, PixelDataFormat format, PixelDataType type,
                    const void *data);

  /// Updates a part of the base image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param x_offset/y_offset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width/height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  void subUpload(TextureCubeTarget target, GLint x_offset, GLint y_offset,
                 GLsizei width, GLsizei height, PixelDataFormat format,
                 PixelDataType type, const void *data);

  /// Updates a part of a mipmap image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param x_offset/y_offset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width/height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  void subUploadMipmap(TextureCubeTarget target, GLint level, GLint x_offset,
                       GLint y_offset, GLsizei width, GLsizei height,
                       PixelDataFormat format, PixelDataType type,
                       const void *data);

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage2D)
  /// Simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param levels - Specify the number of texture levels.
    * @param internal_format - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels.
    * @param height - Specifies the height of the texture, in texels. */
  void storage(TextureCubeTarget target, GLsizei levels, GLenum internal_format,
               GLsizei width, GLsizei height);
#endif  // glTexStorage2D

  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param internal_format - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  void copy(TextureCubeTarget target, PixelDataInternalFormat internal_format,
            GLint x, GLint y, GLsizei width, GLsizei height);

  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internal_format - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  void copyMipmap(TextureCubeTarget target, GLint level,
                  PixelDataInternalFormat internal_format, GLint x, GLint y,
                  GLsizei width, GLsizei height);

  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of one side with them.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param x_offset/y_offset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  void copySub(TextureCubeTarget target, GLint x_offset, GLint y_offset,
               GLint x, GLint y, GLsizei width, GLsizei height);

  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param x_offset/y_offset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  void copySubMipmap(TextureCubeTarget target, GLint level, GLint x_offset,
                     GLint y_offset, GLint x, GLint y, GLsizei width,
                     GLsizei height);

  /// Returns the width of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  GLsizei width(TextureCubeTarget target, GLint level = 0) const;

  /// Returns the height of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT */
  GLsizei height(TextureCubeTarget target, GLint level = 0) const;

  /// Returns the i-th element of the cube sides in alphabetic order.
  /** @param i - The index of the TextureCubeTarget to return */
  static TextureCubeTarget cubeFace(int i);

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
  /// Return the compressed texture image of one side
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  void getCompressedImage(TextureCubeTarget target,
                          GLint level, GLvoid* img) const;
#endif

#if OGLWRAP_USE_IMAGEMAGICK
  /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param file - Path to the image file.
    * @param format_string - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  void loadTexture(TextureCubeTarget target, const std::string& file,
                  std::string format_string = "CSRGBA");

  /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
  /** @param faceID - Specifies the index of the side to upload. It is usefully to upload all six sides in a for loop.
    * @param file - Path to the image file.
    * @param format_string - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  void loadTexture(GLuint faceID, const std::string& file,
                  std::string format_string = "CSRGBA");
#endif
};

#endif  // GL_TEXTURE_CUBE_MAP

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_CUBE_H_
