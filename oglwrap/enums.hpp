/** @file enums.hpp
    @brief Contains enumeration wrappers for GLenums.
*/

#pragma once

namespace oglwrap {

namespace Enums { // just to make doxygen list enum namespaces nicely

// -------======{[ Shaders ]}======-------

namespace _ShaderType {
enum ShaderType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPUTE_SHADER)
  Compute = GL_COMPUTE_SHADER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_VERTEX_SHADER)
  Vertex = GL_VERTEX_SHADER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_GEOMETRY_SHADER)
  Geometry = GL_GEOMETRY_SHADER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAGMENT_SHADER)
  Fragment = GL_FRAGMENT_SHADER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TESS_CONTROL_SHADER)
  TessControl = GL_TESS_CONTROL_SHADER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TESS_EVALUATION_SHADER)
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
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BYTE)
  Byte = GL_BYTE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SHORT)
  Short = GL_SHORT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_INT)
  Int = GL_INT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FIXED)
  Fixed = GL_FIXED,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FLOAT)
  Float = GL_FLOAT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_HALF_FLOAT)
  HalfFloat = GL_HALF_FLOAT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DOUBLE)
  Double = GL_DOUBLE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_BYTE)
  UnsignedByte = GL_UNSIGNED_BYTE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_SHORT)
  UnsignedShort = GL_UNSIGNED_SHORT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_INT)
  UnsignedInt = GL_UNSIGNED_INT
#endif
};
}
typedef _DataType::DataType DataType;

namespace _WholeDataType {
enum WholeDataType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BYTE)
  Byte = GL_BYTE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SHORT)
  Short = GL_SHORT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_INT)
  Int = GL_INT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_BYTE)
  UnsignedByte = GL_UNSIGNED_BYTE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_SHORT)
  UnsignedShort = GL_UNSIGNED_SHORT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_INT)
  UnsignedInt = GL_UNSIGNED_INT
#endif
};
}
typedef _WholeDataType::WholeDataType WholeDataType;

// SinglePrecisionRealDataType if I wanted to be correct...
namespace _FloatDataType {
enum FloatDataType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FIXED)
  Fixed = GL_FIXED,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FLOAT)
  Float = GL_FLOAT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_HALF_FLOAT)
  HalfFloat = GL_HALF_FLOAT,
#endif
};
}
typedef _FloatDataType::FloatDataType FloatDataType;


// -------======{[ Buffers ]}======-------

namespace _BufferType {
enum BufferType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ARRAY_BUFFER)
  Array = GL_ARRAY_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ATOMIC_COUNTER_BUFFER)
  AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COPY_READ_BUFFER)
  CopyRead = GL_COPY_READ_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COPY_WRITE_BUFFER)
  CopyWrite = GL_COPY_WRITE_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DISPATCH_INDIRECT_BUFFER)
  DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DRAW_INDIRECT_BUFFER)
  DrawIndirect = GL_DRAW_INDIRECT_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ELEMENT_ARRAY_BUFFER)
  ElementArray = GL_ELEMENT_ARRAY_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_PIXEL_PACK_BUFFER)
  PixelPack = GL_PIXEL_PACK_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_PIXEL_UNPACK_BUFFER)
  PixelUnpack = GL_PIXEL_UNPACK_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SHADER_STORAGE_BUFFER)
  ShaderStorage = GL_SHADER_STORAGE_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BUFFER)
  Texture = GL_TEXTURE_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
  TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNIFORM_BUFFER)
  Uniform = GL_UNIFORM_BUFFER
#endif
};
}
typedef _BufferType::BufferType BufferType;

namespace _BufferBinding {
enum BufferBinding {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ARRAY_BUFFER_BINDING)
  Array = GL_ARRAY_BUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
  AtomicCounter = GL_ATOMIC_COUNTER_BUFFER_BINDING,
#endif
// Note: these two do not end with _BINDING
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COPY_READ_BUFFER)
  CopyRead = GL_COPY_READ_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COPY_WRITE_BUFFER)
  CopyWrite = GL_COPY_WRITE_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DISPATCH_INDIRECT_BUFFER_BINDING)
  DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DRAW_INDIRECT_BUFFER_BINDING)
  DrawIndirect = GL_DRAW_INDIRECT_BUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ELEMENT_ARRAY_BUFFER_BINDING)
  ElementArray = GL_ELEMENT_ARRAY_BUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_PIXEL_PACK_BUFFER_BINDING)
  PixelPack = GL_PIXEL_PACK_BUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_PIXEL_UNPACK_BUFFER_BINDING)
  PixelUnpack = GL_PIXEL_UNPACK_BUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
  ShaderStorage = GL_SHADER_STORAGE_BUFFER_BINDING,
#endif
// Note: It's not BUFFER_BINDING but BINDING_BUFFER.
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_BUFFER)
  Texture = GL_TEXTURE_BINDING_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
  TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNIFORM_BUFFER_BINDING)
  Uniform = GL_UNIFORM_BUFFER_BINDING,
#endif
};
}
typedef _BufferBinding::BufferBinding BufferBinding;

namespace _IndexedBufferType {
enum IndexedBufferType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ATOMIC_COUNTER_BUFFER)
  AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SHADER_STORAGE_BUFFER)
  ShaderStorage = GL_SHADER_STORAGE_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
  TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNIFORM_BUFFER)
  Uniform = GL_UNIFORM_BUFFER
#endif
};
}
typedef _IndexedBufferType::IndexedBufferType IndexedBufferType;

namespace _IndexedBufferBinding {
enum IndexedBufferBinding {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
  AtomicCounter = GL_ATOMIC_COUNTER_BUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SHADER_STORAGE_BUFFER_BINDING)
  ShaderStorage = GL_SHADER_STORAGE_BUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
  TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNIFORM_BUFFER_BINDING)
  Uniform = GL_UNIFORM_BUFFER_BINDING,
#endif
};
}
typedef _IndexedBufferBinding::IndexedBufferBinding IndexedBufferBinding;

namespace _BufferUsage {
enum BufferUsage {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_STREAM_DRAW)
  StreamDraw = GL_STREAM_DRAW,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_STREAM_READ)
  StreamRead = GL_STREAM_READ,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_STREAM_COPY)
  StreamCopy = GL_STREAM_COPY,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_STATIC_DRAW)
  StaticDraw = GL_STATIC_DRAW,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_STATIC_READ)
  StaticRead = GL_STATIC_READ,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_STATIC_COPY)
  StaticCopy = GL_STATIC_COPY,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DYNAMIC_DRAW)
  DynamicDraw = GL_DYNAMIC_DRAW,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DYNAMIC_READ)
  DynamicRead = GL_DYNAMIC_READ,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DYNAMIC_COPY)
  DynamicCopy = GL_DYNAMIC_COPY
#endif
};
}
typedef _BufferUsage::BufferUsage BufferUsage;

namespace _BufferMapAccess {
enum BufferMapAccess {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_READ_ONLY)
  Read = GL_READ_ONLY,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_WRITE_ONLY)
  Write = GL_WRITE_ONLY,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_READ_WRITE)
  ReadWrite = GL_READ_WRITE
#endif
};
}
typedef _BufferMapAccess::BufferMapAccess BufferMapAccess;

namespace _BufferMapAccessFlags {
enum BufferMapAccessFlags {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_MAP_READ_BIT)
  Read_Bit = GL_MAP_READ_BIT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_MAP_WRITE_BIT)
  Write_Bit = GL_MAP_WRITE_BIT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_MAP_INVALIDATE_RANGE_BIT)
  Invalidate_Range_Bit = GL_MAP_INVALIDATE_RANGE_BIT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
  Invalidate_Buffer_Bit = GL_MAP_INVALIDATE_BUFFER_BIT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
  Flush_Explicit_Bit = GL_MAP_FLUSH_EXPLICIT_BIT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_MAP_UNSYNCHRONIZED_BIT)
  Unsynchronized_Bit = GL_MAP_UNSYNCHRONIZED_BIT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_MAP_PERSISTENT_BIT)
  Persistent_Bit = GL_MAP_PERSISTENT_BIT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_MAP_COHERENT_BIT)
  Coherent_Bit = GL_MAP_COHERENT_BIT
