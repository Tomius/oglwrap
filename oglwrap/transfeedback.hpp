/** @file transfeedback.hpp
    @brief Implements transform feedback functionality.
*/

#pragma once

namespace oglwrap {

#ifdef glGenTransformFeedbacks
#ifdef glDeleteTransformFeedbacks
/// A wrapper class for transform feedback.
/** Transform Feedback is the process of altering the rendering pipeline so that primitives
  * processed by a Vertex Shader and optionally a Geometry Shader will be written to buffer
  * objects. This allows one to preserve the post-transform rendering state of an object and
  * resubmit this data multiple times. */
/// @see glGenTransformFeedbacks, glDeleteTransformFeedbacks
class TransformFeedback : protected RefCounted {
    /// The handle for the TransformFeedback
    ObjectExt<glGenTransformFeedbacks, glDeleteTransformFeedbacks> handle;
    enum TFBstate{none, working, paused} state;
public:
    /// Generates a transform feedback.
    TransformFeedback() : state(none) {}

    /// Creates a transform feedback and activates it. It will work till the variable's lifetime.
    /// @param mode - The primitive type the TFB should use.
    TransformFeedback(TFB_PrimType mode) : state(working) {
        bind();
        begin(mode);
    }

    /// Deletes the transform feedback, if only one instance of it exists.
    /** Also ends it if it's active. In this case it will change the currently active TFB. */
    /// @see glDeleteTransformFeedbacks
    ~TransformFeedback() {
        if(!handle.isDeletable())
            return;
        if(state != none) {
            bind();
            end();
        }
    }

    #ifdef glBindTransformFeedback
    /// Binds the transform feedback.
    /// @see glBindTransformFeedback
    void bind() const {
        gl( BindTransformFeedback(GL_TRANSFORM_FEEDBACK, handle) );
    }
    #endif // glBindTransformFeedback

    #ifdef glBindTransformFeedback
    /// Unbinds the currently bound transform feedback.
    /// @see glBindTransformFeedback
    void unbind() const {
        gl( BindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0) );
    }
    #endif // glBindTransformFeedback

    /// @brief Returns if this is the currently bound transform feedback.
    /// @see glGetIntegerv
    bool isBound() const {
        GLint currentlyBoundTFB;
        gl( GetIntegerv(GL_TRANSFORM_FEEDBACK, &currentlyBoundTFB) );
        OGLWRAP_LAST_BIND_TARGET = "GL_TRANSFORM_FEEDBACK";
        return handle == GLuint(currentlyBoundTFB);
    }

    #ifdef glBeginTransformFeedback
    /// Begins the transform feedback mode.
    /// @param mode - The primitive type the TFB should use.
    /// @see glBeginTransformFeedback
    void begin(TFB_PrimType mode) {
        CHECK_BINDING();
        state = working;
        gl( BeginTransformFeedback(mode) );
    }
    #endif // glBeginTransformFeedback

    #ifdef glEndTransformFeedback
    /// Ends the transform feedback mode.
    /// @see glEndTransformFeedback
    void end() {
        CHECK_BINDING();
        state = none;
        gl( EndTransformFeedback() );
    }
    #endif // glEndTransformFeedback

    #ifdef glPauseTransformFeedback
    /// Pauses transform feedback operations on the currently active transform feedback object.
    /// @see glPauseTransformFeedback
    void pause() {
        CHECK_BINDING();
        state = paused;
        gl( PauseTransformFeedback() );
    }
    #endif // glPauseTransformFeedback

    #ifdef glResumeTransformFeedback
    /// Resumes transform feedback operations on the currently active transform feedback object.
    /// @see glResumeTransformFeedback
    void resume() {
        CHECK_BINDING();
        state = working;
        gl( ResumeTransformFeedback() );
    }
    #endif // glResumeTransformFeedback
};
#endif // glDeleteTransformFeedbacks
#endif // glGenTransformFeedbacks

};
