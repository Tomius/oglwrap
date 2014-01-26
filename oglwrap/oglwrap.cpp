/** @file oglwrap.cpp
    @brief The file to link if OGLWRAP_HEADER_ONLY is 0. 
    It might grant a little speed boost.
*/

#define OGLWRAP_HEADER_ONLY 0
#include "oglwrap/glew.hpp"
#include "oglwrap/oglwrap.hpp"

namespace oglwrap {

DebugOutput debug_output;
#if OGLWRAP_DEBUG
  GLenum OGLWRAP_LAST_ERROR = GL_NO_ERROR;
#endif

}



