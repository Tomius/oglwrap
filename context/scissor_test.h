// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_SCISSOR_TEST_H_
#define OGLWRAP_CONTEXT_SCISSOR_TEST_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "../config.h"
#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

inline void Scissor(GLint left, GLint bottom, GLsizei width, GLsizei height) {
  gl(Scissor(left, bottom, width, height));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glScissorIndexed)
inline void Scissor(GLuint viewport, GLint left, GLint bottom,
                    GLsizei width, GLsizei height) {
  gl(ScissorIndexed(viewport, left, bottom, width, height));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glScissorIndexedv)
  inline void Scissor(GLuint viewport, GLint *v) {
  gl(ScissorIndexedv(viewport, v));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glScissorArrayv)
inline void ScissorArray(GLuint first, GLuint count, GLint *v) {
  gl(ScissorArrayv(first, count, v));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_BOX)
inline glm::ivec4 ScissorBox() {
  GLint data[4];
  gl(GetIntegerv(GL_SCISSOR_BOX, data));
  return glm::ivec4{data[0], data[1], data[2], data[3]};
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING \
    || defined(GL_SCISSOR_BOX) && defined(glScissorIndexed)
inline glm::ivec4 ScissorBox(GLuint viewport) {
  GLint data[4];
  gl(GetIntegeri_v(GL_SCISSOR_BOX, viewport, data));
  return glm::ivec4{data[0], data[1], data[2], data[3]};
}
#endif

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
