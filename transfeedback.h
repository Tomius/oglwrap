// Copyright (c) 2014, Tamas Csala

/** @file transfeedback.h
    @brief Implements transform feedback functionality.
*/

#ifndef OGLWRAP_TRANSFORMFEEDBACK_H_
#define OGLWRAP_TRANSFORMFEEDBACK_H_

#include "general.h"
#include "globjects.h"
#include "debug/binding.h"
#include "enums/basic_primitive_type.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING \
    || (defined(glGenTransformFeedbacks) && defined(glDeleteTransformFeedbacks))
/**
 * @brief A wrapper class for transform feedback.
 *
 * Transform Feedback is the process of altering the rendering pipeline so that
 * primitives processed by a Vertex Shader and optionally a Geometry Shader will
 * be written to buffer objects. This allows one to preserve the post-transform
 * rendering state of an object and resubmit this data multiple times.
 * @see glGenTransformFeedbacks, glDeleteTransformFeedbacks
 */
class TransformFeedback {
  /// The handle for the TransformFeedback
  globjects::TransformFeedback tfb_;
public:
  TransformFeedback() = default;

  // It doesn't make much sense to copy a TFB
  TransformFeedback(const TransformFeedback&) = delete;
  TransformFeedback& operator=(const TransformFeedback&) = delete;

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindTransformFeedback)
  /// Binds the transform feedback.
  /** @see glBindTransformFeedback */
  void bind() const {
    gl(BindTransformFeedback(GL_TRANSFORM_FEEDBACK, tfb_));
  }
#endif // glBindTransformFeedback

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindTransformFeedback)
  /// Unbinds the currently bound transform feedback.
  /** @see glBindTransformFeedback */
  static void Unbind() {
    gl(BindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0));
  }
  /// Unbinds the currently bound transform feedback.
  /** @see glBindTransformFeedback */
  BIND_CHECKED void unbind() const {
    OGLWRAP_CHECK_BINDING2();
    Unbind();
  }
#endif // glBindTransformFeedback

  /// Returns if this is the currently bound transform feedback.
  /** @see glGetIntegerv */
  bool isBound() const {
    GLint currentlyBoundTFB;
    gl(GetIntegerv(GL_TRANSFORM_FEEDBACK, &currentlyBoundTFB));

    #if OGLWRAP_DEBUG
      DebugOutput::LastUsedBindTarget() = "GL_TRANSFORM_FEEDBACK";
    #endif

    return tfb_ == GLuint(currentlyBoundTFB);
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBeginTransformFeedback)
  /// Begins the transform feedback mode.
  /** @param mode - The primitive type the TFB should use.
    * @see glBeginTransformFeedback */
  static void Begin(BasicPrimitiveType mode) {
    gl(BeginTransformFeedback(GLenum(mode)));
  }
  /// Begins the transform feedback mode.
  /** @param mode - The primitive type the TFB should use.
    * @see glBeginTransformFeedback */
  BIND_CHECKED void begin(BasicPrimitiveType mode) {
    OGLWRAP_CHECK_BINDING();
    Begin(mode);
  }
#endif // glBeginTransformFeedback

#if OGLWRAP_DEFINE_EVERYTHING || defined(glEndTransformFeedback)
  /// Ends the transform feedback mode.
  /** @see glEndTransformFeedback */
  static void End() {
    gl(EndTransformFeedback());
  }
  /// Ends the transform feedback mode.
  /** @see glEndTransformFeedback */
  BIND_CHECKED void end() {
    OGLWRAP_CHECK_BINDING();
    End();
  }
#endif // glEndTransformFeedback

#if OGLWRAP_DEFINE_EVERYTHING || defined(glPauseTransformFeedback)
  /**
   * @brief Pauses transform feedback operations on the currently active
   *        transform feedback object.
   *
   * @see glPauseTransformFeedback
   */
  static void Pause() {
    gl(PauseTransformFeedback());
  }

  /**
   * @brief Pauses transform feedback operations on the currently active
   *        transform feedback object.
   *
   * @see glPauseTransformFeedback
   */
  BIND_CHECKED void pause() {
    OGLWRAP_CHECK_BINDING();
    Pause();
  }
#endif // glPauseTransformFeedback

#if OGLWRAP_DEFINE_EVERYTHING || defined(glResumeTransformFeedback)
  /**
   * @brief Resumes transform feedback operations on the currently active
   *        transform feedback object.
   *
   * @see glResumeTransformFeedback
   */
  static void Resume() {
    gl(ResumeTransformFeedback());
  }
  /**
   * @brief Resumes transform feedback operations on the currently active
   *        transform feedback object.
   *
   * @see glResumeTransformFeedback
   */
  BIND_CHECKED void resume() {
    OGLWRAP_CHECK_BINDING();
    Resume();
  }
#endif // glResumeTransformFeedback
};

/**
 * @brief Activates TransformFeedback for the lifetime of this variable.
 *
 * Assumes that no other tfb will be used during this.
 */
class TransformFeedbackActivator {
  TransformFeedback tfb_;
  bool paused_;
public:
  TransformFeedbackActivator(BasicPrimitiveType mode) : paused_(false) {
    // Bind and start
    tfb_.bind();
    tfb_.begin(mode);
  }

  ~TransformFeedbackActivator() {
    // End and unbind this
    tfb_.end();
    tfb_.unbind();
  }

  void pause() {
    if (!paused_) {
      tfb_.pause();
      paused_ = true;
    }
  }

  void resume() {
    if (paused_) {
      tfb_.resume();
      paused_ = false;
    }
  }
};
#endif // glGenTransformFeedbacks && glDeleteTransformFeedbacks

} // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif // OGLWRAP_TRANSFORMFEEDBACK_H_

