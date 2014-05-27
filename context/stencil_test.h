// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_STENCIL_TEST_H_
#define OGLWRAP_CONTEXT_STENCIL_TEST_H_

#include "../config.h"
#include "../enums/face.h"
#include "../enums/compare_func.h"
#include "../enums/stencil_operation.h"
#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/**
 * @brief set front and back function and reference value for stencil testing
 *
 * Stenciling, like depth-buffering, enables and disables drawing on a
 * per-pixel basis. Stencil planes are first drawn into using GL drawing
 * primitives, then geometry and images are rendered using the stencil planes
 * to mask out portions of the screen. Stenciling is typically used in
 * multipass rendering algorithms to achieve special effects, such as decals,
 * outlining, and constructive solid geometry rendering.
 *
 * The stencil test conditionally eliminates a pixel based on the outcome of a
 * comparison between the reference value and the value in the stencil buffer.
 * To enable and disable the test, call Context::Enable​ and Context::Disable​
 * with argument Capability::StencilTest. To specify actions based on the
 * outcome of the stencil test, call glStencilOp​ or glStencilOpSeparate​.
 *
 * There can be two separate sets of func​, ref​, and mask​ parameters; one
 * affects back-facing polygons, and the other affects front-facing polygons
 * as well as other non-polygon primitives. glStencilFunc​ sets both front and
 * back stencil state to the same values. Use glStencilFuncSeparate​ to set
 * front and back stencil state to different values.
 *
 * func​ is a symbolic constant that determines the stencil comparison function.
 * It accepts one of eight values, shown in the following list. ref​ is an
 * integer reference value that is used in the stencil comparison. It is
 * clamped to the range [0, 2n - 1], where n is the number of bitplanes in the
 * stencil buffer. mask​ is bitwise ANDed with both the reference value and the
 * stored stencil value, with the ANDed values participating in the comparison.
 *
 * If stencil represents the value stored in the corresponding stencil buffer
 * location, the following list shows the effect of each comparison function
 * that can be specified by func​. Only if the comparison succeeds is the pixel
 * passed through to the next stage in the rasterization process
 * (see StencilOp​). All tests treat stencil values as unsigned integers in the
 * range [0, 2n - 1], where n is the number of bitplanes in the stencil buffer.
 *
 * The following values are accepted by func​:
 *
 * CompareFunc::Never​
 *   Always fails.
 * CompareFunc::Less
 *   Passes if ( ref​ & mask​ ) < ( stencil & mask​ ).
 * CompareFunc::LEqual​
 *   Passes if ( ref​ & mask​ ) <= ( stencil & mask​ ).
 * CompareFunc::Greater​
 *   Passes if ( ref​ & mask​ ) > ( stencil & mask​ ).
 * CompareFunc::GEqual
 *   Passes if ( ref​ & mask​ ) >= ( stencil & mask​ ).
 * CompareFunc::Equal
 *   Passes if ( ref​ & mask​ ) = ( stencil & mask​ ).
 * CompareFunc::NotEqual​
 *   Passes if ( ref​ & mask​ ) != ( stencil & mask​ ).
 * CompareFunc::Always
 *   Always passes.
 *
 * @param func Specifies the test function.
 * @param ref  Specifies the reference value for the stencil test. ref​ is
 *             clamped to the range [0, 2n - 1], where n is the number of
 *             bitplanes in the stencil buffer. The initial value is 0.
 * @param mask Specifies a mask that is ANDed with both the reference value
 *             and the stored stencil value when the test is done. The initial
 *             value is all 1's.
 * @see glStencilFunc
 * @version OpenGL 1.0
 */
inline void StencilFunc(CompareFunc func,
                        GLint ref=GLint(0),
                        GLuint mask=~GLuint(0)) {
  gl(StencilFunc(GLenum(func), ref, mask));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glStencilFuncSeparate)
