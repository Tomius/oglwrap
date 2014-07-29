// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_RENDERBUFFER_INL_H_
#define OGLWRAP_RENDERBUFFER_INL_H_

#include "./renderbuffer.h"
#include "context/binding.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenRenderbuffers) && defined(glDeleteRenderbuffers))

#if OGLWRAP_DEFINE_EVERYTHING || defined(glRenderbufferStorage)
inline void Renderbuffer::storage(PixelDataInternalFormat internal_format,
                                  GLsizei width, GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(RenderbufferStorage(
      GL_RENDERBUFFER, GLenum(internal_format), width, height));
}
#endif  // glRenderbufferStorage

#if OGLWRAP_DEFINE_EVERYTHING || defined(glRenderbufferStorageMultisample)
inline void Renderbuffer::storageMultisample(
    GLsizei samples, PixelDataInternalFormat internal_format,
    GLsizei width, GLsizei height) {
  OGLWRAP_CHECK_BINDING();
  gl(RenderbufferStorageMultisample(
      GL_RENDERBUFFER, samples, GLenum(internal_format), width, height));
}
#endif  // glRenderbufferStorageMultisample

#endif  // glGenRenderbuffers && glDeleteRenderbuffers

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_FRAMEBUFFER_H_

