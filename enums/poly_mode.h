// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_POLY_MODE_H_
#define OGLWRAP_ENUMS_POLY_MODE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class PolyMode : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
  kPoint = GL_POINT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
  kLine = GL_LINE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
  kFill = GL_FILL,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
