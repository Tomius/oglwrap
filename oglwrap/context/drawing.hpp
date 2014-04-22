/** @file drawing.hpp
    @brief Wrapper for primitive drawing operations.
*/

#ifndef OGLWRAP_CONTEXT_DRAWING_HPP_
#define OGLWRAP_CONTEXT_DRAWING_HPP_

#include "../config.hpp"
#include "../enums.hpp"
#include "../debug/error.hpp"
#include "../define_internal_macros.hpp"

namespace oglwrap {
namespace context {

/// Wrapper for primitive drawing operations
class Drawing {
public:
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
  static void DrawArrays(PrimitiveType type,
                         GLint first,
                         GLsizei count) {
    gl(DrawArrays(type, first, count));
  }

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawArraysInstanced)
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
  static void DrawArraysInstanced(PrimitiveType type,
                                  GLint first,
                                  GLsizei count,
                                  GLsizei inst_count) {
    gl(DrawArraysInstanced(type, first, count, inst_count));
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawArraysInstancedBaseInstance)
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
   * ⌊gl_InstanceID/divisor⌋+baseInstance. Note that baseinstance​ does not
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
  static void DrawArraysInstancedBaseInstance(PrimitiveType type,
                                              GLint first,
                                              GLsizei count,
                                              GLsizei inst_count,
                                              GLsizei base_instance) {
    gl(DrawArraysInstancedBaseInstance(
      type, first, count, inst_count, base_instance
    ));
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawArraysIndirect)
  /**
   * @brief Renders primitives from array data, taking parameters from memory.
   *
   * glDrawArraysIndirect specifies multiple geometric primitives with very few
   * subroutine calls. glDrawArraysIndirect behaves similarly to
   * glDrawArraysInstancedBaseInstance​, except that the parameters to
   * glDrawArraysInstancedBaseInstance​ are stored in the buffer bound to
   * GL_DRAW_INDIRECT_BUFFER​, offset by indirect​ bytes.
   *
   * The parameters referenced by indirect​ are packed into a structure that
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
   * indirect​ is interpreted as an offset, in basic machine units, into the
   * buffer bound to GL_DRAW_INDIRECT_BUFFER​ at the time of the call. The
   * parameter data stored there is read from the buffer and executed.
   *
   * In contrast to glDrawArraysInstancedBaseInstance​, the first​ member of the
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
  static void DrawArraysIndirect(PrimitiveType type,
                                 const void *indirect = nullptr) {
    gl(DrawArraysIndirect(type, indirect));
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glMultiDrawArrays)
  /**
   * @brief Renders multiple sets of primitives from array data
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
  static void MultiDrawArrays(PrimitiveType type,
                              const GLint *first,
                              const GLsizei *count,
                              GLsizei prim_count) {
    gl(MultiDrawArrays(type, first, count, prim_count));
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glMultiDrawArraysIndirect)
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
  static void MultiDrawArraysIndirect(PrimitiveType type,
                                      const void *indirect,
                                      GLsizei draw_count,
                                      GLsizei stride) {
    gl(MultiDrawArraysIndirect(type, indirect, draw_count, stride));
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
  static void DrawElements(PrimitiveType type,
                           GLsizei count,
                           IndexType index_type) {
    gl(DrawElements(type, count, index_type, nullptr));
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
  static void DrawElements(PrimitiveType type,
                           GLsizei count,
                           const GLtype* indices) {
    static_assert((sizeof(GLtype), false),
      "index type must be one of GLubyte, GLushort, or GLuint"
    );
  }


  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstanced)
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
  static void DrawElementsInstanced(PrimitiveType type,
                                    GLsizei count,
                                    IndexType index_type,
                                    GLsizei inst_count) {
    gl(DrawElementsInstanced(type, count, index_type, nullptr, inst_count));
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
  static void DrawElementsInstanced(PrimitiveType type,
                                    GLsizei count,
                                    const GLtype* indices,
                                    GLsizei inst_count) {
    static_assert((sizeof(GLtype), false),
      "index type must be one of GLubyte, GLushort, or GLuint"
    );
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstancedBaseInstance)
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
  static void DrawElementsInstancedBaseInstance(PrimitiveType type,
                                                GLsizei count,
                                                IndexType index_type,
                                                GLsizei inst_count,
                                                GLuint base_instance) {
    gl(DrawElementsInstancedBaseInstance(
      type, count, index_type, nullptr, inst_count, base_instance
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
  static void DrawElementsInstancedBaseInstance(PrimitiveType type,
                                                GLsizei count,
                                                const GLtype* indices,
                                                GLsizei inst_count,
                                                GLuint base_instance) {
    static_assert((sizeof(GLtype), false),
      "index type must be one of GLubyte, GLushort, or GLuint"
    );
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glMultiDrawElements)
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
  static void MultiDrawElements(PrimitiveType type,
                                const GLsizei* count,
                                const GLtype* const* indices,
                                GLsizei draw_count) {
    static_assert((sizeof(GLtype), false),
      "index type must be one of GLubyte, GLushort, or GLuint"
    );
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawRangeElements)
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
  static void DrawRangeElements(PrimitiveType type,
                                GLuint start,
                                GLuint end,
                                GLsizei count,
                                IndexType index_type) {
    gl(DrawRangeElements(type, start, end, count, index_type, nullptr));
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
  static void DrawRangeElements(PrimitiveType type,
                                GLuint start,
                                GLuint end,
                                GLsizei count,
                                const GLtype* indices) {
    static_assert((sizeof(GLtype), false),
      "index type must be one of GLubyte, GLushort, or GLuint"
    );
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsIndirect)
  /**
   * @brief ender indexed primitives from array data, taking parameters from memory
   *
   * glDrawElementsIndirect specifies multiple indexed geometric primitives with
   * very few subroutine calls. glDrawElementsIndirect behaves similarly to
   * glDrawElementsInstancedBaseVertexBaseInstance​, except that the parameters
   * to glDrawElementsInstancedBaseVertexBaseInstance​ are stored in the buffer
   * bound to GL_DRAW_INDIRECT_BUFFER​, offset by indirect​ bytes.
   *
   * The parameters referenced by indirect​ are packed into a structure that
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
   * indirect​ is interpreted as an offset, in basic machine units, into the
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
  static void DrawElementsIndirect(PrimType type,
                                   IndexType index_type,
                                   const void* indirect = nullptr) {
    gl(DrawElementsIndirect(type, index_type, indirect));
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glMultiDrawElementsIndirect)
  static void MultiDrawElementsIndirect(PrimType type,
                                        IndexType index_type,
                                        GLsizei draw_count,
                                        GLsizei stride = 0,
                                        const void* indirect = nullptr) {
    gl(MultiDrawElementsIndirect(type, index_type, indirect, draw_count, stride));
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsBaseVertex)
  static void DrawElementsBaseVertex(PrimType type,
                                     GLsizei count,
                                     IndexType index_type,
                                     GLint base_vertex) {
    gl(DrawElementsBaseVertex(type, count, index_type, nullptr, base_vertex));
  }

  template<typename GLtype>
  static void DrawElementsBaseVertex(PrimType type,
                                     GLsizei count,
                                     const GLtype* indices,
                                     GLint base_vertex) {
    static_assert((sizeof(GLtype), false),
      "index type must be one of GLubyte, GLushort, or GLuint"
    );
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawRangeElementsBaseVertex)
  static void DrawRangeElementsBaseVertex(PrimType type,
                                          GLuint start,
                                          GLuint end,
                                          GLsizei count,
                                          IndexType index_type,
                                          GLint base_vertex) {
    gl(DrawRangeElementsBaseVertex(
      type, start, end, count, index_type, nullptr, base_vertex
    ));
  }

  template<typename GLtype>
  static void DrawRangeElementsBaseVertex(PrimType type,
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

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstancedBaseVertex)
  static void DrawElementsInstancedBaseVertex(PrimType type,
                                              GLsizei count,
                                              IndexType index_type,
                                              GLsizei inst_count,
                                              GLint base_vertex) {
    gl(DrawElementsInstancedBaseVertex(
      type, count, index_type, nullptr, inst_count, base_vertex
    ));
  }

  template<typename GLtype>
  static void DrawElementsInstancedBaseVertex(PrimType type,
                                              GLsizei count,
                                              const GLtype* indices,
                                              GLsizei inst_count,
                                              GLint base_vertex) {
    static_assert((sizeof(GLtype), false),
      "index type must be one of GLubyte, GLushort, or GLuint"
    );
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glMultiDrawElementsBaseVertex)
  static void MultiDrawElementsBaseVertex(PrimType type,
                                          const GLsizei *count,
                                          IndexType index_type,
                                          GLuint draw_count,
                                          const GLint *base_vertex) {
    gl(MultiDrawElementsBaseVertex(
      type, (GLsizei*)count, index_type, nullptr,
      draw_count, (GLint*)base_vertex
    ));
  }

  template<typename GLtype>
  static void MultiDrawElementsBaseVertex(PrimType type,
                                          const GLsizei *count,
                                          const GLtype* const* indices,
                                          GLuint draw_count,
                                          const GLint *base_vertex) {
    static_assert((sizeof(GLtype), false),
      "index type must be one of GLubyte, GLushort, or GLuint"
    );
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstancedBaseVertexBaseInstance)
  static void DrawElementsInstancedBaseVertexBaseInstance(PrimType type,
                                                         GLsizei count,
                                                         IndexType index_type,
                                                         GLsizei inst_count,
                                                         GLint base_vertex,
                                                         GLuint base_instance) {
    gl(DrawElementsInstancedBaseVertexBaseInstance(
      type, count, index_type, nullptr, inst_count, base_vertex, base_instance
    ));
  }

  template<typename GLtype>
  static void DrawElementsInstancedBaseVertexBaseInstance(PrimType type,
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


  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glPrimitiveRestartIndex)
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
  static void PrimitiveRestartIndex(GLuint index) {
    gl(PrimitiveRestartIndex(index));
  }
  #endif
};


template<>
inline void Drawing::DrawElements<GLubyte>(PrimitiveType type,
                                           GLsizei count,
                                           const GLubyte* indices) {
  gl(DrawElements(type, count, DataType::UnsignedByte, indices));
}

template<>
inline void Drawing::DrawElements<GLushort>(PrimitiveType type,
                                            GLsizei count,
                                            const GLushort* indices) {
  gl(DrawElements(type, count, DataType::UnsignedShort, indices));
}

template<>
inline void Drawing::DrawElements<GLuint>(PrimitiveType type,
                                          GLsizei count,
                                          const GLuint* indices) {
  gl(DrawElements(type, count, DataType::UnsignedInt, indices));
}

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstanced)
template<>
inline void Drawing::DrawElementsInstanced<GLubyte>(PrimitiveType type,
                                                    GLsizei count,
                                                    const GLubyte* indices,
                                                    GLsizei inst_count) {
  gl(DrawElementsInstanced(
    type, count, DataType::UnsignedByte, indices, inst_count
  ));
}

template<>
inline void Drawing::DrawElementsInstanced<GLushort>(PrimitiveType type,
                                                     GLsizei count,
                                                     const GLushort* indices,
                                                     GLsizei inst_count) {
  gl(DrawElementsInstanced(
    type, count, DataType::UnsignedShort, indices, inst_count
  ));
}

template<>
inline void Drawing::DrawElementsInstanced<GLuint>(PrimitiveType type,
                                                   GLsizei count,
                                                   const GLuint* indices,
                                                   GLsizei inst_count) {
  gl(DrawElementsInstanced(
    type, count, DataType::UnsignedInt, indices, inst_count
  ));
}
#endif

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstancedBaseInstance)
template<>
inline void Drawing::DrawElementsInstancedBaseInstance<GLubyte>(
                                                  PrimitiveType type,
                                                  GLsizei count,
                                                  const GLubyte* indices,
                                                  GLsizei inst_count,
                                                  GLuint base_instance) {
  gl(DrawElementsInstancedBaseInstance(
    type, count, DataType::UnsignedByte, indices, inst_count, base_instance
  ));
}

template<>
inline void Drawing::DrawElementsInstancedBaseInstance<GLushort>(
                                                  PrimitiveType type,
                                                  GLsizei count,
                                                  const GLushort* indices,
                                                  GLsizei inst_count,
                                                  GLuint base_instance) {
  gl(DrawElementsInstancedBaseInstance(
    type, count, DataType::UnsignedShort, indices, inst_count, base_instance
  ));
}

template<>
inline void Drawing::DrawElementsInstancedBaseInstance<GLuint>(
                                                  PrimitiveType type,
                                                  GLsizei count,
                                                  const GLuint* indices,
                                                  GLsizei inst_count,
                                                  GLuint base_instance) {
  gl(DrawElementsInstancedBaseInstance(
    type, count, DataType::UnsignedInt, indices, inst_count, base_instance
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

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glMultiDrawElements)
template<>
inline void Drawing::MultiDrawElements<GLubyte>(PrimitiveType type,
                                                const GLsizei* count,
                                                const GLubyte* const* indices,
                                                GLsizei draw_count) {
  gl(MultiDrawElements(
    type, count, DataType::UnsignedByte,
    OGLWRAP_POINTER_HACKER(indices), draw_count
  ));
}

template<>
inline void Drawing::MultiDrawElements<GLushort>(PrimitiveType type,
                                                 const GLsizei* count,
                                                 const GLushort* const* indices,
                                                 GLsizei draw_count) {
  gl(MultiDrawElements(
    type, count, DataType::UnsignedShort,
    OGLWRAP_POINTER_HACKER(indices), draw_count
  ));
}

template<>
inline void Drawing::MultiDrawElements<GLuint>(PrimitiveType type,
                                               const GLsizei* count,
                                               const GLuint* const* indices,
                                               GLsizei draw_count) {
  gl(MultiDrawElements(
    type, count, DataType::UnsignedInt,
    OGLWRAP_POINTER_HACKER(indices), draw_count
  ));
}
#endif

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawRangeElements)
template<>
inline void Drawing::DrawRangeElements<GLubyte>(PrimitiveType type,
                                                GLuint start,
                                                GLuint end,
                                                GLsizei count,
                                                const GLubyte* indices) {
  gl(DrawRangeElements(
    type, start, end, count, IndexType::UnsignedByte, indices
  ));
}
template<>
inline void Drawing::DrawRangeElements<GLushort>(PrimitiveType type,
                                                 GLuint start,
                                                 GLuint end,
                                                 GLsizei count,
                                                 const GLushort* indices) {
  gl(DrawRangeElements(
    type, start, end, count, IndexType::UnsignedShort, indices
  ));
}
template<>
inline void Drawing::DrawRangeElements<GLuint>(PrimitiveType type,
                                               GLuint start,
                                               GLuint end,
                                               GLsizei count,
                                               const GLuint* indices) {
  gl(DrawRangeElements(
    type, start, end, count, IndexType::UnsignedInt, indices
  ));
}
#endif

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsBaseVertex)
template<>
inline void Drawing::DrawElementsBaseVertex<GLubyte>(PrimType type,
                                                     GLsizei count,
                                                     const GLubyte* indices,
                                                     GLint base_vertex) {
  gl(DrawElementsBaseVertex(
    type, count, IndexType::UnsignedByte, (void*)indices, base_vertex
  ));
}
template<>
inline void Drawing::DrawElementsBaseVertex<GLushort>(PrimType type,
                                                      GLsizei count,
                                                      const GLushort* indices,
                                                      GLint base_vertex) {
  gl(DrawElementsBaseVertex(
    type, count, IndexType::UnsignedShort, (void*)indices, base_vertex
  ));
}
template<>
inline void Drawing::DrawElementsBaseVertex<GLuint>(PrimType type,
                                                    GLsizei count,
                                                    const GLuint* indices,
                                                    GLint base_vertex) {
  gl(DrawElementsBaseVertex(
    type, count, IndexType::UnsignedInt, (void*)indices, base_vertex
  ));
}
#endif

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawRangeElementsBaseVertex)
template<>
inline void Drawing::DrawRangeElementsBaseVertex<GLubyte>(PrimType type,
                                                          GLuint start,
                                                          GLuint end,
                                                          GLsizei count,
                                                          const GLubyte* indices,
                                                          GLint base_vertex) {
  gl(DrawRangeElementsBaseVertex(
    type, start, end, count, IndexType::UnsignedByte,
    (void*)indices, base_vertex
  ));
}
template<>
inline void Drawing::DrawRangeElementsBaseVertex<GLushort>(PrimType type,
                                                          GLuint start,
                                                          GLuint end,
                                                          GLsizei count,
                                                          const GLushort* indices,
                                                          GLint base_vertex) {
  gl(DrawRangeElementsBaseVertex(
    type, start, end, count, IndexType::UnsignedShort,
    (void*)indices, base_vertex
  ));
}
template<>
inline void Drawing::DrawRangeElementsBaseVertex<GLuint>(PrimType type,
                                                         GLuint start,
                                                         GLuint end,
                                                         GLsizei count,
                                                         const GLuint* indices,
                                                         GLint base_vertex) {
  gl(DrawRangeElementsBaseVertex(
    type, start, end, count, IndexType::UnsignedInt,
    (void*)indices, base_vertex
  ));
}
#endif

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstancedBaseVertex)
template<>
inline void Drawing::DrawElementsInstancedBaseVertex<GLubyte>(
                                                    PrimType type,
                                                    GLsizei count,
                                                    const GLubyte* indices,
                                                    GLsizei inst_count,
                                                    GLint base_vertex) {
  gl(DrawElementsInstancedBaseVertex(
    type, count, IndexType::UnsignedByte,
    (void*)indices, inst_count, base_vertex
  ));
}
template<>
inline void Drawing::DrawElementsInstancedBaseVertex<GLushort>(
                                                    PrimType type,
                                                    GLsizei count,
                                                    const GLushort* indices,
                                                    GLsizei inst_count,
                                                    GLint base_vertex) {
  gl(DrawElementsInstancedBaseVertex(
    type, count, IndexType::UnsignedShort,
    (void*)indices, inst_count, base_vertex
  ));
}
template<>
inline void Drawing::DrawElementsInstancedBaseVertex<GLuint>(
                                                    PrimType type,
                                                    GLsizei count,
                                                    const GLuint* indices,
                                                    GLsizei inst_count,
                                                    GLint base_vertex) {
  gl(DrawElementsInstancedBaseVertex(
    type, count, IndexType::UnsignedInt,
    (void*)indices, inst_count, base_vertex
  ));
}
#endif

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glMultiDrawElementsBaseVertex)
template<>
inline void Drawing::MultiDrawElementsBaseVertex<GLubyte>(
                                                  PrimType type,
                                                  const GLsizei *count,
                                                  const GLubyte* const* indices,
                                                  GLuint draw_count,
                                                  const GLint *base_vertex) {
  gl(MultiDrawElementsBaseVertex(
    type, (GLsizei*)count, IndexType::UnsignedByte,
    OGLWRAP_POINTER_HACKER(indices), draw_count, (GLint*)base_vertex
  ));
}
template<>
inline void Drawing::MultiDrawElementsBaseVertex<GLushort>(
                                                  PrimType type,
                                                  const GLsizei *count,
                                                  const GLushort* const* indices,
                                                  GLuint draw_count,
                                                  const GLint *base_vertex) {
  gl(MultiDrawElementsBaseVertex(
    type, (GLsizei*)count, IndexType::UnsignedShort,
    OGLWRAP_POINTER_HACKER(indices), draw_count, (GLint*)base_vertex
  ));
}
template<>
inline void Drawing::MultiDrawElementsBaseVertex<GLuint>(
                                                  PrimType type,
                                                  const GLsizei *count,
                                                  const GLuint* const* indices,
                                                  GLuint draw_count,
                                                  const GLint *base_vertex) {
  gl(MultiDrawElementsBaseVertex(
    type, (GLsizei*)count, IndexType::UnsignedInt,
    OGLWRAP_POINTER_HACKER(indices), draw_count, (GLint*)base_vertex
  ));
}
#endif

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstancedBaseVertexBaseInstance)
template<>
inline void Drawing::DrawElementsInstancedBaseVertexBaseInstance<GLubyte>(
                                                    PrimType type,
                                                    GLsizei count,
                                                    const GLubyte* indices,
                                                    GLsizei inst_count,
                                                    GLint base_vertex,
                                                    GLuint base_instance) {
  gl(DrawElementsInstancedBaseVertexBaseInstance(
    type, count, IndexType::UnsignedByte,
    (void*)indices, inst_count, base_vertex, base_instance
  ));
}
template<>
inline void Drawing::DrawElementsInstancedBaseVertexBaseInstance<GLushort>(
                                                    PrimType type,
                                                    GLsizei count,
                                                    const GLushort* indices,
                                                    GLsizei inst_count,
                                                    GLint base_vertex,
                                                    GLuint base_instance) {
  gl(DrawElementsInstancedBaseVertexBaseInstance(
    type, count, IndexType::UnsignedShort,
    (void*)indices, inst_count, base_vertex, base_instance
  ));
}
template<>
inline void Drawing::DrawElementsInstancedBaseVertexBaseInstance<GLuint>(
                                                    PrimType type,
                                                    GLsizei count,
                                                    const GLuint* indices,
                                                    GLsizei inst_count,
                                                    GLint base_vertex,
                                                    GLuint base_instance) {
  gl(DrawElementsInstancedBaseVertexBaseInstance(
    type, count, IndexType::UnsignedInt,
    (void*)indices, inst_count, base_vertex, base_instance
  ));
}
#endif

}
}

#include "../undefine_internal_macros.hpp"
#endif
