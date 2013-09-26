/** @file framebuffer.hpp
    @brief Implements a wrapper for Framebuffer objects
*/

#ifndef OGLWRAP_FRAMEBUFFER_HPP_
#define OGLWRAP_FRAMEBUFFER_HPP_

#include "textures/texture_base.hpp"
#include "textures/texture_cube.hpp"

namespace oglwrap {

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glGenRenderbuffers) && defined(glDeleteRenderbuffers))
/// A buffer that servers as a storage for a framebuffer.
/** @see glGenRenderbuffers, glDeleteRenderbuffers */
class RenderBuffer {
  /// The handle for the render buffer.
  ObjectExt<glGenRenderbuffers, glDeleteRenderbuffers> renderbuffer_;
public:
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindRenderbuffer)
  /// Binds this renderbuffer.
  /** @see glBindRenderbuffer */
  void bind() const {
    gl(BindRenderbuffer(GL_RENDERBUFFER, renderbuffer_));
  }
#endif // glBindRenderbuffer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindRenderbuffer)
  /// Unbinds this renderbuffer.
  /** @see glBindRenderbuffer */
  static void Unbind() {
    gl(BindRenderbuffer(GL_RENDERBUFFER, 0));
  }
#endif // glBindRenderbuffer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindRenderbuffer)
  /// Unbinds this renderbuffer.
  /** @see glBindRenderbuffer */
  BIND_CHECKED void unbind() const {
    CHECK_BINDING2();
    Unbind();
  }
#endif // glBindRenderbuffer

  /// Returns if this is the currently bound RenderBuffer.
  /** @see glGetIntegerv */
  bool isBound() const {
    GLint currentlyBoundBuffer;
    gl(GetIntegerv(GL_RENDERBUFFER_BINDING, &currentlyBoundBuffer));
    OGLWRAP_LAST_BIND_TARGET = "GL_RENDERBUFFER_BINDING";
    return renderbuffer_ == GLuint(currentlyBoundBuffer);
  }

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glRenderbufferStorage)
  /// Establish data storage, format and dimensions of a renderbuffer object's image.
  /** @see glRenderbufferStorage */
  static void Storage(PixelDataInternalFormat internalFormat, GLsizei width, GLsizei height) {
    gl(RenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height));
  }
#endif // glRenderbufferStorage

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glRenderbufferStorage)
  /// Establish data storage, format and dimensions of a renderbuffer object's image.
  /** @see glRenderbufferStorage */
  BIND_CHECKED void storage(PixelDataInternalFormat internalFormat, GLsizei width, GLsizei height) const {
    CHECK_BINDING();
    Storage(internalFormat, width, height);
  }
#endif // glRenderbufferStorage

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glRenderbufferStorageMultisample)
  /// Establish data storage, format, dimensions and sample count of a renderbuffer object's image.
  /** @see glRenderbufferStorageMultisample */
  static void StorageMultisample(GLsizei samples, PixelDataInternalFormat internalFormat,
                                 GLsizei width, GLsizei height) {
    gl(RenderbufferStorageMultisample(GL_RENDERBUFFER, samples, internalFormat, width, height));
  }
#endif // glRenderbufferStorageMultisample

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glRenderbufferStorageMultisample)
  /// Establish data storage, format, dimensions and sample count of a renderbuffer object's image.
  /** @see glRenderbufferStorageMultisample */
  BIND_CHECKED void storageMultisample(GLsizei samples, PixelDataInternalFormat internalFormat,
                                       GLsizei width, GLsizei height) const {
    CHECK_BINDING();
    StorageMultisample(samples, internalFormat, width, height);
  }
#endif // glRenderbufferStorageMultisample

  /// Returns the handle for this object.
  const ObjectExt<glGenRenderbuffers, glDeleteRenderbuffers>& expose() const {
    return renderbuffer_;
  }
};
#endif // glGenRenderbuffers && glDeleteRenderbuffers

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glGenFramebuffers) && defined(glDeleteFramebuffers))
/// A buffer that you can draw to.
template<FramebufferType FBO_TYPE>
class FramebufferObject {
  ObjectExt<glGenFramebuffers, glDeleteFramebuffers> framebuffer_; ///< The handle for the framebuffer
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

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindFramebuffer)
  /// Binds the framebuffer for reading and/or drawing.
  /** @see glBindFramebuffer */
  void bind() const {
    gl(BindFramebuffer(FBO_TYPE, framebuffer_));
  }
#endif // glBindFramebuffer

  /// Returns if this is the currently bound framebuffer for its target.
  /** @see glGetIntegerv */
  bool isBound() const {
    GLint currentlyBoundBuffer;
    gl(GetIntegerv(getBindingTarget(FBO_TYPE), &currentlyBoundBuffer));
    return framebuffer_ == GLuint(currentlyBoundBuffer);
  }

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindFramebuffer)
  /// Unbinds the buffer from the target it is currently bound to.
  /** @see glBindFramebuffer */
  static void Unbind() {
    gl(BindFramebuffer(FBO_TYPE, 0));
  }
  /// Unbinds the buffer from the target it is currently bound to.
  /** @see glBindFramebuffer */
  BIND_CHECKED void unbind() const {
    CHECK_BINDING2();
    Unbind();
  }
