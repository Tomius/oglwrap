// Copyright (c) 2014, Tamas Csala

/** @file texture_2D.h
    @brief Implements two-dimensional, non-cubeMap textures.
*/

#ifndef OGLWRAP_TEXTURES_TEXTURE_2D_H_
#define OGLWRAP_TEXTURES_TEXTURE_2D_H_

#include "texture_base.h"
#include "../enums/texture2D_type.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

// -------======{[ 2D Textures' declaration ]}======-------

template<Texture2DType texture_t>
/// The base class describing functionality for all 2D textures.
/** You should rather use the typedefed versions than this template. */
class Texture2DBase : public TextureBase<TextureType(texture_t)> {
public:
  using TextureBase<TextureType(texture_t)>::isBound;
  using TextureBase<TextureType(texture_t)>::bind;

  /// Uploads the base image.
  /** @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  static void Upload(
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) {
    gl(TexImage2D(
      GLenum(texture_t), 0, GLenum(internalFormat),
      width, height, 0, GLenum(format), GLenum(type), data
    ));
  }
  /// Uploads the base image.
  /** @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  BIND_CHECKED void upload(
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    OGLWRAP_CHECK_BINDING();
    Upload(internalFormat, width, height, format, type, data);
  }

  /// Uploads a mipmap of the image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  static void UploadMipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) {
    gl(TexImage2D(
      GLenum(texture_t), level, GLenum(internalFormat),
      width, height, 0, GLenum(format), GLenum(type), data
    ));
  }
  /// Uploads a mipmap of the image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the number, order, and size of the color components in the texture.
    * @param width - Specifies the width of the texture image. All implementations support texture images that are at least 1024 texels wide.
    * @param height - Specifies the height of the texture image, or the number of layers in a texture array. All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that are at least 256 layers deep.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexImage2D */
  BIND_CHECKED void uploadMipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    OGLWRAP_CHECK_BINDING();
    UploadMipmap(level, internalFormat, width, height, format, type, data);
  }

  /// Updates a part of the base image.
  /** @param xOffset, yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width, height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  static void SubUpload(
    GLint xOffset,
    GLint yOffset,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) {
    gl(TexSubImage2D(
      GLenum(texture_t), 0, xOffset, yOffset,
      width, height, GLenum(format), GLenum(type), data
    ));
  }
  /// Updates a part of the base image.
  /** @param xOffset, yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width, height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  BIND_CHECKED void subUpload(
    GLint xOffset,
    GLint yOffset,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    OGLWRAP_CHECK_BINDING();
    SubUpload(xOffset, yOffset, width, height, format, type, data);
  }

  /// Updates a part of a mipmap image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset, yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width, height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  static void SubUploadMipmap(
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
      GLenum(texture_t), level, xOffset, yOffset,
      width, height, GLenum(format), GLenum(type), data
    ));
  }
  /// Updates a part of a mipmap image.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset, yOffset - Specifies a texel offset in the x/y direction within the texture array.
    * @param width, height - Specifies the width/height of the texture subimage.
    * @param format - Specifies the format of the pixel data.
    * @param type - Specifies the data type of the pixel data.
    * @param data - Specifies a pointer to the image data in memory.
    * @see glTexSubImage2D */
  BIND_CHECKED void subUploadMipmap(
    GLint level,
    GLint xOffset,
    GLint yOffset,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
  ) const {
    OGLWRAP_CHECK_BINDING();
    SubUploadMipmap(level, xOffset, yOffset, width, height, format, type, data);
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage2D)
  /// Simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
  /** @param levels - Specify the number of texture levels.
    * @param internalFormat - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels.
    * @param height - Specifies the height of the texture, in texels. */
  static void Storage(
    GLsizei levels,
    GLenum internalFormat,
    GLsizei width,
    GLsizei height
  ) {
    gl(TexStorage2D(
      GLenum(texture_t), levels, GLenum(internalFormat), width, height
    ));
  }
  /// Simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
  /** @param levels - Specify the number of texture levels.
    * @param internalFormat - Specifies the sized internal format to be used to store texture image data.
    * @param width - Specifies the width of the texture, in texels.
    * @param height - Specifies the height of the texture, in texels. */
  BIND_CHECKED void storage(
    GLsizei levels,
    GLenum internalFormat,
    GLsizei width,
    GLsizei height
  ) const {
    OGLWRAP_CHECK_BINDING();
    Storage(levels, internalFormat, width, height);
  }
