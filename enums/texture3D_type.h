// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_TEXTURE3D_TYPE_H_
#define OGLWRAP_ENUMS_TEXTURE3D_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class Texture3DType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
  Tex3D = GL_TEXTURE_3D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
  Tex2DArray = GL_TEXTURE_2D_ARRAY,
#endif
};

} // enums

} // oglwrap

#endif
