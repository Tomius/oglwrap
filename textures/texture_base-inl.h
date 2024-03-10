// Copyright (c) Tamas Csala

#ifndef OGLWRAP_TEXTURES_TEXUTRE_BASE_INL_H_
#define OGLWRAP_TEXTURES_TEXUTRE_BASE_INL_H_

#include "./texture_base.h"
#include "../context/binding.h"
#include "../debug/bind_checking.h"
#include "../debug/texture_state_checking.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGenerateMipmap)
template <TextureType texture_t>
void TextureBase<texture_t>::generateMipmap() {
  OGLWRAP_CHECK_BINDING();
  gl(GenerateMipmap(GLenum(texture_t)));
}
#endif

template <TextureType texture_t>
void TextureBase<texture_t>::borderColor(glm::vec4 color) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameterfv(GLenum(texture_t), GL_TEXTURE_BORDER_COLOR,
                    glm::value_ptr(color)));
}

template <TextureType texture_t>
void TextureBase<texture_t>::minFilter(enums::MinFilter filtermode) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_MIN_FILTER,
                   GLenum(filtermode)));
}

template <TextureType texture_t>
void TextureBase<texture_t>::magFilter(enums::MagFilter filtermode) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_MAG_FILTER,
                   GLenum(filtermode)));
}


template <TextureType texture_t>
void TextureBase<texture_t>::wrapS(WrapMode wrap_mode) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_WRAP_S, GLenum(wrap_mode)));
}

template <TextureType texture_t>
void TextureBase<texture_t>::wrapT(WrapMode wrap_mode) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_WRAP_T, GLenum(wrap_mode)));
}

template <TextureType texture_t>
void TextureBase<texture_t>::wrapP(WrapMode wrap_mode) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_WRAP_R, GLenum(wrap_mode)));
}

template <TextureType texture_t>
void TextureBase<texture_t>::swizzleR(SwizzleMode swizzle_mode) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_SWIZZLE_R,
                   GLenum(swizzle_mode)));
}


template <TextureType texture_t>
void TextureBase<texture_t>::swizzleG(SwizzleMode swizzle_mode) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_SWIZZLE_G,
                   GLenum(swizzle_mode)));
}

template <TextureType texture_t>
void TextureBase<texture_t>::swizzleB(SwizzleMode swizzle_mode) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_SWIZZLE_B,
                   GLenum(swizzle_mode)));
}

template <TextureType texture_t>
void TextureBase<texture_t>::swizzleA(SwizzleMode swizzle_mode) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_SWIZZLE_A,
                   GLenum(swizzle_mode)));
}


template <TextureType texture_t>
void TextureBase<texture_t>::swizzleRGBA(SwizzleMode swizzle_mode) {
  OGLWRAP_CHECK_BINDING();
  const GLint swizzle_array[4] = {GLint(swizzle_mode), GLint(swizzle_mode),
                                  GLint(swizzle_mode), GLint(swizzle_mode)};
  gl(TexParameteriv(GLenum(texture_t), GL_TEXTURE_SWIZZLE_RGBA, swizzle_array));
}

template <TextureType texture_t>
void TextureBase<texture_t>::anisotropy(float value) {
  OGLWRAP_CHECK_BINDING();
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_MAX_ANISOTROPY_EXT)
  gl(TexParameterf(GLenum(texture_t), GL_TEXTURE_MAX_ANISOTROPY_EXT, value));
#endif
}

template <TextureType texture_t>
void TextureBase<texture_t>::maxAnisotropy() {
  OGLWRAP_CHECK_BINDING();
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_MAX_ANISOTROPY_EXT)
  GLfloat maxAniso = 0.0f;
  gl(GetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAniso));
  gl(TexParameterf(GLenum(texture_t), GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAniso));
#endif
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexBuffer)
template <TextureType texture_t>
void TextureBase<texture_t>::buffer(PixelDataInternalFormat internal_format,
                                    const TextureBuffer& buffer) {
  OGLWRAP_CHECK_BINDING();
  OGLWRAP_CHECK_BINDLESS_TEXTURE_MODIFIED(bindless_handle_);
  gl(TexBuffer(GLenum(texture_t), GLenum(internal_format), buffer.expose()));
}
#endif

template <TextureType texture_t>
void TextureBase<texture_t>::compareMode(enums::CompareMode mode) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_COMPARE_MODE, GLenum(mode)));
}

template <TextureType texture_t>
void TextureBase<texture_t>::compareFunc(enums::CompareFunc func) {
  OGLWRAP_CHECK_BINDING();
  gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_COMPARE_FUNC, GLenum(func)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetTextureHandleARB)
template <TextureType texture_t>
void TextureBase<texture_t>::makeBindless() {
  OGLWRAP_CHECK_TEXTURE_ALREADY_BINDLESS(bindless_handle_);
  bindless_handle_ = gl(GetTextureHandleARB(expose()));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMakeTextureHandleResidentARB)
template <TextureType texture_t>
void TextureBase<texture_t>::makeResident() {
  OGLWRAP_CHECK_NON_BINDLESS_TEXTURE_RESIDENCY_CHANGE(bindless_handle_);
  gl(MakeTextureHandleResidentARB(bindless_handle_));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMakeTextureHandleNonResidentARB)
template <TextureType texture_t>
void TextureBase<texture_t>::makeNonResident() {
  OGLWRAP_CHECK_NON_BINDLESS_TEXTURE_RESIDENCY_CHANGE(bindless_handle_);
  gl(MakeTextureHandleNonResidentARB(bindless_handle_));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetTexImage)
template <TextureType texture_t>
void TextureBase<texture_t>::getTexImage(GLint level,
                                          GLenum format,
                                          GLenum type,
                                          void* pixels) {
  OGLWRAP_CHECK_BINDING();
  gl(GetTexImage(GLenum(texture_t), level, format, type, pixels));
}
#endif

template <TextureType texture_t>
GLuint64 TextureBase<texture_t>::bindless_handle() const {
  return bindless_handle_;
}

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXUTRE_BASE_INL_H_
