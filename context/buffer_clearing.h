// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_BUFFER_CLEARING_H_
#define OGLWRAP_CONTEXT_BUFFER_CLEARING_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "../config.h"
#include "../enums/buffer_select_bit.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/// Specify clear values for the color buffers.
/** @see glClearColor */
inline void ClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	gl(ClearColor(r, g, b, a));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_CLEAR_VALUE)
/// Returns the clear values for the color buffers.
/** @see glGetFloatv, GL_COLOR_CLEAR_VALUE */
inline glm::vec4 GetClearColor() {
	GLfloat data[4];
	gl(GetFloatv(GL_COLOR_CLEAR_VALUE, data));
	return glm::vec4(data[0], data[1], data[2], data[3]);
}
#endif

/// Specify the clear value for the depth buffers.
/** @see glClearDepth */
inline void ClearDepth(GLdouble d) {
	gl(ClearDepth(d));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_CLEAR_VALUE)
/// Returns the clear value for the depth buffers.
/** @see glGetDoublev, GL_DEPTH_CLEAR_VALUE */
inline double GetClearDepth() {
	GLdouble data;
	gl(GetDoublev(GL_DEPTH_CLEAR_VALUE, &data));
	return data;
}
#endif

/// Specify the clear value for the stencil buffers.
/** @see glClearStencil */
inline void ClearStencil(GLuint mask) {
	gl(ClearStencil(mask));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_CLEAR_VALUE)
/// Returns the clear value for the stencil buffers.
/** @see GetIntegerv, GL_STENCIL_CLEAR_VALUE */
inline GLuint GetClearStencil() {
	GLuint data;
	gl(GetIntegerv(GL_STENCIL_CLEAR_VALUE, reinterpret_cast<GLint*>(&data)));
	return data;
}
#endif

/// Clears buffers in its destructor, depending on which functions were called on it.
/** @see glClear */
class ClearBuffers {
	Bitfield<BufferSelectBit> buffers;
public:
	ClearBuffers& Color() {
		buffers |= BufferSelectBit::kColorBufferBit;
		return *this;
	}
	ClearBuffers& Depth() {
		buffers |= BufferSelectBit::kDepthBufferBit;
		return *this;
	}
	ClearBuffers& Stencil() {
		buffers |= BufferSelectBit::kStencilBufferBit;
		return *this;
	}
	~ClearBuffers() {
		if (buffers != 0) {
			gl(Clear(buffers));
		}
	}
};

/// Clears buffers specified by calling functions of the returned object.
/** @see glClear */
inline ClearBuffers Clear() {
	return ClearBuffers();
}

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
