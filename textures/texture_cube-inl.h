// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_TEXTURES_TEXTURE_CUBE_INL_H_
#define OGLWRAP_TEXTURES_TEXTURE_CUBE_INL_H_

#include <string>
#include "./texture_cube.h"
#include "../context/binding.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
inline void TextureCube::upload(TextureCubeTarget target,
                                PixelDataInternalFormat internal_format,
                                GLsizei width, GLsizei height,
                                PixelDataFormat format, PixelDataType type,
                                const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexImage2D(GLenum(target), 0, GLenum(internal_format), width, height,
                0, GLenum(format), GLenum(type), data));
}

inline void TextureCube::uploadMipmap(TextureCubeTarget target, GLint level,
                                      PixelDataInternalFormat internal_format,
                                      GLsizei width, GLsizei height,
                                      PixelDataFormat format,
                                      PixelDataType type,
                                      const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexImage2D(GLenum(target), level, GLenum(internal_format), width, height,
                0, GLenum(format), GLenum(type), data));
}

inline void TextureCube::subUpload(TextureCubeTarget target, GLint x_offset,
                                   GLint y_offset, GLsizei width, GLsizei height,
                                   PixelDataFormat format, PixelDataType type,
                                   const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexSubImage2D(GLenum(target), 0, x_offset, y_offset, width, height,
                   GLenum(format), GLenum(type), data));
}

inline void TextureCube::subUploadMipmap(TextureCubeTarget target, GLint level,
                                         GLint x_offset, GLint y_offset,
                                         GLsizei width, GLsizei height,
                                         PixelDataFormat format,
                                         PixelDataType type,
                                         const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexSubImage2D(GLenum(target), level, x_offset, y_offset, width,
                   height, GLenum(format), GLenum(type), data));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage2D)
inline void TextureCube::storage(TextureCubeTarget target, GLsizei levels,
                                 GLenum internal_format, GLsizei width,
                                 GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(TexStorage2D(GLenum(target), levels, GLenum(internal_format),
                  width, height));
}
#endif  // glTexStorage2D

inline void TextureCube::copy(TextureCubeTarget target,
                              PixelDataInternalFormat internal_format, GLint x,
                              GLint y, GLsizei width, GLsizei height) {
  OGLWRAP_CHECK_BINDING();
   gl(CopyTexImage2D(GLenum(target), 0, GLenum(internal_format),
                     x, y, width, height, 0));
}

inline void TextureCube::copyMipmap(TextureCubeTarget target, GLint level,
                                    PixelDataInternalFormat internal_format,
                                    GLint x, GLint y, GLsizei width,
                                    GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexImage2D(GLenum(target), level, GLenum(internal_format),
                    x, y, width, height, 0));
}

inline void TextureCube::copySub(TextureCubeTarget target, GLint x_offset,
                                 GLint y_offset, GLint x, GLint y,
                                 GLsizei width, GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexSubImage2D(GLenum(target), 0, x_offset, y_offset,
                       x, y, width, height));
}

inline void TextureCube::copySubMipmap(TextureCubeTarget target, GLint level,
                                       GLint x_offset, GLint y_offset, GLint x,
                                       GLint y, GLsizei width,
                                       GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexSubImage2D(GLenum(target), level, x_offset, y_offset,
                   x, y, width, height));
}

inline GLsizei TextureCube::width(TextureCubeTarget target, GLint level) const {
  OGLWRAP_CHECK_BINDING();
  GLsizei data;
  gl(GetTexLevelParameteriv(GLenum(target), level, GL_TEXTURE_WIDTH, &data));
  return data;
}

inline GLsizei TextureCube::height(TextureCubeTarget target, GLint level) const {
  OGLWRAP_CHECK_BINDING();
  GLsizei data;
  gl(GetTexLevelParameteriv(GLenum(target), level, GL_TEXTURE_HEIGHT, &data));
  return data;
}

inline TextureCubeTarget TextureCube::cubeFace(int face_id) {
  switch (face_id) {
    case 0: return TextureCubeTarget::kTextureCubeMapPositiveX;
    case 1: return TextureCubeTarget::kTextureCubeMapNegativeX;
    case 2: return TextureCubeTarget::kTextureCubeMapPositiveY;
    case 3: return TextureCubeTarget::kTextureCubeMapNegativeY;
    case 4: return TextureCubeTarget::kTextureCubeMapPositiveZ;
    case 5: return TextureCubeTarget::kTextureCubeMapNegativeZ;
    default:
      throw std::invalid_argument("CubeFace argument must be between 0 and 5");
  }
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
inline void TextureCube::getCompressedImage(TextureCubeTarget target,
                                            GLint level, GLvoid* img) const {
  OGLWRAP_CHECK_BINDING();
  gl(GetCompressedTexImage(GLenum(target), level, img));
}
#endif

#if OGLWRAP_USE_IMAGEMAGICK
inline void TextureCube::loadTexture(TextureCubeTarget target,
                                     const std::string& file,
                                     std::string format_string) {
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

inline void TextureCube::loadTexture(GLuint face_id, const std::string& file,
                                    std::string format_string) {
  loadTexture(cubeFace(face_id), file, format_string);
}
#endif

#endif  // GL_TEXTURE_CUBE_MAP

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_CUBE_INL_H_
