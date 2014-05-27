// Copyright (c) 2014, Tamas Csala

/** @file framebuffer.h
    @brief Implements a wrapper for Framebuffer objects
*/

#ifndef OGLWRAP_FRAMEBUFFER_H_
#define OGLWRAP_FRAMEBUFFER_H_

#include "globjects.h"
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

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenRenderbuffers) && defined(glDeleteRenderbuffers))
/// A buffer that servers as a storage for a framebuffer.
/** @see glGenRenderbuffers, glDeleteRenderbuffers */
class Renderbuffer {
  /// The handle for the render buffer.
  globjects::Renderbuffer renderbuffer_;
public:
#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindRenderbuffer)
  /// Binds this renderbuffer.
  /** @see glBindRenderbuffer */
  void bind() const {
    gl(BindRenderbuffer(GL_RENDERBUFFER, renderbuffer_));
  }
#endif // glBindRenderbuffer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindRenderbuffer)
  /// Unbinds this renderbuffer.
  /** @see glBindRenderbuffer */
  static void Unbind() {
    gl(BindRenderbuffer(GL_RENDERBUFFER, 0));
  }
#endif // glBindRenderbuffer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindRenderbuffer)
  /// Unbinds this renderbuffer.
  /** @see glBindRenderbuffer */
  BIND_CHECKED void unbind() const {
    OGLWRAP_CHECK_BINDING2();
    Unbind();
  }
#endif // glBindRenderbuffer

  /// Returns if this is the currently bound Renderbuffer.
  /** @see glGetIntegerv */
  bool isBound() const {
    GLint currentlyBoundBuffer;
    gl(GetIntegerv(GL_RENDERBUFFER_BINDING, &currentlyBoundBuffer));

    #if OGLWRAP_DEBUG
      DebugOutput::LastUsedBindTarget() = "GL_RENDERBUFFER_BINDING";
    #endif

    return renderbuffer_ == GLuint(currentlyBoundBuffer);
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glRenderbufferStorage)
  /// Establish data storage, format and dimensions of a renderbuffer object's image.
  /** @see glRenderbufferStorage */
  static void Storage(PixelDataInternalFormat internalFormat,
                      GLsizei width, GLsizei height) {
    gl(RenderbufferStorage(
      GL_RENDERBUFFER, GLenum(internalFormat), width, height
    ));
  }
#endif // glRenderbufferStorage

#if OGLWRAP_DEFINE_EVERYTHING || defined(glRenderbufferStorage)
  /// Establish data storage, format and dimensions of a renderbuffer object's image.
  /** @see glRenderbufferStorage */
  BIND_CHECKED void storage(PixelDataInternalFormat internalFormat,
                            GLsizei width, GLsizei height) const {
    OGLWRAP_CHECK_BINDING();
    Storage(internalFormat, width, height);
  }
#endif // glRenderbufferStorage

#if OGLWRAP_DEFINE_EVERYTHING || defined(glRenderbufferStorageMultisample)
  /// Establish data storage, format, dimensions and sample count of a renderbuffer object's image.
  /** @see glRenderbufferStorageMultisample */
  static void StorageMultisample(GLsizei samples,
                                 PixelDataInternalFormat internalFormat,
                                 GLsizei width, GLsizei height) {
    gl(RenderbufferStorageMultisample(
      GL_RENDERBUFFER, samples, GLenum(internalFormat), width, height
    ));
  }
#endif // glRenderbufferStorageMultisample

#if OGLWRAP_DEFINE_EVERYTHING || defined(glRenderbufferStorageMultisample)
  /// Establish data storage, format, dimensions and sample count of a renderbuffer object's image.
  /** @see glRenderbufferStorageMultisample */
  BIND_CHECKED void storageMultisample(GLsizei samples,
                                       PixelDataInternalFormat internalFormat,
                                       GLsizei width, GLsizei height) const {
    OGLWRAP_CHECK_BINDING();
    StorageMultisample(samples, internalFormat, width, height);
  }
#endif // glRenderbufferStorageMultisample

