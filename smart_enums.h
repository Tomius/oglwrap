// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_SMART_ENUMS_H_
#define OGLWRAP_SMART_ENUMS_H_

#include "./config.h"
#include "./enums/stencil_operation.h"
#include "./enums/blend_function.h"
#include "./enums/poly_mode.h"
#include "./enums/blend_equation.h"
#include "./enums/buffer_binding.h"
#include "./enums/basic_primitive_type.h"
#include "./enums/texture_cube_target.h"
#include "./enums/vertex_array_binding.h"
#include "./enums/buffer_usage.h"
#include "./enums/texture2D_type.h"
#include "./enums/buffer_select_bit.h"
#include "./enums/color_logic_operation.h"
#include "./enums/compare_func.h"
#include "./enums/blit_filter.h"
#include "./enums/pixel_data_internal_format.h"
#include "./enums/texture3D_type.h"
#include "./enums/buffer_map_access_flags.h"
#include "./enums/renderbuffer_binding.h"
#include "./enums/index_type.h"
#include "./enums/framebuffer_binding.h"
#include "./enums/error_type.h"
#include "./enums/renderbuffer_type.h"
#include "./enums/transform_feedback_type.h"
#include "./enums/shader_type.h"
#include "./enums/face.h"
#include "./enums/wrap_mode.h"
#include "./enums/pixel_data_type.h"
#include "./enums/framebuffer_type.h"
#include "./enums/hint_option.h"
#include "./enums/framebuffer_attachment.h"
#include "./enums/swizzle_mode.h"
#include "./enums/texture_type.h"
#include "./enums/whole_data_type.h"
#include "./enums/pixel_storage_mode.h"
#include "./enums/framebuffer_status.h"
#include "./enums/color_buffer.h"
#include "./enums/transform_feedback_binding.h"
#include "./enums/face_orientation.h"
#include "./enums/provoke_mode.h"
#include "./enums/buffer_map_access.h"
#include "./enums/data_type.h"
#include "./enums/mag_filter.h"
#include "./enums/indexed_buffer_type.h"
#include "./enums/hint_target.h"
#include "./enums/indexed_buffer_binding.h"
#include "./enums/vertex_array_type.h"
#include "./enums/compare_mode.h"
#include "./enums/capability.h"
#include "./enums/min_filter.h"
#include "./enums/texture_binding.h"
#include "./enums/pixel_data_format.h"
#include "./enums/buffer_type.h"
#include "./enums/memory_barrier_bit.h"
#include "./enums/primitive_type.h"
#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {
namespace smart_enums {

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALPHA)
struct AlphaEnum {
  operator SwizzleMode() const { return SwizzleMode(GL_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
struct AlwaysEnum {
  operator CompareFunc() const { return CompareFunc(GL_ALWAYS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
struct AndEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
struct AndInvertedEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND_INVERTED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
struct AndReverseEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND_REVERSE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
struct ArrayBufferEnum {
  operator BufferType() const { return BufferType(GL_ARRAY_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BARRIER_BIT)
struct AtomicCounterBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_ATOMIC_COUNTER_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
struct AtomicCounterBufferEnum {
  operator IndexedBufferType() const { return IndexedBufferType(GL_ATOMIC_COUNTER_BUFFER); }
  operator BufferType() const { return BufferType(GL_ATOMIC_COUNTER_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
struct BackEnum {
  operator Face() const { return Face(GL_BACK); }
  operator ColorBuffer() const { return ColorBuffer(GL_BACK); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_LEFT)
struct BackLeftEnum {
  operator ColorBuffer() const { return ColorBuffer(GL_BACK_LEFT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_RIGHT)
struct BackRightEnum {
  operator ColorBuffer() const { return ColorBuffer(GL_BACK_RIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
struct BgrEnum {
  operator PixelDataFormat() const { return PixelDataFormat(GL_BGR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
struct BgraEnum {
  operator PixelDataFormat() const { return PixelDataFormat(GL_BGRA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
struct BgraIntegerEnum {
  operator PixelDataFormat() const { return PixelDataFormat(GL_BGRA_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
struct BgrIntegerEnum {
  operator PixelDataFormat() const { return PixelDataFormat(GL_BGR_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLEND)
struct BlendEnum {
  operator Capability() const { return Capability(GL_BLEND); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
struct BlueEnum {
  operator SwizzleMode() const { return SwizzleMode(GL_BLUE); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_BLUE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
struct BlueIntegerEnum {
  operator PixelDataFormat() const { return PixelDataFormat(GL_BLUE_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BUFFER_UPDATE_BARRIER_BIT)
struct BufferUpdateBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_BUFFER_UPDATE_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BYTE)
struct ByteEnum {
  operator PixelDataType() const { return PixelDataType(GL_BYTE); }
  operator WholeDataType() const { return WholeDataType(GL_BYTE); }
  operator DataType() const { return DataType(GL_BYTE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
struct CcwEnum {
  operator FaceOrientation() const { return FaceOrientation(GL_CCW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_BORDER)
struct ClampToBorderEnum {
  operator WrapMode() const { return WrapMode(GL_CLAMP_TO_BORDER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_EDGE)
struct ClampToEdgeEnum {
  operator WrapMode() const { return WrapMode(GL_CLAMP_TO_EDGE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
struct ClearEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_CLEAR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT)
struct ClientMappedBufferBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIP_DISTANCE)
struct ClipDistanceEnum {
  operator Capability() const { return Capability(GL_CLIP_DISTANCE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT0)
struct ColorAttachment0Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT0); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT0); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT1)
struct ColorAttachment1Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT1); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT1); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT10)
struct ColorAttachment10Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT10); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT10); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT11)
struct ColorAttachment11Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT11); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT11); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT12)
struct ColorAttachment12Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT12); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT12); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT13)
struct ColorAttachment13Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT13); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT13); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT14)
struct ColorAttachment14Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT14); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT14); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT15)
struct ColorAttachment15Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT15); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT15); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT2)
struct ColorAttachment2Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT2); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT3)
struct ColorAttachment3Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT3); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT3); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT4)
struct ColorAttachment4Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT4); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT4); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT5)
struct ColorAttachment5Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT5); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT5); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT6)
struct ColorAttachment6Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT6); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT6); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT7)
struct ColorAttachment7Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT7); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT7); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT8)
struct ColorAttachment8Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT8); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT9)
struct ColorAttachment9Enum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT9); }
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT9); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
struct ColorBufferBitEnum {
  operator BufferSelectBit() const { return BufferSelectBit(GL_COLOR_BUFFER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_LOGIC_OP)
struct ColorLogicOpEnum {
  operator Capability() const { return Capability(GL_COLOR_LOGIC_OP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMMAND_BARRIER_BIT)
struct CommandBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_COMMAND_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPARE_REF_TO_TEXTURE)
struct CompareRefToTextureEnum {
  operator CompareMode() const { return CompareMode(GL_COMPARE_REF_TO_TEXTURE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED)
struct CompressedRedEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED_RGTC1)
struct CompressedRedRgtc1Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RED_RGTC1); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG)
struct CompressedRgEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RG); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGB)
struct CompressedRgbEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RGB); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGBA)
struct CompressedRgbaEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RGBA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG_RGTC2)
struct CompressedRgRgtc2Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RG_RGTC2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RED_RGTC1)
struct CompressedSignedRedRgtc1Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SIGNED_RED_RGTC1); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RG_RGTC2)
struct CompressedSignedRgRgtc2Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SIGNED_RG_RGTC2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB)
struct CompressedSrgbEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SRGB); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB_ALPHA)
struct CompressedSrgbAlphaEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SRGB_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
struct ComputeShaderEnum {
  operator ShaderType() const { return ShaderType(GL_COMPUTE_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_ALPHA)
struct ConstantAlphaEnum {
  operator BlendFunction() const { return BlendFunction(GL_CONSTANT_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_COLOR)
struct ConstantColorEnum {
  operator BlendFunction() const { return BlendFunction(GL_CONSTANT_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
struct CopyEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_COPY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
struct CopyInvertedEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_COPY_INVERTED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
struct CopyReadBufferEnum {
  operator BufferType() const { return BufferType(GL_COPY_READ_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
struct CopyWriteBufferEnum {
  operator BufferType() const { return BufferType(GL_COPY_WRITE_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CULL_FACE)
struct CullFaceEnum {
  operator Capability() const { return Capability(GL_CULL_FACE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
struct CwEnum {
  operator FaceOrientation() const { return FaceOrientation(GL_CW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT)
struct DebugOutputEnum {
  operator Capability() const { return Capability(GL_DEBUG_OUTPUT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT_SYNCHRONOUS)
struct DebugOutputSynchronousEnum {
  operator Capability() const { return Capability(GL_DEBUG_OUTPUT_SYNCHRONOUS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
struct DecrEnum {
  operator StencilOperation() const { return StencilOperation(GL_DECR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
struct DecrWrapEnum {
  operator StencilOperation() const { return StencilOperation(GL_DECR_WRAP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_ATTACHMENT)
struct DepthAttachmentEnum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_DEPTH_ATTACHMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
struct DepthBufferBitEnum {
  operator BufferSelectBit() const { return BufferSelectBit(GL_DEPTH_BUFFER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_CLAMP)
struct DepthClampEnum {
  operator Capability() const { return Capability(GL_DEPTH_CLAMP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_COMPONENT)
struct DepthComponentEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_DEPTH_COMPONENT); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_DEPTH_COMPONENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL)
struct DepthStencilEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_DEPTH_STENCIL); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_DEPTH_STENCIL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL_ATTACHMENT)
struct DepthStencilAttachmentEnum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_DEPTH_STENCIL_ATTACHMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_TEST)
struct DepthTestEnum {
  operator Capability() const { return Capability(GL_DEPTH_TEST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER)
struct DispatchIndirectBufferEnum {
  operator BufferType() const { return BufferType(GL_DISPATCH_INDIRECT_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DITHER)
struct DitherEnum {
  operator Capability() const { return Capability(GL_DITHER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DONT_CARE)
struct DontCareEnum {
  operator HintOption() const { return HintOption(GL_DONT_CARE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DOUBLE)
struct DoubleEnum {
  operator DataType() const { return DataType(GL_DOUBLE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
struct DrawFramebufferEnum {
  operator FramebufferType() const { return FramebufferType(GL_DRAW_FRAMEBUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER)
struct DrawIndirectBufferEnum {
  operator BufferType() const { return BufferType(GL_DRAW_INDIRECT_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_ALPHA)
struct DstAlphaEnum {
  operator BlendFunction() const { return BlendFunction(GL_DST_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_COLOR)
struct DstColorEnum {
  operator BlendFunction() const { return BlendFunction(GL_DST_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_COPY)
struct DynamicCopyEnum {
  operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_COPY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_DRAW)
struct DynamicDrawEnum {
  operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_DRAW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_READ)
struct DynamicReadEnum {
  operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_READ); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BARRIER_BIT)
struct ElementArrayBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_ELEMENT_ARRAY_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
struct ElementArrayBufferEnum {
  operator BufferType() const { return BufferType(GL_ELEMENT_ARRAY_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
struct EqualEnum {
  operator CompareFunc() const { return CompareFunc(GL_EQUAL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
struct EquivEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_EQUIV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FASTEST)
struct FastestEnum {
  operator HintOption() const { return HintOption(GL_FASTEST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
struct FillEnum {
  operator PolyMode() const { return PolyMode(GL_FILL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
struct FirstVertexConventionEnum {
  operator ProvokeMode() const { return ProvokeMode(GL_FIRST_VERTEX_CONVENTION); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIXED)
struct FixedEnum {
  operator DataType() const { return DataType(GL_FIXED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT)
struct FloatEnum {
  operator PixelDataType() const { return PixelDataType(GL_FLOAT); }
  operator DataType() const { return DataType(GL_FLOAT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
struct Float32UnsignedInt248RevEnum {
  operator PixelDataType() const { return PixelDataType(GL_FLOAT_32_UNSIGNED_INT_24_8_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
struct FragmentShaderEnum {
  operator ShaderType() const { return ShaderType(GL_FRAGMENT_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
struct FragmentShaderDerivativeHintEnum {
  operator HintTarget() const { return HintTarget(GL_FRAGMENT_SHADER_DERIVATIVE_HINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
struct FramebufferEnum {
  operator FramebufferType() const { return FramebufferType(GL_FRAMEBUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BARRIER_BIT)
struct FramebufferBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_FRAMEBUFFER_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_COMPLETE)
struct FramebufferCompleteEnum {
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_COMPLETE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
struct FramebufferIncompleteAttachmentEnum {
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER)
struct FramebufferIncompleteDrawBufferEnum {
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
struct FramebufferIncompleteLayerTargetsEnum {
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
struct FramebufferIncompleteMissingAttachmentEnum {
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
struct FramebufferIncompleteMultisampleEnum {
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER)
struct FramebufferIncompleteReadBufferEnum {
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_SRGB)
struct FramebufferSrgbEnum {
  operator Capability() const { return Capability(GL_FRAMEBUFFER_SRGB); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNDEFINED)
struct FramebufferUndefinedEnum {
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_UNDEFINED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNSUPPORTED)
struct FramebufferUnsupportedEnum {
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_UNSUPPORTED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
struct FrontEnum {
  operator Face() const { return Face(GL_FRONT); }
  operator ColorBuffer() const { return ColorBuffer(GL_FRONT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
struct FrontAndBackEnum {
  operator Face() const { return Face(GL_FRONT_AND_BACK); }
  operator ColorBuffer() const { return ColorBuffer(GL_FRONT_AND_BACK); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_LEFT)
struct FrontLeftEnum {
  operator ColorBuffer() const { return ColorBuffer(GL_FRONT_LEFT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_RIGHT)
struct FrontRightEnum {
  operator ColorBuffer() const { return ColorBuffer(GL_FRONT_RIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_ADD)
struct FuncAddEnum {
  operator BlendEquation() const { return BlendEquation(GL_FUNC_ADD); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_REVERSE_SUBTRACT)
struct FuncReverseSubtractEnum {
  operator BlendEquation() const { return BlendEquation(GL_FUNC_REVERSE_SUBTRACT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_SUBTRACT)
struct FuncSubtractEnum {
  operator BlendEquation() const { return BlendEquation(GL_FUNC_SUBTRACT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
struct GeometryShaderEnum {
  operator ShaderType() const { return ShaderType(GL_GEOMETRY_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
struct GequalEnum {
  operator CompareFunc() const { return CompareFunc(GL_GEQUAL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
struct GreaterEnum {
  operator CompareFunc() const { return CompareFunc(GL_GREATER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
struct GreenEnum {
  operator SwizzleMode() const { return SwizzleMode(GL_GREEN); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_GREEN); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
struct GreenIntegerEnum {
  operator PixelDataFormat() const { return PixelDataFormat(GL_GREEN_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_HALF_FLOAT)
struct HalfFloatEnum {
  operator PixelDataType() const { return PixelDataType(GL_HALF_FLOAT); }
  operator DataType() const { return DataType(GL_HALF_FLOAT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
struct IncrEnum {
  operator StencilOperation() const { return StencilOperation(GL_INCR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
struct IncrWrapEnum {
  operator StencilOperation() const { return StencilOperation(GL_INCR_WRAP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INT)
struct IntEnum {
  operator PixelDataType() const { return PixelDataType(GL_INT); }
  operator WholeDataType() const { return WholeDataType(GL_INT); }
  operator DataType() const { return DataType(GL_INT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
struct InvalidEnumEnum {
  operator ErrorType() const { return ErrorType(GL_INVALID_ENUM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
struct InvalidFramebufferOperationEnum {
  operator ErrorType() const { return ErrorType(GL_INVALID_FRAMEBUFFER_OPERATION); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
struct InvalidOperationEnum {
  operator ErrorType() const { return ErrorType(GL_INVALID_OPERATION); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
struct InvalidValueEnum {
  operator ErrorType() const { return ErrorType(GL_INVALID_VALUE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
struct InvertEnum {
  operator StencilOperation() const { return StencilOperation(GL_INVERT); }
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_INVERT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
struct KeepEnum {
  operator StencilOperation() const { return StencilOperation(GL_KEEP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
struct LastVertexConventionEnum {
  operator ProvokeMode() const { return ProvokeMode(GL_LAST_VERTEX_CONVENTION); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEFT)
struct LeftEnum {
  operator ColorBuffer() const { return ColorBuffer(GL_LEFT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
struct LequalEnum {
  operator CompareFunc() const { return CompareFunc(GL_LEQUAL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
struct LessEnum {
  operator CompareFunc() const { return CompareFunc(GL_LESS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
struct LineEnum {
  operator PolyMode() const { return PolyMode(GL_LINE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
struct LinearEnum {
  operator BlitFilter() const { return BlitFilter(GL_LINEAR); }
  operator MagFilter() const { return MagFilter(GL_LINEAR); }
  operator MinFilter() const { return MinFilter(GL_LINEAR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_LINEAR)
struct LinearMipmapLinearEnum {
  operator MinFilter() const { return MinFilter(GL_LINEAR_MIPMAP_LINEAR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_NEAREST)
struct LinearMipmapNearestEnum {
  operator MinFilter() const { return MinFilter(GL_LINEAR_MIPMAP_NEAREST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
struct LinesEnum {
  operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_LINES); }
  operator PrimitiveType() const { return PrimitiveType(GL_LINES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
struct LinesAdjacencyEnum {
  operator PrimitiveType() const { return PrimitiveType(GL_LINES_ADJACENCY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
struct LineLoopEnum {
  operator PrimitiveType() const { return PrimitiveType(GL_LINE_LOOP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH)
struct LineSmoothEnum {
  operator Capability() const { return Capability(GL_LINE_SMOOTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH_HINT)
struct LineSmoothHintEnum {
  operator HintTarget() const { return HintTarget(GL_LINE_SMOOTH_HINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
struct LineStripEnum {
  operator PrimitiveType() const { return PrimitiveType(GL_LINE_STRIP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
struct LineStripAdjacencyEnum {
  operator PrimitiveType() const { return PrimitiveType(GL_LINE_STRIP_ADJACENCY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
struct MapCoherentBitEnum {
  operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_COHERENT_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
struct MapFlushExplicitBitEnum {
  operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_FLUSH_EXPLICIT_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
struct MapInvalidateBufferBitEnum {
  operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_INVALIDATE_BUFFER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
struct MapInvalidateRangeBitEnum {
  operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_INVALIDATE_RANGE_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
struct MapPersistentBitEnum {
  operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_PERSISTENT_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
struct MapReadBitEnum {
  operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_READ_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
struct MapUnsynchronizedBitEnum {
  operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_UNSYNCHRONIZED_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
struct MapWriteBitEnum {
  operator BufferMapAccessFlags() const { return BufferMapAccessFlags(GL_MAP_WRITE_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAX)
struct MaxEnum {
  operator BlendEquation() const { return BlendEquation(GL_MAX); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN)
struct MinEnum {
  operator BlendEquation() const { return BlendEquation(GL_MIN); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIRRORED_REPEAT)
struct MirroredRepeatEnum {
  operator WrapMode() const { return WrapMode(GL_MIRRORED_REPEAT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MULTISAMPLE)
struct MultisampleEnum {
  operator Capability() const { return Capability(GL_MULTISAMPLE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
struct NandEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_NAND); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
struct NearestEnum {
  operator BlitFilter() const { return BlitFilter(GL_NEAREST); }
  operator MagFilter() const { return MagFilter(GL_NEAREST); }
  operator MinFilter() const { return MinFilter(GL_NEAREST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_LINEAR)
struct NearestMipmapLinearEnum {
  operator MinFilter() const { return MinFilter(GL_NEAREST_MIPMAP_LINEAR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_NEAREST)
struct NearestMipmapNearestEnum {
  operator MinFilter() const { return MinFilter(GL_NEAREST_MIPMAP_NEAREST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
struct NeverEnum {
  operator CompareFunc() const { return CompareFunc(GL_NEVER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NICEST)
struct NicestEnum {
  operator HintOption() const { return HintOption(GL_NICEST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
struct NoneEnum {
  operator ColorBuffer() const { return ColorBuffer(GL_NONE); }
  operator CompareMode() const { return CompareMode(GL_NONE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
struct NoopEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_NOOP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
struct NorEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_NOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
struct NotequalEnum {
  operator CompareFunc() const { return CompareFunc(GL_NOTEQUAL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
struct NoErrorEnum {
  operator ErrorType() const { return ErrorType(GL_NO_ERROR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
struct OneEnum {
  operator BlendFunction() const { return BlendFunction(GL_ONE); }
  operator SwizzleMode() const { return SwizzleMode(GL_ONE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_ALPHA)
struct OneMinusConstantAlphaEnum {
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_CONSTANT_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_COLOR)
struct OneMinusConstantColorEnum {
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_CONSTANT_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_ALPHA)
struct OneMinusDstAlphaEnum {
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_DST_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_COLOR)
struct OneMinusDstColorEnum {
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_DST_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_ALPHA)
struct OneMinusSrc1AlphaEnum {
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC1_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_COLOR)
struct OneMinusSrc1ColorEnum {
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC1_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_ALPHA)
struct OneMinusSrcAlphaEnum {
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_COLOR)
struct OneMinusSrcColorEnum {
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
struct OrEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
struct OrInvertedEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR_INVERTED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
struct OrReverseEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR_REVERSE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
struct OutOfMemoryEnum {
  operator ErrorType() const { return ErrorType(GL_OUT_OF_MEMORY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ALIGNMENT)
struct PackAlignmentEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_ALIGNMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_DEPTH)
struct PackCompressedBlockDepthEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_DEPTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_HEIGHT)
struct PackCompressedBlockHeightEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_HEIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_SIZE)
struct PackCompressedBlockSizeEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_SIZE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_WIDTH)
struct PackCompressedBlockWidthEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_WIDTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_IMAGE_HEIGHT)
struct PackImageHeightEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_IMAGE_HEIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_LSB_FIRST)
struct PackLsbFirstEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_LSB_FIRST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ROW_LENGTH)
struct PackRowLengthEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_ROW_LENGTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_IMAGES)
struct PackSkipImagesEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_IMAGES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_PIXELS)
struct PackSkipPixelsEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_PIXELS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_ROWS)
struct PackSkipRowsEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_ROWS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SWAP_BYTES)
struct PackSwapBytesEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SWAP_BYTES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
struct PatchesEnum {
  operator PrimitiveType() const { return PrimitiveType(GL_PATCHES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_BUFFER_BARRIER_BIT)
struct PixelBufferBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_PIXEL_BUFFER_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER)
struct PixelPackBufferEnum {
  operator BufferType() const { return BufferType(GL_PIXEL_PACK_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER)
struct PixelUnpackBufferEnum {
  operator BufferType() const { return BufferType(GL_PIXEL_UNPACK_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
struct PointEnum {
  operator PolyMode() const { return PolyMode(GL_POINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
struct PointsEnum {
  operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_POINTS); }
  operator PrimitiveType() const { return PrimitiveType(GL_POINTS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_FILL)
struct PolygonOffsetFillEnum {
  operator Capability() const { return Capability(GL_POLYGON_OFFSET_FILL); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_LINE)
struct PolygonOffsetLineEnum {
  operator Capability() const { return Capability(GL_POLYGON_OFFSET_LINE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_POINT)
struct PolygonOffsetPointEnum {
  operator Capability() const { return Capability(GL_POLYGON_OFFSET_POINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH)
struct PolygonSmoothEnum {
  operator Capability() const { return Capability(GL_POLYGON_SMOOTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH_HINT)
struct PolygonSmoothHintEnum {
  operator HintTarget() const { return HintTarget(GL_POLYGON_SMOOTH_HINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART)
struct PrimitiveRestartEnum {
  operator Capability() const { return Capability(GL_PRIMITIVE_RESTART); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART_FIXED_INDEX)
struct PrimitiveRestartFixedIndexEnum {
  operator Capability() const { return Capability(GL_PRIMITIVE_RESTART_FIXED_INDEX); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PROGRAM_POINT_SIZE)
struct ProgramPointSizeEnum {
  operator Capability() const { return Capability(GL_PROGRAM_POINT_SIZE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R11F_G11F_B10F)
struct R11FG11FB10FEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R11F_G11F_B10F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16)
struct R16Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16F)
struct R16FEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16I)
struct R16IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16UI)
struct R16UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16_SNORM)
struct R16SnormEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32F)
struct R32FEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32I)
struct R32IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32UI)
struct R32UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R3_G3_B2)
struct R3G3B2Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R3_G3_B2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8)
struct R8Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8I)
struct R8IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8UI)
struct R8UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8_SNORM)
struct R8SnormEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RASTERIZER_DISCARD)
struct RasterizerDiscardEnum {
  operator Capability() const { return Capability(GL_RASTERIZER_DISCARD); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
struct ReadFramebufferEnum {
  operator FramebufferType() const { return FramebufferType(GL_READ_FRAMEBUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
struct ReadOnlyEnum {
  operator BufferMapAccess() const { return BufferMapAccess(GL_READ_ONLY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
struct ReadWriteEnum {
  operator BufferMapAccess() const { return BufferMapAccess(GL_READ_WRITE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
struct RedEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RED); }
  operator SwizzleMode() const { return SwizzleMode(GL_RED); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_RED); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
struct RedIntegerEnum {
  operator PixelDataFormat() const { return PixelDataFormat(GL_RED_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RENDERBUFFER)
struct RenderbufferEnum {
  operator RenderbufferType() const { return RenderbufferType(GL_RENDERBUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPEAT)
struct RepeatEnum {
  operator WrapMode() const { return WrapMode(GL_REPEAT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
struct ReplaceEnum {
  operator StencilOperation() const { return StencilOperation(GL_REPLACE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG)
struct RgEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_RG); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16)
struct Rg16Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16F)
struct Rg16FEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16I)
struct Rg16IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16UI)
struct Rg16UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16_SNORM)
struct Rg16SnormEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32F)
struct Rg32FEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32I)
struct Rg32IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32UI)
struct Rg32UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8)
struct Rg8Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8I)
struct Rg8IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8UI)
struct Rg8UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8_SNORM)
struct Rg8SnormEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
struct RgbEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_RGB); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10)
struct Rgb10Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2)
struct Rgb10A2Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10_A2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2UI)
struct Rgb10A2UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10_A2UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB12)
struct Rgb12Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB12); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16)
struct Rgb16Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16F)
struct Rgb16FEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16I)
struct Rgb16IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16UI)
struct Rgb16UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16_SNORM)
struct Rgb16SnormEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32F)
struct Rgb32FEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32I)
struct Rgb32IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32UI)
struct Rgb32UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB4)
struct Rgb4Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB4); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5)
struct Rgb5Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB5); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5_A1)
struct Rgb5A1Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB5_A1); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8)
struct Rgb8Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8I)
struct Rgb8IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8UI)
struct Rgb8UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8_SNORM)
struct Rgb8SnormEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB9_E5)
struct Rgb9E5Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB9_E5); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
struct RgbaEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_RGBA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA12)
struct Rgba12Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA12); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16)
struct Rgba16Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16F)
struct Rgba16FEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16I)
struct Rgba16IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16UI)
struct Rgba16UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16_SNORM)
struct Rgba16SnormEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA2)
struct Rgba2Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32F)
struct Rgba32FEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32F); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32I)
struct Rgba32IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32UI)
struct Rgba32UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA4)
struct Rgba4Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA4); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8)
struct Rgba8Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8I)
struct Rgba8IEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8I); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8UI)
struct Rgba8UiEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8UI); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8_SNORM)
struct Rgba8SnormEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8_SNORM); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
struct RgbaIntegerEnum {
  operator PixelDataFormat() const { return PixelDataFormat(GL_RGBA_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
struct RgbIntegerEnum {
  operator PixelDataFormat() const { return PixelDataFormat(GL_RGB_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
struct RgIntegerEnum {
  operator PixelDataFormat() const { return PixelDataFormat(GL_RG_INTEGER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RIGHT)
struct RightEnum {
  operator ColorBuffer() const { return ColorBuffer(GL_RIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_COVERAGE)
struct SampleAlphaToCoverageEnum {
  operator Capability() const { return Capability(GL_SAMPLE_ALPHA_TO_COVERAGE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_ONE)
struct SampleAlphaToOneEnum {
  operator Capability() const { return Capability(GL_SAMPLE_ALPHA_TO_ONE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_COVERAGE)
struct SampleCoverageEnum {
  operator Capability() const { return Capability(GL_SAMPLE_COVERAGE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_MASK)
struct SampleMaskEnum {
  operator Capability() const { return Capability(GL_SAMPLE_MASK); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_SHADING)
struct SampleShadingEnum {
  operator Capability() const { return Capability(GL_SAMPLE_SHADING); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_TEST)
struct ScissorTestEnum {
  operator Capability() const { return Capability(GL_SCISSOR_TEST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
struct SetEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_SET); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT)
struct ShaderImageAccessBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BARRIER_BIT)
struct ShaderStorageBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_SHADER_STORAGE_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
struct ShaderStorageBufferEnum {
  operator IndexedBufferType() const { return IndexedBufferType(GL_SHADER_STORAGE_BUFFER); }
  operator BufferType() const { return BufferType(GL_SHADER_STORAGE_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHORT)
struct ShortEnum {
  operator PixelDataType() const { return PixelDataType(GL_SHORT); }
  operator WholeDataType() const { return WholeDataType(GL_SHORT); }
  operator DataType() const { return DataType(GL_SHORT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_ALPHA)
struct Src1AlphaEnum {
  operator BlendFunction() const { return BlendFunction(GL_SRC1_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_COLOR)
struct Src1ColorEnum {
  operator BlendFunction() const { return BlendFunction(GL_SRC1_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA)
struct SrcAlphaEnum {
  operator BlendFunction() const { return BlendFunction(GL_SRC_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA_SATURATE)
struct SrcAlphaSaturateEnum {
  operator BlendFunction() const { return BlendFunction(GL_SRC_ALPHA_SATURATE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_COLOR)
struct SrcColorEnum {
  operator BlendFunction() const { return BlendFunction(GL_SRC_COLOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB)
struct SrgbEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8)
struct Srgb8Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8_ALPHA8)
struct Srgb8Alpha8Enum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB8_ALPHA8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB_ALPHA)
struct SrgbAlphaEnum {
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB_ALPHA); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
struct StackOverflowEnum {
  operator ErrorType() const { return ErrorType(GL_STACK_OVERFLOW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
struct StackUnderflowEnum {
  operator ErrorType() const { return ErrorType(GL_STACK_UNDERFLOW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_COPY)
struct StaticCopyEnum {
  operator BufferUsage() const { return BufferUsage(GL_STATIC_COPY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_DRAW)
struct StaticDrawEnum {
  operator BufferUsage() const { return BufferUsage(GL_STATIC_DRAW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_READ)
struct StaticReadEnum {
  operator BufferUsage() const { return BufferUsage(GL_STATIC_READ); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_ATTACHMENT)
struct StencilAttachmentEnum {
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_STENCIL_ATTACHMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
struct StencilBufferBitEnum {
  operator BufferSelectBit() const { return BufferSelectBit(GL_STENCIL_BUFFER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_INDEX)
struct StencilIndexEnum {
  operator PixelDataFormat() const { return PixelDataFormat(GL_STENCIL_INDEX); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_TEST)
struct StencilTestEnum {
  operator Capability() const { return Capability(GL_STENCIL_TEST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_COPY)
struct StreamCopyEnum {
  operator BufferUsage() const { return BufferUsage(GL_STREAM_COPY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_DRAW)
struct StreamDrawEnum {
  operator BufferUsage() const { return BufferUsage(GL_STREAM_DRAW); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_READ)
struct StreamReadEnum {
  operator BufferUsage() const { return BufferUsage(GL_STREAM_READ); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
struct TableTooLargeEnum {
  operator ErrorType() const { return ErrorType(GL_TABLE_TOO_LARGE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
struct TessControlShaderEnum {
  operator ShaderType() const { return ShaderType(GL_TESS_CONTROL_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
struct TessEvaluationShaderEnum {
  operator ShaderType() const { return ShaderType(GL_TESS_EVALUATION_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D)
struct Texture1DEnum {
  operator TextureType() const { return TextureType(GL_TEXTURE_1D); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
struct Texture1DArrayEnum {
  operator Texture2DType() const { return Texture2DType(GL_TEXTURE_1D_ARRAY); }
  operator TextureType() const { return TextureType(GL_TEXTURE_1D_ARRAY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
struct Texture2DEnum {
  operator Texture2DType() const { return Texture2DType(GL_TEXTURE_2D); }
  operator TextureType() const { return TextureType(GL_TEXTURE_2D); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
struct Texture2DArrayEnum {
  operator Texture3DType() const { return Texture3DType(GL_TEXTURE_2D_ARRAY); }
  operator TextureType() const { return TextureType(GL_TEXTURE_2D_ARRAY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
struct Texture3DEnum {
  operator Texture3DType() const { return Texture3DType(GL_TEXTURE_3D); }
  operator TextureType() const { return TextureType(GL_TEXTURE_3D); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
struct TextureBufferEnum {
  operator BufferType() const { return BufferType(GL_TEXTURE_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_COMPRESSION_HINT)
struct TextureCompressionHintEnum {
  operator HintTarget() const { return HintTarget(GL_TEXTURE_COMPRESSION_HINT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
struct TextureCubeMapEnum {
  operator Texture2DType() const { return Texture2DType(GL_TEXTURE_CUBE_MAP); }
  operator TextureType() const { return TextureType(GL_TEXTURE_CUBE_MAP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
struct TextureCubeMapNegativeXEnum {
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_X); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
struct TextureCubeMapNegativeYEnum {
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
struct TextureCubeMapNegativeZEnum {
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
struct TextureCubeMapPositiveXEnum {
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_X); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
struct TextureCubeMapPositiveYEnum {
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_Y); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
struct TextureCubeMapPositiveZEnum {
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_Z); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_SEAMLESS)
struct TextureCubeMapSeamlessEnum {
  operator Capability() const { return Capability(GL_TEXTURE_CUBE_MAP_SEAMLESS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_FETCH_BARRIER_BIT)
struct TextureFetchBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TEXTURE_FETCH_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
struct TextureRectangleEnum {
  operator Texture2DType() const { return Texture2DType(GL_TEXTURE_RECTANGLE); }
  operator TextureType() const { return TextureType(GL_TEXTURE_RECTANGLE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_UPDATE_BARRIER_BIT)
struct TextureUpdateBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TEXTURE_UPDATE_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK)
struct TransformFeedbackEnum {
  operator TransformFeedbackType() const { return TransformFeedbackType(GL_TRANSFORM_FEEDBACK); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BARRIER_BIT)
struct TransformFeedbackBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TRANSFORM_FEEDBACK_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
struct TransformFeedbackBufferEnum {
  operator IndexedBufferType() const { return IndexedBufferType(GL_TRANSFORM_FEEDBACK_BUFFER); }
  operator BufferType() const { return BufferType(GL_TRANSFORM_FEEDBACK_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
struct TrianglesEnum {
  operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_TRIANGLES); }
  operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
struct TrianglesAdjacencyEnum {
  operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLES_ADJACENCY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
struct TriangleFanEnum {
  operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_FAN); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
struct TriangleStripEnum {
  operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_STRIP); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
struct TriangleStripAdjacencyEnum {
  operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_STRIP_ADJACENCY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BARRIER_BIT)
struct UniformBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_UNIFORM_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
struct UniformBufferEnum {
  operator IndexedBufferType() const { return IndexedBufferType(GL_UNIFORM_BUFFER); }
  operator BufferType() const { return BufferType(GL_UNIFORM_BUFFER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ALIGNMENT)
struct UnpackAlignmentEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_ALIGNMENT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_DEPTH)
struct UnpackCompressedBlockDepthEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_DEPTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT)
struct UnpackCompressedBlockHeightEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_SIZE)
struct UnpackCompressedBlockSizeEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_SIZE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_WIDTH)
struct UnpackCompressedBlockWidthEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_WIDTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_IMAGE_HEIGHT)
struct UnpackImageHeightEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_IMAGE_HEIGHT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_LSB_FIRST)
struct UnpackLsbFirstEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_LSB_FIRST); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ROW_LENGTH)
struct UnpackRowLengthEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_ROW_LENGTH); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_IMAGES)
struct UnpackSkipImagesEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_IMAGES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_PIXELS)
struct UnpackSkipPixelsEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_PIXELS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_ROWS)
struct UnpackSkipRowsEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_ROWS); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SWAP_BYTES)
struct UnpackSwapBytesEnum {
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SWAP_BYTES); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE)
struct UnsignedByteEnum {
  operator IndexType() const { return IndexType(GL_UNSIGNED_BYTE); }
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE); }
  operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_BYTE); }
  operator DataType() const { return DataType(GL_UNSIGNED_BYTE); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_2_3_3_REV)
struct UnsignedByte233RevEnum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE_2_3_3_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_3_3_2)
struct UnsignedByte332Enum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE_3_3_2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT)
struct UnsignedIntEnum {
  operator IndexType() const { return IndexType(GL_UNSIGNED_INT); }
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT); }
  operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_INT); }
  operator DataType() const { return DataType(GL_UNSIGNED_INT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10F_11F_11F_REV)
struct UnsignedInt10F11F11FRevEnum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_10F_11F_11F_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10_10_10_2)
struct UnsignedInt1010102Enum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_10_10_10_2); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_24_8)
struct UnsignedInt248Enum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_24_8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_2_10_10_10_REV)
struct UnsignedInt2101010RevEnum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_2_10_10_10_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_5_9_9_9_REV)
struct UnsignedInt5999RevEnum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_5_9_9_9_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8)
struct UnsignedInt8888Enum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_8_8_8_8); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8_REV)
struct UnsignedInt8888RevEnum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_8_8_8_8_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT)
struct UnsignedShortEnum {
  operator IndexType() const { return IndexType(GL_UNSIGNED_SHORT); }
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT); }
  operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_SHORT); }
  operator DataType() const { return DataType(GL_UNSIGNED_SHORT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_1_5_5_5_REV)
struct UnsignedShort1555RevEnum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_1_5_5_5_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4)
struct UnsignedShort4444Enum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_4_4_4_4); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4_REV)
struct UnsignedShort4444RevEnum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_4_4_4_4_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_5_5_1)
struct UnsignedShort5551Enum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_5_5_1); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5)
struct UnsignedShort565Enum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_6_5); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5_REV)
struct UnsignedShort565RevEnum {
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_6_5_REV); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ARRAY)
struct VertexArrayEnum {
  operator VertexArrayType() const { return VertexArrayType(GL_VERTEX_ARRAY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT)
struct VertexAttribArrayBarrierBitEnum {
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
struct VertexShaderEnum {
  operator ShaderType() const { return ShaderType(GL_VERTEX_SHADER); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
struct WriteOnlyEnum {
  operator BufferMapAccess() const { return BufferMapAccess(GL_WRITE_ONLY); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
struct XorEnum {
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_XOR); }
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
struct ZeroEnum {
  operator StencilOperation() const { return StencilOperation(GL_ZERO); }
  operator BlendFunction() const { return BlendFunction(GL_ZERO); }
  operator SwizzleMode() const { return SwizzleMode(GL_ZERO); }
};
#endif

} // namespace smart_enums

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALPHA)
  static smart_enums::AlphaEnum kAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
  static smart_enums::AlwaysEnum kAlways;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
  static smart_enums::AndEnum kAnd;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
  static smart_enums::AndInvertedEnum kAndInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
  static smart_enums::AndReverseEnum kAndReverse;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
  static smart_enums::ArrayBufferEnum kArrayBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BARRIER_BIT)
  static smart_enums::AtomicCounterBarrierBitEnum kAtomicCounterBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
  static smart_enums::AtomicCounterBufferEnum kAtomicCounterBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
  static smart_enums::BackEnum kBack;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_LEFT)
  static smart_enums::BackLeftEnum kBackLeft;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_RIGHT)
  static smart_enums::BackRightEnum kBackRight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
  static smart_enums::BgrEnum kBgr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
  static smart_enums::BgraEnum kBgra;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
  static smart_enums::BgraIntegerEnum kBgraInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
  static smart_enums::BgrIntegerEnum kBgrInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLEND)
  static smart_enums::BlendEnum kBlend;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
  static smart_enums::BlueEnum kBlue;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
  static smart_enums::BlueIntegerEnum kBlueInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BUFFER_UPDATE_BARRIER_BIT)
  static smart_enums::BufferUpdateBarrierBitEnum kBufferUpdateBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BYTE)
  static smart_enums::ByteEnum kByte;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
  static smart_enums::CcwEnum kCcw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_BORDER)
  static smart_enums::ClampToBorderEnum kClampToBorder;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_EDGE)
  static smart_enums::ClampToEdgeEnum kClampToEdge;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
  static smart_enums::ClearEnum kClear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT)
  static smart_enums::ClientMappedBufferBarrierBitEnum kClientMappedBufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIP_DISTANCE)
  static smart_enums::ClipDistanceEnum kClipDistance;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT0)
  static smart_enums::ColorAttachment0Enum kColorAttachment0;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT1)
  static smart_enums::ColorAttachment1Enum kColorAttachment1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT10)
  static smart_enums::ColorAttachment10Enum kColorAttachment10;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT11)
  static smart_enums::ColorAttachment11Enum kColorAttachment11;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT12)
  static smart_enums::ColorAttachment12Enum kColorAttachment12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT13)
  static smart_enums::ColorAttachment13Enum kColorAttachment13;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT14)
  static smart_enums::ColorAttachment14Enum kColorAttachment14;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT15)
  static smart_enums::ColorAttachment15Enum kColorAttachment15;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT2)
  static smart_enums::ColorAttachment2Enum kColorAttachment2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT3)
  static smart_enums::ColorAttachment3Enum kColorAttachment3;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT4)
  static smart_enums::ColorAttachment4Enum kColorAttachment4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT5)
  static smart_enums::ColorAttachment5Enum kColorAttachment5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT6)
  static smart_enums::ColorAttachment6Enum kColorAttachment6;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT7)
  static smart_enums::ColorAttachment7Enum kColorAttachment7;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT8)
  static smart_enums::ColorAttachment8Enum kColorAttachment8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT9)
  static smart_enums::ColorAttachment9Enum kColorAttachment9;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
  static smart_enums::ColorBufferBitEnum kColorBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_LOGIC_OP)
  static smart_enums::ColorLogicOpEnum kColorLogicOp;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMMAND_BARRIER_BIT)
  static smart_enums::CommandBarrierBitEnum kCommandBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPARE_REF_TO_TEXTURE)
  static smart_enums::CompareRefToTextureEnum kCompareRefToTexture;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED)
  static smart_enums::CompressedRedEnum kCompressedRed;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED_RGTC1)
  static smart_enums::CompressedRedRgtc1Enum kCompressedRedRgtc1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG)
  static smart_enums::CompressedRgEnum kCompressedRg;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGB)
  static smart_enums::CompressedRgbEnum kCompressedRgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGBA)
  static smart_enums::CompressedRgbaEnum kCompressedRgba;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG_RGTC2)
  static smart_enums::CompressedRgRgtc2Enum kCompressedRgRgtc2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RED_RGTC1)
  static smart_enums::CompressedSignedRedRgtc1Enum kCompressedSignedRedRgtc1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RG_RGTC2)
  static smart_enums::CompressedSignedRgRgtc2Enum kCompressedSignedRgRgtc2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB)
  static smart_enums::CompressedSrgbEnum kCompressedSrgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB_ALPHA)
  static smart_enums::CompressedSrgbAlphaEnum kCompressedSrgbAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
  static smart_enums::ComputeShaderEnum kComputeShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_ALPHA)
  static smart_enums::ConstantAlphaEnum kConstantAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_COLOR)
  static smart_enums::ConstantColorEnum kConstantColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
  static smart_enums::CopyEnum kCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
  static smart_enums::CopyInvertedEnum kCopyInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
  static smart_enums::CopyReadBufferEnum kCopyReadBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
  static smart_enums::CopyWriteBufferEnum kCopyWriteBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CULL_FACE)
  static smart_enums::CullFaceEnum kCullFace;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
  static smart_enums::CwEnum kCw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT)
  static smart_enums::DebugOutputEnum kDebugOutput;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT_SYNCHRONOUS)
  static smart_enums::DebugOutputSynchronousEnum kDebugOutputSynchronous;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
  static smart_enums::DecrEnum kDecr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
  static smart_enums::DecrWrapEnum kDecrWrap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_ATTACHMENT)
  static smart_enums::DepthAttachmentEnum kDepthAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
  static smart_enums::DepthBufferBitEnum kDepthBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_CLAMP)
  static smart_enums::DepthClampEnum kDepthClamp;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_COMPONENT)
  static smart_enums::DepthComponentEnum kDepthComponent;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL)
  static smart_enums::DepthStencilEnum kDepthStencil;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL_ATTACHMENT)
  static smart_enums::DepthStencilAttachmentEnum kDepthStencilAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_TEST)
  static smart_enums::DepthTestEnum kDepthTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER)
  static smart_enums::DispatchIndirectBufferEnum kDispatchIndirectBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DITHER)
  static smart_enums::DitherEnum kDither;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DONT_CARE)
  static smart_enums::DontCareEnum kDontCare;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DOUBLE)
  static smart_enums::DoubleEnum kDouble;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
  static smart_enums::DrawFramebufferEnum kDrawFramebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER)
  static smart_enums::DrawIndirectBufferEnum kDrawIndirectBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_ALPHA)
  static smart_enums::DstAlphaEnum kDstAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_COLOR)
  static smart_enums::DstColorEnum kDstColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_COPY)
  static smart_enums::DynamicCopyEnum kDynamicCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_DRAW)
  static smart_enums::DynamicDrawEnum kDynamicDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_READ)
  static smart_enums::DynamicReadEnum kDynamicRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BARRIER_BIT)
  static smart_enums::ElementArrayBarrierBitEnum kElementArrayBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
  static smart_enums::ElementArrayBufferEnum kElementArrayBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
  static smart_enums::EqualEnum kEqual;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
  static smart_enums::EquivEnum kEquiv;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FASTEST)
  static smart_enums::FastestEnum kFastest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
  static smart_enums::FillEnum kFill;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
  static smart_enums::FirstVertexConventionEnum kFirstVertexConvention;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIXED)
  static smart_enums::FixedEnum kFixed;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT)
  static smart_enums::FloatEnum kFloat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
  static smart_enums::Float32UnsignedInt248RevEnum kFloat32UnsignedInt248Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
  static smart_enums::FragmentShaderEnum kFragmentShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
  static smart_enums::FragmentShaderDerivativeHintEnum kFragmentShaderDerivativeHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
  static smart_enums::FramebufferEnum kFramebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BARRIER_BIT)
  static smart_enums::FramebufferBarrierBitEnum kFramebufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_COMPLETE)
  static smart_enums::FramebufferCompleteEnum kFramebufferComplete;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
  static smart_enums::FramebufferIncompleteAttachmentEnum kFramebufferIncompleteAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER)
  static smart_enums::FramebufferIncompleteDrawBufferEnum kFramebufferIncompleteDrawBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
  static smart_enums::FramebufferIncompleteLayerTargetsEnum kFramebufferIncompleteLayerTargets;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
  static smart_enums::FramebufferIncompleteMissingAttachmentEnum kFramebufferIncompleteMissingAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
  static smart_enums::FramebufferIncompleteMultisampleEnum kFramebufferIncompleteMultisample;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER)
  static smart_enums::FramebufferIncompleteReadBufferEnum kFramebufferIncompleteReadBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_SRGB)
  static smart_enums::FramebufferSrgbEnum kFramebufferSrgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNDEFINED)
  static smart_enums::FramebufferUndefinedEnum kFramebufferUndefined;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNSUPPORTED)
  static smart_enums::FramebufferUnsupportedEnum kFramebufferUnsupported;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
  static smart_enums::FrontEnum kFront;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
  static smart_enums::FrontAndBackEnum kFrontAndBack;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_LEFT)
  static smart_enums::FrontLeftEnum kFrontLeft;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_RIGHT)
  static smart_enums::FrontRightEnum kFrontRight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_ADD)
  static smart_enums::FuncAddEnum kFuncAdd;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_REVERSE_SUBTRACT)
  static smart_enums::FuncReverseSubtractEnum kFuncReverseSubtract;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_SUBTRACT)
  static smart_enums::FuncSubtractEnum kFuncSubtract;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
  static smart_enums::GeometryShaderEnum kGeometryShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
  static smart_enums::GequalEnum kGequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
  static smart_enums::GreaterEnum kGreater;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
  static smart_enums::GreenEnum kGreen;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
  static smart_enums::GreenIntegerEnum kGreenInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_HALF_FLOAT)
  static smart_enums::HalfFloatEnum kHalfFloat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
  static smart_enums::IncrEnum kIncr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
  static smart_enums::IncrWrapEnum kIncrWrap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INT)
  static smart_enums::IntEnum kInt;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
  static smart_enums::InvalidEnumEnum kInvalidEnum;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
  static smart_enums::InvalidFramebufferOperationEnum kInvalidFramebufferOperation;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
  static smart_enums::InvalidOperationEnum kInvalidOperation;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
  static smart_enums::InvalidValueEnum kInvalidValue;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
  static smart_enums::InvertEnum kInvert;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
  static smart_enums::KeepEnum kKeep;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
  static smart_enums::LastVertexConventionEnum kLastVertexConvention;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEFT)
  static smart_enums::LeftEnum kLeft;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
  static smart_enums::LequalEnum kLequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
  static smart_enums::LessEnum kLess;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
  static smart_enums::LineEnum kLine;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
  static smart_enums::LinearEnum kLinear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_LINEAR)
  static smart_enums::LinearMipmapLinearEnum kLinearMipmapLinear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_NEAREST)
  static smart_enums::LinearMipmapNearestEnum kLinearMipmapNearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
  static smart_enums::LinesEnum kLines;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
  static smart_enums::LinesAdjacencyEnum kLinesAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
  static smart_enums::LineLoopEnum kLineLoop;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH)
  static smart_enums::LineSmoothEnum kLineSmooth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH_HINT)
  static smart_enums::LineSmoothHintEnum kLineSmoothHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
  static smart_enums::LineStripEnum kLineStrip;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
  static smart_enums::LineStripAdjacencyEnum kLineStripAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
  static smart_enums::MapCoherentBitEnum kMapCoherentBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
  static smart_enums::MapFlushExplicitBitEnum kMapFlushExplicitBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
  static smart_enums::MapInvalidateBufferBitEnum kMapInvalidateBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
  static smart_enums::MapInvalidateRangeBitEnum kMapInvalidateRangeBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
  static smart_enums::MapPersistentBitEnum kMapPersistentBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
  static smart_enums::MapReadBitEnum kMapReadBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
  static smart_enums::MapUnsynchronizedBitEnum kMapUnsynchronizedBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
  static smart_enums::MapWriteBitEnum kMapWriteBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAX)
  static smart_enums::MaxEnum kMax;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN)
  static smart_enums::MinEnum kMin;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIRRORED_REPEAT)
  static smart_enums::MirroredRepeatEnum kMirroredRepeat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MULTISAMPLE)
  static smart_enums::MultisampleEnum kMultisample;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
  static smart_enums::NandEnum kNand;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
  static smart_enums::NearestEnum kNearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_LINEAR)
  static smart_enums::NearestMipmapLinearEnum kNearestMipmapLinear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_NEAREST)
  static smart_enums::NearestMipmapNearestEnum kNearestMipmapNearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
  static smart_enums::NeverEnum kNever;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NICEST)
  static smart_enums::NicestEnum kNicest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
  static smart_enums::NoneEnum kNone;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
  static smart_enums::NoopEnum kNoop;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
  static smart_enums::NorEnum kNor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
  static smart_enums::NotequalEnum kNotequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
  static smart_enums::NoErrorEnum kNoError;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
  static smart_enums::OneEnum kOne;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_ALPHA)
  static smart_enums::OneMinusConstantAlphaEnum kOneMinusConstantAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_COLOR)
  static smart_enums::OneMinusConstantColorEnum kOneMinusConstantColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_ALPHA)
  static smart_enums::OneMinusDstAlphaEnum kOneMinusDstAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_COLOR)
  static smart_enums::OneMinusDstColorEnum kOneMinusDstColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_ALPHA)
  static smart_enums::OneMinusSrc1AlphaEnum kOneMinusSrc1Alpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_COLOR)
  static smart_enums::OneMinusSrc1ColorEnum kOneMinusSrc1Color;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_ALPHA)
  static smart_enums::OneMinusSrcAlphaEnum kOneMinusSrcAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_COLOR)
  static smart_enums::OneMinusSrcColorEnum kOneMinusSrcColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
  static smart_enums::OrEnum kOr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
  static smart_enums::OrInvertedEnum kOrInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
  static smart_enums::OrReverseEnum kOrReverse;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
  static smart_enums::OutOfMemoryEnum kOutOfMemory;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ALIGNMENT)
  static smart_enums::PackAlignmentEnum kPackAlignment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_DEPTH)
  static smart_enums::PackCompressedBlockDepthEnum kPackCompressedBlockDepth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_HEIGHT)
  static smart_enums::PackCompressedBlockHeightEnum kPackCompressedBlockHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_SIZE)
  static smart_enums::PackCompressedBlockSizeEnum kPackCompressedBlockSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_WIDTH)
  static smart_enums::PackCompressedBlockWidthEnum kPackCompressedBlockWidth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_IMAGE_HEIGHT)
  static smart_enums::PackImageHeightEnum kPackImageHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_LSB_FIRST)
  static smart_enums::PackLsbFirstEnum kPackLsbFirst;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ROW_LENGTH)
  static smart_enums::PackRowLengthEnum kPackRowLength;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_IMAGES)
  static smart_enums::PackSkipImagesEnum kPackSkipImages;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_PIXELS)
  static smart_enums::PackSkipPixelsEnum kPackSkipPixels;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_ROWS)
  static smart_enums::PackSkipRowsEnum kPackSkipRows;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SWAP_BYTES)
  static smart_enums::PackSwapBytesEnum kPackSwapBytes;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
  static smart_enums::PatchesEnum kPatches;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_BUFFER_BARRIER_BIT)
  static smart_enums::PixelBufferBarrierBitEnum kPixelBufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER)
  static smart_enums::PixelPackBufferEnum kPixelPackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER)
  static smart_enums::PixelUnpackBufferEnum kPixelUnpackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
  static smart_enums::PointEnum kPoint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
  static smart_enums::PointsEnum kPoints;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_FILL)
  static smart_enums::PolygonOffsetFillEnum kPolygonOffsetFill;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_LINE)
  static smart_enums::PolygonOffsetLineEnum kPolygonOffsetLine;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_POINT)
  static smart_enums::PolygonOffsetPointEnum kPolygonOffsetPoint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH)
  static smart_enums::PolygonSmoothEnum kPolygonSmooth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH_HINT)
  static smart_enums::PolygonSmoothHintEnum kPolygonSmoothHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART)
  static smart_enums::PrimitiveRestartEnum kPrimitiveRestart;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART_FIXED_INDEX)
  static smart_enums::PrimitiveRestartFixedIndexEnum kPrimitiveRestartFixedIndex;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PROGRAM_POINT_SIZE)
  static smart_enums::ProgramPointSizeEnum kProgramPointSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R11F_G11F_B10F)
  static smart_enums::R11FG11FB10FEnum kR11FG11FB10F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16)
  static smart_enums::R16Enum kR16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16F)
  static smart_enums::R16FEnum kR16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16I)
  static smart_enums::R16IEnum kR16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16UI)
  static smart_enums::R16UiEnum kR16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16_SNORM)
  static smart_enums::R16SnormEnum kR16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32F)
  static smart_enums::R32FEnum kR32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32I)
  static smart_enums::R32IEnum kR32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32UI)
  static smart_enums::R32UiEnum kR32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R3_G3_B2)
  static smart_enums::R3G3B2Enum kR3G3B2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8)
  static smart_enums::R8Enum kR8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8I)
  static smart_enums::R8IEnum kR8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8UI)
  static smart_enums::R8UiEnum kR8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8_SNORM)
  static smart_enums::R8SnormEnum kR8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RASTERIZER_DISCARD)
  static smart_enums::RasterizerDiscardEnum kRasterizerDiscard;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
  static smart_enums::ReadFramebufferEnum kReadFramebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
  static smart_enums::ReadOnlyEnum kReadOnly;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
  static smart_enums::ReadWriteEnum kReadWrite;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
  static smart_enums::RedEnum kRed;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
  static smart_enums::RedIntegerEnum kRedInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RENDERBUFFER)
  static smart_enums::RenderbufferEnum kRenderbuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPEAT)
  static smart_enums::RepeatEnum kRepeat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
  static smart_enums::ReplaceEnum kReplace;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG)
  static smart_enums::RgEnum kRg;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16)
  static smart_enums::Rg16Enum kRg16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16F)
  static smart_enums::Rg16FEnum kRg16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16I)
  static smart_enums::Rg16IEnum kRg16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16UI)
  static smart_enums::Rg16UiEnum kRg16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16_SNORM)
  static smart_enums::Rg16SnormEnum kRg16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32F)
  static smart_enums::Rg32FEnum kRg32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32I)
  static smart_enums::Rg32IEnum kRg32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32UI)
  static smart_enums::Rg32UiEnum kRg32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8)
  static smart_enums::Rg8Enum kRg8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8I)
  static smart_enums::Rg8IEnum kRg8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8UI)
  static smart_enums::Rg8UiEnum kRg8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8_SNORM)
  static smart_enums::Rg8SnormEnum kRg8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
  static smart_enums::RgbEnum kRgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10)
  static smart_enums::Rgb10Enum kRgb10;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2)
  static smart_enums::Rgb10A2Enum kRgb10A2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2UI)
  static smart_enums::Rgb10A2UiEnum kRgb10A2Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB12)
  static smart_enums::Rgb12Enum kRgb12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16)
  static smart_enums::Rgb16Enum kRgb16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16F)
  static smart_enums::Rgb16FEnum kRgb16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16I)
  static smart_enums::Rgb16IEnum kRgb16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16UI)
  static smart_enums::Rgb16UiEnum kRgb16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16_SNORM)
  static smart_enums::Rgb16SnormEnum kRgb16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32F)
  static smart_enums::Rgb32FEnum kRgb32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32I)
  static smart_enums::Rgb32IEnum kRgb32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32UI)
  static smart_enums::Rgb32UiEnum kRgb32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB4)
  static smart_enums::Rgb4Enum kRgb4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5)
  static smart_enums::Rgb5Enum kRgb5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5_A1)
  static smart_enums::Rgb5A1Enum kRgb5A1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8)
  static smart_enums::Rgb8Enum kRgb8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8I)
  static smart_enums::Rgb8IEnum kRgb8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8UI)
  static smart_enums::Rgb8UiEnum kRgb8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8_SNORM)
  static smart_enums::Rgb8SnormEnum kRgb8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB9_E5)
  static smart_enums::Rgb9E5Enum kRgb9E5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
  static smart_enums::RgbaEnum kRgba;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA12)
  static smart_enums::Rgba12Enum kRgba12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16)
  static smart_enums::Rgba16Enum kRgba16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16F)
  static smart_enums::Rgba16FEnum kRgba16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16I)
  static smart_enums::Rgba16IEnum kRgba16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16UI)
  static smart_enums::Rgba16UiEnum kRgba16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16_SNORM)
  static smart_enums::Rgba16SnormEnum kRgba16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA2)
  static smart_enums::Rgba2Enum kRgba2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32F)
  static smart_enums::Rgba32FEnum kRgba32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32I)
  static smart_enums::Rgba32IEnum kRgba32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32UI)
  static smart_enums::Rgba32UiEnum kRgba32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA4)
  static smart_enums::Rgba4Enum kRgba4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8)
  static smart_enums::Rgba8Enum kRgba8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8I)
  static smart_enums::Rgba8IEnum kRgba8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8UI)
  static smart_enums::Rgba8UiEnum kRgba8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8_SNORM)
  static smart_enums::Rgba8SnormEnum kRgba8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
  static smart_enums::RgbaIntegerEnum kRgbaInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
  static smart_enums::RgbIntegerEnum kRgbInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
  static smart_enums::RgIntegerEnum kRgInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RIGHT)
  static smart_enums::RightEnum kRight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_COVERAGE)
  static smart_enums::SampleAlphaToCoverageEnum kSampleAlphaToCoverage;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_ONE)
  static smart_enums::SampleAlphaToOneEnum kSampleAlphaToOne;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_COVERAGE)
  static smart_enums::SampleCoverageEnum kSampleCoverage;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_MASK)
  static smart_enums::SampleMaskEnum kSampleMask;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_SHADING)
  static smart_enums::SampleShadingEnum kSampleShading;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_TEST)
  static smart_enums::ScissorTestEnum kScissorTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
  static smart_enums::SetEnum kSet;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT)
  static smart_enums::ShaderImageAccessBarrierBitEnum kShaderImageAccessBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BARRIER_BIT)
  static smart_enums::ShaderStorageBarrierBitEnum kShaderStorageBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
  static smart_enums::ShaderStorageBufferEnum kShaderStorageBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHORT)
  static smart_enums::ShortEnum kShort;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_ALPHA)
  static smart_enums::Src1AlphaEnum kSrc1Alpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_COLOR)
  static smart_enums::Src1ColorEnum kSrc1Color;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA)
  static smart_enums::SrcAlphaEnum kSrcAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA_SATURATE)
  static smart_enums::SrcAlphaSaturateEnum kSrcAlphaSaturate;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_COLOR)
  static smart_enums::SrcColorEnum kSrcColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB)
  static smart_enums::SrgbEnum kSrgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8)
  static smart_enums::Srgb8Enum kSrgb8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8_ALPHA8)
  static smart_enums::Srgb8Alpha8Enum kSrgb8Alpha8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB_ALPHA)
  static smart_enums::SrgbAlphaEnum kSrgbAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
  static smart_enums::StackOverflowEnum kStackOverflow;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
  static smart_enums::StackUnderflowEnum kStackUnderflow;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_COPY)
  static smart_enums::StaticCopyEnum kStaticCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_DRAW)
  static smart_enums::StaticDrawEnum kStaticDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_READ)
  static smart_enums::StaticReadEnum kStaticRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_ATTACHMENT)
  static smart_enums::StencilAttachmentEnum kStencilAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
  static smart_enums::StencilBufferBitEnum kStencilBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_INDEX)
  static smart_enums::StencilIndexEnum kStencilIndex;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_TEST)
  static smart_enums::StencilTestEnum kStencilTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_COPY)
  static smart_enums::StreamCopyEnum kStreamCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_DRAW)
  static smart_enums::StreamDrawEnum kStreamDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_READ)
  static smart_enums::StreamReadEnum kStreamRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
  static smart_enums::TableTooLargeEnum kTableTooLarge;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
  static smart_enums::TessControlShaderEnum kTessControlShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
  static smart_enums::TessEvaluationShaderEnum kTessEvaluationShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D)
  static smart_enums::Texture1DEnum kTexture1D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
  static smart_enums::Texture1DArrayEnum kTexture1DArray;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
  static smart_enums::Texture2DEnum kTexture2D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
  static smart_enums::Texture2DArrayEnum kTexture2DArray;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
  static smart_enums::Texture3DEnum kTexture3D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
  static smart_enums::TextureBufferEnum kTextureBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_COMPRESSION_HINT)
  static smart_enums::TextureCompressionHintEnum kTextureCompressionHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
  static smart_enums::TextureCubeMapEnum kTextureCubeMap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
  static smart_enums::TextureCubeMapNegativeXEnum kTextureCubeMapNegativeX;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
  static smart_enums::TextureCubeMapNegativeYEnum kTextureCubeMapNegativeY;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
  static smart_enums::TextureCubeMapNegativeZEnum kTextureCubeMapNegativeZ;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
  static smart_enums::TextureCubeMapPositiveXEnum kTextureCubeMapPositiveX;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
  static smart_enums::TextureCubeMapPositiveYEnum kTextureCubeMapPositiveY;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
  static smart_enums::TextureCubeMapPositiveZEnum kTextureCubeMapPositiveZ;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_SEAMLESS)
  static smart_enums::TextureCubeMapSeamlessEnum kTextureCubeMapSeamless;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_FETCH_BARRIER_BIT)
  static smart_enums::TextureFetchBarrierBitEnum kTextureFetchBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
  static smart_enums::TextureRectangleEnum kTextureRectangle;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_UPDATE_BARRIER_BIT)
  static smart_enums::TextureUpdateBarrierBitEnum kTextureUpdateBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK)
  static smart_enums::TransformFeedbackEnum kTransformFeedback;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BARRIER_BIT)
  static smart_enums::TransformFeedbackBarrierBitEnum kTransformFeedbackBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
  static smart_enums::TransformFeedbackBufferEnum kTransformFeedbackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
  static smart_enums::TrianglesEnum kTriangles;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
  static smart_enums::TrianglesAdjacencyEnum kTrianglesAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
  static smart_enums::TriangleFanEnum kTriangleFan;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
  static smart_enums::TriangleStripEnum kTriangleStrip;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
  static smart_enums::TriangleStripAdjacencyEnum kTriangleStripAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BARRIER_BIT)
  static smart_enums::UniformBarrierBitEnum kUniformBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
  static smart_enums::UniformBufferEnum kUniformBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ALIGNMENT)
  static smart_enums::UnpackAlignmentEnum kUnpackAlignment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_DEPTH)
  static smart_enums::UnpackCompressedBlockDepthEnum kUnpackCompressedBlockDepth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT)
  static smart_enums::UnpackCompressedBlockHeightEnum kUnpackCompressedBlockHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_SIZE)
  static smart_enums::UnpackCompressedBlockSizeEnum kUnpackCompressedBlockSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_WIDTH)
  static smart_enums::UnpackCompressedBlockWidthEnum kUnpackCompressedBlockWidth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_IMAGE_HEIGHT)
  static smart_enums::UnpackImageHeightEnum kUnpackImageHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_LSB_FIRST)
  static smart_enums::UnpackLsbFirstEnum kUnpackLsbFirst;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ROW_LENGTH)
  static smart_enums::UnpackRowLengthEnum kUnpackRowLength;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_IMAGES)
  static smart_enums::UnpackSkipImagesEnum kUnpackSkipImages;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_PIXELS)
  static smart_enums::UnpackSkipPixelsEnum kUnpackSkipPixels;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_ROWS)
  static smart_enums::UnpackSkipRowsEnum kUnpackSkipRows;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SWAP_BYTES)
  static smart_enums::UnpackSwapBytesEnum kUnpackSwapBytes;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE)
  static smart_enums::UnsignedByteEnum kUnsignedByte;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_2_3_3_REV)
  static smart_enums::UnsignedByte233RevEnum kUnsignedByte233Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_3_3_2)
  static smart_enums::UnsignedByte332Enum kUnsignedByte332;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT)
  static smart_enums::UnsignedIntEnum kUnsignedInt;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10F_11F_11F_REV)
  static smart_enums::UnsignedInt10F11F11FRevEnum kUnsignedInt10F11F11FRev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10_10_10_2)
  static smart_enums::UnsignedInt1010102Enum kUnsignedInt1010102;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_24_8)
  static smart_enums::UnsignedInt248Enum kUnsignedInt248;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_2_10_10_10_REV)
  static smart_enums::UnsignedInt2101010RevEnum kUnsignedInt2101010Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_5_9_9_9_REV)
  static smart_enums::UnsignedInt5999RevEnum kUnsignedInt5999Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8)
  static smart_enums::UnsignedInt8888Enum kUnsignedInt8888;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8_REV)
  static smart_enums::UnsignedInt8888RevEnum kUnsignedInt8888Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT)
  static smart_enums::UnsignedShortEnum kUnsignedShort;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_1_5_5_5_REV)
  static smart_enums::UnsignedShort1555RevEnum kUnsignedShort1555Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4)
  static smart_enums::UnsignedShort4444Enum kUnsignedShort4444;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4_REV)
  static smart_enums::UnsignedShort4444RevEnum kUnsignedShort4444Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_5_5_1)
  static smart_enums::UnsignedShort5551Enum kUnsignedShort5551;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5)
  static smart_enums::UnsignedShort565Enum kUnsignedShort565;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5_REV)
  static smart_enums::UnsignedShort565RevEnum kUnsignedShort565Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ARRAY)
  static smart_enums::VertexArrayEnum kVertexArray;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT)
  static smart_enums::VertexAttribArrayBarrierBitEnum kVertexAttribArrayBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
  static smart_enums::VertexShaderEnum kVertexShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
  static smart_enums::WriteOnlyEnum kWriteOnly;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
  static smart_enums::XorEnum kXor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  static smart_enums::ZeroEnum kZero;
