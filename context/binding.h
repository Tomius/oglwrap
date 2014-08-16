// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_BINDING_H_
#define OGLWRAP_CONTEXT_BINDING_H_

#include "../program.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

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

#endif
