// Copyright (c) Tamas Csala

#ifndef OGLWRAP_CONTEXT_BINDING_H_
#define OGLWRAP_CONTEXT_BINDING_H_

#include "../buffer.h"
#include "../renderbuffer.h"
#include "../framebuffer.h"
#include "../transform_feedback.h"
#include "../vertex_array.h"
#include "../textures/texture_base.h"
#include "../program.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

// Buffer
#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindBuffer)
template<BufferType BUFFER_TYPE>
void Bind(const BufferObject<BUFFER_TYPE>& buffer) {
  gl(BindBuffer(GLenum(BUFFER_TYPE), buffer.expose()));
}

template<BufferType BUFFER_TYPE>
void Unbind(const BufferObject<BUFFER_TYPE>&) {
  gl(BindBuffer(GLenum(BUFFER_TYPE), 0));
}

inline void Unbind(BufferType BUFFER_TYPE) {
  gl(BindBuffer(GLenum(BUFFER_TYPE), 0));
}

template<BufferType BUFFER_TYPE>
bool IsBound(const BufferObject<BUFFER_TYPE>& buffer) {
  GLint currently_bound_buffer;
  gl(GetIntegerv(GLenum(GetBindingTarget(BUFFER_TYPE)),
                 &currently_bound_buffer));

  return buffer.expose() == GLuint(currently_bound_buffer);
}

template<BufferType BUFFER_TYPE>
BufferObject<BUFFER_TYPE> GetCurrentlyBoundObject(const BufferObject<BUFFER_TYPE>*) {
  GLint currently_bound_buffer;
  gl(GetIntegerv(GLenum(GetBindingTarget(BUFFER_TYPE)),
                 &currently_bound_buffer));
  return BufferObject<BUFFER_TYPE>{GLuint(currently_bound_buffer)};
}
#endif

// IndexedBuffer
#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindBufferBase)
template<IndexedBufferType BUFFER_TYPE, GLuint index>
void Bind(const IndexedBufferObject<BUFFER_TYPE, index>& buffer) {
  gl(BindBufferBase(GLenum(BUFFER_TYPE), index, buffer.expose()));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindBufferRange)
template<IndexedBufferType BUFFER_TYPE, GLuint index>
void BindRange(const IndexedBufferObject<BUFFER_TYPE, index>& buffer,
               GLintptr offset, GLsizeiptr size) {
  gl(BindBufferRange(GLenum(BUFFER_TYPE), index, offset, size, buffer.expose()));
}
#endif

template<IndexedBufferType BUFFER_TYPE, GLuint index>
void Unbind(const IndexedBufferObject<BUFFER_TYPE, index>&) {
  gl(BindBufferBase(GLenum(BUFFER_TYPE), index, 0));
}

inline void Unbind(IndexedBufferType BUFFER_TYPE, GLuint index) {
  gl(BindBufferBase(GLenum(BUFFER_TYPE), index, 0));
}

template<IndexedBufferType BUFFER_TYPE, GLuint index>
bool IsBound(const IndexedBufferObject<BUFFER_TYPE, index>& buffer) {
  GLint currently_bound_buffer;
  gl(GetIntegeri_v(GLenum(GetBindingTarget(BUFFER_TYPE)), index,
                   &currently_bound_buffer));
  return buffer.expose() == GLuint(currently_bound_buffer);
}

template<IndexedBufferType BUFFER_TYPE, GLuint index>
IndexedBufferObject<BUFFER_TYPE, index> GetCurrentlyBoundObject(const IndexedBufferObject<BUFFER_TYPE, index>*) {
  GLint currently_bound_buffer;
  gl(GetIntegeri_v(GLenum(GetBindingTarget(BUFFER_TYPE)), index,
                   &currently_bound_buffer));
  return IndexedBufferObject<BUFFER_TYPE, index>{currently_bound_buffer};
}
#endif

// Renderbuffer
#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindRenderbuffer)
inline void Bind(const Renderbuffer& buffer) {
  gl(BindRenderbuffer(GL_RENDERBUFFER, buffer.expose()));
}

inline void Unbind(const Renderbuffer&) {
  gl(BindRenderbuffer(GL_RENDERBUFFER, 0));
}

inline void Unbind(RenderbufferType) {
  gl(BindRenderbuffer(GL_RENDERBUFFER, 0));
}

inline bool IsBound(const Renderbuffer& buffer) {
  GLint currently_bound_buffer;
  gl(GetIntegerv(GLenum(GetBindingTarget(RenderbufferType::kRenderbuffer)),
                 &currently_bound_buffer));
  return buffer.expose() == GLuint(currently_bound_buffer);
}

