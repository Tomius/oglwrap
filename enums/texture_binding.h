#ifndef OGLWRAP_ENUMS_TEXTURE_BINDING_H_
#define OGLWRAP_ENUMS_TEXTURE_BINDING_H_

#include "../config.h"
#include "../debug/binding.h"
#include "texture_type.h"

namespace oglwrap {

inline namespace enums {

enum class TextureBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D)
  Tex1D = GL_TEXTURE_BINDING_1D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D)
  Tex2D = GL_TEXTURE_BINDING_2D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_3D)
  Tex3D = GL_TEXTURE_BINDING_3D,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_RECTANGLE)
  TexRect = GL_TEXTURE_BINDING_RECTANGLE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D_ARRAY)
  Tex1DArray = GL_TEXTURE_BINDING_1D_ARRAY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D_ARRAY)
  Tex2DArray = GL_TEXTURE_BINDING_2D_ARRAY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_CUBE_MAP)
  TexCubeMap = GL_TEXTURE_BINDING_CUBE_MAP,
#endif
};

} // enums

/// Returns the texture binding point's GLenum for the given texture target.
/** @param tex_t - The texture target.*/
inline TextureBinding GetBindingTarget(TextureType tex_t) {
  TextureBinding target;

  switch(tex_t) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D)
    case TextureType::Tex1D:
      target = TextureBinding::Tex1D;
      OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_1D";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D)
    case TextureType::Tex2D:
      target = TextureBinding::Tex2D;
      OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_2D";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_3D)
    case TextureType::Tex3D:
      target = TextureBinding::Tex3D;
      OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_3D";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_RECTANGLE)
    case TextureType::TexRect:
      target = TextureBinding::TexRect;
      OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_RECTANGLE";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_1D_ARRAY)
    case TextureType::Tex1DArray:
      target = TextureBinding::Tex1DArray;
      OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_1D_ARRAY";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_2D_ARRAY)
    case TextureType::Tex2DArray:
      target = TextureBinding::Tex2DArray;
      OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_2D_ARRAY";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BINDING_CUBE_MAP)
    case TextureType::TexCubeMap:
      target = TextureBinding::TexCubeMap;
      OGLWRAP_LAST_BIND_TARGET = "GL_TEXTURE_BINDING_CUBE_MAP";
      break;
#endif
    default:
      abort();
  }

  return target;
}

} // oglwrap

#endif
