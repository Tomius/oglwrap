// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_BLENDING_H_
#define OGLWRAP_CONTEXT_BLENDING_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "../config.h"
#include "../enums/blend_equation.h"
#include "../enums/blend_function.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/**
 * @brief set the RGB blend equation for the RGBA components.
 *
 * @param eq specifies how source and destination colors are combined.
 * @see glBlendEquation
 * @version 1.0
 */
inline void BlendEquation(enums::BlendEquation eq) {
  gl(BlendEquation(GLenum(eq)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBlendEquationi)
/**
 * @brief set the blend equation for the RGBA components.
 *
 * @param buffer specifies the index of the draw buffer for which to set the
 *               blend equation.
 * @param eq     specifies how source and destination colors are combined.
 * @see glBlendEquationi
 * @version 4.0
 */
inline void BlendEquation(GLuint buffer, enums::BlendEquation eq) {
  gl(BlendEquationi(buffer, GLenum(eq)));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBlendEquationSeparate)
/**
 * @brief set the RGB blend equation and the alpha blend equation separately.
 *
 * @param mode_rgb  specifies the RGB blend equation, how the red, green, and
 *                  blue components of the source and destination colors are
 *                  combined.
 * @param mode_a    specifies the alpha blend equation, how the alpha component
 *                  of the source and destination colors are combined.
 * @see glBlendEquationSeparate
 * @version 2.0
 */
inline void BlendEquationSeparate(enums::BlendEquation mode_rgb,
                                 enums::BlendEquation mode_a) {
  gl(BlendEquationSeparate(GLenum(mode_rgb), GLenum(mode_a)));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBlendEquationSeparatei)
/**
 * @brief set the RGB blend equation and the alpha blend equation separately.
 *
 * @param buffer    specifies the index of the draw buffer for which to set the
 *                  blend equation.
 * @param mode_rgb  specifies the RGB blend equation, how the red, green, and
 *                  blue components of the source and destination colors are
 *                  combined.
 * @param mode_a    specifies the alpha blend equation, how the alpha component
 *                  of the source and destination colors are combined.
 * @see glBlendEquationSeparatei
 * @version 4.0
 */
inline void BlendEquationSeparate(GLuint buffer, enums::BlendEquation mode_rgb,
                                 enums::BlendEquation mode_a) {
  gl(BlendEquationSeparatei(buffer, GLenum(mode_rgb), GLenum(mode_a)));
}
#endif

/**
 * @see glBlendFunc
 * @version 1.0
 */
inline void BlendFunc(enums::BlendFunction src, enums::BlendFunction dst) {
  gl(BlendFunc(GLenum(src), GLenum(dst)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBlendFunci)
/**
 * @see glBlendFunci
 * @version 4.0
 */
inline void BlendFunc(GLuint buffer, enums::BlendFunction src,
                     enums::BlendFunction dst) {
  gl(BlendFunci(buffer, GLenum(src), GLenum(dst)));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBlendFuncSeparatei)
/**
 * @see glBlendFuncSeparate
 * @version 1.4
 */
inline void BlendFuncSeparate(enums::BlendFunction src_rgb,
                              enums::BlendFunction dst_rgb,
                              enums::BlendFunction src_a,
                              enums::BlendFunction dst_a) {
  gl(BlendFuncSeparate(GLenum(src_rgb), GLenum(dst_rgb),
                       GLenum(src_a), GLenum(dst_a)));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glBlendFuncSeparatei)
/**
 * @see glBlendFuncSeparatei
 * @version 4.0
 */
inline void BlendFuncSeparate(GLuint buffer,
                              enums::BlendFunction src_rgb,
                              enums::BlendFunction dst_rgb,
                              enums::BlendFunction src_a,
                              enums::BlendFunction dst_a) {
  gl(BlendFuncSeparatei(buffer, GLenum(src_rgb), GLenum(dst_rgb),
                        GLenum(src_a), GLenum(dst_a)));
}
#endif

/**
 * @see glBlendColor
 * @version 1.0
 */
inline void BlendColor(glm::vec4 blend_color) {
  gl(BlendColor(blend_color.r, blend_color.g, blend_color.b, blend_color.a));
}

/**
 * @see glBlendColor
 * @version 1.0
 */
inline void BlendColor(GLfloat red, GLfloat green,
                       GLfloat blue, GLfloat alpha) {
  gl(BlendColor(red, green, blue, alpha));
}

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
