// Copyright (c) Tamas Csala

/** @file globjects.h
    @brief Implements wrappers for OpenGL objects
*/

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

  // But it should be moveable
  glObject(glObject&& other) noexcept
      : handle_{other.handle_}
      , ownership_{other.ownership_} {
    other.handle_ = 0;
    other.ownership_ = false;
  }
  glObject& operator=(glObject&& other) noexcept {
    std::swap(handle_, other.handle_);
    std::swap(ownership_, other.ownership_);
    return *this;
  }

  bool hasOwnership() const { return ownership_; }

 protected:
  /// The C handle for the object.
  GLuint handle_ = 0;

  /// Specifies if this object has the ownership of the entity behind the handle
  bool ownership_ = false;

  glObject() = default;
};

namespace globjects {

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glCreateShader) && defined(glDeleteShader))
  class Shader : public glObject {
   public:
    explicit Shader(GLuint handle) {
      handle_ = handle;
      ownership_ = false;
    }

    explicit Shader(ShaderType shader_t) {
      handle_ = gl(CreateShader(GLenum(shader_t)));
      ownership_ = true;
    }

    ~Shader() {
      if (ownership_) {
        gl(DeleteShader(handle_));
      }
    }

    Shader(Shader&&) noexcept = default;
    Shader& operator=(Shader&&) noexcept = default;
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glCreateProgram) && defined(glDeleteProgram))
  class Program : public glObject {
  public:
    explicit Program(GLuint handle) {
      handle_ = handle;
      ownership_ = false;
    }

    Program() {
      handle_ = gl(CreateProgram());
      ownership_ = true;
    }

    ~Program() {
      if (ownership_) {
        gl(DeleteProgram(handle_));
      }
    }

    Program(Program&&) noexcept = default;
    Program& operator=(Program&&) noexcept = default;
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenBuffers) && defined(glDeleteBuffers))
  class Buffer : public glObject {
   public:
    explicit Buffer(GLuint handle) {
      handle_ = handle;
      ownership_ = false;
    }

    Buffer() {
      gl(GenBuffers(1, &handle_));
      ownership_ = true;
    }

    ~Buffer() {
      if (ownership_) {
        gl(DeleteBuffers(1, &handle_));
      }
    }

    Buffer(Buffer&&) noexcept = default;
    Buffer& operator=(Buffer&&) noexcept = default;
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenRenderbuffers) && defined(glDeleteRenderbuffers))
  class Renderbuffer : public glObject {
   public:
    explicit Renderbuffer(GLuint handle) {
      handle_ = handle;
      ownership_ = false;
    }

    Renderbuffer() {
      gl(GenRenderbuffers(1, &handle_));
      ownership_ = true;
    }

    ~Renderbuffer() {
      if (ownership_) {
        gl(DeleteRenderbuffers(1, &handle_));
      }
    }

    Renderbuffer(Renderbuffer&&) noexcept = default;
    Renderbuffer& operator=(Renderbuffer&&) noexcept = default;
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenFramebuffers) && defined(glDeleteFramebuffers))
  class Framebuffer : public glObject {
   public:
    explicit Framebuffer(GLuint handle) {
      handle_ = handle;
      ownership_ = false;
    }

    Framebuffer() {
      gl(GenFramebuffers(1, &handle_));
      ownership_ = true;
    }

    ~Framebuffer() {
      if (ownership_) {
        gl(DeleteFramebuffers(1, &handle_));
      }
    }

    Framebuffer(Framebuffer&&) noexcept = default;
    Framebuffer& operator=(Framebuffer&&) noexcept = default;
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenTransformFeedbacks) && defined(glDeleteTransformFeedbacks))
  class TransformFeedback : public glObject {
   public:
    explicit TransformFeedback(GLuint handle) {
      handle_ = handle;
      ownership_ = false;
    }

    TransformFeedback() {
      gl(GenTransformFeedbacks(1, &handle_));
      ownership_ = true;
    }

    ~TransformFeedback() {
      if (ownership_) {
        gl(DeleteTransformFeedbacks(1, &handle_));
      }
    }

    TransformFeedback(TransformFeedback&&) noexcept = default;
    TransformFeedback& operator=(TransformFeedback&&) noexcept = default;
  };
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenVertexArrays) && defined(glDeleteVertexArrays))
  class VertexArray : public glObject {
   public:
    explicit VertexArray(GLuint handle) {
      handle_ = handle;
      ownership_ = false;
    }

    VertexArray() {
      gl(GenVertexArrays(1, &handle_));
      ownership_ = true;
    }

    ~VertexArray() {
      if (ownership_) {
        gl(DeleteVertexArrays(1, &handle_));
      }
    }

    VertexArray(VertexArray&&) noexcept = default;
    VertexArray& operator=(VertexArray&&) noexcept = default;
  };
#endif

class Texture : public glObject {
 public:
  explicit Texture(GLuint handle) {
    handle_ = handle;
    ownership_ = false;
  }

  Texture() {
    gl(GenTextures(1, &handle_));
    ownership_ = true;
  }

  ~Texture() {
    if (ownership_) {
      gl(DeleteTextures(1, &handle_));
    }
  }

  Texture(Texture&&) noexcept = default;
  Texture& operator=(Texture&&) noexcept = default;
};

}  // namespace globjects
}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_GLOBJECTS_H_
