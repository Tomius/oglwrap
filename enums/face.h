// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_FACE_H_
#define OGLWRAP_ENUMS_FACE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class Face : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
  kFront = GL_FRONT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
  kBack = GL_BACK,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
  kFrontAndBack = GL_FRONT_AND_BACK,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
