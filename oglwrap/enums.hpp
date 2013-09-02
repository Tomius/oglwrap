/** @file enums.hpp
    @brief Contains enumeration wrappers for GLenums.
*/

#pragma once

namespace oglwrap {

// -------======{[ Shaders ]}======-------

namespace _ShaderType {
enum ShaderType {
#ifdef GL_COMPUTE_SHADER
    Compute = GL_COMPUTE_SHADER,
#endif
#ifdef GL_VERTEX_SHADER
    Vertex = GL_VERTEX_SHADER,
#endif
#ifdef GL_GEOMETRY_SHADER
    Geometry = GL_GEOMETRY_SHADER,
#endif
#ifdef GL_FRAGMENT_SHADER
    Fragment = GL_FRAGMENT_SHADER,
#endif
#ifdef GL_TESS_CONTROL_SHADER
    TessControl = GL_TESS_CONTROL_SHADER,
#endif
#ifdef GL_TESS_EVALUATION_SHADER
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
#ifdef GL_BYTE
    Byte = GL_BYTE,
#endif
#ifdef GL_SHORT
    Short = GL_SHORT,
#endif
#ifdef GL_INT
    Int = GL_INT,
#endif
#ifdef GL_FIXED
    Fixed = GL_FIXED,
#endif
#ifdef GL_FLOAT
    Float = GL_FLOAT,
#endif
#ifdef GL_HALF_FLOAT
    HalfFloat = GL_HALF_FLOAT,
#endif
#ifdef GL_DOUBLE
    Double = GL_DOUBLE,
#endif
#ifdef GL_UNSIGNED_BYTE
    UnsignedByte = GL_UNSIGNED_BYTE,
#endif
#ifdef GL_UNSIGNED_SHORT
    UnsignedShort = GL_UNSIGNED_SHORT,
#endif
#ifdef GL_UNSIGNED_INT
    UnsignedInt = GL_UNSIGNED_INT
#endif
};
}
typedef _DataType::DataType DataType;

namespace _WholeDataType {
enum WholeDataType {
#ifdef GL_BYTE
    Byte = GL_BYTE,
#endif
#ifdef GL_SHORT
    Short = GL_SHORT,
#endif
#ifdef GL_INT
    Int = GL_INT,
#endif
#ifdef GL_UNSIGNED_BYTE
    UnsignedByte = GL_UNSIGNED_BYTE,
#endif
#ifdef GL_UNSIGNED_SHORT
    UnsignedShort = GL_UNSIGNED_SHORT,
#endif
#ifdef GL_UNSIGNED_INT
    UnsignedInt = GL_UNSIGNED_INT
#endif
};
}
typedef _WholeDataType::WholeDataType WholeDataType;

// SinglePrecisionRealDataType if I wanted to be correct...
namespace _FloatDataType {
enum FloatDataType {
#ifdef GL_FIXED
    Fixed = GL_FIXED,
#endif
#ifdef GL_FLOAT
    Float = GL_FLOAT,
#endif
#ifdef GL_HALF_FLOAT
    HalfFloat = GL_HALF_FLOAT,
#endif
};
}
typedef _FloatDataType::FloatDataType FloatDataType;


// -------======{[ Buffers ]}======-------

namespace _BufferType {
enum BufferType {
#ifdef GL_ARRAY_BUFFER
    Array = GL_ARRAY_BUFFER,
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER
    AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
#endif
#ifdef GL_COPY_READ_BUFFER
    CopyRead = GL_COPY_READ_BUFFER,
#endif
#ifdef GL_COPY_WRITE_BUFFER
    CopyWrite = GL_COPY_WRITE_BUFFER,
#endif
#ifdef GL_DISPATCH_INDIRECT_BUFFER
    DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER,
#endif
#ifdef GL_DRAW_INDIRECT_BUFFER
    DrawIndirect = GL_DRAW_INDIRECT_BUFFER,
#endif
#ifdef GL_ELEMENT_ARRAY_BUFFER
    ElementArray = GL_ELEMENT_ARRAY_BUFFER,
#endif
#ifdef GL_PIXEL_PACK_BUFFER
    PixelPack = GL_PIXEL_PACK_BUFFER,
#endif
#ifdef GL_PIXEL_UNPACK_BUFFER
    PixelUnpack = GL_PIXEL_UNPACK_BUFFER,
#endif
#ifdef GL_SHADER_STORAGE_BUFFER
    ShaderStorage = GL_SHADER_STORAGE_BUFFER,
#endif
#ifdef GL_TEXTURE_BUFFER
    Texture = GL_TEXTURE_BUFFER,
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
    TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
#endif
#ifdef GL_UNIFORM_BUFFER
    Uniform = GL_UNIFORM_BUFFER
#endif
};
}
typedef _BufferType::BufferType BufferType;

namespace _IndexedBufferType {
enum IndexedBufferType {
#ifdef GL_ATOMIC_COUNTER_BUFFER
    AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
#endif
#ifdef GL_SHADER_STORAGE_BUFFER
    ShaderStorage = GL_SHADER_STORAGE_BUFFER,
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
    TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
#endif
#ifdef GL_UNIFORM_BUFFER
    Uniform = GL_UNIFORM_BUFFER
#endif
};
}
typedef _IndexedBufferType::IndexedBufferType IndexedBufferType;


namespace _BufferUsage {
enum BufferUsage {
#ifdef GL_STREAM_DRAW
    StreamDraw = GL_STREAM_DRAW,
#endif
#ifdef GL_STREAM_READ
    StreamRead = GL_STREAM_READ,
#endif
#ifdef GL_STREAM_COPY
    StreamCopy = GL_STREAM_COPY,
#endif
#ifdef GL_STATIC_DRAW
    StaticDraw = GL_STATIC_DRAW,
#endif
#ifdef GL_STATIC_READ
    StaticRead = GL_STATIC_READ,
#endif
#ifdef GL_STATIC_COPY
    StaticCopy = GL_STATIC_COPY,
#endif
#ifdef GL_DYNAMIC_DRAW
    DynamicDraw = GL_DYNAMIC_DRAW,
#endif
#ifdef GL_DYNAMIC_READ
    DynamicRead = GL_DYNAMIC_READ,
#endif
#ifdef GL_DYNAMIC_COPY
    DynamicCopy = GL_DYNAMIC_COPY
#endif
};
}
typedef _BufferUsage::BufferUsage BufferUsage;

namespace _BufferMapAccess {
enum BufferMapAccess {
#ifdef GL_MAP_READ_BIT
    Read = GL_MAP_READ_BIT,
#endif
#ifdef GL_MAP_WRITE_BIT
    Write = GL_MAP_WRITE_BIT,
#endif
#ifdef GL_READ_WRITE
    ReadWrite = GL_READ_WRITE
#endif
};
}
typedef _BufferMapAccess::BufferMapAccess BufferMapAccess;

// -------======{[ Framebuffers ]}======-------

namespace _FramebufferTarget {
enum FramebufferTarget {
#ifdef GL_READ_FRAMEBUFFER
    Read = GL_READ_FRAMEBUFFER,
#endif
#ifdef GL_DRAW_FRAMEBUFFER
    Draw = GL_DRAW_FRAMEBUFFER,
#endif
#ifdef GL_FRAMEBUFFER
    Read_Draw = GL_FRAMEBUFFER,
#endif
};
}
typedef _FramebufferTarget::FramebufferTarget FramebufferTarget;
typedef _FramebufferTarget::FramebufferTarget FBO_Target;

namespace _FramebufferStatus {
enum FramebufferStatus {
#ifdef GL_FRAMEBUFFER_COMPLETE
    Complete = GL_FRAMEBUFFER_COMPLETE,
#endif
#ifdef GL_FRAMEBUFFER_UNDEFINED
    Undefined = GL_FRAMEBUFFER_UNDEFINED,
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
    Incomplete_Attachment = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
    Incomplete_MissingAttachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER
    Incomplete_DrawBuffer = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER,
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER
    Incomplete_ReadBuffer = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER,
#endif
#ifdef GL_FRAMEBUFFER_UNSUPPORTED
    Unsupported = GL_FRAMEBUFFER_UNSUPPORTED,
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
    Incomplete_Multisample = GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
    Incomplete_LayerTargets = GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
#endif
};
}
typedef _FramebufferStatus::FramebufferStatus FramebufferStatus;
typedef _FramebufferStatus::FramebufferStatus FBO_Status;

namespace _FramebufferAttachment {
enum FramebufferAttachment {
#ifdef GL_COLOR_ATTACHMENT0
    Color = GL_COLOR_ATTACHMENT0,
#endif
#ifdef GL_COLOR_ATTACHMENT1
    Color1 = GL_COLOR_ATTACHMENT1,
#endif
#ifdef GL_COLOR_ATTACHMENT2
    Color2 = GL_COLOR_ATTACHMENT2,
#endif
#ifdef GL_COLOR_ATTACHMENT3
    Color3 = GL_COLOR_ATTACHMENT3,
#endif
#ifdef GL_COLOR_ATTACHMENT4
    Color4 = GL_COLOR_ATTACHMENT4,
#endif
#ifdef GL_COLOR_ATTACHMENT5
    Color5 = GL_COLOR_ATTACHMENT5,
#endif
#ifdef GL_COLOR_ATTACHMENT6
    Color6 = GL_COLOR_ATTACHMENT6,
#endif
#ifdef GL_COLOR_ATTACHMENT7
    Color7 = GL_COLOR_ATTACHMENT7,
#endif
#ifdef GL_COLOR_ATTACHMENT8
    Color8 = GL_COLOR_ATTACHMENT8,
#endif
#ifdef GL_COLOR_ATTACHMENT9
    Color9 = GL_COLOR_ATTACHMENT9,
#endif
#ifdef GL_COLOR_ATTACHMENT10
    Color10 = GL_COLOR_ATTACHMENT10,
#endif
#ifdef GL_COLOR_ATTACHMENT11
    Color11 = GL_COLOR_ATTACHMENT11,
#endif
#ifdef GL_COLOR_ATTACHMENT12
    Color12 = GL_COLOR_ATTACHMENT12,
#endif
#ifdef GL_COLOR_ATTACHMENT13
    Color13 = GL_COLOR_ATTACHMENT13,
#endif
#ifdef GL_COLOR_ATTACHMENT14
    Color14 = GL_COLOR_ATTACHMENT14,
#endif
#ifdef GL_COLOR_ATTACHMENT15
    Color15 = GL_COLOR_ATTACHMENT15,
#endif
#ifdef GL_DEPTH_ATTACHMENT
    Depth = GL_DEPTH_ATTACHMENT,
#endif
#ifdef GL_STENCIL_ATTACHMENT
    Stencil = GL_STENCIL_ATTACHMENT,
#endif
#ifdef GL_DEPTH_STENCIL_ATTACHMENT
    DepthStencil = GL_DEPTH_STENCIL_ATTACHMENT
#endif
};
}
typedef _FramebufferAttachment::FramebufferAttachment FramebufferAttachment;
typedef _FramebufferAttachment::FramebufferAttachment FBO_Attachment;

// -------======{[ Textures ]}======-------

namespace _TexType {
enum TexType {
#ifdef GL_TEXTURE_1D
    Tex1D = GL_TEXTURE_1D,
#endif
#ifdef GL_TEXTURE_2D
    Tex2D = GL_TEXTURE_2D,
#endif
#ifdef GL_TEXTURE_3D
    Tex3D = GL_TEXTURE_3D,
#endif
#ifdef GL_TEXTURE_RECTANGLE
    TexRect = GL_TEXTURE_RECTANGLE,
#endif
#ifdef GL_TEXTURE_1D_ARRAY
    Tex1DArray = GL_TEXTURE_1D_ARRAY,
#endif
#ifdef GL_TEXTURE_2D_ARRAY
    Tex2DArray = GL_TEXTURE_2D_ARRAY,
#endif
#ifdef GL_TEXTURE_CUBE_MAP
    TexCubeMap = GL_TEXTURE_CUBE_MAP,
#endif
};
}
typedef _TexType::TexType TexType;

namespace _Tex2DType {
enum Tex2DType {
#ifdef GL_TEXTURE_2D
    Tex2D = GL_TEXTURE_2D,
#endif
#ifdef GL_TEXTURE_1D_ARRAY
    Tex1DArray = GL_TEXTURE_1D_ARRAY,
#endif
#ifdef GL_TEXTURE_RECTANGLE
    TexRect = GL_TEXTURE_RECTANGLE
#endif
};
}
typedef _Tex2DType::Tex2DType Tex2DType;

namespace _CubeTarget {
enum CubeTarget {
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
    PosX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
    NegX = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
    PosY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
    NegY = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
    PosZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
    NegZ = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
#endif
};
}
typedef _CubeTarget::CubeTarget CubeTarget;

namespace _Tex3DType {
enum Tex3DType {
#ifdef GL_TEXTURE_3D
    Tex3D = GL_TEXTURE_3D,
#endif
#ifdef GL_TEXTURE_2D_ARRAY
    Tex2DArray = GL_TEXTURE_2D_ARRAY,
#endif
};
}
typedef _Tex3DType::Tex3DType Tex3DType;

// These aren't supported yet.. sorry :(
namespace _ExtraTexType {
enum ExtraTexType {
#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
    TexCubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
#endif
#ifdef GL_TEXTURE_2D_MULTISAMPLE
    Tex2DMultisample = GL_TEXTURE_2D_MULTISAMPLE,
#endif
#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
    Tex2DMultisampleArray = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
#endif
};
}
typedef _ExtraTexType::ExtraTexType ExtraTexType;

namespace _PixelDataInternalFormat {
enum PixelDataInternalFormat {
    // Base internal
#ifdef GL_DEPTH_COMPONENT
    DepthComponent = GL_DEPTH_COMPONENT,
#endif
#ifdef GL_DEPTH_STENCIL
    DepthStencil = GL_DEPTH_STENCIL,
#endif
#ifdef GL_RED
    Red = GL_RED,
#endif
#ifdef GL_RG
    RG = GL_RG,
#endif
#ifdef GL_RGB
    RGB = GL_RGB,
#endif
#ifdef GL_RGBA
    RGBA = GL_RGBA,
#endif