/**
 * @brief set front and back function and reference value for stencil testing
 *
 * Stenciling, like depth-buffering, enables and disables drawing on a
 * per-pixel basis. Stencil planes are first drawn into using GL drawing
 * primitives, then geometry and images are rendered using the stencil planes
 * to mask out portions of the screen. Stenciling is typically used in
 * multipass rendering algorithms to achieve special effects, such as decals,
 * outlining, and constructive solid geometry rendering.
 *
 * The stencil test conditionally eliminates a pixel based on the outcome of a
 * comparison between the reference value and the value in the stencil buffer.
 * To enable and disable the test, call Context::Enable​ and Context::Disable​
 * with argument Capability::StencilTest. To specify actions based on the
 * outcome of the stencil test, call glStencilOp​ or glStencilOpSeparate​.
 *
 * There can be two separate sets of func​, ref​, and mask​ parameters; one
 * affects back-facing polygons, and the other affects front-facing polygons
 * as well as other non-polygon primitives. glStencilFunc​ sets both front and
 * back stencil state to the same values, as if glStencilFuncSeparate​ were
 * called with face​ set to Face::FrontAndBack.
 *
 * func​ is a symbolic constant that determines the stencil comparison function.
 * It accepts one of eight values, shown in the following list. ref​ is an
 * integer reference value that is used in the stencil comparison. It is
 * clamped to the range [0, 2n - 1], where n is the number of bitplanes in the
 * stencil buffer. mask​ is bitwise ANDed with both the reference value and the
 * stored stencil value, with the ANDed values participating in the comparison.
 *
 * If stencil represents the value stored in the corresponding stencil buffer
 * location, the following list shows the effect of each comparison function
 * that can be specified by func​. Only if the comparison succeeds is the pixel
 * passed through to the next stage in the rasterization process
 * (see StencilOp​). All tests treat stencil values as unsigned integers in the
 * range [0, 2n - 1], where n is the number of bitplanes in the stencil buffer.
 *
 * The following values are accepted by func​:
 *
 * CompareFunc::Never​
 *   Always fails.
 * CompareFunc::Less
 *   Passes if ( ref​ & mask​ ) < ( stencil & mask​ ).
 * CompareFunc::LEqual​
 *   Passes if ( ref​ & mask​ ) <= ( stencil & mask​ ).
 * CompareFunc::Greater​
 *   Passes if ( ref​ & mask​ ) > ( stencil & mask​ ).
 * CompareFunc::GEqual
 *   Passes if ( ref​ & mask​ ) >= ( stencil & mask​ ).
 * CompareFunc::Equal
 *   Passes if ( ref​ & mask​ ) = ( stencil & mask​ ).
 * CompareFunc::NotEqual​
 *   Passes if ( ref​ & mask​ ) != ( stencil & mask​ ).
 * CompareFunc::Always
 *   Always passes.
 *
 * @param face Specifies whether front and/or back stencil state is updated.
 * @param func Specifies the test function.
 * @param ref  Specifies the reference value for the stencil test. ref​ is
 *             clamped to the range [0, 2n - 1], where n is the number of
 *             bitplanes in the stencil buffer. The initial value is 0.
 * @param mask Specifies a mask that is ANDed with both the reference value
 *             and the stored stencil value when the test is done. The initial
 *             value is all 1's.
 * @see glStencilFuncSeparate
 * @version OpenGL 2.0
 */
inline void StencilFuncSeparate(Face face,
                                CompareFunc func,
                                GLint ref=GLint(0),
                                GLuint mask=~GLuint(0)) {
  gl(StencilFuncSeparate(GLenum(face), GLenum(func), ref, mask));
}
#endif

