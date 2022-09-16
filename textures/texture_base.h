// Copyright (c) Tamas Csala

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
  /// Creates a new texture
  TextureBase() = default;

  /// Moves a texture
  TextureBase(TextureBase&&) noexcept = default;

  /// Moves a texture
  TextureBase& operator=(TextureBase&&) noexcept = default;

  /// Wrappes an existing OpenGL texture into an oglwrap TextureBase
  explicit TextureBase(GLuint handle) : texture_{handle} {}

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

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGetTextureHandleARB)
  /// Generates a handle for the texture to be used bindless.
  /** @see glGetTextureHandleARB */
  void makeBindless();
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMakeTextureHandleResidentARB)
  /// Make the texture memory resident
  /** @see glMakeTextureHandleResidentARB */
  void makeResident();
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(glMakeTextureHandleNonResidentARB)
  /// Make the texture non-resident
  /** @see glMakeTextureHandleNonResidentARB */
  void makeNonResident();
#endif

  /// return a texture image
  /** @param level - Specifies the level-of-detail number of the desired image. Level 0 is the base image level. Level n is the nth mipmap reduction image.
    * @param format - Specifies a pixel format for the returned data. The supported formats are GL_STENCIL_INDEX, GL_DEPTH_COMPONENT, GL_DEPTH_STENCIL, GL_RED, GL_GREEN, GL_BLUE, GL_RG, GL_RGB, GL_RGBA, GL_BGR, GL_BGRA, GL_RED_INTEGER, GL_GREEN_INTEGER, GL_BLUE_INTEGER, GL_RG_INTEGER, GL_RGB_INTEGER, GL_RGBA_INTEGER, GL_BGR_INTEGER, GL_BGRA_INTEGER.
    * @param type - Specifies a pixel type for the returned data. The supported types are GL_UNSIGNED_BYTE, GL_BYTE, GL_UNSIGNED_SHORT, GL_SHORT, GL_UNSIGNED_INT, GL_INT, GL_HALF_FLOAT, GL_FLOAT, GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV, GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV, GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2, GL_UNSIGNED_INT_2_10_10_10_REV, GL_UNSIGNED_INT_24_8, GL_UNSIGNED_INT_10F_11F_11F_REV, GL_UNSIGNED_INT_5_9_9_9_REV, and GL_FLOAT_32_UNSIGNED_INT_24_8_REV.
    * @param pixels - Returns the texture image. Should be a pointer to an array of the type specified by type.
    * @See glGetTexImage */
  void getTexImage(GLint level,
                    GLenum format,
                    GLenum type,
                    void* pixels);

  /// Returns the bindless handle if any, or zero
  GLuint64 bindless_handle() const;

  /// Returns the handle for the texture.
  const glObject& expose() const { return texture_; }

 protected:
  /// The handle for the texture.
  globjects::Texture texture_;

  /// The bindless handle for the texture.
  GLuint64 bindless_handle_ = 0;
};

} // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXUTRE_BASE_H_
