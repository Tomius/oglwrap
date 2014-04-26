/** @file logical_ops.hpp
    @brief Implements OpenGL logical operation related stuff.
*/

#ifndef OGLWRAP_CONTEXT_LOGICAL_OPS_HPP_
#define OGLWRAP_CONTEXT_LOGICAL_OPS_HPP_

#include "../config.hpp"
#include "../enums.hpp"
#include "../define_internal_macros.hpp"

namespace oglwrap {
namespace context {

/// Wrapper for the color buffer logical operations.
class LogicalOps {

  /**
   * @brief specify a logical pixel operation for rendering
   *
   * glLogicOp specifies a logical operation that, when enabled, is applied
   * between the incoming RGBA color and the RGBA color at the corresponding
   * location in the frame buffer. To enable or disable the logical operation,
   * call Context::Enable​ and Context::Disable​ using the Capability::ColorLogicOp.
   * The initial value is disabled.
   *
   * Opcode       Resulting Operation
   * ================================
   * Clear         |    0
   * Set           |    1
   * Copy          |    s
   * CopyInverted  |    ~s
   * Noop          |    d
   * Invert        |    ~d
   * And           |    s & d
   * Nand          |    ~(s & d)
   * Or            |    s | d
   * Nor           |    ~(s | d)
   * Xor           |    s ^ d
   * Equiv         |    ~(s ^ d)
   * AndReverse    |    s & ~d
   * AndInverted   |    ~s & d
   * OrReverse     |    s | ~d
   * OrInverted​    |    ~s | d
   * =================================
   *
   * opcode​ is a symbolic constant chosen from the list above. In the explanation
   * of the logical operations, s represents the incoming color and d represents
   * the color in the frame buffer. Standard C-language operators are used. As
   * these bitwise operators suggest, the logical operation is applied
   * independently to each bit pair of the source and destination colors.
   *
   * @param op Specifies a symbolic constant that selects a logical operation.
   * @see <a href="https://www.opengl.org/wiki/GLAPI/glLogicOp">glLogicOp</a>
   * @version OpenGL 1.0
   */
  static void LogicOp(ColorLogicOperation op) {
    gl(LogicOp(op));
  }

  #if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_LOGIC_OP)
  /**
   * @brief Returns the color logical operation.
   * @see <a href="https://www.opengl.org/wiki/GLAPI/glGet">
   *      glGetIntegerv, GL_COLOR_LOGIC_OP</a>
   * @version OpenGL 1.0
   */
  static ColorLogicOperation LogicOp() {
    GLint data;
    gl(GetIntegerv(GL_COLOR_LOGIC_OP, &data));
    return static_cast<ColorLogicOperation>(data);
  }
  #endif
};

}
}

#include "../undefine_internal_macros.hpp"
#endif
