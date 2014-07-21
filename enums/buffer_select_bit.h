// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_BUFFER_SELECT_BIT_H_
#define OGLWRAP_ENUMS_BUFFER_SELECT_BIT_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class BufferSelectBit : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
  kColorBufferBit = GL_COLOR_BUFFER_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
  kDepthBufferBit = GL_DEPTH_BUFFER_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
  kStencilBufferBit = GL_STENCIL_BUFFER_BIT,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
