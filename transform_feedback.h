// Copyright (c) 2014, Tamas Csala

/** @file transform_feedback.h
    @brief Implements transform feedback functionality.
*/

#ifndef OGLWRAP_TRANSFORM_FEEDBACK_H_
#define OGLWRAP_TRANSFORM_FEEDBACK_H_

#include "./globjects.h"
#include "enums/transform_feedback_type.h"
#include "enums/transform_feedback_binding.h"
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
 public:
  TransformFeedback() = default;

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBeginTransformFeedback)
  /// Begins the transform feedback mode.
  /** @param mode - The primitive type the TFB should use.
    * @see glBeginTransformFeedback */
  void begin(BasicPrimitiveType mode);
#endif  // glBeginTransformFeedback

#if OGLWRAP_DEFINE_EVERYTHING || defined(glEndTransformFeedback)
  /// Ends the transform feedback mode.
  /** @see glEndTransformFeedback */
  void end();
#endif  // glEndTransformFeedback

#if OGLWRAP_DEFINE_EVERYTHING || defined(glPauseTransformFeedback)
  /**
   * @brief Pauses transform feedback operations on the currently active
   *        transform feedback object.
   *
   * @see glPauseTransformFeedback
   */
  void pause();
#endif  // glPauseTransformFeedback

#if OGLWRAP_DEFINE_EVERYTHING || defined(glResumeTransformFeedback)
  /**
   * @brief Resumes transform feedback operations on the currently active
   *        transform feedback object.
   *
   * @see glResumeTransformFeedback
   */
  void resume();
#endif  // glResumeTransformFeedback

  /// Returns the handle for the transform feedback.
  const glObject& expose() const { return tfb_; }

 private:
  /// The handle for the TransformFeedback
  globjects::TransformFeedback tfb_;
};

/**
 * @brief Activates TransformFeedback for the lifetime of this variable.
 *
 * Assumes that no other tfb will be used during this.
 */
class TransformFeedbackActivator {
 public:
  explicit TransformFeedbackActivator(BasicPrimitiveType mode);
  ~TransformFeedbackActivator();

  void pause();
  void resume();

 private:
  TransformFeedback tfb_;
  bool paused_;
};
#endif  // glGenTransformFeedbacks && glDeleteTransformFeedbacks

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_TRANSFORMFEEDBACK_H_