/**
 * @brief Set front and back stencil test actions.
 *
 * Stenciling, like depth-buffering, enables and disables drawing on a
 * per-pixel basis. You draw into the stencil planes using GL drawing
 * primitives, then render geometry and images, using the stencil planes to
 * mask out portions of the screen. Stenciling is typically used in multipass
 * rendering algorithms to achieve special effects, such as decals, outlining,
 * and constructive solid geometry rendering.
 *
 * The stencil test conditionally eliminates a pixel based on the outcome of a
 * comparison between the value in the stencil buffer and a reference value.
 * To enable and disable the test, call glEnable​ and glDisable​ with argument
 * GL_STENCIL_TEST​; to control it, call glStencilFunc​ or glStencilFuncSeparate​.
 *
 * There can be two separate sets of sfail​, dpfail​, and dppass​ parameters; one
 * affects back-facing polygons, and the other affects front-facing polygons
 * as well as other non-polygon primitives. glStencilOp​ sets both front and
 * back stencil state to the same values. Use glStencilOpSeparate​ to set front
 * and back stencil state to different values.
 *
 * glStencilOp takes three arguments that indicate what happens to the stored
 * stencil value while stenciling is enabled. If the stencil test fails, no
 * change is made to the pixel's color or depth buffers, and sfail​ specifies
 * what happens to the stencil buffer contents. The following eight actions
 * are possible.
 *
 * StencilOperation::Keep
 *   Keeps the current value.
 * StencilOperation::Zero
 *   Sets the stencil buffer value to 0.
 * StencilOperation::Replace
 *   Sets the stencil buffer value to ref, as specified by glStencilFunc​.
 * StencilOperation::Incr
 *   Increments the current stencil buffer value. Clamps to the maximum
 *   representable unsigned value.
 * StencilOperation::IncrWrap
 *   Increments the current stencil buffer value. Wraps stencil buffer value to
 *   zero when incrementing the maximum representable unsigned value.
 * StencilOperation::Decr
 *   Decrements the current stencil buffer value. Clamps to 0.
 * StencilOperation::DecrWrap
 *   Decrements the current stencil buffer value. Wraps stencil buffer value to
 *   the maximum representable unsigned value when decrementing a stencil buffer
 *   value of zero.
 * StencilOperation::Invert
 *   Bitwise inverts the current stencil buffer value.
 *
 * Stencil buffer values are treated as unsigned integers. When incremented
 * and decremented, values are clamped to 0 and 2n - 1, where n is the value
 * returned by querying GL_STENCIL_BITS​.
 *
 * The other two arguments to glStencilOp specify stencil buffer actions that
 * depend on whether subsequent depth buffer tests succeed (dppass​) or fail
 * (dpfail​) (see glDepthFunc​). The actions are specified using the same eight
 * symbolic constants as sfail​. Note that dpfail​ is ignored when there is no
 * depth buffer, or when the depth buffer is not enabled. In these cases,
 * sfail​ and dppass​ specify stencil action when the stencil test fails and
 * passes, respectively.
 *
 * @param sfail Specifies the action to take when the stencil test fails.
 * @param dfail Specifies the stencil action when the stencil test passes,
 *              but the depth test fails.
 * @param dpass Specifies the stencil action when both the stencil test and
 *              the depth test pass, or when the stencil test passes and
 *              either there is no depth buffer or depth testing is not enabled.
 */
inline void StencilOp(StencilOperation sfail = StencilOperation::kKeep,
                      StencilOperation dfail = StencilOperation::kKeep,
                      StencilOperation dpass = StencilOperation::kKeep) {
  gl(StencilOp(GLenum(sfail), GLenum(dfail), GLenum(dpass)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glStencilOpSeparate)
/**
 * @brief Set front and back stencil test actions.
 *
 * Stenciling, like depth-buffering, enables and disables drawing on a
 * per-pixel basis. You draw into the stencil planes using GL drawing
 * primitives, then render geometry and images, using the stencil planes to
 * mask out portions of the screen. Stenciling is typically used in multipass
 * rendering algorithms to achieve special effects, such as decals, outlining,
 * and constructive solid geometry rendering.
 *
 * The stencil test conditionally eliminates a pixel based on the outcome of a
 * comparison between the value in the stencil buffer and a reference value.
 * To enable and disable the test, call glEnable​ and glDisable​ with argument
 * GL_STENCIL_TEST​; to control it, call glStencilFunc​ or glStencilFuncSeparate​.
 *
 * There can be two separate sets of sfail​, dpfail​, and dppass​ parameters;
 * one affects back-facing polygons, and the other affects front-facing
 * polygons as well as other non-polygon primitives. glStencilOp​ sets both
 * front and back stencil state to the same values, as if glStencilOpSeparate​
 * were called with face​ set to GL_FRONT_AND_BACK​.
 *
 * glStencilOpSeparate takes three arguments that indicate what happens to the
 * stored stencil value while stenciling is enabled. If the stencil test
 * fails, no change is made to the pixel's color or depth buffers, and sfail​
 * specifies what happens to the stencil buffer contents. The following eight
 * actions are possible.
 *
 * StencilOperation::Keep
 *   Keeps the current value.
 * StencilOperation::Zero
 *   Sets the stencil buffer value to 0.
 * StencilOperation::Replace
 *   Sets the stencil buffer value to ref, as specified by glStencilFunc​.
 * StencilOperation::Incr
 *   Increments the current stencil buffer value. Clamps to the maximum
 *   representable unsigned value.
 * StencilOperation::IncrWrap
 *   Increments the current stencil buffer value. Wraps stencil buffer value to
 *   zero when incrementing the maximum representable unsigned value.
 * StencilOperation::Decr
 *   Decrements the current stencil buffer value. Clamps to 0.
 * StencilOperation::DecrWrap
 *   Decrements the current stencil buffer value. Wraps stencil buffer value to
 *   the maximum representable unsigned value when decrementing a stencil buffer
 *   value of zero.
 * StencilOperation::Invert
 *   Bitwise inverts the current stencil buffer value.
 *
 * Stencil buffer values are treated as unsigned integers. When incremented
 * and decremented, values are clamped to 0 and 2n - 1, where n is the value
 * returned by querying GL_STENCIL_BITS​.
 *
 * The other two arguments to glStencilOp specify stencil buffer actions that
 * depend on whether subsequent depth buffer tests succeed (dppass​) or fail
 * (dpfail​) (see glDepthFunc​). The actions are specified using the same eight
 * symbolic constants as sfail​. Note that dpfail​ is ignored when there is no
 * depth buffer, or when the depth buffer is not enabled. In these cases,
 * sfail​ and dppass​ specify stencil action when the stencil test fails and
 * passes, respectively.
 *
 * @param face
 * @param sfail Specifies the action to take when the stencil test fails.
 * @param dfail Specifies the stencil action when the stencil test passes,
 *              but the depth test fails.
 * @param dpass Specifies the stencil action when both the stencil test and
 *              the depth test pass, or when the stencil test passes and
 *              either there is no depth buffer or depth testing is not enabled.
 * @see glStencilOpSeparate
 * @version OpenGL 2.0
 */
inline void StencilOpSeparate(Face face,
                              StencilOperation sfail = StencilOperation::kKeep,
                              StencilOperation dfail = StencilOperation::kKeep,
                              StencilOperation dpass = StencilOperation::kKeep) {
  gl(StencilOpSeparate(GLenum(face), GLenum(sfail),
                       GLenum(dfail), GLenum(dpass)));
}
#endif

/**
 * @brief Returns the stencil function
 * @param backface Specifies if the the backface should be queried.
 * @see glGetIntegerv, GL_STENCIL_FUNC, GL_STENCIL_BACK_FUNC
 * @version OpenGL 1.0
 */
inline CompareFunc StencilFunc(bool backface = false) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_FUNC, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_FUNC, &data));
  }
  return static_cast<CompareFunc>(data);
}

