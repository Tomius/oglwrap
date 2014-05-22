// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BLEND_FUNCTION_H_
#define OGLWRAP_ENUMS_BLEND_FUNCTION_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class BlendFunction : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  Zero = GL_ZERO,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
  One = GL_ONE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_COLOR)
  SrcColor = GL_SRC_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_COLOR)
  OneMinusSrcColor = GL_ONE_MINUS_SRC_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_COLOR)
  DstColor = GL_DST_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_COLOR)
  OneMinusDstColor = GL_ONE_MINUS_DST_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA)
  SrcAlpha = GL_SRC_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_ALPHA)
  OneMinusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_ALPHA)
  DstAlpha = GL_DST_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_ALPHA)
  OneMinusDstAlpha = GL_ONE_MINUS_DST_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_COLOR)
  ConstantColor = GL_CONSTANT_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_COLOR)
  OneMinusConstantColor = GL_ONE_MINUS_CONSTANT_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_ALPHA)
  ConstantAlpha = GL_CONSTANT_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_ALPHA)
  OneMinusConstantAlpha = GL_ONE_MINUS_CONSTANT_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA_SATURATE)
  SrcAlphaSaturate = GL_SRC_ALPHA_SATURATE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_COLOR)
  Src1Color = GL_SRC1_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_COLOR)
  OneMinusSrc1Color = GL_ONE_MINUS_SRC1_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_ALPHA)
  Src1Alpha = GL_SRC1_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_ALPHA)
  OneMinusSrc1Alpha = GL_ONE_MINUS_SRC1_ALPHA,
#endif
};

} // enums

} // oglwrap

#endif
