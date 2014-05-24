// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_SMART_ENUMS_H_
#define OGLWRAP_SMART_ENUMS_H_

#include "./config.h"
#include "./enums/framebuffer_type.h"
#include "./enums/pixel_data_internal_format.h"
#include "./enums/capability.h"
#include "./enums/texture_type.h"
#include "./enums/pixel_storage_mode.h"
#include "./enums/indexed_buffer_type.h"
#include "./enums/buffer_binding.h"
#include "./enums/data_type.h"
#include "./enums/blend_function.h"
#include "./enums/framebuffer_status.h"
#include "./enums/min_filter.h"
#include "./enums/pixel_data_type.h"
#include "./enums/color_buffer.h"
#include "./enums/color_logic_operation.h"
#include "./enums/basic_primitive_type.h"
#include "./enums/indexed_buffer_binding.h"
#include "./enums/primitive_type.h"
#include "./enums/whole_data_type.h"
#include "./enums/blit_filter.h"
#include "./enums/buffer_map_access.h"
#include "./enums/compare_func.h"
#include "./enums/texture_binding.h"
#include "./enums/swizzle_mode.h"
#include "./enums/wrap_mode.h"
#include "./enums/buffer_usage.h"
#include "./enums/face_orientation.h"
#include "./enums/memory_barrier_bit.h"
#include "./enums/buffer_type.h"
#include "./enums/compare_mode.h"
#include "./enums/error_type.h"
#include "./enums/stencil_operation.h"
#include "./enums/texture3D_type.h"
#include "./enums/buffer_map_access_flags.h"
#include "./enums/face.h"
#include "./enums/blend_equation.h"
#include "./enums/framebuffer_binding.h"
#include "./enums/buffer_select_bit.h"
#include "./enums/poly_mode.h"
#include "./enums/shader_type.h"
#include "./enums/index_type.h"
#include "./enums/mag_filter.h"
#include "./enums/texture_cube_target.h"
#include "./enums/framebuffer_attachment.h"
#include "./enums/texture2D_type.h"
#include "./enums/provoke_mode.h"
#include "./enums/pixel_data_format.h"
#include "./define_internal_macros.h"

