/** @file transfeedback.hpp
    @brief Implements transform feedback functionality.
*/

#ifndef OGLWRAP_TRANSFORMFEEDBACK_HPP_
#define OGLWRAP_TRANSFORMFEEDBACK_HPP_

namespace oglwrap {

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glGenTransformFeedbacks) && defined(glDeleteTransformFeedbacks))
/// A wrapper class for transform feedback.
/** Transform Feedback is the process of altering the rendering pipeline so that primitives
  * processed by a Vertex Shader and optionally a Geometry Shader will be written to buffer
  * objects. This allows one to preserve the post-transform rendering state of an object and
  * resubmit this data multiple times.
  * @see glGenTransformFeedbacks, glDeleteTransformFeedbacks */
class TransformFeedback : protected RefCounted {
  /// The handle for the TransformFeedback
  ObjectExt<glGenTransformFeedbacks, glDeleteTransformFeedbacks> handle_;
  enum TFBstate {TFB_STATE_NONE, TFB_STATE_WORKING, TFB_STATE_PAUSED} state_;
public:
  /// Generates a transform feedback.
  TransformFeedback() : state_(TFB_STATE_NONE) {}

  /// Creates a transform feedback and activates it. It will work till the variable's lifetime.
  /** @param mode - The primitive type the TFB should use. */
  TransformFeedback(TFB_PrimType mode) : state_(TFB_STATE_WORKING) {
    bind();
    begin(mode);
  }

  /// Deletes the transform feedback, if only one instance of it exists.
  /** Also ends it if it's active. In this case it will change the currently active TFB.
    * @see glDeleteTransformFeedbacks */
  ~TransformFeedback() {
    if(!handle_.isDeletable()) {
      return;
    }
    if(state_ != TFB_STATE_NONE) {
      bind();
      end();
    }
  }

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindTransformFeedback)
  /// Binds the transform feedback.
  /** @see glBindTransformFeedback */
  void bind() const {
    gl( BindTransformFeedback(GL_TRANSFORM_FEEDBACK, handle_) );
  }
#endif // glBindTransformFeedback

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBindTransformFeedback)
  /// Unbinds the currently bound transform feedback.
  /** @see glBindTransformFeedback */
  static void Unbind() {
    gl( BindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0) );
  }
  /// Unbinds the currently bound transform feedback.
  /** @see glBindTransformFeedback */
  BIND_CHECKED void unbind() const {
    CHECK_BINDING2();
    Unbind();
  }
#endif // glBindTransformFeedback

  /// Returns if this is the currently bound transform feedback.
  /** @see glGetIntegerv */
  bool isBound() const {
    GLint currentlyBoundTFB;
    gl( GetIntegerv(GL_TRANSFORM_FEEDBACK, &currentlyBoundTFB) );
    OGLWRAP_LAST_BIND_TARGET = "GL_TRANSFORM_FEEDBACK";
    return handle_ == GLuint(currentlyBoundTFB);
  }

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glBeginTransformFeedback)
  /// Begins the transform feedback mode.
  /** @param mode - The primitive type the TFB should use.
    * @see glBeginTransformFeedback */
  static void Begin(TFB_PrimType mode) {
    gl( BeginTransformFeedback(mode) );
  }
  /// Begins the transform feedback mode.
  /** @param mode - The primitive type the TFB should use.
    * @see glBeginTransformFeedback */
  BIND_CHECKED void begin(TFB_PrimType mode) {
    CHECK_BINDING();
    state_ = TFB_STATE_WORKING;
    Begin(mode);
  }
#endif // glBeginTransformFeedback

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glEndTransformFeedback)
  /// Ends the transform feedback mode.
  /** @see glEndTransformFeedback */
  static void End() {
    gl( EndTransformFeedback() );
  }
  /// Ends the transform feedback mode.
  /** @see glEndTransformFeedback */
  BIND_CHECKED void end() {
    CHECK_BINDING();
    state_ = TFB_STATE_NONE;
    End();
  }
#endif // glEndTransformFeedback

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glPauseTransformFeedback)
  /// Pauses transform feedback operations on the currently active transform feedback object.
  /** @see glPauseTransformFeedback */
  static void Pause() {
    gl( PauseTransformFeedback() );
  }
  /// Pauses transform feedback operations on the currently active transform feedback object.
  /** @see glPauseTransformFeedback */
  BIND_CHECKED void pause() {
    CHECK_BINDING();
    state_ = TFB_STATE_PAUSED;
    Pause();
  }
#endif // glPauseTransformFeedback

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glResumeTransformFeedback)
  /// Resumes transform feedback operations on the currently active transform feedback object.
  /** @see glResumeTransformFeedback */
  static void Resume() {
    gl( ResumeTransformFeedback() );
  }
  /// Resumes transform feedback operations on the currently active transform feedback object.
  /** @see glResumeTransformFeedback */
  BIND_CHECKED void resume() {
    CHECK_BINDING();
    state_ = TFB_STATE_WORKING;
    Resume();
  }
#endif // glResumeTransformFeedback
};
#endif // glGenTransformFeedbacks && glDeleteTransformFeedbacks

} // namespace oglwrap

#endif // OGLWRAP_TRANSFORMFEEDBACK_HPP_

