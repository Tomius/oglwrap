// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_PIXEL_DATA_FORMAT_H_
#define OGLWRAP_ENUMS_PIXEL_DATA_FORMAT_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class PixelDataFormat : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_INDEX)
  kStencilIndex = GL_STENCIL_INDEX,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_COMPONENT)
  kDepthComponent = GL_DEPTH_COMPONENT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL)
  kDepthStencil = GL_DEPTH_STENCIL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
  kRed = GL_RED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
  kGreen = GL_GREEN,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
  kBlue = GL_BLUE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG)
  kRg = GL_RG,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
  kRgb = GL_RGB,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
  kRgba = GL_RGBA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
  kBgr = GL_BGR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
  kBgra = GL_BGRA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
  kRedInteger = GL_RED_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
  kGreenInteger = GL_GREEN_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
  kBlueInteger = GL_BLUE_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
  kRgInteger = GL_RG_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
  kRgbInteger = GL_RGB_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
  kRgbaInteger = GL_RGBA_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
  kBgrInteger = GL_BGR_INTEGER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
  kBgraInteger = GL_BGRA_INTEGER,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
