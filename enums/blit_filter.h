// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BLIT_FILTER_H_
#define OGLWRAP_ENUMS_BLIT_FILTER_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class BlitFilter : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
  Nearest = GL_NEAREST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
  Linear = GL_LINEAR,
#endif
};

} // enums

} // oglwrap

#endif
