/** @file framebuffer.hpp
    @brief Implements a wrapper for Framebuffer objects
*/

#ifndef FRAMEBUFFER_HPP
#define FRAMEBUFFER_HPP

#include "GL/glew.h"

#include "enums.hpp"
#include "error.hpp"
#include "general.hpp"
#include "textures/texture_base.hpp"
#include "textures/texture_cube.hpp"

namespace oglwrap {

/// @brief A buffer that servers as a storage for a framebuffer.
/// @see glGenRenderbuffers, glDeleteRenderbuffers
class RenderBuffer {
    /// The handle for the render buffer.
    ObjectExt<glGenRenderbuffers, glDeleteRenderbuffers> renderbuffer;
public:

    /// @brief Binds this renderbuffer.
    /// @see glBindRenderbuffer
    void Bind() {
        gl( BindRenderbuffer(GL_RENDERBUFFER, renderbuffer) );
    }

    /// @brief Unbinds this renderbuffer.
    /// @see glBindRenderbuffer
    void Unbind() {
        gl( BindRenderbuffer(GL_RENDERBUFFER, 0) );
    }

    /// @brief Establish data storage, format and dimensions of a renderbuffer object's image.
    /// @see glRenderbufferStorage
    void Storage(PixelDataInternalFormat internalFormat, GLsizei width, GLsizei height) {
        gl( RenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height) );

        oglwrap_PrintError(
            GL_INVALID_VALUE,
            "RenderBuffer::Storage is called, but width or height is negative, or greater "
            "than the value of GL_MAX_RENDERBUFFER_SIZE."
        );
        oglwrap_PrintError(
            GL_INVALID_ENUM,
            "RenderBuffer::Storage is called, but internalFormat is not a color-renderable, "
            "depth-renderable, or stencil-renderable format."
        );
        oglwrap_PrintError(
            GL_OUT_OF_MEMORY,
            "RenderBuffer::Storage is called, but GL is unable to create a data store of "
            "the requested size."
        );
    }

    /// @brief Establish data storage, format, dimensions and sample count of a renderbuffer object's image.
    /// @see glRenderbufferStorageMultisample
    void StorageMultisample(
        GLsizei samples, PixelDataInternalFormat internalFormat, GLsizei width, GLsizei height
    ) {
        gl( RenderbufferStorageMultisample(GL_RENDERBUFFER, samples, internalFormat, width, height) );

        oglwrap_PrintError(
            GL_INVALID_VALUE,
            "RenderBuffer::Storage is called, but width or height is negative, or greater "
            "than the value of GL_MAX_RENDERBUFFER_SIZE or samples is greater than GL_MAX_SAMPLES."
        );
        oglwrap_PrintError(
            GL_INVALID_ENUM,
            "RenderBuffer::Storage is called, but internalFormat is not a color-renderable, "
            "depth-renderable, or stencil-renderable format."
        );
        oglwrap_PrintError(
            GL_OUT_OF_MEMORY,
            "RenderBuffer::Storage is called, but GL is unable to create a data store of "
            "the requested size."
        );
    }

    /// Returns the handle for this object.
    const ObjectExt<glGenRenderbuffers, glDeleteRenderbuffers>& Expose() const {
        return renderbuffer;
    }
};

/// A buffer that you can draw to.
class FrameBuffer {
    ObjectExt<glGenFramebuffers, glDeleteFramebuffers> framebuffer; ///< The handle for the framebuffer
    GLenum currentTarget; ///< The current target of this Framebuffer
public:
    /// @brief Binds the framebuffer for reading and/or drawing.
    /// @param target - The target to bind the framebuffer to.
    /// @see glBindFramebuffer
    void Bind(FBO_Target target = FBO_Target::Read_Draw) {
        gl( BindFramebuffer(target, framebuffer) );
        currentTarget = target;
    }

    /// @brief Unbinds the buffer from the target it is currently bound to.
    /// @see glBindFramebuffer
    void Unbind() {
        if(currentTarget != 0) {
            gl( BindFramebuffer(currentTarget, 0) );
            currentTarget = 0;
        }
    }

    /// @brief Returns the status of a bound framebuffer.
    /** Throws an exception if the framebuffer isn't bound. */
    /// @see glCheckFramebufferStatus
    FBO_Status Status() {
        if(!currentTarget) {
            throw std::logic_error(
                "FrameBuffer::Status is called, but the framebuffer isn't bound to any target."
            );
        }
        return FBO_Status(glCheckFramebufferStatus(currentTarget));
    }

    /// @brief Returns if the framebuffer is currently bound.
    bool isBound() {
        return currentTarget != 0;
    }

