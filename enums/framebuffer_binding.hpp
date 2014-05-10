#ifndef OGLWRAP_ENUMS_FRAMEBUFFER_BINDING_HPP_
#define OGLWRAP_ENUMS_FRAMEBUFFER_BINDING_HPP_

#include "../config.hpp"
#include "../debug/binding.hpp"
#include "framebuffer_type.hpp"

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

  switch(fbo_t) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER_BINDING)
    case FramebufferType::Read:
      target = FramebufferBinding::Read;
      OGLWRAP_LAST_BIND_TARGET = "GL_READ_FRAMEBUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER_BINDING)
    case FramebufferType::Draw:
      target = FramebufferBinding::Draw;
      OGLWRAP_LAST_BIND_TARGET = "GL_DRAW_FRAMEBUFFER_BINDING";
      break;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BINDING)
    case FramebufferType::Read_Draw:
      target = FramebufferBinding::Read_Draw;
      OGLWRAP_LAST_BIND_TARGET = "GL_FRAMEBUFFER_BINDING";
      break;
#endif
    default:
      abort();
  }

  return target;
}

} // oglwrap

#endif