#endif
};
}
typedef _BufferMapAccessFlags::BufferMapAccessFlags BufferMapAccessFlags;

// -------======{[ Framebuffers ]}======-------

namespace _FramebufferType {
enum FramebufferType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_READ_FRAMEBUFFER)
  Read = GL_READ_FRAMEBUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DRAW_FRAMEBUFFER)
  Draw = GL_DRAW_FRAMEBUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER)
  Read_Draw = GL_FRAMEBUFFER,
#endif
};
}
typedef _FramebufferType::FramebufferType FramebufferType;
typedef _FramebufferType::FramebufferType FboType;

namespace _FramebufferBinding {
enum FramebufferBinding {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_READ_FRAMEBUFFER_BINDING)
  Read = GL_READ_FRAMEBUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DRAW_FRAMEBUFFER_BINDING)
  Draw = GL_DRAW_FRAMEBUFFER_BINDING,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER_BINDING)
  Read_Draw = GL_FRAMEBUFFER_BINDING,
#endif
};
}
typedef _FramebufferBinding::FramebufferBinding FramebufferBinding;
typedef _FramebufferBinding::FramebufferBinding FboBinding;

namespace _FramebufferStatus {
enum FramebufferStatus {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER_COMPLETE)
  Complete = GL_FRAMEBUFFER_COMPLETE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER_UNDEFINED)
  Undefined = GL_FRAMEBUFFER_UNDEFINED,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
  Incomplete_Attachment = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
  Incomplete_MissingAttachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER)
  Incomplete_DrawBuffer = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER)
  Incomplete_ReadBuffer = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER_UNSUPPORTED)
  Unsupported = GL_FRAMEBUFFER_UNSUPPORTED,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
  Incomplete_Multisample = GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
  Incomplete_LayerTargets = GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
#endif
};
}
typedef _FramebufferStatus::FramebufferStatus FramebufferStatus;
typedef _FramebufferStatus::FramebufferStatus FboStatus;

namespace _FramebufferAttachment {
enum FramebufferAttachment {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT0)
  Color = GL_COLOR_ATTACHMENT0,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT1)
  Color1 = GL_COLOR_ATTACHMENT1,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT2)
  Color2 = GL_COLOR_ATTACHMENT2,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT3)
  Color3 = GL_COLOR_ATTACHMENT3,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT4)
  Color4 = GL_COLOR_ATTACHMENT4,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT5)
  Color5 = GL_COLOR_ATTACHMENT5,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT6)
  Color6 = GL_COLOR_ATTACHMENT6,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT7)
  Color7 = GL_COLOR_ATTACHMENT7,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT8)
  Color8 = GL_COLOR_ATTACHMENT8,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT9)
  Color9 = GL_COLOR_ATTACHMENT9,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT10)
  Color10 = GL_COLOR_ATTACHMENT10,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT11)
  Color11 = GL_COLOR_ATTACHMENT11,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT12)
  Color12 = GL_COLOR_ATTACHMENT12,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT13)
  Color13 = GL_COLOR_ATTACHMENT13,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT14)
  Color14 = GL_COLOR_ATTACHMENT14,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COLOR_ATTACHMENT15)
  Color15 = GL_COLOR_ATTACHMENT15,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DEPTH_ATTACHMENT)
  Depth = GL_DEPTH_ATTACHMENT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_STENCIL_ATTACHMENT)
  Stencil = GL_STENCIL_ATTACHMENT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DEPTH_STENCIL_ATTACHMENT)
  DepthStencil = GL_DEPTH_STENCIL_ATTACHMENT
