// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_TRANSFORM_FEEDBACK_H_
#define OGLWRAP_TRANSFORM_FEEDBACK_H_

#include "./globjects.h"
#include "enums/transform_feedback_target.h"
#include "enums/transform_feedback_binding.h"
#include "enums/basic_primitive_type.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING \
    || (defined(glGenTransformFeedbacks) && defined(glDeleteTransformFeedbacks))

struct TransformFeedback {
  static const TransformFeedbackTarget target;
  globjects::TransformFeedback handle;
};

class BoundTransformFeedback {
 public:
  BoundTransformFeedback(const TransformFeedback& buffer,
                         BasicPrimitiveType mode)
    : moved_(false) {
      gl(GetIntegerv(GL_TRANSFORM_FEEDBACK_BINDING,
                     reinterpret_cast<GLint*>(&last_binding_)));
      gl(BindTransformFeedback(GL_TRANSFORM_FEEDBACK, buffer.handle));
      gl(BeginTransformFeedback(GLenum(mode)));
  }

  BoundTransformFeedback(BoundTransformFeedback&& other)
      : last_binding_(other.last_binding_)
      , moved_(other.moved_) {
    other.moved_ = true;
  }

  ~BoundTransformFeedback() {
    if (!moved_) {
      gl(EndTransformFeedback());
      gl(BindTransformFeedback(GL_TRANSFORM_FEEDBACK, last_binding_));
    }
  }

  // No copy
  BoundTransformFeedback(const BoundTransformFeedback&) = delete;
  BoundTransformFeedback& operator=(const BoundTransformFeedback&) = delete;

#if OGLWRAP_DEFINE_EVERYTHING || defined(glPauseTransformFeedback)

  void pause() {
    gl(PauseTransformFeedback());
  }
#endif  // glPauseTransformFeedback

#if OGLWRAP_DEFINE_EVERYTHING || defined(glResumeTransformFeedback)

  void resume() {
    gl(ResumeTransformFeedback());
  }
#endif  // glResumeTransformFeedback

 private:
  GLuint last_binding_;
  bool moved_;
};
#endif  // glGenTransformFeedbacks && glDeleteTransformFeedbacks

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_TRANSFORMFEEDBACK_H_

