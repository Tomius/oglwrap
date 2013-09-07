/** @file config.hpp
    @brief Contains macros to configure oglwrap.
*/

#pragma once

/// If true, loads only the extensions, that are available.
/** By default, it's only turned on, if a GL header is included. */
#ifndef OGLWRAP_CHECK_DEPENDENCIES
    #ifdef GL_LINE // If an OpenGL header is loaded.
        #define OGLWRAP_CHECK_DEPENDENCIES 1
    #else // else all #if defined(gl*) would evaluate as false, so better just disable dependency check
        #define OGLWRAP_CHECK_DEPENDENCIES 0
#endif

/// If true, enables error checking, and DebugOutputs.
#ifndef OGLWRAP_DEBUG
    #define OGLWRAP_DEBUG 1
#endif

/// If true, warns you if call a function that requires binding through an object that isn't the currently bound one.
#if OGLWRAP_DEBUG
    #ifndef OGLWRAP_BINDCHECK
        #define OGLWRAP_BINDCHECK 1
    #endif
#endif

/// If true, uses the ARB_DebugOutput. If it's false, it will use the own debug output instead.
/** DebugOutputs only work if OGLWRAP_DEBUG is true */
#ifndef GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB
    #define OGLWRAP_USE_ARB_DEBUG_OUTPUT 0
#else
    #ifndef OGLWRAP_USE_ARB_DEBUG_OUTPUT
        #define OGLWRAP_USE_ARB_DEBUG_OUTPUT 0
    #endif
#endif

/// If true, uses Magick++ API to load images.
#ifndef OGLWRAP_IMAGEMAGICK
    #define OGLWRAP_IMAGEMAGICK 1
#endif

