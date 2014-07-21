// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_SCISSOR_TEST_H_
#define OGLWRAP_CONTEXT_SCISSOR_TEST_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "../config.h"
#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/**
 * @brief define the scissor box.
 *
 * glScissor defines a rectangle, called the scissor box, in window coordinates.
 *
 * To enable and disable the scissor test, call glEnable​ and glDisable​ with
 * argument GL_SCISSOR_TEST​. The test is initially disabled. While the test is
 * enabled, only pixels that lie within the scissor box can be modified by
 * drawing commands. Window coordinates have integer values at the shared
 * corners of frame buffer pixels. glScissor(0,0,1,1)​ allows modification of
 * only the lower left pixel in the window, and glScissor(0,0,0,0)​ doesn't
 * allow modification of any pixels in the window.
 *
 * When the scissor test is disabled, it is as though the scissor box includes
 * the entire window.
 *
 * @param left, bottom  Specify the lower left corner of the scissor box.
 *                      Initially (0, 0).
 * @param width, height Specify the width and height of the scissor box.
 *                      When a GL context is first attached to a window, width​
 *                      and height​ are set to the dimensions of that window.
 * @see glScissor
 * @version OpenGL 1.1
 */
inline void Scissor(GLint left, GLint bottom, GLsizei width, GLsizei height) {
  gl(Scissor(left, bottom, width, height));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glScissorIndexed)
/**
 * @brief define the scissor box for a specific viewport
 *
 * glScissorIndexed defines the scissor box for a specified viewport. index​
 * specifies the index of scissor box to modify. index​ must be less than the
 * value of GL_MAX_VIEWPORTS​. Left​, bottom​, width​ and height​ specify the left,
 * bottom, width and height of the scissor box, in pixels, respectively.
 *
 * To enable and disable the scissor test, call glEnable​ and glDisable​ with
 * argument GL_SCISSOR_TEST​. The test is initially disabled for all viewports.
 * While the test is enabled, only pixels that lie within the scissor box can
 * be modified by drawing commands. Window coordinates have integer values at
 * the shared corners of frame buffer pixels. glScissor(0,0,1,1)​ allows
 * modification of only the lower left pixel in the window, and
 * glScissor(0,0,0,0)​ doesn't allow modification of any pixels in the window.
 *
 * When the scissor test is disabled, it is as though the scissor box includes
 * the entire window.
 *
 * @param index  Specifies the index of the viewport whose scissor box to modify.
 * @param left, bottom Specify the coordinate of the bottom left corner of the
 *                     scissor box, in pixels.
 * @param width, height
 * @see glScissorIndexed
 * @version OpenGL 4.1
 */
inline void Scissor(GLuint viewport, GLint left, GLint bottom,
                    GLsizei width, GLsizei height) {
  gl(ScissorIndexed(viewport, left, bottom, width, height));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glScissorIndexedv)
  /**
 * @brief define the scissor box for a specific viewport
 *
 * glScissorIndexed defines the scissor box for a specified viewport. index​
 * specifies the index of scissor box to modify. index​ must be less than the
 * value of GL_MAX_VIEWPORTS​. v​ specifies the address of an
 * array containing integers specifying the lower left corner of the scissor
 * box, and the width and height of the scissor box, in that order.
 *
 * To enable and disable the scissor test, call glEnable​ and glDisable​ with
 * argument GL_SCISSOR_TEST​. The test is initially disabled for all viewports.
 * While the test is enabled, only pixels that lie within the scissor box can
 * be modified by drawing commands. Window coordinates have integer values at
 * the shared corners of frame buffer pixels. glScissor(0,0,1,1)​ allows
 * modification of only the lower left pixel in the window, and
 * glScissor(0,0,0,0)​ doesn't allow modification of any pixels in the window.
 *
 * When the scissor test is disabled, it is as though the scissor box includes
 * the entire window.
 *
 * @param index  Specifies the index of the viewport whose scissor box to modify.
 * @param v      For glScissorIndexedv, specifies the address of an array
 *               containing the left, bottom, width and height of each scissor
 *               box, in that order.
 * @see glScissorIndexedv
 * @version OpenGL 4.1
 */
inline void Scissor(GLuint viewport, GLint *v) {
  gl(ScissorIndexedv(viewport, v));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glScissorArrayv)
/**
 * @brief define the scissor box for multiple viewports
 *
 * glScissorArrayv defines rectangles, called scissor boxes, in window
 * coordinates for each viewport. first​ specifies the index of the first
 * scissor box to modify and count​ specifies the number of scissor boxes to
 * modify. first​ must be less than the value of GL_MAX_VIEWPORTS​, and
 * first​ + count​ must be less than or equal to the value of GL_MAX_VIEWPORTS​.
 * v​ specifies the address of an array containing integers specifying the
 * lower left corner of the scissor boxes, and the width and height of the
 * scissor boxes, in that order.
 *
 * To enable and disable the scissor test, call glEnable​ and glDisable​ with
 * argument GL_SCISSOR_TEST​. The test is initially disabled for all viewports.
 * While the test is enabled, only pixels that lie within the scissor box can
 * be modified by drawing commands. Window coordinates have integer values at
 * the shared corners of frame buffer pixels. glScissor(0,0,1,1)​ allows
 * modification of only the lower left pixel in the window, and
 * glScissor(0,0,0,0)​ doesn't allow modification of any pixels in the window.
 *
 * When the scissor test is disabled, it is as though the scissor box includes
 * the entire window.
 *
 * @param first   Specifies the index of the first viewport whose scissor box
 *                to modify.
 * @param count   Specifies the number of scissor boxes to modify.
 * @param v       Specifies the address of an array containing the left,
 *                bottom, width and height of each scissor box, in that order.
 * @see glScissorArrayv
 * @version OpenGL 4.1
 */
inline void ScissorArray(GLuint first, GLuint count, GLint *v) {
  gl(ScissorArrayv(first, count, v));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_BOX)
/**
 * Returns the extents of scissor box of the default viewport.
 * @see glGetIntegerv, GL_SCISSOR_BOX
 * @version OpenGL 1.1
 */
inline glm::ivec4 ScissorBox() {
  GLint data[4];
  gl(GetIntegerv(GL_SCISSOR_BOX, data));
  return glm::ivec4{data[0], data[1], data[2], data[3]};
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING \
    || defined(GL_SCISSOR_BOX) && defined(glScissorIndexed)
/**
 * Returns the extents of scissor box of the specified viewport.
 * @see glGetIntegeri_v, GL_SCISSOR_BOX
 * @version OpenGL 4.1
 */
inline glm::ivec4 ScissorBox(GLuint viewport) {
  GLint data[4];
  gl(GetIntegeri_v(GL_SCISSOR_BOX, viewport, data));
  return glm::ivec4{data[0], data[1], data[2], data[3]};
}
#endif

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