#endif  // glTexStorage2D

  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of this texture.
  /** @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  static void Copy(
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) {
    gl(CopyTexImage2D(
      GLenum(texture_t), 0, GLenum(internalFormat), x, y, width, height, 0
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of this texture.
  /** @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  BIND_CHECKED void copy(
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) const {
    OGLWRAP_CHECK_BINDING();
    Copy(internalFormat, x, y, width, height);
  }

  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of this texture.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  static void CopyMipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) {
    gl(CopyTexImage2D(
      GLenum(texture_t), level, GLenum(internalFormat), x, y, width, height, 0
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of this texture.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param internalFormat - Specifies the internal format of the texture.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexImage2D */
  BIND_CHECKED void copyMipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) const {
    OGLWRAP_CHECK_BINDING();
    CopyMipmap(level, internalFormat, x, y, width, height);
  }

  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
  /** @param xOffset, yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  static void CopySub(
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) {
    gl(CopyTexSubImage2D(
      GLenum(texture_t), 0, xOffset, yOffset, x, y, width, height
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
  /** @param xOffset, yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  BIND_CHECKED void copySub(
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) const {
    OGLWRAP_CHECK_BINDING();
    CopySub(xOffset, yOffset, x, y, width, height);
  }

  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  static void CopySubMipmap(
    GLint level,
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) {
    gl(CopyTexSubImage2D(
      GLenum(texture_t), level, xOffset, yOffset, x, y, width, height
    ));
  }
  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture.
  /** @param level - Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param xOffset/yOffset - Specifies the texel offset in the x/y direction within the destination texture array.
    * @param x, y - Specify the window coordinates of the left corner of the row of pixels to be copied.
    * @param width/height - Specifies the width/height of the texture to copy.
    * @see glCopyTexSubImage2D */
  BIND_CHECKED void copySubMipmap(
    GLint level,
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
  ) const {
    OGLWRAP_CHECK_BINDING();
    CopySubMipmap(level, xOffset, yOffset, x, y, width, height);
  }

  /// Returns the width of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  static GLsizei Width(GLint level = 0) {
    GLsizei data;
    gl(GetTexLevelParameteriv(GLenum(texture_t), level, GL_TEXTURE_WIDTH, &data));
    return data;
  }
  /// Returns the width of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_WIDTH */
  BIND_CHECKED GLsizei width(GLint level = 0) const {
    OGLWRAP_CHECK_BINDING();
    return Width(level);
  }

  /// Returns the height of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT */
  static GLsizei Height(GLint level = 0) {
    GLsizei data;
    gl(GetTexLevelParameteriv(GLenum(texture_t), level, GL_TEXTURE_HEIGHT, &data));
    return data;
  }
  /// Returns the height of a mipmap of the currently bound texture of this class.
  /** @param level - Specifies the mipmap whose size should be queried.
    * @see glGetTexLevelParameteriv, GL_TEXTURE_HEIGHT */
  BIND_CHECKED GLsizei height(GLint level = 0) const {
    OGLWRAP_CHECK_BINDING();
    return Height(level);
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
  /// Return a compressed texture image
  /** @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  static void GetCompressedImage(GLint level, GLvoid* img) {
    gl(GetCompressedTexImage(GL_TEXTURE_2D, level, img));
  }
  /// Return a compressed texture image
  /** @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param img - Returns the compressed texture image.
    * @see glGetCompressedTexImage */
  BIND_CHECKED void getCompressedImage(GLint level, GLvoid* img) const {
    OGLWRAP_CHECK_BINDING();
    GetCompressedImage(level, img);
  }
#endif  // glGetCompressedTexImage

#if OGLWRAP_USE_IMAGEMAGICK
  /// Loads in, and uploads an image from a file using Magick++.
  /** @param file - Path to the image file.
    * @param format_string - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  static void LoadTexture(const std::string& file,
                          std::string format_string = "CSRGBA") {
    try {
      bool srgb{false}, compressed{false};
      size_t s_pos = format_string.find('S');
      if(s_pos != std::string::npos) {
        srgb = true;
        format_string.erase(format_string.begin() + s_pos);
      }
      size_t c_pos = format_string.find('C');
      if(c_pos != std::string::npos) {
        compressed = true;
        format_string.erase(format_string.begin() + c_pos);
      }

      Magick::Image image = Magick::Image(file);
      Magick::Blob blob;
      image.write(&blob, format_string);

      using InternalFormat = PixelDataInternalFormat;
      InternalFormat internal_format =
        srgb ? (compressed ? InternalFormat::kCompressedSrgbAlpha :
                             InternalFormat::kSrgb8Alpha8) :
               (compressed ? InternalFormat::kCompressedRgba :
                             InternalFormat::kRgba8);

      bool bad_alignment = (image.columns() * format_string.length()) % 4 != 0;
      GLint unpack_aligment;

      if(bad_alignment) {
        gl(GetIntegerv(GL_UNPACK_ALIGNMENT, &unpack_aligment));
        gl(PixelStorei(GL_UNPACK_ALIGNMENT, 1));
      }

      Upload(
        internal_format,
        image.columns(),
        image.rows(),
        PixelDataFormat::kRgba,
        PixelDataType::kUnsignedByte,
        blob.data()
      );

      if(bad_alignment) {
        gl(PixelStorei(GL_UNPACK_ALIGNMENT, unpack_aligment));
      }
    } catch(Magick::Error& Error) {
      std::cerr << "Error loading texture: " << Error.what() << std::endl;
    }
  }
  /// Loads in, and uploads an image from a file using Magick++.
  /** @param file - Path to the image file.
    * @param format_string - Specifies the number and order of components to be read.
    * @see glTexImage2D */
  BIND_CHECKED void loadTexture(const std::string& file,
                                const std::string& format_string = "CSRGBA") const {
    OGLWRAP_CHECK_BINDING();
    LoadTexture(file, format_string);
  }
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

} // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_2D_H_
