// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_SHADER_TYPE_H_
#define OGLWRAP_ENUMS_SHADER_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class ShaderType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
  kComputeShader = GL_COMPUTE_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
  kVertexShader = GL_VERTEX_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
  kGeometryShader = GL_GEOMETRY_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
  kFragmentShader = GL_FRAGMENT_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
  kTessControlShader = GL_TESS_CONTROL_SHADER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
  kTessEvaluationShader = GL_TESS_EVALUATION_SHADER,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
