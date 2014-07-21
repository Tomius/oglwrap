// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BASIC_PRIMITIVE_TYPE_H_
#define OGLWRAP_ENUMS_BASIC_PRIMITIVE_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class BasicPrimitiveType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
  kTriangles = GL_TRIANGLES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
  kLines = GL_LINES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
  kPoints = GL_POINTS,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
