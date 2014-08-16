// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_STENCIL_TEST_H_
#define OGLWRAP_CONTEXT_STENCIL_TEST_H_

#include "../config.h"
#include "../enums/face.h"
#include "../enums/compare_func.h"
#include "../enums/stencil_operation.h"
#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

inline void StencilFunc(CompareFunc func,
                        GLint ref=GLint(0),
                        GLuint mask=~GLuint(0)) {
  gl(StencilFunc(GLenum(func), ref, mask));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glStencilFuncSeparate)
inline void StencilFuncSeparate(Face face,
                                CompareFunc func,
                                GLint ref=GLint(0),
                                GLuint mask=~GLuint(0)) {
  gl(StencilFuncSeparate(GLenum(face), GLenum(func), ref, mask));
}
#endif

inline void StencilOp(StencilOperation sfail = StencilOperation::kKeep,
                      StencilOperation dfail = StencilOperation::kKeep,
                      StencilOperation dpass = StencilOperation::kKeep) {
  gl(StencilOp(GLenum(sfail), GLenum(dfail), GLenum(dpass)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glStencilOpSeparate)
inline void StencilOpSeparate(Face face,
                              StencilOperation sfail = StencilOperation::kKeep,
                              StencilOperation dfail = StencilOperation::kKeep,
                              StencilOperation dpass = StencilOperation::kKeep) {
  gl(StencilOpSeparate(GLenum(face), GLenum(sfail),
                       GLenum(dfail), GLenum(dpass)));
}
#endif

inline CompareFunc StencilFunc(bool backface = false) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_FUNC, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_FUNC, &data));
  }
  return static_cast<CompareFunc>(data);
}

inline GLuint StencilValueMask(bool backface = true) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_VALUE_MASK, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_VALUE_MASK, &data));
  }
  return data;
}

inline GLuint StencilRef(bool backface = false) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_REF, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_REF, &data));
  }
  return data;
}

inline StencilOperation StencilFail(bool backface = false) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_FAIL, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_FAIL, &data));
  }
  return static_cast<StencilOperation>(data);
}

inline StencilOperation StencilPassDepthFail(bool backface = false) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_PASS_DEPTH_FAIL, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_PASS_DEPTH_FAIL, &data));
  }
  return static_cast<StencilOperation>(data);
}

inline StencilOperation StencilPassDepthPass(bool backface = false) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_PASS_DEPTH_PASS, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_PASS_DEPTH_PASS, &data));
  }
  return static_cast<StencilOperation>(data);
}

}  // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
