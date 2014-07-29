// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_TRANSFORM_FEEDBACK_TYPE_H_
#define OGLWRAP_ENUMS_TRANSFORM_FEEDBACK_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class TransformFeedbackType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK)
  kTransformFeedback = GL_TRANSFORM_FEEDBACK,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