  /// Returns the handle for this object.
  const glObject& expose() const {
    return renderbuffer_;
  }
};
#endif // glGenRenderbuffers && glDeleteRenderbuffers


#if OGLWRAP_DEFINE_EVERYTHING \
  || (defined(glGenFramebuffers) && defined(glDeleteFramebuffers))
/// A buffer that you can draw to.
template<FramebufferType FBO_TYPE>
class FramebufferObject {
  globjects::Framebuffer framebuffer_; ///< The handle for the framebuffer
public:

  /// Default constructor
  FramebufferObject() {}

  template<FramebufferType another_fbo_t>
  /// Creates a copy of the framebuffer, or casts it to another type.
  /** Important: if you use this to change the type of the active framebuffer,
    * don't forget to unbind the old one, and bind the new one */
  FramebufferObject(const BufferObject<another_fbo_t> src)
    : framebuffer_(src.Expose())
  { }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindFramebuffer)
  /// Binds the framebuffer for reading and/or drawing.
  /** @see glBindFramebuffer */
  void bind() const {
    gl(BindFramebuffer(GLenum(FBO_TYPE), framebuffer_));
  }
#endif // glBindFramebuffer

  /// Returns if this is the currently bound framebuffer for its target.
  /** @see glGetIntegerv */
  bool isBound() const {
    GLint currentlyBoundBuffer;
    gl(GetIntegerv(GLenum(GetBindingTarget(FBO_TYPE)), &currentlyBoundBuffer));
    return framebuffer_ == GLuint(currentlyBoundBuffer);
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindFramebuffer)
  /// Unbinds the buffer from the target it is currently bound to.
  /** @see glBindFramebuffer */
  static void Unbind() {
    gl(BindFramebuffer(GLenum(FBO_TYPE), 0));
  }
  /// Unbinds the buffer from the target it is currently bound to.
  /** @see glBindFramebuffer */
  BIND_CHECKED void unbind() const {
    OGLWRAP_CHECK_BINDING2();
    Unbind();
  }
#endif // glBindFramebuffer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCheckFramebufferStatus)
  /// Returns the status of a bound framebuffer.
  /** @see glCheckFramebufferStatus */
  static FramebufferStatus Status() {
    GLenum status = gl(CheckFramebufferStatus(GLenum(FBO_TYPE)));
    return FramebufferStatus(status);
  }
  /// Returns the status of a bound framebuffer.
  /** @see glCheckFramebufferStatus */
  BIND_CHECKED FramebufferStatus status() const {
    OGLWRAP_CHECK_BINDING();
    return Status();
  }
#endif // glCheckFramebufferStatus

