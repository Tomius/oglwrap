// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_HINT_TARGET_H_
#define OGLWRAP_ENUMS_HINT_TARGET_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class HintTarget : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
  FragmentShaderDerivativeHint = GL_FRAGMENT_SHADER_DERIVATIVE_HINT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH_HINT)
  LineSmoothHint = GL_LINE_SMOOTH_HINT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH_HINT)
  PolygonSmoothHint = GL_POLYGON_SMOOTH_HINT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_COMPRESSION_HINT)
  TextureCompressionHint = GL_TEXTURE_COMPRESSION_HINT,
#endif
};

} // enums

} // oglwrap

#endif
