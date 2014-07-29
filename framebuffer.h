// Copyright (c) 2014, Tamas Csala

/** @file framebuffer.h
    @brief Implements a wrapper for Framebuffer objects
*/

#ifndef OGLWRAP_FRAMEBUFFER_H_
#define OGLWRAP_FRAMEBUFFER_H_

#include "./renderbuffer.h"
#include "textures/texture_base.h"
#include "textures/texture_1D.h"
#include "textures/texture_2D.h"
#include "textures/texture_cube.h"
#include "textures/texture_3D.h"

#include "enums/framebuffer_type.h"
#include "enums/framebuffer_binding.h"
#include "enums/framebuffer_status.h"
#include "enums/framebuffer_attachment.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING \
  || (defined(glGenFramebuffers) && defined(glDeleteFramebuffers))
/// A buffer that you can draw to.
template<FramebufferType FBO_TYPE>
class FramebufferObject {
 public:
  /// Default constructor
  FramebufferObject() = default;

  template<FramebufferType another_fbo_t>
  /// Creates a copy of the framebuffer, or casts it to another type.
  /** Important: if you use this to change the type of the active framebuffer,
    * don't forget to unbind the old one, and bind the new one */
  FramebufferObject(const BufferObject<another_fbo_t> src)
      : framebuffer_(src.expose()) { }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCheckFramebufferStatus)
  /// Returns the status of a bound framebuffer.
  /** @see glCheckFramebufferStatus */
  FramebufferStatus status() const;
#endif  // glCheckFramebufferStatus

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCheckFramebufferStatus)
  /// Throws a logic error exception if the framebuffer isn't complete.
  /** @see glCheckFramebufferStatus */
  void validate() const;
#endif  // glCheckFramebufferStatus

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferRenderbuffer)
  /// Attach a renderbuffer as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point to which renderbuffer should be attached.
    * @param render_buffer - Specifies the renderbuffer object that is to be attached.
    * @see glFramebufferRenderbuffer */
  void attachBuffer(FramebufferAttachment attachment,
                    const Renderbuffer& render_buffer);
#endif  // glFramebufferRenderbuffer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture1D)
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture1D */
  void attachTexture(FramebufferAttachment attachment, const Texture1D& texture,
                     GLuint level = 0);
#endif  // glFramebufferTexture1D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture2D)
  template <Texture2DType texture_t>
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture2D */
  void attachTexture(FramebufferAttachment attachment,
                     const Texture2DBase<texture_t>& texture,
                     GLint level = 0);
#endif  // glFramebufferTexture2D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture2D)
  /// Attach a level of a cube map as a logical buffer to the currently bound framebuffer object.
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param target - Specifies which face of the cube map is to be attached.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture2D */
  void attachTexture(FramebufferAttachment attachment, TextureCubeTarget target,
                     const TextureCube& texture, GLint level = 0);
#endif  // glFramebufferTexture2D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture3D)
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @param layer - Specifies the \a layer of texture to attach.
    * @see glFramebufferTexture3D */
  void attachTexture(FramebufferAttachment attachment, const Texture3D& texture,
                     GLint level, GLint layer);
#endif  // glFramebufferTexture3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTextureLayer)
  template <TextureType texture_t>
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @param layer - Specifies the \a layer of texture to attach.
    * @see glFramebufferTexture3D */
  void attachTextureLayer(FramebufferAttachment attachment,
                          const TextureBase<texture_t>& texture,
                          GLint level, GLint layer);
#endif  // glFramebufferTextureLayer

  /// Returns the handle for the framebuffer object.
  const glObject& expose() const { return framebuffer_; }

 private:
  globjects::Framebuffer framebuffer_;
};

using Framebuffer     = FramebufferObject<FramebufferType::kFramebuffer>;
using ReadFramebuffer = FramebufferObject<FramebufferType::kReadFramebuffer>;
using DrawFramebuffer = FramebufferObject<FramebufferType::kDrawFramebuffer>;

#endif  // glGenFramebuffers && glDeleteFramebuffers

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_FRAMEBUFFER_H_

