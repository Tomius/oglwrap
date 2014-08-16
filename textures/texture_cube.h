// Copyright (c) 2014, Tamas Csala


#ifndef OGLWRAP_TEXTURES_TEXTURE_CUBE_H_
#define OGLWRAP_TEXTURES_TEXTURE_CUBE_H_

#include "./texture_base.h"
#include "../enums/texture_cube_target.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/// A set of 6 2D textures, that is used to be sampled with 3D direction vectors
class TextureCube : public TextureBase {
 public:
  TextureCube() : TextureBase(TextureTarget::kTextureCubeMap) { }
};

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
class BoundTextureCube : public BoundTexture {
 public:
  explicit BoundTextureCube(const TextureCube& tex) : BoundTexture(tex) {}
  BoundTextureCube(BoundTextureCube&& other) : BoundTexture(std::move(other)) {}

  /// Uploads one a base image for one side of the cube.
  void upload(TextureCubeTarget target, PixelDataInternalFormat internal_format,
              GLsizei width, GLsizei height, PixelDataFormat format,
              PixelDataType type, const void *data) {
    gl(TexImage2D(target_, 0, GLenum(internal_format), width, height,
                  0, GLenum(format), GLenum(type), data));
  }

  /// Uploads a mipmap for one side of the cube.
  void uploadMipmap(TextureCubeTarget target, GLint level,
                    PixelDataInternalFormat internal_format, GLsizei width,
                    GLsizei height, PixelDataFormat format, PixelDataType type,
                    const void *data) {
    gl(TexImage2D(target_, level, GLenum(internal_format), width, height,
                  0, GLenum(format), GLenum(type), data));
  }

  /// Updates a part of the base image for one side of the cube.
  void subUpload(TextureCubeTarget target, GLint x_offset, GLint y_offset,
                 GLsizei width, GLsizei height, PixelDataFormat format,
                 PixelDataType type, const void *data) {
    gl(TexSubImage2D(target_, 0, x_offset, y_offset, width, height,
                     GLenum(format), GLenum(type), data));
  }

  /// Updates a part of a mipmap image for one side of the cube.
  void subUploadMipmap(TextureCubeTarget target, GLint level, GLint x_offset,
                       GLint y_offset, GLsizei width, GLsizei height,
                       PixelDataFormat format, PixelDataType type,
                       const void *data) {
    gl(TexSubImage2D(target_, level, x_offset, y_offset, width,
                     height, GLenum(format), GLenum(type), data));
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage2D)
  /// Simultaneously specify storage for all levels of a two-dimensional or one-dimensional array texture
  void storage(TextureCubeTarget target, GLsizei levels, GLenum internal_format,
               GLsizei width, GLsizei height) {
    gl(TexStorage2D(target_, levels, GLenum(internal_format),
                    width, height));
  }
#endif  // glTexStorage2D

  /// Copies pixels from the current GL_READ_BUFFER into the base mipmap of one side of the cube.
  void copy(TextureCubeTarget target, PixelDataInternalFormat internal_format,
            GLint x, GLint y, GLsizei width, GLsizei height) {
    gl(CopyTexImage2D(target_, 0, GLenum(internal_format),
                      x, y, width, height, 0));
  }

  /// Copies pixels from the current GL_READ_BUFFER into a mipmap of one side of the cube.
  void copyMipmap(TextureCubeTarget target, GLint level,
                  PixelDataInternalFormat internal_format, GLint x, GLint y,
                  GLsizei width, GLsizei height) {
    gl(CopyTexImage2D(target_, level, GLenum(internal_format),
                      x, y, width, height, 0));
  }

  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of one side with them.
  void copySub(TextureCubeTarget target, GLint x_offset, GLint y_offset,
               GLint x, GLint y, GLsizei width, GLsizei height) {
    gl(CopyTexSubImage2D(target_, 0, x_offset, y_offset,
                         x, y, width, height));
  }

  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of one side.
  void copySubMipmap(TextureCubeTarget target, GLint level, GLint x_offset,
                     GLint y_offset, GLint x, GLint y, GLsizei width,
                     GLsizei height) {
    gl(CopyTexSubImage2D(target_, level, x_offset, y_offset,
                         x, y, width, height));
  }

