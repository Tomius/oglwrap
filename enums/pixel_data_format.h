// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_PIXEL_DATA_FORMAT_H_
#define OGLWRAP_ENUMS_PIXEL_DATA_FORMAT_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class PixelDataFormat : GLenum {
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
  Rg = GL_RG,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
  Rgb = GL_RGB,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
  Rgba = GL_RGBA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
  Bgr = GL_BGR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
  Bgra = GL_BGRA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
  RedInteger = GL_RED_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
  GreenInteger = GL_GREEN_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
  BlueInteger = GL_BLUE_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
  RgInteger = GL_RG_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
  RgbInteger = GL_RGB_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
  RgbaInteger = GL_RGBA_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
  BgrInteger = GL_BGR_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
  BgraInteger = GL_BGRA_INTEGER,
#endif
};

} // enums

} // oglwrap

#endif
