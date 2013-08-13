/** @file config.hpp
    @brief Contains macros to configure oglwrap.
*/
#ifndef CONFIG_HPP
#define CONFIG_HPP

/// Loads core profile only
#ifndef OGLWRAP_COREONLY
#define OGLWRAP_COREONLY 1
#endif

/// Catches errors that happens inside an oglwrap function.
#ifndef OGLWRAP_DEBUG
#define OGLWRAP_DEBUG 1
#endif

/// Catches every error, even the ones caused by OpenGL calls outside oglwrap
#ifndef OGLWRAP_DEBUG_FULL
#define OGLWRAP_DEBUG_FULL 0
#endif

/// Uses Magick++ API to load images
#ifndef OGLWRAP_IMAGEMAGICK
#define OGLWRAP_IMAGEMAGICK 1
#endif


#endif // CONFIG_HPP
