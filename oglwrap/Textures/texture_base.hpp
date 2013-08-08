#ifndef TEXUTRE_BASE_HPP
#define TEXTURE_BASE_HPP

#pragma once

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
    TextureBase() {
        glGenTextures(1, &texture);
        oglwrap_CheckError();
    }

    ~TextureBase() {
        if(!isDeletable())
            return;
        glDeleteTextures(1, &texture);
        oglwrap_CheckError();
    }

    void Bind() {
        glBindTexture(texture_t, texture);
        oglwrap_CheckError();
    }

    static void Unbind() {
        glBindTexture(texture_t, 0);
        oglwrap_CheckError();
    }

    static void Active(GLuint texUnit) {
        glActiveTexture(GL_TEXTURE0 + texUnit);
        oglwrap_CheckError();
    }

    static void GenerateMipmap() {
        glGenerateMipmap(texture_t);
        oglwrap_CheckError();
    }

    static void BorderColor(glm::vec4 color) {
        glTexParameterfv(texture_t, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color));
        oglwrap_CheckError();
    }

    static void MinFilter(MinF filtermode){
        glTexParameteri(texture_t, GL_TEXTURE_MIN_FILTER, filtermode);
        oglwrap_CheckError();
    }

    static void MagFilter(MagF filtermode){
        glTexParameteri(texture_t, GL_TEXTURE_MAG_FILTER, filtermode);
        oglwrap_CheckError();
    }

    static void WrapS(Wrap wrapmode) {
        glTexParameteri(texture_t, GL_TEXTURE_WRAP_S, wrapmode);
        oglwrap_CheckError();
    }

    static void WrapT(Wrap wrapmode) {
        glTexParameteri(texture_t, GL_TEXTURE_WRAP_T, wrapmode);
        oglwrap_CheckError();
    }

    static void WrapR(Wrap wrapmode) {
        glTexParameteri(texture_t, GL_TEXTURE_WRAP_R, wrapmode);
        oglwrap_CheckError();
    }

    static void SwizzleR(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_R, swizzlemode);
        oglwrap_CheckError();
    }

    static void SwizzleG(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_G, swizzlemode);
        oglwrap_CheckError();
    }

    static void SwizzleB(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_B, swizzlemode);
        oglwrap_CheckError();
    }

    static void SwizzleA(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_A, swizzlemode);
        oglwrap_CheckError();
    }

    static void SwizzleRGBA(Swizzle swizzlemode) {
        glTexParameteri(texture_t, GL_TEXTURE_SWIZZLE_RGBA, swizzlemode);
        oglwrap_CheckError();
    }

    static void Anisotropy(float value) {
        glTexParameterf(texture_t, GL_TEXTURE_MAX_ANISOTROPY_EXT, value);
        oglwrap_CheckError();
    }
    static void Buffer(PixelDataInternalFormat internalFormat, const TextureBuffer& buffer) {
        glTexBuffer(texture_t, internalFormat, buffer.Expose());
        oglwrap_CheckError();
    }
};

} // namespace oglwrap

#endif // TEXUTRE_BASE
