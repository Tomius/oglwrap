/** @file glew.hpp
    @brief #includes glew in a platform independent way.
*/

#ifndef OGLWRAP_GLEW_HPP_
#define OGLWRAP_GLEW_HPP_

#define GLEW_NO_GLU

#if defined(__APPLE__)
#include <OpenGL/glew.h>
#else
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#include <windows.h>
#endif
#include <GL/glew.h>
#endif

#endif // OGLWRAP_GLEW_HPP_
