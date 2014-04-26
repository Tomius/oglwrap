/** @file pixel_ops.hpp
    @brief Implements OpenGL pixel operations related stuff.
*/

#ifndef OGLWRAP_CONTEXT_PIXEL_OPS_HPP_
#define OGLWRAP_CONTEXT_PIXEL_OPS_HPP_

#include "../config.hpp"
#include "../enums.hpp"
#include "../general.hpp"
#include "../define_internal_macros.hpp"

namespace oglwrap {
namespace context {

/// Wrapper for the pixel storage and transfer operations
class PixelOps {
public:
  /**
   * @brief set pixel storage modes
   * @param parameter Specifies the symbolic name of the parameter to be set.
   * @param value     Specifies the value that pname​ is set to.
   * @see <a href="https://www.opengl.org/wiki/GLAPI/glPixelStore">glPixelStoref</a>
   * @version OpenGL 1.0
   */
  static void PixelStore(PixelStorageMode parameter, GLfloat value) {
    gl(PixelStoref(parameter, value));
  }

  /**
   * @brief set pixel storage modes
   * @param parameter Specifies the symbolic name of the parameter to be set.
   * @param value     Specifies the value that pname​ is set to.
   * @see <a href="https://www.opengl.org/wiki/GLAPI/glPixelStore">glPixelStorei</a>
   * @version OpenGL 1.0
   */
  static void PixelStore(PixelStorageMode parameter, GLint value) {
    gl(PixelStorei(parameter, value));
  }

  /**
   * read a block of pixels from the frame buffer
   * @see <a href="https://www.opengl.org/wiki/GLAPI/glReadPixels">glReadPixels</a>
   * @version OpenGL 1.0
   */
  static void ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height,
                         PixelDataFormat format, PixelDataType type, void* data) {
    gl(ReadPixels(x, y, width, height, format, type, data));
  }

  /**
   * read a block of pixels from the frame buffer
   * @see <a href="https://www.opengl.org/wiki/GLAPI/glBlitFramebuffer">
   *      glBlitFramebuffer</a>
   * @version OpenGL 3.0
   */
  static void BlitFramebuffer(GLint srcX0, GLint srcX1, GLint srcY0, GLint srcY1,
                              GLint dstX0, GLint dstX1, GLint dstY0, GLint dstY1,
                              Bitfield<BufferSelectBit> mask, BlitFilter filter) {
    gl(BlitFramebuffer(
      srcX0, srcX1, srcY0, srcY1, dstX0, dstX1, dstY0, dstY1, mask, filter
    ));
  }
};

}
}

#include "../undefine_internal_macros.hpp"
#endif
