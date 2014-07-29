// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_FRAMEBUFFER_INL_H_
#define OGLWRAP_FRAMEBUFFER_INL_H_

#include "./framebuffer.h"
#include "context/binding.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING \
  || (defined(glGenFramebuffers) && defined(glDeleteFramebuffers))

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCheckFramebufferStatus)
template<FramebufferType FBO_TYPE>
FramebufferStatus FramebufferObject<FBO_TYPE>::status() const {
  OGLWRAP_CHECK_BINDING();
  GLenum status = gl(CheckFramebufferStatus(GLenum(FBO_TYPE)));
  return FramebufferStatus(status);
}
#endif  // glCheckFramebufferStatus

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCheckFramebufferStatus)
template<FramebufferType FBO_TYPE>
void FramebufferObject<FBO_TYPE>::validate() const {
  OGLWRAP_CHECK_BINDING();
  std::string error;
  GLenum status = gl(CheckFramebufferStatus(GLenum(FBO_TYPE)));
  switch (FramebufferStatus(status)) {
    case FramebufferStatus::kFramebufferComplete:
      return;
    case FramebufferStatus::kFramebufferIncompleteAttachment:
      error = "One or more framebuffer attachment points are incomplete.";
      break;
    case FramebufferStatus::kFramebufferIncompleteMissingAttachment:
      error = "The framebuffer does not have at least one image attached to "
               "it.";
      break;
    case FramebufferStatus::kFramebufferIncompleteDrawBuffer:
      error = "The value of GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is "
               "GL_NONE for any color attachment point(s) named by "
               "GL_DRAW_BUFFERi.";
      break;
    case FramebufferStatus::kFramebufferIncompleteReadBuffer:
      error = "The GL_READ_BUFFER is not GL_NONE and the value of "
               "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is GL_NONE for the "
               "color attachment point named by GL_READ_BUFFER.";
      break;
    case FramebufferStatus::kFramebufferUnsupported:
      error = "The combination of internal formats of the attached images "
               "violates an implementation-dependent set of restrictions.";
      break;
    case FramebufferStatus::kFramebufferUndefined:
      error = "The currently bound framebuffer does not exist.";
      break;
    case FramebufferStatus::kFramebufferIncompleteMultisample:
      error = "One of the followings happened: \n"
               "-  The value of GL_RENDERBUFFER_SAMPLES is not the same for "
               "all attached renderbuffers; if the value of "
               "GL_TEXTURE_SAMPLES is the not same for all attached textures; "
               "or, if the attached images are a mix of renderbuffers and "
               "textures, the value of GL_RENDERBUFFER_SAMPLES does not match "
               "the value of GL_TEXTURE_SAMPLES. \n"
               "-  The value of GL_TEXTURE_FIXED_SAMPLE_LOCATIONS is not the "
               "same for all attached textures; or, if the attached images "
               "are a mix of renderbuffers and textures, the value of "
               "GL_TEXTURE_FIXED_SAMPLE_LOCATIONS is not GL_TRUE for all "
               "attached textures.";
      break;
    case FramebufferStatus::kFramebufferIncompleteLayerTargets:
      error = "One or more framebuffer attachment is layered, and any "
              "populated attachment is not layered, or if all populated color "
              "attachments are not from textures of the same target.";
      break;
  }

  throw std::logic_error("Framebuffer error: \n" + error);
}
#endif  // glCheckFramebufferStatus

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferRenderbuffer)
template<FramebufferType FBO_TYPE>
void FramebufferObject<FBO_TYPE>::attachBuffer(
    FramebufferAttachment attachment, const Renderbuffer& render_buffer) {
  OGLWRAP_CHECK_BINDING();
  gl(FramebufferRenderbuffer(GLenum(FBO_TYPE), GLenum(attachment),
                             GL_RENDERBUFFER, render_buffer.expose()));
}
#endif  // glFramebufferRenderbuffer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture1D)
template<FramebufferType FBO_TYPE>
void FramebufferObject<FBO_TYPE>::attachTexture(
    FramebufferAttachment attachment,
    const Texture1D& texture,
    GLuint level) {
  OGLWRAP_CHECK_BINDING();
  gl(FramebufferTexture1D(GLenum(FBO_TYPE), GLenum(attachment), GL_TEXTURE_1D,
                          texture.expose(), level));
}
#endif  // glFramebufferTexture1D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture2D)
template<FramebufferType FBO_TYPE>
template <Texture2DType texture_t>
void FramebufferObject<FBO_TYPE>::attachTexture(
    FramebufferAttachment attachment,
    const Texture2DBase<texture_t>& texture,
    GLint level) {
  OGLWRAP_CHECK_BINDING();
  gl(FramebufferTexture2D(GLenum(FBO_TYPE), GLenum(attachment),
                          GLenum(texture_t), texture.expose(), level));
}
#endif  // glFramebufferTexture2D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture2D)
template<FramebufferType FBO_TYPE>
void FramebufferObject<FBO_TYPE>::attachTexture(
    FramebufferAttachment attachment,
    TextureCubeTarget target,
    const TextureCube& texture,
    GLint level) {
  OGLWRAP_CHECK_BINDING();
  gl(FramebufferTexture2D(GLenum(FBO_TYPE), GLenum(attachment),
                          GLenum(target), texture.expose(), level));
}
#endif  // glFramebufferTexture2D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture3D)
template<FramebufferType FBO_TYPE>
void FramebufferObject<FBO_TYPE>::attachTexture(
    FramebufferAttachment attachment, const Texture3D& texture,
    GLint level, GLint layer) {
  OGLWRAP_CHECK_BINDING();
  gl(FramebufferTexture3D(GLenum(FBO_TYPE), GLenum(attachment), GL_TEXTURE_3D,
                          texture.expose(), level, layer));
}
#endif  // glFramebufferTexture3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTextureLayer)
template<FramebufferType FBO_TYPE>
template <TextureType texture_t>
void FramebufferObject<FBO_TYPE>::attachTextureLayer(
    FramebufferAttachment attachment, const TextureBase<texture_t>& texture,
    GLint level, GLint layer) {
  OGLWRAP_CHECK_BINDING();
  gl(FramebufferTextureLayer(GLenum(FBO_TYPE), GLenum(attachment),
                             texture.expose(), level, layer));
}
#endif  // glFramebufferTextureLayer

#endif  // glGenFramebuffers && glDeleteFramebuffers

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_FRAMEBUFFER_H_