    // Sized Internal
#ifdef GL_R8
    R8 = GL_R8,
#endif
#ifdef GL_R8_SNORM
    R8_SNorm = GL_R8_SNORM,
#endif
#ifdef GL_R16
    R16 = GL_R16,
#endif
#ifdef GL_R16_SNORM
    R16_SNorm = GL_R16_SNORM,
#endif
#ifdef GL_RG8
    RG8 = GL_RG8,
#endif
#ifdef GL_RG8_SNORM
    RG8_SNorm = GL_RG8_SNORM,
#endif
#ifdef GL_RG16
    RG16 = GL_RG16,
#endif
#ifdef GL_RG16_SNORM
    RG16_SNorm = GL_RG16_SNORM,
#endif
#ifdef GL_R3_G3_B2
    R3_G3_B2 = GL_R3_G3_B2,
#endif
#ifdef GL_RGB4
    RGB4 = GL_RGB4,
#endif
#ifdef GL_RGB5
    RGB5 = GL_RGB5,
#endif
#ifdef GL_RGB8
    RGB8 = GL_RGB8,
#endif
#ifdef GL_RGB8_SNORM
    RGB8_SNorm = GL_RGB8_SNORM,
#endif
#ifdef GL_RGB10
    RGB10 = GL_RGB10,
#endif
#ifdef GL_RGB12
    RGB12 = GL_RGB12,
#endif
#ifdef GL_RGB16
    RGB16 = GL_RGB16,
#endif
#ifdef GL_RGB16_SNORM
    RGB16_SNorm = GL_RGB16_SNORM,
#endif
#ifdef GL_RGBA2
    RGBA2 = GL_RGBA2,
#endif
#ifdef GL_RGBA4
    RGBA4 = GL_RGBA4,
#endif
#ifdef GL_RGB5_A1
    RGB5A1 = GL_RGB5_A1,
#endif
#ifdef GL_RGBA8
    RGBA8 = GL_RGBA8,
#endif
#ifdef GL_RGBA8_SNORM
    RGBA8_SNorm = GL_RGBA8_SNORM,
#endif
#ifdef GL_RGB10_A2
    RGB10_A2 = GL_RGB10_A2,
#endif
#ifdef GL_RGB10_A2UI
    RGB10_A2UI = GL_RGB10_A2UI,
#endif
#ifdef GL_RGBA12
    RGBA12 = GL_RGBA12,
#endif
#ifdef GL_RGBA16
    RGBA16 = GL_RGBA16,
#endif
#ifdef GL_RGBA16_SNORM
    RGBA16_SNorm = GL_RGBA16_SNORM,
#endif
#ifdef GL_SRGB8
    SRGB8 = GL_SRGB8,
#endif
#ifdef GL_SRGB8_ALPHA8
    SRGBA8 = GL_SRGB8_ALPHA8,
#endif
#ifdef GL_R16F
    R16F = GL_R16F,
#endif
#ifdef GL_RG16F
    RG16F = GL_RG16F,
#endif
#ifdef GL_RGB16F
    RGB16F = GL_RGB16F,
#endif
#ifdef GL_RGBA16F
    RGBA16F = GL_RGBA16F,
#endif
#ifdef GL_R32F
    R32F = GL_R32F,
#endif
#ifdef GL_RG32F
    RG32F = GL_RG32F,
#endif
#ifdef GL_RGB32F
    RGB32F = GL_RGB32F,
#endif
#ifdef GL_RGBA32F
    RGBA32F = GL_RGBA32F,
#endif
#ifdef GL_R11F_G11F_B10F
    R11F_G11F_B10F = GL_R11F_G11F_B10F,
#endif
#ifdef GL_RGB9_E5
    RGB9_E5 = GL_RGB9_E5,
#endif
#ifdef GL_R8I
    R8I = GL_R8I,
#endif
#ifdef GL_R8UI
    R8UI = GL_R8UI,
#endif
#ifdef GL_R16I
    R16I = GL_R16I,
#endif
#ifdef GL_R16UI
    R16UI = GL_R16UI,
#endif
#ifdef GL_R32I
    R32I = GL_R32I,
#endif
#ifdef GL_R32UI
    R32UI = GL_R32UI,
#endif
#ifdef GL_RG8I
    RG8I = GL_RG8I,
#endif
#ifdef GL_RG8UI
    RG8UI = GL_RG8UI,
#endif
#ifdef GL_RG16I
    RG16I = GL_RG16I,
#endif
#ifdef GL_RG16UI
    RG16UI = GL_RG16UI,
#endif
#ifdef GL_RG32I
    RG32I = GL_RG32I,
#endif
#ifdef GL_RG32UI
    RG32UI = GL_RG32UI,
#endif
#ifdef GL_RGB8I
    RGB8I = GL_RGB8I,
#endif
#ifdef GL_RGB8UI
    RGB8UI = GL_RGB8UI,
#endif
#ifdef GL_RGB16I
    RGB16I = GL_RGB16I,
#endif
#ifdef GL_RGB16UI
    RGB16UI = GL_RGB16UI,
#endif
#ifdef GL_RGB32I
    RGB32I = GL_RGB32I,
#endif
#ifdef GL_RGB32UI
    RGB32UI = GL_RGB32UI,
#endif
#ifdef GL_RGBA8I
    RGBA8I = GL_RGBA8I,
#endif
#ifdef GL_RGBA8UI
    RGBA8UI = GL_RGBA8UI,
#endif
#ifdef GL_RGBA16I
    RGBA16I = GL_RGBA16I,
#endif
#ifdef GL_RGBA16UI
    RGBA16UI = GL_RGBA16UI,
#endif
#ifdef GL_RGBA32I
    RGBA32I = GL_RGBA32I,
#endif
#ifdef GL_RGBA32UI
    RGBA32UI = GL_RGBA32UI,
#endif

