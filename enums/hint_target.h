// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_HINT_TARGET_H_
#define OGLWRAP_ENUMS_HINT_TARGET_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class HintTarget : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
  kFragmentShaderDerivativeHint = GL_FRAGMENT_SHADER_DERIVATIVE_HINT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH_HINT)
  kLineSmoothHint = GL_LINE_SMOOTH_HINT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH_HINT)
  kPolygonSmoothHint = GL_POLYGON_SMOOTH_HINT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_COMPRESSION_HINT)
  kTextureCompressionHint = GL_TEXTURE_COMPRESSION_HINT,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
