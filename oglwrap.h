// Copyright (c) 2014, Tamas Csala

/** @file oglwrap.h
    @brief The main header, including the core files of the library.
    It doesn't include everything, just the main features.
*/

#ifndef OGLWRAP_OGLWRAP_H_
#define OGLWRAP_OGLWRAP_H_

#ifdef gl
  #undef gl
  #warning Please do not define a macro named gl before including oglwrap
#endif

#ifdef glfunc
  #undef glfunc
  #warning Please do not define a macro named glfunc before including oglwrap
#endif

// Commonly used oglwrap headers
#include "./buffer.h"
#include "./program.h"
#include "./context.h"
#include "./uniform.h"
#include "./smart_enums.h"
#include "./vertex_array.h"
#include "./vertex_attrib.h"
#include "textures/texture_2D.h"
#include "textures/texture_cube.h"


// Optional headers
#if OGLWRAP_INCLUDE_EVERYTHING
  #include "./texture.h"
  #include "./framebuffer.h"
  #include "./transform_feedback.h"
  #include "shapes/cube_shape.h"
  #include "shapes/sphere_shape.h"
  #include "shapes/rectangle_shape.h"
#endif

// Put a warning if I forget to undef the internal macros
#ifdef gl
  #warning Some oglwrap header forgot to undefine its internal macros.
#endif

#endif  // OGLWRAP_OGLWRAP_H_
