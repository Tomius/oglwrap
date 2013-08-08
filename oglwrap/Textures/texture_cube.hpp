#ifndef TEXUTRE_CUBE_HPP
#define TEXTURE_CUBE_HPP

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

// -------======{[ TextureCube declaration ]}======-------

class TextureCube : public TextureBase<TexType::TexCubeMap> {
public:
    // uploads
    static void Upload(
        CubeTarget target,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void Upload_Mipmap(
        CubeTarget target,
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void SubUpload(
        CubeTarget target,
        GLint xOffset,
        GLint yOffset,
        GLsizei width,
        GLsizei height,
        PixelDataFormat format,
        PixelDataType type,
        const void *data
    );

    static void SubUpload_Mipmap(
        CubeTarget target,
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
        CubeTarget target,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    );

    static void Copy_Mipmap(
        CubeTarget target,
        GLint level,
        PixelDataInternalFormat internalFormat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    );

    static void CopySub(
        CubeTarget target,
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    );

    static void CopySub_Mipmap(
        CubeTarget target,
        GLint level,
        GLint xOffset,
        GLint yOffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height
    );

    // Size getters
    static GLsizei Width(CubeTarget target, GLint level = 0);
    static GLsizei Height(CubeTarget target, GLint level = 0);

    // Cube face indexing
    static CubeTarget CubeFace(int i);

    // compressed image getter
    static void GetCompressedImage(CubeTarget target, GLint level, GLvoid* img);

#if OGLWRAP_IMAGEMAGICK
    static void LoadTexture(CubeTarget target,
                            const std::string& file,
                            const std::string& formatString = "RGBA");

    static void LoadTexture(GLuint faceID,
                            const std::string& file,
                            const std::string& formatString = "RGBA");
#endif
};



/*         //=====:==-==-==:=====\\                                   //=====:==-==-==:=====\\
    <---<}>==~=~=~==--==--==~=~=~==<{>----- Class definitions -----<}>==~=~=~==--==--==~=~=~==<{>--->
           \\=====:==-==-==:=====//                                   \\=====:==-==-==:=====//         */



// -------======{[ TextureCube definition ]}======-------

// uploads
inline void TextureCube::Upload(
    CubeTarget target,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexImage2D(
        target, 0, internalFormat, width, height, 0, format, type, data
    );
    oglwrap_CheckError();
}

inline void TextureCube::Upload_Mipmap(
    CubeTarget target,
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexImage2D(
        target, level, internalFormat, width, height, 0, format, type, data
    );
    oglwrap_CheckError();
}

inline void TextureCube::SubUpload(
    CubeTarget target,
    GLint xOffset,
    GLint yOffset,
    GLsizei width,
    GLsizei height,
    PixelDataFormat format,
    PixelDataType type,
    const void *data
) {
    glTexSubImage2D(
        target, 0, xOffset, yOffset, width, height, format, type, data
    );
    oglwrap_CheckError();
}

inline void TextureCube::SubUpload_Mipmap(
    CubeTarget target,
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
        target, level, xOffset, yOffset, width, height, format, type, data
    );
    oglwrap_CheckError();
}

// Copies
inline void TextureCube::Copy(
    CubeTarget target,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
) {
    glCopyTexImage2D(target, 0, internalFormat, x, y, width, height, 0);
    oglwrap_CheckError();
}

inline void TextureCube::Copy_Mipmap(
    CubeTarget target,
    GLint level,
    PixelDataInternalFormat internalFormat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
) {
    glCopyTexImage2D(target, level, internalFormat, x, y, width, height, 0);
    oglwrap_CheckError();
}

inline void TextureCube::CopySub(
    CubeTarget target,
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
) {
    glCopyTexSubImage2D(target, 0, xOffset, yOffset, x, y, width, height);
    oglwrap_CheckError();
}

inline void TextureCube::CopySub_Mipmap(
    CubeTarget target,
    GLint level,
    GLint xOffset,
    GLint yOffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height
) {
    glCopyTexSubImage2D(target, level, xOffset, yOffset, x, y, width, height);
    oglwrap_CheckError();
}

// Size getters
inline GLsizei TextureCube::Width(CubeTarget target, GLint level) {
    GLsizei data;
    glGetTexLevelParameteriv(target, level, GL_TEXTURE_WIDTH, &data);
    oglwrap_CheckError();
    return data;
}

inline GLsizei TextureCube::Height(CubeTarget target, GLint level) {
    GLsizei data;
    glGetTexLevelParameteriv(target, level, GL_TEXTURE_HEIGHT, &data);
    oglwrap_CheckError();
    return data;
}

// Cube face indexing
inline CubeTarget TextureCube::CubeFace(int i) {
    switch(i) {
        case 0:
            return CubeTarget::PosX;
        case 1:
            return CubeTarget::NegX;
        case 2:
            return CubeTarget::PosY;
        case 3:
            return CubeTarget::NegY;
        case 4:
            return CubeTarget::PosZ;
        case 5:
            return CubeTarget::NegZ;
        default:
            throw std::invalid_argument("CubeFace argument must be between 0 and 5");
    }
}

// compressed image getter
inline void TextureCube::GetCompressedImage(CubeTarget target, GLint level, GLvoid* img) {
    glGetCompressedTexImage(target, level, img);
    oglwrap_CheckError();
}

#if OGLWRAP_IMAGEMAGICK
inline void TextureCube::LoadTexture(CubeTarget target,
                                     const std::string& file,
                                     const std::string& formatString) {
    try {
        Magick::Image image = Magick::Image(file);
        Magick::Blob blob;
        image.write(&blob, formatString);

        Upload(
            target,
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

inline void TextureCube::LoadTexture(GLuint faceID,
                                     const std::string& file,
                                     const std::string& formatString) {
    try {
        Magick::Image image = Magick::Image(file);
        Magick::Blob blob;
        image.write(&blob, formatString);

        Upload(
            CubeFace(faceID),
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

#endif // TEXTURE_CUBE

