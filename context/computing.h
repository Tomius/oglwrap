// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_COMPUTING_H_
#define OGLWRAP_CONTEXT_COMPUTING_H_

#include "../config.h"
#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDispatchCompute)
inline void DispatchCompute(GLuint num_groups_x,
                            GLuint num_groups_y,
                            GLuint num_groups_z) {
  gl(DispatchCompute(num_groups_x, num_groups_y, num_groups_z));
}
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDispatchComputeIndirect)
inline void DispatchComputeIndirect(GLintptr indirect) {
  gl(DispatchComputeIndirect(indirect));
}
#endif

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
