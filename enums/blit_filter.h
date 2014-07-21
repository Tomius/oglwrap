// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BLIT_FILTER_H_
#define OGLWRAP_ENUMS_BLIT_FILTER_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class BlitFilter : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
  kNearest = GL_NEAREST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
  kLinear = GL_LINEAR,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
