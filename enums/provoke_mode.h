// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_PROVOKE_MODE_H_
#define OGLWRAP_ENUMS_PROVOKE_MODE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class ProvokeMode : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
  kFirstVertexConvention = GL_FIRST_VERTEX_CONVENTION,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
  kLastVertexConvention = GL_LAST_VERTEX_CONVENTION,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