inline Renderbuffer GetCurrentlyBoundObject(const Renderbuffer*) {
  GLint currently_bound_buffer;
  gl(GetIntegerv(GLenum(GetBindingTarget(RenderbufferType::kRenderbuffer)),
                 &currently_bound_buffer));
  return Renderbuffer{GLuint(currently_bound_buffer)};
}
#endif  // glBindRenderbuffer

// Framebuffer
#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindFramebuffer)
template<FramebufferType FBO_TYPE>
void Bind(const FramebufferObject<FBO_TYPE>& fbo) {
  gl(BindFramebuffer(GLenum(FBO_TYPE), fbo.expose()));
}

template<FramebufferType FBO_TYPE>
void Unbind(const FramebufferObject<FBO_TYPE>& fbo) {
  gl(BindFramebuffer(GLenum(FBO_TYPE), 0));
}

inline void Unbind(FramebufferType FBO_TYPE) {
  gl(BindFramebuffer(GLenum(FBO_TYPE), 0));
}

template<FramebufferType FBO_TYPE>
bool IsBound(const FramebufferObject<FBO_TYPE>& fbo) {
  GLint currently_bound_buffer;
  gl(GetIntegerv(GLenum(GetBindingTarget(FBO_TYPE)), &currently_bound_buffer));
  return fbo.expose() == GLuint(currently_bound_buffer);
}

template<FramebufferType FBO_TYPE>
FramebufferObject<FBO_TYPE> GetCurrentlyBoundObject(const FramebufferObject<FBO_TYPE>*) {
  GLint currently_bound_buffer;
  gl(GetIntegerv(GLenum(GetBindingTarget(FBO_TYPE)), &currently_bound_buffer));
  return FramebufferObject<FBO_TYPE>{GLuint(currently_bound_buffer)};
}
#endif


// TransformFeedback
#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindTransformFeedback)
inline void Bind(const TransformFeedback& tfb)  {
  gl(BindTransformFeedback(GL_TRANSFORM_FEEDBACK, tfb.expose()));
}

inline void Unbind(const TransformFeedback& tfb) {
  gl(BindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0));
}

inline void Unbind(TransformFeedbackType) {
  gl(BindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0));
}

inline bool IsBound(const TransformFeedback& tfb)  {
  GLint currently_bound_tfb;
  gl(GetIntegerv(GLenum(GetBindingTarget(TransformFeedbackType::kTransformFeedback)),
                 &currently_bound_tfb));
  return tfb.expose() == GLuint(currently_bound_tfb);
}

inline TransformFeedback GetCurrentlyBoundObject(const TransformFeedback*) {
  GLint currently_bound_tfb;
  gl(GetIntegerv(GLenum(GetBindingTarget(TransformFeedbackType::kTransformFeedback)),
                 &currently_bound_tfb));
  return TransformFeedback{GLuint(currently_bound_tfb)};
}
#endif


// VertexArray
#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindVertexArray)
inline void Bind(const VertexArray& vao) {
  gl(BindVertexArray(vao.expose()));
}

inline void Unbind(const VertexArray& vao) {
  gl(BindVertexArray(0));
}

inline void Unbind(VertexArrayType) {
  gl(BindVertexArray(0));
}

inline bool IsBound(const VertexArray& vao) {
  GLint currently_bound_vao;
  gl(GetIntegerv(GLenum(GetBindingTarget(VertexArrayType::kVertexArray)),
                 &currently_bound_vao));
  return vao.expose() == GLuint(currently_bound_vao);
}

inline VertexArray GetCurrentlyBoundObject(const VertexArray*) {
  GLint currently_bound_vao;
  gl(GetIntegerv(GLenum(GetBindingTarget(VertexArrayType::kVertexArray)),
                 &currently_bound_vao));
  return VertexArray{ GLuint(currently_bound_vao)};
}
#endif

// Texture
inline void ActiveTexture(GLuint tex_unit) {
  gl(ActiveTexture(GL_TEXTURE0 + tex_unit));
}

template <TextureType TEXTURE_TYPE>
void Bind(const TextureBase<TEXTURE_TYPE>& tex) {
  gl(BindTexture(GLenum(TEXTURE_TYPE), tex.expose()));
}

template <TextureType TEXTURE_TYPE>
void BindToTexUnit(const TextureBase<TEXTURE_TYPE>& tex, GLuint tex_unit) {
  gl(ActiveTexture(GL_TEXTURE0 + tex_unit));
  gl(BindTexture(GLenum(TEXTURE_TYPE), tex.expose()));
}

template <TextureType TEXTURE_TYPE>
void Unbind(const TextureBase<TEXTURE_TYPE>& tex) {
  gl(BindTexture(GLenum(TEXTURE_TYPE), 0));
}

