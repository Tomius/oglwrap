// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_SELECT_BIT_H_
#define OGLWRAP_ENUMS_BUFFER_SELECT_BIT_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class BufferSelectBit : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
  ColorBuffer = GL_COLOR_BUFFER_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
  DepthBuffer = GL_DEPTH_BUFFER_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
  StencilBuffer = GL_STENCIL_BUFFER_BIT,
#endif
};

} // enums

} // oglwrap

#endif
