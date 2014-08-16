// Copyright (c) 2014, Tamas Csala


#ifndef OGLWRAP_TEXTURES_TEXTURE1D_H_
#define OGLWRAP_TEXTURES_TEXTURE1D_H_

#include "./texture_base.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

class Texture1D : public TextureBase {
 public:
  Texture1D() : TextureBase(TextureTarget::kTexture1D) { }
};

/// A one dimensional texture class
class BoundTexture1D : public BoundTexture {
 public:
  explicit BoundTexture1D(const Texture1D& tex) : BoundTexture(tex) {}
  BoundTexture1D(BoundTexture1D&& other) : BoundTexture(std::move(other)) {}

  /// Uploads the base image.
  void upload(PixelDataInternalFormat internal_format, GLsizei width,
              PixelDataFormat format, PixelDataType type,
              const void *data) {
    gl(TexImage1D(GL_TEXTURE_1D, 0, GLenum(internal_format), width,
                  0, GLenum(format), GLenum(type), data));
  }

  /// Uploads a mipmap of the image.
  void uploadMipmap(GLint level, PixelDataInternalFormat internal_format,
                    GLsizei width, PixelDataFormat format,
                    PixelDataType type, const void *data) {
    gl(TexImage1D(GL_TEXTURE_1D, level, GLenum(internal_format), width,
                  0, GLenum(format), GLenum(type), data));
  }

  /// Updates a part of the base image.
  void subUpload(GLint x_offset, GLsizei width, PixelDataFormat format,
                 PixelDataType type, const void *data) {
    gl(TexSubImage1D(GL_TEXTURE_1D, 0, x_offset, width,
                     GLenum(format), GLenum(type), data));
  }

  /// Updates a part of a mipmap image.
  void subUploadMipmap(GLint level, GLint x_offset, GLsizei width,
                       PixelDataFormat format, PixelDataType type,
                       const void *data) {
    gl(TexSubImage1D(GL_TEXTURE_1D, level, x_offset, width,
                     GLenum(format), GLenum(type), data));
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage1D)
  /// Simultaneously specify storage for all levels of a one-dimensional texture
  void storage(GLsizei levels, GLenum internal_format, GLsizei width) {
    gl(TexStorage1D(GL_TEXTURE_1D, levels, GLenum(internal_format), width));
  }
#endif  // glTexStorage1D

  void copy(PixelDataInternalFormat internal_format,
            GLint x, GLint y, GLsizei width) {
    gl(CopyTexImage1D(GL_TEXTURE_1D, 0, GLenum(internal_format), x, y, width, 0));
  }

  void copyMipmap(GLint level, PixelDataInternalFormat internal_format,
                  GLint x, GLint y, GLsizei width) {
    gl(CopyTexImage1D(GL_TEXTURE_1D, level, GLenum(internal_format),
                      x, y, width, 0));
  }

  void copySub(GLint x_offset, GLint x, GLint y, GLsizei width) {
    gl(CopyTexSubImage1D(GL_TEXTURE_1D, 0, x_offset, x, y, width));
  }

  void copySubMipmap(GLint level, GLint x_offset, GLint x, GLint y,
                      GLsizei width) {
    gl(CopyTexSubImage1D(GL_TEXTURE_1D, level, x_offset, x, y, width));
  }

  /// Returns the width of a mipmap of the currently bound texture of this class
  GLsizei width(GLint level = 0) const {
    GLsizei w;
    gl(GetTexLevelParameteriv(GL_TEXTURE_1D, level, GL_TEXTURE_WIDTH, &w));
    return w;
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
  /// Return a compressed texture image
  void getCompressedImage(GLint level, GLvoid* img) const {
    gl(GetCompressedTexImage(GL_TEXTURE_1D, level, img));
  }
#endif  // glGetCompressedTexImage
};

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_1D_H_
