// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_TEXTURE_CUBE_TARGET_H_
#define OGLWRAP_ENUMS_TEXTURE_CUBE_TARGET_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class TextureCubeTarget : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
  PosX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
  NegX = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
  PosY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
  NegY = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
  PosZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
  NegZ = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
#endif
};

} // enums

} // oglwrap

#endif
