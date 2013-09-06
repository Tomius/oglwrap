/** @file oglwrap.hpp
    @brief The main header, including the core files of the library.
    It doesn't include everything, just the main features.
*/

#pragma once

/* TODO:
    - shapes -> block multiply setup calls
    - document shapes
    - context class
    - program uniforms
    - uniform blocks / shader storage
    - separable shader stages.
    - some 4.0+ features are still missing.
*/

// standard headers
#include <map>
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
#include "debug/callback.hpp"
#include "debug/error.hpp"
#include "enums.hpp"
#include "debug/binding.hpp"
#include "general.hpp"

// GLM
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/type_ptr.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

// Own headers
#include "shader.hpp"
#include "uniform.hpp"
#include "buffer.hpp"
#include "vertexAttrib.hpp"
#include "global.hpp"
#include "texture.hpp"
#include "framebuffer.hpp"
#include "transfeedback.hpp"

