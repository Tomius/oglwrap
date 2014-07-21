// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_HINT_OPTION_H_
#define OGLWRAP_ENUMS_HINT_OPTION_H_

#include "../config.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class HintOption : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FASTEST)
  kFastest = GL_FASTEST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NICEST)
  kNicest = GL_NICEST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DONT_CARE)
  kDontCare = GL_DONT_CARE,
#endif
};

}  // namespace enums
using namespace enums;
}  // namespace oglwrap

#endif