#endif
};
}
typedef _FramebufferAttachment::FramebufferAttachment FramebufferAttachment;
typedef _FramebufferAttachment::FramebufferAttachment FboAttachment;

// -------======{[ Textures ]}======-------

namespace _TexType {
enum TexType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_1D)
  Tex1D = GL_TEXTURE_1D,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_2D)
  Tex2D = GL_TEXTURE_2D,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_3D)
  Tex3D = GL_TEXTURE_3D,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_RECTANGLE)
  TexRect = GL_TEXTURE_RECTANGLE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_1D_ARRAY)
  Tex1DArray = GL_TEXTURE_1D_ARRAY,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_2D_ARRAY)
  Tex2DArray = GL_TEXTURE_2D_ARRAY,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_CUBE_MAP)
  TexCubeMap = GL_TEXTURE_CUBE_MAP,
#endif
};
}
typedef _TexType::TexType TexType;

namespace _TexBinding {
enum TexBinding {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_1D)
  Tex1D = GL_TEXTURE_BINDING_1D,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_2D)
  Tex2D = GL_TEXTURE_BINDING_2D,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_3D)
  Tex3D = GL_TEXTURE_BINDING_3D,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_RECTANGLE)
  TexRect = GL_TEXTURE_BINDING_RECTANGLE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_1D_ARRAY)
  Tex1DArray = GL_TEXTURE_BINDING_1D_ARRAY,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_2D_ARRAY)
  Tex2DArray = GL_TEXTURE_BINDING_2D_ARRAY,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_BINDING_CUBE_MAP)
  TexCubeMap = GL_TEXTURE_BINDING_CUBE_MAP,
#endif
};
}
typedef _TexBinding::TexBinding TexBinding;

namespace _Tex2DType {
enum Tex2DType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_2D)
  Tex2D = GL_TEXTURE_2D,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_1D_ARRAY)
  Tex1DArray = GL_TEXTURE_1D_ARRAY,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_RECTANGLE)
  TexRect = GL_TEXTURE_RECTANGLE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_CUBE_MAP)
  TexCubeMap = GL_TEXTURE_CUBE_MAP
#endif
};
}
typedef _Tex2DType::Tex2DType Tex2DType;

namespace _CubeTarget {
enum CubeTarget {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
  PosX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
  NegX = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
  PosY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
  NegY = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
  PosZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
  NegZ = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
#endif
};
}
typedef _CubeTarget::CubeTarget CubeTarget;

namespace _Tex3DType {
enum Tex3DType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_3D)
  Tex3D = GL_TEXTURE_3D,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_2D_ARRAY)
  Tex2DArray = GL_TEXTURE_2D_ARRAY,
#endif
};
}
typedef _Tex3DType::Tex3DType Tex3DType;

// These aren't supported yet.. sorry :(
namespace _ExtraTexType {
enum ExtraTexType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_CUBE_MAP_ARRAY)
  TexCubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_2D_MULTISAMPLE)
  Tex2DMultisample = GL_TEXTURE_2D_MULTISAMPLE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TEXTURE_2D_MULTISAMPLE_ARRAY)
  Tex2DMultisampleArray = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
#endif
};
}
typedef _ExtraTexType::ExtraTexType ExtraTexType;

namespace _PixelDataInternalFormat {
enum PixelDataInternalFormat {
  // Base internal
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DEPTH_COMPONENT)
  DepthComponent = GL_DEPTH_COMPONENT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DEPTH_STENCIL)
  DepthStencil = GL_DEPTH_STENCIL,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RED)
  Red = GL_RED,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG)
  RG = GL_RG,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB)
  RGB = GL_RGB,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA)
  RGBA = GL_RGBA,