/**
 * @brief Returns the value of stencil mask
 * @param backface Specifies if the the backface should be queried.
 * @see glGetIntegerv, GL_STENCIL_VALUE_MASK, GL_STENCIL_BACK_VALUE_MASK
 * @version OpenGL 1.0
 */
inline GLuint StencilValueMask(bool backface = true) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_VALUE_MASK, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_VALUE_MASK, &data));
  }
  return data;
}

/**
 * @brief Returns the stencil reference value.
 * @param backface Specifies if the the backface should be queried.
 * @see glGetIntegerv, GL_STENCIL_REF, GL_STENCIL_BACK_REF
 * @version OpenGL 1.0
 */
inline GLuint StencilRef(bool backface = false) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_REF, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_REF, &data));
  }
  return data;
}

/**
 * @brief Returns the stencil-fail action
 * @param backface Specifies if the the backface should be queried.
 * @see glGetIntegerv, GL_STENCIL_FAIL, GL_STENCIL_BACK_FAIL
 * @version OpenGL 1.0
 */
inline StencilOperation StencilFail(bool backface = false) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_FAIL, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_FAIL, &data));
  }
  return static_cast<StencilOperation>(data);
}

/**
 * @brief Returns the stencil-pass depth-fail action
 * @param backface Specifies if the the backface should be queried.
 * @see glGetIntegerv, GL_STENCIL_PASS_DEPTH_FAIL,
 *      GL_STENCIL_BACK_PASS_DEPTH_FAIL
 * @version OpenGL 1.0
 */
inline StencilOperation StencilPassDepthFail(bool backface = false) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_PASS_DEPTH_FAIL, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_PASS_DEPTH_FAIL, &data));
  }
  return static_cast<StencilOperation>(data);
}

/**
 * @brief Returns the stencil-pass depth-pass action
 * @param backface Specifies if the the backface should be queried.
 * @see glGetIntegerv, GL_STENCIL_PASS_DEPTH_PASS,
 *      GL_STENCIL_BACK_PASS_DEPTH_PASS
 * @version OpenGL 1.0
 */
inline StencilOperation StencilPassDepthPass(bool backface = false) {
  GLint data;
  if (backface) {
    gl(GetIntegerv(GL_STENCIL_PASS_DEPTH_PASS, &data));
  } else {
    gl(GetIntegerv(GL_STENCIL_BACK_PASS_DEPTH_PASS, &data));
  }
  return static_cast<StencilOperation>(data);
}

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
