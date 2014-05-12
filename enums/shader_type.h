// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_SHADER_TYPE_H_
#define OGLWRAP_ENUMS_SHADER_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class ShaderType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
  Compute = GL_COMPUTE_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
  Vertex = GL_VERTEX_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
  Geometry = GL_GEOMETRY_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
  Fragment = GL_FRAGMENT_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
  TessControl = GL_TESS_CONTROL_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
  TessEval = GL_TESS_EVALUATION_SHADER,
#endif
};

} // enums

} // oglwrap

#endif