#endif

// Just an ugly hack to surpress -Wunused-variable
template<typename T> static void _OGLWRAP_SUPPRESS_UNUSED() {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALPHA)
  (void) kAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
  (void) kAlways;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
  (void) kAnd;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
  (void) kAndInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
  (void) kAndReverse;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
  (void) kArrayBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BARRIER_BIT)
  (void) kAtomicCounterBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
  (void) kAtomicCounterBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
  (void) kBack;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_LEFT)
  (void) kBackLeft;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_RIGHT)
  (void) kBackRight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
  (void) kBgr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
  (void) kBgra;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
  (void) kBgraInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
  (void) kBgrInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLEND)
  (void) kBlend;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
  (void) kBlue;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
  (void) kBlueInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BUFFER_UPDATE_BARRIER_BIT)
  (void) kBufferUpdateBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BYTE)
  (void) kByte;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
  (void) kCcw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_BORDER)
  (void) kClampToBorder;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_EDGE)
  (void) kClampToEdge;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
  (void) kClear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT)
  (void) kClientMappedBufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIP_DISTANCE)
  (void) kClipDistance;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT0)
  (void) kColorAttachment0;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT1)
  (void) kColorAttachment1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT10)
  (void) kColorAttachment10;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT11)
  (void) kColorAttachment11;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT12)
  (void) kColorAttachment12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT13)
  (void) kColorAttachment13;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT14)
  (void) kColorAttachment14;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT15)
  (void) kColorAttachment15;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT2)
  (void) kColorAttachment2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT3)
  (void) kColorAttachment3;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT4)
  (void) kColorAttachment4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT5)
  (void) kColorAttachment5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT6)
  (void) kColorAttachment6;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT7)
  (void) kColorAttachment7;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT8)
  (void) kColorAttachment8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT9)
  (void) kColorAttachment9;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
  (void) kColorBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_LOGIC_OP)
  (void) kColorLogicOp;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMMAND_BARRIER_BIT)
  (void) kCommandBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPARE_REF_TO_TEXTURE)
  (void) kCompareRefToTexture;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED)
  (void) kCompressedRed;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED_RGTC1)
  (void) kCompressedRedRgtc1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG)
  (void) kCompressedRg;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGB)
  (void) kCompressedRgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGBA)
  (void) kCompressedRgba;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG_RGTC2)
  (void) kCompressedRgRgtc2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RED_RGTC1)
  (void) kCompressedSignedRedRgtc1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RG_RGTC2)
  (void) kCompressedSignedRgRgtc2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB)
  (void) kCompressedSrgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB_ALPHA)
  (void) kCompressedSrgbAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
  (void) kComputeShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_ALPHA)
  (void) kConstantAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_COLOR)
  (void) kConstantColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
  (void) kCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
  (void) kCopyInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
  (void) kCopyReadBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
  (void) kCopyWriteBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CULL_FACE)
  (void) kCullFace;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
  (void) kCw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT)
  (void) kDebugOutput;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT_SYNCHRONOUS)
  (void) kDebugOutputSynchronous;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
  (void) kDecr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
  (void) kDecrWrap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_ATTACHMENT)
  (void) kDepthAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
  (void) kDepthBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_CLAMP)
  (void) kDepthClamp;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_COMPONENT)
  (void) kDepthComponent;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL)
  (void) kDepthStencil;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL_ATTACHMENT)
  (void) kDepthStencilAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_TEST)
  (void) kDepthTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER)
  (void) kDispatchIndirectBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DITHER)
  (void) kDither;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DONT_CARE)
  (void) kDontCare;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DOUBLE)
  (void) kDouble;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
  (void) kDrawFramebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER)
  (void) kDrawIndirectBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_ALPHA)
  (void) kDstAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_COLOR)
  (void) kDstColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_COPY)
  (void) kDynamicCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_DRAW)
  (void) kDynamicDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_READ)
  (void) kDynamicRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BARRIER_BIT)
  (void) kElementArrayBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
  (void) kElementArrayBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
  (void) kEqual;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
  (void) kEquiv;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FASTEST)
  (void) kFastest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
  (void) kFill;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
  (void) kFirstVertexConvention;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIXED)
  (void) kFixed;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT)
  (void) kFloat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
  (void) kFloat32UnsignedInt248Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
  (void) kFragmentShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
  (void) kFragmentShaderDerivativeHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
  (void) kFramebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BARRIER_BIT)
  (void) kFramebufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_COMPLETE)
  (void) kFramebufferComplete;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
  (void) kFramebufferIncompleteAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER)
  (void) kFramebufferIncompleteDrawBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
  (void) kFramebufferIncompleteLayerTargets;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
  (void) kFramebufferIncompleteMissingAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
  (void) kFramebufferIncompleteMultisample;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER)
  (void) kFramebufferIncompleteReadBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_SRGB)
  (void) kFramebufferSrgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNDEFINED)
  (void) kFramebufferUndefined;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNSUPPORTED)
  (void) kFramebufferUnsupported;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
  (void) kFront;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
  (void) kFrontAndBack;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_LEFT)
  (void) kFrontLeft;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_RIGHT)
  (void) kFrontRight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_ADD)
  (void) kFuncAdd;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_REVERSE_SUBTRACT)
  (void) kFuncReverseSubtract;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_SUBTRACT)
  (void) kFuncSubtract;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
  (void) kGeometryShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
  (void) kGequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
  (void) kGreater;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
  (void) kGreen;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
  (void) kGreenInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_HALF_FLOAT)
  (void) kHalfFloat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
  (void) kIncr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
  (void) kIncrWrap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INT)
  (void) kInt;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
  (void) kInvalidEnum;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
  (void) kInvalidFramebufferOperation;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
  (void) kInvalidOperation;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
  (void) kInvalidValue;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
  (void) kInvert;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
  (void) kKeep;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
  (void) kLastVertexConvention;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEFT)
  (void) kLeft;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
  (void) kLequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
  (void) kLess;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
  (void) kLine;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
  (void) kLinear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_LINEAR)
  (void) kLinearMipmapLinear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_NEAREST)
  (void) kLinearMipmapNearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
  (void) kLines;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
  (void) kLinesAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
  (void) kLineLoop;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH)
  (void) kLineSmooth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH_HINT)
  (void) kLineSmoothHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
  (void) kLineStrip;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
  (void) kLineStripAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
  (void) kMapCoherentBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
  (void) kMapFlushExplicitBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
  (void) kMapInvalidateBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
  (void) kMapInvalidateRangeBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
  (void) kMapPersistentBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
  (void) kMapReadBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
  (void) kMapUnsynchronizedBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
  (void) kMapWriteBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAX)
  (void) kMax;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN)
  (void) kMin;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIRRORED_REPEAT)
  (void) kMirroredRepeat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MULTISAMPLE)
  (void) kMultisample;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
  (void) kNand;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
  (void) kNearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_LINEAR)
  (void) kNearestMipmapLinear;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_NEAREST)
  (void) kNearestMipmapNearest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
  (void) kNever;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NICEST)
  (void) kNicest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
  (void) kNone;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
  (void) kNoop;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
  (void) kNor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
  (void) kNotequal;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
  (void) kNoError;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
  (void) kOne;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_ALPHA)
  (void) kOneMinusConstantAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_COLOR)
  (void) kOneMinusConstantColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_ALPHA)
  (void) kOneMinusDstAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_COLOR)
  (void) kOneMinusDstColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_ALPHA)
  (void) kOneMinusSrc1Alpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_COLOR)
  (void) kOneMinusSrc1Color;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_ALPHA)
  (void) kOneMinusSrcAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_COLOR)
  (void) kOneMinusSrcColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
  (void) kOr;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
  (void) kOrInverted;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
  (void) kOrReverse;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
  (void) kOutOfMemory;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ALIGNMENT)
  (void) kPackAlignment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_DEPTH)
  (void) kPackCompressedBlockDepth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_HEIGHT)
  (void) kPackCompressedBlockHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_SIZE)
  (void) kPackCompressedBlockSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_WIDTH)
  (void) kPackCompressedBlockWidth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_IMAGE_HEIGHT)
  (void) kPackImageHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_LSB_FIRST)
  (void) kPackLsbFirst;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ROW_LENGTH)
  (void) kPackRowLength;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_IMAGES)
  (void) kPackSkipImages;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_PIXELS)
  (void) kPackSkipPixels;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_ROWS)
  (void) kPackSkipRows;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SWAP_BYTES)
  (void) kPackSwapBytes;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
  (void) kPatches;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_BUFFER_BARRIER_BIT)
  (void) kPixelBufferBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER)
  (void) kPixelPackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER)
  (void) kPixelUnpackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
  (void) kPoint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
  (void) kPoints;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_FILL)
  (void) kPolygonOffsetFill;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_LINE)
  (void) kPolygonOffsetLine;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_POINT)
  (void) kPolygonOffsetPoint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH)
  (void) kPolygonSmooth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH_HINT)
  (void) kPolygonSmoothHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART)
  (void) kPrimitiveRestart;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART_FIXED_INDEX)
  (void) kPrimitiveRestartFixedIndex;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PROGRAM_POINT_SIZE)
  (void) kProgramPointSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R11F_G11F_B10F)
  (void) kR11FG11FB10F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16)
  (void) kR16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16F)
  (void) kR16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16I)
  (void) kR16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16UI)
  (void) kR16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16_SNORM)
  (void) kR16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32F)
  (void) kR32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32I)
  (void) kR32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32UI)
  (void) kR32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R3_G3_B2)
  (void) kR3G3B2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8)
  (void) kR8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8I)
  (void) kR8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8UI)
  (void) kR8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8_SNORM)
  (void) kR8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RASTERIZER_DISCARD)
  (void) kRasterizerDiscard;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
  (void) kReadFramebuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
  (void) kReadOnly;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
  (void) kReadWrite;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
  (void) kRed;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
  (void) kRedInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RENDERBUFFER)
  (void) kRenderbuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPEAT)
  (void) kRepeat;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
  (void) kReplace;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG)
  (void) kRg;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16)
  (void) kRg16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16F)
  (void) kRg16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16I)
  (void) kRg16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16UI)
  (void) kRg16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16_SNORM)
  (void) kRg16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32F)
  (void) kRg32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32I)
  (void) kRg32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32UI)
  (void) kRg32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8)
  (void) kRg8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8I)
  (void) kRg8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8UI)
  (void) kRg8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8_SNORM)
  (void) kRg8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
  (void) kRgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10)
  (void) kRgb10;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2)
  (void) kRgb10A2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2UI)
  (void) kRgb10A2Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB12)
  (void) kRgb12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16)
  (void) kRgb16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16F)
  (void) kRgb16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16I)
  (void) kRgb16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16UI)
  (void) kRgb16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16_SNORM)
  (void) kRgb16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32F)
  (void) kRgb32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32I)
  (void) kRgb32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32UI)
  (void) kRgb32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB4)
  (void) kRgb4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5)
  (void) kRgb5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5_A1)
  (void) kRgb5A1;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8)
  (void) kRgb8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8I)
  (void) kRgb8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8UI)
  (void) kRgb8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8_SNORM)
  (void) kRgb8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB9_E5)
  (void) kRgb9E5;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
  (void) kRgba;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA12)
  (void) kRgba12;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16)
  (void) kRgba16;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16F)
  (void) kRgba16F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16I)
  (void) kRgba16I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16UI)
  (void) kRgba16Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16_SNORM)
  (void) kRgba16Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA2)
  (void) kRgba2;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32F)
  (void) kRgba32F;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32I)
  (void) kRgba32I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32UI)
  (void) kRgba32Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA4)
  (void) kRgba4;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8)
  (void) kRgba8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8I)
  (void) kRgba8I;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8UI)
  (void) kRgba8Ui;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8_SNORM)
  (void) kRgba8Snorm;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
  (void) kRgbaInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
  (void) kRgbInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
  (void) kRgInteger;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RIGHT)
  (void) kRight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_COVERAGE)
  (void) kSampleAlphaToCoverage;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_ONE)
  (void) kSampleAlphaToOne;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_COVERAGE)
  (void) kSampleCoverage;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_MASK)
  (void) kSampleMask;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_SHADING)
  (void) kSampleShading;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_TEST)
  (void) kScissorTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
  (void) kSet;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT)
  (void) kShaderImageAccessBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BARRIER_BIT)
  (void) kShaderStorageBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
  (void) kShaderStorageBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHORT)
  (void) kShort;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_ALPHA)
  (void) kSrc1Alpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_COLOR)
  (void) kSrc1Color;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA)
  (void) kSrcAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA_SATURATE)
  (void) kSrcAlphaSaturate;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_COLOR)
  (void) kSrcColor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB)
  (void) kSrgb;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8)
  (void) kSrgb8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8_ALPHA8)
  (void) kSrgb8Alpha8;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB_ALPHA)
  (void) kSrgbAlpha;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
  (void) kStackOverflow;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
  (void) kStackUnderflow;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_COPY)
  (void) kStaticCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_DRAW)
  (void) kStaticDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_READ)
  (void) kStaticRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_ATTACHMENT)
  (void) kStencilAttachment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
  (void) kStencilBufferBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_INDEX)
  (void) kStencilIndex;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_TEST)
  (void) kStencilTest;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_COPY)
  (void) kStreamCopy;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_DRAW)
  (void) kStreamDraw;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_READ)
  (void) kStreamRead;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
  (void) kTableTooLarge;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
  (void) kTessControlShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
  (void) kTessEvaluationShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D)
  (void) kTexture1D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
  (void) kTexture1DArray;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
  (void) kTexture2D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
  (void) kTexture2DArray;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
  (void) kTexture3D;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
  (void) kTextureBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_COMPRESSION_HINT)
  (void) kTextureCompressionHint;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
  (void) kTextureCubeMap;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
  (void) kTextureCubeMapNegativeX;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
  (void) kTextureCubeMapNegativeY;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
  (void) kTextureCubeMapNegativeZ;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
  (void) kTextureCubeMapPositiveX;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
  (void) kTextureCubeMapPositiveY;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
  (void) kTextureCubeMapPositiveZ;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_SEAMLESS)
  (void) kTextureCubeMapSeamless;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_FETCH_BARRIER_BIT)
  (void) kTextureFetchBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
  (void) kTextureRectangle;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_UPDATE_BARRIER_BIT)
  (void) kTextureUpdateBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK)
  (void) kTransformFeedback;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BARRIER_BIT)
  (void) kTransformFeedbackBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
  (void) kTransformFeedbackBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
  (void) kTriangles;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
  (void) kTrianglesAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
  (void) kTriangleFan;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
  (void) kTriangleStrip;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
  (void) kTriangleStripAdjacency;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BARRIER_BIT)
  (void) kUniformBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
  (void) kUniformBuffer;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ALIGNMENT)
  (void) kUnpackAlignment;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_DEPTH)
  (void) kUnpackCompressedBlockDepth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT)
  (void) kUnpackCompressedBlockHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_SIZE)
  (void) kUnpackCompressedBlockSize;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_WIDTH)
  (void) kUnpackCompressedBlockWidth;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_IMAGE_HEIGHT)
  (void) kUnpackImageHeight;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_LSB_FIRST)
  (void) kUnpackLsbFirst;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ROW_LENGTH)
  (void) kUnpackRowLength;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_IMAGES)
  (void) kUnpackSkipImages;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_PIXELS)
  (void) kUnpackSkipPixels;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_ROWS)
  (void) kUnpackSkipRows;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SWAP_BYTES)
  (void) kUnpackSwapBytes;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE)
  (void) kUnsignedByte;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_2_3_3_REV)
  (void) kUnsignedByte233Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_3_3_2)
  (void) kUnsignedByte332;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT)
  (void) kUnsignedInt;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10F_11F_11F_REV)
  (void) kUnsignedInt10F11F11FRev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10_10_10_2)
  (void) kUnsignedInt1010102;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_24_8)
  (void) kUnsignedInt248;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_2_10_10_10_REV)
  (void) kUnsignedInt2101010Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_5_9_9_9_REV)
  (void) kUnsignedInt5999Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8)
  (void) kUnsignedInt8888;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8_REV)
  (void) kUnsignedInt8888Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT)
  (void) kUnsignedShort;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_1_5_5_5_REV)
  (void) kUnsignedShort1555Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4)
  (void) kUnsignedShort4444;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4_REV)
  (void) kUnsignedShort4444Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_5_5_1)
  (void) kUnsignedShort5551;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5)
  (void) kUnsignedShort565;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5_REV)
  (void) kUnsignedShort565Rev;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ARRAY)
  (void) kVertexArray;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT)
  (void) kVertexAttribArrayBarrierBit;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
  (void) kVertexShader;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
  (void) kWriteOnly;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
  (void) kXor;
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  (void) kZero;
#endif
}

} // namespace enums
using namespace enums;
} // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif
