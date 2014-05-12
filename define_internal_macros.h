// Copyright (c) 2014, Tamas Csala

/** @file define_internal_macros.h
    @brief Defines oglwrap's internal macros
*/

#include "debug/error_checking.h"

#ifndef glfunc
	#define glfunc(func) OGLWRAP_CHECKED_GLFUNCTION(func)
#endif

#ifndef gl
	#define gl(func) OGLWRAP_CHECKED_FUNCTION(func)
#endif
