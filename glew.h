// Copyright (c) 2014, Tamas Csala

/** @file glew.h
    @brief #includes glew in a platform independent way.
*/

#ifndef OGLWRAP_GLEW_H_
#define OGLWRAP_GLEW_H_

#define GLEW_NO_GLU

#if defined(__APPLE__)
  #include <OpenGL/glew.h>
#else
  #include <GL/glew.h>
#endif

#endif  // OGLWRAP_GLEW_H_
