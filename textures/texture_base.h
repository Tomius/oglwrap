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
#include "../general.h"
#include "../globjects.h"
#include "../debug/binding.h"

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
#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

// -------======{[ TextureBase declaration ]}======-------

template <TextureType texture_t>
/// This class is implementing the base functions for textures.
/** You shouldn't use this class directly.
  * glGenTextures, glDeleteTextures */
class TextureBase {
protected:
  globjects::Texture texture; ///< The handle for the texture.
public:

  /// Binds the texture to this texture class's target.
  /** @see glBindTexture */
  void bind() const {
    gl(BindTexture(GLenum(texture_t), texture));
  }

  /// Binds the texture to this texture class's target in the specified texture unit.
  /** @see glBindTexture, glActiveTexture */
  void bind(GLuint tex_unit) const {
    Active(tex_unit);
    gl(BindTexture(GLenum(texture_t), texture));
  }

  /// Unbinds the texture from this texture class's target.
  /** @see glBindTexture */
  static void Unbind() {
    gl(BindTexture(GLenum(texture_t), 0));
  }
  /// Unbinds the texture from this texture class's target.
  /** @see glBindTexture */
  BIND_CHECKED void unbind() const {
    OGLWRAP_CHECK_BINDING2();
    Unbind();
  }

  /// Unbinds the texture from this texture class's target in the specified texture unit.
  /** @see glBindTexture */
  static void Unbind(GLuint tex_unit) {
    Active(tex_unit);
    gl(BindTexture(GLenum(texture_t), 0));
  }
  /// Unbinds the texture from this texture class's target in the specified texture unit.
  /** @see glBindTexture */
  BIND_CHECKED void unbind(GLuint tex_unit) const {
    Active(tex_unit);
    OGLWRAP_CHECK_BINDING2();
    Unbind();
  }

  /// Returns if this is the currently bound texture for its target.
  /** @see glGetIntegerv */
  bool isBound() const {
    GLint currentlyBoundTexture;
    gl(GetIntegerv(GLenum(GetBindingTarget(texture_t)), &currentlyBoundTexture));
    return texture == GLuint(currentlyBoundTexture);
  }

  /// Sets a specific texture unit to be the active texUnit.
  /** @param texUnit - The ID of the texture unit as an integer. Tex unit 1 is simply 1, not GL_TEXTURE0 + 1.
    * @see glActiveTexture */
  static void Active(GLuint texUnit) {
    gl(ActiveTexture(GL_TEXTURE0 + texUnit));
  }
  /// Sets a specific texture unit to be the active texUnit.
  /** @param texUnit - The ID of the texture unit as an integer. Tex unit 1 is simply 1, not GL_TEXTURE0 + 1.
    * @see glActiveTexture */
  void active(GLuint texUnit) const {
    Active(texUnit);
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGenerateMipmap)
  /// Generates mipmaps for the currently uploaded image to this texture class.
  /** @see glGenerateMipmap */
  static void GenerateMipmap() {
    gl(GenerateMipmap(GLenum(texture_t)));
  }
  /// Generates mipmaps for the currently uploaded image to this texture class.
  /** @see glGenerateMipmap */
  BIND_CHECKED void generateMipmap() const {
    OGLWRAP_CHECK_BINDING();
    GenerateMipmap();
  }
#endif

