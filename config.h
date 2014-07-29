// Copyright (c) 2014, Tamas Csala

/** @file config.h
    @brief Contains macros to configure oglwrap.
*/

#ifndef OGLWRAP_CONFIG_H_
#define OGLWRAP_CONFIG_H_

/// Oglwrap can be forced to load glew.
#ifndef OGLWRAP_USE_GLEW
  #define OGLWRAP_USE_GLEW 0
#endif

#if OGLWRAP_USE_GLEW
  #include "./glew.h"
#endif

/**
 * @brief Instantiates the templates that can be used only with a few types.
 *
 * The compile time can be drastically decreased with this.
 * This also makes sure that global variables are only defined once
 */
#ifndef OGLWRAP_INSTANTIATE
  #define OGLWRAP_INSTANTIATE 0
#endif

/// A macro for internal use only
#ifdef GL_LINE
  #define OGLWRAP_OPENGL_INCLUDED 1
#else
  #define OGLWRAP_OPENGL_INCLUDED 0
#endif

/**
 * @brief If true, loads only the extensions, that are available.
 *
 * By default, it's only turned on, if a GL header is included.
 */
#ifndef OGLWRAP_DEFINE_EVERYTHING
  #if OGLWRAP_OPENGL_INCLUDED
    #define OGLWRAP_DEFINE_EVERYTHING 0
  #else
    // All #if defined(gl*) would evaluate as false,
    // so better just disable dependency check
    #define OGLWRAP_DEFINE_EVERYTHING 1
  #endif
#endif

/// If true, enables error checking, and DebugOutputs.
#ifndef OGLWRAP_DEBUG
  #define OGLWRAP_DEBUG 1
#endif

/**
 * @brief If true, warns you if you call a function that requires binding,
 * through an object that isn't the currently bound one.
 */
#if OGLWRAP_DEBUG
  #ifndef OGLWRAP_BINDCHECK
    #define OGLWRAP_BINDCHECK 1
  #endif
#else
  #ifndef OGLWRAP_BINDCHECK
    #define OGLWRAP_BINDCHECK 0
  #endif
#endif

/**
 * @brief If set to true, disables the oglwrap debug output.
 *
 * Setting OGLWRAP_DEBUG flag to false will override this flag, and will
 * also turn the debug output off
 */
#ifndef OGLWRAP_DISABLE_DEBUG_OUTPUT
  #define OGLWRAP_DISABLE_DEBUG_OUTPUT 0
#endif

/// If true, uses Magick++ API to load images.
#ifndef OGLWRAP_USE_IMAGEMAGICK
  #define OGLWRAP_USE_IMAGEMAGICK 0
#endif

/**
 * @brief If true, includes every oglwrap header, not just the commonly used ones.
 *
 * Setting this to true can drastically increase the compilation time
 */
#ifndef OGLWRAP_INCLUDE_EVERYTHING
  #define OGLWRAP_INCLUDE_EVERYTHING 0
#endif


#if OGLWRAP_DEBUG
  #ifndef OGLWRAP_STOP_AFTER_X_ERRORS
    #define OGLWRAP_STOP_AFTER_X_ERRORS 10
  #endif
#endif

/**
 * @brief You can define a default shader path, like "shaders/"
 *
 * Be sure to define this as a string literal, including quotes
 */
#ifndef OGLWRAP_DEFAULT_SHADER_PATH
  #define OGLWRAP_DEFAULT_SHADER_PATH ""
#endif

/// You can specify the oglwrap's namespace name.
#ifndef OGLWRAP_NAMESPACE_NAME
  #define OGLWRAP_NAMESPACE_NAME gl
#endif

#endif  // OGLWRAP_CONFIG_H_
