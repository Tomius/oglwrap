#ifndef TEXUTRE_3D_HPP
#define TEXTURE_3D_HPP

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

// -------======{[ 3D Textures' declaration ]}======-------

template<Tex3DType texture_t>
class _Texture3D : public TextureBase<TexType(texture_t)> {
public:
    // Uploads
    static void Upload(
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void Upload_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void SubUpload(
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void SubUpload_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLsizei width,
        GLsizei height,
        GLsizei depth,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    // Copies
    static void CopySub(
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    );

    static void CopySub_Mipmap(
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint zOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    );

    // Size getters
    static GLsizei Width(GLint level = 0);
    static GLsizei Height(GLint level = 0);
    static GLsizei Depth(GLint level = 0);

    // compressed image getter
    static void GetCompressedImage(GLint level, GLvoid* img);
};

typedef _Texture3D<Tex3DType::Tex3D> Texture3D;
typedef _Texture3D<Tex3DType::Tex2DArray> Texture2D_Array;



/*         //=====:==-==-==:=====\\                                   //=====:==-==-==:=====\\
    <---<}>==~=~=~==--==--==~=~=~==<{>----- Class definitions -----<}>==~=~=~==--==--==~=~=~==<{>--->
           \\=====:==-==-==:=====//                                   \\=====:==-==-==:=====//         */



// -------======{[ 3D Textures' definition ]}======-------

// Uploads
template<Tex3DType texture_t>
void _Texture3D<texture_t>::Upload(
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexImage3D(
        texture_t, 0, internalFormat, width, height, depth, 0, format, type, data
    );
    oglwrap_CheckError();
}

template<Tex3DType texture_t>
void _Texture3D<texture_t>::Upload_Mipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexImage3D(
        texture_t, level, internalFormat, width, height, depth, 0, format, type, data
    );
    oglwrap_CheckError();
}

template<Tex3DType texture_t>
void _Texture3D<texture_t>::SubUpload(
    GLint xOffset,
    GLint yOffset,
    GLint zOffset,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexSubImage3D(
        texture_t, 0, xOffset, yOffset, zOffset, width, height, depth, format, type, data
    );
    oglwrap_CheckError();
}

template<Tex3DType texture_t>
void _Texture3D<texture_t>::SubUpload_Mipmap(
    GLint level,
    GLint xOffset,
    GLint yOffset,
    GLint zOffset,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexSubImage3D(
        texture_t, level, xOffset, yOffset, zOffset, width, height, depth, format, type, data
    );
    oglwrap_CheckError();
}

// Copies
template<Tex3DType texture_t>
void _Texture3D<texture_t>::CopySub(
    GLint xOffset,
    GLint yOffset,
    GLint zOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
) {
    glCopyTexSubImage3D(texture_t, 0, xOffset, yOffset, zOffset, x, y, width, height);
    oglwrap_CheckError();
}

template<Tex3DType texture_t>
void _Texture3D<texture_t>::CopySub_Mipmap(
    GLint level,
    GLint xOffset,
    GLint yOffset,
    GLint zOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
) {
    glCopyTexSubImage3D(texture_t, level, xOffset, yOffset, zOffset, x, y, width, height);
    oglwrap_CheckError();
}

// Size getters
template<Tex3DType texture_t>
GLsizei _Texture3D<texture_t>::Width(GLint level) {
    GLsizei data;
    glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_WIDTH, &data);
    oglwrap_CheckError();
    return data;
}

template<Tex3DType texture_t>
GLsizei _Texture3D<texture_t>::Height(GLint level) {
    GLsizei data;
    glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_HEIGHT, &data);
    oglwrap_CheckError();
    return data;
}

template<Tex3DType texture_t>
GLsizei _Texture3D<texture_t>::Depth(GLint level) {
    GLsizei data;
    glGetTexLevelParameteriv(texture_t, level, GL_TEXTURE_DEPTH, &data);
    oglwrap_CheckError();
    return data;
}

// compressed image getter
template<Tex3DType texture_t>
void _Texture3D<texture_t>::GetCompressedImage(GLint level, GLvoid* img) {
    glGetCompressedTexImage(TexType::Tex3D, level, img);
    oglwrap_CheckError();
}

} // namespace oglwrap

#endif // TEXTURE_3D
