// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_RENDERBUFFER_TYPE_H_
#define OGLWRAP_ENUMS_RENDERBUFFER_TYPE_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class RenderbufferType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RENDERBUFFER)
  kRenderbuffer = GL_RENDERBUFFER,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
