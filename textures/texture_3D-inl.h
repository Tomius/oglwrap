// Copyright (c) 2014, Tamas Csala

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
  gl(TexImage3D(GLenum(texture_t), 0, GLenum(internal_format), width, height,
                depth, 0, GLenum(format), GLenum(type), data));
}

template<Texture3DType texture_t>
void Texture3DBase<texture_t>::uploadMipmap(
    GLint level, PixelDataInternalFormat internal_format, GLsizei width,
    GLsizei height, GLsizei depth, PixelDataFormat format, PixelDataType type,
    const void *data) {
  OGLWRAP_CHECK_BINDING();
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

#endif  // GL_TEXTURE_3D

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXTURE_3D_INL_H_
