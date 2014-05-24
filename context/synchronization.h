// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_SYNCHRONIZATION_H_
#define OGLWRAP_CONTEXT_SYNCHRONIZATION_H_

#include "../config.h"
#include "../general.h"
#include "../enums/memory_barrier_bit.h"

#include "../define_internal_macros.h"

namespace oglwrap {
namespace context {

class Synchronization {
public:
  #if OGLWRAP_DEFINE_EVERYTHING || defined(glMemoryBarrier)
  /**
   * @brief Defines a barrier for memory transactions.
   *
   * @see glMemoryBarrier
   * @version OpenGL 4.2
   */
  static void MemoryBarrier(Bitfield<MemoryBarrierBit> bits) {
    gl(MemoryBarrier(bits));
  }
  #endif

  /**
   * @brief Indicate that all previous GL commands must finish in finite time.
   *
   * @see glFlush
   * @version OpenGL 1.0
   */
  static void Flush() {
    gl(Flush());
  }

  /**
   * @brief Force all previous GL commands to complete before returning.
   *
   * @see glFinish
   * @version OpenGL 1.0
   */
  static void Finish() {
    gl(Finish());
  }

};
}
}

#include "../undefine_internal_macros.h"

#endif
