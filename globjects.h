// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_GLOBJECTS_H_
#define OGLWRAP_GLOBJECTS_H_

#include <cmath>
#include <memory>

#include "config.h"
#include "enums/shader_type.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/// A class for managing OpenGL resources.
class glObject {
 public:
  /// Returns the C handle for the object.
  operator GLuint() const { return handle_; }

  // It shouldn't be copyable
  glObject(const glObject&) = delete;
  glObject& operator=(const glObject&) = delete;

 protected:
  /// The C handle for the object.
  GLuint handle_;

  glObject() : handle_{0} {}
};

namespace globjects {

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glCreateShader) && defined(glDeleteShader))
  class Shader : public glObject {
   public:
    explicit Shader(ShaderType shader_t) {
      handle_ = gl(CreateShader(GLenum(shader_t)));
    }
    ~Shader() { gl(DeleteShader(handle_)); }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glCreateProgram) && defined(glDeleteProgram))
  class Program : public glObject {
  public:
    Program() { handle_ = gl(CreateProgram()); }
    ~Program() { gl(DeleteProgram(handle_)); }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenBuffers) && defined(glDeleteBuffers))
  class Buffer : public glObject {
    public:
      Buffer() { gl(GenBuffers(1, &handle_)); }
      ~Buffer() { gl(DeleteBuffers(1, &handle_)); }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenRenderbuffers) && defined(glDeleteRenderbuffers))
  class Renderbuffer : public glObject {
    public:
      Renderbuffer() { gl(GenRenderbuffers(1, &handle_)); }
      ~Renderbuffer() { gl(DeleteRenderbuffers(1, &handle_)); }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenFramebuffers) && defined(glDeleteFramebuffers))
  class Framebuffer : public glObject {
    public:
      Framebuffer() { gl(GenFramebuffers(1, &handle_)); }
      ~Framebuffer() { gl(DeleteFramebuffers(1, &handle_)); }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenTransformFeedbacks) && defined(glDeleteTransformFeedbacks))
  class TransformFeedback : public glObject {
    public:
      TransformFeedback() { gl(GenTransformFeedbacks(1, &handle_)); }
      ~TransformFeedback() { gl(DeleteTransformFeedbacks(1, &handle_)); }
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenVertexArrays) && defined(glDeleteVertexArrays))
  class VertexArray : public glObject {
    public:
      VertexArray() { gl(GenVertexArrays(1, &handle_)); }
      ~VertexArray() { gl(DeleteVertexArrays(1, &handle_)); }
  };
#endif

class Texture : public glObject {
  public:
    Texture() { gl(GenTextures(1, &handle_)); }
    ~Texture() { gl(DeleteTextures(1, &handle_)); }
};

}  // namespace globjects
}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_GLOBJECTS_H_
