// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_MIN_FILTER_H_
#define OGLWRAP_ENUMS_MIN_FILTER_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class MinFilter : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
  kNearest = GL_NEAREST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
  kLinear = GL_LINEAR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_NEAREST)
  kNearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_LINEAR)
  kNearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_NEAREST)
  kLinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_LINEAR)
  kLinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
