// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_DRAWING_H_
#define OGLWRAP_CONTEXT_DRAWING_H_

#include "../config.h"
#include "../enums/index_type.h"
#include "../enums/primitive_type.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

using PrimType = PrimitiveType;

/**
 * @brief Draws count of primitives from the bound array buffer.
 *
 * glDrawArrays specifies multiple geometric primitives with very few
 * subroutine calls. Instead of calling a GL procedure to pass each individual
 * vertex attribute, you can use glVertexAttribPointer to prespecify separate
 * arrays of vertices, normals, and colors and use them to construct a
 * sequence of primitives with a single call to glDrawArrays.
 *
 * When glDrawArrays is called, it uses count sequential elements from each
 * enabled array to construct a sequence of geometric primitives, beginning
 * with element first. mode specifies what kind of primitives are constructed
 * and how the array elements construct those primitives.
 *
 * To enable and disable a generic vertex attribute array, call
 * glEnableVertexAttribArray and glDisableVertexAttribArray.
 *
 * @param type    Specifies what kind of primitives to render.
 * @param first   Specifies the starting index in the enabled arrays.
 * @param count   Specifies the number of indices to be rendered.
 * @see glDrawArrays
 * @version OpenGL 1.1
 */
inline void DrawArrays(PrimType type,
                       GLint first,
                       GLsizei count) {
  gl(DrawArrays(GLenum(type), first, count));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawArraysInstanced)
/**
 * @brief Draw multiples instances of a range of elements.
 *
 * glDrawArraysInstanced behaves identically to glDrawArrays except that
 * inst_count instances of the range of elements are executed. Those attributes
 * that have divisor N where N is other than zero (as specified by
 * glVertexAttribDivisor) advance once every N instances. Thus, the element
 * transferred from instanced vertex attributes is given by: instance divisor
 *
 * The value of instance may be read by a vertex shader as gl_InstanceID.
 *
 * To enable and disable a generic vertex attribute array, call
 * glEnableVertexAttribArray and glDisableVertexAttribArray.
 *
 * If an array corresponding to a generic attribute required by a vertex
 * shader is not enabled, then the corresponding element is taken from the
 * current generic attribute state.
 *
 * @param type       Specifies what kind of primitives to render.
 * @param first      Specifies the starting index in the enabled arrays.
 * @param count      Specifies the number of indices to be rendered.
 * @param inst_count Specifies the number of instances of the specified range
 *                   of indices to be rendered.
 * @see glDrawArraysInstanced
 * @version OpenGL 3.1
 */
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
/**
 * @brief Draw multiples instances of a range of elements from a starting
 *        instance count.
 *
 * glDrawArraysInstancedBaseInstance behaves identically to glDrawArrays​
 * except that inst_count instances of the range of elements are executed and
 * the value of the internal counter instanceID​ advances for each iteration.
 * instanceID​ is an internal 32-bit integer counter that may be read by a
 * vertex shader as gl_InstanceID​.
 *
 * glDrawArraysInstancedBaseInstance has the same effect as:
 *
 * if ( mode or count is invalid )
 *     generate appropriate error
 * else {
 *     for (int i = 0; i < inst_count ; i++) {
 *         instanceID = i;
 *         glDrawArrays(mode, first, count);
 *     }
 *     instanceID = 0;
 * }
 *
 * Specific vertex attributes may be classified as instanced through the use
 * of glVertexAttribDivisor​. Instanced vertex attributes supply per-instance
 * vertex data to the vertex shader. The index of the vertex fetched from the
 * enabled instanced vertex attribute arrays is calculated as:
 * ⌊gl_InstanceID/divisor⌋+baseInstance. Note that base_instance​ does not
 * affect the shader-visible value of gl_InstanceID​.
 *
 * @param type           Specifies what kind of primitives to render.
 * @param first          Specifies the starting index in the enabled arrays.
 * @param count          Specifies the number of indices to be rendered.
 * @param inst_count     Specifies the number of instances of the specified
 *                       range of indices to be rendered.
 * @param base_instace   Specifies the base instance for use in fetching
 *                       instanced vertex attributes.
 * @see glDrawArraysInstancedBaseInstance
 * @version OpenGL 4.2
 */
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
/**
 * @brief Renders primitives from array data, taking parameters from memory.
 *
 * glDrawArraysIndirect specifies multiple geometric primitives with very few
 * subroutine calls. glDrawArraysIndirect behaves similarly to
 * glDrawArraysInstancedBaseInstance​, except that the parameters to
 * glDrawArraysInstancedBaseInstance​ are stored in the buffer bound to
 * GL_DRAW_INDIRECT_BUFFER​, offset by indirect bytes.
 *
 * The parameters referenced by indirect are packed into a structure that
 * takes the form (in C):
 *
 * typedef  struct {
 *     uint  count;
 *     uint  instanceCount;
 *     uint  first;
 *     uint  baseInstance;
 * } DrawArraysIndirectCommand;
 *
 * const DrawArraysIndirectCommand *cmd =
 *   (const DrawArraysIndirectCommand *)indirect;
 * glDrawArraysInstancedBaseInstance(
 *   mode, cmd->first, cmd->count, cmd->instanceCount, cmd->baseInstance
 * );
 *
 * indirect is interpreted as an offset, in basic machine units, into the
 * buffer bound to GL_DRAW_INDIRECT_BUFFER​ at the time of the call. The
 * parameter data stored there is read from the buffer and executed.
 *
 * In contrast to glDrawArraysInstancedBaseInstance​, the first member of the
 * parameter structure is unsigned, and out-of-range indices do not generate
 * an error.
 *
 * Vertex attributes that are modified by glDrawArraysIndirect have an
 * unspecified value after glDrawArraysIndirect returns. Attributes that
 * aren't modified remain well defined.
 *
 * @param mode       Specifies what kind of primitives to render.
 * @param indirect   Specifies a byte offset (cast to a pointer type) into the
 *                   buffer bound to GL_DRAW_INDIRECT_BUFFER​, which designates
 *                   the starting point of the structure containing the draw
 *                   parameters.
 * @see glDrawArraysIndirect
 * @version OpenGL 4.0
 */