namespace oglwrap {

class SmartEnums {
public:

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALPHA)
  struct AlphaEnum {
    constexpr operator SwizzleMode() const { return SwizzleMode(GL_ALPHA); }
  };
  static AlphaEnum Alpha;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
  struct AlwaysEnum {
    constexpr operator CompareFunc() const { return CompareFunc(GL_ALWAYS); }
  };
  static AlwaysEnum Always;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
  struct AndEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND); }
  };
  static AndEnum And;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
  struct AndInvertedEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND_INVERTED); }
  };
  static AndInvertedEnum AndInverted;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
  struct AndReverseEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND_REVERSE); }
  };
  static AndReverseEnum AndReverse;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
  struct ArrayBufferEnum {
    constexpr operator BufferType() const { return BufferType(GL_ARRAY_BUFFER); }
  };
  static ArrayBufferEnum ArrayBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BARRIER_BIT)
  struct AtomicCounterBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_ATOMIC_COUNTER_BARRIER_BIT); }
  };
  static AtomicCounterBarrierBitEnum AtomicCounterBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
  struct AtomicCounterBufferEnum {
    constexpr operator IndexedBufferType() const { return IndexedBufferType(GL_ATOMIC_COUNTER_BUFFER); }
    constexpr operator BufferType() const { return BufferType(GL_ATOMIC_COUNTER_BUFFER); }
  };
  static AtomicCounterBufferEnum AtomicCounterBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
  struct BackEnum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_BACK); }
    constexpr operator Face() const { return Face(GL_BACK); }
  };
  static BackEnum Back;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_LEFT)
  struct BackLeftEnum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_BACK_LEFT); }
  };
  static BackLeftEnum BackLeft;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_RIGHT)
  struct BackRightEnum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_BACK_RIGHT); }
  };
  static BackRightEnum BackRight;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
  struct BgrEnum {
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGR); }
  };
  static BgrEnum Bgr;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
  struct BgraEnum {
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGRA); }
  };
  static BgraEnum Bgra;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
  struct BgraIntegerEnum {
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGRA_INTEGER); }
  };
  static BgraIntegerEnum BgraInteger;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
  struct BgrIntegerEnum {
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGR_INTEGER); }
  };
  static BgrIntegerEnum BgrInteger;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLEND)
  struct BlendEnum {
    constexpr operator Capability() const { return Capability(GL_BLEND); }
  };
  static BlendEnum Blend;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
  struct BlueEnum {
    constexpr operator SwizzleMode() const { return SwizzleMode(GL_BLUE); }
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BLUE); }
  };
  static BlueEnum Blue;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
  struct BlueIntegerEnum {
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BLUE_INTEGER); }
  };
  static BlueIntegerEnum BlueInteger;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BUFFER_UPDATE_BARRIER_BIT)
  struct BufferUpdateBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_BUFFER_UPDATE_BARRIER_BIT); }
  };
  static BufferUpdateBarrierBitEnum BufferUpdateBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BYTE)
  struct ByteEnum {
    constexpr operator DataType() const { return DataType(GL_BYTE); }
    constexpr operator PixelDataType() const { return PixelDataType(GL_BYTE); }
    constexpr operator WholeDataType() const { return WholeDataType(GL_BYTE); }
  };
  static ByteEnum Byte;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
  struct CcwEnum {
    constexpr operator FaceOrientation() const { return FaceOrientation(GL_CCW); }
  };
  static CcwEnum Ccw;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_BORDER)
  struct ClampToBorderEnum {
    constexpr operator WrapMode() const { return WrapMode(GL_CLAMP_TO_BORDER); }
  };
  static ClampToBorderEnum ClampToBorder;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_EDGE)
  struct ClampToEdgeEnum {
    constexpr operator WrapMode() const { return WrapMode(GL_CLAMP_TO_EDGE); }
  };
  static ClampToEdgeEnum ClampToEdge;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
  struct ClearEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_CLEAR); }
  };
  static ClearEnum Clear;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT)
  struct ClientMappedBufferBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT); }
  };
  static ClientMappedBufferBarrierBitEnum ClientMappedBufferBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIP_DISTANCE)
  struct ClipDistanceEnum {
    constexpr operator Capability() const { return Capability(GL_CLIP_DISTANCE); }
  };
  static ClipDistanceEnum ClipDistance;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT0)
  struct ColorAttachment0Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT0); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT0); }
  };
  static ColorAttachment0Enum ColorAttachment0;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT1)
  struct ColorAttachment1Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT1); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT1); }
  };
  static ColorAttachment1Enum ColorAttachment1;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT10)
  struct ColorAttachment10Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT10); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT10); }
  };
  static ColorAttachment10Enum ColorAttachment10;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT11)
  struct ColorAttachment11Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT11); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT11); }
  };
  static ColorAttachment11Enum ColorAttachment11;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT12)
  struct ColorAttachment12Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT12); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT12); }
  };
  static ColorAttachment12Enum ColorAttachment12;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT13)
  struct ColorAttachment13Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT13); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT13); }
  };
  static ColorAttachment13Enum ColorAttachment13;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT14)
  struct ColorAttachment14Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT14); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT14); }
  };
  static ColorAttachment14Enum ColorAttachment14;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT15)
  struct ColorAttachment15Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT15); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT15); }
  };
  static ColorAttachment15Enum ColorAttachment15;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT2)
  struct ColorAttachment2Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT2); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT2); }
  };
  static ColorAttachment2Enum ColorAttachment2;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT3)
  struct ColorAttachment3Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT3); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT3); }
  };
  static ColorAttachment3Enum ColorAttachment3;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT4)
  struct ColorAttachment4Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT4); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT4); }
  };
  static ColorAttachment4Enum ColorAttachment4;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT5)
  struct ColorAttachment5Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT5); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT5); }
  };
  static ColorAttachment5Enum ColorAttachment5;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT6)
  struct ColorAttachment6Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT6); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT6); }
  };
  static ColorAttachment6Enum ColorAttachment6;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT7)
  struct ColorAttachment7Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT7); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT7); }
  };
  static ColorAttachment7Enum ColorAttachment7;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT8)
  struct ColorAttachment8Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT8); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT8); }
  };
  static ColorAttachment8Enum ColorAttachment8;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT9)
  struct ColorAttachment9Enum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT9); }
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT9); }
  };
  static ColorAttachment9Enum ColorAttachment9;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
  struct ColorBufferBitEnum {
    constexpr operator BufferSelectBit() const { return BufferSelectBit(GL_COLOR_BUFFER_BIT); }
  };
  static ColorBufferBitEnum ColorBufferBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_LOGIC_OP)
  struct ColorLogicOpEnum {
    constexpr operator Capability() const { return Capability(GL_COLOR_LOGIC_OP); }
  };
  static ColorLogicOpEnum ColorLogicOp;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMMAND_BARRIER_BIT)
  struct CommandBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_COMMAND_BARRIER_BIT); }
  };
  static CommandBarrierBitEnum CommandBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPARE_REF_TO_TEXTURE)
  struct CompareRefToTextureEnum {
    constexpr operator CompareMode() const { return CompareMode(GL_COMPARE_REF_TO_TEXTURE); }
  };
  static CompareRefToTextureEnum CompareRefToTexture;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED)
  struct CompressedRedEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RED); }
  };
  static CompressedRedEnum CompressedRed;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED_RGTC1)
  struct CompressedRedRgtc1Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RED_RGTC1); }
  };
  static CompressedRedRgtc1Enum CompressedRedRgtc1;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG)
  struct CompressedRgEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RG); }
  };
  static CompressedRgEnum CompressedRg;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGB)
  struct CompressedRgbEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RGB); }
  };
  static CompressedRgbEnum CompressedRgb;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGBA)
  struct CompressedRgbaEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RGBA); }
  };
  static CompressedRgbaEnum CompressedRgba;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG_RGTC2)
  struct CompressedRgRgtc2Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RG_RGTC2); }
  };
  static CompressedRgRgtc2Enum CompressedRgRgtc2;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RED_RGTC1)
  struct CompressedSignedRedRgtc1Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SIGNED_RED_RGTC1); }
  };
  static CompressedSignedRedRgtc1Enum CompressedSignedRedRgtc1;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RG_RGTC2)
  struct CompressedSignedRgRgtc2Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SIGNED_RG_RGTC2); }
  };
  static CompressedSignedRgRgtc2Enum CompressedSignedRgRgtc2;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB)
  struct CompressedSrgbEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SRGB); }
  };
  static CompressedSrgbEnum CompressedSrgb;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB_ALPHA)
  struct CompressedSrgbAlphaEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SRGB_ALPHA); }
  };
  static CompressedSrgbAlphaEnum CompressedSrgbAlpha;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
  struct ComputeShaderEnum {
    constexpr operator ShaderType() const { return ShaderType(GL_COMPUTE_SHADER); }
  };
  static ComputeShaderEnum ComputeShader;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_ALPHA)
  struct ConstantAlphaEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_CONSTANT_ALPHA); }
  };
  static ConstantAlphaEnum ConstantAlpha;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_COLOR)
  struct ConstantColorEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_CONSTANT_COLOR); }
  };
  static ConstantColorEnum ConstantColor;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
  struct CopyEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_COPY); }
  };
  static CopyEnum Copy;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
  struct CopyInvertedEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_COPY_INVERTED); }
  };
  static CopyInvertedEnum CopyInverted;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
  struct CopyReadBufferEnum {
    constexpr operator BufferType() const { return BufferType(GL_COPY_READ_BUFFER); }
  };
  static CopyReadBufferEnum CopyReadBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
  struct CopyWriteBufferEnum {
    constexpr operator BufferType() const { return BufferType(GL_COPY_WRITE_BUFFER); }
  };
  static CopyWriteBufferEnum CopyWriteBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CULL_FACE)
  struct CullFaceEnum {
    constexpr operator Capability() const { return Capability(GL_CULL_FACE); }
  };
  static CullFaceEnum CullFace;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
  struct CwEnum {
    constexpr operator FaceOrientation() const { return FaceOrientation(GL_CW); }
  };
  static CwEnum Cw;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT)
  struct DebugOutputEnum {
    constexpr operator Capability() const { return Capability(GL_DEBUG_OUTPUT); }
  };
  static DebugOutputEnum DebugOutput;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT_SYNCHRONOUS)
  struct DebugOutputSynchronousEnum {
    constexpr operator Capability() const { return Capability(GL_DEBUG_OUTPUT_SYNCHRONOUS); }
  };
  static DebugOutputSynchronousEnum DebugOutputSynchronous;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
  struct DecrEnum {
    constexpr operator StencilOperation() const { return StencilOperation(GL_DECR); }
  };
  static DecrEnum Decr;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
  struct DecrWrapEnum {
    constexpr operator StencilOperation() const { return StencilOperation(GL_DECR_WRAP); }
  };
  static DecrWrapEnum DecrWrap;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_ATTACHMENT)
  struct DepthAttachmentEnum {
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_DEPTH_ATTACHMENT); }
  };
  static DepthAttachmentEnum DepthAttachment;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
  struct DepthBufferBitEnum {
    constexpr operator BufferSelectBit() const { return BufferSelectBit(GL_DEPTH_BUFFER_BIT); }
  };
  static DepthBufferBitEnum DepthBufferBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_CLAMP)
  struct DepthClampEnum {
    constexpr operator Capability() const { return Capability(GL_DEPTH_CLAMP); }
  };
  static DepthClampEnum DepthClamp;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_COMPONENT)
  struct DepthComponentEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_DEPTH_COMPONENT); }
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_DEPTH_COMPONENT); }
  };
  static DepthComponentEnum DepthComponent;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL)
  struct DepthStencilEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_DEPTH_STENCIL); }
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_DEPTH_STENCIL); }
  };
  static DepthStencilEnum DepthStencil;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL_ATTACHMENT)
  struct DepthStencilAttachmentEnum {
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_DEPTH_STENCIL_ATTACHMENT); }
  };
  static DepthStencilAttachmentEnum DepthStencilAttachment;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_TEST)
  struct DepthTestEnum {
    constexpr operator Capability() const { return Capability(GL_DEPTH_TEST); }
  };
  static DepthTestEnum DepthTest;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER)
  struct DispatchIndirectBufferEnum {
    constexpr operator BufferType() const { return BufferType(GL_DISPATCH_INDIRECT_BUFFER); }
  };
  static DispatchIndirectBufferEnum DispatchIndirectBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DITHER)
  struct DitherEnum {
    constexpr operator Capability() const { return Capability(GL_DITHER); }
  };
  static DitherEnum Dither;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DOUBLE)
  struct DoubleEnum {
    constexpr operator DataType() const { return DataType(GL_DOUBLE); }
  };
  static DoubleEnum Double;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
  struct DrawFramebufferEnum {
    constexpr operator FramebufferType() const { return FramebufferType(GL_DRAW_FRAMEBUFFER); }
  };
  static DrawFramebufferEnum DrawFramebuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER)
  struct DrawIndirectBufferEnum {
    constexpr operator BufferType() const { return BufferType(GL_DRAW_INDIRECT_BUFFER); }
  };
  static DrawIndirectBufferEnum DrawIndirectBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_ALPHA)
  struct DstAlphaEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_DST_ALPHA); }
  };
  static DstAlphaEnum DstAlpha;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_COLOR)
  struct DstColorEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_DST_COLOR); }
  };
  static DstColorEnum DstColor;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_COPY)
  struct DynamicCopyEnum {
    constexpr operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_COPY); }
  };
  static DynamicCopyEnum DynamicCopy;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_DRAW)
  struct DynamicDrawEnum {
    constexpr operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_DRAW); }
  };
  static DynamicDrawEnum DynamicDraw;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_READ)
  struct DynamicReadEnum {
    constexpr operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_READ); }
  };
  static DynamicReadEnum DynamicRead;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BARRIER_BIT)
  struct ElementArrayBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_ELEMENT_ARRAY_BARRIER_BIT); }
  };
  static ElementArrayBarrierBitEnum ElementArrayBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
  struct ElementArrayBufferEnum {
    constexpr operator BufferType() const { return BufferType(GL_ELEMENT_ARRAY_BUFFER); }
  };
  static ElementArrayBufferEnum ElementArrayBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
  struct EqualEnum {
    constexpr operator CompareFunc() const { return CompareFunc(GL_EQUAL); }
  };
  static EqualEnum Equal;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
  struct EquivEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_EQUIV); }
  };
  static EquivEnum Equiv;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
  struct FillEnum {
    constexpr operator PolyMode() const { return PolyMode(GL_FILL); }
  };
  static FillEnum Fill;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
  struct FirstVertexConventionEnum {
    constexpr operator ProvokeMode() const { return ProvokeMode(GL_FIRST_VERTEX_CONVENTION); }
  };
  static FirstVertexConventionEnum FirstVertexConvention;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIXED)
  struct FixedEnum {
    constexpr operator DataType() const { return DataType(GL_FIXED); }
  };
  static FixedEnum Fixed;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT)
  struct FloatEnum {
    constexpr operator DataType() const { return DataType(GL_FLOAT); }
    constexpr operator PixelDataType() const { return PixelDataType(GL_FLOAT); }
  };
  static FloatEnum Float;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
  struct Float32UnsignedInt248RevEnum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_FLOAT_32_UNSIGNED_INT_24_8_REV); }
  };
  static Float32UnsignedInt248RevEnum Float32UnsignedInt248Rev;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
  struct FragmentShaderEnum {
    constexpr operator ShaderType() const { return ShaderType(GL_FRAGMENT_SHADER); }
  };
  static FragmentShaderEnum FragmentShader;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
  struct FramebufferEnum {
    constexpr operator FramebufferType() const { return FramebufferType(GL_FRAMEBUFFER); }
  };
  static FramebufferEnum Framebuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BARRIER_BIT)
  struct FramebufferBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_FRAMEBUFFER_BARRIER_BIT); }
  };
  static FramebufferBarrierBitEnum FramebufferBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_COMPLETE)
  struct FramebufferCompleteEnum {
    constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_COMPLETE); }
  };
  static FramebufferCompleteEnum FramebufferComplete;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
  struct FramebufferIncompleteAttachmentEnum {
    constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT); }
  };
  static FramebufferIncompleteAttachmentEnum FramebufferIncompleteAttachment;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER)
  struct FramebufferIncompleteDrawBufferEnum {
    constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER); }
  };
  static FramebufferIncompleteDrawBufferEnum FramebufferIncompleteDrawBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
  struct FramebufferIncompleteLayerTargetsEnum {
    constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS); }
  };
  static FramebufferIncompleteLayerTargetsEnum FramebufferIncompleteLayerTargets;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
  struct FramebufferIncompleteMissingAttachmentEnum {
    constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT); }
  };
  static FramebufferIncompleteMissingAttachmentEnum FramebufferIncompleteMissingAttachment;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
  struct FramebufferIncompleteMultisampleEnum {
    constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE); }
  };
  static FramebufferIncompleteMultisampleEnum FramebufferIncompleteMultisample;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER)
  struct FramebufferIncompleteReadBufferEnum {
    constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER); }
  };
  static FramebufferIncompleteReadBufferEnum FramebufferIncompleteReadBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_SRGB)
  struct FramebufferSrgbEnum {
    constexpr operator Capability() const { return Capability(GL_FRAMEBUFFER_SRGB); }
  };
  static FramebufferSrgbEnum FramebufferSrgb;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNDEFINED)
  struct FramebufferUndefinedEnum {
    constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_UNDEFINED); }
  };
  static FramebufferUndefinedEnum FramebufferUndefined;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNSUPPORTED)
  struct FramebufferUnsupportedEnum {
    constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_UNSUPPORTED); }
  };
  static FramebufferUnsupportedEnum FramebufferUnsupported;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
  struct FrontEnum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT); }
    constexpr operator Face() const { return Face(GL_FRONT); }
  };
  static FrontEnum Front;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
  struct FrontAndBackEnum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT_AND_BACK); }
    constexpr operator Face() const { return Face(GL_FRONT_AND_BACK); }
  };
  static FrontAndBackEnum FrontAndBack;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_LEFT)
  struct FrontLeftEnum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT_LEFT); }
  };
  static FrontLeftEnum FrontLeft;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_RIGHT)
  struct FrontRightEnum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT_RIGHT); }
  };
  static FrontRightEnum FrontRight;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_ADD)
  struct FuncAddEnum {
    constexpr operator BlendEquation() const { return BlendEquation(GL_FUNC_ADD); }
  };
  static FuncAddEnum FuncAdd;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_REVERSE_SUBTRACT)
  struct FuncReverseSubtractEnum {
    constexpr operator BlendEquation() const { return BlendEquation(GL_FUNC_REVERSE_SUBTRACT); }
  };
  static FuncReverseSubtractEnum FuncReverseSubtract;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_SUBTRACT)
  struct FuncSubtractEnum {
    constexpr operator BlendEquation() const { return BlendEquation(GL_FUNC_SUBTRACT); }
  };
  static FuncSubtractEnum FuncSubtract;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
  struct GeometryShaderEnum {
    constexpr operator ShaderType() const { return ShaderType(GL_GEOMETRY_SHADER); }
  };
  static GeometryShaderEnum GeometryShader;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
  struct GequalEnum {
    constexpr operator CompareFunc() const { return CompareFunc(GL_GEQUAL); }
  };
  static GequalEnum Gequal;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
  struct GreaterEnum {
    constexpr operator CompareFunc() const { return CompareFunc(GL_GREATER); }
  };
  static GreaterEnum Greater;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
  struct GreenEnum {
    constexpr operator SwizzleMode() const { return SwizzleMode(GL_GREEN); }
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_GREEN); }
  };
  static GreenEnum Green;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
  struct GreenIntegerEnum {
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_GREEN_INTEGER); }
  };
  static GreenIntegerEnum GreenInteger;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_HALF_FLOAT)
  struct HalfFloatEnum {
    constexpr operator DataType() const { return DataType(GL_HALF_FLOAT); }
    constexpr operator PixelDataType() const { return PixelDataType(GL_HALF_FLOAT); }
  };
  static HalfFloatEnum HalfFloat;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
  struct IncrEnum {
    constexpr operator StencilOperation() const { return StencilOperation(GL_INCR); }
  };
  static IncrEnum Incr;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
  struct IncrWrapEnum {
    constexpr operator StencilOperation() const { return StencilOperation(GL_INCR_WRAP); }
  };
  static IncrWrapEnum IncrWrap;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INT)
  struct IntEnum {
    constexpr operator DataType() const { return DataType(GL_INT); }
    constexpr operator PixelDataType() const { return PixelDataType(GL_INT); }
    constexpr operator WholeDataType() const { return WholeDataType(GL_INT); }
  };
  static IntEnum Int;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
  struct InvalidEnumEnum {
    constexpr operator ErrorType() const { return ErrorType(GL_INVALID_ENUM); }
  };
  static InvalidEnumEnum InvalidEnum;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
  struct InvalidFramebufferOperationEnum {
    constexpr operator ErrorType() const { return ErrorType(GL_INVALID_FRAMEBUFFER_OPERATION); }
  };
  static InvalidFramebufferOperationEnum InvalidFramebufferOperation;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
  struct InvalidOperationEnum {
    constexpr operator ErrorType() const { return ErrorType(GL_INVALID_OPERATION); }
  };
  static InvalidOperationEnum InvalidOperation;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
  struct InvalidValueEnum {
    constexpr operator ErrorType() const { return ErrorType(GL_INVALID_VALUE); }
  };
  static InvalidValueEnum InvalidValue;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
  struct InvertEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_INVERT); }
    constexpr operator StencilOperation() const { return StencilOperation(GL_INVERT); }
  };
  static InvertEnum Invert;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
  struct KeepEnum {
    constexpr operator StencilOperation() const { return StencilOperation(GL_KEEP); }
  };
  static KeepEnum Keep;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
  struct LastVertexConventionEnum {
    constexpr operator ProvokeMode() const { return ProvokeMode(GL_LAST_VERTEX_CONVENTION); }
  };
  static LastVertexConventionEnum LastVertexConvention;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEFT)
  struct LeftEnum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_LEFT); }
  };
  static LeftEnum Left;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
  struct LequalEnum {
    constexpr operator CompareFunc() const { return CompareFunc(GL_LEQUAL); }
  };
  static LequalEnum Lequal;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
  struct LessEnum {
    constexpr operator CompareFunc() const { return CompareFunc(GL_LESS); }
  };
  static LessEnum Less;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
  struct LineEnum {
    constexpr operator PolyMode() const { return PolyMode(GL_LINE); }
  };
  static LineEnum Line;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
  struct LinearEnum {
    constexpr operator MinFilter() const { return MinFilter(GL_LINEAR); }
    constexpr operator BlitFilter() const { return BlitFilter(GL_LINEAR); }
    constexpr operator MagFilter() const { return MagFilter(GL_LINEAR); }
  };
  static LinearEnum Linear;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_LINEAR)
  struct LinearMipmapLinearEnum {
    constexpr operator MinFilter() const { return MinFilter(GL_LINEAR_MIPMAP_LINEAR); }
  };
  static LinearMipmapLinearEnum LinearMipmapLinear;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_NEAREST)
  struct LinearMipmapNearestEnum {
    constexpr operator MinFilter() const { return MinFilter(GL_LINEAR_MIPMAP_NEAREST); }
  };
  static LinearMipmapNearestEnum LinearMipmapNearest;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
  struct LinesEnum {
    constexpr operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_LINES); }
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINES); }
  };
  static LinesEnum Lines;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
  struct LinesAdjacencyEnum {
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINES_ADJACENCY); }
  };
  static LinesAdjacencyEnum LinesAdjacency;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
  struct LineLoopEnum {
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINE_LOOP); }
  };
  static LineLoopEnum LineLoop;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH)
  struct LineSmoothEnum {
    constexpr operator Capability() const { return Capability(GL_LINE_SMOOTH); }
  };
  static LineSmoothEnum LineSmooth;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
  struct LineStripEnum {
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINE_STRIP); }
  };
  static LineStripEnum LineStrip;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
  struct LineStripAdjacencyEnum {
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINE_STRIP_ADJACENCY); }
  };
  static LineStripAdjacencyEnum LineStripAdjacency;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
  struct MapCoherentBitEnum {
    constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_COHERENT_BIT); }
  };
  static MapCoherentBitEnum MapCoherentBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
  struct MapFlushExplicitBitEnum {
    constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_FLUSH_EXPLICIT_BIT); }
  };
  static MapFlushExplicitBitEnum MapFlushExplicitBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
  struct MapInvalidateBufferBitEnum {
    constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_INVALIDATE_BUFFER_BIT); }
  };
  static MapInvalidateBufferBitEnum MapInvalidateBufferBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
  struct MapInvalidateRangeBitEnum {
    constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_INVALIDATE_RANGE_BIT); }
  };
  static MapInvalidateRangeBitEnum MapInvalidateRangeBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
  struct MapPersistentBitEnum {
    constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_PERSISTENT_BIT); }
  };
  static MapPersistentBitEnum MapPersistentBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
  struct MapReadBitEnum {
    constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_READ_BIT); }
  };
  static MapReadBitEnum MapReadBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
  struct MapUnsynchronizedBitEnum {
    constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_UNSYNCHRONIZED_BIT); }
  };
  static MapUnsynchronizedBitEnum MapUnsynchronizedBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
  struct MapWriteBitEnum {
    constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_WRITE_BIT); }
  };
  static MapWriteBitEnum MapWriteBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAX)
  struct MaxEnum {
    constexpr operator BlendEquation() const { return BlendEquation(GL_MAX); }
  };
  static MaxEnum Max;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN)
  struct MinEnum {
    constexpr operator BlendEquation() const { return BlendEquation(GL_MIN); }
  };
  static MinEnum Min;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIRRORED_REPEAT)
  struct MirroredRepeatEnum {
    constexpr operator WrapMode() const { return WrapMode(GL_MIRRORED_REPEAT); }
  };
  static MirroredRepeatEnum MirroredRepeat;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MULTISAMPLE)
  struct MultisampleEnum {
    constexpr operator Capability() const { return Capability(GL_MULTISAMPLE); }
  };
  static MultisampleEnum Multisample;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
  struct NandEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_NAND); }
  };
  static NandEnum Nand;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
  struct NearestEnum {
    constexpr operator MinFilter() const { return MinFilter(GL_NEAREST); }
    constexpr operator BlitFilter() const { return BlitFilter(GL_NEAREST); }
    constexpr operator MagFilter() const { return MagFilter(GL_NEAREST); }
  };
  static NearestEnum Nearest;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_LINEAR)
  struct NearestMipmapLinearEnum {
    constexpr operator MinFilter() const { return MinFilter(GL_NEAREST_MIPMAP_LINEAR); }
  };
  static NearestMipmapLinearEnum NearestMipmapLinear;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_NEAREST)
  struct NearestMipmapNearestEnum {
    constexpr operator MinFilter() const { return MinFilter(GL_NEAREST_MIPMAP_NEAREST); }
  };
  static NearestMipmapNearestEnum NearestMipmapNearest;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
  struct NeverEnum {
    constexpr operator CompareFunc() const { return CompareFunc(GL_NEVER); }
  };
  static NeverEnum Never;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
  struct NoneEnum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_NONE); }
    constexpr operator CompareMode() const { return CompareMode(GL_NONE); }
  };
  static NoneEnum None;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
  struct NoopEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_NOOP); }
  };
  static NoopEnum Noop;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
  struct NorEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_NOR); }
  };
  static NorEnum Nor;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
  struct NotequalEnum {
    constexpr operator CompareFunc() const { return CompareFunc(GL_NOTEQUAL); }
  };
  static NotequalEnum Notequal;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
  struct NoErrorEnum {
    constexpr operator ErrorType() const { return ErrorType(GL_NO_ERROR); }
  };
  static NoErrorEnum NoError;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
  struct OneEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_ONE); }
    constexpr operator SwizzleMode() const { return SwizzleMode(GL_ONE); }
  };
  static OneEnum One;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_ALPHA)
  struct OneMinusConstantAlphaEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_CONSTANT_ALPHA); }
  };
  static OneMinusConstantAlphaEnum OneMinusConstantAlpha;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_COLOR)
  struct OneMinusConstantColorEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_CONSTANT_COLOR); }
  };
  static OneMinusConstantColorEnum OneMinusConstantColor;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_ALPHA)
  struct OneMinusDstAlphaEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_DST_ALPHA); }
  };
  static OneMinusDstAlphaEnum OneMinusDstAlpha;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_COLOR)
  struct OneMinusDstColorEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_DST_COLOR); }
  };
  static OneMinusDstColorEnum OneMinusDstColor;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_ALPHA)
  struct OneMinusSrc1AlphaEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC1_ALPHA); }
  };
  static OneMinusSrc1AlphaEnum OneMinusSrc1Alpha;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_COLOR)
  struct OneMinusSrc1ColorEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC1_COLOR); }
  };
  static OneMinusSrc1ColorEnum OneMinusSrc1Color;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_ALPHA)
  struct OneMinusSrcAlphaEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC_ALPHA); }
  };
  static OneMinusSrcAlphaEnum OneMinusSrcAlpha;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_COLOR)
  struct OneMinusSrcColorEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC_COLOR); }
  };
  static OneMinusSrcColorEnum OneMinusSrcColor;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
  struct OrEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR); }
  };
  static OrEnum Or;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
  struct OrInvertedEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR_INVERTED); }
  };
  static OrInvertedEnum OrInverted;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
  struct OrReverseEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR_REVERSE); }
  };
  static OrReverseEnum OrReverse;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
  struct OutOfMemoryEnum {
    constexpr operator ErrorType() const { return ErrorType(GL_OUT_OF_MEMORY); }
  };
  static OutOfMemoryEnum OutOfMemory;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ALIGNMENT)
  struct PackAlignmentEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_ALIGNMENT); }
  };
  static PackAlignmentEnum PackAlignment;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_DEPTH)
  struct PackCompressedBlockDepthEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_DEPTH); }
  };
  static PackCompressedBlockDepthEnum PackCompressedBlockDepth;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_HEIGHT)
  struct PackCompressedBlockHeightEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_HEIGHT); }
  };
  static PackCompressedBlockHeightEnum PackCompressedBlockHeight;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_SIZE)
  struct PackCompressedBlockSizeEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_SIZE); }
  };
  static PackCompressedBlockSizeEnum PackCompressedBlockSize;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_WIDTH)
  struct PackCompressedBlockWidthEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_WIDTH); }
  };
  static PackCompressedBlockWidthEnum PackCompressedBlockWidth;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_IMAGE_HEIGHT)
  struct PackImageHeightEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_IMAGE_HEIGHT); }
  };
  static PackImageHeightEnum PackImageHeight;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_LSB_FIRST)
  struct PackLsbFirstEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_LSB_FIRST); }
  };
  static PackLsbFirstEnum PackLsbFirst;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ROW_LENGTH)
  struct PackRowLengthEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_ROW_LENGTH); }
  };
  static PackRowLengthEnum PackRowLength;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_IMAGES)
  struct PackSkipImagesEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_IMAGES); }
  };
  static PackSkipImagesEnum PackSkipImages;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_PIXELS)
  struct PackSkipPixelsEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_PIXELS); }
  };
  static PackSkipPixelsEnum PackSkipPixels;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_ROWS)
  struct PackSkipRowsEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_ROWS); }
  };
  static PackSkipRowsEnum PackSkipRows;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SWAP_BYTES)
  struct PackSwapBytesEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SWAP_BYTES); }
  };
  static PackSwapBytesEnum PackSwapBytes;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
  struct PatchesEnum {
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_PATCHES); }
  };
  static PatchesEnum Patches;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_BUFFER_BARRIER_BIT)
  struct PixelBufferBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_PIXEL_BUFFER_BARRIER_BIT); }
  };
  static PixelBufferBarrierBitEnum PixelBufferBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER)
  struct PixelPackBufferEnum {
    constexpr operator BufferType() const { return BufferType(GL_PIXEL_PACK_BUFFER); }
  };
  static PixelPackBufferEnum PixelPackBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER)
  struct PixelUnpackBufferEnum {
    constexpr operator BufferType() const { return BufferType(GL_PIXEL_UNPACK_BUFFER); }
  };
  static PixelUnpackBufferEnum PixelUnpackBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
  struct PointEnum {
    constexpr operator PolyMode() const { return PolyMode(GL_POINT); }
  };
  static PointEnum Point;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
  struct PointsEnum {
    constexpr operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_POINTS); }
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_POINTS); }
  };
  static PointsEnum Points;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_FILL)
  struct PolygonOffsetFillEnum {
    constexpr operator Capability() const { return Capability(GL_POLYGON_OFFSET_FILL); }
  };
  static PolygonOffsetFillEnum PolygonOffsetFill;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_LINE)
  struct PolygonOffsetLineEnum {
    constexpr operator Capability() const { return Capability(GL_POLYGON_OFFSET_LINE); }
  };
  static PolygonOffsetLineEnum PolygonOffsetLine;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_POINT)
  struct PolygonOffsetPointEnum {
    constexpr operator Capability() const { return Capability(GL_POLYGON_OFFSET_POINT); }
  };
  static PolygonOffsetPointEnum PolygonOffsetPoint;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH)
  struct PolygonSmoothEnum {
    constexpr operator Capability() const { return Capability(GL_POLYGON_SMOOTH); }
  };
  static PolygonSmoothEnum PolygonSmooth;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART)
  struct PrimitiveRestartEnum {
    constexpr operator Capability() const { return Capability(GL_PRIMITIVE_RESTART); }
  };
  static PrimitiveRestartEnum PrimitiveRestart;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART_FIXED_INDEX)
  struct PrimitiveRestartFixedIndexEnum {
    constexpr operator Capability() const { return Capability(GL_PRIMITIVE_RESTART_FIXED_INDEX); }
  };
  static PrimitiveRestartFixedIndexEnum PrimitiveRestartFixedIndex;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PROGRAM_POINT_SIZE)
  struct ProgramPointSizeEnum {
    constexpr operator Capability() const { return Capability(GL_PROGRAM_POINT_SIZE); }
  };
  static ProgramPointSizeEnum ProgramPointSize;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R11F_G11F_B10F)
  struct R11FG11FB10FEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R11F_G11F_B10F); }
  };
  static R11FG11FB10FEnum R11FG11FB10F;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16)
  struct R16Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16); }
  };
  static R16Enum R16;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16F)
  struct R16FEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16F); }
  };
  static R16FEnum R16F;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16I)
  struct R16IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16I); }
  };
  static R16IEnum R16I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16UI)
  struct R16UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16UI); }
  };
  static R16UiEnum R16Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16_SNORM)
  struct R16SnormEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16_SNORM); }
  };
  static R16SnormEnum R16Snorm;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32F)
  struct R32FEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32F); }
  };
  static R32FEnum R32F;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32I)
  struct R32IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32I); }
  };
  static R32IEnum R32I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32UI)
  struct R32UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32UI); }
  };
  static R32UiEnum R32Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R3_G3_B2)
  struct R3G3B2Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R3_G3_B2); }
  };
  static R3G3B2Enum R3G3B2;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8)
  struct R8Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8); }
  };
  static R8Enum R8;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8I)
  struct R8IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8I); }
  };
  static R8IEnum R8I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8UI)
  struct R8UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8UI); }
  };
  static R8UiEnum R8Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8_SNORM)
  struct R8SnormEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8_SNORM); }
  };
  static R8SnormEnum R8Snorm;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RASTERIZER_DISCARD)
  struct RasterizerDiscardEnum {
    constexpr operator Capability() const { return Capability(GL_RASTERIZER_DISCARD); }
  };
  static RasterizerDiscardEnum RasterizerDiscard;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
  struct ReadFramebufferEnum {
    constexpr operator FramebufferType() const { return FramebufferType(GL_READ_FRAMEBUFFER); }
  };
  static ReadFramebufferEnum ReadFramebuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
  struct ReadOnlyEnum {
    constexpr operator BufferMapAccess() const { return BufferMapAccess(GL_READ_ONLY); }
  };
  static ReadOnlyEnum ReadOnly;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
  struct ReadWriteEnum {
    constexpr operator BufferMapAccess() const { return BufferMapAccess(GL_READ_WRITE); }
  };
  static ReadWriteEnum ReadWrite;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
  struct RedEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RED); }
    constexpr operator SwizzleMode() const { return SwizzleMode(GL_RED); }
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RED); }
  };
  static RedEnum Red;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
  struct RedIntegerEnum {
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RED_INTEGER); }
  };
  static RedIntegerEnum RedInteger;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPEAT)
  struct RepeatEnum {
    constexpr operator WrapMode() const { return WrapMode(GL_REPEAT); }
  };
  static RepeatEnum Repeat;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
  struct ReplaceEnum {
    constexpr operator StencilOperation() const { return StencilOperation(GL_REPLACE); }
  };
  static ReplaceEnum Replace;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG)
  struct RgEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG); }
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RG); }
  };
  static RgEnum Rg;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16)
  struct Rg16Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16); }
  };
  static Rg16Enum Rg16;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16F)
  struct Rg16FEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16F); }
  };
  static Rg16FEnum Rg16F;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16I)
  struct Rg16IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16I); }
  };
  static Rg16IEnum Rg16I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16UI)
  struct Rg16UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16UI); }
  };
  static Rg16UiEnum Rg16Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16_SNORM)
  struct Rg16SnormEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16_SNORM); }
  };
  static Rg16SnormEnum Rg16Snorm;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32F)
  struct Rg32FEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32F); }
  };
  static Rg32FEnum Rg32F;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32I)
  struct Rg32IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32I); }
  };
  static Rg32IEnum Rg32I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32UI)
  struct Rg32UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32UI); }
  };
  static Rg32UiEnum Rg32Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8)
  struct Rg8Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8); }
  };
  static Rg8Enum Rg8;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8I)
  struct Rg8IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8I); }
  };
  static Rg8IEnum Rg8I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8UI)
  struct Rg8UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8UI); }
  };
  static Rg8UiEnum Rg8Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8_SNORM)
  struct Rg8SnormEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8_SNORM); }
  };
  static Rg8SnormEnum Rg8Snorm;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
  struct RgbEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB); }
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGB); }
  };
  static RgbEnum Rgb;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10)
  struct Rgb10Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10); }
  };
  static Rgb10Enum Rgb10;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2)
  struct Rgb10A2Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10_A2); }
  };
  static Rgb10A2Enum Rgb10A2;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2UI)
  struct Rgb10A2UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10_A2UI); }
  };
  static Rgb10A2UiEnum Rgb10A2Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB12)
  struct Rgb12Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB12); }
  };
  static Rgb12Enum Rgb12;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16)
  struct Rgb16Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16); }
  };
  static Rgb16Enum Rgb16;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16F)
  struct Rgb16FEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16F); }
  };
  static Rgb16FEnum Rgb16F;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16I)
  struct Rgb16IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16I); }
  };
  static Rgb16IEnum Rgb16I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16UI)
  struct Rgb16UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16UI); }
  };
  static Rgb16UiEnum Rgb16Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16_SNORM)
  struct Rgb16SnormEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16_SNORM); }
  };
  static Rgb16SnormEnum Rgb16Snorm;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32F)
  struct Rgb32FEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32F); }
  };
  static Rgb32FEnum Rgb32F;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32I)
  struct Rgb32IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32I); }
  };
  static Rgb32IEnum Rgb32I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32UI)
  struct Rgb32UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32UI); }
  };
  static Rgb32UiEnum Rgb32Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB4)
  struct Rgb4Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB4); }
  };
  static Rgb4Enum Rgb4;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5)
  struct Rgb5Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB5); }
  };
  static Rgb5Enum Rgb5;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5_A1)
  struct Rgb5A1Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB5_A1); }
  };
  static Rgb5A1Enum Rgb5A1;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8)
  struct Rgb8Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8); }
  };
  static Rgb8Enum Rgb8;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8I)
  struct Rgb8IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8I); }
  };
  static Rgb8IEnum Rgb8I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8UI)
  struct Rgb8UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8UI); }
  };
  static Rgb8UiEnum Rgb8Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8_SNORM)
  struct Rgb8SnormEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8_SNORM); }
  };
  static Rgb8SnormEnum Rgb8Snorm;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB9_E5)
  struct Rgb9E5Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB9_E5); }
  };
  static Rgb9E5Enum Rgb9E5;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
  struct RgbaEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA); }
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGBA); }
  };
  static RgbaEnum Rgba;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA12)
  struct Rgba12Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA12); }
  };
  static Rgba12Enum Rgba12;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16)
  struct Rgba16Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16); }
  };
  static Rgba16Enum Rgba16;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16F)
  struct Rgba16FEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16F); }
  };
  static Rgba16FEnum Rgba16F;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16I)
  struct Rgba16IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16I); }
  };
  static Rgba16IEnum Rgba16I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16UI)
  struct Rgba16UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16UI); }
  };
  static Rgba16UiEnum Rgba16Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16_SNORM)
  struct Rgba16SnormEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16_SNORM); }
  };
  static Rgba16SnormEnum Rgba16Snorm;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA2)
  struct Rgba2Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA2); }
  };
  static Rgba2Enum Rgba2;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32F)
  struct Rgba32FEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32F); }
  };
  static Rgba32FEnum Rgba32F;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32I)
  struct Rgba32IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32I); }
  };
  static Rgba32IEnum Rgba32I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32UI)
  struct Rgba32UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32UI); }
  };
  static Rgba32UiEnum Rgba32Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA4)
  struct Rgba4Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA4); }
  };
  static Rgba4Enum Rgba4;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8)
  struct Rgba8Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8); }
  };
  static Rgba8Enum Rgba8;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8I)
  struct Rgba8IEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8I); }
  };
  static Rgba8IEnum Rgba8I;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8UI)
  struct Rgba8UiEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8UI); }
  };
  static Rgba8UiEnum Rgba8Ui;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8_SNORM)
  struct Rgba8SnormEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8_SNORM); }
  };
  static Rgba8SnormEnum Rgba8Snorm;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
  struct RgbaIntegerEnum {
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGBA_INTEGER); }
  };
  static RgbaIntegerEnum RgbaInteger;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
  struct RgbIntegerEnum {
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGB_INTEGER); }
  };
  static RgbIntegerEnum RgbInteger;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
  struct RgIntegerEnum {
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RG_INTEGER); }
  };
  static RgIntegerEnum RgInteger;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RIGHT)
  struct RightEnum {
    constexpr operator ColorBuffer() const { return ColorBuffer(GL_RIGHT); }
  };
  static RightEnum Right;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_COVERAGE)
  struct SampleAlphaToCoverageEnum {
    constexpr operator Capability() const { return Capability(GL_SAMPLE_ALPHA_TO_COVERAGE); }
  };
  static SampleAlphaToCoverageEnum SampleAlphaToCoverage;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_ONE)
  struct SampleAlphaToOneEnum {
    constexpr operator Capability() const { return Capability(GL_SAMPLE_ALPHA_TO_ONE); }
  };
  static SampleAlphaToOneEnum SampleAlphaToOne;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_COVERAGE)
  struct SampleCoverageEnum {
    constexpr operator Capability() const { return Capability(GL_SAMPLE_COVERAGE); }
  };
  static SampleCoverageEnum SampleCoverage;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_MASK)
  struct SampleMaskEnum {
    constexpr operator Capability() const { return Capability(GL_SAMPLE_MASK); }
  };
  static SampleMaskEnum SampleMask;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_SHADING)
  struct SampleShadingEnum {
    constexpr operator Capability() const { return Capability(GL_SAMPLE_SHADING); }
  };
  static SampleShadingEnum SampleShading;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_TEST)
  struct ScissorTestEnum {
    constexpr operator Capability() const { return Capability(GL_SCISSOR_TEST); }
  };
  static ScissorTestEnum ScissorTest;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
  struct SetEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_SET); }
  };
  static SetEnum Set;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT)
  struct ShaderImageAccessBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT); }
  };
  static ShaderImageAccessBarrierBitEnum ShaderImageAccessBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BARRIER_BIT)
  struct ShaderStorageBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_SHADER_STORAGE_BARRIER_BIT); }
  };
  static ShaderStorageBarrierBitEnum ShaderStorageBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
  struct ShaderStorageBufferEnum {
    constexpr operator IndexedBufferType() const { return IndexedBufferType(GL_SHADER_STORAGE_BUFFER); }
    constexpr operator BufferType() const { return BufferType(GL_SHADER_STORAGE_BUFFER); }
  };
  static ShaderStorageBufferEnum ShaderStorageBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHORT)
  struct ShortEnum {
    constexpr operator DataType() const { return DataType(GL_SHORT); }
    constexpr operator PixelDataType() const { return PixelDataType(GL_SHORT); }
    constexpr operator WholeDataType() const { return WholeDataType(GL_SHORT); }
  };
  static ShortEnum Short;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_ALPHA)
  struct Src1AlphaEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_SRC1_ALPHA); }
  };
  static Src1AlphaEnum Src1Alpha;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_COLOR)
  struct Src1ColorEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_SRC1_COLOR); }
  };
  static Src1ColorEnum Src1Color;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA)
  struct SrcAlphaEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_SRC_ALPHA); }
  };
  static SrcAlphaEnum SrcAlpha;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA_SATURATE)
  struct SrcAlphaSaturateEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_SRC_ALPHA_SATURATE); }
  };
  static SrcAlphaSaturateEnum SrcAlphaSaturate;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_COLOR)
  struct SrcColorEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_SRC_COLOR); }
  };
  static SrcColorEnum SrcColor;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB)
  struct SrgbEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB); }
  };
  static SrgbEnum Srgb;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8)
  struct Srgb8Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB8); }
  };
  static Srgb8Enum Srgb8;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8_ALPHA8)
  struct Srgb8Alpha8Enum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB8_ALPHA8); }
  };
  static Srgb8Alpha8Enum Srgb8Alpha8;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB_ALPHA)
  struct SrgbAlphaEnum {
    constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB_ALPHA); }
  };
  static SrgbAlphaEnum SrgbAlpha;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
  struct StackOverflowEnum {
    constexpr operator ErrorType() const { return ErrorType(GL_STACK_OVERFLOW); }
  };
  static StackOverflowEnum StackOverflow;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
  struct StackUnderflowEnum {
    constexpr operator ErrorType() const { return ErrorType(GL_STACK_UNDERFLOW); }
  };
  static StackUnderflowEnum StackUnderflow;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_COPY)
  struct StaticCopyEnum {
    constexpr operator BufferUsage() const { return BufferUsage(GL_STATIC_COPY); }
  };
  static StaticCopyEnum StaticCopy;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_DRAW)
  struct StaticDrawEnum {
    constexpr operator BufferUsage() const { return BufferUsage(GL_STATIC_DRAW); }
  };
  static StaticDrawEnum StaticDraw;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_READ)
  struct StaticReadEnum {
    constexpr operator BufferUsage() const { return BufferUsage(GL_STATIC_READ); }
  };
  static StaticReadEnum StaticRead;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_ATTACHMENT)
  struct StencilAttachmentEnum {
    constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_STENCIL_ATTACHMENT); }
  };
  static StencilAttachmentEnum StencilAttachment;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
  struct StencilBufferBitEnum {
    constexpr operator BufferSelectBit() const { return BufferSelectBit(GL_STENCIL_BUFFER_BIT); }
  };
  static StencilBufferBitEnum StencilBufferBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_INDEX)
  struct StencilIndexEnum {
    constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_STENCIL_INDEX); }
  };
  static StencilIndexEnum StencilIndex;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_TEST)
  struct StencilTestEnum {
    constexpr operator Capability() const { return Capability(GL_STENCIL_TEST); }
  };
  static StencilTestEnum StencilTest;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_COPY)
  struct StreamCopyEnum {
    constexpr operator BufferUsage() const { return BufferUsage(GL_STREAM_COPY); }
  };
  static StreamCopyEnum StreamCopy;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_DRAW)
  struct StreamDrawEnum {
    constexpr operator BufferUsage() const { return BufferUsage(GL_STREAM_DRAW); }
  };
  static StreamDrawEnum StreamDraw;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_READ)
  struct StreamReadEnum {
    constexpr operator BufferUsage() const { return BufferUsage(GL_STREAM_READ); }
  };
  static StreamReadEnum StreamRead;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
  struct TableTooLargeEnum {
    constexpr operator ErrorType() const { return ErrorType(GL_TABLE_TOO_LARGE); }
  };
  static TableTooLargeEnum TableTooLarge;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
  struct TessControlShaderEnum {
    constexpr operator ShaderType() const { return ShaderType(GL_TESS_CONTROL_SHADER); }
  };
  static TessControlShaderEnum TessControlShader;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
  struct TessEvaluationShaderEnum {
    constexpr operator ShaderType() const { return ShaderType(GL_TESS_EVALUATION_SHADER); }
  };
  static TessEvaluationShaderEnum TessEvaluationShader;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D)
  struct Texture1DEnum {
    constexpr operator TextureType() const { return TextureType(GL_TEXTURE_1D); }
  };
  static Texture1DEnum Texture1D;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
  struct Texture1DArrayEnum {
    constexpr operator TextureType() const { return TextureType(GL_TEXTURE_1D_ARRAY); }
    constexpr operator Texture2DType() const { return Texture2DType(GL_TEXTURE_1D_ARRAY); }
  };
  static Texture1DArrayEnum Texture1DArray;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
  struct Texture2DEnum {
    constexpr operator TextureType() const { return TextureType(GL_TEXTURE_2D); }
    constexpr operator Texture2DType() const { return Texture2DType(GL_TEXTURE_2D); }
  };
  static Texture2DEnum Texture2D;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
  struct Texture2DArrayEnum {
    constexpr operator TextureType() const { return TextureType(GL_TEXTURE_2D_ARRAY); }
    constexpr operator Texture3DType() const { return Texture3DType(GL_TEXTURE_2D_ARRAY); }
  };
  static Texture2DArrayEnum Texture2DArray;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
  struct Texture3DEnum {
    constexpr operator TextureType() const { return TextureType(GL_TEXTURE_3D); }
    constexpr operator Texture3DType() const { return Texture3DType(GL_TEXTURE_3D); }
  };
  static Texture3DEnum Texture3D;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
  struct TextureBufferEnum {
    constexpr operator BufferType() const { return BufferType(GL_TEXTURE_BUFFER); }
  };
  static TextureBufferEnum TextureBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
  struct TextureCubeMapEnum {
    constexpr operator TextureType() const { return TextureType(GL_TEXTURE_CUBE_MAP); }
    constexpr operator Texture2DType() const { return Texture2DType(GL_TEXTURE_CUBE_MAP); }
  };
  static TextureCubeMapEnum TextureCubeMap;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
  struct TextureCubeMapNegativeXEnum {
    constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_X); }
  };
  static TextureCubeMapNegativeXEnum TextureCubeMapNegativeX;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
  struct TextureCubeMapNegativeYEnum {
    constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y); }
  };
  static TextureCubeMapNegativeYEnum TextureCubeMapNegativeY;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
  struct TextureCubeMapNegativeZEnum {
    constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z); }
  };
  static TextureCubeMapNegativeZEnum TextureCubeMapNegativeZ;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
  struct TextureCubeMapPositiveXEnum {
    constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_X); }
  };
  static TextureCubeMapPositiveXEnum TextureCubeMapPositiveX;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
  struct TextureCubeMapPositiveYEnum {
    constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_Y); }
  };
  static TextureCubeMapPositiveYEnum TextureCubeMapPositiveY;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
  struct TextureCubeMapPositiveZEnum {
    constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_Z); }
  };
  static TextureCubeMapPositiveZEnum TextureCubeMapPositiveZ;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_SEAMLESS)
  struct TextureCubeMapSeamlessEnum {
    constexpr operator Capability() const { return Capability(GL_TEXTURE_CUBE_MAP_SEAMLESS); }
  };
  static TextureCubeMapSeamlessEnum TextureCubeMapSeamless;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_FETCH_BARRIER_BIT)
  struct TextureFetchBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TEXTURE_FETCH_BARRIER_BIT); }
  };
  static TextureFetchBarrierBitEnum TextureFetchBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
  struct TextureRectangleEnum {
    constexpr operator TextureType() const { return TextureType(GL_TEXTURE_RECTANGLE); }
    constexpr operator Texture2DType() const { return Texture2DType(GL_TEXTURE_RECTANGLE); }
  };
  static TextureRectangleEnum TextureRectangle;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_UPDATE_BARRIER_BIT)
  struct TextureUpdateBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TEXTURE_UPDATE_BARRIER_BIT); }
  };
  static TextureUpdateBarrierBitEnum TextureUpdateBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BARRIER_BIT)
  struct TransformFeedbackBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TRANSFORM_FEEDBACK_BARRIER_BIT); }
  };
  static TransformFeedbackBarrierBitEnum TransformFeedbackBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
  struct TransformFeedbackBufferEnum {
    constexpr operator IndexedBufferType() const { return IndexedBufferType(GL_TRANSFORM_FEEDBACK_BUFFER); }
    constexpr operator BufferType() const { return BufferType(GL_TRANSFORM_FEEDBACK_BUFFER); }
  };
  static TransformFeedbackBufferEnum TransformFeedbackBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
  struct TrianglesEnum {
    constexpr operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_TRIANGLES); }
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLES); }
  };
  static TrianglesEnum Triangles;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
  struct TrianglesAdjacencyEnum {
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLES_ADJACENCY); }
  };
  static TrianglesAdjacencyEnum TrianglesAdjacency;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
  struct TriangleFanEnum {
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_FAN); }
  };
  static TriangleFanEnum TriangleFan;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
  struct TriangleStripEnum {
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_STRIP); }
  };
  static TriangleStripEnum TriangleStrip;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
  struct TriangleStripAdjacencyEnum {
    constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_STRIP_ADJACENCY); }
  };
  static TriangleStripAdjacencyEnum TriangleStripAdjacency;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BARRIER_BIT)
  struct UniformBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_UNIFORM_BARRIER_BIT); }
  };
  static UniformBarrierBitEnum UniformBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
  struct UniformBufferEnum {
    constexpr operator IndexedBufferType() const { return IndexedBufferType(GL_UNIFORM_BUFFER); }
    constexpr operator BufferType() const { return BufferType(GL_UNIFORM_BUFFER); }
  };
  static UniformBufferEnum UniformBuffer;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ALIGNMENT)
  struct UnpackAlignmentEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_ALIGNMENT); }
  };
  static UnpackAlignmentEnum UnpackAlignment;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_DEPTH)
  struct UnpackCompressedBlockDepthEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_DEPTH); }
  };
  static UnpackCompressedBlockDepthEnum UnpackCompressedBlockDepth;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT)
  struct UnpackCompressedBlockHeightEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT); }
  };
  static UnpackCompressedBlockHeightEnum UnpackCompressedBlockHeight;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_SIZE)
  struct UnpackCompressedBlockSizeEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_SIZE); }
  };
  static UnpackCompressedBlockSizeEnum UnpackCompressedBlockSize;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_WIDTH)
  struct UnpackCompressedBlockWidthEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_WIDTH); }
  };
  static UnpackCompressedBlockWidthEnum UnpackCompressedBlockWidth;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_IMAGE_HEIGHT)
  struct UnpackImageHeightEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_IMAGE_HEIGHT); }
  };
  static UnpackImageHeightEnum UnpackImageHeight;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_LSB_FIRST)
  struct UnpackLsbFirstEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_LSB_FIRST); }
  };
  static UnpackLsbFirstEnum UnpackLsbFirst;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ROW_LENGTH)
  struct UnpackRowLengthEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_ROW_LENGTH); }
  };
  static UnpackRowLengthEnum UnpackRowLength;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_IMAGES)
  struct UnpackSkipImagesEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_IMAGES); }
  };
  static UnpackSkipImagesEnum UnpackSkipImages;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_PIXELS)
  struct UnpackSkipPixelsEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_PIXELS); }
  };
  static UnpackSkipPixelsEnum UnpackSkipPixels;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_ROWS)
  struct UnpackSkipRowsEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_ROWS); }
  };
  static UnpackSkipRowsEnum UnpackSkipRows;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SWAP_BYTES)
  struct UnpackSwapBytesEnum {
    constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SWAP_BYTES); }
  };
  static UnpackSwapBytesEnum UnpackSwapBytes;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE)
  struct UnsignedByteEnum {
    constexpr operator DataType() const { return DataType(GL_UNSIGNED_BYTE); }
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE); }
    constexpr operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_BYTE); }
    constexpr operator IndexType() const { return IndexType(GL_UNSIGNED_BYTE); }
  };
  static UnsignedByteEnum UnsignedByte;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_2_3_3_REV)
  struct UnsignedByte233RevEnum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE_2_3_3_REV); }
  };
  static UnsignedByte233RevEnum UnsignedByte233Rev;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_3_3_2)
  struct UnsignedByte332Enum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE_3_3_2); }
  };
  static UnsignedByte332Enum UnsignedByte332;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT)
  struct UnsignedIntEnum {
    constexpr operator DataType() const { return DataType(GL_UNSIGNED_INT); }
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT); }
    constexpr operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_INT); }
    constexpr operator IndexType() const { return IndexType(GL_UNSIGNED_INT); }
  };
  static UnsignedIntEnum UnsignedInt;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10F_11F_11F_REV)
  struct UnsignedInt10F11F11FRevEnum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_10F_11F_11F_REV); }
  };
  static UnsignedInt10F11F11FRevEnum UnsignedInt10F11F11FRev;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10_10_10_2)
  struct UnsignedInt1010102Enum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_10_10_10_2); }
  };
  static UnsignedInt1010102Enum UnsignedInt1010102;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_24_8)
  struct UnsignedInt248Enum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_24_8); }
  };
  static UnsignedInt248Enum UnsignedInt248;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_2_10_10_10_REV)
  struct UnsignedInt2101010RevEnum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_2_10_10_10_REV); }
  };
  static UnsignedInt2101010RevEnum UnsignedInt2101010Rev;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_5_9_9_9_REV)
  struct UnsignedInt5999RevEnum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_5_9_9_9_REV); }
  };
  static UnsignedInt5999RevEnum UnsignedInt5999Rev;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8)
  struct UnsignedInt8888Enum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_8_8_8_8); }
  };
  static UnsignedInt8888Enum UnsignedInt8888;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8_REV)
  struct UnsignedInt8888RevEnum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_8_8_8_8_REV); }
  };
  static UnsignedInt8888RevEnum UnsignedInt8888Rev;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT)
  struct UnsignedShortEnum {
    constexpr operator DataType() const { return DataType(GL_UNSIGNED_SHORT); }
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT); }
    constexpr operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_SHORT); }
    constexpr operator IndexType() const { return IndexType(GL_UNSIGNED_SHORT); }
  };
  static UnsignedShortEnum UnsignedShort;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_1_5_5_5_REV)
  struct UnsignedShort1555RevEnum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_1_5_5_5_REV); }
  };
  static UnsignedShort1555RevEnum UnsignedShort1555Rev;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4)
  struct UnsignedShort4444Enum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_4_4_4_4); }
  };
  static UnsignedShort4444Enum UnsignedShort4444;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4_REV)
  struct UnsignedShort4444RevEnum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_4_4_4_4_REV); }
  };
  static UnsignedShort4444RevEnum UnsignedShort4444Rev;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_5_5_1)
  struct UnsignedShort5551Enum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_5_5_1); }
  };
  static UnsignedShort5551Enum UnsignedShort5551;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5)
  struct UnsignedShort565Enum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_6_5); }
  };
  static UnsignedShort565Enum UnsignedShort565;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5_REV)
  struct UnsignedShort565RevEnum {
    constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_6_5_REV); }
  };
  static UnsignedShort565RevEnum UnsignedShort565Rev;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT)
  struct VertexAttribArrayBarrierBitEnum {
    constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT); }
  };
  static VertexAttribArrayBarrierBitEnum VertexAttribArrayBarrierBit;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
  struct VertexShaderEnum {
    constexpr operator ShaderType() const { return ShaderType(GL_VERTEX_SHADER); }
  };
  static VertexShaderEnum VertexShader;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
  struct WriteOnlyEnum {
    constexpr operator BufferMapAccess() const { return BufferMapAccess(GL_WRITE_ONLY); }
  };
  static WriteOnlyEnum WriteOnly;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
  struct XorEnum {
    constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_XOR); }
  };
  static XorEnum Xor;
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  struct ZeroEnum {
    constexpr operator BlendFunction() const { return BlendFunction(GL_ZERO); }
    constexpr operator SwizzleMode() const { return SwizzleMode(GL_ZERO); }
    constexpr operator StencilOperation() const { return StencilOperation(GL_ZERO); }
  };
  static ZeroEnum Zero;
