// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_DEPTH_TEST_H_
#define OGLWRAP_CONTEXT_DEPTH_TEST_H_

#include "../config.h"
#include "../enums/compare_func.h"
#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/**
 * @brief Specify the function used for depth buffer comparisons
 *
 * glDepthFunc specifies the function used to compare each incoming pixel
 * depth value with the depth value present in the depth buffer. The
 * comparison is performed only if depth testing is enabled. (See glEnable​ and
 *  glDisable​ of GL_DEPTH_TEST​.)
 *
 * func​tion specifies the conditions under which the pixel will be drawn. The
 * comparison functions are as follows:
 *
 * CompareFunction::Never​
 *   Never passes.
 * CompareFunction::Less
 *   Passes if the incoming depth value is less than the stored depth value.
 * CompareFunction::Equal
 *   Passes if the incoming depth value is equal to the stored depth value.
 * CompareFunction::LEqual​
 *   Passes if the incoming depth value is less than or equal to the stored
 *   depth value.
 * CompareFunction::Greater​
 *   Passes if the incoming depth value is greater than the stored depth value.
 * CompareFunction::NotEqual​
 *   Passes if the incoming depth value is not equal to the stored depth value.
 * CompareFunction::GEqual
 *   Passes if the incoming depth value is greater than or equal to the stored
 *   depth value.
 * CompareFunction::Always
 *   Always passes.
 *
 * The initial value of func​tion is CompareFunction::Less. Initially, depth
 * testing is disabled. If depth testing is disabled or if no depth buffer
 * exists, it is as if the depth test always passes.
 *
 * Notes: Even if the depth buffer exists and the depth mask is non-zero, the
 * depth buffer is not updated if the depth test is disabled. In order to
 * unconditionally write to the depth buffer, the depth test should be enabled
 * and set to CompareFunction::Always.
 *
 * @param function Specifies the depth comparison function.
 * @see glDepthFunc
 * @version OpenGL 1.0
 */
inline void DepthFunc(CompareFunc function) {
  gl(DepthFunc(GLenum(function)));
}

/**
 * @brief Returns the function currently used for depth buffer comparisons.
 * @see glGetIntegerv, GL_DEPTH_FUNC
 * @version OpenGL 1.0
 */
inline CompareFunc DepthFunc() {
  GLint data;
  gl(GetIntegerv(GL_DEPTH_FUNC, &data));
  return static_cast<CompareFunc>(data);
}

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
