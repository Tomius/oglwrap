// Copyright (c) 2014, Tamas Csala

/** @file texture_1D.h
    @brief Implements one-dimensional textures.
*/

#ifndef OGLWRAP_TEXTURES_TEXTURE_1D_INL_H_
#define OGLWRAP_TEXTURES_TEXTURE_1D_INL_H_

#include "./texture_1D.h"
#include "../context/binding.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

inline void Texture1D::upload(PixelDataInternalFormat internal_format,
                              GLsizei width, PixelDataFormat format,
                              PixelDataType type, const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexImage1D(GL_TEXTURE_1D, 0, GLenum(internal_format), width,
                0, GLenum(format), GLenum(type), data));
}

inline void Texture1D::uploadMipmap(GLint level,
                                    PixelDataInternalFormat internal_format,
                                    GLsizei width, PixelDataFormat format,
                                    PixelDataType type, const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexImage1D(GL_TEXTURE_1D, level, GLenum(internal_format), width,
                0, GLenum(format), GLenum(type), data));
}

inline void Texture1D::subUpload(GLint x_offset, GLsizei width,
                                 PixelDataFormat format, PixelDataType type,
                                 const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexSubImage1D(GL_TEXTURE_1D, 0, x_offset, width,
                   GLenum(format), GLenum(type), data));
}

inline void Texture1D::subUploadMipmap(GLint level, GLint x_offset,
                                       GLsizei width, PixelDataFormat format,
                                       PixelDataType type,
                                       const void *data) {
  OGLWRAP_CHECK_BINDING();
  gl(TexSubImage1D(GL_TEXTURE_1D, level, x_offset, width,
                   GLenum(format), GLenum(type), data));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexStorage1D)
inline void Texture1D::storage(GLsizei levels, GLenum internal_format,
                               GLsizei width) {
  OGLWRAP_CHECK_BINDING();
  gl(TexStorage1D(GL_TEXTURE_1D, levels, GLenum(internal_format), width));
}
#endif  // glTexStorage1D

inline void Texture1D::copy(PixelDataInternalFormat internal_format,
                            GLint x, GLint y, GLsizei width) {
  gl(CopyTexImage1D(GL_TEXTURE_1D, 0, GLenum(internal_format), x, y, width, 0));
}

inline void Texture1D::copyMipmap(GLint level,
                                  PixelDataInternalFormat internal_format,
                                  GLint x, GLint y, GLsizei width) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexImage1D(GL_TEXTURE_1D, level, GLenum(internal_format),
                    x, y, width, 0));
}

inline void Texture1D::copySub(GLint x_offset, GLint x, GLint y,
                               GLsizei width) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexSubImage1D(GL_TEXTURE_1D, 0, x_offset, x, y, width));
}

inline void Texture1D::copySubMipmap(GLint level, GLint x_offset, GLint x,
                                     GLint y, GLsizei width) {
  OGLWRAP_CHECK_BINDING();
  gl(CopyTexSubImage1D(GL_TEXTURE_1D, level, x_offset, x, y, width));
}

inline GLsizei Texture1D::width(GLint level) const {
  OGLWRAP_CHECK_BINDING();
  GLsizei w;
  gl(GetTexLevelParameteriv(GL_TEXTURE_1D, level, GL_TEXTURE_WIDTH, &w));
  return w;
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetCompressedTexImage)
inline void Texture1D::getCompressedImage(GLint level, GLvoid* img) const {
  OGLWRAP_CHECK_BINDING();
  gl(GetCompressedTexImage(GL_TEXTURE_1D, level, img));
}
#endif  // glGetCompressedTexImage

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_1D_INL_H_