#endif

  // Sized Internal
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R8)
  R8 = GL_R8,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R8_SNORM)
  R8_SNorm = GL_R8_SNORM,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R16)
  R16 = GL_R16,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R16_SNORM)
  R16_SNorm = GL_R16_SNORM,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG8)
  RG8 = GL_RG8,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG8_SNORM)
  RG8_SNorm = GL_RG8_SNORM,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG16)
  RG16 = GL_RG16,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG16_SNORM)
  RG16_SNorm = GL_RG16_SNORM,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R3_G3_B2)
  R3_G3_B2 = GL_R3_G3_B2,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB4)
  RGB4 = GL_RGB4,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB5)
  RGB5 = GL_RGB5,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB8)
  RGB8 = GL_RGB8,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB8_SNORM)
  RGB8_SNorm = GL_RGB8_SNORM,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB10)
  RGB10 = GL_RGB10,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB12)
  RGB12 = GL_RGB12,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB16)
  RGB16 = GL_RGB16,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB16_SNORM)
  RGB16_SNorm = GL_RGB16_SNORM,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA2)
  RGBA2 = GL_RGBA2,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA4)
  RGBA4 = GL_RGBA4,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB5_A1)
  RGB5A1 = GL_RGB5_A1,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA8)
  RGBA8 = GL_RGBA8,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA8_SNORM)
  RGBA8_SNorm = GL_RGBA8_SNORM,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB10_A2)
  RGB10_A2 = GL_RGB10_A2,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB10_A2UI)
  RGB10_A2UI = GL_RGB10_A2UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA12)
  RGBA12 = GL_RGBA12,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA16)
  RGBA16 = GL_RGBA16,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA16_SNORM)
  RGBA16_SNorm = GL_RGBA16_SNORM,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SRGB8)
  SRGB8 = GL_SRGB8,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SRGB8_ALPHA8)
  SRGBA8 = GL_SRGB8_ALPHA8,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R16F)
  R16F = GL_R16F,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG16F)
  RG16F = GL_RG16F,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB16F)
  RGB16F = GL_RGB16F,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA16F)
  RGBA16F = GL_RGBA16F,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R32F)
  R32F = GL_R32F,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG32F)
  RG32F = GL_RG32F,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB32F)
  RGB32F = GL_RGB32F,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA32F)
  RGBA32F = GL_RGBA32F,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R11F_G11F_B10F)
  R11F_G11F_B10F = GL_R11F_G11F_B10F,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB9_E5)
  RGB9_E5 = GL_RGB9_E5,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R8I)
  R8I = GL_R8I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R8UI)
  R8UI = GL_R8UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R16I)
  R16I = GL_R16I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R16UI)
  R16UI = GL_R16UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R32I)
  R32I = GL_R32I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_R32UI)
  R32UI = GL_R32UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG8I)
  RG8I = GL_RG8I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG8UI)
  RG8UI = GL_RG8UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG16I)
  RG16I = GL_RG16I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG16UI)
  RG16UI = GL_RG16UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG32I)
  RG32I = GL_RG32I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG32UI)
  RG32UI = GL_RG32UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB8I)
  RGB8I = GL_RGB8I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB8UI)
  RGB8UI = GL_RGB8UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB16I)
  RGB16I = GL_RGB16I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB16UI)
  RGB16UI = GL_RGB16UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB32I)
  RGB32I = GL_RGB32I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB32UI)
  RGB32UI = GL_RGB32UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA8I)
  RGBA8I = GL_RGBA8I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA8UI)
  RGBA8UI = GL_RGBA8UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA16I)
  RGBA16I = GL_RGBA16I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA16UI)
  RGBA16UI = GL_RGBA16UI,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA32I)
  RGBA32I = GL_RGBA32I,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA32UI)
  RGBA32UI = GL_RGBA32UI,
