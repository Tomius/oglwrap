/** @file texture_cube.hpp
    @brief Implements two-dimensional cubeMap textures.
*/

#ifndef OGLWRAP_TEXTURES_TEXTURE_CUBE_HPP_
#define OGLWRAP_TEXTURES_TEXTURE_CUBE_HPP_

#include <stdexcept>
#include "texture_base.hpp"

namespace oglwrap {

// -------======{[ TextureCube declaration ]}======-------

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_CUBE_MAP)
/// A set of 6 2D textures, that is used to be sampled with 3D direction vectors.
/** @see GL_TEXTURE_CUBE_MAP */
class TextureCube : public TextureBase<TexType::TexCubeMap> {
public:
  /// Generates an empty texture.
  /** @see glGenTextures */
  TextureCube() {}

  template <Tex2DType another_texture_t>
  /// Copies a 2D texture or casts a two-dimensional texture to another 2d texture type.
  /** @param src - The texture to copy or cast. */
  TextureCube(const TextureBase<another_texture_t>& src)
    : TextureBase<another_texture_t>(src) {}

  /// Uploads one a base image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  static void Upload(
    CubeTarget target,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) {
    gl(TexImage2D(
         target, 0, internalFormat, width, height, 0, format, type, data
       ));
  }
  /// Uploads one a base image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  BIND_CHECKED void upload(
    CubeTarget target,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    CHECK_BINDING();
    Upload(target, internalFormat, width, height, format, type, data);
  }

  /// Uploads a mipmap for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  static void Upload_mipmap(
    CubeTarget target,
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) {
    gl(TexImage2D(
         target, level, internalFormat, width, height, 0, format, type, data
       ));
  }
  /// Uploads a mipmap for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  BIND_CHECKED void upload_mipmap(
    CubeTarget target,
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    CHECK_BINDING();
    Upload_mipmap(target, level, internalFormat, width, height, format, type, data);
  }


  /// Updates a part of the base image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width/height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
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
    gl(TexSubImage2D(
         target, 0, xOffset, yOffset, width, height, format, type, data
       ));
  }
  /// Updates a part of the base image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width/height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  BIND_CHECKED void subUpload(
    CubeTarget target,
    GLint xOffset,
    GLint yOffset,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    CHECK_BINDING();
    SubUpload(target, xOffset, yOffset, width, height, format, type, data);
  }

  /// Updates a part of a mipmap image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width/height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  static void SubUpload_mipmap(
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
    gl(TexSubImage2D(
         target, level, xOffset, yOffset, width, height, format, type, data
       ));
  }
  /// Updates a part of a mipmap image for one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset/yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width/height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  BIND_CHECKED void subUpload_mipmap(
    CubeTarget target,
    GLint level,
    GLint xOffset,
    GLint yOffset,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    CHECK_BINDING();
    SubUpload_mipmap(target, level, xOffset, yOffset, width, height, format, type, data);
  }

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glTexStorage2D)
  /// Simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param levels - Specify the number of texture levels.
    * @param internalFormat - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels.
    * @param height - Specifies the height of the texture, in texels. */
  static void Storage(
    CubeTarget target,
    GLsizei levels,
    GLenum internalFormat,
    GLsizei width,
    GLsizei height
  ) {
    gl(TexStorage2D(target, levels, internalFormat, width, height));
  }
  /// Simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param levels - Specify the number of texture levels.
    * @param internalFormat - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels.
    * @param height - Specifies the height of the texture, in texels. */
  BIND_CHECKED void storage(
    CubeTarget target,
    GLsizei levels,
    GLenum internalFormat,
    GLsizei width,
    GLsizei height
  ) const {
    CHECK_BINDING();
    Storage(target, levels, internalFormat, width, height);
  }
