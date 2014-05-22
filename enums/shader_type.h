// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_SHADER_TYPE_H_
#define OGLWRAP_ENUMS_SHADER_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class ShaderType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
  ComputeShader = GL_COMPUTE_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
  VertexShader = GL_VERTEX_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
  GeometryShader = GL_GEOMETRY_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
  FragmentShader = GL_FRAGMENT_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
  TessControlShader = GL_TESS_CONTROL_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
  TessEvaluationShader = GL_TESS_EVALUATION_SHADER,
#endif
};

} // enums

} // oglwrap

#endif
