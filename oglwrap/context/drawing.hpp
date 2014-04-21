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

class Drawing {
public:
  /// Draws count of primitives from the bound array buffer.
  /** @param type    Specifies what kind of primitives to render.
    * @param first   Specifies the starting index in the enabled arrays.
    * @param count   Specifies the number of indices to be rendered.
    * @see glDrawArrays */
  static void DrawArrays(PrimitiveType type,
                         GLint first,
                         GLsizei count
  ) {
    gl(DrawArrays(type, first, count));
  }

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawArraysInstaced)
  /// Draw multiples instances of a range of elements.
  /** @param type    Specifies what kind of primitives to render.
    * @param first   Specifies the starting index in the enabled arrays.
    * @param count   Specifies the number of indices to be rendered.
    * @param inst_count - Specifies the number of instances of the specified range of indices to be rendered.
    * @see glDrawArraysInstaced */
  static void DrawArraysInstanced(PrimitiveType type,
                                  GLint first,
                                  GLsizei count,
                                  GLsizei inst_count
  ) {
    gl(DrawArraysInstanced(type, first, count, inst_count));
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawArraysInstancedBaseInstance)
  /// Draw multiples instances of a range of elements from a starting instance count.
  /** @param type           Specifies what kind of primitives to render.
    * @param first          Specifies the starting index in the enabled arrays.
    * @param count          Specifies the number of indices to be rendered.
    * @param inst_count     Specifies the number of instances of the specified range of indices to be rendered.
    * @param base_instace   Specifies the base instance for use in fetching instanced vertex attributes.
    * @see glDrawArraysInstancedBaseInstance */
  static void DrawArraysInstancedBaseInstance(PrimitiveType type,
                                              GLint first,
                                              GLsizei count,
                                              GLsizei inst_count,
                                              GLsizei base_instance
  ) {
    gl(DrawArraysInstancedBaseInstance(
      type, first, count, inst_count, base_instance
    ));
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawArraysIndirect)
  /// Render primitives from array data, taking parameters from memory
  /** @param mode       Specifies what kind of primitives to render.
    * @param indirect   Specifies the address of a structure containing the draw parameters.
    * @see glDrawArraysIndirect */
  static void DrawArraysIndirect(PrimitiveType type, const void *indirect) {
    gl(DrawArraysIndirect(type, indirect));
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glMultiDrawArrays)
  /// Render multiple sets of primitives from array data
  /** @param type       Specifies what kind of primitives to render.
    * @param first      Points to an array of starting indices in the enabled arrays.
    * @param count      Points to an array of the number of indices to be rendered.
    * @param prim_count  Specifies the size of the first and count
    * @see glMultiDrawArrays */
  static void MultiDrawArrays(PrimitiveType type,
                              const GLint *first,
                              const GLsizei *count,
                              GLsizei prim_count
  ) {
    gl(MultiDrawArrays(type, first, count, prim_count));
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glMultiDrawArraysIndirect)
  /// Render multiple sets of primitives from array data
  /** @param type        Specifies what kind of primitives to render.
    * @param indirect    Specifies the address of an array of structures containing the draw parameters.
    * @param draw_count  Specifies the the number of elements in the array of draw parameter structures.
    * @param stride      Specifies the distance in basic machine units between elements of the draw parameter array.
    * @see glMultiDrawArraysIndirect */
  static void MultiDrawArraysIndirect(PrimitiveType type,
                                      const void *indirect,
                                      GLsizei draw_count,
                                      GLsizei stride
  ) {
    gl(MultiDrawArraysIndirect(type, indirect, draw_count, stride));
  }
  #endif

  /// Draws a sequence of primitives from the bound element array buffers, in the order specified by the bound index buffer.
  /** @param type         Specifies what kind of primitives to render.
    * @param count        Specifies the number of elements to be rendered.
    * @param index_type   Specifies the type of the values in the index buffer.
    * @see glDrawElements */
  static void DrawElements(PrimitiveType type,
                           GLsizei count,
                           WholeDataType index_type
  ) {
    gl(DrawElements(type, count, index_type, nullptr));
  }

  template <typename GLtype>
  /// Draws a sequence of primitives from the bound element array buffers, in the order specified by the bound index buffer.
  /** @param type         Specifies what kind of primitives to render.
    * @param count        Specifies the number of elements to be rendered.
    * @param indices      Specifies the offset pointer in the index buffer.
    * @see glDrawElements */
  static void DrawElements(PrimitiveType type,
                           GLsizei count,
                           const GLtype* indices) {
    static_assert((sizeof(GLtype), false), "index type must be one of GLubyte, GLushort, or GLuint");
  }


  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstanced)
  /// Draws multiple instances of a sequence of primitives from the bound element array buffers, in the order specified by the bound index buffer.
  /** @param type         Specifies what kind of primitives to render.
    * @param count        Specifies the number of elements to be rendered.
    * @param index_type   Specifies the type of the values in the index buffer.
    * @param inst_count   Specifies the number of instances of the specified range of indices to be rendered.
    * @see glDrawElementsInstanced */
  static void DrawElementsInstanced(PrimitiveType type,
                                    GLsizei count,
                                    WholeDataType index_type,
                                    GLsizei inst_count
  ) {
    gl(DrawElementsInstanced(type, count, index_type, nullptr, inst_count));
  }

  template <typename GLtype>
  /// Draws multiple instances of a sequence of primitives from the bound element array buffers, in the order specified by the bound index buffer.
  /** @param type         Specifies what kind of primitives to render.
    * @param count        Specifies the number of elements to be rendered.
    * @param indices      Specifies the offset pointer in the index buffer.
    * @param inst_count   Specifies the number of instances of the specified range of indices to be rendered.
    * @see glDrawElementsInstanced */
  static void DrawElementsInstanced(PrimitiveType type,
                                    GLsizei count,
                                    const GLtype* indices,
                                    GLsizei inst_count
  ) {
    static_assert((sizeof(GLtype), false), "index type must be one of GLubyte, GLushort, or GLuint");
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstancedBaseInstance)
  /// Draws multiple instances of a sequence of primitives from the bound element array buffers, in the order specified by the bound index buffer.
  /** @param type           Specifies what kind of primitives to render.
    * @param count          Specifies the number of elements to be rendered.
    * @param index_type     Specifies the type of the values in the index buffer.
    * @param inst_count     Specifies the number of instances of the specified range of indices to be rendered.
    * @param base_instance  Specifies the base instance for use in fetching instanced vertex attributes.
    * @see glDrawElementsInstancedBaseInstance */
  static void DrawElementsInstancedBaseInstance(PrimitiveType type,
                                                GLsizei count,
                                                WholeDataType index_type,
                                                GLsizei inst_count,
                                                GLuint base_instance
  ) {
    gl(DrawElementsInstancedBaseInstance(type, count, index_type, nullptr, inst_count, base_instance));
  }

  template <typename GLtype>
  /// Draws multiple instances of a sequence of primitives from the bound element array buffers, in the order specified by the bound index buffer.
  /** @param type         Specifies what kind of primitives to render.
    * @param count        Specifies the number of elements to be rendered.
    * @param indices      Specifies the offset pointer in the index buffer.
    * @param inst_count   Specifies the number of instances of the specified range of indices to be rendered.
    * @param base_instace Specifies the base instance for use in fetching instanced vertex attributes.
    * @see glDrawElementsInstancedBaseInstance */
  static void DrawElementsInstancedBaseInstance(PrimitiveType type,
                                                GLsizei count,
                                                const GLtype* indices,
                                                GLsizei inst_count,
                                                GLuint base_instance
  ) {
    static_assert((sizeof(GLtype), false), "index type must be one of GLubyte, GLushort, or GLuint");
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glMultiDrawElements)
  template <typename GLtype>
  /// Draws multiple sets of sequences of primitives from the bound element array buffers, in the order specified by the bound index buffer.
  /** @param type         Specifies what kind of primitives to render.
    * @param count        Points to an array of the elements counts.
    * @param indices      Specifies a pointer to the location where the offset pointers to the index buffer are stored.
    * @param draw_count   Specifies the size of the count and indices arrays.
    * @see glMultiDrawElements */
  static void MultiDrawElements(PrimitiveType type,
                                const GLsizei* count,
                                const GLtype* const* indices,
                                GLsizei draw_count
  ) {
    static_assert((sizeof(GLtype), false), "index type must be one of GLubyte, GLushort, or GLuint");
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glPrimitiveRestartIndex)
  /// Sets the primitive restart index.
  /** @see glPrimitiveRestartIndex */
  static void PrimitiveRestartIndex(GLuint index) {
    gl(PrimitiveRestartIndex(index));
  }
  #endif
};


