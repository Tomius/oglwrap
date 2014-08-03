// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_VERTEX_ARRAY_TARGET_H_
#define OGLWRAP_ENUMS_VERTEX_ARRAY_TARGET_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class VertexArrayTarget : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ARRAY)
  kVertexArray = GL_VERTEX_ARRAY,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