#if OGLWRAP_DEFINE_EVERYTHING || defined(glCheckFramebufferStatus)
  /// Throws a logic error exception if the framebuffer isn't complete.
  /** @see glCheckFramebufferStatus */
  static void Validate() {
    std::string errStr;
    GLenum status = gl(CheckFramebufferStatus(GLenum(FBO_TYPE)));
    switch (FramebufferStatus(status)) {
      case FramebufferStatus::kFramebufferComplete:
        return;
      case FramebufferStatus::kFramebufferIncompleteAttachment:
        errStr = "One or more framebuffer attachment points are incomplete.";
        break;
      case FramebufferStatus::kFramebufferIncompleteMissingAttachment:
        errStr = "The framebuffer does not have at least one image attached to it.";
        break;
      case FramebufferStatus::kFramebufferIncompleteDrawBuffer:
        errStr = "The value of GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is GL_NONE for "
                 "any color attachment point(s) named by GL_DRAW_BUFFERi.";
        break;
      case FramebufferStatus::kFramebufferIncompleteReadBuffer:
        errStr = "The GL_READ_BUFFER is not GL_NONE and the value of GL_FRAMEBUFFER_"
                 "ATTACHMENT_OBJECT_TYPE is GL_NONE for the color attachment point "
                 "named by GL_READ_BUFFER.";
        break;
      case FramebufferStatus::kFramebufferUnsupported:
        errStr = "The combination of internal formats of the attached images violates an "
                 "implementation-dependent set of restrictions.";
        break;
      case FramebufferStatus::kFramebufferUndefined:
        errStr = "The currently bound framebuffer does not exist.";
        break;
      case FramebufferStatus::kFramebufferIncompleteMultisample:
        errStr = "One of the followings happened: \n"
                 "-  The value of GL_RENDERBUFFER_SAMPLES is not the same for all attached "
                 "renderbuffers; if the value of GL_TEXTURE_SAMPLES is the not same for all "
                 "attached textures; or, if the attached images are a mix of renderbuffers "
                 "and textures, the value of GL_RENDERBUFFER_SAMPLES does not match the value "
                 "of GL_TEXTURE_SAMPLES. \n"
                 "-  The value of GL_TEXTURE_FIXED_SAMPLE_LOCATIONS is not the same for all "
                 "attached textures; or, if the attached images are a mix of renderbuffers "
                 "and textures, the value of GL_TEXTURE_FIXED_SAMPLE_LOCATIONS is not GL_TRUE "
                 "for all attached textures.";
        break;
      case FramebufferStatus::kFramebufferIncompleteLayerTargets:
        errStr = "One or more framebuffer attachment is layered, and any populated attachment "
                 "is not layered, or if all populated color attachments are not from textures "
                 "of the same target.";
        break;
      default:
        errStr = "Unknown error.";
    }

    throw std::logic_error("Framebuffer error: \n" + errStr);
  }
  /// Throws a logic error exception if the framebuffer isn't complete.
  /** @see glCheckFramebufferStatus */
  BIND_CHECKED void validate() const {
    OGLWRAP_CHECK_BINDING();
    Validate();
  }
#endif // glCheckFramebufferStatus

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferRenderbuffer)
  /// Attach a renderbuffer as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point to which renderbuffer should be attached.
    * @param renderBuffer - Specifies the renderbuffer object that is to be attached.
    * @see glFramebufferRenderbuffer */
  static void AttachBuffer(FramebufferAttachment attachment, const Renderbuffer& renderBuffer) {
    gl(FramebufferRenderbuffer(
      GLenum(FBO_TYPE), GLenum(attachment), GL_RENDERBUFFER, renderBuffer.expose()
    ));
  }
  /// Attach a renderbuffer as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point to which renderbuffer should be attached.
    * @param renderBuffer - Specifies the renderbuffer object that is to be attached.
    * @see glFramebufferRenderbuffer */
  BIND_CHECKED void attachBuffer(FramebufferAttachment attachment, const Renderbuffer& renderBuffer) const {
    OGLWRAP_CHECK_BINDING();
    AttachBuffer(attachment, renderBuffer);
  }
#endif // glFramebufferRenderbuffer

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture1D)
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture1D */
  static void AttachTexture(FramebufferAttachment attachment,
                            const Texture1D& texture, GLuint level) {
    gl(FramebufferTexture1D(
      GLenum(FBO_TYPE), GLenum(attachment), GL_TEXTURE_1D, texture.expose(), level
    ));
  }
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture1D */
  BIND_CHECKED void attachTexture(FramebufferAttachment attachment,
                                  const Texture1D& texture, GLuint level) const {
    OGLWRAP_CHECK_BINDING();
    AttachTexture(attachment, texture, level);
  }
