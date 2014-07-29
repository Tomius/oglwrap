// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_FRAMEBUFFER_BINDING_H_
#define OGLWRAP_ENUMS_FRAMEBUFFER_BINDING_H_

#include "../config.h"
#include "../debug/debug_output.h"
#include "./framebuffer_type.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class FramebufferBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER_BINDING)
  kReadFramebufferBinding = GL_READ_FRAMEBUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER_BINDING)
  kDrawFramebufferBinding = GL_DRAW_FRAMEBUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BINDING)
  kFramebufferBinding = GL_FRAMEBUFFER_BINDING,
#endif
};

}  // namespace enums
using namespace enums;
inline FramebufferBinding GetBindingTarget(FramebufferType type) {
  FramebufferBinding target;

  switch (type) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER_BINDING) && defined(GL_READ_FRAMEBUFFER)
    case FramebufferType::kReadFramebuffer:
      target = FramebufferBinding::kReadFramebufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_READ_FRAMEBUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER_BINDING) && defined(GL_DRAW_FRAMEBUFFER)
    case FramebufferType::kDrawFramebuffer:
      target = FramebufferBinding::kDrawFramebufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_DRAW_FRAMEBUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BINDING) && defined(GL_FRAMEBUFFER)
    case FramebufferType::kFramebuffer:
      target = FramebufferBinding::kFramebufferBinding;
      DebugOutput::LastUsedBindTarget() = "GL_FRAMEBUFFER_BINDING";
      break;
#endif
  }

 return target;
}

}  // namespace oglwrap

#endif
