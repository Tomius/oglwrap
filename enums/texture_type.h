#ifndef OGLWRAP_ENUMS_TEXTURE_TYPE_H_
#define OGLWRAP_ENUMS_TEXTURE_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class TextureType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D)
  Tex1D = GL_TEXTURE_1D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
  Tex2D = GL_TEXTURE_2D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
  Tex3D = GL_TEXTURE_3D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
  TexRect = GL_TEXTURE_RECTANGLE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
  Tex1DArray = GL_TEXTURE_1D_ARRAY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
  Tex2DArray = GL_TEXTURE_2D_ARRAY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
  TexCubeMap = GL_TEXTURE_CUBE_MAP,
#endif
};

// Unsupported texture types (yet):
// - GL_TEXTURE_CUBE_MAP_ARRAY
// - GL_TEXTURE_2D_MULTISAMPLE
// - GL_TEXTURE_2D_MULTISAMPLE_ARRAY

} // enums

} // oglwrap

#endif
