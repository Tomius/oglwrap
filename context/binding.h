// Copyright (c) 2014, Tamas Csala

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

// Renderbuffer
#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindRenderbuffer)
inline void Bind(const Renderbuffer& buffer) {
  gl(BindRenderbuffer(GL_RENDERBUFFER, buffer.expose()));
}

inline void Unbind(const Renderbuffer&) {
  gl(BindRenderbuffer(GL_RENDERBUFFER, 0));
}

inline void Unbind(RenderbufferTarget) {
  gl(BindRenderbuffer(GL_RENDERBUFFER, 0));
}

inline bool IsBound(const Renderbuffer& buffer) {
  GLint currently_bound_buffer;
  gl(GetIntegerv(GLenum(GetBindingTarget(RenderbufferTarget::kRenderbuffer)),
                 &currently_bound_buffer));
  return buffer.expose() == GLuint(currently_bound_buffer);
}
#endif  // glBindRenderbuffer

// Framebuffer
#if OGLWRAP_DEFINE_EVERYTHING || defined(glBindFramebuffer)
template<FramebufferTarget FBO_TYPE>
void Bind(const FramebufferObject<FBO_TYPE>& fbo) {
  gl(BindFramebuffer(GLenum(FBO_TYPE), fbo.expose()));
}

template<FramebufferTarget FBO_TYPE>
bool IsBound(const FramebufferObject<FBO_TYPE>& fbo) {
  GLint currently_bound_buffer;
  gl(GetIntegerv(GLenum(GetBindingTarget(FBO_TYPE)), &currently_bound_buffer));
  return fbo.expose() == GLuint(currently_bound_buffer);
}

template<FramebufferTarget FBO_TYPE>
void Unbind(const FramebufferObject<FBO_TYPE>& fbo) {
  gl(BindFramebuffer(GLenum(FBO_TYPE), 0));
}

inline void Unbind(FramebufferTarget FBO_TYPE) {
  gl(BindFramebuffer(GLenum(FBO_TYPE), 0));
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

inline void Unbind(TransformFeedbackTarget) {
  gl(BindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0));
}

inline bool IsBound(const TransformFeedback& tfb)  {
  GLint currently_bound_tfb;
  gl(GetIntegerv(GLenum(GetBindingTarget(TransformFeedbackTarget::kTransformFeedback)),
                 &currently_bound_tfb));
  return tfb.expose() == GLuint(currently_bound_tfb);
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

inline void Unbind(VertexArrayTarget) {
  gl(BindVertexArray(0));
}

inline bool IsBound(const VertexArray& vao) {
  GLint currently_bound_vao;
  gl(GetIntegerv(GLenum(GetBindingTarget(VertexArrayTarget::kVertexArray)),
                 &currently_bound_vao));
  return vao.expose() == GLuint(currently_bound_vao);
}
#endif

// Texture
template <TextureTarget texture_t>
void Bind(const TextureBase<texture_t>& tex) {
  gl(BindTexture(GLenum(texture_t), tex.expose()));
}

template <TextureTarget texture_t>
void BindToTexUnit(const TextureBase<texture_t>& tex, GLuint tex_unit) {
  gl(ActiveTexture(GL_TEXTURE0 + tex_unit));
  gl(BindTexture(GLenum(texture_t), tex.expose()));
}

template <TextureTarget texture_t>
void Unbind(const TextureBase<texture_t>& tex) {
  gl(BindTexture(GLenum(texture_t), 0));
}

inline void Unbind(TextureTarget texture_t) {
  gl(BindTexture(GLenum(texture_t), 0));
}

template <TextureTarget texture_t>
void UnbindFromTexUnit(const TextureBase<texture_t>& tex, GLuint tex_unit) {
  gl(ActiveTexture(GL_TEXTURE0 + tex_unit));
  gl(BindTexture(GLenum(texture_t), 0));
}

inline void UnbindFromTexUnit(TextureTarget texture_t, GLuint tex_unit) {
  gl(ActiveTexture(GL_TEXTURE0 + tex_unit));
  gl(BindTexture(GLenum(texture_t), 0));
}

template <TextureTarget texture_t>
bool IsBound(const TextureBase<texture_t>& tex) {
  GLint currently_bound_texture;
  gl(GetIntegerv(GLenum(GetBindingTarget(texture_t)), &currently_bound_texture));
  return tex.expose() == GLuint(currently_bound_texture);
}

inline void ActiveTexture(GLuint tex_unit) {
  gl(ActiveTexture(GL_TEXTURE0 + tex_unit));
}

// Program
#if OGLWRAP_DEFINE_EVERYTHING || defined(glUseProgram)
inline void Bind(const Program& prog) {
#if OGLWRAP_DEBUG
  if (!prog.linked()) {
    OGLWRAP_PRINT_ERROR(
      "Program binding failure", "Tried to bind a program that wasn't linked.")
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
#endif

}  // namespace oglwrap

#include "../undefine_internal_macros.h"
#include "../debug/bind_checking.h"
#include "../renderbuffer-inl.h"
#include "../transform_feedback-inl.h"
#include "../textures/texture_base-inl.h"
#include "../textures/texture1D-inl.h"
#include "../textures/texture2D-inl.h"
#include "../textures/texture_cube-inl.h"
#include "../textures/texture3D-inl.h"
#include "../framebuffer-inl.h"

#endif
