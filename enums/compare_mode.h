// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_COMPARE_MODE_H_
#define OGLWRAP_ENUMS_COMPARE_MODE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class CompareMode : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
  kNone = GL_NONE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPARE_REF_TO_TEXTURE)
  kCompareRefToTexture = GL_COMPARE_REF_TO_TEXTURE,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