#endif // glTexStorage2D

  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  static void Copy(
    CubeTarget target,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) {
    gl(CopyTexImage2D(target, 0, internalFormat, x, y, width, height, 0));
  }
  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  BIND_CHECKED void copy(
    CubeTarget target,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) const {
    CHECK_BINDING();
    Copy(target, internalFormat, x, y, width, height);
  }

  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  static void Copy_mipmap(
    CubeTarget target,
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) {
    gl(CopyTexImage2D(target, level, internalFormat, x, y, width, height, 0));
  }
  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of one side of the cube.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  BIND_CHECKED void copy_mipmap(
    CubeTarget target,
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) const {
    CHECK_BINDING();
    Copy_mipmap(target, level, internalFormat, x, y, width, height);
  }

  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of one side with them.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  static void CopySub(
    CubeTarget target,
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) {
    gl(CopyTexSubImage2D(target, 0, xOffset, yOffset, x, y, width, height));
  }
  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of one side with them.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  BIND_CHECKED void copySub(
    CubeTarget target,
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) const {
    CHECK_BINDING();
    CopySub(target, xOffset, yOffset, x, y, width, height);
  }

  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  static void CopySub_mipmap(
    CubeTarget target,
    GLint level,
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) {
    gl(CopyTexSubImage2D(target, level, xOffset, yOffset, x, y, width, height));
  }
  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  BIND_CHECKED void copySub_mipmap(
    CubeTarget target,
    GLint level,
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) const {
    CHECK_BINDING();
    CopySub_mipmap(target, level, xOffset, yOffset, x, y, width, height);
  }

  /// Returns the width of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  static GLsizei Width(CubeTarget target, GLint level = 0) {
    GLsizei data;
    gl(GetTexLevelParameteriv(target, level, GL_TEXTURE_WIDTH, &data));
    return data;
  }
  /// Returns the width of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  BIND_CHECKED GLsizei width(CubeTarget target, GLint level = 0) const {
    CHECK_BINDING();
    return Width(target, level);
  }

  /// Returns the height of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT */
  static GLsizei Height(CubeTarget target, GLint level = 0) {
    GLsizei data;
    gl(GetTexLevelParameteriv(target, level, GL_TEXTURE_HEIGHT, &data));
    return data;
  }
  /// Returns the height of a mipmap of one side.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT */
  BIND_CHECKED GLsizei height(CubeTarget target, GLint level = 0) const {
    CHECK_BINDING();
    return Height(target, level);
  }

  /// Returns the i-th element of the cube sides in alphabetic order.
  /** @param i - The index of the CubeTarget to return */
  static CubeTarget cubeFace(int i) {
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

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glGetCompressedTexImage)
  /// Return the compressed texture image of one side
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  static void GetCompressedImage(CubeTarget target, GLint level, GLvoid* img) {
    gl(GetCompressedTexImage(target, level, img));
  }
  /// Return the compressed texture image of one side
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  BIND_CHECKED void getCompressedImage(CubeTarget target, GLint level, GLvoid* img) const {
    CHECK_BINDING();
    GetCompressedImage(target, level, img);
  }
#endif

#if OGLWRAP_USE_IMAGEMAGICK
  /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param file - Path to the image file.
    * @param formatString - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  static void LoadTexture(
    CubeTarget target,
    const std::string& file,
    const std::string& formatString = "RGBA"
  ) {
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
  /** @param target - Specifies which one of the six sides of the cube to use as target.
    * @param file - Path to the image file.
    * @param formatString - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  BIND_CHECKED void loadTexture(
    CubeTarget target,
    const std::string& file,
    const std::string& formatString = "RGBA"
  ) const {
    CHECK_BINDING();
    LoadTexture(target, file, formatString);
  }

  /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
  /** @param faceID - Specifies the index of the side to upload. It is usefully to upload all six sides in a for loop.
    * @param file - Path to the image file.
    * @param formatString - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  static void LoadTexture(
    GLuint faceID,
    const std::string& file,
    const std::string& formatString = "RGBA"
  ) {
    try {
      Magick::Image image = Magick::Image(file);
      Magick::Blob blob;
      image.write(&blob, formatString);

      Upload(
        cubeFace(faceID),
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
  /** @param faceID - Specifies the index of the side to upload. It is usefully to upload all six sides in a for loop.
    * @param file - Path to the image file.
    * @param formatString - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  BIND_CHECKED void loadTexture(
    GLuint faceID,
    const std::string& file,
    const std::string& formatString = "RGBA"
  ) const {
    CHECK_BINDING();
    LoadTexture(faceID, file, formatString);
  }
#endif
}; // End of TextureCube definition

#endif // GL_TEXTURE_CUBE_MAP

} // namespace oglwrap

#endif // OGLWRAP_TEXTURES_TEXTURE_CUBE_HPP_
