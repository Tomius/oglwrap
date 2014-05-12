// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_FACE_H_
#define OGLWRAP_ENUMS_FACE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class Face : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
  Front = GL_FRONT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
  Back = GL_BACK,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
  FrontAndBack = GL_FRONT_AND_BACK,
#endif
};

} // enums

} // oglwrap

#endif
