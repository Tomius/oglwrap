/** @file framebuffer.hpp
    @brief Implements a wrapper for Framebuffer objects
*/

#pragma once

#include "textures/texture_base.hpp"
#include "textures/texture_cube.hpp"

namespace oglwrap {

#ifdef glGenRenderbuffers
#ifdef glDeleteRenderbuffers
/// @brief A buffer that servers as a storage for a framebuffer.
/// @see glGenRenderbuffers, glDeleteRenderbuffers
class RenderBuffer {
    /// The handle for the render buffer.
    ObjectExt<glGenRenderbuffers, glDeleteRenderbuffers> renderbuffer;
public:
    #ifdef glBindRenderbuffer
    /// @brief Binds this renderbuffer.
    /// @see glBindRenderbuffer
    void bind() {
        gl( BindRenderbuffer(GL_RENDERBUFFER, renderbuffer) );
    }
    #endif // glBindRenderbuffer

    #ifdef glBindRenderbuffer
    /// @brief Unbinds this renderbuffer.
    /// @see glBindRenderbuffer
    void unbind() {
        gl( BindRenderbuffer(GL_RENDERBUFFER, 0) );
    }
    #endif // glBindRenderbuffer

    /// @brief Returns if this is the currently bound RenderBuffer.
    /// @see glGetIntegerv
    bool isBound() const {
        GLint currentlyBoundBuffer;
        gl( GetIntegerv(GL_RENDERBUFFER_BINDING, &currentlyBoundBuffer) );
        OGLWRAP_LAST_BIND_TARGET = "GL_RENDERBUFFER_BINDING";
        return renderbuffer == GLuint(currentlyBoundBuffer);
    }

    #ifdef glRenderbufferStorage
    /// @brief Establish data storage, format and dimensions of a renderbuffer object's image.
    /// @see glRenderbufferStorage
    void storage(PixelDataInternalFormat internalFormat, GLsizei width, GLsizei height) {
        CHECK_BINDING();
        gl( RenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height) );
    }
    #endif // glRenderbufferStorage

    #ifdef glRenderbufferStorageMultisample
    /// @brief Establish data storage, format, dimensions and sample count of a renderbuffer object's image.
    /// @see glRenderbufferStorageMultisample
    void storageMultisample(
        GLsizei samples, PixelDataInternalFormat internalFormat, GLsizei width, GLsizei height
    ) {
        CHECK_BINDING();
        gl( RenderbufferStorageMultisample(GL_RENDERBUFFER, samples, internalFormat, width, height) );
    }
    #endif // glRenderbufferStorageMultisample

    /// Returns the handle for this object.
    const ObjectExt<glGenRenderbuffers, glDeleteRenderbuffers>& expose() const {
        return renderbuffer;
    }
};
#endif // glDeleteRenderbuffers
#endif // glGenRenderbuffers

#ifdef glGenFramebuffers
#ifdef glDeleteFramebuffers
/// A buffer that you can draw to.
template<FramebufferType fbo_t>
class FramebufferObject {
    ObjectExt<glGenFramebuffers, glDeleteFramebuffers> framebuffer; ///< The handle for the framebuffer
public:
    template<FramebufferType another_fbo_t>
    /// Creates a copy of the framebuffer, or casts it to another type.
    /** Important: if you use this to change the type of the active framebuffer,
      * don't forget to unbind the old one, and bind the new one */
    FramebufferObject(const BufferObject<another_fbo_t> src)
        : framebuffer(src.Expose())
    { }

    #ifdef glBindFramebuffer
    /// @brief Binds the framebuffer for reading and/or drawing.
    /// @param target - The target to bind the framebuffer to.
    /// @see glBindFramebuffer
    void bind() {
        gl( BindFramebuffer(fbo_t, framebuffer) );
    }
    #endif // glBindFramebuffer

    #ifdef glBindFramebuffer
    /// @brief Unbinds the buffer from the target it is currently bound to.
    /// @see glBindFramebuffer
    void unbind() {
        gl( BindFramebuffer(fbo_t, 0) );
    }
    #endif // glBindFramebuffer

    #ifdef glCheckFramebufferStatus
    /// @brief Returns the status of a bound framebuffer.
    /** Throws an exception if the framebuffer isn't bound. */
    /// @see glCheckFramebufferStatus
    FramebufferStatus status() {
        GLenum status = gl( CheckFramebufferStatus(fbo_t) );
        return status;
    }
    #endif // glCheckFramebufferStatus

    /// @brief Returns if this is the currently bound framebuffer for its target.
    /// @see glGetIntegerv
    bool isBound() const {
        GLint currentlyBoundBuffer;
        gl( GetIntegerv(getBindingTarget(fbo_t), &currentlyBoundBuffer) );
        return framebuffer == GLuint(currentlyBoundBuffer);
    }

    #ifdef glCheckFramebufferStatus
    /// @brief Throws a logic error exception if the framebuffer isn't complete.
    /// @see glCheckFramebufferStatus
    void validate() {
        CHECK_BINDING();

        std::string errStr;
        GLenum status = gl( CheckFramebufferStatus(fbo_t) );
        switch (FramebufferStatus(status)) {
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
    #endif // glCheckFramebufferStatus

    #ifdef glFramebufferRenderbuffer
    /// @brief Attach a renderbuffer as a logical buffer to the currently bound framebuffer object
    /// @param attachment - Specifies the attachment point to which renderbuffer should be attached.
    /// @param renderBuffer - Specifies the renderbuffer object that is to be attached.
    /// @see glFramebufferRenderbuffer
    void attachBuffer(FramebufferAttachment attachment, RenderBuffer renderBuffer) {
        CHECK_BINDING();

        gl( FramebufferRenderbuffer(fbo_t, attachment, GL_RENDERBUFFER, renderBuffer.expose()) );
    }
    #endif // glFramebufferRenderbuffer

    #ifdef glFramebufferTexture
    template <TexType texture_t>
    /// @brief Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
    /// @param attachment - Specifies the attachment point of the framebuffer.
    /// @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    /// @param level - Specifies the mipmap level of \a texture to attach.
    /// @see glFramebufferTexture
    void attachTexture(FramebufferAttachment attachment, const TextureBase<texture_t>& texture, GLuint level) {
        CHECK_BINDING();

        gl( FramebufferTexture(fbo_t, attachment, texture.Expose(), level) );
    }
    #endif // glFramebufferTexture

    #ifdef glFramebufferTexture2D
    /// @brief Attach a level of a cube map as a logical buffer to the currently bound framebuffer object.
    /// @param attachment - Specifies the attachment point of the framebuffer.
    /// @param target - Specifies which face of the cube map is to be attached.
    /// @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    /// @param level - Specifies the mipmap level of \a texture to attach.
    /// @see glFramebufferTexture2D
    void attachTexture(
        FramebufferAttachment attachment, CubeTarget target, const TextureCube& texture, GLuint level
    ) {
        CHECK_BINDING();

        gl( FramebufferTexture2D(fbo_t, attachment, target, texture.expose(), level) );
    }
    #endif // glFramebufferTexture2D

    const ObjectExt<glGenFramebuffers, glDeleteFramebuffers>& expose() {
        return framebuffer;
    }
}; // class Framebuffer

typedef FramebufferObject<FramebufferType::Read_Draw> Framebuffer;
typedef FramebufferObject<FramebufferType::Read> Read_Framebuffer;
typedef FramebufferObject<FramebufferType::Draw> Draw_Framebuffer;

#endif // glDeleteFramebuffers
#endif // glGenFramebuffers

} // namespace oglwrap
