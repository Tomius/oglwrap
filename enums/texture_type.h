// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_TEXTURE_TYPE_H_
#define OGLWRAP_ENUMS_TEXTURE_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class TextureType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D)
  Texture1D = GL_TEXTURE_1D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
  Texture2D = GL_TEXTURE_2D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
  Texture3D = GL_TEXTURE_3D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
  TextureRectangle = GL_TEXTURE_RECTANGLE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
  Texture1DArray = GL_TEXTURE_1D_ARRAY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
  Texture2DArray = GL_TEXTURE_2D_ARRAY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
  TextureCubeMap = GL_TEXTURE_CUBE_MAP,
#endif
};

} // enums

} // oglwrap

#endif
