// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_SYNCHRONIZATION_H_
#define OGLWRAP_CONTEXT_SYNCHRONIZATION_H_

#include "../config.h"
#include "../bitfield.h"
#include "../enums/memory_barrier_bit.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMemoryBarrier)
inline void MemoryBarrier(Bitfield<MemoryBarrierBit> bits) {
  gl(MemoryBarrier(bits));
}
#endif

inline void Flush() {
  gl(Flush());
}

inline void Finish() {
  gl(Finish());
}

} // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif
