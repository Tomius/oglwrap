// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_LOGICAL_OPS_H_
#define OGLWRAP_CONTEXT_LOGICAL_OPS_H_

#include "../config.h"
#include "../enums/color_logic_operation.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

inline void LogicOp(ColorLogicOperation op) {
  gl(LogicOp(GLenum(op)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_LOGIC_OP)
inline ColorLogicOperation LogicOp() {
  GLint data;
  gl(GetIntegerv(GL_COLOR_LOGIC_OP, &data));
  return static_cast<ColorLogicOperation>(data);
}
#endif

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
