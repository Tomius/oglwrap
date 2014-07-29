// Copyright (c) 2014, Tamas Csala

/** @file bind_checking.h
    @brief Implements enums casts to help binding checks.
*/

#ifndef OGLWRAP_DEBUG_BIND_CHECKING_H_
#define OGLWRAP_DEBUG_BIND_CHECKING_H_

#include <string>
#include <iostream>

#include "./error_checking.h"

namespace OGLWRAP_NAMESPACE_NAME {

#if OGLWRAP_BINDCHECK
/// Calls the IsBound() for this and prints an error and calls Bind() if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING() \
  if (!IsBound(*this)) { \
    OGLWRAP_print_another_object_is_bound_error(__FILE__, OGLWRAP_FUNCTION_MACRO, __LINE__); \
    Bind(*this); \
  }

/// Calls the IsBound() for the given object and prints an error and calls Bind() if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING_EXPLICIT(object_to_check) \
  if (!IsBound(object_to_check)) { \
    OGLWRAP_print_another_object_is_bound_error(__FILE__, OGLWRAP_FUNCTION_MACRO, __LINE__); \
    Bind(object_to_check); \
  }

/// Checks if the object name '0' is bound to the given target, and prints error if it is.
/** Only if OGLWRAP_BINDCHECK is defined true
  * @param bind_target - The target to check. Expected to be a value returned by GetBindingTarget(); */
#define OGLWRAP_CHECK_FOR_DEFAULT_BINDING(bind_target) \
  if (!OGLWRAP_currentlyBoundTarget(bind_target)) \
    OGLWRAP_print_default_object_is_bound_error(__FILE__, OGLWRAP_FUNCTION_MACRO, __LINE__);

/// Checks if the object name '0' is bound to the target explicitly given by its name, and prints error if it is.
/** Only if OGLWRAP_BINDCHECK is defined true
  * @param bind_target - The target to check. Expected to be an explicit OpenGL macro name. */
#define OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(bind_target) \
  DebugOutput::LastUsedBindTarget() = #bind_target;             \
  if (!OGLWRAP_currentlyBoundTarget(bind_target))               \
    OGLWRAP_print_default_object_is_bound_error(__FILE__, OGLWRAP_FUNCTION_MACRO, __LINE__);

inline GLint OGLWRAP_currentlyBoundTarget(GLenum target) {
  GLint currently_bound_target;
  glGetIntegerv(target, &currently_bound_target);
  return currently_bound_target;
}

/// A function used by OGLWRAP_CHECK_FOR_DEFAULT_BINDING() macro
inline void OGLWRAP_print_another_object_is_bound_error(const char *file,
                                                        const char *func,
                                                        int line) {
  DebugOutput::PrintError(
    ErrorMessage {
      "BIND CHECK FAILURE",
      "The function is called through an object that is different "
      "than the one, currently bound to " + DebugOutput::LastUsedBindTarget() +
      ".\nDid you forget to call Bind() on the object? \n\n",
      file, func, line
    }
  );
}

/// A function used by OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT() macro
inline void OGLWRAP_print_default_object_is_bound_error(const char *file,
                                                        const char *func,
                                                        int line) {
  DebugOutput::PrintError(
    ErrorMessage {
      "BIND CHECK FAILURE",
      "The function requires an object to be bound to " +
      DebugOutput::LastUsedBindTarget() + " but only the default object '0' is "
      "bound to that target.\n\n",
      file, func, line
    }
  );
}

#else
/// Calls the isBound() member function, and prints an error, and binds it, if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING()

/// Calls the isBoundFunc function, and prints an error, and calls bindFunc, if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING_EXPLICIT(object_to_check)

/// Checks if the object name '0' is bound to the given target, and prints error if it is.
/** Only if OGLWRAP_BINDCHECK is defined true
  * @param bind_target - The target to check. Expected to be a value returned by GetBindingTarget(); */
#define OGLWRAP_CHECK_FOR_DEFAULT_BINDING(bind_target)

/// Checks if the object name '0' is bound to the target explicitly given by its name, and prints error if it is.
/** Only if OGLWRAP_BINDCHECK is defined true
  * @param bind_target - The target to check. Expected to be an explicit OpenGL macro name. */
#define OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(bind_target)
#endif

}  // namespace oglwarp

#endif  // OGLWRAP_DEBUG_BINDING_H_
