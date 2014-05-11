#ifndef OGLWRAP_ENUMS_FRAMEBUFFER_TYPE_H_
#define OGLWRAP_ENUMS_FRAMEBUFFER_TYPE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class FramebufferType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
  Read = GL_READ_FRAMEBUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
  Draw = GL_DRAW_FRAMEBUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
  Read_Draw = GL_FRAMEBUFFER,
#endif
};

} // enums

} // oglwrap

#endif
