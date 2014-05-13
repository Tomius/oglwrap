// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_STENCIL_OPERATION_H_
#define OGLWRAP_ENUMS_STENCIL_OPERATION_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class StencilOperation : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
  Keep = GL_KEEP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  Zero = GL_ZERO,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
  Replace = GL_REPLACE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
  Incr = GL_INCR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
  Decr = GL_DECR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
  Invert = GL_INVERT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
  IncrWrap = GL_INCR_WRAP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
  DecrWrap = GL_DECR_WRAP,
#endif
};

} // enums

} // oglwrap

#endif
