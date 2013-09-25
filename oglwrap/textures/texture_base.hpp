/** @file texture_base.hpp
    @brief Implements the base functionality for textures.
*/

#pragma once

namespace oglwrap {

// -------======{[ TextureBase declaration ]}======-------

template <TexType texture_t>
/// This class is implementing the base functions for textures.
/** You shouldn't use this class directly.
  * glGenTextures, glDeleteTextures */
class TextureBase {
protected:
  Object<glGenTextures, glDeleteTextures> texture; ///< The handle for the texture.
public:
  /// Generates an empty texture.
  TextureBase() {}

  template <TexType another_texture_t>
  /// Creates a copy of the texture, or casts it to another type.
  /** Important: if you use this to change the type of the active texture,
    * don't forget to unbind the old one, and bind the new one */
  TextureBase(const TextureBase<another_texture_t>& srctexture)
    : texture(srctexture.expose()) {
  }

  /// Binds the texture to this texture class's target.
  /** @see glBindTexture */
  void bind() const {
    gl(BindTexture(texture_t, texture));
  }

  /// Unbinds the texture from this texture class's target.
  /** @see glBindTexture */
  static void Unbind() {
    gl(BindTexture(texture_t, 0));
  }
  /// Unbinds the texture from this texture class's target.
  /** @see glBindTexture */
  BIND_CHECKED void unbind() {
    CHECK_BINDING2();
    Unbind();
  }

  /// Returns if this is the currently bound texture for its target.
  /** @see glGetIntegerv */
  bool isBound() const {
    GLint currentlyBoundTexture;
    gl(GetIntegerv(getBindingTarget(texture_t), &currentlyBoundTexture));
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

#if !OGLWRAP_CHECK_DEPENDENCIES || defined(glGenerateMipmap)
  /// Generates mipmaps for the currently uploaded image to this texture class.
  /** @see glGenerateMipmap */
  static void GenerateMipmap() {
    gl(GenerateMipmap(texture_t));
  }
  /// Generates mipmaps for the currently uploaded image to this texture class.
  /** @see glGenerateMipmap */
  BIND_CHECKED void generateMipmap() const {
    CHECK_BINDING();
    GenerateMipmap();
  }
#endif

  /// Sets the border color for this texture class.
  /** @param color - Specifies the value, the border color should be set to.
    * @see glTexParameterfv, GL_TEXTURE_BORDER_COLOR */
  static void BorderColor(glm::vec4 color) {
    gl(TexParameterfv(texture_t, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color)));
  }
  /// Sets the border color for this texture class.
  /** @param color - Specifies the value, the border color should be set to.
    * @see glTexParameterfv, GL_TEXTURE_BORDER_COLOR */
  BIND_CHECKED void borderColor(glm::vec4 color) const {
    CHECK_BINDING();
    BorderColor(color);
  }

  /// Sets the minification filter for this texture class.
  /** @param filtermode - The desired minification filter mode.
    * @see glTexParameteri, GL_TEXTURE_MIN_FILTER */
  static void MinFilter(Enums::MinFilter filtermode) {
    gl(TexParameteri(texture_t, GL_TEXTURE_MIN_FILTER, filtermode));
  }
  /// Sets the minification filter for this texture class.
  /** @param filtermode - The desired minification filter mode.
    * @see glTexParameteri, GL_TEXTURE_MIN_FILTER */
  BIND_CHECKED void minFilter(Enums::MinFilter filtermode) const {
    CHECK_BINDING();
    MinFilter(filtermode);
  }

  /// Sets the magnification filter for this texture class.
  /** @param filtermode - The desired magnification filter mode.
    * @see glTexParameteri, GL_TEXTURE_MAG_FILTER */
  static void MagFilter(Enums::MagFilter filtermode) {
    gl(TexParameteri(texture_t, GL_TEXTURE_MAG_FILTER, filtermode));
  }
  /// Sets the magnification filter for this texture class.
  /** @param filtermode - The desired magnification filter mode.
    * @see glTexParameteri, GL_TEXTURE_MAG_FILTER */
  BIND_CHECKED void magFilter(Enums::MagFilter filtermode) const {
    CHECK_BINDING();
    MagFilter(filtermode);
  }

