/** @file oglwrap.h
    @brief The main header, including the core files of the library.
    It doesn't include everything, just the main features.
*/

#ifndef OGLWRAP_OGLWRAP_H_
#define OGLWRAP_OGLWRAP_H_

#ifdef gl
  #undef gl
  #warning Please don not define a macro named gl before including oglwrap
#endif

#ifdef glfunc
  #undef glfunc
  #warning Please don not define a macro named glfunc before including oglwrap
#endif

// standard headers
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <cctype>
#include <cstring>
#include <cassert>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

// basic headers, required by all others below
#include "config.h"
#include "enums.h"
#include "debug/error.h"
#include "debug/binding.h"
#include "general.h"

// GLM
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/type_ptr.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

// Commonly used oglwrap headers
#include "context.h"
#include "shader.h"
#include "uniform.h"
#include "buffer.h"
#include "vertex_attrib.h"

// Optional headers
#if OGLWRAP_INCLUDE_EVERYTHING
	#include "texture.h"
	#include "framebuffer.h"
	#include "transfeedback.h"
#endif

// Put a warning if someone forgot to undef a macro
#ifdef gl
  #warning Some oglwrap header forgot to undefine its internal macros.
#endif

#endif // OGLWRAP_OGLWRAP_H_
