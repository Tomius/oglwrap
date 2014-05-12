// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_PIXEL_DATA_FORMAT_H_
#define OGLWRAP_ENUMS_PIXEL_DATA_FORMAT_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum PixelDataFormat {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_INDEX)
  StencilIndex = GL_STENCIL_INDEX,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_COMPONENT)
  DepthComponent = GL_DEPTH_COMPONENT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL)
  DepthStencil = GL_DEPTH_STENCIL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
  Red = GL_RED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
  Green = GL_GREEN,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
  Blue = GL_BLUE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG)
  RG = GL_RG,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
  RGB = GL_RGB,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
  RGBA = GL_RGBA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
  BGR = GL_BGR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
  BGRA = GL_BGRA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
  Red_Integer = GL_RED_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
  Green_Integer = GL_GREEN_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
  Blue_Integer = GL_BLUE_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
  RG_Integer = GL_RG_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
  RGB_Integer = GL_RGB_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
  RGBA_Integer = GL_RGBA_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
  BGR_Integer = GL_BGR_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
  BGRA_Integer = GL_BGRA_INTEGER,
#endif
};

} // enums

} // oglwrap

#endif
