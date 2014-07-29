// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_RENDERBUFFER_BINDING_H_
#define OGLWRAP_ENUMS_RENDERBUFFER_BINDING_H_

#include "../config.h"
#include "../debug/debug_output.h"
#include "./renderbuffer_type.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class RenderbufferBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RENDERBUFFER_BINDING)
  kRenderbufferBinding = GL_RENDERBUFFER_BINDING,
#endif
};

}  // namespace enums
using namespace enums;
inline RenderbufferBinding GetBindingTarget(RenderbufferType type) {
  RenderbufferBinding target;

  switch (type) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RENDERBUFFER_BINDING) && defined(GL_RENDERBUFFER)
    case RenderbufferType::kRenderbuffer:
      target = RenderbufferBinding::kRenderbufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_RENDERBUFFER_BINDING";
      break;
#endif
  }

 return target;
}

}  // namespace oglwrap

#endif
