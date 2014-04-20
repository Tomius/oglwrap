/** @file context.hpp
    @brief Implements OpenGL context related stuff.
*/

#ifndef OGLWRAP_CONTEXT_CAPABILITIES_HPP_
#define OGLWRAP_CONTEXT_CAPABILITIES_HPP_

#include "glm/glm/glm.hpp"

#include "config.hpp"
#include "enums.hpp"
#include "debug/error.hpp"
#include "define_internal_macros.hpp"

namespace oglwrap {
/// This is actually a namespace with only static functions.
/// But dis was, the compilers don't cry for unused functions
class Context {

public:

	// -------======{[ Capabilities ]}======-------

	/// Enables a capability.
	/** @see glEnable */
	static void Enable(Capability capability) {
		gl(Enable(capability));
	}

	/// Enables a capability.
	/** @see glEnable */
	void operator()(Capability capability) const {
		Enable(capability);
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glEnablei)
	/// Enables a capability for an index target.
	/** @see glEnablei */
	static void Enable(Capability capability, GLuint index) {
		gl(Enablei(capability, index));
	}

	/// Enables a capability for an index target.
	/** @see glEnablei */
	void operator()(Capability capability, GLuint index) const {
		Enable(capability, index);
	}
	#endif

	/// Disables a capability.
	/** @see glDisable */
	static void Disable(Capability capability) {
		gl(Disable(capability));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDisablei)
	/// Disables a capability for an index target.
	/** @see glDisablei */
	static void Disable(Capability capability, GLuint index) {
		gl(Disablei(capability, index));
	}
	#endif

	/// Checks if a capability is enabled.
	/** @see glIsEnabled */
	static bool IsEnabled(Capability capability) {
		return gl(IsEnabled(capability));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glIsEnabledi)
	/// Checks if a capability is enabled for an index target.
	/** @see glIsEnabledi */
	static bool IsEnabled(Capability capability, GLuint index) {
		return gl(IsEnabledi(capability, index));
	}
	#endif

	/// Enables or disables a capability.
	/** @see glEnable, glDisable */
	static void SetCapability(Capability capability, bool value) {
		if(value) {
			Enable(capability);
		} else {
			Disable(capability);
		}
	}

	/// Enables or disables a capability.
	/** @see glEnable, glDisable */
	void operator()(Capability capability, bool value) const {
		SetCapability(capability, value);
	}

	/// Enables or disables a capability for an indexet target.
	/** @see glEnable, glDisable */
	static void SetCapability(Capability capability, GLuint index, bool value) {
		if(value) {
			Enable(capability, index);
		} else {
			Disable(capability, index);
		}
	}

	/// Enables or disables a capability for an indexet target.
	/** @see glEnable, glDisable */
	void operator()(Capability capability, GLuint index, bool value) const {
		SetCapability(capability, index, value);
	}

	/// Enables a capability, and creates a variable. When the variable goes
	/// out of the scope, sets the capability back to its old value.
	class TemporaryEnable {
		Capability cap_;
		bool was_enabled_;

	public:
		TemporaryEnable(Capability capability) : cap_(capability) {
			was_enabled_ = IsEnabled(cap_);
			if(!was_enabled_) {
				Enable(cap_);
			}
		}

		~TemporaryEnable() {
			if(!was_enabled_) {
				Disable(cap_);
			}
		}
	};

	/// Disables a capability, and creates a variable. When the variable goes
	/// out of the scope, sets the capability back to its old value.
	class TemporaryDisable {
		Capability cap_;
		bool was_enabled_;

	public:
		TemporaryDisable(Capability capability) : cap_(capability) {
			was_enabled_ = IsEnabled(cap_);
			if(was_enabled_) {
				Disable(cap_);
			}
		}

		~TemporaryDisable() {
			if(was_enabled_) {
				Enable(cap_);
			}
		}
	};

	/// Temporary sets a list of Capabilities to the specified value.
	/// When the created variable goes out of scope, these variables are set back
	/// to their old values.
	class TemporarySet {
		std::vector<std::pair<Capability, bool>> cap_;

	public:
		TemporarySet(std::vector<std::pair<Capability, bool>> capabilites) {
			for(auto i : capabilites) {
				bool current_state = IsEnabled(i.first);
				if(i.second != current_state) {
					cap_.push_back({i.first, i.second});
					if(current_state) {
						Disable(i.first);
					} else {
						Enable(i.first);
					}
				}
			}
		}

		~TemporarySet() {
			for(auto i : cap_) {
				if(i.second) {
					Disable(i.first);
				} else {
					Enable(i.first);
				}
			}
		}
	};


	// -------======{[ Errors ]}======-------

	/// Returns the last OpenGL error.
	/** @see glGetError */
	static GLError GetError() {
		return static_cast<GLError>(glGetError());
	}


	// -------======{[ Viewports ]}======-------

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

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_VIEWPORT)
	/// Returns the extents of the current viewport.
	/** @see glGetIntegerv, GL_VIEWPORT */
	static glm::ivec4 Viewport() {
		GLint data[4];
		gl(GetIntegerv(GL_VIEWPORT, data));
		return glm::ivec4(data[0], data[1], data[2], data[3]);
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glViewportIndexedf)
	/// Sets the extents of the specified viewport.
	/** @see glViewportIndexedf */
	static void Viewport(GLuint viewport, GLfloat x, GLfloat y, GLfloat w, GLfloat h) {
		gl(ViewportIndexedf(viewport, x, y, w, h));
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_VIEWPORT)
	/// Returns the extents of the specified viewport.
	/** @see glGetIntegerv, GL_VIEWPORT */
	static glm::ivec4 Viewport(GLint viewport) {
		GLint data[4];
		gl(GetIntegeri_v(GL_VIEWPORT, viewport, data));
		return glm::ivec4(data[0], data[1], data[2], data[3]);
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDepthRangef)
	/// Sets the depth range of the current viewport.
	/** @see glDepthRangef */
	static void DepthRange(GLclampf near_z, GLclampf far_z) {
		gl(DepthRangef(near_z, far_z));
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDepthRange)
	/// Sets the depth range of the current viewport.
	/** @see glDepthRange */
	static void DepthRange(GLclampd near_z, GLclampd far_z) {
		gl(DepthRange(near_z, far_z));
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DEPTH_RANGE)
	/// Returns the depth range of the current viewport.
	/** @see glDepthRange */
	static glm::dvec2 DepthRange() {
		GLdouble data[2];
		gl(GetDoublev(GL_DEPTH_RANGE, data));
		return glm::dvec2(data[0], data[1]);
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDepthRangeIndexed)
	/// Sets the depth range of the specified viewport.
	/** @see glDepthRangeIndexed */
	static void DepthRange(GLint viewport, GLclampd near_z, GLclampd far_z) {
		gl(DepthRangeIndexed(viewport, near_z, far_z));
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DEPTH_RANGE)
	/// Returns the depth range of the specified viewport.
	/** @see glDepthRange */
	static glm::dvec2 DepthRange(GLint viewport) {
		GLdouble data[2];
		gl(GetDoublei_v(GL_DEPTH_RANGE, viewport, data));
		return glm::dvec2(data[0], data[1]);
	}
	#endif

	// -------======{[ Buffer Selection ]}======-------

	/// Sets the destination color buffer for draw operations.
	/** @see glDrawBuffer */
	static void DrawBuffer(ColorBuffer buffer) {
		gl(DrawBuffer(buffer));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DRAW_BUFFER)
	/// Returns the destination color buffer for draw operations.
	/** @see glGetIntegerv, GL_DRAW_BUFFER */
	static ColorBuffer DrawBuffer() {
		GLint data;
		gl(GetIntegerv(GL_DRAW_BUFFER, &data));
		return static_cast<ColorBuffer>(data);
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glDrawBuffers)
	/// Sets the destination color buffer for draw operations.
	/** @see glDrawBuffers */
	static void DrawBuffers(std::vector<ColorBuffer> buffers) {
		gl(DrawBuffers(buffers.size(), reinterpret_cast<const GLenum*>(buffers.data())));
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DRAW_BUFFER)
	/// Returns the destination color buffer of the specified index for draw operations.
	/** @see glGetIntegerv, GL_DRAW_BUFFER */
	static ColorBuffer DrawBuffers(int idx) {
		GLint data;
		gl(GetIntegerv(GL_DRAW_BUFFER+idx, &data));
		return static_cast<ColorBuffer>(data);
	}
	#endif

	/// Sets the source color buffer for read operations.
	/** @see glReadBuffer */
	static void ReadBuffer(ColorBuffer buffer) {
		gl(ReadBuffer(buffer));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_READ_BUFFER)
	/// Returns the source color buffer for draw operations.
	/** @see glGetIntegerv, GL_DRAW_BUFFER */
	static ColorBuffer ReadBuffer() {
		GLint data;
		gl(GetIntegerv(GL_READ_BUFFER, &data));
		return static_cast<ColorBuffer>(data);
	}
	#endif

	// -------======{[ Buffer Masking ]}======-------

	/// Enables and disables writing of frame buffer color components.
	/** @see glColorMask */
	static void ColorMask(bool r, bool g, bool b, bool a) {
		gl(ColorMask(r, g, b, a));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_WRITEMASK)
	/// Returns the color mask.
	/** @see glGetBooleanv, GL_COLOR_WRITEMASK */
	static std::tuple<bool, bool, bool, bool> ColorMask() {
		GLboolean data[4];
		gl(GetBooleanv(GL_COLOR_WRITEMASK, data));
		return std::tuple<bool, bool, bool, bool>(data[0], data[1], data[2], data[3]);
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glColorMaski)
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

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DEPTH_WRITEMASK)
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

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glStencilMaskSeparate)
	/// Control the front and/or back writing of individual bits in the stencil planes.
	/** @see glStencilMaskSeparate */
	static void StencilMask(Face face, GLuint mask) {
		gl(StencilMaskSeparate(face, mask));
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_STENCIL_WRITEMASK) && defined(GL_STENCIL_BACK_WRITEMASK)
	/// Returns the value of stencil write mask for the specified face.
	/** @see glGetIntegerv, GL_STENCIL_WRITEMASK, GL_STENCIL_BACK_WRITEMASK */
	static GLuint StencilMask(bool front_face = true) {
		GLuint data;
		if(front_face) {
			glGetIntegerv(GL_STENCIL_WRITEMASK, reinterpret_cast<GLint*>(&data));
		} else {
			glGetIntegerv(GL_STENCIL_BACK_WRITEMASK, reinterpret_cast<GLint*>(&data));
		}
		return data;
	}
	#endif

	// -------======{[ Clearing Buffers ]}======-------

	/// Specify clear values for the color buffers.
	/** @see glClearColor */
	static void ClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
		gl(ClearColor(r, g, b, a));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_CLEAR_VALUE)
	/// Returns the clear values for the color buffers.
	/** @see glGetFloatv, GL_COLOR_CLEAR_VALUE */
	static glm::vec4 GetClearColor() {
		GLfloat data[4];
		gl(GetFloatv(GL_COLOR_CLEAR_VALUE, data));
		return glm::vec4(data[0], data[1], data[2], data[3]);
	}
	#endif

	/// Specify the clear value for the depth buffers.
	/** @see glClearDepth */
	static void ClearDepth(GLdouble d) {
		gl(ClearDepth(d));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DEPTH_CLEAR_VALUE)
	/// Returns the clear value for the depth buffers.
	/** @see glGetDoublev, GL_DEPTH_CLEAR_VALUE */
	static double GetClearDepth() {
		GLdouble data;
		gl(GetDoublev(GL_DEPTH_CLEAR_VALUE, &data));
		return data;
	}
	#endif

	/// Specify the clear value for the stencil buffers.
	/** @see glClearStencil */
	static void ClearStencil(GLuint mask) {
		gl(ClearStencil(mask));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_STENCIL_CLEAR_VALUE)
	/// Returns the clear value for the stencil buffers.
	/** @see GetIntegerv, GL_STENCIL_CLEAR_VALUE */
	static GLuint GetClearStencil() {
		GLuint data;
		gl(GetIntegerv(GL_STENCIL_CLEAR_VALUE, reinterpret_cast<GLint*>(&data)));
		return data;
	}
	#endif

	/// Clears buffers in its destructor, depending on which functions
	/// were called on it.
	/** @see glClear */
	class ClearBuffers {
		GLuint buffers = 0;
	public:
		ClearBuffers& Color() {
			buffers |= GL_COLOR_BUFFER_BIT;
			return *this;
		}
		ClearBuffers& Depth() {
			buffers |= GL_DEPTH_BUFFER_BIT;
			return *this;
		}
		ClearBuffers& Stencil() {
			buffers |= GL_STENCIL_BUFFER_BIT;
			return *this;
		}
		~ClearBuffers() {
			if(buffers != 0) {
				gl(Clear(buffers));
			}
		}
	};

	/// Clears buffers specified by calling functions of the returned object.
	/** @see glClear */
	static ClearBuffers Clear() {
		return ClearBuffers();
	}

	// -------======{[ Rasterization ]}======-------

	/// Define front- and back-facing polygons.
	/** @see glFrontFace */
	static void FrontFace(FaceOrientation orintation) {
		gl(FrontFace(orintation));
	}

	/// Define front- and back-facing polygons.
	/** @see glFrontFace */
	void operator()(FaceOrientation orintation) const {
		FrontFace(orintation);
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRONT_FACE)
	/// Returns the orientation of the front facing polygons.
	/** @see GetIntegerv, GL_FRONT_FACE */
	static FaceOrientation FrontFace() {
		GLint data;
		gl(GetIntegerv(GL_FRONT_FACE, &data));
		return static_cast<FaceOrientation>(data);
	}
	#endif

	/// Specify whether front- or back-facing facets can be culled.
	/** @see glCullFace */
	static void CullFace(Face face) {
		gl(CullFace(face));
	}

	/// Specify whether front- or back-facing facets can be culled.
	/** @see glCullFace */
	void operator()(Face face) const {
		CullFace(face);
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_CULL_FACE_MODE)
	/// Returns whether front- or back-facing facets can be culled.
	/** @see GetIntegerv, GL_CULL_FACE_MODE */
	static Face CullFace() {
		GLint data;
		gl(GetIntegerv(GL_CULL_FACE_MODE, &data));
		return static_cast<Face>(data);
	}
	#endif

	/// Sets the polygon rasterization mode.
	/** @see glPolygonMode */
	static void PolygonMode(Face face, PolyMode mode) {
		gl(PolygonMode(face, mode));
	}

	/// Sets the polygon rasterization mode.
	/** @see glPolygonMode */
	void operator()(Face face, PolyMode mode) const {
		PolygonMode(face, mode);
	}

	/// Sets the polygon rasterization mode.
	/** @see glPolygonMode */
	static void PolygonMode(PolyMode mode) {
		gl(PolygonMode(Face::FrontAndBack, mode));
	}

	/// Sets the polygon rasterization mode.
	/** @see glPolygonMode */
	void operator()(PolyMode mode) const {
		PolygonMode(mode);
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_POLYGON_MODE)
	/// Returns the polygon rasterization mode.
	/** @see GetIntegerv, GL_POLYGON_MODE */
	static PolyMode PolygonMode() {
		GLint data;
		gl(GetIntegerv(GL_POLYGON_MODE, &data));
		return static_cast<PolyMode>(data);
	}
	#endif

	/// Sets the scale and units used to calculate depth values.
	/** @see glPolygonOffset */
	static void PolygonOffset(GLfloat factor, GLfloat units) {
		gl(PolygonOffset(factor, units));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_POLYGON_OFFSET_FACTOR) && defined(GL_POLYGON_OFFSET_UNITS)
	/// Returns the scale and units used to calculate depth values.
	/** @see GetFloatv, GL_POLYGON_OFFSET_FACTOR, GL_POLYGON_OFFSET_UNITS */
	static glm::vec2 PolygonOffset() {
		glm::vec2 data;
		gl(GetFloatv(GL_POLYGON_OFFSET_FACTOR, &data.x));
		gl(GetFloatv(GL_POLYGON_OFFSET_UNITS, &data.y));
		return data;
	}
	#endif

	/// Sets the width of rasterized lines.
	/** @see glLineWidth */
	static void LineWidth(GLfloat width) {
		gl(LineWidth(width));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_LINE_WIDTH)
	/// Returns the width of rasterized lines.
	/** @see glGetFloatv, GL_LINE_WIDTH */
	static GLfloat LineWidth() {
		GLfloat data;
		gl(GetFloatv(GL_LINE_WIDTH, &data));
		return data;
	}
	#endif

	/// Specify the diameter of rasterized points.
	/** @see glPointSize */
	static void PointSize(GLfloat diameter) {
		gl(PointSize(diameter));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_POINT_SIZE)
	/// Returns the diameter of rasterized points.
	/** @see glGetFloatv, GL_POINT_SIZE */
	static GLfloat PointSize() {
		GLfloat data;
		gl(GetFloatv(GL_POINT_SIZE, &data));
		return data;
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glPointParameterf) && defined(GL_POINT_FADE_THRESHOLD_SIZE)
	/// Specifies the threshold value to which point sizes are clamped if they exceed the specified value.
	/** @see glPointParameterf GL_POINT_FADE_THRESHOLD_SIZE */
	static void PointFadeThresholdSize(GLfloat width) {
		gl(PointParameterf(GL_POINT_FADE_THRESHOLD_SIZE, width));
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_POINT_FADE_THRESHOLD_SIZE)
	/// Returns the threshold value to which point sizes are clamped if they exceed the specified value.
	/** @see glGetFloatv, GL_POINT_FADE_THRESHOLD_SIZE */
	static GLfloat PointFadeThresholdSize() {
		GLfloat data;
		gl(GetFloatv(GL_POINT_FADE_THRESHOLD_SIZE, &data));
		return data;
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glProvokingVertex)
	/// Specify the vertex to be used as the source of data for flat shaded varyings.
	/** @see glProvokingVertex */
	static void ProvokingVertex(ProvokeMode mode) {
		gl(ProvokingVertex(mode));
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_PROVOKING_VERTEX)
	/// Returns the vertex to be used as the source of data for flat shaded varyings.
	/** @see glGetIntegerv, GL_PROVOKING_VERTEX */
	static ProvokeMode ProvokingVertex() {
		GLint data;
		gl(GetIntegerv(GL_PROVOKING_VERTEX, &data));
		return static_cast<ProvokeMode>(data);
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SAMPLE_BUFFERS)
	/// Returns an integer value indicating the number of sample buffers associated with the framebuffer.
	/** @see glGetIntegerv, GL_SAMPLE_BUFFERS */
	static GLint SampleBuffersNumber() {
		GLint data;
		gl(GetIntegerv(GL_SAMPLE_BUFFERS, &data));
		return data;
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SAMPLES)
	/// Returns an integer value indicating the coverage mask size.
	/** @see glGetIntegerv, GL_SAMPLES */
	static GLint SamplesNumber() {
		GLint data;
		gl(GetIntegerv(GL_SAMPLES, &data));
		return data;
	}
	#endif

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glGetMultisample) && defined(GL_SAMPLE_POSITION)
	/// Returns the location of a sample.
	/** @see glGetMultisample, GL_SAMPLE_POSITION */
	static glm::vec2 SamplePosition(GLuint index) {
		GLfloat data[2];
		gl(GetMultisample(GL_SAMPLE_POSITION, index, data));
		return glm::vec2(data[0], data[1]);
	}
	#endif

	/// Specifies the minimum rate at which sample sharing takes place
	static void MinSampleShading(GLfloat value) {
		gl(MinSampleShading(value));
	}

	#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_MIN_SAMPLE_SHADING)
	/// Returns the minimum rate at which sample sharing takes place.
	/** @see glGetFloatv, GL_MIN_SAMPLE_SHADING */
	static GLfloat MinSampleShading() {
		GLfloat data;
		gl(glGetFloatv(GL_MIN_SAMPLE_SHADING, &data));
		return data;
	}
	#endif

};
}

#include "undefine_internal_macros.hpp"

#endif // OGLWRAP_CONTEXT_CAPABILITIES_HPP_
