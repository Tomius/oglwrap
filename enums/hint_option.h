// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_HINT_OPTION_H_
#define OGLWRAP_ENUMS_HINT_OPTION_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class HintOption : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FASTEST)
  Fastest = GL_FASTEST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NICEST)
  Nicest = GL_NICEST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DONT_CARE)
  DontCare = GL_DONT_CARE,
#endif
};

} // enums

} // oglwrap

#endif
