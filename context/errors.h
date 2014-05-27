// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_ERRORS_H_
#define OGLWRAP_CONTEXT_ERRORS_H_

#include "../enums/error_type.h"

namespace OGLWRAP_NAMESPACE_NAME {

/// Returns the last OpenGL error.
/** @see glGetError */
inline ErrorType GetError() {
	return static_cast<ErrorType>(glGetError());
}

} // namespace oglwrap

#endif
