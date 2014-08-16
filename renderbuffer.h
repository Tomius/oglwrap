// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_RENDERBUFFER_H_
#define OGLWRAP_RENDERBUFFER_H_

#include "./config.h"
#include "./globjects.h"
#include "enums/renderbuffer_target.h"
#include "enums/renderbuffer_binding.h"
#include "enums/pixel_data_internal_format.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenRenderbuffers) && defined(glDeleteRenderbuffers))
/// A buffer that servers as a storage for a framebuffer.
struct Renderbuffer {
  static const RenderbufferTarget target;
  globjects::Renderbuffer handle;
};

class BoundRenderbuffer {
 public:
  explicit BoundRenderbuffer(const Renderbuffer& buffer)
      : moved_(false) {
    gl(GetIntegerv(GL_RENDERBUFFER_BINDING,
                   reinterpret_cast<GLint*>(&last_binding_)));
    gl(BindBuffer(GL_RENDERBUFFER, buffer.handle));
  }

  BoundRenderbuffer(BoundRenderbuffer&& bound_buffer)
      : last_binding_(bound_buffer.last_binding_)
      , moved_(bound_buffer.moved_) {
    bound_buffer.moved_ = true;
  }

  ~BoundRenderbuffer() {
    if (!moved_) { gl(BindBuffer(GL_RENDERBUFFER, last_binding_)); }
  }

  // No copy
  BoundRenderbuffer(const BoundRenderbuffer&) = delete;
  BoundRenderbuffer& operator=(const BoundRenderbuffer&) = delete;

#if OGLWRAP_DEFINE_EVERYTHING || defined(glRenderbufferStorage)
  /// Establish data storage, format and dimensions of a renderbuffer object's image.
  void storage(PixelDataInternalFormat internal_format,
               GLsizei width, GLsizei height) {
    gl(RenderbufferStorage(
      GL_RENDERBUFFER, GLenum(internal_format), width, height));
  }
#endif  // glRenderbufferStorage

#if OGLWRAP_DEFINE_EVERYTHING || defined(glRenderbufferStorageMultisample)
  /// Establish data storage, format, dimensions and sample count of a renderbuffer object's image.
  void storageMultisample(GLsizei samples, PixelDataInternalFormat internal_format,
                          GLsizei width, GLsizei height) {
    gl(RenderbufferStorageMultisample(
      GL_RENDERBUFFER, samples, GLenum(internal_format), width, height));
  }
#endif  // glRenderbufferStorageMultisample

  private:
    GLuint last_binding_;
    bool moved_;
};
#endif  // glGenRenderbuffers && glDeleteRenderbuffers

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_FRAMEBUFFER_H_

