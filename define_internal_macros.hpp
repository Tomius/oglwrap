/** @file define_internal_macros.hpp
    @brief Defines oglwrap's internal macros
*/

#include "debug/error.hpp"

#ifndef glfunc
	#define glfunc(func) OGLWRAP_CHECKED_GLFUNCTION(func)
#endif

#ifndef gl
	#define gl(func) OGLWRAP_CHECKED_FUNCTION(func)
#endif
