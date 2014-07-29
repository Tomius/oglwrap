// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_TRANSFORM_FEEDBACK_INL_H_
#define OGLWRAP_TRANSFORM_FEEDBACK_INL_H_

#include "./transform_feedback.h"
#include "context/binding.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING \
    || (defined(glGenTransformFeedbacks) && defined(glDeleteTransformFeedbacks))

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBeginTransformFeedback)
inline void TransformFeedback::begin(BasicPrimitiveType mode) {
  OGLWRAP_CHECK_BINDING();
  gl(BeginTransformFeedback(GLenum(mode)));
}
#endif  // glBeginTransformFeedback

#if OGLWRAP_DEFINE_EVERYTHING || defined(glEndTransformFeedback)
inline void TransformFeedback::end() {
  OGLWRAP_CHECK_BINDING();
  gl(EndTransformFeedback());
}
#endif  // glEndTransformFeedback

#if OGLWRAP_DEFINE_EVERYTHING || defined(glPauseTransformFeedback)
inline void TransformFeedback::pause() {
  OGLWRAP_CHECK_BINDING();
  gl(PauseTransformFeedback());
}
#endif  // glPauseTransformFeedback

#if OGLWRAP_DEFINE_EVERYTHING || defined(glResumeTransformFeedback)
inline void TransformFeedback::resume() {
  OGLWRAP_CHECK_BINDING();
  gl(ResumeTransformFeedback());
}
#endif  // glResumeTransformFeedback

inline TransformFeedbackActivator::TransformFeedbackActivator(BasicPrimitiveType mode)
    : paused_(false) {
  Bind(tfb_);
  tfb_.begin(mode);
}

inline TransformFeedbackActivator::~TransformFeedbackActivator() {
  tfb_.end();
  Unbind(tfb_);
}

inline void TransformFeedbackActivator::pause() {
  if (!paused_) {
    tfb_.pause();
    paused_ = true;
  }
}

inline void TransformFeedbackActivator::resume() {
  if (paused_) {
    tfb_.resume();
    paused_ = false;
  }
}

#endif  // glGenTransformFeedbacks && glDeleteTransformFeedbacks

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_TRANSFORMFEEDBACK_INL_H_

