#ifndef OGLWRAP_ENUMS_SWIZZLE_MODE_HPP_
#define OGLWRAP_ENUMS_SWIZZLE_MODE_HPP_

#include "../config.hpp"

namespace oglwrap {

inline namespace enums {

enum class SwizzleMode : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
  Red = GL_RED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
  Green = GL_GREEN,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
  Blue = GL_BLUE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALPHA)
  Alpha = GL_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  Zero = GL_ZERO,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
  One = GL_ONE,
#endif
};

} // enums

} // oglwrap

#endif