    // Compressed
#ifdef GL_COMPRESSED_RED
    Compressed_Red = GL_COMPRESSED_RED,
#endif
#ifdef GL_COMPRESSED_RG
    Compressed_RG = GL_COMPRESSED_RG,
#endif
#ifdef GL_COMPRESSED_RGB
    Compressed_RGB = GL_COMPRESSED_RGB,
#endif
#ifdef GL_COMPRESSED_RGBA
    Compressed_RGBA = GL_COMPRESSED_RGBA,
#endif
#ifdef GL_COMPRESSED_SRGB
    Compressed_SRGB = GL_COMPRESSED_SRGB,
#endif
#ifdef GL_COMPRESSED_SRGB_ALPHA
    Compressed_SRGBA = GL_COMPRESSED_SRGB_ALPHA,
#endif
#ifdef GL_COMPRESSED_RED_RGTC1
    Compressed_Red_RGTC1 = GL_COMPRESSED_RED_RGTC1,
#endif
#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
    Compressed_Signed_Red_RGTC1 = GL_COMPRESSED_SIGNED_RED_RGTC1,
#endif
#ifdef GL_COMPRESSED_RG_RGTC2
    Compressed_RG_RGTC2 = GL_COMPRESSED_RG_RGTC2,
#endif
#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
    Compressed_Signed_RG_RGTC2 = GL_COMPRESSED_SIGNED_RG_RGTC2,
#endif
};
}
typedef _PixelDataInternalFormat::PixelDataInternalFormat PixelDataInternalFormat;
typedef _PixelDataInternalFormat::PixelDataInternalFormat PxDIntForm;


namespace _PixelDataFormat {
enum PixelDataFormat {
#ifdef GL_STENCIL_INDEX
    StencilIndex = GL_STENCIL_INDEX,
#endif
#ifdef GL_DEPTH_COMPONENT
    DepthComponent = GL_DEPTH_COMPONENT,
#endif
#ifdef GL_DEPTH_STENCIL
    DepthStencil = GL_DEPTH_STENCIL,
#endif
#ifdef GL_RED
    Red = GL_RED,
#endif
#ifdef GL_GREEN
    Green = GL_GREEN,
#endif
#ifdef GL_BLUE
    Blue = GL_BLUE,
#endif
#ifdef GL_RG
    RG = GL_RG,
#endif
#ifdef GL_RGB
    RGB = GL_RGB,
#endif
#ifdef GL_RGBA
    RGBA = GL_RGBA,
#endif
#ifdef GL_BGR
    BGR = GL_BGR,
#endif
#ifdef GL_BGRA
    BGRA = GL_BGRA,
#endif
#ifdef GL_RED_INTEGER
    Red_Integer = GL_RED_INTEGER,
#endif
#ifdef GL_GREEN_INTEGER
    Green_Integer = GL_GREEN_INTEGER,
#endif
#ifdef GL_BLUE_INTEGER
    Blue_Integer = GL_BLUE_INTEGER,
#endif
#ifdef GL_RG_INTEGER
    RG_Integer = GL_RG_INTEGER,
#endif
#ifdef GL_RGB_INTEGER
    RGB_Integer = GL_RGB_INTEGER,
#endif
#ifdef GL_RGBA_INTEGER
    RGBA_Integer = GL_RGBA_INTEGER,
#endif
#ifdef GL_BGR_INTEGER
    BGR_Integer = GL_BGR_INTEGER,
#endif
#ifdef GL_BGRA_INTEGER
    BGRA_Integer = GL_BGRA_INTEGER
#endif
};
};
typedef _PixelDataFormat::PixelDataFormat PixelDataFormat;
typedef _PixelDataFormat::PixelDataFormat PxDForm;

namespace _PixelDataType {
enum PixelDataType {
#ifdef GL_UNSIGNED_BYTE
    UnsignedByte = GL_UNSIGNED_BYTE,
#endif
#ifdef GL_BYTE
    Byte = GL_BYTE,
#endif
#ifdef GL_UNSIGNED_SHORT
    UnsignedShort = GL_UNSIGNED_SHORT,
#endif
#ifdef GL_SHORT
    Short = GL_SHORT,
#endif
#ifdef GL_UNSIGNED_INT
    UnsignedInt = GL_UNSIGNED_INT,
#endif
#ifdef GL_INT
    Int = GL_INT,
#endif
#ifdef GL_HALF_FLOAT
    HalfFloat = GL_HALF_FLOAT,
#endif
#ifdef GL_FLOAT
    Float = GL_FLOAT,
#endif
#ifdef GL_UNSIGNED_BYTE_3_3_2
    UnsignedByte_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
#endif
#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
    UnsignedByte_2_3_3_Rev = GL_UNSIGNED_BYTE_2_3_3_REV,
#endif
#ifdef GL_UNSIGNED_SHORT_5_6_5
    UnsignedShort_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
#endif
#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
    UnsignedShort_5_6_5_Rev = GL_UNSIGNED_SHORT_5_6_5_REV,
#endif
#ifdef GL_UNSIGNED_SHORT_4_4_4_4
    UnsignedShort_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
#endif
#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
    UnsignedShort_4_4_4_4_Rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
#endif
#ifdef GL_UNSIGNED_SHORT_5_5_5_1
    UnsignedShort_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
#endif
#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
    UnsignedShort_1_5_5_5_Rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
#endif
#ifdef GL_UNSIGNED_INT_8_8_8_8
    UnsignedInt_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
#endif
#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
    UnsignedInt_8_8_8_8_Rev = GL_UNSIGNED_INT_8_8_8_8_REV,
#endif
#ifdef GL_UNSIGNED_INT_10_10_10_2
    UnsignedInt_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
#endif
#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
    UnsignedInt_2_10_10_10_Rev = GL_UNSIGNED_INT_2_10_10_10_REV,
#endif
#ifdef GL_UNSIGNED_INT_24_8
    UnsignedInt_24_8 = GL_UNSIGNED_INT_24_8,
#endif
#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
    UnsignedInt_10f_11f_11f_Rev = GL_UNSIGNED_INT_10F_11F_11F_REV,
#endif
#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
    UnsignedInt_5_9_9_9_Rev = GL_UNSIGNED_INT_5_9_9_9_REV,
#endif
#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
    Float_32UnsignedInt_24_8_Rev = GL_FLOAT_32_UNSIGNED_INT_24_8_REV
#endif
};
};
typedef _PixelDataType::PixelDataType PixelDataType;
typedef _PixelDataType::PixelDataType PxDType;

namespace _Wrap {
enum Wrap {
#ifdef GL_CLAMP_TO_EDGE
    ClampToEdge = GL_CLAMP_TO_EDGE,
#endif
#ifdef GL_REPEAT
    Repeat = GL_REPEAT,
#endif
#ifdef GL_CLAMP_TO_BORDER
    ClampToBorder = GL_CLAMP_TO_BORDER,
#endif
#ifdef GL_MIRRORED_REPEAT
    MirroredRepeat = GL_MIRRORED_REPEAT
#endif
};
}
typedef _Wrap::Wrap Wrap;

namespace _MinFilter {
enum MinF {
#ifdef GL_NEAREST
    Nearest = GL_NEAREST,
#endif
#ifdef GL_LINEAR
    Linear = GL_LINEAR,
#endif
#ifdef GL_NEAREST_MIPMAP_NEAREST
    NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
#endif
#ifdef GL_NEAREST_MIPMAP_LINEAR
    NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
#endif
#ifdef GL_LINEAR_MIPMAP_NEAREST
    LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
#endif
#ifdef GL_LINEAR_MIPMAP_LINEAR
    LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR
#endif
};
}
typedef _MinFilter::MinF MinF;

namespace _MagFilter {
enum MagF {
#ifdef GL_NEAREST
    Nearest = GL_NEAREST,
#endif
#ifdef GL_LINEAR
    Linear = GL_LINEAR
#endif
};
}
typedef _MagFilter::MagF MagF;

namespace _Swizzle {
enum Swizzle {
#ifdef GL_RED
    Red = GL_RED,
#endif
#ifdef GL_GREEN
    Green = GL_GREEN,
#endif
#ifdef GL_BLUE
    Blue = GL_BLUE,
#endif
#ifdef GL_ALPHA
    Alpha = GL_ALPHA,
#endif
#ifdef GL_ZERO
    Zero = GL_ZERO,
#endif
#ifdef GL_ONE
    One = GL_ONE
#endif
};
}
typedef _Swizzle::Swizzle Swizzle;

namespace _CompMode {
enum CompMode {
#ifdef GL_NONE
    None = GL_NONE,
#endif
#ifdef GL_COMPARE_REF_TO_TEXTURE
    CompareRefToTexture = GL_COMPARE_REF_TO_TEXTURE
#endif
};
}
typedef _CompMode::CompMode CompMode;

namespace _CompFunc {
enum CompFunc {
#ifdef GL_LEQUAL
    LEqual = GL_LEQUAL,
#endif
#ifdef GL_GEQUAL
    GEqual = GL_GEQUAL,
#endif
#ifdef GL_LESS
    Less = GL_LESS,
#endif
#ifdef GL_GREATER
    Greater = GL_GREATER,
#endif
#ifdef GL_EQUAL
    Equal = GL_EQUAL,
#endif
#ifdef GL_NOTEQUAL
    NotEqual = GL_NOTEQUAL,
#endif
#ifdef GL_ALWAYS
    Always = GL_ALWAYS,
#endif
#ifdef GL_NEVER
    Never = GL_NEVER,
#endif
};
}
typedef _CompFunc::CompFunc CompFunc;

namespace _TransformFeedbackPrimitiveType {
enum TransformFeedbackPrimitiveType {
#ifdef GL_TRIANGLES
    Triangles = GL_TRIANGLES,
#endif
#ifdef GL_LINES
    Lines = GL_LINES,
#endif
#ifdef GL_POINTS
    Points = GL_POINTS
#endif
};
}

typedef _TransformFeedbackPrimitiveType::TransformFeedbackPrimitiveType TransformFeedbackPrimitiveType;
typedef _TransformFeedbackPrimitiveType::TransformFeedbackPrimitiveType TFB_PrimType;

} // Namespace oglwrap
