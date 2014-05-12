// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_FRAMEBUFFER_BINDING_H_
#define OGLWRAP_ENUMS_FRAMEBUFFER_BINDING_H_

#include "../config.h"
#include "../debug/binding.h"
#include "framebuffer_type.h"

namespace oglwrap {

inline namespace enums {

enum class FramebufferBinding : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER_BINDING)
  Read = GL_READ_FRAMEBUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER_BINDING)
  Draw = GL_DRAW_FRAMEBUFFER_BINDING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BINDING)
  Read_Draw = GL_FRAMEBUFFER_BINDING,
#endif
};

} // enums

/// Returns the framebuffer binding point's GLenum for the given framebuffer target.
/** @param fbo_t - The framebuffer target. */
inline FramebufferBinding GetBindingTarget(FramebufferType fbo_t) {
  FramebufferBinding target;

  switch (fbo_t) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER_BINDING)
    case FramebufferType::Read:
      target = FramebufferBinding::Read;
      DebugOutput::LastUsedBindTarget() = "GL_READ_FRAMEBUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER_BINDING)
    case FramebufferType::Draw:
      target = FramebufferBinding::Draw;
      DebugOutput::LastUsedBindTarget() = "GL_DRAW_FRAMEBUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BINDING)
    case FramebufferType::Read_Draw:
      target = FramebufferBinding::Read_Draw;
      DebugOutput::LastUsedBindTarget() = "GL_FRAMEBUFFER_BINDING";
      break;
#endif
    default:
      abort();
  }

  return target;
}

} // oglwrap

#endif
