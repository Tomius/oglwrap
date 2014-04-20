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
  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawArrays)
  /// Draws count of primitives from the bound array buffer.
  /** @param type    Specifies what kind of primitives to render.
    * @param first   Specifies the starting index in the enabled arrays.
    * @param count   Specifies the number of indices to be rendered.
    * @see glDrawArrays */
  static void DrawArrays(PrimitiveType type, GLint first, GLsizei count) {
    gl(DrawArrays(type, first, count));
  }
  #endif

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
    * @param drawcount   Specifies the the number of elements in the array of draw parameter structures.
    * @param stride      Specifies the distance in basic machine units between elements of the draw parameter array.
    * @see glMultiDrawArraysIndirect */
  static void MultiDrawArraysIndirect(PrimitiveType type,
                                      const void *indirect,
                                      GLsizei drawcount,
                                      GLsizei stride
  ) {
    gl(MultiDrawArraysIndirect(type, indirect, drawcount, stride));
  }
  #endif

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElements)
  /// Draws a sequence of primitives from the bound element array buffers, in the order specified by the bound index buffer.
  /** @param type         Specifies what kind of primitives to render.
    * @param count        Specifies the number of elements to be rendered.
    * @param index_type   Specifies the type of the values in the index buffer.
    * @see glDrawElements */
  static void DrawElements(PrimitiveType type, GLsizei count, WholeDataType index_type) {
    gl(DrawElements(type, count, index_type, nullptr));
  }
  #endif

  template <typename GLtype>
  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElements)
  /// Draws a sequence of primitives from the bound element array buffers, in the order specified by the bound index buffer.
  /** @param type         Specifies what kind of primitives to render.
    * @param count        Specifies the number of elements to be rendered.
    * @param index_type   Specifies the type of the values in the index buffer.
    * @see glDrawElements */
  static void DrawElements(PrimitiveType type, GLsizei count, const GLtype* indices) {
    throw std::invalid_argument("index_type must be one of GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, or GL_UNSIGNED_INT");
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


#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawElements)
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
#endif

}
}

#include "../undefine_internal_macros.hpp"
#endif
