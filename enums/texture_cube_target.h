// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_TEXTURE_CUBE_TARGET_H_
#define OGLWRAP_ENUMS_TEXTURE_CUBE_TARGET_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class TextureCubeTarget : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
  TextureCubeMapPositiveX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
  TextureCubeMapNegativeX = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
  TextureCubeMapPositiveY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
  TextureCubeMapNegativeY = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
  TextureCubeMapPositiveZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
  TextureCubeMapNegativeZ = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
#endif
};

} // enums

} // oglwrap

#endif