inline void DrawArraysIndirect(PrimType type,
                               const void *indirect = nullptr) {
  gl(DrawArraysIndirect(GLenum(type), indirect));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMultiDrawArrays)
/**
 * @brief Renders multiple sets of primitives from array data
 *
 * glMultiDrawArrays specifies multiple sets of geometric primitives with
 * very few subroutine calls. Instead of calling a GL procedure to pass each
 * individual vertex, normal, texture coordinate, edge flag, or color, you can
 * prespecify separate arrays of vertices, normals, and colors and use them to
 * construct a sequence of primitives with a single call to glMultiDrawArrays.
 *
 * glMultiDrawArrays behaves identically to glDrawArrays​ except that drawcount​
 * separate ranges of elements are specified instead.
 *
 * When glMultiDrawArrays is called, it uses count sequential elements from
 * each enabled array to construct a sequence of geometric primitives,
 * beginning with element first. mode specifies what kind of primitives are
 * constructed, and how the array elements construct those primitives.
 *
 * Vertex attributes that are modified by glMultiDrawArrays have an
 * unspecified value after glMultiDrawArrays returns. Attributes that aren't
 * modified remain well defined.
 *
 * @param type         Specifies what kind of primitives to render.
 * @param first        Points to an array of starting indices in the enabled
 *                     arrays.
 * @param count        Points to an array of the number of indices to be
 *                     rendered.
 * @param prim_count   Specifies the size of the first and count
 * @see glMultiDrawArrays
 * @version OpenGL 1.4
 */
inline void MultiDrawArrays(PrimType type,
                            const GLint *first,
                            const GLsizei *count,
                            GLsizei prim_count) {
  gl(MultiDrawArrays(GLenum(type), first, count, prim_count));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMultiDrawArraysIndirect)
/**
 * @brief Renders multiple sets of primitives from array data, taking
 *        parameters from memory
 *
 * glMultiDrawArraysIndirect specifies multiple geometric primitives with very
 * few subroutine calls. glMultiDrawArraysIndirect behaves similarly to a
 * multitude of calls to glDrawArraysInstancedBaseInstance, except that the
 * parameters to each call to glDrawArraysInstancedBaseInstance are stored in
 * an array in memory at the address given by indirect, separated by the
 * stride, in basic machine units, specified by stride. If stride is zero,
 * then the array is assumed to be tightly packed in memory.
 *
 * The parameters addressed by indirect are packed into an array of structures,
 * each element of which takes the form (in C):
 *
 * typedef  struct {
 *    uint  count;
 *    uint  instanceCount;
 *    uint  first;
 *    uint  baseInstance;
 * } DrawArraysIndirectCommand;
 *
 * A single call to glMultiDrawArraysIndirect is equivalent, assuming no errors
 * are generated to:
 *
 * GLsizei n;
 * for (n = 0; n < drawcount; n++) {
 *     const DrawArraysIndirectCommand *cmd;
 *     if (stride != 0) {
 *         cmd = (const DrawArraysIndirectCommand*)((uintptr)indirect +n*stride);
 *     } else  {
 *         cmd = (const DrawArraysIndirectCommand*)indirect + n;
 *     }
 *
 *     glDrawArraysInstancedBaseInstance(
 *       mode, cmd->first, cmd->count, cmd->instanceCount, cmd->baseInstance
 *     );
 * }
 *
 * If a buffer is bound to the GL_DRAW_INDIRECT_BUFFER binding at the time of
 * a call to glMultiDrawArraysIndirect, indirect is interpreted as an offset,
 * in basic machine units, into that buffer and the parameter data is read from
 * the buffer rather than from client memory.
 *
 * In contrast to glDrawArraysInstancedBaseInstance, the first member of the
 * parameter structure is unsigned, and out-of-range indices do not generate
 * an error.
 *
 * Vertex attributes that are modified by glMultiDrawArraysIndirect have an
 * unspecified value after glMultiDrawArraysIndirect returns. Attributes that
 * aren't modified remain well defined.
 *
 * Notes
 * The baseInstance member of the DrawArraysIndirectCommand structure is
 * defined only if the GL version is 4.2 or greater. For versions of the GL
 * less than 4.2, this parameter is present but is reserved and should be set
 * to zero. On earlier versions of the GL, behavior is undefined if it is
 * non-zero.
 *
 * glMultiDrawArraysIndirect is available only if the GL version is 4.3 or greater.
 *
 * @param type        Specifies what kind of primitives to render.
 * @param indirect    Specifies a byte offset (cast to a pointer type) into the
 *                    buffer bound to GL_DRAW_INDIRECT_BUFFER​, which designates
 *                    the starting point of the structure containing the draw
 *                    parameters.
 * @param draw_count  Specifies the the number of elements in the array of
 *                    draw parameter structures.
 * @param stride      Specifies the distance in basic machine units between
 *                    elements of the draw parameter array.
 * @see glMultiDrawArraysIndirect
 * @version OpenGL 4.3
 */
inline void MultiDrawArraysIndirect(PrimType type,
                                    const void *indirect,
                                    GLsizei draw_count,
                                    GLsizei stride) {
  gl(MultiDrawArraysIndirect(
    GLenum(type), indirect, draw_count, stride
  ));
}
#endif

