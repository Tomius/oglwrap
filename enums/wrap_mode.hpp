#ifndef OGLWRAP_ENUMS_WRAP_MODE_HPP_
#define OGLWRAP_ENUMS_WRAP_MODE_HPP_

#include "../config.hpp"

namespace oglwrap {

inline namespace enums {

enum class WrapMode : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_EDGE)
  ClampToEdge = GL_CLAMP_TO_EDGE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPEAT)
  Repeat = GL_REPEAT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_BORDER)
  ClampToBorder = GL_CLAMP_TO_BORDER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIRRORED_REPEAT)
  MirroredRepeat = GL_MIRRORED_REPEAT,
#endif
};

} // enums

} // oglwrap

#endif