#endif // glFramebufferTexture1D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture2D)
  template <Texture2DType texture_t>
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture2D */
  static void AttachTexture(FramebufferAttachment attachment,
                            const Texture2DBase<texture_t>& texture,
                            GLint level) {
    gl(FramebufferTexture2D(
      GLenum(FBO_TYPE), GLenum(attachment),
      GLenum(texture_t), texture.expose(), level
    ));
  }
  template <Texture2DType texture_t>
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture2D */
  BIND_CHECKED void attachTexture(FramebufferAttachment attachment,
                                  const Texture2DBase<texture_t>& texture,
                                  GLint level) const {
    OGLWRAP_CHECK_BINDING();
    AttachTexture(attachment, texture, level);
  }
#endif // glFramebufferTexture2D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture2D)
  /// Attach a level of a cube map as a logical buffer to the currently bound framebuffer object.
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param target - Specifies which face of the cube map is to be attached.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture2D */
  static void AttachTexture(FramebufferAttachment attachment,
                            TextureCubeTarget target,
                            const TextureCube& texture, GLint level) {
    gl(FramebufferTexture2D(
      GLenum(FBO_TYPE), GLenum(attachment),
      GLenum(target), texture.expose(), level
    ));
  }
  /// Attach a level of a cube map as a logical buffer to the currently bound framebuffer object.
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param target - Specifies which face of the cube map is to be attached.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture2D */
  BIND_CHECKED void attachTexture(FramebufferAttachment attachment,
                                  TextureCubeTarget target,
                                  const TextureCube& texture, GLint level) const {
    OGLWRAP_CHECK_BINDING();
    AttachTexture(attachment, target, texture, level);
  }
#endif // glFramebufferTexture2D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTexture3D)
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @param layer - Specifies the \a layer of texture to attach.
    * @see glFramebufferTexture3D */
  static void AttachTexture(FramebufferAttachment attachment,
                            const Texture3D& texture,
                            GLint level, GLint layer) {
    gl(FramebufferTexture3D(
      GLenum(FBO_TYPE), GLenum(attachment), GL_TEXTURE_3D,
      texture.expose(), level, layer
    ));
  }
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @param layer - Specifies the \a layer of texture to attach.
    * @see glFramebufferTexture3D */
  BIND_CHECKED void attachTexture(FramebufferAttachment attachment,
                                  const Texture3D& texture,
                                  GLint level, GLint layer) const {
    OGLWRAP_CHECK_BINDING();
    AttachTexture(attachment, texture, level, layer);
  }
#endif // glFramebufferTexture3D

#if OGLWRAP_DEFINE_EVERYTHING || defined(glFramebufferTextureLayer)
  template <TextureType texture_t>
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @param layer - Specifies the \a layer of texture to attach.
    * @see glFramebufferTexture3D */
  static void AttachTextureLayer(FramebufferAttachment attachment,
                                 const TextureBase<texture_t>& texture,
                                 GLint level, GLint layer) {
    gl(FramebufferTextureLayer(
      GLenum(FBO_TYPE), GLenum(attachment), texture.expose(), level, layer
    ));
  }
  template <TextureType texture_t>
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @param layer - Specifies the \a layer of texture to attach.
    * @see glFramebufferTexture3D */
  BIND_CHECKED void attachTextureLayer(FramebufferAttachment attachment,
                                       const TextureBase<texture_t>& texture,
                                       GLint level, GLint layer) const {
    OGLWRAP_CHECK_BINDING();
    AttachTextureLayer(attachment, texture, level, layer);
  }
#endif // glFramebufferTextureLayer

  /// Returns the handle for the framebuffer object.
  const glObject& expose() const {
    return framebuffer_;
  }
}; // class Framebuffer

using Framebuffer     = FramebufferObject<FramebufferType::kFramebuffer>;
using ReadFramebuffer = FramebufferObject<FramebufferType::kReadFramebuffer>;
using DrawFramebuffer = FramebufferObject<FramebufferType::kDrawFramebuffer>;

#endif // glGenFramebuffers && glDeleteFramebuffers

} // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif // OGLWRAP_FRAMEBUFFER_H_