/**
 * @brief Draws a sequence of primitives from the bound element array buffers,
 *        in the order specified by the bound index buffer.
 *
 * glDrawElements specifies multiple geometric primitives with very few
 * subroutine calls. Instead of calling a GL function to pass each individual
 * vertex, normal, texture coordinate, edge flag, or color, you can prespecify
 * separate arrays of vertices, normals, and so on, and use them to construct a
 * sequence of primitives with a single call to glDrawElements.
 *
 * When glDrawElements is called, it uses count sequential elements from an
 * enabled array, starting at indices to construct a sequence of geometric
 * primitives. mode specifies what kind of primitives are constructed and how
 * the array elements construct these primitives. If more than one array is
 * enabled, each is used.
 * Vertex attributes that are modified by glDrawElements have an unspecified
 * value after glDrawElements returns. Attributes that aren't modified maintain
 * their previous values.
 *
 * @param type         Specifies what kind of primitives to render.
 * @param count        Specifies the number of elements to be rendered.
 * @param index_type   Specifies the type of the values in the index buffer.
 * @see glDrawElements
 * @version OpenGL 1.1
 */
inline void DrawElements(PrimType type,
                         GLsizei count,
                         IndexType index_type) {
  gl(DrawElements(GLenum(type), count, GLenum(index_type), nullptr));
}

template <typename GLtype>
/**
 * @brief Draws a sequence of primitives from the bound element array buffers,
 *        in the order specified by the bound index buffer.
 *
 * glDrawElements specifies multiple geometric primitives with very few
 * subroutine calls. Instead of calling a GL function to pass each individual
 * vertex, normal, texture coordinate, edge flag, or color, you can prespecify
 * separate arrays of vertices, normals, and so on, and use them to construct a
 * sequence of primitives with a single call to glDrawElements.
 *
 * When glDrawElements is called, it uses count sequential elements from an
 * enabled array, starting at indices to construct a sequence of geometric
 * primitives. mode specifies what kind of primitives are constructed and how
 * the array elements construct these primitives. If more than one array is
 * enabled, each is used.
 * Vertex attributes that are modified by glDrawElements have an unspecified
 * value after glDrawElements returns. Attributes that aren't modified maintain
 * their previous values.
 *
 * @param type       Specifies what kind of primitives to render.
 * @param count      Specifies the number of elements to be rendered.
 * @param indices    Specifies the offset pointer in the index buffer.
 * @see glDrawElements
 * @version OpenGL 1.1
 */
inline void DrawElements(PrimType type,
                         GLsizei count,
                         const GLtype* indices) {
  static_assert((sizeof(GLtype), false),
    "index type must be one of GLubyte, GLushort, or GLuint"
  );
}


#if OGLWRAP_DEFINE_EVERYTHING || defined(glDrawElementsInstanced)
/**
 * @brief Draws multiple instances of a sequence of primitives from the bound
 *        element array buffers, in the order specified by the bound index buffer.
 *
 * glDrawElementsInstanced behaves identically to glDrawElements except that
 * inst_count instances of the set of elements are executed and the value of
 * the internal counter instanceID advances for each iteration. instanceID
 * is an internal 32-bit integer counter that may be read by a vertex shader
 * as gl_InstanceID.
 *
 * glDrawElementsInstanced has the same effect as:
 *
 * if (mode, count, or type is invalid )
 *     generate appropriate error
 * else {
 *     for (int i = 0; i < inst_count ; i++) {
 *         instanceID = i;
 *         glDrawElements(mode, count, type, indices);
 *     }
 *     instanceID = 0;
 * }
 *
 * @param type         Specifies what kind of primitives to render.
 * @param count        Specifies the number of elements to be rendered.
 * @param index_type   Specifies the type of the values in the index buffer.
 * @param inst_count   Specifies the number of instances of the specified range
 *                     of indices to be rendered.
 * @see glDrawElementsInstanced
 * @version OpenGL 3.1
 */
inline void DrawElementsInstanced(PrimType type,
                                  GLsizei count,
                                  IndexType index_type,
                                  GLsizei inst_count) {
  gl(DrawElementsInstanced(
    GLenum(type), count, GLenum(index_type), nullptr, inst_count
  ));
}

