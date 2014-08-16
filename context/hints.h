// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_HINTS_H_
#define OGLWRAP_CONTEXT_HINTS_H_

#include "../config.h"
#include "../enums/hint_target.h"
#include "../enums/hint_option.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

inline void Hint(HintTarget target, HintOption option) {
  gl(Hint(GLenum(target), GLenum(option)));
}

inline HintOption Hint(HintTarget target) {
  GLint data;
  gl(GetIntegerv(GLenum(target), &data));
  return HintOption(data);
}

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif
