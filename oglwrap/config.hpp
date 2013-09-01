/** @file config.hpp
    @brief Contains macros to configure oglwrap.
*/
#ifndef CONFIG_HPP
#define CONFIG_HPP

/// Enables error checking, and DebugOutputs.
#ifndef OGLWRAP_DEBUG
#define OGLWRAP_DEBUG 1
#endif

/// Uses the ARB_DebugOutput. If it's 0, it will use the own debug output instead.
/** DebugOutputs only work if OGLWRAP_DEBUG is defined */
#ifndef OGLWRAP_USE_ARB_DEBUG_OUTPUT
#define OGLWRAP_USE_ARB_DEBUG_OUTPUT 0
#endif

/// Uses Magick++ API to load images
#ifndef OGLWRAP_IMAGEMAGICK
#define OGLWRAP_IMAGEMAGICK 1
#endif

#endif // CONFIG_HPP