#endif

  // Compressed
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPRESSED_RED)
  Compressed_Red = GL_COMPRESSED_RED,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPRESSED_RG)
  Compressed_RG = GL_COMPRESSED_RG,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPRESSED_RGB)
  Compressed_RGB = GL_COMPRESSED_RGB,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPRESSED_RGBA)
  Compressed_RGBA = GL_COMPRESSED_RGBA,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPRESSED_SRGB)
  Compressed_SRGB = GL_COMPRESSED_SRGB,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPRESSED_SRGB_ALPHA)
  Compressed_SRGBA = GL_COMPRESSED_SRGB_ALPHA,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPRESSED_RED_RGTC1)
  Compressed_Red_RGTC1 = GL_COMPRESSED_RED_RGTC1,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPRESSED_SIGNED_RED_RGTC1)
  Compressed_Signed_Red_RGTC1 = GL_COMPRESSED_SIGNED_RED_RGTC1,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPRESSED_RG_RGTC2)
  Compressed_RG_RGTC2 = GL_COMPRESSED_RG_RGTC2,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPRESSED_SIGNED_RG_RGTC2)
  Compressed_Signed_RG_RGTC2 = GL_COMPRESSED_SIGNED_RG_RGTC2,
#endif
};
}
typedef _PixelDataInternalFormat::PixelDataInternalFormat PixelDataInternalFormat;


namespace _PixelDataFormat {
enum PixelDataFormat {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_STENCIL_INDEX)
  StencilIndex = GL_STENCIL_INDEX,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DEPTH_COMPONENT)
  DepthComponent = GL_DEPTH_COMPONENT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_DEPTH_STENCIL)
  DepthStencil = GL_DEPTH_STENCIL,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RED)
  Red = GL_RED,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_GREEN)
  Green = GL_GREEN,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BLUE)
  Blue = GL_BLUE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG)
  RG = GL_RG,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB)
  RGB = GL_RGB,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA)
  RGBA = GL_RGBA,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BGR)
  BGR = GL_BGR,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BGRA)
  BGRA = GL_BGRA,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RED_INTEGER)
  Red_Integer = GL_RED_INTEGER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_GREEN_INTEGER)
  Green_Integer = GL_GREEN_INTEGER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BLUE_INTEGER)
  Blue_Integer = GL_BLUE_INTEGER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RG_INTEGER)
  RG_Integer = GL_RG_INTEGER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGB_INTEGER)
  RGB_Integer = GL_RGB_INTEGER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RGBA_INTEGER)
  RGBA_Integer = GL_RGBA_INTEGER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BGR_INTEGER)
  BGR_Integer = GL_BGR_INTEGER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BGRA_INTEGER)
  BGRA_Integer = GL_BGRA_INTEGER
#endif
};
}
typedef _PixelDataFormat::PixelDataFormat PixelDataFormat;

namespace _PixelDataType {
enum PixelDataType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_BYTE)
  UnsignedByte = GL_UNSIGNED_BYTE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BYTE)
  Byte = GL_BYTE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_SHORT)
  UnsignedShort = GL_UNSIGNED_SHORT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_SHORT)
  Short = GL_SHORT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_INT)
  UnsignedInt = GL_UNSIGNED_INT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_INT)
  Int = GL_INT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_HALF_FLOAT)
  HalfFloat = GL_HALF_FLOAT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FLOAT)
  Float = GL_FLOAT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_BYTE_3_3_2)
  UnsignedByte_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_BYTE_2_3_3_REV)
  UnsignedByte_2_3_3_Rev = GL_UNSIGNED_BYTE_2_3_3_REV,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_SHORT_5_6_5)
  UnsignedShort_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_SHORT_5_6_5_REV)
  UnsignedShort_5_6_5_Rev = GL_UNSIGNED_SHORT_5_6_5_REV,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_SHORT_4_4_4_4)
  UnsignedShort_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_SHORT_4_4_4_4_REV)
  UnsignedShort_4_4_4_4_Rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_SHORT_5_5_5_1)
  UnsignedShort_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_SHORT_1_5_5_5_REV)
  UnsignedShort_1_5_5_5_Rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_INT_8_8_8_8)
  UnsignedInt_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_INT_8_8_8_8_REV)
  UnsignedInt_8_8_8_8_Rev = GL_UNSIGNED_INT_8_8_8_8_REV,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_INT_10_10_10_2)
  UnsignedInt_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_INT_2_10_10_10_REV)
  UnsignedInt_2_10_10_10_Rev = GL_UNSIGNED_INT_2_10_10_10_REV,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_INT_24_8)
  UnsignedInt_24_8 = GL_UNSIGNED_INT_24_8,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_INT_10F_11F_11F_REV)
  UnsignedInt_10f_11f_11f_Rev = GL_UNSIGNED_INT_10F_11F_11F_REV,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_UNSIGNED_INT_5_9_9_9_REV)
  UnsignedInt_5_9_9_9_Rev = GL_UNSIGNED_INT_5_9_9_9_REV,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
  Float_32UnsignedInt_24_8_Rev = GL_FLOAT_32_UNSIGNED_INT_24_8_REV
