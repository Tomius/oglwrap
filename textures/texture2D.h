// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_TEXTURES_TEXTURE2D_H_
#define OGLWRAP_TEXTURES_TEXTURE2D_H_

#include "./texture_base.h"
#include "../enums/texture2D_target.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

class Texture2DBase : public TextureBase {
  using TextureBase::TextureBase;
};

class Texture2D : public Texture2DBase {
 public:
  Texture2D() : Texture2DBase(TextureTarget::kTexture2D) { }
};

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
class TextureRect : public Texture2DBase {
 public:
  TextureRect() : Texture2DBase(TextureTarget::kTextureRectangle) { }
};
#endif  // GL_TEXTURE_RECTANGLE

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
class Texture1DArray : public Texture2DBase {
 public:
  Texture1DArray() : Texture2DBase(TextureTarget::kTexture1DArray) { }
};
#endif  // GL_TEXTURE_1D_ARRAY

/// The base class describing functionality for all 2D textures.
class BoundTexture2D : public BoundTexture {
 public:
  explicit BoundTexture2D(const Texture2DBase& tex) : BoundTexture(tex) {}
  BoundTexture2D(BoundTexture2D&& other) : BoundTexture(std::move(other)) {}

  /// Uploads the base image.
  void upload(PixelDataInternalFormat internal_format, GLsizei width,
              GLsizei height, PixelDataFormat format, PixelDataType type,
              const void *data) {
    gl(TexImage2D(target_, 0, GLenum(internal_format), width, height, 0,
                  GLenum(format), GLenum(type), data));
  }

  /// Uploads a mipmap of the image.
  void uploadMipmap(GLint level, PixelDataInternalFormat internal_format,
                    GLsizei width, GLsizei height, PixelDataFormat format,
                    PixelDataType type, const void *data) {
    gl(TexImage2D(target_, level, GLenum(internal_format), width, height, 0,
                  GLenum(format), GLenum(type), data));
  }

  /// Updates a part of the base image.
  void subUpload(GLint x_offset, GLint y_offset, GLsizei width, GLsizei height,
                 PixelDataFormat format, PixelDataType type,
                 const void *data) {
    gl(TexSubImage2D(target_, 0, x_offset, y_offset, width, height,
                     GLenum(format), GLenum(type), data));
  }

  /// Updates a part of a mipmap image.
  void subUploadMipmap(GLint level, GLint x_offset, GLint y_offset,
                       GLsizei width, GLsizei height, PixelDataFormat format,
                       PixelDataType type, const void *data) {
    gl(TexSubImage2D(target_, level, x_offset, y_offset, width, height,
                     GLenum(format), GLenum(type), data));
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage2D)
  void storage(GLsizei levels, GLenum internal_format, GLsizei width,
               GLsizei height) {
    gl(TexStorage2D(target_, levels, GLenum(internal_format), width, height));
  }
#endif  // glTexStorage2D

  void copy(PixelDataInternalFormat internal_format, GLint x, GLint y,
            GLsizei width, GLsizei height) {
    gl(CopyTexImage2D(target_, 0, GLenum(internal_format),
                      x, y, width, height, 0));
  }

  void copyMipmap(GLint level, PixelDataInternalFormat internal_format,
                  GLint x, GLint y, GLsizei width, GLsizei height) {
    gl(CopyTexImage2D(target_, level, GLenum(internal_format),
                      x, y, width, height, 0));
  }

  void copySub(GLint x_offset, GLint y_offset, GLint x, GLint y,
               GLsizei width, GLsizei height) {
    gl(CopyTexSubImage2D(target_, 0, x_offset, y_offset, x, y, width, height));
  }

  void copySubMipmap(GLint level, GLint x_offset, GLint y_offset,
                     GLint x, GLint y, GLsizei width, GLsizei height) {
    gl(CopyTexSubImage2D(target_, level, x_offset, y_offset,
                         x, y, width, height));
  }

  GLsizei width(GLint level = 0) const {
    GLsizei data;
    gl(GetTexLevelParameteriv(target_, level, GL_TEXTURE_WIDTH, &data));
    return data;
  }

  GLsizei height(GLint level = 0) const {
    GLsizei data;
    gl(GetTexLevelParameteriv(target_, level, GL_TEXTURE_HEIGHT, &data));
    return data;
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
  void getCompressedImage(GLint level, GLvoid* img) const {
    gl(GetCompressedTexImage(GL_TEXTURE_2D, level, img));
  }
#endif  // glGetCompressedTexImage

#if OGLWRAP_USE_IMAGEMAGICK
  // Loads in, and uploads an image from a file using Magick++.
  void loadTexture(const std::string& file,
                   std::string format_string = "CSRGBA") {
    try {
      bool srgb{false}, compressed{false}, alpha{false};
      size_t s_pos = format_string.find('S');
      if (s_pos != std::string::npos) {
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

      upload(internal_format, image.columns(), image.rows(),
             alpha ? PixelDataFormat::kRgba : PixelDataFormat::kRgb,
             PixelDataType::kUnsignedByte, blob.data());

      if (bad_alignment) {
        gl(PixelStorei(GL_UNPACK_ALIGNMENT, unpack_aligment));
      }
    } catch (const Magick::Error& error) {
      std::cerr << "Error loading texture: " << error.what() << std::endl;
    }
  }
#endif
};

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_2D_H_
