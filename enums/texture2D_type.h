#ifndef OGLWRAP_ENUMS_TEXTURE2D_TYPE_H_
#define OGLWRAP_ENUMS_TEXTURE2D_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class Texture2DType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
  Tex2D = GL_TEXTURE_2D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
  Tex1DArray = GL_TEXTURE_1D_ARRAY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
  TexRect = GL_TEXTURE_RECTANGLE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
  TexCubeMap = GL_TEXTURE_CUBE_MAP,
#endif
};

} // enums

} // oglwrap

#endif
