// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_TEXTURE_BINDING_H_
#define OGLWRAP_ENUMS_TEXTURE_BINDING_H_

#include "../config.h"
#include "../debug/debug_output.h"
#include "./texture_type.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class TextureBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D)
  kTextureBinding1D = GL_TEXTURE_BINDING_1D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D)
  kTextureBinding2D = GL_TEXTURE_BINDING_2D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_3D)
  kTextureBinding3D = GL_TEXTURE_BINDING_3D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_RECTANGLE)
  kTextureBindingRectangle = GL_TEXTURE_BINDING_RECTANGLE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D_ARRAY)
  kTextureBinding1DArray = GL_TEXTURE_BINDING_1D_ARRAY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D_ARRAY)
  kTextureBinding2DArray = GL_TEXTURE_BINDING_2D_ARRAY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_CUBE_MAP)
  kTextureBindingCubeMap = GL_TEXTURE_BINDING_CUBE_MAP,
#endif
};

}  // namespace enums
using namespace enums;
inline TextureBinding GetBindingTarget(TextureType type) {
  TextureBinding target;

  switch (type) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D) && defined(GL_TEXTURE_1D)
    case TextureType::kTexture1D:
      target = TextureBinding::kTextureBinding1D;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_1D";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D) && defined(GL_TEXTURE_2D)
    case TextureType::kTexture2D:
      target = TextureBinding::kTextureBinding2D;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_2D";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_3D) && defined(GL_TEXTURE_3D)
    case TextureType::kTexture3D:
      target = TextureBinding::kTextureBinding3D;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_3D";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_RECTANGLE) && defined(GL_TEXTURE_RECTANGLE)
    case TextureType::kTextureRectangle:
      target = TextureBinding::kTextureBindingRectangle;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_RECTANGLE";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D_ARRAY) && defined(GL_TEXTURE_1D_ARRAY)
    case TextureType::kTexture1DArray:
      target = TextureBinding::kTextureBinding1DArray;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_1D_ARRAY";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D_ARRAY) && defined(GL_TEXTURE_2D_ARRAY)
    case TextureType::kTexture2DArray:
      target = TextureBinding::kTextureBinding2DArray;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_2D_ARRAY";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_CUBE_MAP) && defined(GL_TEXTURE_CUBE_MAP)
    case TextureType::kTextureCubeMap:
      target = TextureBinding::kTextureBindingCubeMap;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_CUBE_MAP";
      break;
#endif
  }

 return target;
}

}  // namespace oglwrap

#endif
