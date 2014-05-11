/** @file binding.hpp
    @brief Implements enums casts to help binding checks.
*/

#ifndef OGLWRAP_DEBUG_BINDING_H_
#define OGLWRAP_DEBUG_BINDING_H_

#include <string>
#include <iostream>
#include "error.h"
#include "../enums.h"

namespace oglwrap {

static std::string OGLWRAP_LAST_BIND_TARGET;

#if OGLWRAP_BINDCHECK
/// Calls the isBound() member function, and prints an error and calls bind() if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING() \
  if (!isBound()) { \
    OGLWRAP_print_another_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
    bind(); \
  }

/// Calls the isBound() member function, and prints an error if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING2() \
  if (!isBound()) { \
    OGLWRAP_print_another_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
  }

/// Calls the isBoundFunc function, and prints an error and calls bindFunc if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING_EXPLICIT(isBoundFunc, bindFunc) \
  if (!isBoundFunc) { \
    OGLWRAP_print_another_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
    bindFunc; \
  }

/// Calls the isBoundFunc function, and prints an error if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING2_EXPLICIT(isBoundFunc) \
  if (!isBoundFunc) { \
    OGLWRAP_print_another_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
  }

/// Checks if the object name '0' is bound to the given target, and prints error if it is.
/** Only if OGLWRAP_BINDCHECK is defined true
  * @param bindTarget - The target to check. Expected to be a value returned by GetBindingTarget(); */
#define OGLWRAP_CHECK_FOR_DEFAULT_BINDING(bindTarget) \
  GLint __currently_bound_target; \
  glGetIntegerv(bindTarget, &__currently_bound_target); \
  if (__currently_bound_target == 0) \
    OGLWRAP_print_default_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__);

/// Checks if the object name '0' is bound to the target explicitly given by its name, and prints error if it is.
/** Only if OGLWRAP_BINDCHECK is defined true
  * @param bindTarget - The target to check. Expected to be an explicit OpenGL macro name. */
#define OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(bindTarget) \
  OGLWRAP_LAST_BIND_TARGET = #bindTarget; \
  GLint __currently_bound_target_for_##bindTarget; \
  glGetIntegerv(bindTarget, &__currently_bound_target_for_##bindTarget); \
  if (__currently_bound_target_for_##bindTarget == 0) \
    OGLWRAP_print_default_object_is_bound_error(__FILE__, __PRETTY_FUNCTION__, __LINE__);

/// A function used by OGLWRAP_CHECK_FOR_DEFAULT_BINDING() macro
inline void OGLWRAP_print_another_object_is_bound_error(const char *file,
                                                        const char *func,
                                                        int line) {
  DebugOutput::PrintError(
    ErrorMessage {
      "BIND CHECK FAILURE",
      "The function is called through an object that is different "
      "than the one, currently bound to " + OGLWRAP_LAST_BIND_TARGET + ".\n"
      "Did you forget to call .bind() on the object? \n\n",
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
      "The function requires an object to be bound to " + OGLWRAP_LAST_BIND_TARGET +
      " but only the default object '0' is bound to that target.\n\n",
      file, func, line
    }
  );
}

/// Checks if the program is the currently active one, and if not, it returns prints out an error, and calls use on that program.
/** @param program - The shader program to check if is active. */
#define OGLWRAP_CHECK_ACTIVE_PROGRAM(program)                                           \
  if (!program.isActive()) {                                                     \
    OGLWRAP_print_another_program_is_active_error(                              \
      __FILE__, __PRETTY_FUNCTION__, __LINE__                                   \
    );                                                                          \
    program.use();                                                              \
  }

/// A function used by the OGLWRAP_CHECK_ACTIVE_PROGRAM() macro
inline void OGLWRAP_print_another_program_is_active_error(const char *file,
                                                          const char *func,
                                                          int line) {
    DebugOutput::PrintError(
      ErrorMessage {
        "ACTIVE PROGRAM CHECK FAILURE",
        "The currently active program is different than "
        "the one, this function is supposed to operate on.\n"
        "Did you forget to call .use() on the program? \n\n",
        file, func, line
      }
  );
}
#else
/// Calls the isBound() member function, and prints an error, and binds it, if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING()

/// Calls the isBound() member function, and prints an error if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING2()

/// Calls the isBoundFunc function, and prints an error, and calls bindFunc, if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING_EXPLICIT(isBoundFunc, bindFunc)

/// Calls the isBoundFunc function, and prints an error if it returns false.
/** Only if OGLWRAP_BINDCHECK is defined true */
#define OGLWRAP_CHECK_BINDING2_EXPLICIT(isBoundFunc)

/// Checks if the object name '0' is bound to the given target, and prints error if it is.
/** Only if OGLWRAP_BINDCHECK is defined true
  * @param bindTarget - The target to check. Expected to be a value returned by GetBindingTarget(); */
#define OGLWRAP_CHECK_FOR_DEFAULT_BINDING(bindTarget)

/// Checks if the object name '0' is bound to the target explicitly given by its name, and prints error if it is.
/** Only if OGLWRAP_BINDCHECK is defined true
  * @param bindTarget - The target to check. Expected to be an explicit OpenGL macro name. */
#define OGLWRAP_CHECK_FOR_DEFAULT_BINDING_EXPLICIT(bindTarget)

/// Checks if the program is the currently active one, and if not, it prints out an error, and calls use() on that program.
/** Only if OGLWRAP_BINDCHECK is defined true
  * @param program - The shader program to check if is active. */
#define OGLWRAP_CHECK_ACTIVE_PROGRAM(program)
#endif

} // namespace oglwarp

#endif // OGLWRAP_DEBUG_BINDING_H_