inline void Unbind(TextureType TEXTURE_TYPE) {
  gl(BindTexture(GLenum(TEXTURE_TYPE), 0));
}

template <TextureType TEXTURE_TYPE>
void UnbindFromTexUnit(const TextureBase<TEXTURE_TYPE>& tex, GLuint tex_unit) {
  gl(ActiveTexture(GL_TEXTURE0 + tex_unit));
  gl(BindTexture(GLenum(TEXTURE_TYPE), 0));
}

inline void UnbindFromTexUnit(TextureType TEXTURE_TYPE, GLuint tex_unit) {
  gl(ActiveTexture(GL_TEXTURE0 + tex_unit));
  gl(BindTexture(GLenum(TEXTURE_TYPE), 0));
}

template <TextureType TEXTURE_TYPE>
bool IsBound(const TextureBase<TEXTURE_TYPE>& tex) {
  GLint currently_bound_texture;
  gl(GetIntegerv(GLenum(GetBindingTarget(TEXTURE_TYPE)), &currently_bound_texture));
  return tex.expose() == GLuint(currently_bound_texture);
}

template <TextureType TEXTURE_TYPE>
TextureBase<TEXTURE_TYPE> GetCurrentlyBoundObject(const TextureBase<TEXTURE_TYPE>*) {
  GLint currently_bound_texture;
  gl(GetIntegerv(GLenum(GetBindingTarget(TEXTURE_TYPE)), &currently_bound_texture));
  return TextureBase<TEXTURE_TYPE>{GLuint(currently_bound_texture)};
}

// Program
#if OGLWRAP_DEFINE_EVERYTHING || defined(glUseProgram)
inline void Bind(const Program& prog) {
#if OGLWRAP_DEBUG
  if (prog.expose() != 0 && prog.state() != Program::kLinkSuccessful) {
    OGLWRAP_PRINT_ERROR(
      "Program binding failure",
      "Tried to bind a program that wasn't linked successfully.")
    const_cast<Program&>(prog).link();
  }
#endif
  gl(UseProgram(prog.expose()));
}

inline void Use(const Program& prog) {
  Bind(prog);
}

inline void Unbind(const Program&) {
  gl(UseProgram(0));
}

inline void Unuse(const Program&) {
  gl(UseProgram(0));
}

inline void UnbindProgram() {
  gl(UseProgram(0));
}

inline void UnuseProgram() {
  gl(UseProgram(0));
}

inline bool IsBound(const Program& prog) {
  GLint current_program;
  gl(GetIntegerv(GL_CURRENT_PROGRAM, &current_program));

#if OGLWRAP_DEBUG
  DebugOutput::LastUsedBindTarget() = "GL_CURRENT_PROGRAM";
#endif

  return prog.expose() == GLuint(current_program);
}

inline bool IsActive(const Program& prog) {
  return IsBound(prog);
}

inline Program GetCurrentlyBoundObject(const Program*) {
  GLint current_program;
  gl(GetIntegerv(GL_CURRENT_PROGRAM, &current_program));
  return Program{GLuint(current_program)};
}
#endif

template <typename T>
auto GetCurrentlyBoundObject() -> decltype(GetCurrentlyBoundObject(static_cast<T*> (nullptr))) {
  return GetCurrentlyBoundObject(static_cast<T*> (nullptr));
}

/// Binds a value. When the variable goes
/// out of the scope, unbinds the value;
template <typename T>
class TemporaryBind {
public:
  TemporaryBind(T const& object_to_bind)
      : previously_bound_object_{GetCurrentlyBoundObject<T>()} {
    Bind(object_to_bind);
  }

  ~TemporaryBind() {
    Bind(previously_bound_object_);
  }

  TemporaryBind(TemporaryBind&&) = default;
  TemporaryBind& operator=(TemporaryBind&&) = default;

private:
  decltype(GetCurrentlyBoundObject<T>()) previously_bound_object_;

  TemporaryBind(const TemporaryBind&) = delete;
  TemporaryBind& operator=(const TemporaryBind&) = delete;
};

template <typename T>
inline TemporaryBind<T> MakeTemporaryBind (T const& val) {
 return TemporaryBind<T>(val);
}

}  // namespace oglwrap

#include "../undefine_internal_macros.h"
#include "../debug/bind_checking.h"
#include "../buffer-inl.h"
#include "../renderbuffer-inl.h"
#include "../transform_feedback-inl.h"
#include "../textures/texture_base-inl.h"
#include "../textures/texture_1D-inl.h"
#include "../textures/texture_2D-inl.h"
#include "../textures/texture_cube-inl.h"
#include "../textures/texture_3D-inl.h"
#include "../framebuffer-inl.h"

#endif
