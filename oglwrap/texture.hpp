/** @file texture.hpp
    @brief The main header for textures, including the texture related headers of the library.
*/

#pragma once

#if OGLWRAP_IMAGEMAGICK
#include <Magick++.h>
#endif

#include "textures/texture_base.hpp"
#include "textures/texture_1D.hpp"
#include "textures/texture_2D.hpp"
#include "textures/texture_cube.hpp"
#include "textures/texture_3D.hpp"

