// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_TEXTURE3D_TYPE_H_
#define OGLWRAP_ENUMS_TEXTURE3D_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class Texture3DType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
  kTexture3D = GL_TEXTURE_3D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
  kTexture2DArray = GL_TEXTURE_2D_ARRAY,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