  /// Sets the border color for this texture class.
  /** @param color - Specifies the value, the border color should be set to.
    * @see glTexParameterfv, GL_TEXTURE_BORDER_COLOR */
  static void BorderColor(glm::vec4 color) {
    gl(TexParameterfv(
      GLenum(texture_t), GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color)
    ));
  }
  /// Sets the border color for this texture class.
  /** @param color - Specifies the value, the border color should be set to.
    * @see glTexParameterfv, GL_TEXTURE_BORDER_COLOR */
  BIND_CHECKED void borderColor(glm::vec4 color) const {
    OGLWRAP_CHECK_BINDING();
    BorderColor(color);
  }

  /// Sets the minification filter for this texture class.
  /** @param filtermode - The desired minification filter mode.
    * @see glTexParameteri, GL_TEXTURE_MIN_FILTER */
  static void MinFilter(enums::MinFilter filtermode) {
    gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_MIN_FILTER, GLenum(filtermode)));
  }
  /// Sets the minification filter for this texture class.
  /** @param filtermode - The desired minification filter mode.
    * @see glTexParameteri, GL_TEXTURE_MIN_FILTER */
  BIND_CHECKED void minFilter(enums::MinFilter filtermode) const {
    OGLWRAP_CHECK_BINDING();
    MinFilter(filtermode);
  }

  /// Sets the magnification filter for this texture class.
  /** @param filtermode - The desired magnification filter mode.
    * @see glTexParameteri, GL_TEXTURE_MAG_FILTER */
  static void MagFilter(enums::MagFilter filtermode) {
    gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_MAG_FILTER, GLenum(filtermode)));
  }
  /// Sets the magnification filter for this texture class.
  /** @param filtermode - The desired magnification filter mode.
    * @see glTexParameteri, GL_TEXTURE_MAG_FILTER */
  BIND_CHECKED void magFilter(enums::MagFilter filtermode) const {
    OGLWRAP_CHECK_BINDING();
    MagFilter(filtermode);
  }

  /// Sets the way, OpenGL should handle if the texture coordinate's 's' (first) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_S */
  static void WrapS(WrapMode wrapmode) {
    gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_WRAP_S, GLenum(wrapmode)));
  }
  /// Sets the way, OpenGL should handle if the texture coordinate's 's' (first) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_S */
  BIND_CHECKED void wrapS(WrapMode wrapmode) const {
    OGLWRAP_CHECK_BINDING();
    WrapS(wrapmode);
  }

  /// Sets the way, OpenGL should handle if the texture coordinate's 't' (second) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_T */
  static void WrapT(WrapMode wrapmode) {
    gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_WRAP_T, GLenum(wrapmode)));
  }
  /// Sets the way, OpenGL should handle if the texture coordinate's 't' (second) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_T */
  BIND_CHECKED void wrapT(WrapMode wrapmode) const {
    OGLWRAP_CHECK_BINDING();
    WrapT(wrapmode);
  }

  /// Sets the way, OpenGL should handle if the texture coordinate's 'p' (third) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_R */
  static void WrapP(WrapMode wrapmode) {
    gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_WRAP_R, GLenum(wrapmode)));
  }
  /// Sets the way, OpenGL should handle if the texture coordinate's 'p' (third) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_R */
  BIND_CHECKED void wrapP(WrapMode wrapmode) const {
    OGLWRAP_CHECK_BINDING();
    WrapP(wrapmode);
  }

  /// Sets what OpenGL should do if you write texture.r for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_R */
  static void SwizzleR(SwizzleMode swizzleMode) {
    gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_SWIZZLE_R, GLenum(swizzleMode)));
  }
  /// Sets what OpenGL should do if you write texture.r for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_R */
  BIND_CHECKED void swizzleR(SwizzleMode swizzleMode) const {
    OGLWRAP_CHECK_BINDING();
    SwizzleR(swizzleMode);
  }

  /// Sets what OpenGL should do if you write texture.g for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_G */
  static void SwizzleG(SwizzleMode swizzleMode) {
    gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_SWIZZLE_G, GLenum(swizzleMode)));
  }
  /// Sets what OpenGL should do if you write texture.g for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_G */
  BIND_CHECKED void swizzleG(SwizzleMode swizzleMode) const {
    OGLWRAP_CHECK_BINDING();
    SwizzleG(swizzleMode);
  }

  /// Sets what OpenGL should do if you write texture.b for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_B */
  static void SwizzleB(SwizzleMode swizzleMode) {
    gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_SWIZZLE_B, GLenum(swizzleMode)));
  }
  /// Sets what OpenGL should do if you write texture.b for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_B */
  BIND_CHECKED void swizzleB(SwizzleMode swizzleMode) const {
    OGLWRAP_CHECK_BINDING();
    SwizzleB(swizzleMode);
  }

  /// Sets what OpenGL should do if you write texture.a for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_A */
  static void SwizzleA(SwizzleMode swizzleMode) {
    gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_SWIZZLE_A, GLenum(swizzleMode)));
  }
  /// Sets what OpenGL should do if you write texture.a for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_A */
  BIND_CHECKED void swizzleA(SwizzleMode swizzleMode) const {
    OGLWRAP_CHECK_BINDING();
    SwizzleA(swizzleMode);
  }

  /// Sets what OpenGL should do if you use the swizzle operator to select either of the 4 components from a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteriv, GL_TEXTURE_SWIZZLE_RGBA */
  static void SwizzleRGBA(SwizzleMode swizzleMode) {
    const GLint swizzle_array[4] = {
      GLint(swizzleMode), GLint(swizzleMode),
      GLint(swizzleMode), GLint(swizzleMode)
    };
    gl(TexParameteriv(GLenum(texture_t), GL_TEXTURE_SWIZZLE_RGBA, swizzle_array));
  }
  /// Sets what OpenGL should do if you use the swizzle operator to select either of the 4 components from a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteriv, GL_TEXTURE_SWIZZLE_RGBA */
  BIND_CHECKED void swizzleRGBA(SwizzleMode swizzleMode) const {
    OGLWRAP_CHECK_BINDING();
    SwizzleRGBA(swizzleMode);
  }

  /// Sets the anisotropy extension to a desired value.
  /** It doesn't do anything if anisotropy is not supported
    * @param value - The desired anisotropy value.
    * @see glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT */
  static void Anisotropy(float value) {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_MAX_ANISOTROPY_EXT)
    gl(TexParameterf(GLenum(texture_t), GL_TEXTURE_MAX_ANISOTROPY_EXT, value));
