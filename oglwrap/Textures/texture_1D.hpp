#ifndef TEXUTRE_1D_HPP
#define TEXTURE_1D_HPP

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

// -------======{[ Texture1D declaration ]}======-------

class Texture1D : public TextureBase<TexType::Tex1D> {
public:
    // Uploads
    static void Upload(
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void Upload_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void SubUpload(
        GLint xOffset,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void SubUpload_Mipmap(
        GLint level,
        GLint xOffset,
        GLsizei width,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    // Copies
    static void Copy(
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width
    );

    static void Copy_Mipmap(
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width
    );

    static void CopySub(
        GLint xOffset,
        GLint x,
        GLint y,
        GLsizei width
    );

    static void CopySub_Mipmap(
        GLint level,
        GLint xOffset,
        GLint x,
        GLint y,
        GLsizei width
    );

    // Size getter
    static GLsizei Width(GLint level = 0);

    // Get compressed image
    static void GetCompressedImage(GLint level, GLvoid* img);
};

/*         //=====:==-==-==:=====\\                                   //=====:==-==-==:=====\\
    <---<}>==~=~=~==--==--==~=~=~==<{>----- Class definitions -----<}>==~=~=~==--==--==~=~=~==<{>--->
           \\=====:==-==-==:=====//                                   \\=====:==-==-==:=====//         */


// -------======{[ Texture1D definition ]}======-------

// Uploads
inline void Texture1D::Upload(
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexImage1D(
        TexType::Tex1D, 0, internalFormat, width, 0, format, type, data
    );
    oglwrap_CheckError();
}

inline void Texture1D::Upload_Mipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexImage1D(
        TexType::Tex1D, level, internalFormat, width, 0, format, type, data
    );
    oglwrap_CheckError();
}

inline void Texture1D::SubUpload(
    GLint xOffset,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexSubImage1D(
        TexType::Tex1D, 0, xOffset, width, format, type, data
    );
    oglwrap_CheckError();
}

inline void Texture1D::SubUpload_Mipmap(
    GLint level,
    GLint xOffset,
    GLsizei width,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexSubImage1D(
        TexType::Tex1D, level, xOffset, width, format, type, data
    );
    oglwrap_CheckError();
}

// Copies
inline void Texture1D::Copy(
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width
) {
    glCopyTexImage1D(
        TexType::Tex1D, 0, internalFormat, x, y, width, 0
    );
    oglwrap_CheckError();
}

inline void Texture1D::Copy_Mipmap(
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width
) {
    glCopyTexImage1D(
        TexType::Tex1D, level, internalFormat, x, y, width, 0
    );
    oglwrap_CheckError();
}

inline void Texture1D::CopySub(
    GLint xOffset,
    GLint x,
    GLint y,
    GLsizei width
) {
    glCopyTexSubImage1D(
        TexType::Tex1D, 0, xOffset, x, y, width
    );
    oglwrap_CheckError();
}

inline void Texture1D::CopySub_Mipmap(
    GLint level,
    GLint xOffset,
    GLint x,
    GLint y,
    GLsizei width
) {
    glCopyTexSubImage1D(
        TexType::Tex1D, level, xOffset, x, y, width
    );
    oglwrap_CheckError();
}

// Size getter
inline GLsizei Texture1D::Width(GLint level) {
    GLsizei data;
    glGetTexLevelParameteriv(TexType::Tex1D, level, GL_TEXTURE_WIDTH, &data);
    oglwrap_CheckError();
    return data;
}

// Get compressed image
inline void Texture1D::GetCompressedImage(GLint level, GLvoid* img) {
    glGetCompressedTexImage(TexType::Tex1D, level, img);
    oglwrap_CheckError();
}

} // namespace oglwrap

#endif // TEXTURE_1D
