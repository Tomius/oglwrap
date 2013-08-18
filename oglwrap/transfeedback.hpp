/** @file transfeedback.hpp
    @brief Implements transform feedback functionality.
*/

#ifndef TRANSFORMFEEDBACK_HPP
#define TRANSFORMFEEDBACK_HPP

#include <GL/glew.h>
#include "error.hpp"

namespace oglwrap {

/// A wrapper class for transform feedback.
/** Transform Feedback is the process of altering the rendering pipeline so that primitives
  * processed by a Vertex Shader and optionally a Geometry Shader will be written to buffer
  * objects. This allows one to preserve the post-transform rendering state of an object and
  * resubmit this data multiple times. */
class TransformFeedback : protected RefCounted {
    GLuint handle; ///< The C handle for the TransformFeedback
public:
    /// Generates a transform feedback.
    /// @see glGenTransformFeedbacks
    TransformFeedback() {
        oglwrap_PreCheckError();

        glGenTransformFeedbacks(1, &handle);
    }

    /// Deletes the transform feedback, if only one instance of it exists.
    /// @see glDeleteTransformFeedbacks
    ~TransformFeedback() {
        oglwrap_PreCheckError();

        if(!isDeletable())
            return;

        glDeleteTransformFeedbacks(1, &handle);
    }

    /// Binds the transform feedback.
    /// @see glBindTransformFeedback
    void Bind() const {
        oglwrap_PreCheckError();

        glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, handle);
    }

    /// Unbinds the currently bound transform feedback.
    /// @see glBindTransformFeedback
    static void Unbind() const {
        oglwrap_PreCheckError();

        glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0);
    }

    /// Begins the transform feedback mode.
    /// @param mode - The primitive type the TF should use.
    /// @see glBeginTransformFeedback
    static void Begin(TFB_PrimType mode) {
        oglwrap_PreCheckError();

        glBeginTransformFeedback(mode);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "TransformFeedback::Begin is called while transform feedback is active."
        );
    }

    /// Ends the transform feedback mode.
    /// @see glEndTransformFeedback
    static void End() {
        oglwrap_PreCheckError();

        glEndTransformFeedback(mode);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "TransformFeedback::End is called but either of the following apply: \n"
            " - The transform feedback is not active. \n"
            " - Any binding point used in transform feedback mode does not have a buffer object bound. \n "
            " - No binding points would be used, either because no program object is active or because the "
            "active program object has specified no varying variables to record."
        );
    }

    /// Pauses transform feedback operations on the currently active transform feedback object.
    /// @see glPauseTransformFeedback
    static void Pause() {
        oglwrap_PreCheckError();

        glPauseTransformFeedback(mode);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "TransformFeedback::Pause is called but the currently bound "
            "transform feedback object is not active or is paused."
        );
    }

    /// Resumes transform feedback operations on the currently active transform feedback object.
    /// @see glResumeTransformFeedback
    static void Pause() {
        oglwrap_PreCheckError();

        glResumeTransformFeedback(mode);

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "TransformFeedback::Pause is called but the currently bound "
            "transform feedback object is not active or is not paused."
        );
    }
};

};

#endif
