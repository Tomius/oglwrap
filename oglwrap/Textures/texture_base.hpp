#ifndef TEXUTRE_BASE_HPP
#define TEXTURE_BASE_HPP

#pragma once // Header guard doesn't seem to work here :(

#include <string>
#include <GL/glew.h>

#include "../error.hpp"
#include "../enums.hpp"
#include "../general.hpp"

#ifndef OGLWRAP_IMAGEMAGICK
#define OGLWRAP_IMAGEMAGICK 0
#endif

#if OGLWRAP_IMAGEMAGICK
#include <ImageMagick/Magick++.h>
#endif

namespace oglwrap {

// -------======{[ TextureBase declaration ]}======-------

template <TexType texture_t>
class TextureBase : protected RefCounted {
    GLuint texture;
public:
    TextureBase();
    ~TextureBase();
    void Bind();
    static void Unbind();
    static void Active(GLuint texUnit);
    static void GenerateMipmap();
    static void BorderColor(glm::vec4 color);
    static void MinFilter(MinF filtermode);
    static void MagFilter(MagF filtermode);
    static void WrapS(Wrap wrapmode);
    static void WrapT(Wrap wrapmode);
    static void WrapR(Wrap wrapmode);
    static void SwizzleR(Swizzle swizzlemode);
    static void SwizzleG(Swizzle swizzlemode);
    static void SwizzleB(Swizzle swizzlemode);
    static void SwizzleA(Swizzle swizzlemode);
    static void SwizzleRGBA(Swizzle swizzlemode);
    static void Anisotropy(float value);
    static void Buffer(PixelDataInternalFormat internalFormat, const TextureBuffer& buffer);
};

//         //=====:==-==-==:=====\\                                   //=====:==-==-==:=====\\
//  <---<}>==~=~=~==--==--==~=~=~==<{>----- Class definitions -----<}>==~=~=~==--==--==~=~=~==<{>--->
//         \\=====:==-==-==:=====//                                   \\=====:==-==-==:=====//


// -------======{[ TextureBase definition ]}======-------

template <TexType texture_t>
TextureBase<texture_t>::TextureBase() {
    glGenTextures(1, &texture);
    oglwrap_CheckError();
}

template <TexType texture_t>
TextureBase<texture_t>::~TextureBase() {
    if(!isDeleteable())
        return;
    glDeleteTextures(1, &texture);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::Bind() {
    glBindTexture(texture_t, texture);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::Unbind() {
    glBindTexture(texture_t, 0);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::Active(GLuint texUnit) {
    glActiveTexture(GL_TEXTURE0 + texUnit);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::WrapS(Wrap wrapmode) {
    glTexParameteri(texture_t, GL_TEXTURE_WRAP_S, wrapmode);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::WrapT(Wrap wrapmode) {
    glTexParameteri(texture_t, GL_TEXTURE_WRAP_T, wrapmode);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::WrapR(Wrap wrapmode) {
    glTexParameteri(texture_t, GL_TEXTURE_WRAP_R, wrapmode);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::MinFilter(MinF filtermode) {
    glTexParameteri(texture_t, GL_TEXTURE_MIN_FILTER, filtermode);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::MagFilter(MagF filtermode) {
    glTexParameteri(texture_t, GL_TEXTURE_MAG_FILTER, filtermode);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::GenerateMipmap() {
    glGenerateMipmap(texture_t);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::SwizzleR(Swizzle swizzlemode) {
    glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_R, swizzlemode);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::SwizzleG(Swizzle swizzlemode) {
    glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_G, swizzlemode);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::SwizzleB(Swizzle swizzlemode) {
    glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_B, swizzlemode);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::SwizzleA(Swizzle swizzlemode) {
    glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_A, swizzlemode);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::SwizzleRGBA(Swizzle swizzlemode) {
    glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_RGBA, swizzlemode);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::BorderColor(glm::vec4 color) {
    glTexParameterfv(texture_t, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color));
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::Anisotropy(float value) {
    glTexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, value);
    oglwrap_CheckError();
}

template <TexType texture_t>
void TextureBase<texture_t>::Buffer(PixelDataInternalFormat internalFormat, const TextureBuffer& buffer) {
    glTexBuffer(texture_t, internalFormat, buffer.Expose());
    oglwrap_CheckError();
}

} // namespace oglwrap

#endif // TEXUTRE_BASE
