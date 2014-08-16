// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_DRAWING_H_
#define OGLWRAP_CONTEXT_DRAWING_H_

#include "../config.h"
#include "../enums/index_type.h"
#include "../enums/primitive_type.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

using PrimType = PrimitiveType;

inline void DrawArrays(PrimType type,
                       GLint first,
                       GLsizei count) {
  gl(DrawArrays(GLenum(type), first, count));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawArraysInstanced)
inline void DrawArraysInstanced(PrimType type,
                                GLint first,
                                GLsizei count,
                                GLsizei inst_count) {
  gl(DrawArraysInstanced(
    GLenum(type), first, count, inst_count
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawArraysInstancedBaseInstance)
inline void DrawArraysInstancedBaseInstance(PrimType type,
                                            GLint first,
                                            GLsizei count,
                                            GLsizei inst_count,
                                            GLsizei base_instance) {
  gl(DrawArraysInstancedBaseInstance(
    GLenum(type), first, count, inst_count, base_instance
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawArraysIndirect)
inline void DrawArraysIndirect(PrimType type,
                               const void *indirect = nullptr) {
  gl(DrawArraysIndirect(GLenum(type), indirect));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMultiDrawArrays)
inline void MultiDrawArrays(PrimType type,
                            const GLint *first,
                            const GLsizei *count,
                            GLsizei prim_count) {
  gl(MultiDrawArrays(GLenum(type), first, count, prim_count));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMultiDrawArraysIndirect)
inline void MultiDrawArraysIndirect(PrimType type,
                                    const void *indirect,
                                    GLsizei draw_count,
                                    GLsizei stride) {
  gl(MultiDrawArraysIndirect(
    GLenum(type), indirect, draw_count, stride
  ));
}
#endif

inline void DrawElements(PrimType type,
                         GLsizei count,
                         IndexType index_type) {
  gl(DrawElements(GLenum(type), count, GLenum(index_type), nullptr));
}

template <typename GLtype>
inline void DrawElements(PrimType type,
                         GLsizei count,
                         const GLtype* indices) {
  static_assert((sizeof(GLtype), false),
    "index type must be one of GLubyte, GLushort, or GLuint"
  );
}


#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawElementsInstanced)
inline void DrawElementsInstanced(PrimType type,
                                  GLsizei count,
                                  IndexType index_type,
                                  GLsizei inst_count) {
  gl(DrawElementsInstanced(
    GLenum(type), count, GLenum(index_type), nullptr, inst_count
  ));
}

template <typename GLtype>
inline void DrawElementsInstanced(PrimType type,
                                  GLsizei count,
                                  const GLtype* indices,
                                  GLsizei inst_count) {
  static_assert((sizeof(GLtype), false),
    "index type must be one of GLubyte, GLushort, or GLuint"
  );
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawElementsInstancedBaseInstance)
inline void DrawElementsInstancedBaseInstance(PrimType type,
                                              GLsizei count,
                                              IndexType index_type,
                                              GLsizei inst_count,
                                              GLuint base_instance) {
  gl(DrawElementsInstancedBaseInstance(
    GLenum(type), count, GLenum(index_type), nullptr, inst_count, base_instance
  ));
}

template <typename GLtype>
inline void DrawElementsInstancedBaseInstance(PrimType type,
                                              GLsizei count,
                                              const GLtype* indices,
                                              GLsizei inst_count,
                                              GLuint base_instance) {
  static_assert((sizeof(GLtype), false),
    "index type must be one of GLubyte, GLushort, or GLuint"
  );
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMultiDrawElements)
template <typename GLtype>
inline void MultiDrawElements(PrimType type,
                              const GLsizei* count,
                              const GLtype* const* indices,
                              GLsizei draw_count) {
  static_assert((sizeof(GLtype), false),
    "index type must be one of GLubyte, GLushort, or GLuint"
  );
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawRangeElements)
inline void DrawRangeElements(PrimType type,
                              GLuint start,
                              GLuint end,
                              GLsizei count,
                              IndexType index_type) {
  gl(DrawRangeElements(
    GLenum(type), start, end, count, GLenum(index_type), nullptr
  ));
}

template<typename GLtype>
inline void DrawRangeElements(PrimType type,
                              GLuint start,
                              GLuint end,
                              GLsizei count,
                              const GLtype* indices) {
  static_assert((sizeof(GLtype), false),
    "index type must be one of GLubyte, GLushort, or GLuint"
  );
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawElementsIndirect)
inline void DrawElementsIndirect(PrimType type,
                                 IndexType index_type,
                                 const void* indirect = nullptr) {
  gl(DrawElementsIndirect(
    GLenum(type), GLenum(index_type), indirect
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMultiDrawElementsIndirect)
inline void MultiDrawElementsIndirect(PrimType type,
                                      IndexType index_type,
                                      GLsizei draw_count,
                                      GLsizei stride = 0,
                                      const void* indirect = nullptr) {
  gl(MultiDrawElementsIndirect(
    GLenum(type), GLenum(index_type), indirect, draw_count, stride
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawElementsBaseVertex)
inline void DrawElementsBaseVertex(PrimType type,
                                   GLsizei count,
                                   IndexType index_type,
                                   GLint base_vertex) {
  gl(DrawElementsBaseVertex(
    GLenum(type), count, GLenum(index_type), nullptr, base_vertex
  ));
}

template<typename GLtype>
inline void DrawElementsBaseVertex(PrimType type,
                                   GLsizei count,
                                   const GLtype* indices,
                                   GLint base_vertex) {
  static_assert((sizeof(GLtype), false),
    "index type must be one of GLubyte, GLushort, or GLuint"
  );
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawRangeElementsBaseVertex)
inline void DrawRangeElementsBaseVertex(PrimType type,
                                        GLuint start,
                                        GLuint end,
                                        GLsizei count,
                                        IndexType index_type,
                                        GLint base_vertex) {
  gl(DrawRangeElementsBaseVertex(
    GLenum(type), start, end, count, GLenum(index_type), nullptr, base_vertex
  ));
}

template<typename GLtype>
inline void DrawRangeElementsBaseVertex(PrimType type,
                                        GLuint start,
                                        GLuint end,
                                        GLsizei count,
                                        const GLtype* indices,
                                        GLint base_vertex) {
  static_assert((sizeof(GLtype), false),
    "index type must be one of GLubyte, GLushort, or GLuint"
  );
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawElementsInstancedBaseVertex)
inline void DrawElementsInstancedBaseVertex(PrimType type,
                                            GLsizei count,
                                            IndexType index_type,
                                            GLsizei inst_count,
                                            GLint base_vertex) {
  gl(DrawElementsInstancedBaseVertex(
    GLenum(type), count, GLenum(index_type), nullptr, inst_count, base_vertex
  ));
}

template<typename GLtype>
inline void DrawElementsInstancedBaseVertex(PrimType type,
                                            GLsizei count,
                                            const GLtype* indices,
                                            GLsizei inst_count,
                                            GLint base_vertex) {
  static_assert((sizeof(GLtype), false),
    "index type must be one of GLubyte, GLushort, or GLuint"
  );
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMultiDrawElementsBaseVertex)
inline void MultiDrawElementsBaseVertex(PrimType type,
                                        const GLsizei *count,
                                        IndexType index_type,
                                        GLuint draw_count,
                                        const GLint *base_vertex) {
  gl(MultiDrawElementsBaseVertex(
    GLenum(type), (GLsizei*)count, GLenum(index_type),
    nullptr, draw_count, (GLint*)base_vertex
  ));
}

template<typename GLtype>
inline void MultiDrawElementsBaseVertex(PrimType type,
                                        const GLsizei *count,
                                        const GLtype* const* indices,
                                        GLuint draw_count,
                                        const GLint *base_vertex) {
  static_assert((sizeof(GLtype), false),
    "index type must be one of GLubyte, GLushort, or GLuint"
  );
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING \
|| defined(glDrawElementsInstancedBaseVertexBaseInstance)
inline void DrawElementsInstancedBaseVertexBaseInstance(PrimType type,
                                                        GLsizei count,
                                                        IndexType index_type,
                                                        GLsizei inst_count,
                                                        GLint base_vertex,
                                                        GLuint base_instance) {
  gl(DrawElementsInstancedBaseVertexBaseInstance(
    GLenum(type), count, GLenum(index_type), nullptr,
    inst_count, base_vertex, base_instance
  ));
}

template<typename GLtype>
inline void DrawElementsInstancedBaseVertexBaseInstance(PrimType type,
                                                       GLsizei count,
                                                       const GLtype* indices,
                                                       GLsizei inst_count,
                                                       GLint base_vertex,
                                                       GLuint base_instance) {
  static_assert((sizeof(GLtype), false),
    "index type must be one of GLubyte, GLushort, or GLuint"
  );
}
#endif


#if OGLWRAP_DEFINE_EVERYTHING || defined(glPrimitiveRestartIndex)
inline void PrimitiveRestartIndex(GLuint index) {
  gl(PrimitiveRestartIndex(index));
}
#endif

template<>
inline void DrawElements<GLubyte>(PrimType type, GLsizei count,
                                  const GLubyte* indices) {
  gl(DrawElements(GLenum(type), count, GL_UNSIGNED_BYTE, indices));
}

template<>
inline void DrawElements<GLushort>(PrimType type, GLsizei count,
                                   const GLushort* indices) {
  gl(DrawElements(GLenum(type), count, GL_UNSIGNED_SHORT, indices));
}

template<>
inline void DrawElements<GLuint>(PrimType type, GLsizei count,
                                 const GLuint* indices) {
  gl(DrawElements(GLenum(type), count, GL_UNSIGNED_INT, indices));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawElementsInstanced)
template<>
inline void DrawElementsInstanced<GLubyte>(PrimType type, GLsizei count,
                                           const GLubyte* indices,
                                           GLsizei inst_count) {
  gl(DrawElementsInstanced(
    GLenum(type), count, GL_UNSIGNED_BYTE, indices, inst_count
  ));
}

template<>
inline void DrawElementsInstanced<GLushort>(PrimType type, GLsizei count,
                                            const GLushort* indices,
                                            GLsizei inst_count) {
  gl(DrawElementsInstanced(
    GLenum(type), count, GL_UNSIGNED_SHORT, indices, inst_count
  ));
}

template<>
inline void DrawElementsInstanced<GLuint>(PrimType type, GLsizei count,
                                          const GLuint* indices,
                                          GLsizei inst_count) {
  gl(DrawElementsInstanced(
    GLenum(type), count, GL_UNSIGNED_INT, indices, inst_count
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawElementsInstancedBaseInstance)
template<>
inline void DrawElementsInstancedBaseInstance<GLubyte>(
    PrimType type,
    GLsizei count,
    const GLubyte* indices,
    GLsizei inst_count,
    GLuint base_instance) {
  gl(DrawElementsInstancedBaseInstance(
    GLenum(type), count, GL_UNSIGNED_BYTE, indices, inst_count, base_instance
  ));
}

template<>
inline void DrawElementsInstancedBaseInstance<GLushort>(
    PrimType type,
    GLsizei count,
    const GLushort* indices,
    GLsizei inst_count,
    GLuint base_instance) {
  gl(DrawElementsInstancedBaseInstance(
    GLenum(type), count, GL_UNSIGNED_SHORT, indices, inst_count, base_instance
  ));
}

template<>
inline void DrawElementsInstancedBaseInstance<GLuint>(
    PrimType type,
    GLsizei count,
    const GLuint* indices,
    GLsizei inst_count,
    GLuint base_instance) {
  gl(DrawElementsInstancedBaseInstance(
    GLenum(type), count, GL_UNSIGNED_INT, indices, inst_count, base_instance
  ));
}
#endif

// glMultiDrawElements used to have a const GLvoid** parameter, that became
// const GLvoid* const* in later version. In order to avoid GLEW version
// dependency this wrapper class enables casting a pointer to either of
// these two types.
class OGLWRAP_POINTER_HACKER {
  void* ptr_;
public:
  template <typename T>
  OGLWRAP_POINTER_HACKER(T ptr) : ptr_((void*)ptr) {}

  template <typename U>
  operator U() { return U(ptr_); }
};

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMultiDrawElements)
template<>
inline void MultiDrawElements<GLubyte>(PrimType type, const GLsizei* count,
                                       const GLubyte* const* indices,
                                       GLsizei draw_count) {
  gl(MultiDrawElements(
    GLenum(type), count, GL_UNSIGNED_BYTE,
    OGLWRAP_POINTER_HACKER(indices), draw_count
  ));
}

template<>
inline void MultiDrawElements<GLushort>(PrimType type, const GLsizei* count,
                                        const GLushort* const* indices,
                                        GLsizei draw_count) {
  gl(MultiDrawElements(
    GLenum(type), count, GL_UNSIGNED_SHORT,
    OGLWRAP_POINTER_HACKER(indices), draw_count
  ));
}

template<>
inline void MultiDrawElements<GLuint>(PrimType type, const GLsizei* count,
                                      const GLuint* const* indices,
                                      GLsizei draw_count) {
  gl(MultiDrawElements(
    GLenum(type), count, GL_UNSIGNED_INT,
    OGLWRAP_POINTER_HACKER(indices), draw_count
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawRangeElements)
template<>
inline void DrawRangeElements<GLubyte>(PrimType type, GLuint start,
                                       GLuint end, GLsizei count,
                                       const GLubyte* indices) {
  gl(DrawRangeElements(
    GLenum(type), start, end, count, GL_UNSIGNED_BYTE, indices
  ));
}
template<>
inline void DrawRangeElements<GLushort>(PrimType type, GLuint start,
                                        GLuint end, GLsizei count,
                                        const GLushort* indices) {
  gl(DrawRangeElements(
    GLenum(type), start, end, count, GL_UNSIGNED_SHORT, indices
  ));
}
template<>
inline void DrawRangeElements<GLuint>(PrimType type, GLuint start,
                                      GLuint end, GLsizei count,
                                      const GLuint* indices) {
  gl(DrawRangeElements(
    GLenum(type), start, end, count, GL_UNSIGNED_INT, indices
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawElementsBaseVertex)
template<>
inline void DrawElementsBaseVertex<GLubyte>(PrimType type, GLsizei count,
                                            const GLubyte* indices,
                                            GLint base_vertex) {
  gl(DrawElementsBaseVertex(
    GLenum(type), count, GL_UNSIGNED_BYTE,
    (void*)indices, base_vertex
  ));
}
template<>
inline void DrawElementsBaseVertex<GLushort>(PrimType type, GLsizei count,
                                             const GLushort* indices,
                                             GLint base_vertex) {
  gl(DrawElementsBaseVertex(
    GLenum(type), count, GL_UNSIGNED_SHORT,
    (void*)indices, base_vertex
  ));
}
template<>
inline void DrawElementsBaseVertex<GLuint>(PrimType type, GLsizei count,
                                           const GLuint* indices,
                                           GLint base_vertex) {
  gl(DrawElementsBaseVertex(
    GLenum(type), count, GL_UNSIGNED_INT, (void*)indices, base_vertex
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawRangeElementsBaseVertex)
template<>
inline void DrawRangeElementsBaseVertex<GLubyte>(PrimType type, GLuint start,
                                                 GLuint end, GLsizei count,
                                                 const GLubyte* indices,
                                                 GLint base_vertex) {
  gl(DrawRangeElementsBaseVertex(
    GLenum(type), start, end, count, GL_UNSIGNED_BYTE,
    (void*)indices, base_vertex
  ));
}
template<>
inline void DrawRangeElementsBaseVertex<GLushort>(PrimType type, GLuint start,
                                                  GLuint end, GLsizei count,
                                                  const GLushort* indices,
                                                  GLint base_vertex) {
  gl(DrawRangeElementsBaseVertex(
    GLenum(type), start, end, count, GL_UNSIGNED_SHORT,
    (void*)indices, base_vertex
  ));
}
template<>
inline void DrawRangeElementsBaseVertex<GLuint>(PrimType type, GLuint start,
                                                GLuint end, GLsizei count,
                                                const GLuint* indices,
                                                GLint base_vertex) {
  gl(DrawRangeElementsBaseVertex(
    GLenum(type), start, end, count, GL_UNSIGNED_INT,
    (void*)indices, base_vertex
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawElementsInstancedBaseVertex)
template<>
inline void DrawElementsInstancedBaseVertex<GLubyte>(PrimType type,
                                                     GLsizei count,
                                                     const GLubyte* indices,
                                                     GLsizei inst_count,
                                                     GLint base_vertex) {
  gl(DrawElementsInstancedBaseVertex(
    GLenum(type), count, GL_UNSIGNED_BYTE,
    (void*)indices, inst_count, base_vertex
  ));
}
template<>
inline void DrawElementsInstancedBaseVertex<GLushort>(PrimType type,
                                                     GLsizei count,
                                                     const GLushort* indices,
                                                     GLsizei inst_count,
                                                     GLint base_vertex) {
  gl(DrawElementsInstancedBaseVertex(
    GLenum(type), count, GL_UNSIGNED_SHORT,
    (void*)indices, inst_count, base_vertex
  ));
}
template<>
inline void DrawElementsInstancedBaseVertex<GLuint>(PrimType type,
                                                    GLsizei count,
                                                    const GLuint* indices,
                                                    GLsizei inst_count,
                                                    GLint base_vertex) {
  gl(DrawElementsInstancedBaseVertex(
    GLenum(type), count, GL_UNSIGNED_INT,
    (void*)indices, inst_count, base_vertex
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMultiDrawElementsBaseVertex)
template<>
inline void MultiDrawElementsBaseVertex<GLubyte>(PrimType type,
                                                 const GLsizei *count,
                                                 const GLubyte* const* indices,
                                                 GLuint draw_count,
                                                 const GLint *base_vertex) {
  gl(MultiDrawElementsBaseVertex(
    GLenum(type), (GLsizei*)count, GL_UNSIGNED_BYTE,
    OGLWRAP_POINTER_HACKER(indices), draw_count, (GLint*)base_vertex
  ));
}
template<>
inline void MultiDrawElementsBaseVertex<GLushort>(PrimType type,
                                                  const GLsizei *count,
                                                  const GLushort*const* indices,
                                                  GLuint draw_count,
                                                  const GLint *base_vertex) {
  gl(MultiDrawElementsBaseVertex(
    GLenum(type), (GLsizei*)count, GL_UNSIGNED_SHORT,
    OGLWRAP_POINTER_HACKER(indices), draw_count, (GLint*)base_vertex
  ));
}
template<>
inline void MultiDrawElementsBaseVertex<GLuint>(PrimType type,
                                                const GLsizei *count,
                                                const GLuint* const* indices,
                                                GLuint draw_count,
                                                const GLint *base_vertex) {
  gl(MultiDrawElementsBaseVertex(
    GLenum(type), (GLsizei*)count, GL_UNSIGNED_INT,
    OGLWRAP_POINTER_HACKER(indices), draw_count, (GLint*)base_vertex
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || \
    defined(glDrawElementsInstancedBaseVertexBaseInstance)
template<>
inline void DrawElementsInstancedBaseVertexBaseInstance<GLubyte>(
    PrimType type,
    GLsizei count,
    const GLubyte* indices,
    GLsizei inst_count,
    GLint base_vertex,
    GLuint base_instance) {
  gl(DrawElementsInstancedBaseVertexBaseInstance(
    GLenum(type), count, GL_UNSIGNED_BYTE,
    (void*)indices, inst_count, base_vertex, base_instance
  ));
}
template<>
inline void DrawElementsInstancedBaseVertexBaseInstance<GLushort>(
    PrimType type,
    GLsizei count,
    const GLushort* indices,
    GLsizei inst_count,
    GLint base_vertex,
    GLuint base_instance) {
  gl(DrawElementsInstancedBaseVertexBaseInstance(
    GLenum(type), count, GL_UNSIGNED_SHORT,
    (void*)indices, inst_count, base_vertex, base_instance
  ));
}
template<>
inline void DrawElementsInstancedBaseVertexBaseInstance<GLuint>(
    PrimType type,
    GLsizei count,
    const GLuint* indices,
    GLsizei inst_count,
    GLint base_vertex,
    GLuint base_instance) {
  gl(DrawElementsInstancedBaseVertexBaseInstance(
    GLenum(type), count, GL_UNSIGNED_INT,
    (void*)indices, inst_count, base_vertex, base_instance
  ));
}
#endif

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
