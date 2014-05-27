// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_COMPUTING_H_
#define OGLWRAP_CONTEXT_COMPUTING_H_

#include "../config.h"
#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDispatchCompute)
/**
 * @brief Launch one or more compute work groups.
 *
 * glDispatchCompute launches one or more compute work groups. Each work group
 * is processed by the active program object for the compute shader stage.
 * While the individual shader invocations within a work group are executed as
 * a unit, work groups are executed completely independently and in unspecified
 * order. num_groups_x, num_groups_y and num_groups_z specify the number of
 * local work groups that will be dispatched in the X, Y and Z dimensions,
 * respectively.
 *
 * @param num_groups_x The number of work groups to be launched in the X dimension.
 * @param num_groups_y The number of work groups to be launched in the Y dimension.
 * @param num_groups_z The number of work groups to be launched in the Z dimension.
 * @see glDispatchCompute
 * @version OpenGL 4.3
 */
inline void DispatchCompute(GLuint num_groups_x,
                            GLuint num_groups_y,
                            GLuint num_groups_z) {
  gl(DispatchCompute(num_groups_x, num_groups_y, num_groups_z));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDispatchComputeIndirect)
/**
 * @brief launch one or more compute work groups using parameters stored in a
 *        buffer
 *
 * glDispatchComputeIndirect launches one or more compute work groups using
 * parameters stored in the buffer object currently bound to the
 * GL_DISPATCH_INDIRECT_BUFFER​ target. Each work group is processed by the
 * active program object for the compute shader stage. While the individual
 * shader invocations within a work group are executed as a unit, work groups
 * are executed completely independently and in unspecified order. indirect​
 * contains the offset into the data store of the buffer object bound to the
 * GL_DISPATCH_INDIRECT_BUFFER​ target at which the parameters are stored.
 *
 * The parameters addressed by indirect​ are packed a structure, which takes
 * the form (in C):
 *
 * typedef  struct {
 *     uint  num_groups_x;
 *     uint  num_groups_y;
 *     uint  num_groups_z;
 * } DispatchIndirectCommand;
 * A call to glDispatchComputeIndirect is equivalent, assuming no errors are
 * generated, to:
 *
 * cmd = (const DispatchIndirectCommand  *)indirect;
 * glDispatchComputeIndirect(cmd->num_groups_x, cmd->num_groups_y, cmd->num_groups_z);
 *
 * Unlike glDispatchCompute​, no error is generated if any of the num_groups_x​,
 * num_groups_y​ or num_groups_z​ members of the DispatchIndirectCommand​ is
 * larger than the value of GL_MAX_COMPUTE_WORK_GROUP_COUNT​ for the
 * corresponding dimension. In such circumstances, behavior is undefined and
 * may lead to application termination.
 *
 * @param indirect The offset into the buffer object currently bound to the
 *                 GL_DISPATCH_INDIRECT_BUFFER​ buffer target at which the
 *                 dispatch parameters are stored.
 * @see glDispatchComputeIndirect
 * @version OpenGL 4.3
 */
inline void DispatchComputeIndirect(GLintptr indirect) {
  gl(DispatchComputeIndirect(indirect));
}
#endif

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
