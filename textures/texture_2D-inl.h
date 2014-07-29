// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_TEXTURES_TEXTURE_2D_INL_H_
#define OGLWRAP_TEXTURES_TEXTURE_2D_INL_H_

#include "./texture_2D.h"
#include "../context/binding.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

template<Texture2DType texture_t>
void Texture2DBase<texture_t>::upload(
    PixelDataInternalFormat internal_format, GLsizei width, GLsizei height,
    PixelDataFormat format, PixelDataType type, const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexImage2D(GLenum(texture_t), 0, GLenum(internal_format),
                width, height, 0, GLenum(format), GLenum(type), data));
}

template<Texture2DType texture_t>
void Texture2DBase<texture_t>::uploadMipmap(
    GLint level, PixelDataInternalFormat internal_format, GLsizei width,
    GLsizei height, PixelDataFormat format, PixelDataType type,
    const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexImage2D(GLenum(texture_t), level, GLenum(internal_format),
                width, height, 0, GLenum(format), GLenum(type), data));
}

template<Texture2DType texture_t>
void Texture2DBase<texture_t>::subUpload(
    GLint x_offset, GLint y_offset, GLsizei width, GLsizei height,
    PixelDataFormat format, PixelDataType type, const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexSubImage2D(GLenum(texture_t), 0, x_offset, y_offset,
                   width, height, GLenum(format), GLenum(type), data));
}

template<Texture2DType texture_t>
void Texture2DBase<texture_t>::subUploadMipmap(
    GLint level, GLint x_offset, GLint y_offset, GLsizei width, GLsizei height,
    PixelDataFormat format, PixelDataType type, const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexSubImage2D(GLenum(texture_t), level, x_offset, y_offset,
                   width, height, GLenum(format), GLenum(type), data));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage2D)
template<Texture2DType texture_t>
void Texture2DBase<texture_t>::storage(GLsizei levels, GLenum internal_format,
                                       GLsizei width, GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(TexStorage2D(GLenum(texture_t), levels, GLenum(internal_format),
                  width, height));
}
#endif  // glTexStorage2D

template<Texture2DType texture_t>
void Texture2DBase<texture_t>::copy(
    PixelDataInternalFormat internal_format, GLint x, GLint y,
    GLsizei width, GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexImage2D(GLenum(texture_t), 0, GLenum(internal_format),
                    x, y, width, height, 0));
}

template<Texture2DType texture_t>
void Texture2DBase<texture_t>::copyMipmap(
    GLint level, PixelDataInternalFormat internal_format, GLint x, GLint y,
    GLsizei width, GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexImage2D(GLenum(texture_t), level, GLenum(internal_format),
                    x, y, width, height, 0));
}

template<Texture2DType texture_t>
void Texture2DBase<texture_t>::copySub(
    GLint x_offset, GLint y_offset, GLint x,
    GLint y, GLsizei width, GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexSubImage2D(GLenum(texture_t), 0, x_offset, y_offset,
                       x, y, width, height));
}

template<Texture2DType texture_t>
void Texture2DBase<texture_t>::copySubMipmap(
    GLint level, GLint x_offset, GLint y_offset,
    GLint x, GLint y, GLsizei width, GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexSubImage2D(GLenum(texture_t), level, x_offset, y_offset,
                       x, y, width, height));
}

template<Texture2DType texture_t>
GLsizei Texture2DBase<texture_t>::width(GLint level) const {
  OGLWRAP_CHECK_BINDING();
  GLsizei data;
  gl(GetTexLevelParameteriv(GLenum(texture_t), level, GL_TEXTURE_WIDTH, &data));
  return data;
}

template<Texture2DType texture_t>
GLsizei Texture2DBase<texture_t>::height(GLint level) const {
  OGLWRAP_CHECK_BINDING();
  GLsizei data;
  gl(GetTexLevelParameteriv(GLenum(texture_t), level, GL_TEXTURE_HEIGHT, &data));
  return data;
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
template<Texture2DType texture_t>
void Texture2DBase<texture_t>::getCompressedImage(GLint level,
                                                  GLvoid* img) const {
  OGLWRAP_CHECK_BINDING();
  gl(GetCompressedTexImage(GL_TEXTURE_2D, level, img));
}
#endif  // glGetCompressedTexImage

#if OGLWRAP_USE_IMAGEMAGICK
template<Texture2DType texture_t>
void Texture2DBase<texture_t>::loadTexture(const std::string& file,
                                          std::string format_string) {
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

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_2D_INL_H_
