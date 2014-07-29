// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_VERTEX_ARRAY_BINDING_H_
#define OGLWRAP_ENUMS_VERTEX_ARRAY_BINDING_H_

#include "../config.h"
#include "../debug/debug_output.h"
#include "./vertex_array_type.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class VertexArrayBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ARRAY_BINDING)
  kVertexArrayBinding = GL_VERTEX_ARRAY_BINDING,
#endif
};

}  // namespace enums
using namespace enums;
inline VertexArrayBinding GetBindingTarget(VertexArrayType type) {
  VertexArrayBinding target;

  switch (type) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ARRAY_BINDING) && defined(GL_VERTEX_ARRAY)
    case VertexArrayType::kVertexArray:
      target = VertexArrayBinding::kVertexArrayBinding;
      DebugOutput::LastUsedBindTarget() = "GL_VERTEX_ARRAY_BINDING";
      break;
#endif
  }

 return target;
}

}  // namespace oglwrap

#endif