#endif
  }
  /// Sets the anisotropy extension to a desired value.
  /** It doesn't do anything if anisotropy is not supported
    * @param value - The desired anisotropy value.
    * @see glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT */
  BIND_CHECKED void anisotropy(float value) const {
    OGLWRAP_CHECK_BINDING();
    Anisotropy(value);
  }

  /// Sets the anisotropy extension to the maximum value possible on this hardware.
  /** It doesn't do anything if anisotropy is not supported
    * @see glGetFloatv, glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT */
  static void MaxAnisotropy() {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_MAX_ANISOTROPY_EXT)
    GLfloat maxAniso = 0.0f;
    gl(GetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAniso));
    gl(TexParameterf(GLenum(texture_t), GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAniso));
#endif  // GL_TEXTURE_MAX_ANISOTROPY_EXT
  }
  /// Sets the anisotropy extension to the maximum value possible on this hardware.
  /** It doesn't do anything if anisotropy is not supported
    * @see glGetFloatv, glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT */
  BIND_CHECKED void maxAnisotropy() const {
    OGLWRAP_CHECK_BINDING();
    MaxAnisotropy();
  }

#if OGLWRAP_DEFINE_EVERYTHING || (defined(glGenBuffers) && defined(glDeleteBuffers) && defined(GL_TEXTURE_BUFFER))
  /// Assigns a buffer storing the texel data to the texture.
  /** @param internalFormat - Specifies the internal format of the data in the store belonging to buffer. It must be a sized, uncompressed internal format.
    * @param buffer - Specifies the name of the buffer object whose storage to attach to the active buffer texture.
    * @see glTexBuffer */
  static void Buffer(PixelDataInternalFormat internalFormat,
                     const TextureBuffer& buffer) {
    gl(TexBuffer(GLenum(texture_t), GLenum(internalFormat), buffer.expose()));
  }
  /// Assigns a buffer storing the texel data to the texture.
  /** @param internalFormat - Specifies the internal format of the data in the store belonging to buffer. It must be a sized, uncompressed internal format.
    * @param buffer - Specifies the name of the buffer object whose storage to attach to the active buffer texture.
    * @see glTexBuffer */
  BIND_CHECKED void buffer(PixelDataInternalFormat internalFormat,
                           const TextureBuffer& buffer) const {
    OGLWRAP_CHECK_BINDING();
    Buffer(internalFormat, buffer);
  }
#endif

  /// Sets the compare mode.
  /** @param mode - The desired compare mode.
    * @see glTexParameteri, GL_TEXTURE_COMPARE_MODE */
  static void CompareMode(enums::CompareMode mode) {
    gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_COMPARE_MODE, GLenum(mode)));
  }
  /// Sets the compare mode.
  /** @param mode - The desired compare mode.
    * @see glTexParameteri, GL_TEXTURE_COMPARE_MODE */
  BIND_CHECKED void compareMode(enums::CompareMode mode) const {
    OGLWRAP_CHECK_BINDING();
    CompareMode(mode);
  }

  /// Sets the compare function.
  /** @param func - The desired compare function.
    * @see glTexParameteri, GL_TEXTURE_COMPARE_FUNC */
  static void CompareFunc(enums::CompareFunc func) {
    gl(TexParameteri(GLenum(texture_t), GL_TEXTURE_COMPARE_FUNC, GLenum(func)));
  }
  /// Sets the compare function.
  /** @param func - The desired compare function.
    * @see glTexParameteri, GL_TEXTURE_COMPARE_FUNC */
  BIND_CHECKED void compareFunc(enums::CompareFunc func) const {
    OGLWRAP_CHECK_BINDING();
    CompareFunc(func);
  }

  /// Returns the handle for the texture.
  const glObject& expose() const {
    return texture;
  }
};

} // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXUTRE_BASE_H_
