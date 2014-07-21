// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_WRAP_MODE_H_
#define OGLWRAP_ENUMS_WRAP_MODE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class WrapMode : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_EDGE)
  kClampToEdge = GL_CLAMP_TO_EDGE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPEAT)
  kRepeat = GL_REPEAT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_BORDER)
  kClampToBorder = GL_CLAMP_TO_BORDER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIRRORED_REPEAT)
  kMirroredRepeat = GL_MIRRORED_REPEAT,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
