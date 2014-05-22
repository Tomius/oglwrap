// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_FACE_ORIENTATION_H_
#define OGLWRAP_ENUMS_FACE_ORIENTATION_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class FaceOrientation : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
  Cw = GL_CW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
  Ccw = GL_CCW,
#endif
};

} // enums

} // oglwrap

#endif
