/** @file config.hpp
    @brief Contains macros to configure oglwrap.
*/

#pragma once

/// If true, enables error checking, and DebugOutputs.
#ifndef OGLWRAP_DEBUG
    #define OGLWRAP_DEBUG 1
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