#endif


};

#if OGLWRAP_INSTANTIATE
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER)
  SmartEnums::FramebufferIncompleteDrawBufferEnum SmartEnums::FramebufferIncompleteDrawBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5)
  SmartEnums::UnsignedShort565Enum SmartEnums::UnsignedShort565;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_ATTACHMENT)
  SmartEnums::DepthAttachmentEnum SmartEnums::DepthAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DITHER)
  SmartEnums::DitherEnum SmartEnums::Dither;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32UI)
  SmartEnums::R32UiEnum SmartEnums::R32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16_SNORM)
  SmartEnums::R16SnormEnum SmartEnums::R16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT)
  SmartEnums::FloatEnum SmartEnums::Float;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32UI)
  SmartEnums::Rgb32UiEnum SmartEnums::Rgb32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16_SNORM)
  SmartEnums::Rgb16SnormEnum SmartEnums::Rgb16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER)
  SmartEnums::DispatchIndirectBufferEnum SmartEnums::DispatchIndirectBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB9_E5)
  SmartEnums::Rgb9E5Enum SmartEnums::Rgb9E5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32UI)
  SmartEnums::Rgba32UiEnum SmartEnums::Rgba32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8UI)
  SmartEnums::Rg8UiEnum SmartEnums::Rg8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_LINEAR)
  SmartEnums::LinearMipmapLinearEnum SmartEnums::LinearMipmapLinear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
  SmartEnums::TextureCubeMapPositiveYEnum SmartEnums::TextureCubeMapPositiveY;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
  SmartEnums::TextureCubeMapPositiveXEnum SmartEnums::TextureCubeMapPositiveX;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DOUBLE)
  SmartEnums::DoubleEnum SmartEnums::Double;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
  SmartEnums::TextureCubeMapEnum SmartEnums::TextureCubeMap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BYTE)
  SmartEnums::ByteEnum SmartEnums::Byte;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
  SmartEnums::OneEnum SmartEnums::One;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG)
  SmartEnums::RgEnum SmartEnums::Rg;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA_SATURATE)
  SmartEnums::SrcAlphaSaturateEnum SmartEnums::SrcAlphaSaturate;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_DEPTH)
  SmartEnums::PackCompressedBlockDepthEnum SmartEnums::PackCompressedBlockDepth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_IMAGE_HEIGHT)
  SmartEnums::UnpackImageHeightEnum SmartEnums::UnpackImageHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
  SmartEnums::GreenIntegerEnum SmartEnums::GreenInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
  SmartEnums::TriangleStripEnum SmartEnums::TriangleStrip;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
  SmartEnums::NoopEnum SmartEnums::Noop;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_LEFT)
  SmartEnums::FrontLeftEnum SmartEnums::FrontLeft;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_FETCH_BARRIER_BIT)
  SmartEnums::TextureFetchBarrierBitEnum SmartEnums::TextureFetchBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGBA)
  SmartEnums::CompressedRgbaEnum SmartEnums::CompressedRgba;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
  SmartEnums::TriangleStripAdjacencyEnum SmartEnums::TriangleStripAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
  SmartEnums::TransformFeedbackBufferEnum SmartEnums::TransformFeedbackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_5_5_1)
  SmartEnums::UnsignedShort5551Enum SmartEnums::UnsignedShort5551;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SWAP_BYTES)
  SmartEnums::UnpackSwapBytesEnum SmartEnums::UnpackSwapBytes;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
  SmartEnums::MapPersistentBitEnum SmartEnums::MapPersistentBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
  SmartEnums::LineStripAdjacencyEnum SmartEnums::LineStripAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
  SmartEnums::DecrEnum SmartEnums::Decr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
  SmartEnums::BackEnum SmartEnums::Back;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
  SmartEnums::TableTooLargeEnum SmartEnums::TableTooLarge;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB12)
  SmartEnums::Rgb12Enum SmartEnums::Rgb12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INT)
  SmartEnums::IntEnum SmartEnums::Int;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10)
  SmartEnums::Rgb10Enum SmartEnums::Rgb10;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
  SmartEnums::AtomicCounterBufferEnum SmartEnums::AtomicCounterBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16)
  SmartEnums::Rgb16Enum SmartEnums::Rgb16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
  SmartEnums::BgraEnum SmartEnums::Bgra;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_FILL)
  SmartEnums::PolygonOffsetFillEnum SmartEnums::PolygonOffsetFill;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
  SmartEnums::FirstVertexConventionEnum SmartEnums::FirstVertexConvention;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
  SmartEnums::FrontAndBackEnum SmartEnums::FrontAndBack;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8)
  SmartEnums::R8Enum SmartEnums::R8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
  SmartEnums::PointEnum SmartEnums::Point;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG_RGTC2)
  SmartEnums::CompressedRgRgtc2Enum SmartEnums::CompressedRgRgtc2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB)
  SmartEnums::SrgbEnum SmartEnums::Srgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_COLOR)
  SmartEnums::OneMinusConstantColorEnum SmartEnums::OneMinusConstantColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8)
  SmartEnums::UnsignedInt8888Enum SmartEnums::UnsignedInt8888;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8_SNORM)
  SmartEnums::Rgb8SnormEnum SmartEnums::Rgb8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_PIXELS)
  SmartEnums::UnpackSkipPixelsEnum SmartEnums::UnpackSkipPixels;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
  SmartEnums::FragmentShaderEnum SmartEnums::FragmentShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_2_10_10_10_REV)
  SmartEnums::UnsignedInt2101010RevEnum SmartEnums::UnsignedInt2101010Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4)
  SmartEnums::UnsignedShort4444Enum SmartEnums::UnsignedShort4444;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT)
  SmartEnums::DebugOutputEnum SmartEnums::DebugOutput;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
  SmartEnums::NoErrorEnum SmartEnums::NoError;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT)
  SmartEnums::UnpackCompressedBlockHeightEnum SmartEnums::UnpackCompressedBlockHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16UI)
  SmartEnums::Rgba16UiEnum SmartEnums::Rgba16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8I)
  SmartEnums::Rgb8IEnum SmartEnums::Rgb8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
  SmartEnums::AndReverseEnum SmartEnums::AndReverse;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
  SmartEnums::CopyEnum SmartEnums::Copy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
  SmartEnums::FramebufferIncompleteMissingAttachmentEnum SmartEnums::FramebufferIncompleteMissingAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
  SmartEnums::KeepEnum SmartEnums::Keep;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_SEAMLESS)
  SmartEnums::TextureCubeMapSeamlessEnum SmartEnums::TextureCubeMapSeamless;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
  SmartEnums::TextureRectangleEnum SmartEnums::TextureRectangle;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8_SNORM)
  SmartEnums::Rgba8SnormEnum SmartEnums::Rgba8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
  SmartEnums::FillEnum SmartEnums::Fill;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT)
  SmartEnums::ClientMappedBufferBarrierBitEnum SmartEnums::ClientMappedBufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_COLOR)
  SmartEnums::SrcColorEnum SmartEnums::SrcColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
  SmartEnums::AndEnum SmartEnums::And;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
  SmartEnums::RgbaIntegerEnum SmartEnums::RgbaInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_COPY)
  SmartEnums::StaticCopyEnum SmartEnums::StaticCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
  SmartEnums::BgrIntegerEnum SmartEnums::BgrInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_ALPHA)
  SmartEnums::OneMinusDstAlphaEnum SmartEnums::OneMinusDstAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
  SmartEnums::DepthBufferBitEnum SmartEnums::DepthBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
  SmartEnums::UniformBufferEnum SmartEnums::UniformBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
  SmartEnums::MapWriteBitEnum SmartEnums::MapWriteBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
  SmartEnums::CcwEnum SmartEnums::Ccw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_RIGHT)
  SmartEnums::FrontRightEnum SmartEnums::FrontRight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D)
  SmartEnums::Texture1DEnum SmartEnums::Texture1D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
  SmartEnums::MapInvalidateBufferBitEnum SmartEnums::MapInvalidateBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_5_9_9_9_REV)
  SmartEnums::UnsignedInt5999RevEnum SmartEnums::UnsignedInt5999Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_TEST)
  SmartEnums::DepthTestEnum SmartEnums::DepthTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MULTISAMPLE)
  SmartEnums::MultisampleEnum SmartEnums::Multisample;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_COLOR)
  SmartEnums::OneMinusSrc1ColorEnum SmartEnums::OneMinusSrc1Color;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_READ)
  SmartEnums::StreamReadEnum SmartEnums::StreamRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
  SmartEnums::LinearEnum SmartEnums::Linear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_SUBTRACT)
  SmartEnums::FuncSubtractEnum SmartEnums::FuncSubtract;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32F)
  SmartEnums::R32FEnum SmartEnums::R32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER)
  SmartEnums::DrawIndirectBufferEnum SmartEnums::DrawIndirectBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
  SmartEnums::OrReverseEnum SmartEnums::OrReverse;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_BORDER)
  SmartEnums::ClampToBorderEnum SmartEnums::ClampToBorder;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT15)
  SmartEnums::ColorAttachment15Enum SmartEnums::ColorAttachment15;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT14)
  SmartEnums::ColorAttachment14Enum SmartEnums::ColorAttachment14;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
  SmartEnums::GreaterEnum SmartEnums::Greater;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMMAND_BARRIER_BIT)
  SmartEnums::CommandBarrierBitEnum SmartEnums::CommandBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT13)
  SmartEnums::ColorAttachment13Enum SmartEnums::ColorAttachment13;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT12)
  SmartEnums::ColorAttachment12Enum SmartEnums::ColorAttachment12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
  SmartEnums::NearestEnum SmartEnums::Nearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
  SmartEnums::ReplaceEnum SmartEnums::Replace;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
  SmartEnums::FramebufferIncompleteAttachmentEnum SmartEnums::FramebufferIncompleteAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
  SmartEnums::RedIntegerEnum SmartEnums::RedInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8I)
  SmartEnums::Rg8IEnum SmartEnums::Rg8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8I)
  SmartEnums::Rgba8IEnum SmartEnums::Rgba8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_ALPHA)
  SmartEnums::Src1AlphaEnum SmartEnums::Src1Alpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_LEFT)
  SmartEnums::BackLeftEnum SmartEnums::BackLeft;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH)
  SmartEnums::LineSmoothEnum SmartEnums::LineSmooth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
  SmartEnums::ComputeShaderEnum SmartEnums::ComputeShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
  SmartEnums::TessEvaluationShaderEnum SmartEnums::TessEvaluationShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
  SmartEnums::CopyWriteBufferEnum SmartEnums::CopyWriteBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLEND)
  SmartEnums::BlendEnum SmartEnums::Blend;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIRRORED_REPEAT)
  SmartEnums::MirroredRepeatEnum SmartEnums::MirroredRepeat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16UI)
  SmartEnums::R16UiEnum SmartEnums::R16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT)
  SmartEnums::UnsignedShortEnum SmartEnums::UnsignedShort;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN)
  SmartEnums::MinEnum SmartEnums::Min;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
  SmartEnums::TextureCubeMapNegativeXEnum SmartEnums::TextureCubeMapNegativeX;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB_ALPHA)
  SmartEnums::CompressedSrgbAlphaEnum SmartEnums::CompressedSrgbAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_COLOR)
  SmartEnums::OneMinusDstColorEnum SmartEnums::OneMinusDstColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_COLOR)
  SmartEnums::OneMinusSrcColorEnum SmartEnums::OneMinusSrcColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
  SmartEnums::PatchesEnum SmartEnums::Patches;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
  SmartEnums::ColorBufferBitEnum SmartEnums::ColorBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
  SmartEnums::XorEnum SmartEnums::Xor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
  SmartEnums::InvalidValueEnum SmartEnums::InvalidValue;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB_ALPHA)
  SmartEnums::SrgbAlphaEnum SmartEnums::SrgbAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_NEAREST)
  SmartEnums::NearestMipmapNearestEnum SmartEnums::NearestMipmapNearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16I)
  SmartEnums::Rgba16IEnum SmartEnums::Rgba16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_ROWS)
  SmartEnums::PackSkipRowsEnum SmartEnums::PackSkipRows;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BARRIER_BIT)
  SmartEnums::FramebufferBarrierBitEnum SmartEnums::FramebufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
  SmartEnums::GeometryShaderEnum SmartEnums::GeometryShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8I)
  SmartEnums::R8IEnum SmartEnums::R8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32I)
  SmartEnums::R32IEnum SmartEnums::R32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BARRIER_BIT)
  SmartEnums::TransformFeedbackBarrierBitEnum SmartEnums::TransformFeedbackBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_ALPHA)
  SmartEnums::OneMinusConstantAlphaEnum SmartEnums::OneMinusConstantAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_LINEAR)
  SmartEnums::NearestMipmapLinearEnum SmartEnums::NearestMipmapLinear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
  SmartEnums::TextureCubeMapPositiveZEnum SmartEnums::TextureCubeMapPositiveZ;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEFT)
  SmartEnums::LeftEnum SmartEnums::Left;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
  SmartEnums::AndInvertedEnum SmartEnums::AndInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_SRGB)
  SmartEnums::FramebufferSrgbEnum SmartEnums::FramebufferSrgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
  SmartEnums::LineEnum SmartEnums::Line;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_BUFFER_BARRIER_BIT)
  SmartEnums::PixelBufferBarrierBitEnum SmartEnums::PixelBufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_POINT)
  SmartEnums::PolygonOffsetPointEnum SmartEnums::PolygonOffsetPoint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
  SmartEnums::TessControlShaderEnum SmartEnums::TessControlShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
  SmartEnums::ArrayBufferEnum SmartEnums::ArrayBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_INDEX)
  SmartEnums::StencilIndexEnum SmartEnums::StencilIndex;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
  SmartEnums::BlueIntegerEnum SmartEnums::BlueInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32I)
  SmartEnums::Rgb32IEnum SmartEnums::Rgb32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_COPY)
  SmartEnums::DynamicCopyEnum SmartEnums::DynamicCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
  SmartEnums::BgraIntegerEnum SmartEnums::BgraInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32F)
  SmartEnums::Rgb32FEnum SmartEnums::Rgb32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_ALPHA)
  SmartEnums::OneMinusSrcAlphaEnum SmartEnums::OneMinusSrcAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_2_3_3_REV)
  SmartEnums::UnsignedByte233RevEnum SmartEnums::UnsignedByte233Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_ONE)
  SmartEnums::SampleAlphaToOneEnum SmartEnums::SampleAlphaToOne;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RED_RGTC1)
  SmartEnums::CompressedSignedRedRgtc1Enum SmartEnums::CompressedSignedRedRgtc1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PROGRAM_POINT_SIZE)
  SmartEnums::ProgramPointSizeEnum SmartEnums::ProgramPointSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_DEPTH)
  SmartEnums::UnpackCompressedBlockDepthEnum SmartEnums::UnpackCompressedBlockDepth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16F)
  SmartEnums::Rgba16FEnum SmartEnums::Rgba16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_COVERAGE)
  SmartEnums::SampleAlphaToCoverageEnum SmartEnums::SampleAlphaToCoverage;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32F)
  SmartEnums::Rg32FEnum SmartEnums::Rg32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32I)
  SmartEnums::Rg32IEnum SmartEnums::Rg32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
  SmartEnums::RedEnum SmartEnums::Red;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_LINE)
  SmartEnums::PolygonOffsetLineEnum SmartEnums::PolygonOffsetLine;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_REVERSE_SUBTRACT)
  SmartEnums::FuncReverseSubtractEnum SmartEnums::FuncReverseSubtract;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5_REV)
  SmartEnums::UnsignedShort565RevEnum SmartEnums::UnsignedShort565Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
  SmartEnums::GreenEnum SmartEnums::Green;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
  SmartEnums::InvalidOperationEnum SmartEnums::InvalidOperation;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_HEIGHT)
  SmartEnums::PackCompressedBlockHeightEnum SmartEnums::PackCompressedBlockHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
  SmartEnums::NoneEnum SmartEnums::None;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT5)
  SmartEnums::ColorAttachment5Enum SmartEnums::ColorAttachment5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_HALF_FLOAT)
  SmartEnums::HalfFloatEnum SmartEnums::HalfFloat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT7)
  SmartEnums::ColorAttachment7Enum SmartEnums::ColorAttachment7;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT6)
  SmartEnums::ColorAttachment6Enum SmartEnums::ColorAttachment6;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT1)
  SmartEnums::ColorAttachment1Enum SmartEnums::ColorAttachment1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT0)
  SmartEnums::ColorAttachment0Enum SmartEnums::ColorAttachment0;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT3)
  SmartEnums::ColorAttachment3Enum SmartEnums::ColorAttachment3;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT2)
  SmartEnums::ColorAttachment2Enum SmartEnums::ColorAttachment2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT11)
  SmartEnums::ColorAttachment11Enum SmartEnums::ColorAttachment11;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT9)
  SmartEnums::ColorAttachment9Enum SmartEnums::ColorAttachment9;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT8)
  SmartEnums::ColorAttachment8Enum SmartEnums::ColorAttachment8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_EDGE)
  SmartEnums::ClampToEdgeEnum SmartEnums::ClampToEdge;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
  SmartEnums::FrontEnum SmartEnums::Front;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
  SmartEnums::NandEnum SmartEnums::Nand;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
  SmartEnums::LequalEnum SmartEnums::Lequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8_REV)
  SmartEnums::UnsignedInt8888RevEnum SmartEnums::UnsignedInt8888Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIP_DISTANCE)
  SmartEnums::ClipDistanceEnum SmartEnums::ClipDistance;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
  SmartEnums::SetEnum SmartEnums::Set;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_COLOR)
  SmartEnums::DstColorEnum SmartEnums::DstColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT)
  SmartEnums::UnsignedIntEnum SmartEnums::UnsignedInt;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
  SmartEnums::AlwaysEnum SmartEnums::Always;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_IMAGES)
  SmartEnums::PackSkipImagesEnum SmartEnums::PackSkipImages;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
  SmartEnums::InvalidEnumEnum SmartEnums::InvalidEnum;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGB)
  SmartEnums::CompressedRgbEnum SmartEnums::CompressedRgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_COMPONENT)
  SmartEnums::DepthComponentEnum SmartEnums::DepthComponent;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_COLOR)
  SmartEnums::Src1ColorEnum SmartEnums::Src1Color;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16_SNORM)
  SmartEnums::Rg16SnormEnum SmartEnums::Rg16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
  SmartEnums::MapCoherentBitEnum SmartEnums::MapCoherentBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
  SmartEnums::FramebufferIncompleteMultisampleEnum SmartEnums::FramebufferIncompleteMultisample;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA4)
  SmartEnums::Rgba4Enum SmartEnums::Rgba4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
  SmartEnums::StackUnderflowEnum SmartEnums::StackUnderflow;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
  SmartEnums::RgIntegerEnum SmartEnums::RgInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SWAP_BYTES)
  SmartEnums::PackSwapBytesEnum SmartEnums::PackSwapBytes;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
  SmartEnums::EqualEnum SmartEnums::Equal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL_ATTACHMENT)
  SmartEnums::DepthStencilAttachmentEnum SmartEnums::DepthStencilAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16UI)
  SmartEnums::Rg16UiEnum SmartEnums::Rg16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
  SmartEnums::BlueEnum SmartEnums::Blue;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BARRIER_BIT)
  SmartEnums::AtomicCounterBarrierBitEnum SmartEnums::AtomicCounterBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ALIGNMENT)
  SmartEnums::UnpackAlignmentEnum SmartEnums::UnpackAlignment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
  SmartEnums::LineStripEnum SmartEnums::LineStrip;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_COPY)
  SmartEnums::StreamCopyEnum SmartEnums::StreamCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ROW_LENGTH)
  SmartEnums::PackRowLengthEnum SmartEnums::PackRowLength;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8_SNORM)
  SmartEnums::Rg8SnormEnum SmartEnums::Rg8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_READ)
  SmartEnums::DynamicReadEnum SmartEnums::DynamicRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
  SmartEnums::TextureBufferEnum SmartEnums::TextureBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
  SmartEnums::CopyReadBufferEnum SmartEnums::CopyReadBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_WIDTH)
  SmartEnums::PackCompressedBlockWidthEnum SmartEnums::PackCompressedBlockWidth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL)
  SmartEnums::DepthStencilEnum SmartEnums::DepthStencil;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
  SmartEnums::PointsEnum SmartEnums::Points;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_IMAGE_HEIGHT)
  SmartEnums::PackImageHeightEnum SmartEnums::PackImageHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
  SmartEnums::OrEnum SmartEnums::Or;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
  SmartEnums::MapInvalidateRangeBitEnum SmartEnums::MapInvalidateRangeBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT_SYNCHRONOUS)
  SmartEnums::DebugOutputSynchronousEnum SmartEnums::DebugOutputSynchronous;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8_SNORM)
  SmartEnums::R8SnormEnum SmartEnums::R8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
  SmartEnums::TextureCubeMapNegativeYEnum SmartEnums::TextureCubeMapNegativeY;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER)
  SmartEnums::FramebufferIncompleteReadBufferEnum SmartEnums::FramebufferIncompleteReadBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
  SmartEnums::TrianglesAdjacencyEnum SmartEnums::TrianglesAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
  SmartEnums::TextureCubeMapNegativeZEnum SmartEnums::TextureCubeMapNegativeZ;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5)
  SmartEnums::Rgb5Enum SmartEnums::Rgb5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
  SmartEnums::LineLoopEnum SmartEnums::LineLoop;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
  SmartEnums::MapFlushExplicitBitEnum SmartEnums::MapFlushExplicitBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_PIXELS)
  SmartEnums::PackSkipPixelsEnum SmartEnums::PackSkipPixels;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_RIGHT)
  SmartEnums::BackRightEnum SmartEnums::BackRight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16F)
  SmartEnums::R16FEnum SmartEnums::R16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RIGHT)
  SmartEnums::RightEnum SmartEnums::Right;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
  SmartEnums::GequalEnum SmartEnums::Gequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R3_G3_B2)
  SmartEnums::R3G3B2Enum SmartEnums::R3G3B2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8UI)
  SmartEnums::Rgba8UiEnum SmartEnums::Rgba8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPEAT)
  SmartEnums::RepeatEnum SmartEnums::Repeat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_ALPHA)
  SmartEnums::OneMinusSrc1AlphaEnum SmartEnums::OneMinusSrc1Alpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT4)
  SmartEnums::ColorAttachment4Enum SmartEnums::ColorAttachment4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_ADD)
  SmartEnums::FuncAddEnum SmartEnums::FuncAdd;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED_RGTC1)
  SmartEnums::CompressedRedRgtc1Enum SmartEnums::CompressedRedRgtc1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_24_8)
  SmartEnums::UnsignedInt248Enum SmartEnums::UnsignedInt248;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG)
  SmartEnums::CompressedRgEnum SmartEnums::CompressedRg;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
  SmartEnums::Texture2DEnum SmartEnums::Texture2D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_DRAW)
  SmartEnums::DynamicDrawEnum SmartEnums::DynamicDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
  SmartEnums::OutOfMemoryEnum SmartEnums::OutOfMemory;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
  SmartEnums::LinesAdjacencyEnum SmartEnums::LinesAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4_REV)
  SmartEnums::UnsignedShort4444RevEnum SmartEnums::UnsignedShort4444Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ROW_LENGTH)
  SmartEnums::UnpackRowLengthEnum SmartEnums::UnpackRowLength;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_SIZE)
  SmartEnums::UnpackCompressedBlockSizeEnum SmartEnums::UnpackCompressedBlockSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RASTERIZER_DISCARD)
  SmartEnums::RasterizerDiscardEnum SmartEnums::RasterizerDiscard;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_DRAW)
  SmartEnums::StreamDrawEnum SmartEnums::StreamDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BUFFER_UPDATE_BARRIER_BIT)
  SmartEnums::BufferUpdateBarrierBitEnum SmartEnums::BufferUpdateBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
  SmartEnums::FramebufferEnum SmartEnums::Framebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_TEST)
  SmartEnums::StencilTestEnum SmartEnums::StencilTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R11F_G11F_B10F)
  SmartEnums::R11FG11FB10FEnum SmartEnums::R11FG11FB10F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
  SmartEnums::InvertEnum SmartEnums::Invert;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
  SmartEnums::TriangleFanEnum SmartEnums::TriangleFan;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALPHA)
  SmartEnums::AlphaEnum SmartEnums::Alpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RG_RGTC2)
  SmartEnums::CompressedSignedRgRgtc2Enum SmartEnums::CompressedSignedRgRgtc2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_DRAW)
  SmartEnums::StaticDrawEnum SmartEnums::StaticDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT)
  SmartEnums::ShaderImageAccessBarrierBitEnum SmartEnums::ShaderImageAccessBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
  SmartEnums::InvalidFramebufferOperationEnum SmartEnums::InvalidFramebufferOperation;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
  SmartEnums::TrianglesEnum SmartEnums::Triangles;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
  SmartEnums::ShaderStorageBufferEnum SmartEnums::ShaderStorageBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
  SmartEnums::NorEnum SmartEnums::Nor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8_ALPHA8)
  SmartEnums::Srgb8Alpha8Enum SmartEnums::Srgb8Alpha8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_UPDATE_BARRIER_BIT)
  SmartEnums::TextureUpdateBarrierBitEnum SmartEnums::TextureUpdateBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ALIGNMENT)
  SmartEnums::PackAlignmentEnum SmartEnums::PackAlignment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_LSB_FIRST)
  SmartEnums::UnpackLsbFirstEnum SmartEnums::UnpackLsbFirst;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
  SmartEnums::StencilBufferBitEnum SmartEnums::StencilBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16I)
  SmartEnums::Rgb16IEnum SmartEnums::Rgb16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16F)
  SmartEnums::Rgb16FEnum SmartEnums::Rgb16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_LOGIC_OP)
  SmartEnums::ColorLogicOpEnum SmartEnums::ColorLogicOp;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
  SmartEnums::LastVertexConventionEnum SmartEnums::LastVertexConvention;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_MASK)
  SmartEnums::SampleMaskEnum SmartEnums::SampleMask;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT)
  SmartEnums::VertexAttribArrayBarrierBitEnum SmartEnums::VertexAttribArrayBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNSUPPORTED)
  SmartEnums::FramebufferUnsupportedEnum SmartEnums::FramebufferUnsupported;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_ALPHA)
  SmartEnums::DstAlphaEnum SmartEnums::DstAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
  SmartEnums::LessEnum SmartEnums::Less;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNDEFINED)
  SmartEnums::FramebufferUndefinedEnum SmartEnums::FramebufferUndefined;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
  SmartEnums::Texture1DArrayEnum SmartEnums::Texture1DArray;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB)
  SmartEnums::CompressedSrgbEnum SmartEnums::CompressedSrgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA2)
  SmartEnums::Rgba2Enum SmartEnums::Rgba2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
  SmartEnums::EquivEnum SmartEnums::Equiv;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8)
  SmartEnums::Rgba8Enum SmartEnums::Rgba8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10_10_10_2)
  SmartEnums::UnsignedInt1010102Enum SmartEnums::UnsignedInt1010102;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
  SmartEnums::RgbIntegerEnum SmartEnums::RgbInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART_FIXED_INDEX)
  SmartEnums::PrimitiveRestartFixedIndexEnum SmartEnums::PrimitiveRestartFixedIndex;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8)
  SmartEnums::Srgb8Enum SmartEnums::Srgb8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_ALPHA)
  SmartEnums::ConstantAlphaEnum SmartEnums::ConstantAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16I)
  SmartEnums::R16IEnum SmartEnums::R16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_READ)
  SmartEnums::StaticReadEnum SmartEnums::StaticRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_TEST)
  SmartEnums::ScissorTestEnum SmartEnums::ScissorTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
  SmartEnums::MapReadBitEnum SmartEnums::MapReadBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16)
  SmartEnums::Rg16Enum SmartEnums::Rg16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_IMAGES)
  SmartEnums::UnpackSkipImagesEnum SmartEnums::UnpackSkipImages;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BARRIER_BIT)
  SmartEnums::ShaderStorageBarrierBitEnum SmartEnums::ShaderStorageBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
  SmartEnums::FramebufferIncompleteLayerTargetsEnum SmartEnums::FramebufferIncompleteLayerTargets;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
  SmartEnums::IncrWrapEnum SmartEnums::IncrWrap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
  SmartEnums::DecrWrapEnum SmartEnums::DecrWrap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH)
  SmartEnums::PolygonSmoothEnum SmartEnums::PolygonSmooth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPARE_REF_TO_TEXTURE)
  SmartEnums::CompareRefToTextureEnum SmartEnums::CompareRefToTexture;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
  SmartEnums::IncrEnum SmartEnums::Incr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA12)
  SmartEnums::Rgba12Enum SmartEnums::Rgba12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16)
  SmartEnums::Rgba16Enum SmartEnums::Rgba16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_ROWS)
  SmartEnums::UnpackSkipRowsEnum SmartEnums::UnpackSkipRows;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_CLAMP)
  SmartEnums::DepthClampEnum SmartEnums::DepthClamp;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
  SmartEnums::RgbEnum SmartEnums::Rgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT10)
  SmartEnums::ColorAttachment10Enum SmartEnums::ColorAttachment10;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5_A1)
  SmartEnums::Rgb5A1Enum SmartEnums::Rgb5A1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
  SmartEnums::VertexShaderEnum SmartEnums::VertexShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_1_5_5_5_REV)
  SmartEnums::UnsignedShort1555RevEnum SmartEnums::UnsignedShort1555Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16UI)
  SmartEnums::Rgb16UiEnum SmartEnums::Rgb16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
  SmartEnums::CopyInvertedEnum SmartEnums::CopyInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
  SmartEnums::StackOverflowEnum SmartEnums::StackOverflow;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_COLOR)
  SmartEnums::ConstantColorEnum SmartEnums::ConstantColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32F)
  SmartEnums::Rgba32FEnum SmartEnums::Rgba32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32I)
  SmartEnums::Rgba32IEnum SmartEnums::Rgba32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER)
  SmartEnums::PixelUnpackBufferEnum SmartEnums::PixelUnpackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_NEAREST)
  SmartEnums::LinearMipmapNearestEnum SmartEnums::LinearMipmapNearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8)
  SmartEnums::Rg8Enum SmartEnums::Rg8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2)
  SmartEnums::Rgb10A2Enum SmartEnums::Rgb10A2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
  SmartEnums::MapUnsynchronizedBitEnum SmartEnums::MapUnsynchronizedBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  SmartEnums::ZeroEnum SmartEnums::Zero;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART)
  SmartEnums::PrimitiveRestartEnum SmartEnums::PrimitiveRestart;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
  SmartEnums::ElementArrayBufferEnum SmartEnums::ElementArrayBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
  SmartEnums::ReadOnlyEnum SmartEnums::ReadOnly;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA)
  SmartEnums::SrcAlphaEnum SmartEnums::SrcAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
  SmartEnums::Texture3DEnum SmartEnums::Texture3D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIXED)
  SmartEnums::FixedEnum SmartEnums::Fixed;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8)
  SmartEnums::Rgb8Enum SmartEnums::Rgb8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
  SmartEnums::NotequalEnum SmartEnums::Notequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB4)
  SmartEnums::Rgb4Enum SmartEnums::Rgb4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
  SmartEnums::Float32UnsignedInt248RevEnum SmartEnums::Float32UnsignedInt248Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
  SmartEnums::LinesEnum SmartEnums::Lines;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CULL_FACE)
  SmartEnums::CullFaceEnum SmartEnums::CullFace;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED)
  SmartEnums::CompressedRedEnum SmartEnums::CompressedRed;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
  SmartEnums::BgrEnum SmartEnums::Bgr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16_SNORM)
  SmartEnums::Rgba16SnormEnum SmartEnums::Rgba16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_SHADING)
  SmartEnums::SampleShadingEnum SmartEnums::SampleShading;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32UI)
  SmartEnums::Rg32UiEnum SmartEnums::Rg32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
  SmartEnums::NeverEnum SmartEnums::Never;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BARRIER_BIT)
  SmartEnums::ElementArrayBarrierBitEnum SmartEnums::ElementArrayBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_COMPLETE)
  SmartEnums::FramebufferCompleteEnum SmartEnums::FramebufferComplete;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_SIZE)
  SmartEnums::PackCompressedBlockSizeEnum SmartEnums::PackCompressedBlockSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
  SmartEnums::RgbaEnum SmartEnums::Rgba;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHORT)
  SmartEnums::ShortEnum SmartEnums::Short;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
  SmartEnums::ReadFramebufferEnum SmartEnums::ReadFramebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
  SmartEnums::CwEnum SmartEnums::Cw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
  SmartEnums::ReadWriteEnum SmartEnums::ReadWrite;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE)
  SmartEnums::UnsignedByteEnum SmartEnums::UnsignedByte;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BARRIER_BIT)
  SmartEnums::UniformBarrierBitEnum SmartEnums::UniformBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
  SmartEnums::Texture2DArrayEnum SmartEnums::Texture2DArray;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10F_11F_11F_REV)
  SmartEnums::UnsignedInt10F11F11FRevEnum SmartEnums::UnsignedInt10F11F11FRev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16)
  SmartEnums::R16Enum SmartEnums::R16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8UI)
  SmartEnums::R8UiEnum SmartEnums::R8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER)
  SmartEnums::PixelPackBufferEnum SmartEnums::PixelPackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_LSB_FIRST)
  SmartEnums::PackLsbFirstEnum SmartEnums::PackLsbFirst;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_3_3_2)
  SmartEnums::UnsignedByte332Enum SmartEnums::UnsignedByte332;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAX)
  SmartEnums::MaxEnum SmartEnums::Max;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
  SmartEnums::OrInvertedEnum SmartEnums::OrInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8UI)
  SmartEnums::Rgb8UiEnum SmartEnums::Rgb8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_WIDTH)
  SmartEnums::UnpackCompressedBlockWidthEnum SmartEnums::UnpackCompressedBlockWidth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16F)
  SmartEnums::Rg16FEnum SmartEnums::Rg16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
  SmartEnums::ClearEnum SmartEnums::Clear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16I)
  SmartEnums::Rg16IEnum SmartEnums::Rg16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
  SmartEnums::WriteOnlyEnum SmartEnums::WriteOnly;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_ATTACHMENT)
  SmartEnums::StencilAttachmentEnum SmartEnums::StencilAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_COVERAGE)
  SmartEnums::SampleCoverageEnum SmartEnums::SampleCoverage;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
  SmartEnums::DrawFramebufferEnum SmartEnums::DrawFramebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2UI)
  SmartEnums::Rgb10A2UiEnum SmartEnums::Rgb10A2Ui;
#endif
#endif

} // oglwrap


#include "./undefine_internal_macros.h"

#endif