  /// Returns the width of a mipmap of one side.
  GLsizei width(TextureCubeTarget target, GLint level = 0) const {
    GLsizei data;
    gl(GetTexLevelParameteriv(target_, level, GL_TEXTURE_WIDTH, &data));
    return data;
  }

  /// Returns the height of a mipmap of one side.
  GLsizei height(TextureCubeTarget target, GLint level = 0) const {
    GLsizei data;
    gl(GetTexLevelParameteriv(target_, level, GL_TEXTURE_HEIGHT, &data));
    return data;
  }

  /// Returns the i-th element of the cube sides in alphabetic order.
  static TextureCubeTarget cubeFace(int face_id) {
    switch (face_id) {
      case 0: return TextureCubeTarget::kTextureCubeMapPositiveX;
      case 1: return TextureCubeTarget::kTextureCubeMapNegativeX;
      case 2: return TextureCubeTarget::kTextureCubeMapPositiveY;
      case 3: return TextureCubeTarget::kTextureCubeMapNegativeY;
      case 4: return TextureCubeTarget::kTextureCubeMapPositiveZ;
      case 5: return TextureCubeTarget::kTextureCubeMapNegativeZ;
      default: throw std::invalid_argument(
          "CubeFace argument must be between 0 and 5");
    }
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
  /// Return the compressed texture image of one side
  void getCompressedImage(TextureCubeTarget target,
                          GLint level, GLvoid* img) const {
    gl(GetCompressedTexImage(target_, level, img));
  }
#endif

#if OGLWRAP_USE_IMAGEMAGICK
  /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
  void loadTexture(TextureCubeTarget target, const std::string& file,
                   std::string format_string = "CSRGBA") {
    try {
    bool srgb{false}, compressed{false}, alpha{false};
    size_t s_pos = format_string.find('S');
    if( s_pos != std::string::npos) {
      srgb = true;
      format_string.erase(s_pos, 1);
    }
    size_t c_pos = format_string.find('C');
    if (c_pos != std::string::npos) {
      compressed = true;
      format_string.erase(c_pos, 1);
    }
    alpha = format_string.find('A') != std::string::npos;

    Magick::Image image = Magick::Image(file);
    Magick::Blob blob;
    image.write(&blob, format_string);

    using InternalFormat = PixelDataInternalFormat;
    InternalFormat internal_format =
      srgb ? (compressed ? (alpha ? InternalFormat::kCompressedSrgbAlpha
                                  : InternalFormat::kCompressedSrgb)
                         : (alpha ? InternalFormat::kSrgb8Alpha8
                                  : InternalFormat::kSrgb8))
           : (compressed ? (alpha ? InternalFormat::kCompressedRgba
                                  : InternalFormat::kCompressedRgb)
                         : (alpha ? InternalFormat::kRgba8
                                  : InternalFormat::kRgb8));

    bool bad_alignment = (image.columns() * format_string.length()) % 4 != 0;
    GLint unpack_aligment;

    if (bad_alignment) {
      gl(GetIntegerv(GL_UNPACK_ALIGNMENT, &unpack_aligment));
      gl(PixelStorei(GL_UNPACK_ALIGNMENT, 1));
    }

    upload(target, internal_format, image.columns(), image.rows(),
           alpha ? PixelDataFormat::kRgba : PixelDataFormat::kRgb,
           PixelDataType::kUnsignedByte, blob.data());

    if (bad_alignment) {
      gl(PixelStorei(GL_UNPACK_ALIGNMENT, unpack_aligment));
    }
  } catch (const Magick::Error& error) {
    std::cerr << "Error loading texture: " << error.what() << std::endl;
  }
}

  /// Loads in, and uploads an image for one side of the cube from a file using Magick++.
  void loadTexture(GLuint face_id, const std::string& file,
                   std::string format_string = "CSRGBA") {
    loadTexture(cubeFace(face_id), file, format_string);
  }
#endif
};

#endif  // GL_TEXTURE_CUBE_MAP

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_CUBE_H_
