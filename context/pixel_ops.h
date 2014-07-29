// Copyright (c) 2014, Tamas Csala

/** @file pixel_ops.h
    @brief Implements OpenGL pixel operations related stuff.
*/

#ifndef OGLWRAP_CONTEXT_PIXEL_OPS_H_
#define OGLWRAP_CONTEXT_PIXEL_OPS_H_

#include "../config.h"
#include "../enums/blit_filter.h"
#include "../enums/pixel_data_type.h"
#include "../enums/pixel_data_format.h"
#include "../enums/pixel_storage_mode.h"
#include "../enums/buffer_select_bit.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/**
 * @brief set pixel storage modes
 * @param parameter Specifies the symbolic name of the parameter to be set.
 * @param value     Specifies the value that pname​ is set to.
 * @see <a href="https://www.opengl.org/wiki/GLAPI/glPixelStore">glPixelStoref</a>
 * @version OpenGL 1.0
 */
inline void PixelStore(PixelStorageMode parameter, GLfloat value) {
  gl(PixelStoref(GLenum(parameter), value));
}

/**
 * @brief set pixel storage modes
 * @param parameter Specifies the symbolic name of the parameter to be set.
 * @param value     Specifies the value that pname​ is set to.
 * @see <a href="https://www.opengl.org/wiki/GLAPI/glPixelStore">glPixelStorei</a>
 * @version OpenGL 1.0
 */
inline void PixelStore(PixelStorageMode parameter, GLint value) {
  gl(PixelStorei(GLenum(parameter), value));
}

/**
 * read a block of pixels from the frame buffer
 * @see <a href="https://www.opengl.org/wiki/GLAPI/glReadPixels">glReadPixels</a>
 * @version OpenGL 1.0
 */
inline void ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height,
                       PixelDataFormat format, PixelDataType type, void* data) {
  gl(ReadPixels(x, y, width, height, GLenum(format), GLenum(type), data));
}

/**
 * read a block of pixels from the frame buffer
 * @see <a href="https://www.opengl.org/wiki/GLAPI/glBlitFramebuffer">
 *      glBlitFramebuffer</a>
 * @version OpenGL 3.0
 */
inline void BlitFramebuffer(GLint srcX0, GLint srcX1, GLint srcY0, GLint srcY1,
                            GLint dstX0, GLint dstX1, GLint dstY0, GLint dstY1,
                            Bitfield<BufferSelectBit> mask, BlitFilter filter) {
  gl(BlitFramebuffer(
    srcX0, srcX1, srcY0, srcY1, dstX0, dstX1, dstY0, dstY1, mask, GLenum(filter)
  ));
}

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