template <typename GLtype>
/**
 * @brief Draws multiple instances of a sequence of primitives from the bound
 *        element array buffers, in the order specified by the bound index buffer.
 *
 * glDrawElementsInstanced behaves identically to glDrawElements except that
 * inst_count instances of the set of elements are executed and the value of
 * the internal counter instanceID advances for each iteration. instanceID
 * is an internal 32-bit integer counter that may be read by a vertex shader
 * as gl_InstanceID.
 *
 * glDrawElementsInstanced has the same effect as:
 *
 * if (mode, count, or type is invalid )
 *     generate appropriate error
 * else {
 *     for (int i = 0; i < inst_count ; i++) {
 *         instanceID = i;
 *         glDrawElements(mode, count, type, indices);
 *     }
 *     instanceID = 0;
 * }
 *
 * @param type         Specifies what kind of primitives to render.
 * @param count        Specifies the number of elements to be rendered.
 * @param indices      Specifies the offset pointer in the index buffer.
 * @param inst_count   Specifies the number of instances of the specified range
 *                     of indices to be rendered.
 * @see glDrawElementsInstanced
 * @version OpenGL 3.1
 */
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
/**
 * @brief Draws multiple instances of a sequence of primitives from the bound
 *        element array buffers, in the order specified by the bound index buffer.
 *
 * glDrawElementsInstancedBaseInstance behaves identically to glDrawElements
 * except that inst_count instances of the set of elements are executed and the
 * value of the internal counter instanceID advances for each iteration.
 * instanceID is an internal 32-bit integer counter that may be read by a
 * vertex shader as gl_InstanceID.
 *
 * glDrawElementsInstancedBaseInstance has the same effect as:
 *
 * if (mode, count, or type is invalid )
 *     generate appropriate error
 * else {
 *     for (int i = 0; i < inst_count ; i++) {
 *         instanceID = i;
 *         glDrawElements(mode, count, type, indices);
 *     }
 *     instanceID = 0;
 * }
 *
 * Specific vertex attributes may be classified as instanced through the use
 * of glVertexAttribDivisor. Instanced vertex attributes supply per-instance
 * vertex data to the vertex shader. The index of the vertex fetched from the
 * enabled instanced vertex attribute arrays is calculated as
 * ⌊gl_InstanceID/divisor⌋+baseInstance. Note that base_instance does not affect
 * the shader-visible value of gl_InstanceID.
 *
 * @param type           Specifies what kind of primitives to render.
 * @param count          Specifies the number of elements to be rendered.
 * @param index_type     Specifies the type of the values in the index buffer.
 * @param inst_count     Specifies the number of instances of the specified
 *                       range of indices to be rendered.
 * @param base_instance  Specifies the base instance for use in fetching
 *                       instanced vertex attributes.
 * @see glDrawElementsInstancedBaseInstance
 * @version OpenGL 4.2
 */
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
/**
 * @brief Draws multiple instances of a sequence of primitives from the bound
 *        element array buffers, in the order specified by the bound index buffer.
 *
 * glDrawElementsInstancedBaseInstance behaves identically to glDrawElements
 * except that inst_count instances of the set of elements are executed and the
 * value of the internal counter instanceID advances for each iteration.
 * instanceID is an internal 32-bit integer counter that may be read by a
 * vertex shader as gl_InstanceID.
 *
 * glDrawElementsInstancedBaseInstance has the same effect as:
 *
 * if (mode, count, or type is invalid )
 *     generate appropriate error
 * else {
 *     for (int i = 0; i < inst_count ; i++) {
 *         instanceID = i;
 *         glDrawElements(mode, count, type, indices);
 *     }
 *     instanceID = 0;
 * }
 *
 * Specific vertex attributes may be classified as instanced through the use
 * of glVertexAttribDivisor. Instanced vertex attributes supply per-instance
 * vertex data to the vertex shader. The index of the vertex fetched from the
 * enabled instanced vertex attribute arrays is calculated as
 * ⌊gl_InstanceID/divisor⌋+baseInstance. Note that base_instance does not affect
 * the shader-visible value of gl_InstanceID.
 *
 * @param type          Specifies what kind of primitives to render.
 * @param count         Specifies the number of elements to be rendered.
 * @param indices       Specifies the offset pointer in the index buffer.
 * @param inst_count    Specifies the number of instances of the specified
 *                      range of indices to be rendered.
 * @param base_instace  Specifies the base instance for use in fetching
 *                      instanced vertex attributes.
 * @see glDrawElementsInstancedBaseInstance
 * @version OpenGL 4.2
 */
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
/**
 * @brief Draws multiple sets of sequences of primitives from the bound
 *        element array buffers, in the order specified by the bound index buffer.
 *
 * glMultiDrawElements specifies multiple sets of geometric primitives with
 * very few subroutine calls. Instead of calling a GL function to pass each
 * individual vertex, normal, texture coordinate, edge flag, or color, you can
 * prespecify separate arrays of vertices, normals, and so on, and use them to
 * construct a sequence of primitives with a single call to glMultiDrawElements.
 *
 * glMultiDrawElements is identical in operation to glDrawElements except that
 * drawcount separate lists of elements are specified.
 *
 * Vertex attributes that are modified by glMultiDrawElements have an
 * unspecified value after glMultiDrawElements returns. Attributes that aren't
 * modified maintain their previous values.
 *
 * @param type         Specifies what kind of primitives to render.
 * @param count        Points to an array of the elements counts.
 * @param indices      Specifies a pointer to the location where the offset
 *                     pointers to the index buffer are stored.
 * @param draw_count   Specifies the size of the count and indices arrays.
 * @see glMultiDrawElements
 * @version OpenGL 1.4
 */
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
/**
 * @brief glDrawRangeElements is a restricted form of glDrawElements, with the
 *        additional constraint that all values in the arrays count must lie
 *        between start and end, inclusive.
 *
 * Implementations denote recommended maximum amounts of vertex and index data,
 * which may be queried by calling glGet with argument GL_MAX_ELEMENTS_VERTICES
 * and GL_MAX_ELEMENTS_INDICES. If end−start+1 is greater than the value of
 * GL_MAX_ELEMENTS_VERTICES, or if count is greater than the value of
 * GL_MAX_ELEMENTS_INDICES, then the call may operate at reduced performance.
 * There is no requirement that all vertices in the range [start,end] be
 * referenced. However, the implementation may partially process unused
 * vertices, reducing performance from what could be achieved with an optimal
 * index set.
 *
 * When glDrawRangeElements is called, it uses count sequential elements from
 * an enabled array, starting at start to construct a sequence of geometric
 * primitives. mode specifies what kind of primitives are constructed, and
 * how the array elements construct these primitives. If more than one
 * array is enabled, each is used.
 *
 * Vertex attributes that are modified by glDrawRangeElements have an
 * unspecified value after glDrawRangeElements returns. Attributes that
 * aren't modified maintain their previous values.
 *
 * @param type        Specifies what kind of primitives to render.
 * @param start       Specifies the minimum array index contained in indices.
 * @param end         Specifies the maximum array index contained in indices.
 * @param count       Specifies the number of elements to be rendered.
 * @param index_type  Specifies the type of the values in indices
 * @see glDrawRangeElements
 * @version OpenGL 1.2
 */
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
/**
 * @brief glDrawRangeElements is a restricted form of glDrawElements, with the
 *        additional constraint that all values in the arrays count must lie
 *        between start and end, inclusive.
 *
 * Implementations denote recommended maximum amounts of vertex and index data,
 * which may be queried by calling glGet with argument GL_MAX_ELEMENTS_VERTICES
 * and GL_MAX_ELEMENTS_INDICES. If end−start+1 is greater than the value of
 * GL_MAX_ELEMENTS_VERTICES, or if count is greater than the value of
 * GL_MAX_ELEMENTS_INDICES, then the call may operate at reduced performance.
 * There is no requirement that all vertices in the range [start,end] be
 * referenced. However, the implementation may partially process unused
 * vertices, reducing performance from what could be achieved with an optimal
 * index set.
 *
 * When glDrawRangeElements is called, it uses count sequential elements from
 * an enabled array, starting at start to construct a sequence of geometric
 * primitives. mode specifies what kind of primitives are constructed, and
 * how the array elements construct these primitives. If more than one
 * array is enabled, each is used.
 *
 * Vertex attributes that are modified by glDrawRangeElements have an
 * unspecified value after glDrawRangeElements returns. Attributes that
 * aren't modified maintain their previous values.
 *
 * @param type        Specifies what kind of primitives to render.
 * @param start       Specifies the minimum array index contained in indices.
 * @param end         Specifies the maximum array index contained in indices.
 * @param count       Specifies the number of elements to be rendered.
 * @param indices     Specifies the offset pointer in the index buffer
 * @see glDrawRangeElements
 * @version OpenGL 1.2
 */
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
/**
 * @brief ender indexed primitives from array data, taking parameters from memory
 *
 * glDrawElementsIndirect specifies multiple indexed geometric primitives with
 * very few subroutine calls. glDrawElementsIndirect behaves similarly to
 * glDrawElementsInstancedBaseVertexBaseInstance​, except that the parameters
 * to glDrawElementsInstancedBaseVertexBaseInstance​ are stored in the buffer
 * bound to GL_DRAW_INDIRECT_BUFFER​, offset by indirect bytes.
 *
 * The parameters referenced by indirect are packed into a structure that
 * takes the form (in C):
 *
 * typedef  struct {
 *     uint  count;
 *     uint  primCount;
 *     uint  firstIndex;
 *     uint  baseVertex;
 *     uint  baseInstance;
 * } DrawElementsIndirectCommand;
 *
 * glDrawElementsIndirect is equivalent to:
 *
 *  void glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect)
 *  {
 *      const DrawElementsIndirectCommand *cmd  =
 *        (const DrawElementsIndirectCommand *)indirect;
 *      glDrawElementsInstancedBaseVertexBaseInstance(
 *        mode,
 *        cmd->count,
 *        type,
 *        cmd->firstIndex * size-of-type,
 *        cmd->primCount,
 *        cmd->baseVertex,
 *        cmd->baseInstance
 *      );
 *  }
 * indirect is interpreted as an offset, in basic machine units, into the
 * buffer bound to GL_DRAW_INDIRECT_BUFFER​ at the time of the call. That
 * buffer and the parameter data stored there is read from the buffer and
 * executed. If no buffer is bound to the GL_ELEMENT_ARRAY_BUFFER​ binding, an
 * error will be generated.
 *
 * Vertex attributes that are modified by glDrawElementsIndirect have an
 * unspecified value after glDrawElementsIndirect returns. Attributes that
 * aren't modified remain well defined.
 *
 * Notes: The baseInstance​ member of the DrawElementsIndirectCommand​ structure
 * is defined only if the GL version is 4.2 or greater. For versions of the GL
 * less than 4.2, this parameter is present but is reserved and should be set
 * to zero. On earlier versions of the GL, behavior is undefined if it is
 * non-zero.
 *
 * @param type       Specifies what kind of primitives to render.
 * @param index_type Specifies the type of data in the IndexBuffer.
 * @param indirect   Specifies a byte offset (cast to a pointer type) into the
 *                   buffer bound to GL_DRAW_INDIRECT_BUFFER​, which designates
 *                   the starting point of the structure containing the draw
 *                   parameters.
 * @see glDrawElementsIndirect
 * @version OpenGL 4.0
 */
