// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_FRAMEBUFFER_TYPE_H_
#define OGLWRAP_ENUMS_FRAMEBUFFER_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class FramebufferType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
  kReadFramebuffer = GL_READ_FRAMEBUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
  kDrawFramebuffer = GL_DRAW_FRAMEBUFFER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
  kFramebuffer = GL_FRAMEBUFFER,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
