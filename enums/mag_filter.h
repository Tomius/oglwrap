#ifndef OGLWRAP_ENUMS_MAG_FILTER_H_
#define OGLWRAP_ENUMS_MAG_FILTER_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class MagFilter : GLenum {
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