inline void DrawElementsIndirect(PrimType type,
                                 IndexType index_type,
                                 const void* indirect = nullptr) {
  gl(DrawElementsIndirect(
    GLenum(type), GLenum(index_type), indirect
  ));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMultiDrawElementsIndirect)
/**
 * @brief glMultiDrawElementsIndirect: render indexed primitives from array
 *        data, taking parameters from memory
 *
 * glMultiDrawElementsIndirect specifies multiple indexed geometric primitives
 * with very few subroutine calls. glMultiDrawElementsIndirect behaves like
 * repeated calls to glDrawElementsIndirect​.
 *
 * The parameters addressed by indirect are packed into a structure that takes
 * the form (in C):
 *
 * typedef  struct {
 *     uint  count;
 *     uint  instanceCount;
 *     uint  firstIndex;
 *     uint  baseVertex;
 *     uint  baseInstance;
 * } DrawElementsIndirectCommand;
 * A single call to glMultiDrawElementsIndirect is equivalent, assuming no
 * errors are generated to:
 *
 * GLsizei n;
 * for (n = 0; n < drawcount; n++)
 * {
 *     const DrawElementsIndirectCommand  *cmd;
 *     if (stride != 0)
 *     {
 *         cmd = (const DrawElementsIndirectCommand  *)
 *               ((uintptr)indirect + n * stride);
 *     }
 *     else
 *     {
 *         cmd = (const DrawElementsIndirectCommand  *)indirect + n;
 *     }
 *
 *     glDrawElementsInstancedBaseVertexBaseInstance(
 *       mode,
 *       cmd->count,
 *       type,
 *       cmd->firstIndex + size-of-type,
 *       cmd->instanceCount,
 *       cmd->baseVertex,
 *       cmd->baseInstance
 *      );
 * }
 *
 * indirect is interpreted as an offset, in basic machine units, into the
 * buffer bound to GL_DRAW_INDIRECT_BUFFER​ at the time of the call. That
 * buffer and the parameter data stored there is read from the buffer and
 * executed. If no buffer is bound to the GL_ELEMENT_ARRAY_BUFFER​ binding, an
 * error will be generated.
 *
 * The results of the operation are undefined if the reservedMustBeZero​ member
 * of the parameter structure is non-zero. However, no error is generated in
 * this case.
 *
 * Vertex attributes that are modified by glDrawElementsIndirect have an
 * unspecified value after glDrawElementsIndirect returns. Attributes that
 * aren't modified remain well defined.
 *
 * Notes: The baseInstance​ member of the DrawElementsIndirectCommand​ structure
 * is defined only if the GL version is 4.2 or greater. For versions of the GL
 * less than 4.2, this parameter is present but is reserved and should be set
 * to zero. On earlier versions of the GL, behavior is undefined if it is
 * non-zero.
 *
 * @param type       Specifies what kind of primitives to render.
 * @param index_type Specifies the type of data in the IndexBuffer.
 * @param draw_count Specifies a byte offset (cast to a pointer type) into the
 *                   buffer bound to GL_DRAW_INDIRECT_BUFFER​, which designates
 *                   the starting point of the structure containing the draw
 *                   parameters.
 * @param stride     Specifies the number of elements in the array addressed
 *                   by indirect.
 * @param indirect   Specifies the distance in basic machine units between
 *                   elements of the draw parameter array.
 * @see glMultiDrawElementsIndirect
 * @version OpenGL 4.3
 */
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
/**
 * @brief render primitives from array data with a per-element offset
 *
 * glDrawElementsBaseVertex behaves identically to glDrawElements​ except that
 * each index fetched from GL_ELEMENT_ARRAY_BUFFER​ (starting from the byte
 * offset indices​ in bytesbytes) will have basevertex​ added to it before
 * fetching that index from the vertex arrays. If the resulting index is
 * larger than the maximum value representable by type​, it is as if the
 * calculation were upconverted to 32-bit unsigned integers (with wrapping on
 * overflow conditions). The operation is undefined if the sum would be negative.
 *
 * The gl_VertexID​ passed to the Vertex Shader will be the index after being
 * offset by basevertex​, not the index fetched from the buffer.
 *
 * @param type        Specifies what kind of primitives to render.
 * @param count       Specifies the number of elements to be rendered.
 * @param index_type  Specifies the type of the values in indices.
 * @param base_vertex Specifies a constant that should be added to each
 *                    element of indices​ when chosing elements from the
 *                    enabled vertex arrays.
 * @see glDrawElementsBaseVertex
 * @version OpenGL 3.2
 */
