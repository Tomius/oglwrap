// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_POLY_MODE_H_
#define OGLWRAP_ENUMS_POLY_MODE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class PolyMode : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
  Point = GL_POINT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
  Line = GL_LINE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
  Fill = GL_FILL,
#endif
};

} // enums

} // oglwrap

#endif
