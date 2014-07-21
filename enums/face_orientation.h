// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_FACE_ORIENTATION_H_
#define OGLWRAP_ENUMS_FACE_ORIENTATION_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class FaceOrientation : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
  kCw = GL_CW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
  kCcw = GL_CCW,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
