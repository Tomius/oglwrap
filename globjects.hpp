/** @file globjects.hpp
    @brief Implements wrappers for OpenGL objects
*/

#ifndef OGLWRAP_GLOBJECTS_HPP_
#define OGLWRAP_GLOBJECTS_HPP_

#include <cmath>
#include <memory>

#include "config.hpp"
#include "enums.hpp"
#include "enums/shader_type.hpp"

#include "define_internal_macros.hpp"

namespace oglwrap {

#if !OGLWRAP_INITIALIZE_GL_OBJECTS_ON_FIRST_USE
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
#else // OGLWRAP_INITIALIZE_GL_OBJECTS_ON_FIRST_USE
  /// A class for managing OpenGL resources.
  class glObject {
  protected:
    /// The C handle for the object.
    std::shared_ptr<GLuint> handle_;
    glObject() : handle_(new GLuint{0}) {}

  public:
    /// Returns if this is the only instance of this glObject
    bool unique() const { return handle_.unique(); }

    virtual void constructor() const = 0;

    /// Returns the C handle for the object.
    operator GLuint() const {
      if(*handle_ == 0) {
        constructor();
      }

      return *handle_;
    }
  };
#endif // !OGLWRAP_INITIALIZE_GL_OBJECTS_ON_FIRST_USE

namespace globjects {

#if !OGLWRAP_INITIALIZE_GL_OBJECTS_ON_FIRST_USE

  #if OGLWRAP_DEFINE_EVERYTHING || \
      (defined(glCreateShader) && defined(glDeleteShader))
    template<ShaderType shader_t>
    class Shader : public glObject {
    public:
      Shader() { *handle_ = gl(CreateShader(shader_t)); }
      ~Shader() {
        if(unique()) gl(DeleteShader(*handle_));
      }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
      (defined(glCreateProgram) && defined(glDeleteProgram))
    class Program : public glObject {
    public:
      Program() { *handle_ = gl(CreateProgram()); }
      ~Program() {
        if(unique()) gl(DeleteProgram(*handle_));
      }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
      (defined(glGenBuffers) && defined(glDeleteBuffers))
    class Buffer : public glObject {
      public:
        Buffer() { gl(GenBuffers(1, handle_.get())); }
        ~Buffer() {
          if(unique()) gl(DeleteBuffers(1, handle_.get()));
        }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
      (defined(glGenRenderbuffers) && defined(glDeleteRenderbuffers))
    class Renderbuffer : public glObject {
      public:
        Renderbuffer() { gl(GenRenderbuffers(1, handle_.get())); }
        ~Renderbuffer() {
          if(unique()) gl(DeleteRenderbuffers(1, handle_.get()));
        }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
      (defined(glGenFramebuffers) && defined(glDeleteFramebuffers))
    class Framebuffer : public glObject {
      public:
        Framebuffer() { gl(GenFramebuffers(1, handle_.get())); }
        ~Framebuffer() {
          if(unique()) gl(DeleteFramebuffers(1, handle_.get()));
        }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
      (defined(glGenTransformFeedbacks) && defined(glDeleteTransformFeedbacks))
    class TransformFeedback : public glObject {
      public:
        TransformFeedback() { gl(GenTransformFeedbacks(1, handle_.get())); }
        ~TransformFeedback() {
          if(unique()) gl(DeleteTransformFeedbacks(1, handle_.get()));
        }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
      (defined(glGenVertexArrays) && defined(glDeleteVertexArrays))
    class VertexArray : public glObject {
      public:
        VertexArray() { gl(GenVertexArrays(1, handle_.get())); }
        ~VertexArray() {
          if(unique()) gl(DeleteVertexArrays(1, handle_.get()));
        }
    };
  #endif

  class Texture : public glObject {
    public:
      Texture() { gl(GenTextures(1, handle_.get())); }
      ~Texture() {
        if(unique()) gl(DeleteTextures(1, handle_.get()));
      }
  };

#else // OGLWRAP_INITIALIZE_GL_OBJECTS_ON_FIRST_USE

  #if OGLWRAP_DEFINE_EVERYTHING || \
      (defined(glCreateShader) && defined(glDeleteShader))
    template<ShaderType shader_t>
    class Shader : public glObject {
      protected: void constructor() const override {
        *handle_ = gl(CreateShader(GLenum(shader_t)));
      }
      public: ~Shader() {
        if(unique()) gl(DeleteShader(*handle_));
      }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
      (defined(glCreateProgram) && defined(glDeleteProgram))
    class Program : public glObject {
      protected: void constructor() const override {
        *handle_ = gl(CreateProgram());
      }
      public: ~Program() {
        if(unique()) {
          gl(DeleteProgram(*handle_));
        }
      }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenBuffers) && defined(glDeleteBuffers))
    class Buffer : public glObject {
      protected: void constructor() const override {
        gl(GenBuffers(1, handle_.get()));
      }
      public: ~Buffer() {
        if(unique()) {
          gl(DeleteBuffers(1, handle_.get()));
        }
      }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenRenderbuffers) && defined(glDeleteRenderbuffers))
    class Renderbuffer : public glObject {
      protected: void constructor() const override {
        gl(GenRenderbuffers(1, handle_.get()));
      }
      public: ~Renderbuffer() {
        if(unique()) {
          gl(DeleteRenderbuffers(1, handle_.get()));
        }
      }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenFramebuffers) && defined(glDeleteFramebuffers))
    class Framebuffer : public glObject {
      protected: void constructor() const override {
        gl(GenFramebuffers(1, handle_.get()));
      }
      public: ~Framebuffer() {
        if(unique()) {
          gl(DeleteFramebuffers(1, handle_.get()));
        }
      }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenTransformFeedbacks) && defined(glDeleteTransformFeedbacks))
    class TransformFeedback : public glObject {
      protected: void constructor() const override {
        gl(GenTransformFeedbacks(1, handle_.get()));
      }
      public: ~TransformFeedback() {
        if(unique()) {
          gl(DeleteTransformFeedbacks(1, handle_.get()));
        }
      }
    };
  #endif

  #if OGLWRAP_DEFINE_EVERYTHING || \
    (defined(glGenVertexArrays) && defined(glDeleteVertexArrays))
    class VertexArray : public glObject {
      protected: void constructor() const override {
        gl(GenVertexArrays(1, handle_.get()));
      }
      public: ~VertexArray() {
        if(unique()) {
          gl(DeleteVertexArrays(1, handle_.get()));
        }
      }
    };
  #endif

  class Texture : public glObject {
    protected: void constructor() const override {
      gl(GenTextures(1, handle_.get()));
    }
    public: ~Texture() {
      if(unique()) {
        gl(DeleteTextures(1, handle_.get()));
      }
    }
  };

#endif  // !OGLWRAP_INITIALIZE_GL_OBJECTS_ON_FIRST_USE

} // namespace globjects

} // namespace oglwrap

#include "undefine_internal_macros.hpp"

#endif // OGLWRAP_GLOBJECTS_HPP_
