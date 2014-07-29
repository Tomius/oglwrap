// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_TRANSFORM_FEEDBACK_BINDING_H_
#define OGLWRAP_ENUMS_TRANSFORM_FEEDBACK_BINDING_H_

#include "../config.h"
#include "../debug/debug_output.h"
#include "./transform_feedback_type.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class TransformFeedbackBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BINDING)
  kTransformFeedbackBinding = GL_TRANSFORM_FEEDBACK_BINDING,
#endif
};

}  // namespace enums
using namespace enums;
inline TransformFeedbackBinding GetBindingTarget(TransformFeedbackType type) {
  TransformFeedbackBinding target;

  switch (type) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BINDING) && defined(GL_TRANSFORM_FEEDBACK)
    case TransformFeedbackType::kTransformFeedback:
      target = TransformFeedbackBinding::kTransformFeedbackBinding;
      DebugOutput::LastUsedBindTarget() = "GL_TRANSFORM_FEEDBACK_BINDING";
      break;
#endif
  }

 return target;
}

}  // namespace oglwrap

#endif