  /// Sets the way, OpenGL should handle if the texture coordinate's 's' (first) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_S */
  static void WrapS(Wrap wrapmode) {
    gl(TexParameteri(texture_t, GL_TEXTURE_WRAP_S, wrapmode));
  }
  /// Sets the way, OpenGL should handle if the texture coordinate's 's' (first) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_S */
  BIND_CHECKED void wrapS(Wrap wrapmode) const {
    CHECK_BINDING();
    WrapS(wrapmode);
  }

  /// Sets the way, OpenGL should handle if the texture coordinate's 't' (second) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_T */
  static void WrapT(Wrap wrapmode) {
    gl(TexParameteri(texture_t, GL_TEXTURE_WRAP_T, wrapmode));
  }
  /// Sets the way, OpenGL should handle if the texture coordinate's 't' (second) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_T */
  BIND_CHECKED void wrapT(Wrap wrapmode) const {
    CHECK_BINDING();
    WrapT(wrapmode);
  }

  /// Sets the way, OpenGL should handle if the texture coordinate's 'p' (third) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_R */
  static void WrapR(Wrap wrapmode) {
    gl(TexParameteri(texture_t, GL_TEXTURE_WRAP_R, wrapmode));
  }
  /// Sets the way, OpenGL should handle if the texture coordinate's 'p' (third) part is out of the [0, 1] range for this texture class.
  /** @param wrapmode - The desired wrapping mode.
    * @see glTexParameteri, GL_TEXTURE_WRAP_R */
  BIND_CHECKED void wrapR(Wrap wrapmode) const {
    CHECK_BINDING();
    WrapR(wrapmode);
  }

  /// Sets what OpenGL should do if you write texture.r for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_R */
  static void SwizzleR(Swizzle swizzleMode) {
    gl(TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_R, swizzleMode));
  }
  /// Sets what OpenGL should do if you write texture.r for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_R */
  BIND_CHECKED void swizzleR(Swizzle swizzleMode) const {
    CHECK_BINDING();
    SwizzleR(swizzleMode);
  }

  /// Sets what OpenGL should do if you write texture.g for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_G */
  static void SwizzleG(Swizzle swizzleMode) {
    gl(TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_G, swizzleMode));
  }
  /// Sets what OpenGL should do if you write texture.g for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_G */
  BIND_CHECKED void swizzleG(Swizzle swizzleMode) const {
    CHECK_BINDING();
    SwizzleG(swizzleMode);
  }

  /// Sets what OpenGL should do if you write texture.b for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_B */
  static void SwizzleB(Swizzle swizzleMode) {
    gl(TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_B, swizzleMode));
  }
  /// Sets what OpenGL should do if you write texture.b for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_B */
  BIND_CHECKED void swizzleB(Swizzle swizzleMode) const {
    CHECK_BINDING();
    SwizzleB(swizzleMode);
  }

  /// Sets what OpenGL should do if you write texture.a for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_A */
  static void SwizzleA(Swizzle swizzleMode) {
    gl(TexParameteri(texture_t, GL_TEXTURE_SWIZZLE_A, swizzleMode));
  }
  /// Sets what OpenGL should do if you write texture.a for a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteri, GL_TEXTURE_SWIZZLE_A */
  BIND_CHECKED void swizzleA(Swizzle swizzleMode) const {
    CHECK_BINDING();
    SwizzleA(swizzleMode);
  }

  /// Sets what OpenGL should do if you use the swizzle operator to select either of the 4 components from a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteriv, GL_TEXTURE_SWIZZLE_RGBA */
  static void SwizzleRGBA(Swizzle swizzleMode) {
    const GLint swizzle_array[4] = {swizzleMode, swizzleMode, swizzleMode, swizzleMode};
    gl(TexParameteriv(texture_t, GL_TEXTURE_SWIZZLE_RGBA, swizzle_array));
  }
  /// Sets what OpenGL should do if you use the swizzle operator to select either of the 4 components from a texture of this class in a shader.
  /** @param swizzleMode - The desired swizzle mode.
    * @see glTexParameteriv, GL_TEXTURE_SWIZZLE_RGBA */
  BIND_CHECKED void swizzleRGBA(Swizzle swizzleMode) const {
    CHECK_BINDING();
    SwizzleRGBA(swizzleMode);
  }

  /// Sets the anisotropy extension to a desired value.
  /** It doesn't do anything if anisotropy is not supported
    * @param value - The desired anisotropy value.
    * @see glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT */
  static void Anisotropy(float value) {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_MAX_ANISOTROPY_EXT)
    gl(TexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, value));
