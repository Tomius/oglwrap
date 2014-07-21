// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_TEXTURE_CUBE_TARGET_H_
#define OGLWRAP_ENUMS_TEXTURE_CUBE_TARGET_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class TextureCubeTarget : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
  kTextureCubeMapPositiveX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
  kTextureCubeMapNegativeX = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
  kTextureCubeMapPositiveY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
  kTextureCubeMapNegativeY = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
  kTextureCubeMapPositiveZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
  kTextureCubeMapNegativeZ = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