#endif
};
}
typedef _PixelDataType::PixelDataType PixelDataType;

namespace _Wrap {
enum Wrap {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_CLAMP_TO_EDGE)
  ClampToEdge = GL_CLAMP_TO_EDGE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_REPEAT)
  Repeat = GL_REPEAT,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_CLAMP_TO_BORDER)
  ClampToBorder = GL_CLAMP_TO_BORDER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_MIRRORED_REPEAT)
  MirroredRepeat = GL_MIRRORED_REPEAT
#endif
};
}
typedef _Wrap::Wrap Wrap;

namespace _MinFilter {
enum MinFilter {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_NEAREST)
  Nearest = GL_NEAREST,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_LINEAR)
  Linear = GL_LINEAR,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_NEAREST_MIPMAP_NEAREST)
  NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_NEAREST_MIPMAP_LINEAR)
  NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_LINEAR_MIPMAP_NEAREST)
  LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_LINEAR_MIPMAP_LINEAR)
  LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR
#endif
};
}
typedef _MinFilter::MinFilter MinFilter;

namespace _MagFilter {
enum MagFilter {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_NEAREST)
  Nearest = GL_NEAREST,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_LINEAR)
  Linear = GL_LINEAR
#endif
};
}
typedef _MagFilter::MagFilter MagFilter;

namespace _Swizzle {
enum Swizzle {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_RED)
  Red = GL_RED,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_GREEN)
  Green = GL_GREEN,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_BLUE)
  Blue = GL_BLUE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ALPHA)
  Alpha = GL_ALPHA,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ZERO)
  Zero = GL_ZERO,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ONE)
  One = GL_ONE
#endif
};
}
typedef _Swizzle::Swizzle Swizzle;

namespace _CompMode {
enum CompMode {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_NONE)
  None = GL_NONE,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_COMPARE_REF_TO_TEXTURE)
  CompareRefToTexture = GL_COMPARE_REF_TO_TEXTURE
#endif
};
}
typedef _CompMode::CompMode CompMode;

namespace _CompFunc {
enum CompFunc {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_LEQUAL)
  LEqual = GL_LEQUAL,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_GEQUAL)
  GEqual = GL_GEQUAL,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_LESS)
  Less = GL_LESS,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_GREATER)
  Greater = GL_GREATER,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_EQUAL)
  Equal = GL_EQUAL,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_NOTEQUAL)
  NotEqual = GL_NOTEQUAL,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_ALWAYS)
  Always = GL_ALWAYS,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_NEVER)
  Never = GL_NEVER,
#endif
};
}
typedef _CompFunc::CompFunc CompFunc;

namespace _TransformFeedbackPrimitiveType {
enum TransformFeedbackPrimitiveType {
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_TRIANGLES)
  Triangles = GL_TRIANGLES,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_LINES)
  Lines = GL_LINES,
#endif
#if !OGLWRAP_CHECK_DEPENDENCIES || defined(GL_POINTS)
  Points = GL_POINTS
#endif
};
}

typedef _TransformFeedbackPrimitiveType::TransformFeedbackPrimitiveType TransformFeedbackPrimitiveType;
typedef _TransformFeedbackPrimitiveType::TransformFeedbackPrimitiveType TFB_PrimType;

} // Namespace Enums

using namespace oglwrap::Enums;

} // Namespace oglwrap

