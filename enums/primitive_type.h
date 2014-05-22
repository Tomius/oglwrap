// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_PRIMITIVE_TYPE_H_
#define OGLWRAP_ENUMS_PRIMITIVE_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class PrimitiveType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
  Points = GL_POINTS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
  Lines = GL_LINES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
  LineStrip = GL_LINE_STRIP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
  LineLoop = GL_LINE_LOOP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
  Triangles = GL_TRIANGLES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
  TriangleStrip = GL_TRIANGLE_STRIP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
  TriangleFan = GL_TRIANGLE_FAN,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
  LinesAdjacency = GL_LINES_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
  LineStripAdjacency = GL_LINE_STRIP_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
  TrianglesAdjacency = GL_TRIANGLES_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
  TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
  Patches = GL_PATCHES,
#endif
};

} // enums

} // oglwrap

#endif