#endif
  }
  /// Sets the anisotropy extension to a desired value.
  /** It doesn't do anything if anisotropy is not supported
    * @param value - The desired anisotropy value.
    * @see glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT */
  BIND_CHECKED void anisotropy(float value) const {
    CHECK_BINDING();
    Anisotropy(value);
  }

  /// Sets the anisotropy extension to the maximum value possible on this hardware.
  /** It doesn't do anything if anisotropy is not supported
    * @see glGetFloatv, glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT */
  static void MaxAnisotropy() {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_MAX_ANISOTROPY_EXT)
    GLfloat maxAniso = 0.0f;
    gl(GetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAniso));
    gl(TexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAniso));
#endif // GL_TEXTURE_MAX_ANISOTROPY_EXT
  }
  /// Sets the anisotropy extension to the maximum value possible on this hardware.
  /** It doesn't do anything if anisotropy is not supported
    * @see glGetFloatv, glTexParameterf, GL_TEXTURE_MAX_ANISOTROPY_EXT */
  BIND_CHECKED void maxAnisotropy() const {
    CHECK_BINDING();
    MaxAnisotropy();
  }

#if !OGLWRAP_CHECK_DEPENDENCIES || (defined(glGenBuffers) && defined(glDeleteBuffers) && defined(GL_TEXTURE_BUFFER))
  /// Assigns a buffer storing the texel data to the texture.
  /** @param internalFormat - Specifies the internal format of the data in the store belonging to buffer. It must be a sized, uncompressed internal format.
    * @param buffer - Specifies the name of the buffer object whose storage to attach to the active buffer texture.
    * @see glTexBuffer */
  static void Buffer(PixelDataInternalFormat internalFormat, const TextureBuffer& buffer) {
    gl(TexBuffer(texture_t, internalFormat, buffer.expose()));
  }
  /// Assigns a buffer storing the texel data to the texture.
  /** @param internalFormat - Specifies the internal format of the data in the store belonging to buffer. It must be a sized, uncompressed internal format.
    * @param buffer - Specifies the name of the buffer object whose storage to attach to the active buffer texture.
    * @see glTexBuffer */
  BIND_CHECKED void buffer(PixelDataInternalFormat internalFormat, const TextureBuffer& buffer) const {
    CHECK_BINDING();
    Buffer(internalFormat, buffer);
  }
#endif

  /// Sets the compare mode.
  /** @param mode - The desired compare mode.
    * @see glTexParameteri, GL_TEXTURE_COMPARE_MODE */
  static void CompareMode(CompMode mode) {
    gl(TexParameteri(texture_t, GL_TEXTURE_COMPARE_MODE, mode));
  }
  /// Sets the compare mode.
  /** @param mode - The desired compare mode.
    * @see glTexParameteri, GL_TEXTURE_COMPARE_MODE */
  BIND_CHECKED void compareMode(CompMode mode) const {
    CHECK_BINDING();
    CompareMode(mode);
  }

  /// Sets the compare function.
  /** @param func - The desired compare function.
    * @see glTexParameteri, GL_TEXTURE_COMPARE_FUNC */
  static void CompareFunc(CompFunc func) {
    gl(TexParameteri(texture_t, GL_TEXTURE_COMPARE_FUNC, func));
  }
  /// Sets the compare function.
  /** @param func - The desired compare function.
    * @see glTexParameteri, GL_TEXTURE_COMPARE_FUNC */
  BIND_CHECKED void compareFunc(CompFunc func) const {
    CHECK_BINDING();
    CompareFunc(func);
  }

  /// Returns the handle for the texture.
  const Object<glGenTextures, glDeleteTextures>& expose() const {
    return texture;
  }
};

} // namespace oglwrap


