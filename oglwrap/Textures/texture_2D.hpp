#ifndef TEXUTRE_2D_HPP
#define TEXTURE_2D_HPP

#include <string>
#include <GL/glew.h>

#include "../error.hpp"
#include "../enums.hpp"
#include "../general.hpp"
#include "texture_base.hpp"

#ifndef OGLWRAP_IMAGEMAGICK
#define OGLWRAP_IMAGEMAGICK 0
#endif
#if OGLWRAP_IMAGEMAGICK
#include <ImageMagick/Magick++.h>
#endif

namespace oglwrap {

// -------======{[ 2D Textures' declaration ]}======-------

template<Tex2DType texture_t>
class _Texture2D : public TextureBase<TexType(texture_t)> {
public:
    // Uploads
    static void Upload(
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void Upload_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void SubUpload(
        GLint xOffset,
        GLint yOffset,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void SubUpload_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    // Copies
    static void Copy(
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    );

    static void Copy_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    );

    static void CopySub(
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    );

    static void CopySub_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    );

    // Size getters
    static GLsizei Width(GLint level = 0);
    static GLsizei Height(GLint level = 0);

    // Get compressed image
    static void GetCompressedImage(GLint level, GLvoid* img);

#if OGLWRAP_IMAGEMAGICK
    static void LoadTexture(const std::string& file, const std::string& formatString = "RGBA");
#endif
};

typedef _Texture2D<Tex2DType::Tex2D> Texture2D;
typedef _Texture2D<Tex2DType::TexRect> TextureRect;
typedef _Texture2D<Tex2DType::Tex1DArray> Texture1D_Array;


//         //=====:==-==-==:=====\\                                   //=====:==-==-==:=====\\
//  <---<}>==~=~=~==--==--==~=~=~==<{>----- Class definitions -----<}>==~=~=~==--==--==~=~=~==<{>--->
//         \\=====:==-==-==:=====//                                   \\=====:==-==-==:=====//



// Uploads
template<Tex2DType texture_t>
void _Texture2D<texture_t>::Upload(
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexImage2D(
        texture_t, 0, internalFormat, width, height, 0, format, type, data
    );
    oglwrap_CheckError();
}

template<Tex2DType texture_t>
void _Texture2D<texture_t>::Upload_Mipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexImage2D(
        texture_t, level, internalFormat, width, height, 0, format, type, data
    );
    oglwrap_CheckError();
}

template<Tex2DType texture_t>
void _Texture2D<texture_t>::SubUpload(
    GLint xOffset,
    GLint yOffset,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexSubImage2D(
        texture_t, 0, xOffset, yOffset, width, height, format, type, data
    );
    oglwrap_CheckError();
}

template<Tex2DType texture_t>
void _Texture2D<texture_t>::SubUpload_Mipmap(
    GLint level,
    GLint xOffset,
    GLint yOffset,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexSubImage2D(
        texture_t, level, xOffset, yOffset, width, height, format, type, data
    );
    oglwrap_CheckError();
}

// Copies
template<Tex2DType texture_t>
void _Texture2D<texture_t>::Copy(
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
) {
    glCopyTexImage2D(texture_t, 0, internalFormat, x, y, width, height, 0);
    oglwrap_CheckError();
}

template<Tex2DType texture_t>
void _Texture2D<texture_t>::Copy_Mipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
) {
    glCopyTexImage2D(texture_t, level, internalFormat, x, y, width, height, 0);
    oglwrap_CheckError();
}

template<Tex2DType texture_t>
void _Texture2D<texture_t>::CopySub(
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
) {
    glCopyTexSubImage2D(texture_t, 0, xOffset, yOffset, x, y, width, height);
    oglwrap_CheckError();
}

template<Tex2DType texture_t>
void _Texture2D<texture_t>::CopySub_Mipmap(
    GLint level,
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
) {
    glCopyTexSubImage2D(texture_t, level, xOffset, yOffset, x, y, width, height);
    oglwrap_CheckError();
}

// Size getters
template<Tex2DType texture_t>
GLsizei _Texture2D<texture_t>::Width(GLint level) {
    GLsizei data;
    glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_WIDTH, &data);
    oglwrap_CheckError();
    return data;
}

template<Tex2DType texture_t>
GLsizei _Texture2D<texture_t>::Height(GLint level) {
    GLsizei data;
    glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_HEIGHT, &data);
    oglwrap_CheckError();
    return data;
}

// Get compressed image
template<Tex2DType texture_t>
void _Texture2D<texture_t>::GetCompressedImage(GLint level, GLvoid* img) {
    glGetCompressedTexImage(TexType::Tex2D, level, img);
    oglwrap_CheckError();
}

#if OGLWRAP_IMAGEMAGICK
template<Tex2DType texture_t>
void _Texture2D<texture_t>::LoadTexture(const std::string& file, const std::string& formatString) {
    try {
        Magick::Image image = Magick::Image(file);
        Magick::Blob blob;
        image.write(&blob, formatString);

        Upload(
            PixelDataInternalFormat::SRGBA8,
            image.columns(),
            image.rows(),
            PixelDataFormat::RGBA,
            PixelDataType::UnsignedByte,
            blob.data()
        );
    } catch(Magick::Error& Error) {
        std::cerr << "Error loading texture: " << Error.what() << std::endl;
    }
}
#endif

} // namespace oglwrap

#endif // TEXTURE_2D
