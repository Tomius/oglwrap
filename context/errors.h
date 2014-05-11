/** @file errors.h
    @brief Implements OpenGL errors related stuff.
*/

#ifndef OGLWRAP_CONTEXT_ERRORS_H_
#define OGLWRAP_CONTEXT_ERRORS_H_

#include "../config.h"
#include "../enums.h"

namespace oglwrap {
namespace context {

class Errors {
public:
	/// Returns the last OpenGL error.
	/** @see glGetError */
	static GLError GetError() {
		return static_cast<GLError>(glGetError());
	}
};

}
}
#endif
