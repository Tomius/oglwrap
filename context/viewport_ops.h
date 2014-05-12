// Copyright (c) 2014, Tamas Csala

/** @file viewport_ops.h
    @brief Implements OpenGL viewports related stuff.
*/

#ifndef OGLWRAP_CONTEXT_VIEWPORTOPS_H_
#define OGLWRAP_CONTEXT_VIEWPORTOPS_H_

#include "../glm/glm/glm.hpp"

#include "../config.h"
#include "../enums.h"
#include "../define_internal_macros.h"


namespace oglwrap {
namespace context {

class ViewportOps {
public:
	/// Sets the extents of the current viewport.
	/** @see glViewport */
	static void Viewport(GLint x, GLint y, GLsizei w, GLsizei h) {
		gl(Viewport(x, y, w, h));
	}

	/// Sets the size of the current viewport starting at (0,0)
	/** @see glViewport */
	static void Viewport(GLsizei w, GLsizei h) {
		gl(Viewport(0, 0, w, h));
	}

	#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VIEWPORT)
	/// Returns the extents of the current viewport.
	/** @see glGetIntegerv, GL_VIEWPORT */
	static glm::ivec4 Viewport() {
		GLint data[4];
		gl(GetIntegerv(GL_VIEWPORT, data));
		return glm::ivec4(data[0], data[1], data[2], data[3]);
	}
	#endif

	#if OGLWRAP_DEFINE_EVERYTHING || defined(glViewportIndexedf)
	/// Sets the extents of the specified viewport.
	/** @see glViewportIndexedf */
	static void Viewport(GLuint viewport, GLfloat x, GLfloat y, GLfloat w, GLfloat h) {
		gl(ViewportIndexedf(viewport, x, y, w, h));
	}
	#endif

	#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VIEWPORT)
	/// Returns the extents of the specified viewport.
	/** @see glGetIntegerv, GL_VIEWPORT */
	static glm::ivec4 Viewport(GLint viewport) {
		GLint data[4];
		gl(GetIntegeri_v(GL_VIEWPORT, viewport, data));
		return glm::ivec4(data[0], data[1], data[2], data[3]);
	}
	#endif

	#if OGLWRAP_DEFINE_EVERYTHING || defined(glDepthRangef)
	/// Sets the depth range of the current viewport.
	/** @see glDepthRangef */
	static void DepthRange(GLclampf near_z, GLclampf far_z) {
		gl(DepthRangef(near_z, far_z));
	}
	#endif

	#if OGLWRAP_DEFINE_EVERYTHING || defined(glDepthRange)
	/// Sets the depth range of the current viewport.
	/** @see glDepthRange */
	static void DepthRange(GLclampd near_z, GLclampd far_z) {
		gl(DepthRange(near_z, far_z));
	}
	#endif

	#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_RANGE)
	/// Returns the depth range of the current viewport.
	/** @see glDepthRange */
	static glm::dvec2 DepthRange() {
		GLdouble data[2];
		gl(GetDoublev(GL_DEPTH_RANGE, data));
		return glm::dvec2(data[0], data[1]);
	}
	#endif

	#if OGLWRAP_DEFINE_EVERYTHING || defined(glDepthRangeIndexed)
	/// Sets the depth range of the specified viewport.
	/** @see glDepthRangeIndexed */
	static void DepthRange(GLint viewport, GLclampd near_z, GLclampd far_z) {
		gl(DepthRangeIndexed(viewport, near_z, far_z));
	}
	#endif

	#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_RANGE)
	/// Returns the depth range of the specified viewport.
	/** @see glDepthRange */
	static glm::dvec2 DepthRange(GLint viewport) {
		GLdouble data[2];
		gl(GetDoublei_v(GL_DEPTH_RANGE, viewport, data));
		return glm::dvec2(data[0], data[1]);
	}
	#endif
};

}
}
#include "../undefine_internal_macros.h"
#endif
