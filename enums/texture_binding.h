// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_TEXTURE_BINDING_H_
#define OGLWRAP_ENUMS_TEXTURE_BINDING_H_

#include "../config.h"
#include "../debug/binding.h"
#include "texture_type.h"

namespace oglwrap {

inline namespace enums {

enum class TextureBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D)
  TextureBinding1D = GL_TEXTURE_BINDING_1D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D)
  TextureBinding2D = GL_TEXTURE_BINDING_2D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_3D)
  TextureBinding3D = GL_TEXTURE_BINDING_3D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_RECTANGLE)
  TextureBindingRectangle = GL_TEXTURE_BINDING_RECTANGLE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D_ARRAY)
  TextureBinding1DArray = GL_TEXTURE_BINDING_1D_ARRAY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D_ARRAY)
  TextureBinding2DArray = GL_TEXTURE_BINDING_2D_ARRAY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_CUBE_MAP)
  TextureBindingCubeMap = GL_TEXTURE_BINDING_CUBE_MAP,
#endif
};

} // enums

inline TextureBinding GetBindingTarget(TextureType type) {
  TextureBinding target;

  switch (type) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D) && defined(GL_TEXTURE_1D)
    case TextureType::Texture1D:
      target = TextureBinding::TextureBinding1D;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_1D";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D) && defined(GL_TEXTURE_2D)
    case TextureType::Texture2D:
      target = TextureBinding::TextureBinding2D;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_2D";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_3D) && defined(GL_TEXTURE_3D)
    case TextureType::Texture3D:
      target = TextureBinding::TextureBinding3D;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_3D";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_RECTANGLE) && defined(GL_TEXTURE_RECTANGLE)
    case TextureType::TextureRectangle:
      target = TextureBinding::TextureBindingRectangle;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_RECTANGLE";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D_ARRAY) && defined(GL_TEXTURE_1D_ARRAY)
    case TextureType::Texture1DArray:
      target = TextureBinding::TextureBinding1DArray;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_1D_ARRAY";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D_ARRAY) && defined(GL_TEXTURE_2D_ARRAY)
    case TextureType::Texture2DArray:
      target = TextureBinding::TextureBinding2DArray;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_2D_ARRAY";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_CUBE_MAP) && defined(GL_TEXTURE_CUBE_MAP)
    case TextureType::TextureCubeMap:
      target = TextureBinding::TextureBindingCubeMap;
      DebugOutput::LastUsedBindTarget() = "GL_TEXTURE_BINDING_CUBE_MAP";
      break;
#endif
  }

 return target;
}

} // oglwrap

#endif
