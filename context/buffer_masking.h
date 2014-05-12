// Copyright (c) 2014, Tamas Csala

/** @file buffer_masking.h
    @brief Implements OpenGL buffer masking related stuff.
*/

#ifndef OGLWRAP_CONTEXT_BUFFER_MASKING_H_
#define OGLWRAP_CONTEXT_BUFFER_MASKING_H_

#include <tuple>
#include "../config.h"
#include "../enums.h"
#include "../enums/face.h"
#include "../define_internal_macros.h"


namespace oglwrap {
namespace context {

class BufferMasking {
public:
/// Enables and disables writing of frame buffer color components.
	/** @see glColorMask */
	static void ColorMask(bool r, bool g, bool b, bool a) {
		gl(ColorMask(r, g, b, a));
	}

	#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_WRITEMASK)
	/// Returns the color mask.
	/** @see glGetBooleanv, GL_COLOR_WRITEMASK */
	static std::tuple<bool, bool, bool, bool> ColorMask() {
		GLboolean data[4];
		gl(GetBooleanv(GL_COLOR_WRITEMASK, data));
		return std::tuple<bool, bool, bool, bool>(
							data[0], data[1], data[2], data[3]);
	}
	#endif

	#if OGLWRAP_DEFINE_EVERYTHING || defined(glColorMaski)
	/// Enables and disables writing of frame buffer color components for a particular buffer.
	/** @see glColorMaski */
	static void ColorMask(GLuint buffer, bool r, bool g, bool b, bool a) {
		gl(ColorMaski(buffer, r, g, b, a));
	}
	#endif

	/// Enables or disables writing into the depth buffer.
	/** @see glDepthMask */
	static void DepthMask(bool mask) {
		gl(DepthMask(mask));
	}

	#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_WRITEMASK)
	/// Returns the depth mask.
	/** @see glGetBooleanv, GL_DEPTH_WRITEMASK */
	static bool DepthMask() {
		GLboolean data;
		gl(GetBooleanv(GL_DEPTH_WRITEMASK, &data));
		return data;
	}
	#endif

	/// Controls the front and back writing of individual bits in the stencil planes.
	/** @see glStencilMask */
	static void StencilMask(GLuint mask) {
		gl(StencilMask(mask));
	}

	#if OGLWRAP_DEFINE_EVERYTHING || defined(glStencilMaskSeparate)
	/// Control the front and/or back writing of individual bits in the stencil planes.
	/** @see glStencilMaskSeparate */
	static void StencilMask(Face face, GLuint mask) {
		gl(StencilMaskSeparate(GLenum(face), mask));
	}
	#endif

	#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_WRITEMASK) && defined(GL_STENCIL_BACK_WRITEMASK)
	/// Returns the value of stencil write mask for the specified face.
	/** @see glGetIntegerv, GL_STENCIL_WRITEMASK, GL_STENCIL_BACK_WRITEMASK */
	static GLuint StencilMask(bool front_face = true) {
		GLuint data;
		if (front_face) {
			glGetIntegerv(GL_STENCIL_WRITEMASK, reinterpret_cast<GLint*>(&data));
		} else {
			glGetIntegerv(GL_STENCIL_BACK_WRITEMASK, reinterpret_cast<GLint*>(&data));
		}
		return data;
	}
	#endif
};

}
}
#include "../undefine_internal_macros.h"
#endif