inline void DrawElementsBaseVertex(PrimType type,
                                   GLsizei count,
                                   IndexType index_type,
                                   GLint base_vertex) {
  gl(DrawElementsBaseVertex(
    GLenum(type), count, GLenum(index_type), nullptr, base_vertex
  ));
}

template<typename GLtype>
/**
 * @brief render primitives from array data with a per-element offset
 *
 * glDrawElementsBaseVertex behaves identically to glDrawElements​ except that
 * each index fetched from GL_ELEMENT_ARRAY_BUFFER​ (starting from the byte
 * offset indices​ in bytesbytes) will have basevertex​ added to it before
 * fetching that index from the vertex arrays. If the resulting index is
 * larger than the maximum value representable by type​, it is as if the
 * calculation were upconverted to 32-bit unsigned integers (with wrapping on
 * overflow conditions). The operation is undefined if the sum would be negative.
 *
 * The gl_VertexID​ passed to the Vertex Shader will be the index after being
 * offset by basevertex​, not the index fetched from the buffer.
 *
 * @param type        Specifies what kind of primitives to render.
 * @param count       Specifies the number of elements to be rendered.
 * @param indices     Specifies a byte offset (cast to a pointer type) into
 *                    the buffer bound to GL_ELEMENT_ARRAY_BUFFER​ to start
 *                    reading indices from.
 * @param base_vertex Specifies a constant that should be added to each
 *                    element of indices​ when chosing elements from the
 *                    enabled vertex arrays.
 * @see glDrawElementsBaseVertex
 * @version OpenGL 3.2
 */
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
/**
 * @brief render primitives from array data with a per-element offset
 *
 * glDrawRangeElementsBaseVertex is a restricted form of
 * glDrawElementsBaseVertex​. mode​, start​, end​, count​ and basevertex​ match the
 * corresponding arguments to glDrawElementsBaseVertex​, with the additional
 * constraint that all values in the array indices​ must lie between start​ and
 * end​, inclusive, prior to adding basevertex​. Index values lying outside the
 * range [start​, end​] are treated in the same way as glDrawRangeElements​.
 *
 * Each index fetched from GL_ELEMENT_ARRAY_BUFFER​ (starting from the byte
 * offset indices​ in bytesbytes) will have basevertex​ added to it before
 * fetching that index from the vertex arrays. If the resulting value is
 * larger than the maximum value representable by type​, it is as if the
 * calculation were upconverted to 32-bit unsigned integers (with wrapping on
 * overflow conditions). The operation is undefined if the sum would be negative.
 *
 * @param type        Specifies what kind of primitives to render.
 * @param start       Specifies the minimum array index contained in indices​.
 * @param end         Specifies the maximum array index contained in indices​.
 * @param count       Specifies the number of elements to be rendered.
 * @param index_type  Specifies the type of the values in indices.
 * @param base_vertex Specifies a constant that should be added to each
 *                    element of indices​ when chosing elements from the
 *                    enabled vertex arrays.
 * @see glDrawRangeElementsBaseVertex
 * @version OpenGL 3.2
 */
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
/**
 * @brief render primitives from array data with a per-element offset
 *
 * glDrawRangeElementsBaseVertex is a restricted form of
 * glDrawElementsBaseVertex​. mode​, start​, end​, count​ and basevertex​ match the
 * corresponding arguments to glDrawElementsBaseVertex​, with the additional
 * constraint that all values in the array indices​ must lie between start​ and
 * end​, inclusive, prior to adding basevertex​. Index values lying outside the
 * range [start​, end​] are treated in the same way as glDrawRangeElements​.
 *
 * Each index fetched from GL_ELEMENT_ARRAY_BUFFER​ (starting from the byte
 * offset indices​ in bytesbytes) will have basevertex​ added to it before
 * fetching that index from the vertex arrays. If the resulting value is
 * larger than the maximum value representable by type​, it is as if the
 * calculation were upconverted to 32-bit unsigned integers (with wrapping on
 * overflow conditions). The operation is undefined if the sum would be negative.
 *
 * @param type        Specifies what kind of primitives to render.
 * @param start       Specifies the minimum array index contained in indices​.
 * @param end         Specifies the maximum array index contained in indices​.
 * @param count       Specifies the number of elements to be rendered.
 * @param indices     Specifies a byte offset (cast to a pointer type) into
 *                    the buffer bound to GL_ELEMENT_ARRAY_BUFFER​ to start
 *                    reading indices from.
 * @param base_vertex Specifies a constant that should be added to each
 *                    element of indices​ when choosing elements from the
 *                    enabled vertex arrays.
 * @see glDrawRangeElementsBaseVertex
 * @version OpenGL 3.2
 */
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
/**
 * @brief render multiple instances of a set of primitives from array data
 *        with a per-element offset
 *
 * glDrawElementsInstancedBaseVertex behaves identically to
 * glDrawElementsInstanced​ except that each index fetched from
 * GL_ELEMENT_ARRAY_BUFFER​ (starting from the byte offset indices​ in
 * bytesbytes) will have basevertex​ added to it before fetching that index
 * from the vertex arrays. If the resulting value is larger than the maximum
 * value representable by type​, it is as if the calculation were upconverted
 * to 32-bit unsigned integers (with wrapping on overflow conditions).
 * The operation is undefined if the sum would be negative.
 *
 * @param type        Specifies what kind of primitives to render.
 * @param count       Specifies the number of elements to be rendered.
 * @param index_type  Specifies the type of the values in indices.
 * @param inst_count  Specifies the number of instances of the indexed
 *                    geometry that should be drawn.
 * @param base_vertex Specifies a constant that should be added to each
 *                    element of indices​ when choosing elements from the
 *                    enabled vertex arrays.
 * @see glDrawElementsInstancedBaseVertex
 * @version OpenGL 3.2
 */
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
/**
 * @brief render multiple instances of a set of primitives from array data
 *        with a per-element offset
 *
 * glDrawElementsInstancedBaseVertex behaves identically to
 * glDrawElementsInstanced​ except that each index fetched from
 * GL_ELEMENT_ARRAY_BUFFER​ (starting from the byte offset indices​ in
 * bytesbytes) will have basevertex​ added to it before fetching that index
 * from the vertex arrays. If the resulting value is larger than the maximum
 * value representable by type​, it is as if the calculation were upconverted
 * to 32-bit unsigned integers (with wrapping on overflow conditions).
 * The operation is undefined if the sum would be negative.
 *
 * @param type        Specifies what kind of primitives to render.
 * @param count       Specifies the number of elements to be rendered.
 * @param indices     Specifies a byte offset (cast to a pointer type) into
 *                    the buffer bound to GL_ELEMENT_ARRAY_BUFFER​ to start
 *                    reading indices from.
 * @param inst_count  Specifies the number of instances of the indexed
 *                    geometry that should be drawn.
 * @param base_vertex Specifies a constant that should be added to each
 *                    element of indices​ when choosing elements from the
 *                    enabled vertex arrays.
 * @see glDrawElementsInstancedBaseVertex
 * @version OpenGL 3.2
 */
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
/**
 * @brief render multiple sets of primitives by specifying indices of array
 *        data elements and an index to apply to each index
 *
 * glMultiDrawElementsBaseVertex behaves identically to
 * glDrawElementsBaseVertex, except that draw_count separate lists of elements
 * are specified instead.
 *
 * It has the same effect as:
 *
 *  for (int i = 0; i < draw_count; i++)
 *     if (count[i] > 0)
 *         glDrawElementsBaseVertex(mode,
 *                                  count[i],
 *                                  type,
 *                                  indices[i],
 *                                  basevertex[i]);
 *
 * @param type        Specifies what kind of primitives to render.
 * @param count       Points to an array of the elements counts.
 * @param index_type  Specifies the type of the values in indices.
 * @param draw_count  Specifies the size of the count array.
 * @param base_vertex Specifies a pointer to the location where the base
 *                    vertices are stored.
 * @see glMultiDrawElementsBaseVertex
 * @version OpenGL 3.2
 */
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
/**
 * @brief render multiple sets of primitives by specifying indices of array
 *        data elements and an index to apply to each index
 *
 * glMultiDrawElementsBaseVertex behaves identically to
 * glDrawElementsBaseVertex, except that draw_count separate lists of elements
 * are specified instead.
 *
 * It has the same effect as:
 *
 *  for (int i = 0; i < draw_count; i++)
 *     if (count[i] > 0)
 *         glDrawElementsBaseVertex(mode,
 *                                  count[i],
 *                                  type,
 *                                  indices[i],
 *                                  basevertex[i]);
 *
 * @param type        Specifies what kind of primitives to render.
 * @param count       Points to an array of the elements counts.
 * @param indices     Points to an array of draw_count​ values, where each value
 *                    is a byte offset (cast to a pointer type) into the buffer
 *                    bound to GL_ELEMENT_ARRAY_BUFFER​ to start reading indices
 *                    from.
 * @param draw_count  Specifies the size of the count array.
 * @param base_vertex Specifies a pointer to the location where the base
 *                    vertices are stored.
 * @see glMultiDrawElementsBaseVertex
 * @version OpenGL 3.2
 */
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
/**
 * @brief render multiple instances of a set of primitives from array data
 *        with a per-element offset
 *
 * glDrawElementsInstancedBaseVertexBaseInstance behaves identically to
 * glDrawElementsInstanced​ except that each index fetched from
 * GL_ELEMENT_ARRAY_BUFFER​ (starting from the byte offset indices​ in bytes)
 * will have base_vertex​ added to it before fetching that index from the vertex
 * arrays. If the resulting value is larger than the maximum value
 * representable by type​, it is as if the calculation were upconverted to
 * 32-bit unsigned integers (with wrapping on overflow conditions). The
 * operation is undefined if the sum would be negative.
 *
 * Specific vertex attributes may be classified as instanced through the use
 * of glVertexAttribDivisor​. Instanced vertex attributes supply per-instance
 * vertex data to the vertex shader. The index of the vertex fetched from the
 * enabled instanced vertex attribute arrays is calculated as
 * ⌊gl_InstanceID/divisor⌋+baseInstance. Note that base_instance​ does not
 * affect the shader-visible value of gl_InstanceID​.
 *
 * @param type          Specifies what kind of primitives to render.
 * @param count         Specifies the number of elements to be rendered.
 * @param index_type    Specifies the type of the values in indices.
 * @param inst_count    Specifies the number of instances of the indexed
 *                      geometry that should be drawn.
 * @param base_vertex   Specifies a constant that should be added to each
 *                      element of indices​ when choosing elements from the
 *                      enabled vertex arrays.
 * @param base_instance Specifies the base instance for use in fetching
 *                      instanced vertex attributes.
 * @see glDrawElementsInstancedBaseVertexBaseInstance
 * @version OpenGL 4.2
 */
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
/**
 * @brief render multiple instances of a set of primitives from array data
 *        with a per-element offset
 *
 * glDrawElementsInstancedBaseVertexBaseInstance behaves identically to
 * glDrawElementsInstanced​ except that each index fetched from
 * GL_ELEMENT_ARRAY_BUFFER​ (starting from the byte offset indices​ in bytes)
 * will have base_vertex​ added to it before fetching that index from the vertex
 * arrays. If the resulting value is larger than the maximum value
 * representable by type​, it is as if the calculation were upconverted to
 * 32-bit unsigned integers (with wrapping on overflow conditions). The
 * operation is undefined if the sum would be negative.
 *
 * Specific vertex attributes may be classified as instanced through the use
 * of glVertexAttribDivisor​. Instanced vertex attributes supply per-instance
 * vertex data to the vertex shader. The index of the vertex fetched from the
 * enabled instanced vertex attribute arrays is calculated as
 * ⌊gl_InstanceID/divisor⌋+baseInstance. Note that base_instance​ does not
 * affect the shader-visible value of gl_InstanceID​.
 *
 * @param type          Specifies what kind of primitives to render.
 * @param count         Specifies the number of elements to be rendered.
 * @param indices       Specifies a byte offset (cast to a pointer type) into
 *                      the buffer bound to GL_ELEMENT_ARRAY_BUFFER​ to start
 *                      reading indices from.
 * @param inst_count    Specifies the number of instances of the indexed
 *                      geometry that should be drawn.
 * @param base_vertex   Specifies a constant that should be added to each
 *                      element of indices​ when choosing elements from the
 *                      enabled vertex arrays.
 * @param base_instance Specifies the base instance for use in fetching
 *                      instanced vertex attributes.
 * @see glDrawElementsInstancedBaseVertexBaseInstance
 * @version OpenGL 4.2
 */
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
/**
 * @brief Sets the primitive restart index.
 *
 * glPrimitiveRestartIndex specifies a vertex array element that is treated
 * specially when primitive restarting is enabled. This is known as the
 * primitive restart index.
 *
 * When one of the Draw* commands transfers a set of generic attribute array
 * elements to the GL, if the index within the vertex arrays corresponding to
 * that set is equal to the primitive restart index, then the GL does not
 * process those elements as a vertex. Instead, it is as if the drawing
 * command ended with the immediately preceding transfer, and another drawing
 * command is immediately started with the same parameters, but only
 * transferring the immediately following element through the end of the
 * originally specified elements.
 *
 * When either glDrawElementsBaseVertex, glDrawElementsInstancedBaseVertex or
 * glMultiDrawElementsBaseVertex is used, the primitive restart comparison
 * occurs before the basevertex offset is added to the array index.
 *
 * @param index Specifies the index to function as primitive restart.
 * @see glPrimitiveRestartIndex
 * @version OpenGL 3.1
 */
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
