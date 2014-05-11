/** @file globjects.hpp
    @brief Implements wrappers for OpenGL objects
*/

#ifndef OGLWRAP_GLOBJECTS_H_
#define OGLWRAP_GLOBJECTS_H_

#include <cmath>
#include <memory>

#include "config.h"
#include "enums.h"
#include "enums/shader_type.h"

#include "define_internal_macros.h"

namespace oglwrap {

/// A class for managing OpenGL resources.
class glObject {
protected:
  /// The C handle for the object.
  std::shared_ptr<GLuint> handle_;
  glObject() : handle_(new GLuint{0}) {}

public:
  /// Returns if this is the only instance of this glObject
  bool unique() const { return handle_.unique(); }

  /// Returns the C handle for the object.
  operator GLuint() const {
     return *handle_;
   }
};

namespace globjects {

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glCreateShader) && defined(glDeleteShader))
  template<ShaderType shader_t>
  class Shader : public glObject {
  public:
    Shader() { *handle_ = gl(CreateShader(GLenum(shader_t))); }
    ~Shader() {
      if (unique()) gl(DeleteShader(*handle_));
    }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glCreateProgram) && defined(glDeleteProgram))
  class Program : public glObject {
  public:
    Program() { *handle_ = gl(CreateProgram()); }
    ~Program() {
      if (unique()) gl(DeleteProgram(*handle_));
    }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenBuffers) && defined(glDeleteBuffers))
  class Buffer : public glObject {
    public:
      Buffer() { gl(GenBuffers(1, handle_.get())); }
      ~Buffer() {
        if (unique()) gl(DeleteBuffers(1, handle_.get()));
      }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenRenderbuffers) && defined(glDeleteRenderbuffers))
  class Renderbuffer : public glObject {
    public:
      Renderbuffer() { gl(GenRenderbuffers(1, handle_.get())); }
      ~Renderbuffer() {
        if (unique()) gl(DeleteRenderbuffers(1, handle_.get()));
      }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenFramebuffers) && defined(glDeleteFramebuffers))
  class Framebuffer : public glObject {
    public:
      Framebuffer() { gl(GenFramebuffers(1, handle_.get())); }
      ~Framebuffer() {
        if (unique()) gl(DeleteFramebuffers(1, handle_.get()));
      }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenTransformFeedbacks) && defined(glDeleteTransformFeedbacks))
  class TransformFeedback : public glObject {
    public:
      TransformFeedback() { gl(GenTransformFeedbacks(1, handle_.get())); }
      ~TransformFeedback() {
        if (unique()) gl(DeleteTransformFeedbacks(1, handle_.get()));
      }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenVertexArrays) && defined(glDeleteVertexArrays))
  class VertexArray : public glObject {
    public:
      VertexArray() { gl(GenVertexArrays(1, handle_.get())); }
      ~VertexArray() {
        if (unique()) gl(DeleteVertexArrays(1, handle_.get()));
      }
  };
#endif

class Texture : public glObject {
  public:
    Texture() { gl(GenTextures(1, handle_.get())); }
    ~Texture() {
      if (unique()) gl(DeleteTextures(1, handle_.get()));
    }
};

} // namespace globjects

} // namespace oglwrap

#include "undefine_internal_macros.h"

#endif // OGLWRAP_GLOBJECTS_H_