template<>
inline void Drawing::DrawElements<GLubyte>(PrimitiveType type, GLsizei count, const GLubyte* indices) {
  gl(DrawElements(type, count, DataType::UnsignedByte, indices));
}

template<>
inline void Drawing::DrawElements<GLushort>(PrimitiveType type, GLsizei count, const GLushort* indices) {
  gl(DrawElements(type, count, DataType::UnsignedShort, indices));
}

template<>
inline void Drawing::DrawElements<GLuint>(PrimitiveType type, GLsizei count, const GLuint* indices) {
  gl(DrawElements(type, count, DataType::UnsignedInt, indices));
}

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstanced)
template<>
inline void Drawing::DrawElementsInstanced<GLubyte>(PrimitiveType type, GLsizei count, const GLubyte* indices, GLsizei inst_count) {
  gl(DrawElementsInstanced(type, count, DataType::UnsignedByte, indices, inst_count));
}

template<>
inline void Drawing::DrawElementsInstanced<GLushort>(PrimitiveType type, GLsizei count, const GLushort* indices, GLsizei inst_count) {
  gl(DrawElementsInstanced(type, count, DataType::UnsignedShort, indices, inst_count));
}

template<>
inline void Drawing::DrawElementsInstanced<GLuint>(PrimitiveType type, GLsizei count, const GLuint* indices, GLsizei inst_count) {
  gl(DrawElementsInstanced(type, count, DataType::UnsignedInt, indices, inst_count));
}
#endif

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElementsInstancedBaseInstance)
template<>
inline void Drawing::DrawElementsInstancedBaseInstance<GLubyte>(PrimitiveType type, GLsizei count, const GLubyte* indices, GLsizei inst_count, GLuint base_instance) {
  gl(DrawElementsInstancedBaseInstance(type, count, DataType::UnsignedByte, indices, inst_count, base_instance));
}

