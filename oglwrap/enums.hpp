/** @file enums.hpp
    @brief Contains enumeration wrappers for GLenums.
*/

#ifndef OGLWRAP_ENUMS_H
#define OGLWRAP_ENUMS_H

namespace oglwrap {

// -------======{[ Shaders ]}======-------

namespace _ShaderType {
enum ShaderType {
#if !OGLWRAP_COREONLY
    Compute = GL_COMPUTE_SHADER,
#endif
    Vertex = GL_VERTEX_SHADER,
    Geometry = GL_GEOMETRY_SHADER,
    Fragment = GL_FRAGMENT_SHADER,
#if !OGLWRAP_COREONLY
    TessControl = GL_TESS_CONTROL_SHADER,
    TessEval = GL_TESS_EVALUATION_SHADER
#endif
};
}
typedef _ShaderType::ShaderType ShaderType;

// -------======{[ Uniforms ]}======-------

#define INVALID_LOCATION 0xFFFFFFFF

// -------======{[ Vertex Attrib Array ]}======-------

namespace _DataType {
enum DataType {
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
}
typedef _DataType::DataType DataType;

namespace _WholeDataType {
enum WholeDataType {
    Byte = GL_BYTE,
    Short = GL_SHORT,
    Int = GL_INT,
    UnsignedByte = GL_UNSIGNED_BYTE,
    UnsignedShort = GL_UNSIGNED_SHORT,
    UnsignedInt = GL_UNSIGNED_INT
};
}
typedef _WholeDataType::WholeDataType WholeDataType;

// SinglePrecisionRealDataType if I wanted to be correct...
namespace _FloatDataType {
enum FloatDataType {
    Fixed = GL_FIXED,
    Float = GL_FLOAT,
    HalfFloat = GL_HALF_FLOAT,
};
}
typedef _FloatDataType::FloatDataType FloatDataType;


// -------======{[ Buffers ]}======-------

namespace _BufferType {
enum BufferType {
    Array = GL_ARRAY_BUFFER,
#if !OGLWRAP_COREONLY
    AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
#endif
    CopyRead = GL_COPY_READ_BUFFER,
    CopyWrite = GL_COPY_WRITE_BUFFER,
#if !OGLWRAP_COREONLY
    DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER,
#endif
    DrawIndirect = GL_DRAW_INDIRECT_BUFFER,
    ElementArray = GL_ELEMENT_ARRAY_BUFFER,
    PixelPack = GL_PIXEL_PACK_BUFFER,
    PixelUnpack = GL_PIXEL_UNPACK_BUFFER,
#if !OGLWRAP_COREONLY
    ShaderStorage = GL_SHADER_STORAGE_BUFFER,
#endif
    Texture = GL_TEXTURE_BUFFER,
    TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
    Uniform = GL_UNIFORM_BUFFER,
};
}
typedef _BufferType::BufferType BufferType;

namespace _IndexedBufferType {
enum IndexedBufferType {
#if !OGLWRAP_COREONLY
    AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
    ShaderStorage = GL_SHADER_STORAGE_BUFFER,
#endif
    TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
    Uniform = GL_UNIFORM_BUFFER
};
}
typedef _IndexedBufferType::IndexedBufferType IndexedBufferType;


namespace _BufferUsage {
enum BufferUsage {
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
typedef _BufferUsage::BufferUsage BufferUsage;

namespace _BufferMapAccess {
enum BufferMapAccess {
    Read = GL_MAP_READ_BIT,
    Write = GL_MAP_WRITE_BIT,
    ReadWrite = GL_READ_WRITE
};
}
typedef _BufferMapAccess::BufferMapAccess BufferMapAccess;

// -------======{[ FrameBuffers ]}======-------

namespace _FrameBufferTarget {
enum FrameBufferTarget {
    Read = GL_READ_FRAMEBUFFER,
    Draw = GL_DRAW_FRAMEBUFFER,
    Read_Draw = GL_FRAMEBUFFER,
};
}
typedef _FrameBufferTarget::FrameBufferTarget FrameBufferTarget;
typedef _FrameBufferTarget::FrameBufferTarget FBO_Target;

namespace _FrameBufferStatus {
enum FrameBufferStatus {
    Complete = GL_FRAMEBUFFER_COMPLETE,
    Undefined = GL_FRAMEBUFFER_UNDEFINED,
    Incomplete_Attachment = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
    Incomplete_MissingAttachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
    Incomplete_DrawBuffer = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER,
    Incomplete_ReadBuffer = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER,
    Unsupported = GL_FRAMEBUFFER_UNSUPPORTED,
    Incomplete_Multisample = GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,
    Incomplete_LayerTargets = GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
};
}
typedef _FrameBufferStatus::FrameBufferStatus FrameBufferStatus;
typedef _FrameBufferStatus::FrameBufferStatus FBO_Status;

namespace _FrameBufferAttachment {
enum FrameBufferAttachment {
    Color = GL_COLOR_ATTACHMENT0,
    Color1 = GL_COLOR_ATTACHMENT1,
    Color2 = GL_COLOR_ATTACHMENT2,
    Color3 = GL_COLOR_ATTACHMENT3,
    Color4 = GL_COLOR_ATTACHMENT4,
    Color5 = GL_COLOR_ATTACHMENT5,
    Color6 = GL_COLOR_ATTACHMENT6,
    Color7 = GL_COLOR_ATTACHMENT7,
    Color8 = GL_COLOR_ATTACHMENT8,
    Color9 = GL_COLOR_ATTACHMENT9,
    Color10 = GL_COLOR_ATTACHMENT10,
    Color11 = GL_COLOR_ATTACHMENT11,
    Color12 = GL_COLOR_ATTACHMENT12,
    Color13 = GL_COLOR_ATTACHMENT13,
    Color14 = GL_COLOR_ATTACHMENT14,
    Color15 = GL_COLOR_ATTACHMENT15,
    Depth = GL_DEPTH_ATTACHMENT,
    Stencil = GL_STENCIL_ATTACHMENT,
    DepthStencil = GL_DEPTH_STENCIL_ATTACHMENT
};
}
typedef _FrameBufferAttachment::FrameBufferAttachment FrameBufferAttachment;
typedef _FrameBufferAttachment::FrameBufferAttachment FBO_Attachment;

// -------======{[ Textures ]}======-------

namespace _TexType {
enum TexType {
    Tex1D = GL_TEXTURE_1D,
    Tex2D = GL_TEXTURE_2D,
    Tex3D = GL_TEXTURE_3D,
    TexRect = GL_TEXTURE_RECTANGLE,
    Tex1DArray = GL_TEXTURE_1D_ARRAY,
    Tex2DArray = GL_TEXTURE_2D_ARRAY,
    TexCubeMap = GL_TEXTURE_CUBE_MAP,
};
}
typedef _TexType::TexType TexType;

namespace _Tex2DType {
enum Tex2DType {
    Tex2D = GL_TEXTURE_2D,
    Tex1DArray = GL_TEXTURE_1D_ARRAY,
    TexRect = GL_TEXTURE_RECTANGLE
};
}
typedef _Tex2DType::Tex2DType Tex2DType;

namespace _CubeTarget {
enum CubeTarget {
    PosX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
    NegX = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
    PosY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
    NegY = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
    PosZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
    NegZ = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
};
}
typedef _CubeTarget::CubeTarget CubeTarget;

namespace _Tex3DType {
enum Tex3DType {
    Tex3D = GL_TEXTURE_3D,
    Tex2DArray = GL_TEXTURE_2D_ARRAY,
};
}
typedef _Tex3DType::Tex3DType Tex3DType;

// These aren't supported yet.. sorry :(
namespace _ExtraTexType {
enum ExtraTexType {
    TexCubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
    Tex2DMultisample = GL_TEXTURE_2D_MULTISAMPLE,
    Tex2DMultisampleArray = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
};
}
typedef _ExtraTexType::ExtraTexType ExtraTexType;

namespace _PixelDataInternalFormat {
enum PixelDataInternalFormat {
    // Base internal
    DepthComponent = GL_DEPTH_COMPONENT,
    DepthStencil = GL_DEPTH_STENCIL,
    Red = GL_RED,
    RG = GL_RG,
    RGB = GL_RGB,
    RGBA = GL_RGBA,

