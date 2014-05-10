#ifndef OGLWRAP_ENUMS_COMPARE_MODE_HPP_
#define OGLWRAP_ENUMS_COMPARE_MODE_HPP_

#include "../config.hpp"

namespace oglwrap {

inline namespace enums {

enum class CompareMode : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
  None = GL_NONE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPARE_REF_TO_TEXTURE)
  CompareRefToTexture = GL_COMPARE_REF_TO_TEXTURE,
#endif
};

} // enums

} // oglwrap

#endif