template<>
inline void Drawing::DrawElementsInstancedBaseInstance<GLushort>(PrimitiveType type, GLsizei count, const GLushort* indices, GLsizei inst_count, GLuint base_instance) {
  gl(DrawElementsInstancedBaseInstance(type, count, DataType::UnsignedShort, indices, inst_count, base_instance));
}

template<>
inline void Drawing::DrawElementsInstancedBaseInstance<GLuint>(PrimitiveType type, GLsizei count, const GLuint* indices, GLsizei inst_count, GLuint base_instance) {
  gl(DrawElementsInstancedBaseInstance(type, count, DataType::UnsignedInt, indices, inst_count, base_instance));
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
inline void Drawing::MultiDrawElements<GLubyte>(PrimitiveType type, const GLsizei* count, const GLubyte* const* indices, GLsizei draw_count) {
  gl(MultiDrawElements(type, count, DataType::UnsignedByte, OGLWRAP_POINTER_HACKER(indices), draw_count));
}

template<>
inline void Drawing::MultiDrawElements<GLushort>(PrimitiveType type, const GLsizei* count, const GLushort* const* indices, GLsizei draw_count) {
  gl(MultiDrawElements(type, count, DataType::UnsignedShort, OGLWRAP_POINTER_HACKER(indices), draw_count));
}

template<>
inline void Drawing::MultiDrawElements<GLuint>(PrimitiveType type, const GLsizei* count, const GLuint* const* indices, GLsizei draw_count) {
  gl(MultiDrawElements(type, count, DataType::UnsignedInt, OGLWRAP_POINTER_HACKER(indices), draw_count));
}
#endif

}
}

#include "../undefine_internal_macros.hpp"
#endif
