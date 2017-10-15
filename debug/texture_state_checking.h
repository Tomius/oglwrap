// Copyright (c) Tamas Csala

/** @file texture_state_checking.h
    @brief Implements functions that check for consistent bindless texture usage
*/

#ifndef OGLWRAP_TEXTURE_STATE_CHECKING_H_
#define OGLWRAP_TEXTURE_STATE_CHECKING_H_

#include "./error_checking.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_BINDCHECK

#define OGLWRAP_CHECK_BINDLESS_TEXTURE_MODIFIED(bindless_handle) \
  if (bindless_handle != 0) { \
    OGLWRAP_print_bindless_texture_modified(__FILE__, OGLWRAP_FUNCTION_MACRO, __LINE__);  \
  }

#define OGLWRAP_CHECK_TEXTURE_ALREADY_BINDLESS(bindless_handle) \
  if (bindless_handle != 0) { \
    OGLWRAP_texture_already_bindless(__FILE__, OGLWRAP_FUNCTION_MACRO, __LINE__);  \
  }

#define OGLWRAP_CHECK_NON_BINDLESS_TEXTURE_RESIDENCY_CHANGE(bindless_handle) \
  if (bindless_handle == 0) { \
    OGLWRAP_non_bindless_texture_residency_change(__FILE__, OGLWRAP_FUNCTION_MACRO, __LINE__);  \
    makeBindless(); \
  }

inline void OGLWRAP_print_bindless_texture_modified(const char *file,
                                                    const char *func,
                                                    int line) {
  DebugOutput::PrintError(
    ErrorMessage {
      "BINDLESS TEXTURE MODIFIED",
      "Textures marked as bindless are immutable and none of their state can be changed\n\n",
      file, func, line
    }
  );
}

inline void OGLWRAP_texture_already_bindless(const char *file,
                                             const char *func,
                                             int line) {
  DebugOutput::PrintError(
    ErrorMessage {
      "TEXTURE ALREADY BINDLESS",
      "gl::TextureBase<T>::makeBindless() was called several times on a texture\n\n",
      file, func, line
    }
  );
}

inline void OGLWRAP_non_bindless_texture_residency_change(const char *file,
                                                          const char *func,
                                                          int line) {
  DebugOutput::PrintError(
    ErrorMessage {
      "NON BINDLESS TEXTURE RESIDENCY CHANGE",
      "Residency change was requested on a non-bindless texture\n\n",
      file, func, line
    }
  );
}

#else

#define OGLWRAP_CHECK_BINDLESS_TEXTURE_MODIFIED(bindless_handle)
#define OGLWRAP_CHECK_TEXTURE_ALREADY_BINDLESS(bindless_handle)
#define OGLWRAP_CHECK_NON_BINDLESS_TEXTURE_RESIDENCY_CHANGE(bindless_handle)

#endif

}  // namespace oglwarp

#endif  // OGLWRAP_TEXTURE_STATE_CHECKING_H_
