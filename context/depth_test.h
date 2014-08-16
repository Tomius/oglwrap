// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_DEPTH_TEST_H_
#define OGLWRAP_CONTEXT_DEPTH_TEST_H_

#include "../config.h"
#include "../enums/compare_func.h"
#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {
inline void DepthFunc(CompareFunc function) {
  gl(DepthFunc(GLenum(function)));
}

inline CompareFunc DepthFunc() {
  GLint data;
  gl(GetIntegerv(GL_DEPTH_FUNC, &data));
  return static_cast<CompareFunc>(data);
}

}  // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
