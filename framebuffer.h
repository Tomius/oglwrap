// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_FRAMEBUFFER_H_
#define OGLWRAP_FRAMEBUFFER_H_

#include "./renderbuffer.h"
#include "textures/texture_base.h"
#include "textures/texture1D.h"
#include "textures/texture2D.h"
#include "textures/texture_cube.h"
#include "textures/texture3D.h"

#include "enums/framebuffer_target.h"
#include "enums/framebuffer_binding.h"
#include "enums/framebuffer_status.h"
#include "enums/framebuffer_attachment.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING \
  || (defined(glGenFramebuffers) && defined(glDeleteFramebuffers))

/// A buffer that you can draw to.
struct FramebufferBase {
  FramebufferTarget target;
  globjects::Framebuffer handle;

  explicit FramebufferBase(FramebufferTarget target) : target(target) {}
};

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
struct Framebuffer : public FramebufferBase {
  Framebuffer() : FramebufferBase(FramebufferTarget::kFramebuffer) {}
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
struct ReadFramebuffer : public FramebufferBase {
  ReadFramebuffer() : FramebufferBase(FramebufferTarget::kReadFramebuffer) {}
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
struct DrawFramebuffer : public FramebufferBase {
  DrawFramebuffer() : FramebufferBase(FramebufferTarget::kDrawFramebuffer) {}
};
#endif

class BoundFramebuffer {
 public:
  explicit BoundFramebuffer(const FramebufferBase& fbo)
      : target_(static_cast<GLenum>(fbo.target))
      , moved_(false) {
    gl(GetIntegerv(GLenum(GetBindingTarget(fbo.target)),
                   reinterpret_cast<GLint*>(&last_binding_)));
    gl(BindFramebuffer(target_, fbo.handle));
  }

  explicit BoundFramebuffer(BoundFramebuffer&& bound_fbo)
      : last_binding_(bound_fbo.last_binding_)
      , target_(bound_fbo.target_)
      , moved_(bound_fbo.moved_) {
    bound_fbo.moved_ = true;
  }

  ~BoundFramebuffer() {
    if (!moved_) { gl(BindFramebuffer(target_, last_binding_)); }
  }

  // No copy
  BoundFramebuffer(const BoundFramebuffer&) = delete;
  BoundFramebuffer& operator=(const BoundFramebuffer&) = delete;

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCheckFramebufferStatus)
  /// Returns the status of a bound framebuffer.
  FramebufferStatus status() const {
    GLenum status = gl(CheckFramebufferStatus(target_));
    return FramebufferStatus(status);
  }
#endif  // glCheckFramebufferStatus

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCheckFramebufferStatus)
  /// Throws a logic error exception if the framebuffer isn't complete.
  void validate() const {
    std::string error;
    GLenum status = gl(CheckFramebufferStatus(target_));
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
  /// Attach a renderbuffer as a logical buffer to the currently bound framebuffer object
  void attachBuffer(FramebufferAttachment attachment,
                    const Renderbuffer& render_buffer) {
    gl(FramebufferRenderbuffer(target_, GLenum(attachment),
                               GL_RENDERBUFFER, render_buffer.handle));
  }
#endif  // glFramebufferRenderbuffer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture1D)
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  void attachTexture(FramebufferAttachment attachment, const Texture1D& texture,
                     GLuint level = 0) {
    gl(FramebufferTexture1D(target_, GLenum(attachment), GL_TEXTURE_1D,
                            texture.handle, level));
  }
#endif  // glFramebufferTexture1D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture2D)
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  void attachTexture(FramebufferAttachment attachment,
                     const Texture2DBase& texture,
                     GLint level = 0) {
    gl(FramebufferTexture2D(target_, GLenum(attachment), GLenum(texture.target),
                            texture.handle, level));
  }
#endif  // glFramebufferTexture2D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture2D)
  /// Attach a level of a cube map as a logical buffer to the currently bound framebuffer object.
  void attachTexture(FramebufferAttachment attachment, TextureCubeTarget target,
                     const TextureCube& texture, GLint level = 0) {
    gl(FramebufferTexture2D(target_, GLenum(attachment), GLenum(texture.target),
                            texture.handle, level));
  }
#endif  // glFramebufferTexture2D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture3D)
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  void attachTexture(FramebufferAttachment attachment,
                     const Texture3DBase& texture, GLint level, GLint layer) {
    gl(FramebufferTexture3D(target_, GLenum(attachment), GLenum(texture.target),
                            texture.handle, level, layer));
  }
#endif  // glFramebufferTexture3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTextureLayer)
  template <TextureTarget texture_t>
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  void attachTextureLayer(FramebufferAttachment attachment,
                          const TextureBase& texture,
                          GLint level, GLint layer) {
    gl(FramebufferTextureLayer(target_, GLenum(attachment),
                               texture.handle, level, layer));
  }
#endif  // glFramebufferTextureLayer

private:
  GLuint last_binding_;
  const GLenum target_;
  bool moved_;
};

#endif  // glGenFramebuffers && glDeleteFramebuffers

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_FRAMEBUFFER_H_