#endif // glBindFramebuffer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glCheckFramebufferStatus)
  /// Returns the status of a bound framebuffer.
  /** @see glCheckFramebufferStatus */
  static FramebufferStatus Status() {
    GLenum status = gl(CheckFramebufferStatus(FBO_TYPE));
    return status;
  }
  /// Returns the status of a bound framebuffer.
  /** @see glCheckFramebufferStatus */
  BIND_CHECKED FramebufferStatus status() const {
    CHECK_BINDING();
    return Status();
  }
#endif // glCheckFramebufferStatus

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glCheckFramebufferStatus)
  /// Throws a logic error exception if the framebuffer isn't complete.
  /** @see glCheckFramebufferStatus */
  static void Validate() {
    std::string errStr;
    GLenum status = gl(CheckFramebufferStatus(FBO_TYPE));
    switch(FramebufferStatus(status)) {
      case FramebufferStatus::Complete:
        return;
      case FramebufferStatus::Incomplete_Attachment:
        errStr = "One or more framebuffer attachment points are incomplete.";
        break;
      case FramebufferStatus::Incomplete_MissingAttachment:
        errStr = "The framebuffer does not have at least one image attached to it.";
        break;
      case FramebufferStatus::Incomplete_DrawBuffer:
        errStr = "The value of GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is GL_NONE for "
                 "any color attachment point(s) named by GL_DRAW_BUFFERi.";
        break;
      case FramebufferStatus::Incomplete_ReadBuffer:
        errStr = "The GL_READ_BUFFER is not GL_NONE and the value of GL_FRAMEBUFFER_"
                 "ATTACHMENT_OBJECT_TYPE is GL_NONE for the color attachment point "
                 "named by GL_READ_BUFFER.";
        break;
      case FramebufferStatus::Unsupported:
        errStr = "The combination of internal formats of the attached images violates an "
                 "implementation-dependent set of restrictions.";
        break;
      case FramebufferStatus::Undefined:
        errStr = "The currently bound framebuffer does not exist.";
        break;
      case FramebufferStatus::Incomplete_Multisample:
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
      case FramebufferStatus::Incomplete_LayerTargets:
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
    CHECK_BINDING();
    Validate();
  }
#endif // glCheckFramebufferStatus

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glFramebufferRenderbuffer)
  /// Attach a renderbuffer as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point to which renderbuffer should be attached.
    * @param renderBuffer - Specifies the renderbuffer object that is to be attached.
    * @see glFramebufferRenderbuffer */
  static void AttachBuffer(FramebufferAttachment attachment, RenderBuffer renderBuffer) {
    gl(FramebufferRenderbuffer(FBO_TYPE, attachment, GL_RENDERBUFFER, renderBuffer.expose()));
  }
  /// Attach a renderbuffer as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point to which renderbuffer should be attached.
    * @param renderBuffer - Specifies the renderbuffer object that is to be attached.
    * @see glFramebufferRenderbuffer */
  BIND_CHECKED void attachBuffer(FramebufferAttachment attachment, RenderBuffer renderBuffer) const {
    CHECK_BINDING();
    AttachBuffer(attachment, renderBuffer);
  }
#endif // glFramebufferRenderbuffer

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glFramebufferTexture)
  template <TexType texture_t>
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture */
  static void AttachTexture(FramebufferAttachment attachment, const TextureBase<texture_t>& texture, GLuint level) {
    gl(FramebufferTexture(FBO_TYPE, attachment, texture.expose(), level));
  }
  template <TexType texture_t>
  /// Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture */
  BIND_CHECKED void attachTexture(FramebufferAttachment attachment, const TextureBase<texture_t>& texture, GLuint level) const {
    CHECK_BINDING();
    AttachTexture(attachment, texture, level);
  }
#endif // glFramebufferTexture

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glFramebufferTexture2D)
  /// Attach a level of a cube map as a logical buffer to the currently bound framebuffer object.
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param target - Specifies which face of the cube map is to be attached.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture2D */
  static void AttachTexture(
    FramebufferAttachment attachment, CubeTarget target, const TextureCube& texture, GLuint level
  ) {
    gl(FramebufferTexture2D(FBO_TYPE, attachment, target, texture.expose(), level));
  }
  /// Attach a level of a cube map as a logical buffer to the currently bound framebuffer object.
  /** @param attachment - Specifies the attachment point of the framebuffer.
    * @param target - Specifies which face of the cube map is to be attached.
    * @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    * @param level - Specifies the mipmap level of \a texture to attach.
    * @see glFramebufferTexture2D */
  BIND_CHECKED void attachTexture(
    FramebufferAttachment attachment, CubeTarget target, const TextureCube& texture, GLuint level
  ) const {
    CHECK_BINDING();
    AttachTexture(attachment, target, texture, level);
  }
#endif // glFramebufferTexture2D

  /// Returns the handle for the framebuffer object.
  const ObjectExt<glGenFramebuffers, glDeleteFramebuffers>& expose() const {
    return framebuffer_;
  }
}; // class Framebuffer

typedef FramebufferObject<FramebufferType::Read_Draw> Framebuffer;
typedef FramebufferObject<FramebufferType::Read> Read_Framebuffer;
typedef FramebufferObject<FramebufferType::Draw> Draw_Framebuffer;

#endif // glGenFramebuffers && glDeleteFramebuffers

} // namespace oglwrap

#endif // OGLWRAP_FRAMEBUFFER_HPP_