    /// @brief Throws an exception if the framebuffer isn't complete.
    /// @see glCheckFramebufferStatus
    void Validate() {
        std::string errStr;

        if(!currentTarget) {
            errStr = "The framebuffer isn't bound to any target.";
        } else {
            FBO_Status status = FBO_Status(glCheckFramebufferStatus(currentTarget));
            switch (status) {
                case FBO_Status::Complete:
                    return;
                case FBO_Status::Incomplete_Attachment:
                    errStr = "One or more framebuffer attachment points are incomplete.";
                    break;
                case FBO_Status::Incomplete_MissingAttachment:
                    errStr = "The framebuffer does not have at least one image attached to it.";
                    break;
                case FBO_Status::Incomplete_DrawBuffer:
                    errStr = "The value of GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is GL_NONE for "
                             "any color attachment point(s) named by GL_DRAW_BUFFERi.";
                    break;
                case FBO_Status::Incomplete_ReadBuffer:
                    errStr = "The GL_READ_BUFFER is not GL_NONE and the value of GL_FRAMEBUFFER_"
                             "ATTACHMENT_OBJECT_TYPE is GL_NONE for the color attachment point "
                             "named by GL_READ_BUFFER.";
                    break;
                case FBO_Status::Unsupported:
                    errStr = "The combination of internal formats of the attached images violates an "
                             "implementation-dependent set of restrictions.";
                    break;
                case FBO_Status::Undefined:
                    errStr = "The currently bound framebuffer does not exist.";
                    break;
                case FBO_Status::Incomplete_Multisample:
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
                case FBO_Status::Incomplete_LayerTargets:
                    errStr = "One or more framebuffer attachment is layered, and any populated attachment "
                             "is not layered, or if all populated color attachments are not from textures "
                             "of the same target.";
                    break;
                default:
                    errStr = "I have no damn idea about what the hell did you do.";
            }
        }

        throw std::logic_error("Framebuffer error: \n" + errStr);
    }

    /// @brief Attach a renderbuffer as a logical buffer to the currently bound framebuffer object
    /// @param attachment - Specifies the attachment point to which renderbuffer should be attached.
    /// @param renderBuffer - Specifies the renderbuffer object that is to be attached.
    /// @see glFramebufferRenderbuffer
    void AttachBuffer(FBO_Attachment attachment, RenderBuffer renderBuffer) {
        if(!currentTarget) {
            std::cerr << "FrameBuffer::AttachBuffer is called, but the "
                         "framebuffer isn't bound to any target." << std::endl;
            return;
        }

        gl( FramebufferRenderbuffer(currentTarget, attachment, GL_RENDERBUFFER, renderBuffer.Expose()) );

        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "FrameBuffer::AttachBuffer is called, but the default FBO is bound to this target."
        );
    }

    template <TexType texture_t>
    /// @brief Attach a level of a texture object as a logical buffer to the currently bound framebuffer object
    /// @param attachment - Specifies the attachment point of the framebuffer.
    /// @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    /// @param level - Specifies the mipmap level of \a texture to attach.
    /// @see glFramebufferTexture
    void AttachTexture(FBO_Attachment attachment, const TextureBase<texture_t>& texture, GLuint level) {
        if(!currentTarget) {
            std::cerr << "FrameBuffer::AttachBuffer is called, but the "
                         "framebuffer isn't bound to any target." << std::endl;
            return;
        }
        gl( FramebufferTexture(currentTarget, attachment, texture.Expose(), level) );

        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "FrameBuffer::AttachBuffer is called, but the default FBO is bound to this target."
        );
    }

    /// @brief Attach a level of a cube map as a logical buffer to the currently bound framebuffer object.
    /// @param attachment - Specifies the attachment point of the framebuffer.
    /// @param target - Specifies which face of the cube map is to be attached.
    /// @param texture - Specifies the texture object to attach to the framebuffer attachment point named by \a attachment.
    /// @param level - Specifies the mipmap level of \a texture to attach.
    /// @see glFramebufferTexture2D
    void AttachTexture(
        FBO_Attachment attachment, CubeTarget target, const TextureCube& texture, GLuint level
    ) {
        if(!currentTarget) {
            std::cerr << "FrameBuffer::AttachBuffer is called, but the "
                         "framebuffer isn't bound to any target." << std::endl;
            return;
        }
        gl( FramebufferTexture2D(currentTarget, attachment, target, texture.Expose(), level) );

        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "FrameBuffer::AttachBuffer is called, but the default FBO is bound to this target."
        );
    }

    const ObjectExt<glGenFramebuffers, glDeleteFramebuffers>& Expose() {
        return framebuffer;
    }
};

} // namespace oglwrap

#endif
