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
    enum TFBstate{none, working, paused} state;
public:
    /// Generates a transform feedback.
    /// @see glGenTransformFeedbacks
    TransformFeedback() : state(none) {
        oglwrap_PreCheckError();

        glGenTransformFeedbacks(1, &handle);
    }

    /// Creates a transform feedback and activates it. It will work till the variable's lifetime.
    /// @param mode - The primitive type the TFB should use.
    /// @see glGenTransformFeedbacks
    TransformFeedback(TFB_PrimType mode) : state(working) {
        oglwrap_PreCheckError();

        glGenTransformFeedbacks(1, &handle);
        Bind();
        Begin(mode);
    }

    /// Deletes the transform feedback, if only one instance of it exists.
    /** Also ends it if it's active. In this case it will change the currently active TFB. */
    /// @see glDeleteTransformFeedbacks
    ~TransformFeedback() {
        oglwrap_PreCheckError();

        if(!isDeletable())
            return;
        if(state != none) {
            Bind();
            End();
        }
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
    void Unbind() {
        oglwrap_PreCheckError();

        glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0);
    }

    /// Begins the transform feedback mode.
    /// @param mode - The primitive type the TFB should use.
    /// @see glBeginTransformFeedback
    void Begin(TFB_PrimType mode) {
        oglwrap_PreCheckError();

        glBeginTransformFeedback(mode);
        state = working;

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "TransformFeedback::Begin is called while transform feedback is active."
        );
    }

    /// Ends the transform feedback mode.
    /// @see glEndTransformFeedback
    void End() {
        oglwrap_PreCheckError();

        glEndTransformFeedback();
        state = none;

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
    void Pause() {
        oglwrap_PreCheckError();

        glPauseTransformFeedback();
        state = paused;

        oglwrap_CheckError();
        oglwrap_PrintError(
            GL_INVALID_OPERATION,
            "TransformFeedback::Pause is called but the currently bound "
            "transform feedback object is not active or is paused."
        );
    }

    /// Resumes transform feedback operations on the currently active transform feedback object.
    /// @see glResumeTransformFeedback
    void Resume() {
        oglwrap_PreCheckError();

        glResumeTransformFeedback();
        state = working;

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
