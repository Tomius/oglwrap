// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_ERRORS_H_
#define OGLWRAP_CONTEXT_ERRORS_H_

#include "../enums/error_type.h"

namespace oglwrap {
namespace context {

class Errors {
public:
	/// Returns the last OpenGL error.
	/** @see glGetError */
	static ErrorType GetError() {
		return static_cast<ErrorType>(glGetError());
	}
};

}
}
#endif