    // Sized Internal
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

    // Compressed
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
};
}
typedef _PixelDataInternalFormat::PixelDataInternalFormat PixelDataInternalFormat;
typedef _PixelDataInternalFormat::PixelDataInternalFormat PxDIntForm;


namespace _PixelDataFormat {
enum PixelDataFormat {
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
typedef _PixelDataFormat::PixelDataFormat PixelDataFormat;
typedef _PixelDataFormat::PixelDataFormat PxDForm;

namespace _PixelDataType {
enum PixelDataType {
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
typedef _PixelDataType::PixelDataType PixelDataType;
typedef _PixelDataType::PixelDataType PxDType;

namespace _Wrap {
enum Wrap {
    ClampToEdge = GL_CLAMP_TO_EDGE,
    Repeat = GL_REPEAT,
    ClampToBorder = GL_CLAMP_TO_BORDER,
    MirroredRepeat = GL_MIRRORED_REPEAT
};
}
typedef _Wrap::Wrap Wrap;

namespace _MinFilter {
enum MinF {
    Nearest = GL_NEAREST,
    Linear = GL_LINEAR,
    NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
    NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
    LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
    LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR
};
}
typedef _MinFilter::MinF MinF;

namespace _MagFilter {
enum MagF {
    Nearest = GL_NEAREST,
    Linear = GL_LINEAR
};
}
typedef _MagFilter::MagF MagF;

namespace _Swizzle {
enum Swizzle {
    Red = GL_RED,
    Green = GL_GREEN,
    Blue = GL_BLUE,
    Alpha = GL_ALPHA,
    Zero = GL_ZERO,
    One = GL_ONE
};
}
typedef _Swizzle::Swizzle Swizzle;

namespace _CompMode {
enum CompMode {
    None = GL_NONE,
    CompareRefToTexture = GL_COMPARE_REF_TO_TEXTURE
};
}
typedef _CompMode::CompMode CompMode;

namespace _CompFunc {
enum CompFunc {
    LEqual = GL_LEQUAL,
    GEqual = GL_GEQUAL,
    Less = GL_LESS,
    Greater = GL_GREATER,
    Equal = GL_EQUAL,
    NotEqual = GL_NOTEQUAL,
    Always = GL_ALWAYS,
    Never = GL_NEVER,
};
}
typedef _CompFunc::CompFunc CompFunc;

namespace _TransformFeedbackPrimitiveType {
enum TransformFeedbackPrimitiveType {
    Triangles = GL_TRIANGLES,
    Lines = GL_LINES,
    Points = GL_POINTS
};
}

typedef _TransformFeedbackPrimitiveType::TransformFeedbackPrimitiveType TransformFeedbackPrimitiveType;
typedef _TransformFeedbackPrimitiveType::TransformFeedbackPrimitiveType TFB_PrimType;

} // Namespace oglwrap

#endif // OGLWRAP_ENUMS_H
