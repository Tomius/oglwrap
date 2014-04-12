/** @file oglwrap.hpp
    @brief The main header, including the core files of the library.
    It doesn't include everything, just the main features.
*/

#ifndef OGLWRAP_OGLWRAP_HPP_
#define OGLWRAP_OGLWRAP_HPP_

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
#include "config.hpp"
#include "debug/error.hpp"
#include "enums.hpp"
#include "debug/binding.hpp"
#include "general.hpp"

// GLM
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/type_ptr.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

// Commonly used oglwrap headers
#include "shader.hpp"
#include "uniform.hpp"
#include "buffer.hpp"
#include "vertexAttrib.hpp"
#include "global.hpp"

// Optional headers
#if OGLWRAP_INCLUDE_EVERYTHING
	#include "texture.hpp"
	#include "framebuffer.hpp"
	#include "transfeedback.hpp"
#endif

#endif // OGLWRAP_OGLWRAP_HPP_
