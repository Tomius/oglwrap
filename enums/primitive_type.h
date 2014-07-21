// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_PRIMITIVE_TYPE_H_
#define OGLWRAP_ENUMS_PRIMITIVE_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class PrimitiveType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
  kPoints = GL_POINTS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
  kLines = GL_LINES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
  kLineStrip = GL_LINE_STRIP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
  kLineLoop = GL_LINE_LOOP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
  kTriangles = GL_TRIANGLES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
  kTriangleStrip = GL_TRIANGLE_STRIP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
  kTriangleFan = GL_TRIANGLE_FAN,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
  kLinesAdjacency = GL_LINES_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
  kLineStripAdjacency = GL_LINE_STRIP_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
  kTrianglesAdjacency = GL_TRIANGLES_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
  kTriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
  kPatches = GL_PATCHES,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
