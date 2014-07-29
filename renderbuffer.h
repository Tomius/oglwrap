// Copyright (c) 2014, Tamas Csala

/** @file renderbuffer.h
    @brief Implements a wrapper for renderbuffer objects
*/

#ifndef OGLWRAP_RENDERBUFFER_H_
#define OGLWRAP_RENDERBUFFER_H_

#include "./config.h"
#include "./globjects.h"
#include "enums/renderbuffer_type.h"
#include "enums/renderbuffer_binding.h"
#include "enums/pixel_data_internal_format.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenRenderbuffers) && defined(glDeleteRenderbuffers))
/// A buffer that servers as a storage for a framebuffer.
/** @see glGenRenderbuffers, glDeleteRenderbuffers */
class Renderbuffer {
 public:
#if OGLWRAP_DEFINE_EVERYTHING || defined(glRenderbufferStorage)
  /// Establish data storage, format and dimensions of a renderbuffer object's image.
  /** @see glRenderbufferStorage */
  void storage(PixelDataInternalFormat internal_format,
               GLsizei width, GLsizei height);
#endif  // glRenderbufferStorage

#if OGLWRAP_DEFINE_EVERYTHING || defined(glRenderbufferStorageMultisample)
  /// Establish data storage, format, dimensions and sample count of a renderbuffer object's image.
  /** @see glRenderbufferStorageMultisample */
  void storageMultisample(GLsizei samples, PixelDataInternalFormat internal_format,
                          GLsizei width, GLsizei height);
#endif  // glRenderbufferStorageMultisample

  /// Returns the handle for this object.
  const glObject& expose() const { return renderbuffer_; }

 private:
  globjects::Renderbuffer renderbuffer_;
};
#endif  // glGenRenderbuffers && glDeleteRenderbuffers

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_FRAMEBUFFER_H_

