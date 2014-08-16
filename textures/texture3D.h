// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_TEXTURES_TEXTURE3D_H_
#define OGLWRAP_TEXTURES_TEXTURE3D_H_

#include "./texture_base.h"
#include "../enums/texture3D_target.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)

class Texture3DBase : public TextureBase {
  using TextureBase::TextureBase;
};

class Texture3D : public Texture3DBase {
 public:
  Texture3D() : Texture3DBase(TextureTarget::kTexture3D) { }
};

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
class Texture2DArray : public Texture3DBase {
 public:
  Texture2DArray() : Texture3DBase(TextureTarget::kTexture2DArray) { }
};
#endif  // GL_TEXTURE_1D_ARRAY

/// The base class describing functionality for all 2D textures.
class BoundTexture3D : public BoundTexture {
 public:
  explicit BoundTexture3D(const Texture3DBase& tex) : BoundTexture(tex) {}
  BoundTexture3D(BoundTexture3D&& other) : BoundTexture(std::move(other)) {}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexImage3D)
  /// Uploads the base image.
  void upload(PixelDataInternalFormat internal_format, GLsizei width,
              GLsizei height, GLsizei depth, PixelDataFormat format,
              PixelDataType type, const void *data) {
    gl(TexImage3D(target_, 0, GLenum(internal_format), width, height,
                  depth, 0, GLenum(format), GLenum(type), data));
  }

  /// Uploads a mipmap of the image.
  void uploadMipmap(GLint level, PixelDataInternalFormat internal_format,
                    GLsizei width, GLsizei height, GLsizei depth,
                    PixelDataFormat format, PixelDataType type,
                    const void *data) {
    gl(TexImage3D(target_, level, GLenum(internal_format), width,
                  height, depth, 0, GLenum(format), GLenum(type), data));
  }
#endif  // glTexImage3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexSubImage3D)
  /// Updates a part of the base image.
  void subUpload(GLint x_offset, GLint y_offset, GLint z_offset, GLsizei width,
                 GLsizei height, GLsizei depth, PixelDataFormat format,
                 PixelDataType type, const void *data) {
     gl(TexSubImage3D(target_, 0, x_offset, y_offset, z_offset, width,
                      height, depth, GLenum(format), GLenum(type), data));
  }

  /// Updates a part of a mipmap image.
  void subUploadMipmap(GLint level, GLint x_offset, GLint y_offset, GLint z_offset,
                       GLsizei width, GLsizei height, GLsizei depth,
                       PixelDataFormat format, PixelDataType type,
                       const void *data) {
     gl(TexSubImage3D(target_, level, x_offset, y_offset, z_offset, width,
                      height, depth, GLenum(format), GLenum(type), data));
  }
#endif  // glTexSubImage3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCopyTexSubImage3D)
  /// Copies pixels from the current GL_READ_BUFFER and updates part of the base mipmap of this texture with them.
  void copySub(GLint x_offset, GLint y_offset, GLint z_offset, GLint x, GLint y,
               GLsizei width, GLsizei height) {
    gl(CopyTexSubImage3D(target_, 0, x_offset, y_offset, z_offset, x, y,
                         width, height));
  }

  /// Copies pixels from the current GL_READ_BUFFER and updates part of a mipmap of this texture.
  void copySubMipmap(GLint level, GLint x_offset, GLint y_offset, GLint z_offset,
                     GLint x, GLint y, GLsizei width, GLsizei height) {
    gl(CopyTexSubImage3D(target_, level, x_offset, y_offset, z_offset, x,
                         y, width, height));
  }
#endif  // glCopyTexSubImage3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage3D)
  /// Simultaneously specify storage for all levels of a three-dimensional, two-dimensional array or cube-map array texture.
  void storage(GLsizei levels, PixelDataInternalFormat internal_format,
               GLsizei width, GLsizei height, GLsizei depth) {
    gl(TexStorage3D(target_, levels, GLenum(internal_format), width,
                    height, depth));
  }
#endif  // glTexStorage3D

  /// Returns the width of a mipmap of the currently bound texture of this class.
  GLsizei width(GLint level = 0) const {
    GLsizei data;
    gl(GetTexLevelParameteriv(target_, level, GL_TEXTURE_WIDTH, &data));
    return data;
  }

  /// Returns the height of a mipmap of the currently bound texture of this class.
  GLsizei height(GLint level = 0) const {
    GLsizei data;
    gl(GetTexLevelParameteriv(target_, level, GL_TEXTURE_HEIGHT, &data));
    return data;
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_DEPTH)
  /// Returns the depth of a mipmap of the currently bound texture of this class.
  GLsizei depth(GLint level = 0) const {
    GLsizei data;
    gl(GetTexLevelParameteriv(target_, level, GL_TEXTURE_DEPTH, &data));
    return data;
  }
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
  /// Return a compressed texture image
  void getCompressedImage(GLint level, GLvoid* img) const {
    gl(GetCompressedTexImage(GL_TEXTURE_3D, level, img));
  }
#endif
};

#endif  // GL_TEXTURE_3D

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_3D_H_
