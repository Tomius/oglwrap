// Copyright (c) 2014, Tamas Csala

/** @file texture_base.h
    @brief Implements the base functionality for textures.
*/

#ifndef OGLWRAP_TEXTURES_TEXUTRE_BASE_H_
#define OGLWRAP_TEXTURES_TEXUTRE_BASE_H_

#if OGLWRAP_USE_IMAGEMAGICK
  #include <Magick++.h>
#endif

#include "../config.h"
#include "../buffer.h"
#include "../globjects.h"

#include "../enums/wrap_mode.h"
#include "../enums/min_filter.h"
#include "../enums/mag_filter.h"
#include "../enums/swizzle_mode.h"
#include "../enums/compare_mode.h"
#include "../enums/compare_func.h"
#include "../enums/texture_type.h"
#include "../enums/texture_binding.h"
#include "../enums/pixel_data_type.h"
#include "../enums/pixel_data_format.h"
#include "../enums/pixel_data_internal_format.h"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

template <TextureType texture_t>
/// This class is implementing the base functions for textures.
/** You shouldn't use this class directly.
  * glGenTextures, glDeleteTextures */
class TextureBase {
 public:
#if OGLWRAP_DEFINE_EVERYTHING || defined(glGenerateMipmap)
  /// Generates mipmaps for the currently uploaded image to this texture class.
  /** @see glGenerateMipmap */
  void generateMipmap();
#endif

  /// Sets the border color for this texture class.
  /** @param color - Specifies the value, the border color should be set to.
    * @see glTexParameterfv, GL_TEXTURE_BORDER_COLOR */
  void borderColor(glm::vec4 color);

  /// Sets the minification filter for this texture class.
  /** @param filtermode - The desired minification filter mode.
    * @see glTexParameteri, GL_TEXTURE_MIN_FILTER */
  void minFilter(enums::MinFilter filtermode);

  /// Sets the magnification filter for this texture class.
  /** @param filtermode - The desired magnification filter mode.
    * @see glTexParameteri, GL_TEXTURE_MAG_FILTER */
  void magFilter(enums::MagFilter filtermode);

  /// Sets the way, OpenGL should handle if the texture coordinate's 's' (first) part is out of the [0, 1] range for this texture class.
  /** @param wrap_mode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_S */
  void wrapS(WrapMode wrap_mode);

  /// Sets the way, OpenGL should handle if the texture coordinate's 't' (second) part is out of the [0, 1] range for this texture class.
  /** @param wrap_mode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_T */
  void wrapT(WrapMode wrap_mode);

  /// Sets the way, OpenGL should handle if the texture coordinate's 'p' (third) part is out of the [0, 1] range for this texture class.
  /** @param wrap_mode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_R */
  void wrapP(WrapMode wrap_mode);

  /// Sets what OpenGL should do if you write texture.r for a texture of this class in a shader.
  /** @param swizzle_mode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_R */
  void swizzleR(SwizzleMode swizzle_mode);

  /// Sets what OpenGL should do if you write texture.g for a texture of this class in a shader.
  /** @param swizzle_mode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_G */
  void swizzleG(SwizzleMode swizzle_mode);

  /// Sets what OpenGL should do if you write texture.b for a texture of this class in a shader.
  /** @param swizzle_mode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_B */
  void swizzleB(SwizzleMode swizzle_mode);

  /// Sets what OpenGL should do if you write texture.a for a texture of this class in a shader.
  /** @param swizzle_mode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_A */
  void swizzleA(SwizzleMode swizzle_mode);

  /// Sets what OpenGL should do if you use the swizzle operator to select either of the 4 components from a texture of this class in a shader.
  /** @param swizzle_mode - The desired swizzle mode.
    * @see glTexParameteriv, GL_TEXTURE_SWIZZLE_RGBA */
  void swizzleRGBA(SwizzleMode swizzle_mode);

  /// Sets the anisotropy extension to a desired value.
  /** It doesn't do anything if anisotropy is not supported
    * @param value - The desired anisotropy value.
    * @see glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT */
  void anisotropy(float value);

  /// Sets the anisotropy extension to the maximum value possible on this hardware.
  /** It doesn't do anything if anisotropy is not supported
    * @see glGetFloatv, glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT */
  void maxAnisotropy();

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexBuffer)
  /// Assigns a buffer storing the texel data to the texture.
  /** @param internal_format - Specifies the internal format of the data in the store belonging to buffer. It must be a sized, uncompressed internal format.
    * @param buffer - Specifies the name of the buffer object whose storage to attach to the active buffer texture.
    * @see glTexBuffer */
  void buffer(PixelDataInternalFormat internal_format,
              const TextureBuffer& buffer);
#endif

  /// Sets the compare mode.
  /** @param mode - The desired compare mode.
    * @see glTexParameteri, GL_TEXTURE_COMPARE_MODE */
  void compareMode(enums::CompareMode mode);

  /// Sets the compare function.
  /** @param func - The desired compare function.
    * @see glTexParameteri, GL_TEXTURE_COMPARE_FUNC */
  void compareFunc(enums::CompareFunc func);

  /// Returns the handle for the texture.
  const glObject& expose() const { return texture_; }

 protected:
  /// The handle for the texture.
  globjects::Texture texture_;
};

} // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXUTRE_BASE_H_
