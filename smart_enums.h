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
#include "./enums/hint_target.h"
#include "./enums/face_orientation.h"
#include "./enums/hint_option.h"
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

namespace OGLWRAP_NAMESPACE_NAME {
inline namespace enums {
namespace smart_enums {

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALPHA)
struct AlphaEnum {
  constexpr AlphaEnum() { }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
struct AlwaysEnum {
  constexpr AlwaysEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_ALWAYS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
struct AndEnum {
  constexpr AndEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
struct AndInvertedEnum {
  constexpr AndInvertedEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND_INVERTED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
struct AndReverseEnum {
  constexpr AndReverseEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND_REVERSE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
struct ArrayBufferEnum {
  constexpr ArrayBufferEnum() { }
  constexpr operator BufferType() const { return BufferType(GL_ARRAY_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BARRIER_BIT)
struct AtomicCounterBarrierBitEnum {
  constexpr AtomicCounterBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_ATOMIC_COUNTER_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
struct AtomicCounterBufferEnum {
  constexpr AtomicCounterBufferEnum() { }
  constexpr operator IndexedBufferType() const { return IndexedBufferType(GL_ATOMIC_COUNTER_BUFFER); }
  constexpr operator BufferType() const { return BufferType(GL_ATOMIC_COUNTER_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
struct BackEnum {
  constexpr BackEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_BACK); }
  constexpr operator Face() const { return Face(GL_BACK); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_LEFT)
struct BackLeftEnum {
  constexpr BackLeftEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_BACK_LEFT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_RIGHT)
struct BackRightEnum {
  constexpr BackRightEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_BACK_RIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
struct BgrEnum {
  constexpr BgrEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
struct BgraEnum {
  constexpr BgraEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGRA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
struct BgraIntegerEnum {
  constexpr BgraIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGRA_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
struct BgrIntegerEnum {
  constexpr BgrIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGR_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLEND)
struct BlendEnum {
  constexpr BlendEnum() { }
  constexpr operator Capability() const { return Capability(GL_BLEND); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
struct BlueEnum {
  constexpr BlueEnum() { }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_BLUE); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BLUE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
struct BlueIntegerEnum {
  constexpr BlueIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BLUE_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BUFFER_UPDATE_BARRIER_BIT)
struct BufferUpdateBarrierBitEnum {
  constexpr BufferUpdateBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_BUFFER_UPDATE_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BYTE)
struct ByteEnum {
  constexpr ByteEnum() { }
  constexpr operator DataType() const { return DataType(GL_BYTE); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_BYTE); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_BYTE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
struct CcwEnum {
  constexpr CcwEnum() { }
  constexpr operator FaceOrientation() const { return FaceOrientation(GL_CCW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_BORDER)
struct ClampToBorderEnum {
  constexpr ClampToBorderEnum() { }
  constexpr operator WrapMode() const { return WrapMode(GL_CLAMP_TO_BORDER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_EDGE)
struct ClampToEdgeEnum {
  constexpr ClampToEdgeEnum() { }
  constexpr operator WrapMode() const { return WrapMode(GL_CLAMP_TO_EDGE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
struct ClearEnum {
  constexpr ClearEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_CLEAR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT)
struct ClientMappedBufferBarrierBitEnum {
  constexpr ClientMappedBufferBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIP_DISTANCE)
struct ClipDistanceEnum {
  constexpr ClipDistanceEnum() { }
  constexpr operator Capability() const { return Capability(GL_CLIP_DISTANCE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT0)
struct ColorAttachment0Enum {
  constexpr ColorAttachment0Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT0); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT0); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT1)
struct ColorAttachment1Enum {
  constexpr ColorAttachment1Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT1); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT1); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT10)
struct ColorAttachment10Enum {
  constexpr ColorAttachment10Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT10); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT10); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT11)
struct ColorAttachment11Enum {
  constexpr ColorAttachment11Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT11); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT11); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT12)
struct ColorAttachment12Enum {
  constexpr ColorAttachment12Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT12); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT12); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT13)
struct ColorAttachment13Enum {
  constexpr ColorAttachment13Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT13); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT13); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT14)
struct ColorAttachment14Enum {
  constexpr ColorAttachment14Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT14); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT14); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT15)
struct ColorAttachment15Enum {
  constexpr ColorAttachment15Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT15); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT15); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT2)
struct ColorAttachment2Enum {
  constexpr ColorAttachment2Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT2); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT3)
struct ColorAttachment3Enum {
  constexpr ColorAttachment3Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT3); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT3); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT4)
struct ColorAttachment4Enum {
  constexpr ColorAttachment4Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT4); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT4); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT5)
struct ColorAttachment5Enum {
  constexpr ColorAttachment5Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT5); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT5); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT6)
struct ColorAttachment6Enum {
  constexpr ColorAttachment6Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT6); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT6); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT7)
struct ColorAttachment7Enum {
  constexpr ColorAttachment7Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT7); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT7); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT8)
struct ColorAttachment8Enum {
  constexpr ColorAttachment8Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT8); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT9)
struct ColorAttachment9Enum {
  constexpr ColorAttachment9Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT9); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT9); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
