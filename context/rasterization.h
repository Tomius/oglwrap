// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_RASTERIZATION_H_
#define OGLWRAP_CONTEXT_RASTERIZATION_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "../config.h"
#include "../enums/face.h"
#include "../enums/face_orientation.h"
#include "../enums/poly_mode.h"
#include "../enums/provoke_mode.h"
#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/// Define front- and back-facing polygons.
/** @see glFrontFace */
inline void FrontFace(FaceOrientation orintation) {
	gl(FrontFace(GLenum(orintation)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_FACE)
/// Returns the orientation of the front facing polygons.
/** @see GetIntegerv, GL_FRONT_FACE */
inline FaceOrientation FrontFace() {
	GLint data;
	gl(GetIntegerv(GL_FRONT_FACE, &data));
	return static_cast<FaceOrientation>(data);
}
#endif

/// Specify whether front- or back-facing facets can be culled.
/** @see glCullFace */
inline void CullFace(Face face) {
	gl(CullFace(GLenum(face)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CULL_FACE_MODE)
/// Returns whether front- or back-facing facets can be culled.
/** @see GetIntegerv, GL_CULL_FACE_MODE */
inline Face CullFace() {
	GLint data;
	gl(GetIntegerv(GL_CULL_FACE_MODE, &data));
	return static_cast<Face>(data);
}
#endif

/// Sets the polygon rasterization mode.
/** @see glPolygonMode */
inline void PolygonMode(Face face, PolyMode mode) {
	gl(PolygonMode(GLenum(face), GLenum(mode)));
}

/// Sets the polygon rasterization mode.
/** @see glPolygonMode */
inline void PolygonMode(PolyMode mode) {
	gl(PolygonMode(GLenum(Face::kFrontAndBack), GLenum(mode)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_MODE)
/// Returns the polygon rasterization mode.
/** @see GetIntegerv, GL_POLYGON_MODE */
inline PolyMode PolygonMode() {
	GLint data;
	gl(GetIntegerv(GL_POLYGON_MODE, &data));
	return static_cast<PolyMode>(data);
}
#endif

/// Sets the scale and units used to calculate depth values.
/** @see glPolygonOffset */
inline void PolygonOffset(GLfloat factor, GLfloat units) {
	gl(PolygonOffset(factor, units));
}

#if OGLWRAP_DEFINE_EVERYTHING \
		|| defined(GL_POLYGON_OFFSET_FACTOR) && defined(GL_POLYGON_OFFSET_UNITS)
/// Returns the scale and units used to calculate depth values.
/** @see GetFloatv, GL_POLYGON_OFFSET_FACTOR, GL_POLYGON_OFFSET_UNITS */
inline glm::vec2 PolygonOffset() {
	glm::vec2 data;
	gl(GetFloatv(GL_POLYGON_OFFSET_FACTOR, &data.x));
	gl(GetFloatv(GL_POLYGON_OFFSET_UNITS, &data.y));
	return data;
}
#endif

/// Sets the width of rasterized lines.
/** @see glLineWidth */
inline void LineWidth(GLfloat width) {
	gl(LineWidth(width));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_WIDTH)
/// Returns the width of rasterized lines.
/** @see glGetFloatv, GL_LINE_WIDTH */
inline GLfloat LineWidth() {
	GLfloat data;
	gl(GetFloatv(GL_LINE_WIDTH, &data));
	return data;
}
#endif

/// Specify the diameter of rasterized points.
/** @see glPointSize */
inline void PointSize(GLfloat diameter) {
	gl(PointSize(diameter));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT_SIZE)
/// Returns the diameter of rasterized points.
/** @see glGetFloatv, GL_POINT_SIZE */
inline GLfloat PointSize() {
	GLfloat data;
	gl(GetFloatv(GL_POINT_SIZE, &data));
	return data;
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING \
	|| defined(glPointParameterf) && defined(GL_POINT_FADE_THRESHOLD_SIZE)
/// Specifies the threshold value to which point sizes are clamped if they exceed the specified value.
/** @see glPointParameterf GL_POINT_FADE_THRESHOLD_SIZE */
inline void PointFadeThresholdSize(GLfloat width) {
	gl(PointParameterf(GL_POINT_FADE_THRESHOLD_SIZE, width));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT_FADE_THRESHOLD_SIZE)
/// Returns the threshold value to which point sizes are clamped if they exceed the specified value.
/** @see glGetFloatv, GL_POINT_FADE_THRESHOLD_SIZE */
inline GLfloat PointFadeThresholdSize() {
	GLfloat data;
	gl(GetFloatv(GL_POINT_FADE_THRESHOLD_SIZE, &data));
	return data;
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glProvokingVertex)
/// Specify the vertex to be used as the source of data for flat shaded varyings.
/** @see glProvokingVertex */
inline void ProvokingVertex(ProvokeMode mode) {
	gl(ProvokingVertex(GLenum(mode)));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PROVOKING_VERTEX)
/// Returns the vertex to be used as the source of data for flat shaded varyings.
/** @see glGetIntegerv, GL_PROVOKING_VERTEX */
inline ProvokeMode ProvokingVertex() {
	GLint data;
	gl(GetIntegerv(GL_PROVOKING_VERTEX, &data));
	return static_cast<ProvokeMode>(data);
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_BUFFERS)
/// Returns an integer value indicating the number of sample buffers associated with the framebuffer.
/** @see glGetIntegerv, GL_SAMPLE_BUFFERS */
inline GLint SampleBuffersNumber() {
	GLint data;
	gl(GetIntegerv(GL_SAMPLE_BUFFERS, &data));
	return data;
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLES)
/// Returns an integer value indicating the coverage mask size.
/** @see glGetIntegerv, GL_SAMPLES */
inline GLint SamplesNumber() {
	GLint data;
	gl(GetIntegerv(GL_SAMPLES, &data));
	return data;
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING \
	|| defined(glGetMultisample) && defined(GL_SAMPLE_POSITION)
/// Returns the location of a sample.
/** @see glGetMultisample, GL_SAMPLE_POSITION */
inline glm::vec2 SamplePosition(GLuint index) {
	GLfloat data[2];
	gl(GetMultisample(GL_SAMPLE_POSITION, index, data));
	return glm::vec2(data[0], data[1]);
}
#endif

/// Specifies the minimum rate at which sample sharing takes place
inline void MinSampleShading(GLfloat value) {
	gl(MinSampleShading(value));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN_SAMPLE_SHADING)
/// Returns the minimum rate at which sample sharing takes place.
/** @see glGetFloatv, GL_MIN_SAMPLE_SHADING */
inline GLfloat MinSampleShading() {
	GLfloat data;
	gl(glGetFloatv(GL_MIN_SAMPLE_SHADING, &data));
	return data;
}
#endif

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
