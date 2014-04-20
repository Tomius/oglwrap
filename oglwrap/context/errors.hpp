/** @file errors.hpp
    @brief Implements OpenGL errors related stuff.
*/

#ifndef OGLWRAP_CONTEXT_ERRORS_HPP_
#define OGLWRAP_CONTEXT_ERRORS_HPP_

#include "../config.hpp"
#include "../enums.hpp"

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
