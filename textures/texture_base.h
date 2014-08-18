// Copyright (c) 2014, Tamas Csala

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
#include "../enums/texture_target.h"
#include "../enums/texture_binding.h"
#include "../enums/pixel_data_type.h"
#include "../enums/pixel_data_format.h"
#include "../enums/pixel_data_internal_format.h"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

class TextureBase {
 public:
  const TextureTarget target;
  globjects::Texture handle;

  explicit TextureBase(TextureTarget target) : target(target) { }
};

/// This class is implementing the base functions for textures.
class BoundTexture {
 public:
  explicit BoundTexture(const TextureBase& tex)
      : target_(static_cast<GLenum>(tex.target))
      , moved_(false) {
    gl(GetIntegerv(GLenum(GetBindingTarget(tex.target)),
                  reinterpret_cast<GLint*>(&last_binding_)));
    gl(BindTexture(target_, tex.handle));
  }

  BoundTexture(BoundTexture&& other)
      : target_(other.target_)
      , last_binding_(other.last_binding_)
      , moved_(other.moved_) {
    other.moved_ = true;
  }

  ~BoundTexture() {
    if (!moved_) { gl(BindTexture(target_, last_binding_)); }
  }

  // No copy
  BoundTexture(const BoundTexture&) = delete;
  BoundTexture& operator=(const BoundTexture&) = delete;

#if OGLWRAP_DEFINE_EVERYTHING || defined(glGenerateMipmap)
  /// Generates mipmaps for the currently uploaded image to this texture class.
  void generateMipmap() {
     gl(GenerateMipmap(target_));
  }
#endif

  /// Sets the border color for this texture class.
  void borderColor(const glm::vec4& color) {
    gl(TexParameterfv(target_, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color)));
  }

  /// Sets the minification filter for this texture.
  void minFilter(enums::MinFilter filtermode) {
    gl(TexParameteri(target_, GL_TEXTURE_MIN_FILTER, GLenum(filtermode)));
  }

  /// Sets the magnification filter for this texture.
  void magFilter(enums::MagFilter filtermode) {
    gl(TexParameteri(target_, GL_TEXTURE_MAG_FILTER, GLenum(filtermode)));
  }

  void wrapS(WrapMode wrap_mode) {
    gl(TexParameteri(target_, GL_TEXTURE_WRAP_S, GLenum(wrap_mode)));
  }

  void wrapT(WrapMode wrap_mode) {
    gl(TexParameteri(target_, GL_TEXTURE_WRAP_T, GLenum(wrap_mode)));
  }

  void wrapP(WrapMode wrap_mode) {
    gl(TexParameteri(target_, GL_TEXTURE_WRAP_R, GLenum(wrap_mode)));
  }

  void swizzleR(SwizzleMode swizzle_mode) {
    gl(TexParameteri(target_, GL_TEXTURE_SWIZZLE_R, GLenum(swizzle_mode)));
  }

  void swizzleG(SwizzleMode swizzle_mode) {
    gl(TexParameteri(target_, GL_TEXTURE_SWIZZLE_G, GLenum(swizzle_mode)));
  }

  void swizzleB(SwizzleMode swizzle_mode) {
    gl(TexParameteri(target_, GL_TEXTURE_SWIZZLE_B, GLenum(swizzle_mode)));
  }

  void swizzleA(SwizzleMode swizzle_mode) {
    gl(TexParameteri(target_, GL_TEXTURE_SWIZZLE_A, GLenum(swizzle_mode)));
  }


  void swizzleRGBA(SwizzleMode swizzle_mode) {
    const GLint swizzle_array[4] = {GLint(swizzle_mode), GLint(swizzle_mode),
                                    GLint(swizzle_mode), GLint(swizzle_mode)};
    gl(TexParameteriv(target_, GL_TEXTURE_SWIZZLE_RGBA, swizzle_array));
  }

  /// Sets the anisotropy extension to a desired value.
  void anisotropy(float value) {
    #if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_MAX_ANISOTROPY_EXT)
      gl(TexParameterf(target_, GL_TEXTURE_MAX_ANISOTROPY_EXT, value));
    #endif
  }

  void maxAnisotropy() {
    #if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_MAX_ANISOTROPY_EXT)
      GLfloat max_aniso = 0.0f;
      gl(GetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &max_aniso));
      gl(TexParameterf(target_, GL_TEXTURE_MAX_ANISOTROPY_EXT, max_aniso));
    #endif
  }

#if OGLWRAP_DEFINE_EVERYTHING || defined(glTexBuffer)
  /// Assigns a buffer storing the texel data to the texture.
  void buffer(PixelDataInternalFormat internal_format,
              const TextureBuffer& buffer) {
    gl(TexBuffer(target_, GLenum(internal_format), buffer.handle));
  }
#endif

  /// Sets the compare mode.
  void compareMode(enums::CompareMode mode) {
    gl(TexParameteri(target_, GL_TEXTURE_COMPARE_MODE, GLenum(mode)));
  }

  /// Sets the compare function.
  void compareFunc(enums::CompareFunc func) {
    gl(TexParameteri(target_, GL_TEXTURE_COMPARE_FUNC, GLenum(func)));
  }

 protected:
  const GLenum target_;

 private:
  GLuint last_binding_;
  bool moved_;
};

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_TEXTURES_TEXUTRE_BASE_H_
