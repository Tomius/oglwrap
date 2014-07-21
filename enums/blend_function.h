// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BLEND_FUNCTION_H_
#define OGLWRAP_ENUMS_BLEND_FUNCTION_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class BlendFunction : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  kZero = GL_ZERO,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
  kOne = GL_ONE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_COLOR)
  kSrcColor = GL_SRC_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_COLOR)
  kOneMinusSrcColor = GL_ONE_MINUS_SRC_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_COLOR)
  kDstColor = GL_DST_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_COLOR)
  kOneMinusDstColor = GL_ONE_MINUS_DST_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA)
  kSrcAlpha = GL_SRC_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_ALPHA)
  kOneMinusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_ALPHA)
  kDstAlpha = GL_DST_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_ALPHA)
  kOneMinusDstAlpha = GL_ONE_MINUS_DST_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_COLOR)
  kConstantColor = GL_CONSTANT_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_COLOR)
  kOneMinusConstantColor = GL_ONE_MINUS_CONSTANT_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_ALPHA)
  kConstantAlpha = GL_CONSTANT_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_ALPHA)
  kOneMinusConstantAlpha = GL_ONE_MINUS_CONSTANT_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA_SATURATE)
  kSrcAlphaSaturate = GL_SRC_ALPHA_SATURATE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_COLOR)
  kSrc1Color = GL_SRC1_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_COLOR)
  kOneMinusSrc1Color = GL_ONE_MINUS_SRC1_COLOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_ALPHA)
  kSrc1Alpha = GL_SRC1_ALPHA,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_ALPHA)
  kOneMinusSrc1Alpha = GL_ONE_MINUS_SRC1_ALPHA,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
