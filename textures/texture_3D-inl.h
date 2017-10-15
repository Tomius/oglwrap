// Copyright (c) Tamas Csala

#ifndef OGLWRAP_TEXTURES_TEXTURE_3D_INL_H_
#define OGLWRAP_TEXTURES_TEXTURE_3D_INL_H_

#include "./texture_3D.h"
#include "../context/binding.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexImage3D)
template<Texture3DType texture_t>
void Texture3DBase<texture_t>::upload(PixelDataInternalFormat internal_format,
                                      GLsizei width, GLsizei height,
                                      GLsizei depth, PixelDataFormat format,
                                      PixelDataType type,
                                      const void *data) {
  OGLWRAP_CHECK_BINDING();
  OGLWRAP_CHECK_BINDLESS_TEXTURE_MODIFIED(this->bindless_handle_);
  gl(TexImage3D(GLenum(texture_t), 0, GLenum(internal_format), width, height,
                depth, 0, GLenum(format), GLenum(type), data));
}

template<Texture3DType texture_t>
void Texture3DBase<texture_t>::uploadMipmap(
    GLint level, PixelDataInternalFormat internal_format, GLsizei width,
    GLsizei height, GLsizei depth, PixelDataFormat format, PixelDataType type,
    const void *data) {
  OGLWRAP_CHECK_BINDING();
  OGLWRAP_CHECK_BINDLESS_TEXTURE_MODIFIED(this->bindless_handle_);
  gl(TexImage3D(GLenum(texture_t), level, GLenum(internal_format), width,
                height, depth, 0, GLenum(format), GLenum(type), data));
}
#endif  // glTexImage3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexSubImage3D)
template<Texture3DType texture_t>
void Texture3DBase<texture_t>::subUpload(
    GLint x_offset, GLint y_offset, GLint z_offset, GLsizei width,
    GLsizei height, GLsizei depth, PixelDataFormat format, PixelDataType type,
    const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexSubImage3D(GLenum(texture_t), 0, x_offset, y_offset, z_offset, width,
                   height, depth, GLenum(format), GLenum(type), data));
}

template<Texture3DType texture_t>
void Texture3DBase<texture_t>::subUploadMipmap(
    GLint level, GLint x_offset, GLint y_offset, GLint z_offset, GLsizei width,
    GLsizei height, GLsizei depth, PixelDataFormat format, PixelDataType type,
    const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexSubImage3D(GLenum(texture_t), level, x_offset, y_offset, z_offset, width,
                   height, depth, GLenum(format), GLenum(type), data));
}
#endif  // glTexSubImage3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCopyTexSubImage3D)
template<Texture3DType texture_t>
void Texture3DBase<texture_t>::copySub(GLint x_offset, GLint y_offset,
                                       GLint z_offset, GLint x, GLint y,
                                       GLsizei width, GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexSubImage3D(GLenum(texture_t), 0, x_offset, y_offset, z_offset, x, y,
                       width, height));
}

template<Texture3DType texture_t>
void Texture3DBase<texture_t>::copySubMipmap(GLint level, GLint x_offset,
                                             GLint y_offset, GLint z_offset,
                                             GLint x, GLint y, GLsizei width,
                                             GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexSubImage3D(GLenum(texture_t), level, x_offset, y_offset, z_offset, x,
                       y, width, height));
}
#endif  // glCopyTexSubImage3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage3D)
template<Texture3DType texture_t>
void Texture3DBase<texture_t>::storage(
    GLsizei levels, PixelDataInternalFormat internal_format, GLsizei width,
    GLsizei height, GLsizei depth) {
  OGLWRAP_CHECK_BINDING();
  OGLWRAP_CHECK_BINDLESS_TEXTURE_MODIFIED(this->bindless_handle_);
  gl(TexStorage3D(GLenum(texture_t), levels, GLenum(internal_format), width,
                  height, depth));
}
#endif  // glTexStorage3D

template<Texture3DType texture_t>
GLsizei Texture3DBase<texture_t>::width(GLint level) const {
  OGLWRAP_CHECK_BINDING();
  GLsizei data;
  gl(GetTexLevelParameteriv(GLenum(texture_t), level, GL_TEXTURE_WIDTH, &data));
  return data;
}

template<Texture3DType texture_t>
GLsizei Texture3DBase<texture_t>::height(GLint level) const {
  OGLWRAP_CHECK_BINDING();
  GLsizei data;
  gl(GetTexLevelParameteriv(GLenum(texture_t), level, GL_TEXTURE_HEIGHT, &data));
  return data;
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_DEPTH)
template<Texture3DType texture_t>
GLsizei Texture3DBase<texture_t>::depth(GLint level) const {
  OGLWRAP_CHECK_BINDING();
  GLsizei data;
  gl(GetTexLevelParameteriv(GLenum(texture_t), level, GL_TEXTURE_DEPTH, &data));
  return data;
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
template<Texture3DType texture_t>
void Texture3DBase<texture_t>::getCompressedImage(GLint level,
                                                  GLvoid* img) const {
  OGLWRAP_CHECK_BINDING();
  gl(GetCompressedTexImage(GL_TEXTURE_3D, level, img));
}
#endif

#if OGLWRAP_USE_IMAGEMAGICK && (OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage3D))
template<Texture3DType texture_t>
template<typename IterT>
void Texture3DBase<texture_t>::loadTextures(IterT files_begin, IterT files_end,
                                            std::string format_string,
                                            GLint level) {
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

    int layers_num = files_end - files_begin;
    if (layers_num <= 0) {
      std::cerr << "Texture3D::loadTextures called with 0 file names." << std::endl;
      return;
    }

    Magick::Image first_image = Magick::Image(*files_begin);
    GLsizei w = first_image.columns(), h = first_image.rows();
    int num_componenets = format_string.length();

    size_t size_per_layer = w * h * num_componenets;
    auto blob = std::unique_ptr<GLubyte>(new GLubyte[size_per_layer * layers_num]);
    first_image.write(0, 0, w, h, format_string, Magick::CharPixel, blob.get());

    for (int layer = 1; layer < layers_num; ++layer) {
      Magick::Image image = Magick::Image(*(++files_begin));
      image.write(0, 0, w, h, format_string, Magick::CharPixel,
                  blob.get() + layer*size_per_layer);
    }

    // check if image is badly aligned to GL_UNPACK_ALIGNMENT
    bool bad_alignment = (w * num_componenets) % 4 != 0;
    GLint unpack_aligment;

    if (bad_alignment) {
      gl(GetIntegerv(GL_UNPACK_ALIGNMENT, &unpack_aligment));
      gl(PixelStorei(GL_UNPACK_ALIGNMENT, 1));
    }

    // upload the first image
    uploadMipmap(level, internal_format, w, h, layers_num,
                 alpha ? PixelDataFormat::kRgba : PixelDataFormat::kRgb,
                 PixelDataType::kUnsignedByte, blob.get());

    if (bad_alignment) {
      gl(PixelStorei(GL_UNPACK_ALIGNMENT, unpack_aligment));
    }
  } catch (const Magick::Error& error) {
    std::cerr << "Error loading texture: " << error.what() << std::endl;
  }
}
#endif

#endif  // GL_TEXTURE_3D

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_3D_INL_H_
