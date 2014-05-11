#ifndef OGLWRAP_ENUMS_COMPARE_MODE_H_
#define OGLWRAP_ENUMS_COMPARE_MODE_H_

#include "../config.h"

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
