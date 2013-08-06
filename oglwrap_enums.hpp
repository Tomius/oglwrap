#ifndef OGLWRAP_ENUMS_H
#define OGLWRAP_ENUMS_H

// easter egg :)
#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

namespace oglwrap {

// -------======{[ Shaders ]}======-------

namespace _ShaderType {
enum Enum {
    Compute = GL_COMPUTE_SHADER,
    Vertex = GL_VERTEX_SHADER,
    Geometry = GL_GEOMETRY_SHADER,
    Fragment = GL_FRAGMENT_SHADER,
    TessControl = GL_TESS_CONTROL_SHADER,
    TessEval = GL_TESS_EVALUATION_SHADER
};
};
typedef _ShaderType::Enum ShaderType;

// -------======{[ Vertex Attrib Array ]}======-------

namespace _DataType {
enum Enum {
    Byte = GL_BYTE,
    Short = GL_SHORT,
    Int = GL_INT,
    Fixed = GL_FIXED,
    Float = GL_FLOAT,
    HalfFloat = GL_HALF_FLOAT,
    Double = GL_DOUBLE,
    UnsignedByte = GL_UNSIGNED_BYTE,
    UnsignedShort = GL_UNSIGNED_SHORT,
    UnsignedInt = GL_UNSIGNED_INT
};
};

typedef _DataType::Enum DataType;

// -------======{[ Buffers ]}======-------

namespace _BufferType{
enum Enum{
    Array = GL_ARRAY_BUFFER,
    AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
    CopyRead = GL_COPY_READ_BUFFER,
    CopyWrite = GL_COPY_WRITE_BUFFER,
    DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER,
    DrawIndirect = GL_DRAW_INDIRECT_BUFFER,
    ElementArray = GL_ELEMENT_ARRAY_BUFFER,
    PixelPack = GL_PIXEL_PACK_BUFFER,
    PixelUnpack = GL_PIXEL_UNPACK_BUFFER,
    ShaderStorage = GL_SHADER_STORAGE_BUFFER,
    Texture = GL_TEXTURE_BUFFER,
    TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
    Uniform = GL_UNIFORM_BUFFER,
    Query = GL_QUERY_BUFFER_AMD,
    ExternalVirtualMemory = GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD,
};
}
typedef _BufferType::Enum BufferType;

namespace _BufferUsage{
enum Enum{
    StreamDraw = GL_STREAM_DRAW,
    StreamRead = GL_STREAM_READ,
    StreamCopy = GL_STREAM_COPY,
    StaticDraw = GL_STATIC_DRAW,
    StaticRead = GL_STATIC_READ,
    StaticCopy = GL_STATIC_COPY,
    DynamicDraw = GL_DYNAMIC_DRAW,
    DynamicRead = GL_DYNAMIC_READ,
    DynamicCopy = GL_DYNAMIC_COPY
};
}
typedef _BufferUsage::Enum BufferUsage;


// -------======{[ Textures ]}======-------

namespace _TexType {
enum Enum {
    Tex1D = GL_TEXTURE_1D,
    Tex2D = GL_TEXTURE_2D,
    Tex3D = GL_TEXTURE_3D,
    TexRect = GL_TEXTURE_RECTANGLE,
    Tex1DArray = GL_TEXTURE_1D_ARRAY,
    Tex2DArray = GL_TEXTURE_2D_ARRAY,
    TexCubeMap = GL_TEXTURE_CUBE_MAP,
};
}
typedef _TexType::Enum TexType;

namespace _Tex2DType {
enum Enum {
    Tex2D = GL_TEXTURE_2D,
    Tex1DArray = GL_TEXTURE_1D_ARRAY,
    TexRect = GL_TEXTURE_RECTANGLE
};
}
typedef _Tex2DType::Enum Tex2DType;

namespace _CubeTarget {
enum Enum {
    PosX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
    NegX = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
    PosY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
    NegY = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
    PosZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
    NegZ = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
};
}
typedef _CubeTarget::Enum CubeTarget;

namespace _Tex3DType {
enum Enum {
    Tex3D = GL_TEXTURE_3D,
    Tex2DArray = GL_TEXTURE_2D_ARRAY,
};
}
typedef _Tex3DType::Enum Tex3DType;

// These aren't supported yet.. sorry :(
namespace _ExtraTexType {
enum Enum {
    TexCubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
    Tex2DMultisample = GL_TEXTURE_2D_MULTISAMPLE,
    Tex2DMultisampleArray = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
};
}
typedef _ExtraTexType::Enum ExtraTexType;

namespace _PixelDataInternalFormat {
enum Enum {
    DepthComponent = GL_DEPTH_COMPONENT,
    DepthStencil = GL_DEPTH_STENCIL,
    Red = GL_RED,
    RG = GL_RG,
    RGB = GL_RGB,
    RGBA = GL_RGBA,
    R8 = GL_R8,
    R8_SNorm = GL_R8_SNORM,
    R16 = GL_R16,
    R16_SNorm = GL_R16_SNORM,
    RG8 = GL_RG8,
    RG8_SNorm = GL_RG8_SNORM,
    RG16 = GL_RG16,
    RG16_SNorm = GL_RG16_SNORM,
    R3_G3_B2 = GL_R3_G3_B2,
    RGB4 = GL_RGB4,
    RGB5 = GL_RGB5,
    RGB8 = GL_RGB8,
    RGB8_SNorm = GL_RGB8_SNORM,
    RGB10 = GL_RGB10,
    RGB12 = GL_RGB12,
    RGB16 = GL_RGB16,
    RGB16_SNorm = GL_RGB16_SNORM,
    RGBA2 = GL_RGBA2,
    RGBA4 = GL_RGBA4,
    RGB5A1 = GL_RGB5_A1,
    RGBA8 = GL_RGBA8,
    RGBA8_SNorm = GL_RGBA8_SNORM,
    RGB10_A2 = GL_RGB10_A2,
    RGB10_A2UI = GL_RGB10_A2UI,
    RGBA12 = GL_RGBA12,
    RGBA16 = GL_RGBA16,
    RGBA16_SNorm = GL_RGBA16_SNORM,
    SRGB8 = GL_SRGB8,
    SRGBA8 = GL_SRGB8_ALPHA8,
    R16F = GL_R16F,
    RG16F = GL_RG16F,
    RGB16F = GL_RGB16F,
    RGBA16F = GL_RGBA16F,
    R32F = GL_R32F,
    RG32F = GL_RG32F,
    RGB32F = GL_RGB32F,
    RGBA32F = GL_RGBA32F,
    R11F_G11F_B10F = GL_R11F_G11F_B10F,
    RGB9_E5 = GL_RGB9_E5,
    R8I = GL_R8I,
    R8UI = GL_R8UI,
    R16I = GL_R16I,
    R16UI = GL_R16UI,
    R32I = GL_R32I,
    R32UI = GL_R32UI,
    RG8I = GL_RG8I,
    RG8UI = GL_RG8UI,
    RG16I = GL_RG16I,
    RG16UI = GL_RG16UI,
    RG32I = GL_RG32I,
    RG32UI = GL_RG32UI,
    RGB8I = GL_RGB8I,
    RGB8UI = GL_RGB8UI,
    RGB16I = GL_RGB16I,
    RGB16UI = GL_RGB16UI,
    RGB32I = GL_RGB32I,
    RGB32UI = GL_RGB32UI,
    RGBA8I = GL_RGBA8I,
    RGBA8UI = GL_RGBA8UI,
    RGBA16I = GL_RGBA16I,
    RGBA16UI = GL_RGBA16UI,
    RGBA32I = GL_RGBA32I,
    RGBA32UI = GL_RGBA32UI,
    DepthComponent16 = GL_DEPTH_COMPONENT16,
    DepthComponent24 = GL_DEPTH_COMPONENT24,
    DepthComponent32 = GL_DEPTH_COMPONENT32,
    DepthComponent32F = GL_DEPTH_COMPONENT32F,
    Depth24_Stencil8 = GL_DEPTH24_STENCIL8,
    Depth32f_Stencil8 = GL_DEPTH32F_STENCIL8,
    Compressed_Red = GL_COMPRESSED_RED,
    Compressed_RG = GL_COMPRESSED_RG,
    Compressed_RGB = GL_COMPRESSED_RGB,
    Compressed_RGBA = GL_COMPRESSED_RGBA,
    Compressed_SRGB = GL_COMPRESSED_SRGB,
    Compressed_SRGBA = GL_COMPRESSED_SRGB_ALPHA,
    Compressed_Red_RGTC1 = GL_COMPRESSED_RED_RGTC1,
    Compressed_Signed_Red_RGTC1 = GL_COMPRESSED_SIGNED_RED_RGTC1,
    Compressed_RG_RGTC2 = GL_COMPRESSED_RG_RGTC2,
    Compressed_Signed_RG_RGTC2 = GL_COMPRESSED_SIGNED_RG_RGTC2,
    Compressed_RGBA_BPTC_UNorm = GL_COMPRESSED_RGBA_BPTC_UNORM,
    Compressed_SRGBA_BPTC_UNorm = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
    Compressed_RGB_BPTC_Signed_Float = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
    Compressed_RGB_BPTC_Unsigned_Float = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT,
    Compressed_RGB8_ETC2 = GL_COMPRESSED_RGB8_ETC2,
    Compressed_SRGB8_ETC2 = GL_COMPRESSED_SRGB8_ETC2,
    Compressed_RGB8_Punchthrough_Alpha1_ETC2 = GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2,
    Compressed_SRGB8_Punchthrough_Alpha1_ETC2 = GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2,
    Compressed_RGBA8_ETC2_EAC = GL_COMPRESSED_RGBA8_ETC2_EAC,
    Compressed_SRGBA8_ETC2_EAC = GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC,
    Compressed_R11_EAC = GL_COMPRESSED_R11_EAC,
    Compressed_Signed_R11_EAC = GL_COMPRESSED_SIGNED_R11_EAC,
    Compressed_RG11_EAC = GL_COMPRESSED_RG11_EAC,
    Compressed_Signed_RG11_EAC = GL_COMPRESSED_SIGNED_RG11_EAC
};
}
typedef _PixelDataInternalFormat::Enum PixelDataInternalFormat;


namespace _PixelDataFormat {
enum Enum {
    StencilIndex = GL_STENCIL_INDEX,
    DepthComponent = GL_DEPTH_COMPONENT,
    DepthStencil = GL_DEPTH_STENCIL,
    Red = GL_RED,
    Green = GL_GREEN,
    Blue = GL_BLUE,
    RG = GL_RG,
    RGB = GL_RGB,
    RGBA = GL_RGBA,
    BGR = GL_BGR,
    BGRA = GL_BGRA,
    Red_Integer = GL_RED_INTEGER,
    Green_Integer = GL_GREEN_INTEGER,
    Blue_Integer = GL_BLUE_INTEGER,
    RG_Integer = GL_RG_INTEGER,
    RGB_Integer = GL_RGB_INTEGER,
    RGBA_Integer = GL_RGBA_INTEGER,
    BGR_Integer = GL_BGR_INTEGER,
    BGRA_Integer = GL_BGRA_INTEGER
};
};
typedef _PixelDataFormat::Enum PixelDataFormat;

namespace _PixelDataType {
enum Enum {
    UnsignedByte = GL_UNSIGNED_BYTE,
    Byte = GL_BYTE,
    UnsignedShort = GL_UNSIGNED_SHORT,
    Short = GL_SHORT,
    UnsignedInt = GL_UNSIGNED_INT,
    Int = GL_INT,
    HalfFloat = GL_HALF_FLOAT,
    Float = GL_FLOAT,
    UnsignedByte_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
    UnsignedByte_2_3_3_Rev = GL_UNSIGNED_BYTE_2_3_3_REV,
    UnsignedShort_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
    UnsignedShort_5_6_5_Rev = GL_UNSIGNED_SHORT_5_6_5_REV,
    UnsignedShort_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
    UnsignedShort_4_4_4_4_Rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
    UnsignedShort_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
    UnsignedShort_1_5_5_5_Rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
    UnsignedInt_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
    UnsignedInt_8_8_8_8_Rev = GL_UNSIGNED_INT_8_8_8_8_REV,
    UnsignedInt_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
    UnsignedInt_2_10_10_10_Rev = GL_UNSIGNED_INT_2_10_10_10_REV,
    UnsignedInt_24_8 = GL_UNSIGNED_INT_24_8,
    UnsignedInt_10f_11f_11f_Rev = GL_UNSIGNED_INT_10F_11F_11F_REV,
    UnsignedInt_5_9_9_9_Rev = GL_UNSIGNED_INT_5_9_9_9_REV,
    Float_32UnsignedInt_24_8_Rev = GL_FLOAT_32_UNSIGNED_INT_24_8_REV
};
};
typedef _PixelDataType::Enum PixelDataType;

namespace _Wrap {
enum Enum {
    ClampToEdge = GL_CLAMP_TO_EDGE,
    Repeat = GL_REPEAT,
    ClampToBorder = GL_CLAMP_TO_BORDER,
    MirroredRepeat = GL_MIRRORED_REPEAT
};
}
typedef _Wrap::Enum Wrap;

namespace _MinFilter {
enum Enum {
    Nearest = GL_NEAREST,
    Linear = GL_LINEAR,
    NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
    NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
    LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
    LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR
};
}
typedef _MinFilter::Enum MinF;

namespace _MagFilter {
enum Enum {
    Nearest = GL_NEAREST,
    Linear = GL_LINEAR
};
}
typedef _MagFilter::Enum MagF;

namespace _Swizzle {
enum Enum {
    Red = GL_RED,
    Green = GL_GREEN,
    Blue = GL_BLUE,
    Alpha = GL_ALPHA,
    Zero = GL_ZERO,
    One = GL_ONE
};
}
typedef _Swizzle::Enum Swizzle;

} // Namespace oglwrap

#endif // OGLWRAP_ENUMS_H