struct ColorBufferBitEnum {
  constexpr ColorBufferBitEnum() { }
  constexpr operator BufferSelectBit() const { return BufferSelectBit(GL_COLOR_BUFFER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_LOGIC_OP)
struct ColorLogicOpEnum {
  constexpr ColorLogicOpEnum() { }
  constexpr operator Capability() const { return Capability(GL_COLOR_LOGIC_OP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMMAND_BARRIER_BIT)
struct CommandBarrierBitEnum {
  constexpr CommandBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_COMMAND_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPARE_REF_TO_TEXTURE)
struct CompareRefToTextureEnum {
  constexpr CompareRefToTextureEnum() { }
  constexpr operator CompareMode() const { return CompareMode(GL_COMPARE_REF_TO_TEXTURE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED)
struct CompressedRedEnum {
  constexpr CompressedRedEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED_RGTC1)
struct CompressedRedRgtc1Enum {
  constexpr CompressedRedRgtc1Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RED_RGTC1); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG)
struct CompressedRgEnum {
  constexpr CompressedRgEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RG); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGB)
struct CompressedRgbEnum {
  constexpr CompressedRgbEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RGB); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGBA)
struct CompressedRgbaEnum {
  constexpr CompressedRgbaEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RGBA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG_RGTC2)
struct CompressedRgRgtc2Enum {
  constexpr CompressedRgRgtc2Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RG_RGTC2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RED_RGTC1)
struct CompressedSignedRedRgtc1Enum {
  constexpr CompressedSignedRedRgtc1Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SIGNED_RED_RGTC1); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RG_RGTC2)
struct CompressedSignedRgRgtc2Enum {
  constexpr CompressedSignedRgRgtc2Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SIGNED_RG_RGTC2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB)
struct CompressedSrgbEnum {
  constexpr CompressedSrgbEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SRGB); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB_ALPHA)
struct CompressedSrgbAlphaEnum {
  constexpr CompressedSrgbAlphaEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SRGB_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
struct ComputeShaderEnum {
  constexpr ComputeShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_COMPUTE_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_ALPHA)
struct ConstantAlphaEnum {
  constexpr ConstantAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_CONSTANT_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_COLOR)
struct ConstantColorEnum {
  constexpr ConstantColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_CONSTANT_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
struct CopyEnum {
  constexpr CopyEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_COPY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
struct CopyInvertedEnum {
  constexpr CopyInvertedEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_COPY_INVERTED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
struct CopyReadBufferEnum {
  constexpr CopyReadBufferEnum() { }
  constexpr operator BufferType() const { return BufferType(GL_COPY_READ_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
struct CopyWriteBufferEnum {
  constexpr CopyWriteBufferEnum() { }
  constexpr operator BufferType() const { return BufferType(GL_COPY_WRITE_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CULL_FACE)
struct CullFaceEnum {
  constexpr CullFaceEnum() { }
  constexpr operator Capability() const { return Capability(GL_CULL_FACE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
struct CwEnum {
  constexpr CwEnum() { }
  constexpr operator FaceOrientation() const { return FaceOrientation(GL_CW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT)
struct DebugOutputEnum {
  constexpr DebugOutputEnum() { }
  constexpr operator Capability() const { return Capability(GL_DEBUG_OUTPUT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT_SYNCHRONOUS)
struct DebugOutputSynchronousEnum {
  constexpr DebugOutputSynchronousEnum() { }
  constexpr operator Capability() const { return Capability(GL_DEBUG_OUTPUT_SYNCHRONOUS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
struct DecrEnum {
  constexpr DecrEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_DECR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
struct DecrWrapEnum {
  constexpr DecrWrapEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_DECR_WRAP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_ATTACHMENT)
struct DepthAttachmentEnum {
  constexpr DepthAttachmentEnum() { }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_DEPTH_ATTACHMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
struct DepthBufferBitEnum {
  constexpr DepthBufferBitEnum() { }
  constexpr operator BufferSelectBit() const { return BufferSelectBit(GL_DEPTH_BUFFER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_CLAMP)
struct DepthClampEnum {
  constexpr DepthClampEnum() { }
  constexpr operator Capability() const { return Capability(GL_DEPTH_CLAMP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_COMPONENT)
struct DepthComponentEnum {
  constexpr DepthComponentEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_DEPTH_COMPONENT); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_DEPTH_COMPONENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL)
struct DepthStencilEnum {
  constexpr DepthStencilEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_DEPTH_STENCIL); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_DEPTH_STENCIL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL_ATTACHMENT)
struct DepthStencilAttachmentEnum {
  constexpr DepthStencilAttachmentEnum() { }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_DEPTH_STENCIL_ATTACHMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_TEST)
struct DepthTestEnum {
  constexpr DepthTestEnum() { }
  constexpr operator Capability() const { return Capability(GL_DEPTH_TEST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER)
struct DispatchIndirectBufferEnum {
  constexpr DispatchIndirectBufferEnum() { }
  constexpr operator BufferType() const { return BufferType(GL_DISPATCH_INDIRECT_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DITHER)
struct DitherEnum {
  constexpr DitherEnum() { }
  constexpr operator Capability() const { return Capability(GL_DITHER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DONT_CARE)
struct DontCareEnum {
  constexpr DontCareEnum() { }
  constexpr operator HintOption() const { return HintOption(GL_DONT_CARE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DOUBLE)
struct DoubleEnum {
  constexpr DoubleEnum() { }
  constexpr operator DataType() const { return DataType(GL_DOUBLE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
struct DrawFramebufferEnum {
  constexpr DrawFramebufferEnum() { }
  constexpr operator FramebufferType() const { return FramebufferType(GL_DRAW_FRAMEBUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER)
struct DrawIndirectBufferEnum {
  constexpr DrawIndirectBufferEnum() { }
  constexpr operator BufferType() const { return BufferType(GL_DRAW_INDIRECT_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_ALPHA)
struct DstAlphaEnum {
  constexpr DstAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_DST_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_COLOR)
struct DstColorEnum {
  constexpr DstColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_DST_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_COPY)
struct DynamicCopyEnum {
  constexpr DynamicCopyEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_COPY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_DRAW)
struct DynamicDrawEnum {
  constexpr DynamicDrawEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_DRAW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_READ)
struct DynamicReadEnum {
  constexpr DynamicReadEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_READ); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BARRIER_BIT)
struct ElementArrayBarrierBitEnum {
  constexpr ElementArrayBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_ELEMENT_ARRAY_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
struct ElementArrayBufferEnum {
  constexpr ElementArrayBufferEnum() { }
  constexpr operator BufferType() const { return BufferType(GL_ELEMENT_ARRAY_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
struct EqualEnum {
  constexpr EqualEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_EQUAL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
struct EquivEnum {
  constexpr EquivEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_EQUIV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FASTEST)
struct FastestEnum {
  constexpr FastestEnum() { }
  constexpr operator HintOption() const { return HintOption(GL_FASTEST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
struct FillEnum {
  constexpr FillEnum() { }
  constexpr operator PolyMode() const { return PolyMode(GL_FILL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
struct FirstVertexConventionEnum {
  constexpr FirstVertexConventionEnum() { }
  constexpr operator ProvokeMode() const { return ProvokeMode(GL_FIRST_VERTEX_CONVENTION); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIXED)
struct FixedEnum {
  constexpr FixedEnum() { }
  constexpr operator DataType() const { return DataType(GL_FIXED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT)
struct FloatEnum {
  constexpr FloatEnum() { }
  constexpr operator DataType() const { return DataType(GL_FLOAT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_FLOAT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
struct Float32UnsignedInt248RevEnum {
  constexpr Float32UnsignedInt248RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_FLOAT_32_UNSIGNED_INT_24_8_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
struct FragmentShaderEnum {
  constexpr FragmentShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_FRAGMENT_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
struct FragmentShaderDerivativeHintEnum {
  constexpr FragmentShaderDerivativeHintEnum() { }
  constexpr operator HintTarget() const { return HintTarget(GL_FRAGMENT_SHADER_DERIVATIVE_HINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
struct FramebufferEnum {
  constexpr FramebufferEnum() { }
  constexpr operator FramebufferType() const { return FramebufferType(GL_FRAMEBUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BARRIER_BIT)
struct FramebufferBarrierBitEnum {
  constexpr FramebufferBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_FRAMEBUFFER_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_COMPLETE)
struct FramebufferCompleteEnum {
  constexpr FramebufferCompleteEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_COMPLETE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
struct FramebufferIncompleteAttachmentEnum {
  constexpr FramebufferIncompleteAttachmentEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER)
struct FramebufferIncompleteDrawBufferEnum {
  constexpr FramebufferIncompleteDrawBufferEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
struct FramebufferIncompleteLayerTargetsEnum {
  constexpr FramebufferIncompleteLayerTargetsEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
struct FramebufferIncompleteMissingAttachmentEnum {
  constexpr FramebufferIncompleteMissingAttachmentEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
struct FramebufferIncompleteMultisampleEnum {
  constexpr FramebufferIncompleteMultisampleEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER)
struct FramebufferIncompleteReadBufferEnum {
  constexpr FramebufferIncompleteReadBufferEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_SRGB)
struct FramebufferSrgbEnum {
  constexpr FramebufferSrgbEnum() { }
  constexpr operator Capability() const { return Capability(GL_FRAMEBUFFER_SRGB); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNDEFINED)
struct FramebufferUndefinedEnum {
  constexpr FramebufferUndefinedEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_UNDEFINED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNSUPPORTED)
struct FramebufferUnsupportedEnum {
  constexpr FramebufferUnsupportedEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_UNSUPPORTED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
struct FrontEnum {
  constexpr FrontEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT); }
  constexpr operator Face() const { return Face(GL_FRONT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
struct FrontAndBackEnum {
  constexpr FrontAndBackEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT_AND_BACK); }
  constexpr operator Face() const { return Face(GL_FRONT_AND_BACK); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_LEFT)
struct FrontLeftEnum {
  constexpr FrontLeftEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT_LEFT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_RIGHT)
struct FrontRightEnum {
  constexpr FrontRightEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT_RIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_ADD)
struct FuncAddEnum {
  constexpr FuncAddEnum() { }
  constexpr operator BlendEquation() const { return BlendEquation(GL_FUNC_ADD); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_REVERSE_SUBTRACT)
struct FuncReverseSubtractEnum {
  constexpr FuncReverseSubtractEnum() { }
  constexpr operator BlendEquation() const { return BlendEquation(GL_FUNC_REVERSE_SUBTRACT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_SUBTRACT)
struct FuncSubtractEnum {
  constexpr FuncSubtractEnum() { }
  constexpr operator BlendEquation() const { return BlendEquation(GL_FUNC_SUBTRACT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
struct GeometryShaderEnum {
  constexpr GeometryShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_GEOMETRY_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
struct GequalEnum {
  constexpr GequalEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_GEQUAL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
struct GreaterEnum {
  constexpr GreaterEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_GREATER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
struct GreenEnum {
  constexpr GreenEnum() { }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_GREEN); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_GREEN); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
struct GreenIntegerEnum {
  constexpr GreenIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_GREEN_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_HALF_FLOAT)
struct HalfFloatEnum {
  constexpr HalfFloatEnum() { }
  constexpr operator DataType() const { return DataType(GL_HALF_FLOAT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_HALF_FLOAT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
struct IncrEnum {
  constexpr IncrEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_INCR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
struct IncrWrapEnum {
  constexpr IncrWrapEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_INCR_WRAP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INT)
struct IntEnum {
  constexpr IntEnum() { }
  constexpr operator DataType() const { return DataType(GL_INT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_INT); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_INT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
struct InvalidEnumEnum {
  constexpr InvalidEnumEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_INVALID_ENUM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
struct InvalidFramebufferOperationEnum {
  constexpr InvalidFramebufferOperationEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_INVALID_FRAMEBUFFER_OPERATION); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
struct InvalidOperationEnum {
  constexpr InvalidOperationEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_INVALID_OPERATION); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
struct InvalidValueEnum {
  constexpr InvalidValueEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_INVALID_VALUE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
struct InvertEnum {
  constexpr InvertEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_INVERT); }
  constexpr operator StencilOperation() const { return StencilOperation(GL_INVERT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
struct KeepEnum {
  constexpr KeepEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_KEEP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
struct LastVertexConventionEnum {
  constexpr LastVertexConventionEnum() { }
  constexpr operator ProvokeMode() const { return ProvokeMode(GL_LAST_VERTEX_CONVENTION); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEFT)
struct LeftEnum {
  constexpr LeftEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_LEFT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
struct LequalEnum {
  constexpr LequalEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_LEQUAL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
struct LessEnum {
  constexpr LessEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_LESS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
struct LineEnum {
  constexpr LineEnum() { }
  constexpr operator PolyMode() const { return PolyMode(GL_LINE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
struct LinearEnum {
  constexpr LinearEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_LINEAR); }
  constexpr operator BlitFilter() const { return BlitFilter(GL_LINEAR); }
  constexpr operator MagFilter() const { return MagFilter(GL_LINEAR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_LINEAR)
struct LinearMipmapLinearEnum {
  constexpr LinearMipmapLinearEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_LINEAR_MIPMAP_LINEAR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_NEAREST)
struct LinearMipmapNearestEnum {
  constexpr LinearMipmapNearestEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_LINEAR_MIPMAP_NEAREST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
struct LinesEnum {
  constexpr LinesEnum() { }
  constexpr operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_LINES); }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
struct LinesAdjacencyEnum {
  constexpr LinesAdjacencyEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINES_ADJACENCY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
struct LineLoopEnum {
  constexpr LineLoopEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINE_LOOP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH)
struct LineSmoothEnum {
  constexpr LineSmoothEnum() { }
  constexpr operator Capability() const { return Capability(GL_LINE_SMOOTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH_HINT)
struct LineSmoothHintEnum {
  constexpr LineSmoothHintEnum() { }
  constexpr operator HintTarget() const { return HintTarget(GL_LINE_SMOOTH_HINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
struct LineStripEnum {
  constexpr LineStripEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINE_STRIP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
struct LineStripAdjacencyEnum {
  constexpr LineStripAdjacencyEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINE_STRIP_ADJACENCY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
struct MapCoherentBitEnum {
  constexpr MapCoherentBitEnum() { }
  constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_COHERENT_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
struct MapFlushExplicitBitEnum {
  constexpr MapFlushExplicitBitEnum() { }
  constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_FLUSH_EXPLICIT_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
struct MapInvalidateBufferBitEnum {
  constexpr MapInvalidateBufferBitEnum() { }
  constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_INVALIDATE_BUFFER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
struct MapInvalidateRangeBitEnum {
  constexpr MapInvalidateRangeBitEnum() { }
  constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_INVALIDATE_RANGE_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
struct MapPersistentBitEnum {
  constexpr MapPersistentBitEnum() { }
  constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_PERSISTENT_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
struct MapReadBitEnum {
  constexpr MapReadBitEnum() { }
  constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_READ_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
struct MapUnsynchronizedBitEnum {
  constexpr MapUnsynchronizedBitEnum() { }
  constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_UNSYNCHRONIZED_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
struct MapWriteBitEnum {
  constexpr MapWriteBitEnum() { }
  constexpr operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_WRITE_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAX)
struct MaxEnum {
  constexpr MaxEnum() { }
  constexpr operator BlendEquation() const { return BlendEquation(GL_MAX); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN)
struct MinEnum {
  constexpr MinEnum() { }
  constexpr operator BlendEquation() const { return BlendEquation(GL_MIN); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIRRORED_REPEAT)
struct MirroredRepeatEnum {
  constexpr MirroredRepeatEnum() { }
  constexpr operator WrapMode() const { return WrapMode(GL_MIRRORED_REPEAT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MULTISAMPLE)
struct MultisampleEnum {
  constexpr MultisampleEnum() { }
  constexpr operator Capability() const { return Capability(GL_MULTISAMPLE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
struct NandEnum {
  constexpr NandEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_NAND); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
struct NearestEnum {
  constexpr NearestEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_NEAREST); }
  constexpr operator BlitFilter() const { return BlitFilter(GL_NEAREST); }
  constexpr operator MagFilter() const { return MagFilter(GL_NEAREST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_LINEAR)
struct NearestMipmapLinearEnum {
  constexpr NearestMipmapLinearEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_NEAREST_MIPMAP_LINEAR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_NEAREST)
struct NearestMipmapNearestEnum {
  constexpr NearestMipmapNearestEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_NEAREST_MIPMAP_NEAREST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
struct NeverEnum {
  constexpr NeverEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_NEVER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NICEST)
struct NicestEnum {
  constexpr NicestEnum() { }
  constexpr operator HintOption() const { return HintOption(GL_NICEST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
struct NoneEnum {
  constexpr NoneEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_NONE); }
  constexpr operator CompareMode() const { return CompareMode(GL_NONE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
struct NoopEnum {
  constexpr NoopEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_NOOP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
struct NorEnum {
  constexpr NorEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_NOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
struct NotequalEnum {
  constexpr NotequalEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_NOTEQUAL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
struct NoErrorEnum {
  constexpr NoErrorEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_NO_ERROR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
struct OneEnum {
  constexpr OneEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE); }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_ONE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_ALPHA)
struct OneMinusConstantAlphaEnum {
  constexpr OneMinusConstantAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_CONSTANT_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_COLOR)
struct OneMinusConstantColorEnum {
  constexpr OneMinusConstantColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_CONSTANT_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_ALPHA)
struct OneMinusDstAlphaEnum {
  constexpr OneMinusDstAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_DST_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_COLOR)
struct OneMinusDstColorEnum {
  constexpr OneMinusDstColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_DST_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_ALPHA)
struct OneMinusSrc1AlphaEnum {
  constexpr OneMinusSrc1AlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC1_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_COLOR)
struct OneMinusSrc1ColorEnum {
  constexpr OneMinusSrc1ColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC1_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_ALPHA)
struct OneMinusSrcAlphaEnum {
  constexpr OneMinusSrcAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_COLOR)
struct OneMinusSrcColorEnum {
  constexpr OneMinusSrcColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
struct OrEnum {
  constexpr OrEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
struct OrInvertedEnum {
  constexpr OrInvertedEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR_INVERTED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
struct OrReverseEnum {
  constexpr OrReverseEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR_REVERSE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
struct OutOfMemoryEnum {
  constexpr OutOfMemoryEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_OUT_OF_MEMORY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ALIGNMENT)
struct PackAlignmentEnum {
  constexpr PackAlignmentEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_ALIGNMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_DEPTH)
struct PackCompressedBlockDepthEnum {
  constexpr PackCompressedBlockDepthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_DEPTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_HEIGHT)
struct PackCompressedBlockHeightEnum {
  constexpr PackCompressedBlockHeightEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_HEIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_SIZE)
struct PackCompressedBlockSizeEnum {
  constexpr PackCompressedBlockSizeEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_SIZE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_WIDTH)
struct PackCompressedBlockWidthEnum {
  constexpr PackCompressedBlockWidthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_WIDTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_IMAGE_HEIGHT)
struct PackImageHeightEnum {
  constexpr PackImageHeightEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_IMAGE_HEIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_LSB_FIRST)
struct PackLsbFirstEnum {
  constexpr PackLsbFirstEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_LSB_FIRST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ROW_LENGTH)
struct PackRowLengthEnum {
  constexpr PackRowLengthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_ROW_LENGTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_IMAGES)
struct PackSkipImagesEnum {
  constexpr PackSkipImagesEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_IMAGES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_PIXELS)
struct PackSkipPixelsEnum {
  constexpr PackSkipPixelsEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_PIXELS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_ROWS)
struct PackSkipRowsEnum {
  constexpr PackSkipRowsEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_ROWS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SWAP_BYTES)
struct PackSwapBytesEnum {
  constexpr PackSwapBytesEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SWAP_BYTES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
struct PatchesEnum {
  constexpr PatchesEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_PATCHES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_BUFFER_BARRIER_BIT)
struct PixelBufferBarrierBitEnum {
  constexpr PixelBufferBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_PIXEL_BUFFER_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER)
struct PixelPackBufferEnum {
  constexpr PixelPackBufferEnum() { }
  constexpr operator BufferType() const { return BufferType(GL_PIXEL_PACK_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER)
struct PixelUnpackBufferEnum {
  constexpr PixelUnpackBufferEnum() { }
  constexpr operator BufferType() const { return BufferType(GL_PIXEL_UNPACK_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
struct PointEnum {
  constexpr PointEnum() { }
  constexpr operator PolyMode() const { return PolyMode(GL_POINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
struct PointsEnum {
  constexpr PointsEnum() { }
  constexpr operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_POINTS); }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_POINTS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_FILL)
struct PolygonOffsetFillEnum {
  constexpr PolygonOffsetFillEnum() { }
  constexpr operator Capability() const { return Capability(GL_POLYGON_OFFSET_FILL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_LINE)
struct PolygonOffsetLineEnum {
  constexpr PolygonOffsetLineEnum() { }
  constexpr operator Capability() const { return Capability(GL_POLYGON_OFFSET_LINE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_POINT)
struct PolygonOffsetPointEnum {
  constexpr PolygonOffsetPointEnum() { }
  constexpr operator Capability() const { return Capability(GL_POLYGON_OFFSET_POINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH)
struct PolygonSmoothEnum {
  constexpr PolygonSmoothEnum() { }
  constexpr operator Capability() const { return Capability(GL_POLYGON_SMOOTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH_HINT)
struct PolygonSmoothHintEnum {
  constexpr PolygonSmoothHintEnum() { }
  constexpr operator HintTarget() const { return HintTarget(GL_POLYGON_SMOOTH_HINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART)
struct PrimitiveRestartEnum {
  constexpr PrimitiveRestartEnum() { }
  constexpr operator Capability() const { return Capability(GL_PRIMITIVE_RESTART); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART_FIXED_INDEX)
struct PrimitiveRestartFixedIndexEnum {
  constexpr PrimitiveRestartFixedIndexEnum() { }
  constexpr operator Capability() const { return Capability(GL_PRIMITIVE_RESTART_FIXED_INDEX); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PROGRAM_POINT_SIZE)
struct ProgramPointSizeEnum {
  constexpr ProgramPointSizeEnum() { }
  constexpr operator Capability() const { return Capability(GL_PROGRAM_POINT_SIZE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R11F_G11F_B10F)
struct R11FG11FB10FEnum {
  constexpr R11FG11FB10FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R11F_G11F_B10F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16)
struct R16Enum {
  constexpr R16Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16F)
struct R16FEnum {
  constexpr R16FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16I)
struct R16IEnum {
  constexpr R16IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16UI)
struct R16UiEnum {
  constexpr R16UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16_SNORM)
struct R16SnormEnum {
  constexpr R16SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32F)
struct R32FEnum {
  constexpr R32FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32I)
struct R32IEnum {
  constexpr R32IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32UI)
struct R32UiEnum {
  constexpr R32UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R3_G3_B2)
struct R3G3B2Enum {
  constexpr R3G3B2Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R3_G3_B2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8)
struct R8Enum {
  constexpr R8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8I)
struct R8IEnum {
  constexpr R8IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8UI)
struct R8UiEnum {
  constexpr R8UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8_SNORM)
struct R8SnormEnum {
  constexpr R8SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RASTERIZER_DISCARD)
struct RasterizerDiscardEnum {
  constexpr RasterizerDiscardEnum() { }
  constexpr operator Capability() const { return Capability(GL_RASTERIZER_DISCARD); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
struct ReadFramebufferEnum {
  constexpr ReadFramebufferEnum() { }
  constexpr operator FramebufferType() const { return FramebufferType(GL_READ_FRAMEBUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
struct ReadOnlyEnum {
  constexpr ReadOnlyEnum() { }
  constexpr operator BufferMapAccess() const { return BufferMapAccess(GL_READ_ONLY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
struct ReadWriteEnum {
  constexpr ReadWriteEnum() { }
  constexpr operator BufferMapAccess() const { return BufferMapAccess(GL_READ_WRITE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
struct RedEnum {
  constexpr RedEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RED); }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_RED); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
struct RedIntegerEnum {
  constexpr RedIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RED_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPEAT)
struct RepeatEnum {
  constexpr RepeatEnum() { }
  constexpr operator WrapMode() const { return WrapMode(GL_REPEAT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
struct ReplaceEnum {
  constexpr ReplaceEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_REPLACE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG)
struct RgEnum {
  constexpr RgEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RG); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16)
struct Rg16Enum {
  constexpr Rg16Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16F)
struct Rg16FEnum {
  constexpr Rg16FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16I)
struct Rg16IEnum {
  constexpr Rg16IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16UI)
struct Rg16UiEnum {
  constexpr Rg16UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16_SNORM)
struct Rg16SnormEnum {
  constexpr Rg16SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32F)
struct Rg32FEnum {
  constexpr Rg32FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32I)
struct Rg32IEnum {
  constexpr Rg32IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32UI)
struct Rg32UiEnum {
  constexpr Rg32UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8)
struct Rg8Enum {
  constexpr Rg8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8I)
struct Rg8IEnum {
  constexpr Rg8IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8UI)
struct Rg8UiEnum {
  constexpr Rg8UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8_SNORM)
struct Rg8SnormEnum {
  constexpr Rg8SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
struct RgbEnum {
  constexpr RgbEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGB); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10)
struct Rgb10Enum {
  constexpr Rgb10Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2)
struct Rgb10A2Enum {
  constexpr Rgb10A2Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10_A2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2UI)
struct Rgb10A2UiEnum {
  constexpr Rgb10A2UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10_A2UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB12)
struct Rgb12Enum {
  constexpr Rgb12Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB12); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16)
struct Rgb16Enum {
  constexpr Rgb16Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16F)
struct Rgb16FEnum {
  constexpr Rgb16FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16I)
struct Rgb16IEnum {
  constexpr Rgb16IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16UI)
struct Rgb16UiEnum {
  constexpr Rgb16UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16_SNORM)
struct Rgb16SnormEnum {
  constexpr Rgb16SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32F)
struct Rgb32FEnum {
  constexpr Rgb32FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32I)
struct Rgb32IEnum {
  constexpr Rgb32IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32UI)
struct Rgb32UiEnum {
  constexpr Rgb32UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB4)
struct Rgb4Enum {
  constexpr Rgb4Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB4); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5)
struct Rgb5Enum {
  constexpr Rgb5Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB5); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5_A1)
struct Rgb5A1Enum {
  constexpr Rgb5A1Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB5_A1); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8)
struct Rgb8Enum {
  constexpr Rgb8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8I)
struct Rgb8IEnum {
  constexpr Rgb8IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8UI)
struct Rgb8UiEnum {
  constexpr Rgb8UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8_SNORM)
struct Rgb8SnormEnum {
  constexpr Rgb8SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB9_E5)
struct Rgb9E5Enum {
  constexpr Rgb9E5Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB9_E5); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
struct RgbaEnum {
  constexpr RgbaEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGBA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA12)
struct Rgba12Enum {
  constexpr Rgba12Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA12); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16)
struct Rgba16Enum {
  constexpr Rgba16Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16F)
struct Rgba16FEnum {
  constexpr Rgba16FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16I)
struct Rgba16IEnum {
  constexpr Rgba16IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16UI)
struct Rgba16UiEnum {
  constexpr Rgba16UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16_SNORM)
struct Rgba16SnormEnum {
  constexpr Rgba16SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA2)
struct Rgba2Enum {
  constexpr Rgba2Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32F)
struct Rgba32FEnum {
  constexpr Rgba32FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32I)
struct Rgba32IEnum {
  constexpr Rgba32IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32UI)
struct Rgba32UiEnum {
  constexpr Rgba32UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA4)
struct Rgba4Enum {
  constexpr Rgba4Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA4); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8)
struct Rgba8Enum {
  constexpr Rgba8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8I)
struct Rgba8IEnum {
  constexpr Rgba8IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8UI)
struct Rgba8UiEnum {
  constexpr Rgba8UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8_SNORM)
struct Rgba8SnormEnum {
  constexpr Rgba8SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
struct RgbaIntegerEnum {
  constexpr RgbaIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGBA_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
struct RgbIntegerEnum {
  constexpr RgbIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGB_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
struct RgIntegerEnum {
  constexpr RgIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RG_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RIGHT)
struct RightEnum {
  constexpr RightEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_RIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_COVERAGE)
struct SampleAlphaToCoverageEnum {
  constexpr SampleAlphaToCoverageEnum() { }
  constexpr operator Capability() const { return Capability(GL_SAMPLE_ALPHA_TO_COVERAGE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_ONE)
struct SampleAlphaToOneEnum {
  constexpr SampleAlphaToOneEnum() { }
  constexpr operator Capability() const { return Capability(GL_SAMPLE_ALPHA_TO_ONE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_COVERAGE)
struct SampleCoverageEnum {
  constexpr SampleCoverageEnum() { }
  constexpr operator Capability() const { return Capability(GL_SAMPLE_COVERAGE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_MASK)
struct SampleMaskEnum {
  constexpr SampleMaskEnum() { }
  constexpr operator Capability() const { return Capability(GL_SAMPLE_MASK); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_SHADING)
struct SampleShadingEnum {
  constexpr SampleShadingEnum() { }
  constexpr operator Capability() const { return Capability(GL_SAMPLE_SHADING); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_TEST)
struct ScissorTestEnum {
  constexpr ScissorTestEnum() { }
  constexpr operator Capability() const { return Capability(GL_SCISSOR_TEST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
struct SetEnum {
  constexpr SetEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_SET); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT)
struct ShaderImageAccessBarrierBitEnum {
  constexpr ShaderImageAccessBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BARRIER_BIT)
struct ShaderStorageBarrierBitEnum {
  constexpr ShaderStorageBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_SHADER_STORAGE_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
struct ShaderStorageBufferEnum {
  constexpr ShaderStorageBufferEnum() { }
  constexpr operator IndexedBufferType() const { return IndexedBufferType(GL_SHADER_STORAGE_BUFFER); }
  constexpr operator BufferType() const { return BufferType(GL_SHADER_STORAGE_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHORT)
struct ShortEnum {
  constexpr ShortEnum() { }
  constexpr operator DataType() const { return DataType(GL_SHORT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_SHORT); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_SHORT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_ALPHA)
struct Src1AlphaEnum {
  constexpr Src1AlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_SRC1_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_COLOR)
struct Src1ColorEnum {
  constexpr Src1ColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_SRC1_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA)
struct SrcAlphaEnum {
  constexpr SrcAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_SRC_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA_SATURATE)
struct SrcAlphaSaturateEnum {
  constexpr SrcAlphaSaturateEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_SRC_ALPHA_SATURATE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_COLOR)
struct SrcColorEnum {
  constexpr SrcColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_SRC_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB)
struct SrgbEnum {
  constexpr SrgbEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8)
struct Srgb8Enum {
  constexpr Srgb8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8_ALPHA8)
struct Srgb8Alpha8Enum {
  constexpr Srgb8Alpha8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB8_ALPHA8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB_ALPHA)
struct SrgbAlphaEnum {
  constexpr SrgbAlphaEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
struct StackOverflowEnum {
  constexpr StackOverflowEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_STACK_OVERFLOW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
struct StackUnderflowEnum {
  constexpr StackUnderflowEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_STACK_UNDERFLOW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_COPY)
struct StaticCopyEnum {
  constexpr StaticCopyEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STATIC_COPY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_DRAW)
struct StaticDrawEnum {
  constexpr StaticDrawEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STATIC_DRAW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_READ)
struct StaticReadEnum {
  constexpr StaticReadEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STATIC_READ); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_ATTACHMENT)
struct StencilAttachmentEnum {
  constexpr StencilAttachmentEnum() { }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_STENCIL_ATTACHMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
struct StencilBufferBitEnum {
  constexpr StencilBufferBitEnum() { }
  constexpr operator BufferSelectBit() const { return BufferSelectBit(GL_STENCIL_BUFFER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_INDEX)
struct StencilIndexEnum {
  constexpr StencilIndexEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_STENCIL_INDEX); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_TEST)
struct StencilTestEnum {
  constexpr StencilTestEnum() { }
  constexpr operator Capability() const { return Capability(GL_STENCIL_TEST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_COPY)
struct StreamCopyEnum {
  constexpr StreamCopyEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STREAM_COPY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_DRAW)
struct StreamDrawEnum {
  constexpr StreamDrawEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STREAM_DRAW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_READ)
struct StreamReadEnum {
  constexpr StreamReadEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STREAM_READ); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
struct TableTooLargeEnum {
  constexpr TableTooLargeEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_TABLE_TOO_LARGE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
struct TessControlShaderEnum {
  constexpr TessControlShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_TESS_CONTROL_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
struct TessEvaluationShaderEnum {
  constexpr TessEvaluationShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_TESS_EVALUATION_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D)
struct Texture1DEnum {
  constexpr Texture1DEnum() { }
  constexpr operator TextureType() const { return TextureType(GL_TEXTURE_1D); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
struct Texture1DArrayEnum {
  constexpr Texture1DArrayEnum() { }
  constexpr operator TextureType() const { return TextureType(GL_TEXTURE_1D_ARRAY); }
  constexpr operator Texture2DType() const { return Texture2DType(GL_TEXTURE_1D_ARRAY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
struct Texture2DEnum {
  constexpr Texture2DEnum() { }
  constexpr operator TextureType() const { return TextureType(GL_TEXTURE_2D); }
  constexpr operator Texture2DType() const { return Texture2DType(GL_TEXTURE_2D); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
struct Texture2DArrayEnum {
  constexpr Texture2DArrayEnum() { }
  constexpr operator TextureType() const { return TextureType(GL_TEXTURE_2D_ARRAY); }
  constexpr operator Texture3DType() const { return Texture3DType(GL_TEXTURE_2D_ARRAY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
struct Texture3DEnum {
  constexpr Texture3DEnum() { }
  constexpr operator TextureType() const { return TextureType(GL_TEXTURE_3D); }
  constexpr operator Texture3DType() const { return Texture3DType(GL_TEXTURE_3D); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
struct TextureBufferEnum {
  constexpr TextureBufferEnum() { }
  constexpr operator BufferType() const { return BufferType(GL_TEXTURE_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_COMPRESSION_HINT)
struct TextureCompressionHintEnum {
  constexpr TextureCompressionHintEnum() { }
  constexpr operator HintTarget() const { return HintTarget(GL_TEXTURE_COMPRESSION_HINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
struct TextureCubeMapEnum {
  constexpr TextureCubeMapEnum() { }
  constexpr operator TextureType() const { return TextureType(GL_TEXTURE_CUBE_MAP); }
  constexpr operator Texture2DType() const { return Texture2DType(GL_TEXTURE_CUBE_MAP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
struct TextureCubeMapNegativeXEnum {
  constexpr TextureCubeMapNegativeXEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_X); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
struct TextureCubeMapNegativeYEnum {
  constexpr TextureCubeMapNegativeYEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
struct TextureCubeMapNegativeZEnum {
  constexpr TextureCubeMapNegativeZEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
struct TextureCubeMapPositiveXEnum {
  constexpr TextureCubeMapPositiveXEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_X); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
struct TextureCubeMapPositiveYEnum {
  constexpr TextureCubeMapPositiveYEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_Y); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
struct TextureCubeMapPositiveZEnum {
  constexpr TextureCubeMapPositiveZEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_Z); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_SEAMLESS)
struct TextureCubeMapSeamlessEnum {
  constexpr TextureCubeMapSeamlessEnum() { }
  constexpr operator Capability() const { return Capability(GL_TEXTURE_CUBE_MAP_SEAMLESS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_FETCH_BARRIER_BIT)
struct TextureFetchBarrierBitEnum {
  constexpr TextureFetchBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TEXTURE_FETCH_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
struct TextureRectangleEnum {
  constexpr TextureRectangleEnum() { }
  constexpr operator TextureType() const { return TextureType(GL_TEXTURE_RECTANGLE); }
  constexpr operator Texture2DType() const { return Texture2DType(GL_TEXTURE_RECTANGLE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_UPDATE_BARRIER_BIT)
struct TextureUpdateBarrierBitEnum {
  constexpr TextureUpdateBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TEXTURE_UPDATE_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BARRIER_BIT)
struct TransformFeedbackBarrierBitEnum {
  constexpr TransformFeedbackBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TRANSFORM_FEEDBACK_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
struct TransformFeedbackBufferEnum {
  constexpr TransformFeedbackBufferEnum() { }
  constexpr operator IndexedBufferType() const { return IndexedBufferType(GL_TRANSFORM_FEEDBACK_BUFFER); }
  constexpr operator BufferType() const { return BufferType(GL_TRANSFORM_FEEDBACK_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
struct TrianglesEnum {
  constexpr TrianglesEnum() { }
  constexpr operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_TRIANGLES); }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
struct TrianglesAdjacencyEnum {
  constexpr TrianglesAdjacencyEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLES_ADJACENCY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
struct TriangleFanEnum {
  constexpr TriangleFanEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_FAN); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
struct TriangleStripEnum {
  constexpr TriangleStripEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_STRIP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
struct TriangleStripAdjacencyEnum {
  constexpr TriangleStripAdjacencyEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_STRIP_ADJACENCY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BARRIER_BIT)
struct UniformBarrierBitEnum {
  constexpr UniformBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_UNIFORM_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
struct UniformBufferEnum {
  constexpr UniformBufferEnum() { }
  constexpr operator IndexedBufferType() const { return IndexedBufferType(GL_UNIFORM_BUFFER); }
  constexpr operator BufferType() const { return BufferType(GL_UNIFORM_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ALIGNMENT)
struct UnpackAlignmentEnum {
  constexpr UnpackAlignmentEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_ALIGNMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_DEPTH)
struct UnpackCompressedBlockDepthEnum {
  constexpr UnpackCompressedBlockDepthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_DEPTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT)
struct UnpackCompressedBlockHeightEnum {
  constexpr UnpackCompressedBlockHeightEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_SIZE)
struct UnpackCompressedBlockSizeEnum {
  constexpr UnpackCompressedBlockSizeEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_SIZE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_WIDTH)
struct UnpackCompressedBlockWidthEnum {
  constexpr UnpackCompressedBlockWidthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_WIDTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_IMAGE_HEIGHT)
struct UnpackImageHeightEnum {
  constexpr UnpackImageHeightEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_IMAGE_HEIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_LSB_FIRST)
struct UnpackLsbFirstEnum {
  constexpr UnpackLsbFirstEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_LSB_FIRST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ROW_LENGTH)
struct UnpackRowLengthEnum {
  constexpr UnpackRowLengthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_ROW_LENGTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_IMAGES)
struct UnpackSkipImagesEnum {
  constexpr UnpackSkipImagesEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_IMAGES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_PIXELS)
struct UnpackSkipPixelsEnum {
  constexpr UnpackSkipPixelsEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_PIXELS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_ROWS)
struct UnpackSkipRowsEnum {
  constexpr UnpackSkipRowsEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_ROWS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SWAP_BYTES)
struct UnpackSwapBytesEnum {
  constexpr UnpackSwapBytesEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SWAP_BYTES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE)
struct UnsignedByteEnum {
  constexpr UnsignedByteEnum() { }
  constexpr operator DataType() const { return DataType(GL_UNSIGNED_BYTE); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_BYTE); }
  constexpr operator IndexType() const { return IndexType(GL_UNSIGNED_BYTE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_2_3_3_REV)
struct UnsignedByte233RevEnum {
  constexpr UnsignedByte233RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE_2_3_3_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_3_3_2)
struct UnsignedByte332Enum {
  constexpr UnsignedByte332Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE_3_3_2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT)
struct UnsignedIntEnum {
  constexpr UnsignedIntEnum() { }
  constexpr operator DataType() const { return DataType(GL_UNSIGNED_INT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_INT); }
  constexpr operator IndexType() const { return IndexType(GL_UNSIGNED_INT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10F_11F_11F_REV)
struct UnsignedInt10F11F11FRevEnum {
  constexpr UnsignedInt10F11F11FRevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_10F_11F_11F_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10_10_10_2)
struct UnsignedInt1010102Enum {
  constexpr UnsignedInt1010102Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_10_10_10_2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_24_8)
struct UnsignedInt248Enum {
  constexpr UnsignedInt248Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_24_8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_2_10_10_10_REV)
struct UnsignedInt2101010RevEnum {
  constexpr UnsignedInt2101010RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_2_10_10_10_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_5_9_9_9_REV)
struct UnsignedInt5999RevEnum {
  constexpr UnsignedInt5999RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_5_9_9_9_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8)
struct UnsignedInt8888Enum {
  constexpr UnsignedInt8888Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_8_8_8_8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8_REV)
struct UnsignedInt8888RevEnum {
  constexpr UnsignedInt8888RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_8_8_8_8_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT)
struct UnsignedShortEnum {
  constexpr UnsignedShortEnum() { }
  constexpr operator DataType() const { return DataType(GL_UNSIGNED_SHORT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_SHORT); }
  constexpr operator IndexType() const { return IndexType(GL_UNSIGNED_SHORT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_1_5_5_5_REV)
struct UnsignedShort1555RevEnum {
  constexpr UnsignedShort1555RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_1_5_5_5_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4)
struct UnsignedShort4444Enum {
  constexpr UnsignedShort4444Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_4_4_4_4); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4_REV)
struct UnsignedShort4444RevEnum {
  constexpr UnsignedShort4444RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_4_4_4_4_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_5_5_1)
struct UnsignedShort5551Enum {
  constexpr UnsignedShort5551Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_5_5_1); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5)
struct UnsignedShort565Enum {
  constexpr UnsignedShort565Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_6_5); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5_REV)
struct UnsignedShort565RevEnum {
  constexpr UnsignedShort565RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_6_5_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT)
struct VertexAttribArrayBarrierBitEnum {
  constexpr VertexAttribArrayBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
struct VertexShaderEnum {
  constexpr VertexShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_VERTEX_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
struct WriteOnlyEnum {
  constexpr WriteOnlyEnum() { }
  constexpr operator BufferMapAccess() const { return BufferMapAccess(GL_WRITE_ONLY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
struct XorEnum {
  constexpr XorEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_XOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
struct ZeroEnum {
  constexpr ZeroEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ZERO); }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_ZERO); }
  constexpr operator StencilOperation() const { return StencilOperation(GL_ZERO); }
};
#endif

} // namespace smart_enums

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALPHA)
  constexpr smart_enums::AlphaEnum kAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
  constexpr smart_enums::AlwaysEnum kAlways;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
  constexpr smart_enums::AndEnum kAnd;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
  constexpr smart_enums::AndInvertedEnum kAndInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
  constexpr smart_enums::AndReverseEnum kAndReverse;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
  constexpr smart_enums::ArrayBufferEnum kArrayBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BARRIER_BIT)
  constexpr smart_enums::AtomicCounterBarrierBitEnum kAtomicCounterBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
  constexpr smart_enums::AtomicCounterBufferEnum kAtomicCounterBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
  constexpr smart_enums::BackEnum kBack;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_LEFT)
  constexpr smart_enums::BackLeftEnum kBackLeft;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_RIGHT)
  constexpr smart_enums::BackRightEnum kBackRight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
  constexpr smart_enums::BgrEnum kBgr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
  constexpr smart_enums::BgraEnum kBgra;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
  constexpr smart_enums::BgraIntegerEnum kBgraInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
  constexpr smart_enums::BgrIntegerEnum kBgrInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLEND)
  constexpr smart_enums::BlendEnum kBlend;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
  constexpr smart_enums::BlueEnum kBlue;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
  constexpr smart_enums::BlueIntegerEnum kBlueInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BUFFER_UPDATE_BARRIER_BIT)
  constexpr smart_enums::BufferUpdateBarrierBitEnum kBufferUpdateBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BYTE)
  constexpr smart_enums::ByteEnum kByte;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
  constexpr smart_enums::CcwEnum kCcw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_BORDER)
  constexpr smart_enums::ClampToBorderEnum kClampToBorder;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_EDGE)
  constexpr smart_enums::ClampToEdgeEnum kClampToEdge;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
  constexpr smart_enums::ClearEnum kClear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT)
  constexpr smart_enums::ClientMappedBufferBarrierBitEnum kClientMappedBufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIP_DISTANCE)
  constexpr smart_enums::ClipDistanceEnum kClipDistance;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT0)
  constexpr smart_enums::ColorAttachment0Enum kColorAttachment0;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT1)
  constexpr smart_enums::ColorAttachment1Enum kColorAttachment1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT10)
  constexpr smart_enums::ColorAttachment10Enum kColorAttachment10;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT11)
  constexpr smart_enums::ColorAttachment11Enum kColorAttachment11;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT12)
  constexpr smart_enums::ColorAttachment12Enum kColorAttachment12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT13)
  constexpr smart_enums::ColorAttachment13Enum kColorAttachment13;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT14)
  constexpr smart_enums::ColorAttachment14Enum kColorAttachment14;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT15)
  constexpr smart_enums::ColorAttachment15Enum kColorAttachment15;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT2)
  constexpr smart_enums::ColorAttachment2Enum kColorAttachment2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT3)
  constexpr smart_enums::ColorAttachment3Enum kColorAttachment3;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT4)
  constexpr smart_enums::ColorAttachment4Enum kColorAttachment4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT5)
  constexpr smart_enums::ColorAttachment5Enum kColorAttachment5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT6)
  constexpr smart_enums::ColorAttachment6Enum kColorAttachment6;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT7)
  constexpr smart_enums::ColorAttachment7Enum kColorAttachment7;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT8)
  constexpr smart_enums::ColorAttachment8Enum kColorAttachment8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT9)
  constexpr smart_enums::ColorAttachment9Enum kColorAttachment9;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
  constexpr smart_enums::ColorBufferBitEnum kColorBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_LOGIC_OP)
  constexpr smart_enums::ColorLogicOpEnum kColorLogicOp;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMMAND_BARRIER_BIT)
  constexpr smart_enums::CommandBarrierBitEnum kCommandBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPARE_REF_TO_TEXTURE)
  constexpr smart_enums::CompareRefToTextureEnum kCompareRefToTexture;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED)
  constexpr smart_enums::CompressedRedEnum kCompressedRed;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED_RGTC1)
  constexpr smart_enums::CompressedRedRgtc1Enum kCompressedRedRgtc1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG)
  constexpr smart_enums::CompressedRgEnum kCompressedRg;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGB)
  constexpr smart_enums::CompressedRgbEnum kCompressedRgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGBA)
  constexpr smart_enums::CompressedRgbaEnum kCompressedRgba;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG_RGTC2)
  constexpr smart_enums::CompressedRgRgtc2Enum kCompressedRgRgtc2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RED_RGTC1)
  constexpr smart_enums::CompressedSignedRedRgtc1Enum kCompressedSignedRedRgtc1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RG_RGTC2)
  constexpr smart_enums::CompressedSignedRgRgtc2Enum kCompressedSignedRgRgtc2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB)
  constexpr smart_enums::CompressedSrgbEnum kCompressedSrgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB_ALPHA)
  constexpr smart_enums::CompressedSrgbAlphaEnum kCompressedSrgbAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
  constexpr smart_enums::ComputeShaderEnum kComputeShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_ALPHA)
  constexpr smart_enums::ConstantAlphaEnum kConstantAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_COLOR)
  constexpr smart_enums::ConstantColorEnum kConstantColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
  constexpr smart_enums::CopyEnum kCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
  constexpr smart_enums::CopyInvertedEnum kCopyInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
  constexpr smart_enums::CopyReadBufferEnum kCopyReadBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
  constexpr smart_enums::CopyWriteBufferEnum kCopyWriteBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CULL_FACE)
  constexpr smart_enums::CullFaceEnum kCullFace;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
  constexpr smart_enums::CwEnum kCw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT)
  constexpr smart_enums::DebugOutputEnum kDebugOutput;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT_SYNCHRONOUS)
  constexpr smart_enums::DebugOutputSynchronousEnum kDebugOutputSynchronous;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
  constexpr smart_enums::DecrEnum kDecr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
  constexpr smart_enums::DecrWrapEnum kDecrWrap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_ATTACHMENT)
  constexpr smart_enums::DepthAttachmentEnum kDepthAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
  constexpr smart_enums::DepthBufferBitEnum kDepthBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_CLAMP)
  constexpr smart_enums::DepthClampEnum kDepthClamp;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_COMPONENT)
  constexpr smart_enums::DepthComponentEnum kDepthComponent;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL)
  constexpr smart_enums::DepthStencilEnum kDepthStencil;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL_ATTACHMENT)
  constexpr smart_enums::DepthStencilAttachmentEnum kDepthStencilAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_TEST)
  constexpr smart_enums::DepthTestEnum kDepthTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER)
  constexpr smart_enums::DispatchIndirectBufferEnum kDispatchIndirectBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DITHER)
  constexpr smart_enums::DitherEnum kDither;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DONT_CARE)
  constexpr smart_enums::DontCareEnum kDontCare;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DOUBLE)
  constexpr smart_enums::DoubleEnum kDouble;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
  constexpr smart_enums::DrawFramebufferEnum kDrawFramebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER)
  constexpr smart_enums::DrawIndirectBufferEnum kDrawIndirectBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_ALPHA)
  constexpr smart_enums::DstAlphaEnum kDstAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_COLOR)
  constexpr smart_enums::DstColorEnum kDstColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_COPY)
  constexpr smart_enums::DynamicCopyEnum kDynamicCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_DRAW)
  constexpr smart_enums::DynamicDrawEnum kDynamicDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_READ)
  constexpr smart_enums::DynamicReadEnum kDynamicRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BARRIER_BIT)
  constexpr smart_enums::ElementArrayBarrierBitEnum kElementArrayBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
  constexpr smart_enums::ElementArrayBufferEnum kElementArrayBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
  constexpr smart_enums::EqualEnum kEqual;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
  constexpr smart_enums::EquivEnum kEquiv;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FASTEST)
  constexpr smart_enums::FastestEnum kFastest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
  constexpr smart_enums::FillEnum kFill;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
  constexpr smart_enums::FirstVertexConventionEnum kFirstVertexConvention;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIXED)
  constexpr smart_enums::FixedEnum kFixed;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT)
  constexpr smart_enums::FloatEnum kFloat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
  constexpr smart_enums::Float32UnsignedInt248RevEnum kFloat32UnsignedInt248Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
  constexpr smart_enums::FragmentShaderEnum kFragmentShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
  constexpr smart_enums::FragmentShaderDerivativeHintEnum kFragmentShaderDerivativeHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
  constexpr smart_enums::FramebufferEnum kFramebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BARRIER_BIT)
  constexpr smart_enums::FramebufferBarrierBitEnum kFramebufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_COMPLETE)
  constexpr smart_enums::FramebufferCompleteEnum kFramebufferComplete;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
  constexpr smart_enums::FramebufferIncompleteAttachmentEnum kFramebufferIncompleteAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER)
  constexpr smart_enums::FramebufferIncompleteDrawBufferEnum kFramebufferIncompleteDrawBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
  constexpr smart_enums::FramebufferIncompleteLayerTargetsEnum kFramebufferIncompleteLayerTargets;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
  constexpr smart_enums::FramebufferIncompleteMissingAttachmentEnum kFramebufferIncompleteMissingAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
  constexpr smart_enums::FramebufferIncompleteMultisampleEnum kFramebufferIncompleteMultisample;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER)
  constexpr smart_enums::FramebufferIncompleteReadBufferEnum kFramebufferIncompleteReadBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_SRGB)
  constexpr smart_enums::FramebufferSrgbEnum kFramebufferSrgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNDEFINED)
  constexpr smart_enums::FramebufferUndefinedEnum kFramebufferUndefined;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNSUPPORTED)
  constexpr smart_enums::FramebufferUnsupportedEnum kFramebufferUnsupported;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
  constexpr smart_enums::FrontEnum kFront;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
  constexpr smart_enums::FrontAndBackEnum kFrontAndBack;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_LEFT)
  constexpr smart_enums::FrontLeftEnum kFrontLeft;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_RIGHT)
  constexpr smart_enums::FrontRightEnum kFrontRight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_ADD)
  constexpr smart_enums::FuncAddEnum kFuncAdd;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_REVERSE_SUBTRACT)
  constexpr smart_enums::FuncReverseSubtractEnum kFuncReverseSubtract;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_SUBTRACT)
  constexpr smart_enums::FuncSubtractEnum kFuncSubtract;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
  constexpr smart_enums::GeometryShaderEnum kGeometryShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
  constexpr smart_enums::GequalEnum kGequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
  constexpr smart_enums::GreaterEnum kGreater;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
  constexpr smart_enums::GreenEnum kGreen;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
  constexpr smart_enums::GreenIntegerEnum kGreenInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_HALF_FLOAT)
  constexpr smart_enums::HalfFloatEnum kHalfFloat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
  constexpr smart_enums::IncrEnum kIncr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
  constexpr smart_enums::IncrWrapEnum kIncrWrap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INT)
  constexpr smart_enums::IntEnum kInt;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
  constexpr smart_enums::InvalidEnumEnum kInvalidEnum;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
  constexpr smart_enums::InvalidFramebufferOperationEnum kInvalidFramebufferOperation;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
  constexpr smart_enums::InvalidOperationEnum kInvalidOperation;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
  constexpr smart_enums::InvalidValueEnum kInvalidValue;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
  constexpr smart_enums::InvertEnum kInvert;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
  constexpr smart_enums::KeepEnum kKeep;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
  constexpr smart_enums::LastVertexConventionEnum kLastVertexConvention;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEFT)
  constexpr smart_enums::LeftEnum kLeft;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
  constexpr smart_enums::LequalEnum kLequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
  constexpr smart_enums::LessEnum kLess;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
  constexpr smart_enums::LineEnum kLine;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
  constexpr smart_enums::LinearEnum kLinear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_LINEAR)
  constexpr smart_enums::LinearMipmapLinearEnum kLinearMipmapLinear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_NEAREST)
  constexpr smart_enums::LinearMipmapNearestEnum kLinearMipmapNearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
  constexpr smart_enums::LinesEnum kLines;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
  constexpr smart_enums::LinesAdjacencyEnum kLinesAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
  constexpr smart_enums::LineLoopEnum kLineLoop;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH)
  constexpr smart_enums::LineSmoothEnum kLineSmooth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH_HINT)
  constexpr smart_enums::LineSmoothHintEnum kLineSmoothHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
  constexpr smart_enums::LineStripEnum kLineStrip;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
  constexpr smart_enums::LineStripAdjacencyEnum kLineStripAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
  constexpr smart_enums::MapCoherentBitEnum kMapCoherentBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
  constexpr smart_enums::MapFlushExplicitBitEnum kMapFlushExplicitBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
  constexpr smart_enums::MapInvalidateBufferBitEnum kMapInvalidateBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
  constexpr smart_enums::MapInvalidateRangeBitEnum kMapInvalidateRangeBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
  constexpr smart_enums::MapPersistentBitEnum kMapPersistentBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
  constexpr smart_enums::MapReadBitEnum kMapReadBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
  constexpr smart_enums::MapUnsynchronizedBitEnum kMapUnsynchronizedBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
  constexpr smart_enums::MapWriteBitEnum kMapWriteBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAX)
  constexpr smart_enums::MaxEnum kMax;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN)
  constexpr smart_enums::MinEnum kMin;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIRRORED_REPEAT)
  constexpr smart_enums::MirroredRepeatEnum kMirroredRepeat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MULTISAMPLE)
  constexpr smart_enums::MultisampleEnum kMultisample;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
  constexpr smart_enums::NandEnum kNand;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
  constexpr smart_enums::NearestEnum kNearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_LINEAR)
  constexpr smart_enums::NearestMipmapLinearEnum kNearestMipmapLinear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_NEAREST)
  constexpr smart_enums::NearestMipmapNearestEnum kNearestMipmapNearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
  constexpr smart_enums::NeverEnum kNever;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NICEST)
  constexpr smart_enums::NicestEnum kNicest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
  constexpr smart_enums::NoneEnum kNone;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
  constexpr smart_enums::NoopEnum kNoop;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
  constexpr smart_enums::NorEnum kNor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
  constexpr smart_enums::NotequalEnum kNotequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
  constexpr smart_enums::NoErrorEnum kNoError;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
  constexpr smart_enums::OneEnum kOne;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_ALPHA)
  constexpr smart_enums::OneMinusConstantAlphaEnum kOneMinusConstantAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_COLOR)
  constexpr smart_enums::OneMinusConstantColorEnum kOneMinusConstantColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_ALPHA)
  constexpr smart_enums::OneMinusDstAlphaEnum kOneMinusDstAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_COLOR)
  constexpr smart_enums::OneMinusDstColorEnum kOneMinusDstColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_ALPHA)
  constexpr smart_enums::OneMinusSrc1AlphaEnum kOneMinusSrc1Alpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_COLOR)
  constexpr smart_enums::OneMinusSrc1ColorEnum kOneMinusSrc1Color;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_ALPHA)
  constexpr smart_enums::OneMinusSrcAlphaEnum kOneMinusSrcAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_COLOR)
  constexpr smart_enums::OneMinusSrcColorEnum kOneMinusSrcColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
  constexpr smart_enums::OrEnum kOr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
  constexpr smart_enums::OrInvertedEnum kOrInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
  constexpr smart_enums::OrReverseEnum kOrReverse;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
  constexpr smart_enums::OutOfMemoryEnum kOutOfMemory;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ALIGNMENT)
  constexpr smart_enums::PackAlignmentEnum kPackAlignment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_DEPTH)
  constexpr smart_enums::PackCompressedBlockDepthEnum kPackCompressedBlockDepth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_HEIGHT)
  constexpr smart_enums::PackCompressedBlockHeightEnum kPackCompressedBlockHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_SIZE)
  constexpr smart_enums::PackCompressedBlockSizeEnum kPackCompressedBlockSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_WIDTH)
  constexpr smart_enums::PackCompressedBlockWidthEnum kPackCompressedBlockWidth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_IMAGE_HEIGHT)
  constexpr smart_enums::PackImageHeightEnum kPackImageHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_LSB_FIRST)
  constexpr smart_enums::PackLsbFirstEnum kPackLsbFirst;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ROW_LENGTH)
  constexpr smart_enums::PackRowLengthEnum kPackRowLength;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_IMAGES)
  constexpr smart_enums::PackSkipImagesEnum kPackSkipImages;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_PIXELS)
  constexpr smart_enums::PackSkipPixelsEnum kPackSkipPixels;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_ROWS)
  constexpr smart_enums::PackSkipRowsEnum kPackSkipRows;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SWAP_BYTES)
  constexpr smart_enums::PackSwapBytesEnum kPackSwapBytes;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
  constexpr smart_enums::PatchesEnum kPatches;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_BUFFER_BARRIER_BIT)
  constexpr smart_enums::PixelBufferBarrierBitEnum kPixelBufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER)
  constexpr smart_enums::PixelPackBufferEnum kPixelPackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER)
  constexpr smart_enums::PixelUnpackBufferEnum kPixelUnpackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
  constexpr smart_enums::PointEnum kPoint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
  constexpr smart_enums::PointsEnum kPoints;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_FILL)
  constexpr smart_enums::PolygonOffsetFillEnum kPolygonOffsetFill;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_LINE)
  constexpr smart_enums::PolygonOffsetLineEnum kPolygonOffsetLine;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_POINT)
  constexpr smart_enums::PolygonOffsetPointEnum kPolygonOffsetPoint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH)
  constexpr smart_enums::PolygonSmoothEnum kPolygonSmooth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH_HINT)
  constexpr smart_enums::PolygonSmoothHintEnum kPolygonSmoothHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART)
  constexpr smart_enums::PrimitiveRestartEnum kPrimitiveRestart;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART_FIXED_INDEX)
  constexpr smart_enums::PrimitiveRestartFixedIndexEnum kPrimitiveRestartFixedIndex;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PROGRAM_POINT_SIZE)
  constexpr smart_enums::ProgramPointSizeEnum kProgramPointSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R11F_G11F_B10F)
  constexpr smart_enums::R11FG11FB10FEnum kR11FG11FB10F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16)
  constexpr smart_enums::R16Enum kR16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16F)
  constexpr smart_enums::R16FEnum kR16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16I)
  constexpr smart_enums::R16IEnum kR16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16UI)
  constexpr smart_enums::R16UiEnum kR16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16_SNORM)
  constexpr smart_enums::R16SnormEnum kR16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32F)
  constexpr smart_enums::R32FEnum kR32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32I)
  constexpr smart_enums::R32IEnum kR32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32UI)
  constexpr smart_enums::R32UiEnum kR32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R3_G3_B2)
  constexpr smart_enums::R3G3B2Enum kR3G3B2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8)
  constexpr smart_enums::R8Enum kR8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8I)
  constexpr smart_enums::R8IEnum kR8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8UI)
  constexpr smart_enums::R8UiEnum kR8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8_SNORM)
  constexpr smart_enums::R8SnormEnum kR8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RASTERIZER_DISCARD)
  constexpr smart_enums::RasterizerDiscardEnum kRasterizerDiscard;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
  constexpr smart_enums::ReadFramebufferEnum kReadFramebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
  constexpr smart_enums::ReadOnlyEnum kReadOnly;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
  constexpr smart_enums::ReadWriteEnum kReadWrite;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
  constexpr smart_enums::RedEnum kRed;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
  constexpr smart_enums::RedIntegerEnum kRedInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPEAT)
  constexpr smart_enums::RepeatEnum kRepeat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
  constexpr smart_enums::ReplaceEnum kReplace;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG)
  constexpr smart_enums::RgEnum kRg;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16)
  constexpr smart_enums::Rg16Enum kRg16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16F)
  constexpr smart_enums::Rg16FEnum kRg16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16I)
  constexpr smart_enums::Rg16IEnum kRg16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16UI)
  constexpr smart_enums::Rg16UiEnum kRg16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16_SNORM)
  constexpr smart_enums::Rg16SnormEnum kRg16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32F)
  constexpr smart_enums::Rg32FEnum kRg32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32I)
  constexpr smart_enums::Rg32IEnum kRg32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32UI)
  constexpr smart_enums::Rg32UiEnum kRg32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8)
  constexpr smart_enums::Rg8Enum kRg8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8I)
  constexpr smart_enums::Rg8IEnum kRg8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8UI)
  constexpr smart_enums::Rg8UiEnum kRg8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8_SNORM)
  constexpr smart_enums::Rg8SnormEnum kRg8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
  constexpr smart_enums::RgbEnum kRgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10)
  constexpr smart_enums::Rgb10Enum kRgb10;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2)
  constexpr smart_enums::Rgb10A2Enum kRgb10A2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2UI)
  constexpr smart_enums::Rgb10A2UiEnum kRgb10A2Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB12)
  constexpr smart_enums::Rgb12Enum kRgb12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16)
  constexpr smart_enums::Rgb16Enum kRgb16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16F)
  constexpr smart_enums::Rgb16FEnum kRgb16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16I)
  constexpr smart_enums::Rgb16IEnum kRgb16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16UI)
  constexpr smart_enums::Rgb16UiEnum kRgb16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16_SNORM)
  constexpr smart_enums::Rgb16SnormEnum kRgb16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32F)
  constexpr smart_enums::Rgb32FEnum kRgb32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32I)
  constexpr smart_enums::Rgb32IEnum kRgb32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32UI)
  constexpr smart_enums::Rgb32UiEnum kRgb32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB4)
  constexpr smart_enums::Rgb4Enum kRgb4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5)
  constexpr smart_enums::Rgb5Enum kRgb5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5_A1)
  constexpr smart_enums::Rgb5A1Enum kRgb5A1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8)
  constexpr smart_enums::Rgb8Enum kRgb8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8I)
  constexpr smart_enums::Rgb8IEnum kRgb8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8UI)
  constexpr smart_enums::Rgb8UiEnum kRgb8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8_SNORM)
  constexpr smart_enums::Rgb8SnormEnum kRgb8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB9_E5)
  constexpr smart_enums::Rgb9E5Enum kRgb9E5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
  constexpr smart_enums::RgbaEnum kRgba;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA12)
  constexpr smart_enums::Rgba12Enum kRgba12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16)
  constexpr smart_enums::Rgba16Enum kRgba16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16F)
  constexpr smart_enums::Rgba16FEnum kRgba16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16I)
  constexpr smart_enums::Rgba16IEnum kRgba16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16UI)
  constexpr smart_enums::Rgba16UiEnum kRgba16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16_SNORM)
  constexpr smart_enums::Rgba16SnormEnum kRgba16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA2)
  constexpr smart_enums::Rgba2Enum kRgba2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32F)
  constexpr smart_enums::Rgba32FEnum kRgba32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32I)
  constexpr smart_enums::Rgba32IEnum kRgba32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32UI)
  constexpr smart_enums::Rgba32UiEnum kRgba32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA4)
  constexpr smart_enums::Rgba4Enum kRgba4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8)
  constexpr smart_enums::Rgba8Enum kRgba8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8I)
  constexpr smart_enums::Rgba8IEnum kRgba8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8UI)
  constexpr smart_enums::Rgba8UiEnum kRgba8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8_SNORM)
  constexpr smart_enums::Rgba8SnormEnum kRgba8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
  constexpr smart_enums::RgbaIntegerEnum kRgbaInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
  constexpr smart_enums::RgbIntegerEnum kRgbInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
  constexpr smart_enums::RgIntegerEnum kRgInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RIGHT)
  constexpr smart_enums::RightEnum kRight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_COVERAGE)
  constexpr smart_enums::SampleAlphaToCoverageEnum kSampleAlphaToCoverage;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_ONE)
  constexpr smart_enums::SampleAlphaToOneEnum kSampleAlphaToOne;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_COVERAGE)
  constexpr smart_enums::SampleCoverageEnum kSampleCoverage;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_MASK)
  constexpr smart_enums::SampleMaskEnum kSampleMask;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_SHADING)
  constexpr smart_enums::SampleShadingEnum kSampleShading;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_TEST)
  constexpr smart_enums::ScissorTestEnum kScissorTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
  constexpr smart_enums::SetEnum kSet;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT)
  constexpr smart_enums::ShaderImageAccessBarrierBitEnum kShaderImageAccessBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BARRIER_BIT)
  constexpr smart_enums::ShaderStorageBarrierBitEnum kShaderStorageBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
  constexpr smart_enums::ShaderStorageBufferEnum kShaderStorageBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHORT)
  constexpr smart_enums::ShortEnum kShort;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_ALPHA)
  constexpr smart_enums::Src1AlphaEnum kSrc1Alpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_COLOR)
  constexpr smart_enums::Src1ColorEnum kSrc1Color;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA)
  constexpr smart_enums::SrcAlphaEnum kSrcAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA_SATURATE)
  constexpr smart_enums::SrcAlphaSaturateEnum kSrcAlphaSaturate;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_COLOR)
  constexpr smart_enums::SrcColorEnum kSrcColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB)
  constexpr smart_enums::SrgbEnum kSrgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8)
  constexpr smart_enums::Srgb8Enum kSrgb8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8_ALPHA8)
  constexpr smart_enums::Srgb8Alpha8Enum kSrgb8Alpha8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB_ALPHA)
  constexpr smart_enums::SrgbAlphaEnum kSrgbAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
  constexpr smart_enums::StackOverflowEnum kStackOverflow;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
  constexpr smart_enums::StackUnderflowEnum kStackUnderflow;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_COPY)
  constexpr smart_enums::StaticCopyEnum kStaticCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_DRAW)
  constexpr smart_enums::StaticDrawEnum kStaticDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_READ)
  constexpr smart_enums::StaticReadEnum kStaticRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_ATTACHMENT)
  constexpr smart_enums::StencilAttachmentEnum kStencilAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
  constexpr smart_enums::StencilBufferBitEnum kStencilBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_INDEX)
  constexpr smart_enums::StencilIndexEnum kStencilIndex;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_TEST)
  constexpr smart_enums::StencilTestEnum kStencilTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_COPY)
  constexpr smart_enums::StreamCopyEnum kStreamCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_DRAW)
  constexpr smart_enums::StreamDrawEnum kStreamDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_READ)
  constexpr smart_enums::StreamReadEnum kStreamRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
  constexpr smart_enums::TableTooLargeEnum kTableTooLarge;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
  constexpr smart_enums::TessControlShaderEnum kTessControlShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
  constexpr smart_enums::TessEvaluationShaderEnum kTessEvaluationShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D)
  constexpr smart_enums::Texture1DEnum kTexture1D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
  constexpr smart_enums::Texture1DArrayEnum kTexture1DArray;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
  constexpr smart_enums::Texture2DEnum kTexture2D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
  constexpr smart_enums::Texture2DArrayEnum kTexture2DArray;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
  constexpr smart_enums::Texture3DEnum kTexture3D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
  constexpr smart_enums::TextureBufferEnum kTextureBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_COMPRESSION_HINT)
  constexpr smart_enums::TextureCompressionHintEnum kTextureCompressionHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
  constexpr smart_enums::TextureCubeMapEnum kTextureCubeMap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
  constexpr smart_enums::TextureCubeMapNegativeXEnum kTextureCubeMapNegativeX;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
  constexpr smart_enums::TextureCubeMapNegativeYEnum kTextureCubeMapNegativeY;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
  constexpr smart_enums::TextureCubeMapNegativeZEnum kTextureCubeMapNegativeZ;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
  constexpr smart_enums::TextureCubeMapPositiveXEnum kTextureCubeMapPositiveX;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
  constexpr smart_enums::TextureCubeMapPositiveYEnum kTextureCubeMapPositiveY;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
  constexpr smart_enums::TextureCubeMapPositiveZEnum kTextureCubeMapPositiveZ;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_SEAMLESS)
  constexpr smart_enums::TextureCubeMapSeamlessEnum kTextureCubeMapSeamless;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_FETCH_BARRIER_BIT)
  constexpr smart_enums::TextureFetchBarrierBitEnum kTextureFetchBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
  constexpr smart_enums::TextureRectangleEnum kTextureRectangle;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_UPDATE_BARRIER_BIT)
  constexpr smart_enums::TextureUpdateBarrierBitEnum kTextureUpdateBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BARRIER_BIT)
  constexpr smart_enums::TransformFeedbackBarrierBitEnum kTransformFeedbackBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
  constexpr smart_enums::TransformFeedbackBufferEnum kTransformFeedbackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
  constexpr smart_enums::TrianglesEnum kTriangles;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
  constexpr smart_enums::TrianglesAdjacencyEnum kTrianglesAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
  constexpr smart_enums::TriangleFanEnum kTriangleFan;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
  constexpr smart_enums::TriangleStripEnum kTriangleStrip;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
  constexpr smart_enums::TriangleStripAdjacencyEnum kTriangleStripAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BARRIER_BIT)
  constexpr smart_enums::UniformBarrierBitEnum kUniformBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
  constexpr smart_enums::UniformBufferEnum kUniformBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ALIGNMENT)
  constexpr smart_enums::UnpackAlignmentEnum kUnpackAlignment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_DEPTH)
  constexpr smart_enums::UnpackCompressedBlockDepthEnum kUnpackCompressedBlockDepth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT)
  constexpr smart_enums::UnpackCompressedBlockHeightEnum kUnpackCompressedBlockHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_SIZE)
  constexpr smart_enums::UnpackCompressedBlockSizeEnum kUnpackCompressedBlockSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_WIDTH)
  constexpr smart_enums::UnpackCompressedBlockWidthEnum kUnpackCompressedBlockWidth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_IMAGE_HEIGHT)
  constexpr smart_enums::UnpackImageHeightEnum kUnpackImageHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_LSB_FIRST)
  constexpr smart_enums::UnpackLsbFirstEnum kUnpackLsbFirst;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ROW_LENGTH)
  constexpr smart_enums::UnpackRowLengthEnum kUnpackRowLength;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_IMAGES)
  constexpr smart_enums::UnpackSkipImagesEnum kUnpackSkipImages;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_PIXELS)
  constexpr smart_enums::UnpackSkipPixelsEnum kUnpackSkipPixels;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_ROWS)
  constexpr smart_enums::UnpackSkipRowsEnum kUnpackSkipRows;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SWAP_BYTES)
  constexpr smart_enums::UnpackSwapBytesEnum kUnpackSwapBytes;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE)
  constexpr smart_enums::UnsignedByteEnum kUnsignedByte;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_2_3_3_REV)
  constexpr smart_enums::UnsignedByte233RevEnum kUnsignedByte233Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_3_3_2)
  constexpr smart_enums::UnsignedByte332Enum kUnsignedByte332;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT)
  constexpr smart_enums::UnsignedIntEnum kUnsignedInt;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10F_11F_11F_REV)
  constexpr smart_enums::UnsignedInt10F11F11FRevEnum kUnsignedInt10F11F11FRev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10_10_10_2)
  constexpr smart_enums::UnsignedInt1010102Enum kUnsignedInt1010102;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_24_8)
  constexpr smart_enums::UnsignedInt248Enum kUnsignedInt248;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_2_10_10_10_REV)
  constexpr smart_enums::UnsignedInt2101010RevEnum kUnsignedInt2101010Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_5_9_9_9_REV)
  constexpr smart_enums::UnsignedInt5999RevEnum kUnsignedInt5999Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8)
  constexpr smart_enums::UnsignedInt8888Enum kUnsignedInt8888;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8_REV)
  constexpr smart_enums::UnsignedInt8888RevEnum kUnsignedInt8888Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT)
  constexpr smart_enums::UnsignedShortEnum kUnsignedShort;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_1_5_5_5_REV)
  constexpr smart_enums::UnsignedShort1555RevEnum kUnsignedShort1555Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4)
  constexpr smart_enums::UnsignedShort4444Enum kUnsignedShort4444;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4_REV)
  constexpr smart_enums::UnsignedShort4444RevEnum kUnsignedShort4444Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_5_5_1)
  constexpr smart_enums::UnsignedShort5551Enum kUnsignedShort5551;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5)
  constexpr smart_enums::UnsignedShort565Enum kUnsignedShort565;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5_REV)
  constexpr smart_enums::UnsignedShort565RevEnum kUnsignedShort565Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT)
  constexpr smart_enums::VertexAttribArrayBarrierBitEnum kVertexAttribArrayBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
  constexpr smart_enums::VertexShaderEnum kVertexShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
  constexpr smart_enums::WriteOnlyEnum kWriteOnly;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
  constexpr smart_enums::XorEnum kXor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  constexpr smart_enums::ZeroEnum kZero;
#endif

} // namespace enums
} // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif
