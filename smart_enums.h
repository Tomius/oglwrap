// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_SMART_ENUMS_H_
#define OGLWRAP_SMART_ENUMS_H_

#include "./config.h"
#include "./enums/framebuffer_target.h"
#include "./enums/buffer_target.h"
#include "./enums/pixel_data_internal_format.h"
#include "./enums/capability.h"
#include "./enums/pixel_storage_mode.h"
#include "./enums/buffer_binding.h"
#include "./enums/data_type.h"
#include "./enums/blend_function.h"
#include "./enums/framebuffer_status.h"
#include "./enums/min_filter.h"
#include "./enums/pixel_data_type.h"
#include "./enums/indexed_buffer_target.h"
#include "./enums/color_buffer.h"
#include "./enums/buffer_map_access_bit.h"
#include "./enums/color_logic_operation.h"
#include "./enums/vertex_array_target.h"
#include "./enums/transform_feedback_target.h"
#include "./enums/basic_primitive_type.h"
#include "./enums/indexed_buffer_binding.h"
#include "./enums/primitive_type.h"
#include "./enums/vertex_array_binding.h"
#include "./enums/whole_data_type.h"
#include "./enums/blit_filter.h"
#include "./enums/texture2D_target.h"
#include "./enums/buffer_map_access.h"
#include "./enums/compare_func.h"
#include "./enums/texture_binding.h"
#include "./enums/swizzle_mode.h"
#include "./enums/wrap_mode.h"
#include "./enums/buffer_usage.h"
#include "./enums/hint_target.h"
#include "./enums/face_orientation.h"
#include "./enums/hint_option.h"
#include "./enums/renderbuffer_binding.h"
#include "./enums/memory_barrier_bit.h"
#include "./enums/compare_mode.h"
#include "./enums/error_type.h"
#include "./enums/stencil_operation.h"
#include "./enums/face.h"
#include "./enums/blend_equation.h"
#include "./enums/framebuffer_binding.h"
#include "./enums/buffer_select_bit.h"
#include "./enums/renderbuffer_target.h"
#include "./enums/transform_feedback_binding.h"
#include "./enums/poly_mode.h"
#include "./enums/shader_type.h"
#include "./enums/texture3D_target.h"
#include "./enums/index_type.h"
#include "./enums/mag_filter.h"
#include "./enums/texture_cube_target.h"
#include "./enums/framebuffer_attachment.h"
#include "./enums/texture_target.h"
#include "./enums/provoke_mode.h"
#include "./enums/pixel_data_format.h"
#include "./enums/buffer_storage_bit.h"
#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {
namespace smart_enums {

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALPHA)
struct AlphaEnum {
#if __has_feature(cxx_constexpr)
  constexpr AlphaEnum() { }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_ALPHA); }
#else
  operator SwizzleMode() const { return SwizzleMode(GL_ALPHA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
struct AlwaysEnum {
#if __has_feature(cxx_constexpr)
  constexpr AlwaysEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_ALWAYS); }
#else
  operator CompareFunc() const { return CompareFunc(GL_ALWAYS); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
struct AndEnum {
#if __has_feature(cxx_constexpr)
  constexpr AndEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
struct AndInvertedEnum {
#if __has_feature(cxx_constexpr)
  constexpr AndInvertedEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND_INVERTED); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND_INVERTED); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
struct AndReverseEnum {
#if __has_feature(cxx_constexpr)
  constexpr AndReverseEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND_REVERSE); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_AND_REVERSE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
struct ArrayBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr ArrayBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_ARRAY_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_ARRAY_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BARRIER_BIT)
struct AtomicCounterBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr AtomicCounterBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_ATOMIC_COUNTER_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_ATOMIC_COUNTER_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
struct AtomicCounterBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr AtomicCounterBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_ATOMIC_COUNTER_BUFFER); }
  constexpr operator IndexedBufferTarget() const { return IndexedBufferTarget(GL_ATOMIC_COUNTER_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_ATOMIC_COUNTER_BUFFER); }
  operator IndexedBufferTarget() const { return IndexedBufferTarget(GL_ATOMIC_COUNTER_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
struct BackEnum {
#if __has_feature(cxx_constexpr)
  constexpr BackEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_BACK); }
  constexpr operator Face() const { return Face(GL_BACK); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_BACK); }
  operator Face() const { return Face(GL_BACK); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_LEFT)
struct BackLeftEnum {
#if __has_feature(cxx_constexpr)
  constexpr BackLeftEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_BACK_LEFT); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_BACK_LEFT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_RIGHT)
struct BackRightEnum {
#if __has_feature(cxx_constexpr)
  constexpr BackRightEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_BACK_RIGHT); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_BACK_RIGHT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
struct BgrEnum {
#if __has_feature(cxx_constexpr)
  constexpr BgrEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGR); }
#else
  operator PixelDataFormat() const { return PixelDataFormat(GL_BGR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
struct BgraEnum {
#if __has_feature(cxx_constexpr)
  constexpr BgraEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGRA); }
#else
  operator PixelDataFormat() const { return PixelDataFormat(GL_BGRA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
struct BgraIntegerEnum {
#if __has_feature(cxx_constexpr)
  constexpr BgraIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGRA_INTEGER); }
#else
  operator PixelDataFormat() const { return PixelDataFormat(GL_BGRA_INTEGER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
struct BgrIntegerEnum {
#if __has_feature(cxx_constexpr)
  constexpr BgrIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BGR_INTEGER); }
#else
  operator PixelDataFormat() const { return PixelDataFormat(GL_BGR_INTEGER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLEND)
struct BlendEnum {
#if __has_feature(cxx_constexpr)
  constexpr BlendEnum() { }
  constexpr operator Capability() const { return Capability(GL_BLEND); }
#else
  operator Capability() const { return Capability(GL_BLEND); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
struct BlueEnum {
#if __has_feature(cxx_constexpr)
  constexpr BlueEnum() { }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_BLUE); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BLUE); }
#else
  operator SwizzleMode() const { return SwizzleMode(GL_BLUE); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_BLUE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
struct BlueIntegerEnum {
#if __has_feature(cxx_constexpr)
  constexpr BlueIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_BLUE_INTEGER); }
#else
  operator PixelDataFormat() const { return PixelDataFormat(GL_BLUE_INTEGER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BUFFER_UPDATE_BARRIER_BIT)
struct BufferUpdateBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr BufferUpdateBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_BUFFER_UPDATE_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_BUFFER_UPDATE_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BYTE)
struct ByteEnum {
#if __has_feature(cxx_constexpr)
  constexpr ByteEnum() { }
  constexpr operator DataType() const { return DataType(GL_BYTE); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_BYTE); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_BYTE); }
#else
  operator DataType() const { return DataType(GL_BYTE); }
  operator PixelDataType() const { return PixelDataType(GL_BYTE); }
  operator WholeDataType() const { return WholeDataType(GL_BYTE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
struct CcwEnum {
#if __has_feature(cxx_constexpr)
  constexpr CcwEnum() { }
  constexpr operator FaceOrientation() const { return FaceOrientation(GL_CCW); }
#else
  operator FaceOrientation() const { return FaceOrientation(GL_CCW); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_BORDER)
struct ClampToBorderEnum {
#if __has_feature(cxx_constexpr)
  constexpr ClampToBorderEnum() { }
  constexpr operator WrapMode() const { return WrapMode(GL_CLAMP_TO_BORDER); }
#else
  operator WrapMode() const { return WrapMode(GL_CLAMP_TO_BORDER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_EDGE)
struct ClampToEdgeEnum {
#if __has_feature(cxx_constexpr)
  constexpr ClampToEdgeEnum() { }
  constexpr operator WrapMode() const { return WrapMode(GL_CLAMP_TO_EDGE); }
#else
  operator WrapMode() const { return WrapMode(GL_CLAMP_TO_EDGE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
struct ClearEnum {
#if __has_feature(cxx_constexpr)
  constexpr ClearEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_CLEAR); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_CLEAR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT)
struct ClientMappedBufferBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr ClientMappedBufferBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_STORAGE_BIT)
struct ClientStorageBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr ClientStorageBitEnum() { }
  constexpr operator BufferStorageBit() const { return BufferStorageBit(GL_CLIENT_STORAGE_BIT); }
#else
  operator BufferStorageBit() const { return BufferStorageBit(GL_CLIENT_STORAGE_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIP_DISTANCE)
struct ClipDistanceEnum {
#if __has_feature(cxx_constexpr)
  constexpr ClipDistanceEnum() { }
  constexpr operator Capability() const { return Capability(GL_CLIP_DISTANCE); }
#else
  operator Capability() const { return Capability(GL_CLIP_DISTANCE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT0)
struct ColorAttachment0Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment0Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT0); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT0); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT0); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT0); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT1)
struct ColorAttachment1Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment1Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT1); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT1); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT1); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT1); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT10)
struct ColorAttachment10Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment10Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT10); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT10); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT10); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT10); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT11)
struct ColorAttachment11Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment11Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT11); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT11); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT11); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT11); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT12)
struct ColorAttachment12Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment12Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT12); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT12); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT12); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT12); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT13)
struct ColorAttachment13Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment13Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT13); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT13); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT13); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT13); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT14)
struct ColorAttachment14Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment14Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT14); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT14); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT14); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT14); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT15)
struct ColorAttachment15Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment15Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT15); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT15); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT15); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT15); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT2)
struct ColorAttachment2Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment2Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT2); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT2); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT2); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT2); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT3)
struct ColorAttachment3Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment3Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT3); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT3); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT3); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT3); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT4)
struct ColorAttachment4Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment4Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT4); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT4); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT4); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT4); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT5)
struct ColorAttachment5Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment5Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT5); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT5); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT5); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT5); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT6)
struct ColorAttachment6Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment6Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT6); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT6); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT6); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT6); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT7)
struct ColorAttachment7Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment7Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT7); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT7); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT7); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT7); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT8)
struct ColorAttachment8Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment8Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT8); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT8); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT8); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT8); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT9)
struct ColorAttachment9Enum {
#if __has_feature(cxx_constexpr)
  constexpr ColorAttachment9Enum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT9); }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT9); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_COLOR_ATTACHMENT9); }
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_COLOR_ATTACHMENT9); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
struct ColorBufferBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr ColorBufferBitEnum() { }
  constexpr operator BufferSelectBit() const { return BufferSelectBit(GL_COLOR_BUFFER_BIT); }
#else
  operator BufferSelectBit() const { return BufferSelectBit(GL_COLOR_BUFFER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_LOGIC_OP)
struct ColorLogicOpEnum {
#if __has_feature(cxx_constexpr)
  constexpr ColorLogicOpEnum() { }
  constexpr operator Capability() const { return Capability(GL_COLOR_LOGIC_OP); }
#else
  operator Capability() const { return Capability(GL_COLOR_LOGIC_OP); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMMAND_BARRIER_BIT)
struct CommandBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr CommandBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_COMMAND_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_COMMAND_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPARE_REF_TO_TEXTURE)
struct CompareRefToTextureEnum {
#if __has_feature(cxx_constexpr)
  constexpr CompareRefToTextureEnum() { }
  constexpr operator CompareMode() const { return CompareMode(GL_COMPARE_REF_TO_TEXTURE); }
#else
  operator CompareMode() const { return CompareMode(GL_COMPARE_REF_TO_TEXTURE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED)
struct CompressedRedEnum {
#if __has_feature(cxx_constexpr)
  constexpr CompressedRedEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RED); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RED); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED_RGTC1)
struct CompressedRedRgtc1Enum {
#if __has_feature(cxx_constexpr)
  constexpr CompressedRedRgtc1Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RED_RGTC1); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RED_RGTC1); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG)
struct CompressedRgEnum {
#if __has_feature(cxx_constexpr)
  constexpr CompressedRgEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RG); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RG); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGB)
struct CompressedRgbEnum {
#if __has_feature(cxx_constexpr)
  constexpr CompressedRgbEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RGB); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RGB); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGBA)
struct CompressedRgbaEnum {
#if __has_feature(cxx_constexpr)
  constexpr CompressedRgbaEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RGBA); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RGBA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG_RGTC2)
struct CompressedRgRgtc2Enum {
#if __has_feature(cxx_constexpr)
  constexpr CompressedRgRgtc2Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RG_RGTC2); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_RG_RGTC2); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RED_RGTC1)
struct CompressedSignedRedRgtc1Enum {
#if __has_feature(cxx_constexpr)
  constexpr CompressedSignedRedRgtc1Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SIGNED_RED_RGTC1); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SIGNED_RED_RGTC1); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RG_RGTC2)
struct CompressedSignedRgRgtc2Enum {
#if __has_feature(cxx_constexpr)
  constexpr CompressedSignedRgRgtc2Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SIGNED_RG_RGTC2); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SIGNED_RG_RGTC2); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB)
struct CompressedSrgbEnum {
#if __has_feature(cxx_constexpr)
  constexpr CompressedSrgbEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SRGB); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SRGB); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB_ALPHA)
struct CompressedSrgbAlphaEnum {
#if __has_feature(cxx_constexpr)
  constexpr CompressedSrgbAlphaEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SRGB_ALPHA); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_COMPRESSED_SRGB_ALPHA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
struct ComputeShaderEnum {
#if __has_feature(cxx_constexpr)
  constexpr ComputeShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_COMPUTE_SHADER); }
#else
  operator ShaderType() const { return ShaderType(GL_COMPUTE_SHADER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_ALPHA)
struct ConstantAlphaEnum {
#if __has_feature(cxx_constexpr)
  constexpr ConstantAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_CONSTANT_ALPHA); }
#else
  operator BlendFunction() const { return BlendFunction(GL_CONSTANT_ALPHA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_COLOR)
struct ConstantColorEnum {
#if __has_feature(cxx_constexpr)
  constexpr ConstantColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_CONSTANT_COLOR); }
#else
  operator BlendFunction() const { return BlendFunction(GL_CONSTANT_COLOR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
struct CopyEnum {
#if __has_feature(cxx_constexpr)
  constexpr CopyEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_COPY); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_COPY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
struct CopyInvertedEnum {
#if __has_feature(cxx_constexpr)
  constexpr CopyInvertedEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_COPY_INVERTED); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_COPY_INVERTED); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
struct CopyReadBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr CopyReadBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_COPY_READ_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_COPY_READ_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
struct CopyWriteBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr CopyWriteBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_COPY_WRITE_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_COPY_WRITE_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CULL_FACE)
struct CullFaceEnum {
#if __has_feature(cxx_constexpr)
  constexpr CullFaceEnum() { }
  constexpr operator Capability() const { return Capability(GL_CULL_FACE); }
#else
  operator Capability() const { return Capability(GL_CULL_FACE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
struct CwEnum {
#if __has_feature(cxx_constexpr)
  constexpr CwEnum() { }
  constexpr operator FaceOrientation() const { return FaceOrientation(GL_CW); }
#else
  operator FaceOrientation() const { return FaceOrientation(GL_CW); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT)
struct DebugOutputEnum {
#if __has_feature(cxx_constexpr)
  constexpr DebugOutputEnum() { }
  constexpr operator Capability() const { return Capability(GL_DEBUG_OUTPUT); }
#else
  operator Capability() const { return Capability(GL_DEBUG_OUTPUT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT_SYNCHRONOUS)
struct DebugOutputSynchronousEnum {
#if __has_feature(cxx_constexpr)
  constexpr DebugOutputSynchronousEnum() { }
  constexpr operator Capability() const { return Capability(GL_DEBUG_OUTPUT_SYNCHRONOUS); }
#else
  operator Capability() const { return Capability(GL_DEBUG_OUTPUT_SYNCHRONOUS); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
struct DecrEnum {
#if __has_feature(cxx_constexpr)
  constexpr DecrEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_DECR); }
#else
  operator StencilOperation() const { return StencilOperation(GL_DECR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
struct DecrWrapEnum {
#if __has_feature(cxx_constexpr)
  constexpr DecrWrapEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_DECR_WRAP); }
#else
  operator StencilOperation() const { return StencilOperation(GL_DECR_WRAP); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_ATTACHMENT)
struct DepthAttachmentEnum {
#if __has_feature(cxx_constexpr)
  constexpr DepthAttachmentEnum() { }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_DEPTH_ATTACHMENT); }
#else
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_DEPTH_ATTACHMENT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
struct DepthBufferBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr DepthBufferBitEnum() { }
  constexpr operator BufferSelectBit() const { return BufferSelectBit(GL_DEPTH_BUFFER_BIT); }
#else
  operator BufferSelectBit() const { return BufferSelectBit(GL_DEPTH_BUFFER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_CLAMP)
struct DepthClampEnum {
#if __has_feature(cxx_constexpr)
  constexpr DepthClampEnum() { }
  constexpr operator Capability() const { return Capability(GL_DEPTH_CLAMP); }
#else
  operator Capability() const { return Capability(GL_DEPTH_CLAMP); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_COMPONENT)
struct DepthComponentEnum {
#if __has_feature(cxx_constexpr)
  constexpr DepthComponentEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_DEPTH_COMPONENT); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_DEPTH_COMPONENT); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_DEPTH_COMPONENT); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_DEPTH_COMPONENT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL)
struct DepthStencilEnum {
#if __has_feature(cxx_constexpr)
  constexpr DepthStencilEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_DEPTH_STENCIL); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_DEPTH_STENCIL); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_DEPTH_STENCIL); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_DEPTH_STENCIL); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL_ATTACHMENT)
struct DepthStencilAttachmentEnum {
#if __has_feature(cxx_constexpr)
  constexpr DepthStencilAttachmentEnum() { }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_DEPTH_STENCIL_ATTACHMENT); }
#else
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_DEPTH_STENCIL_ATTACHMENT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_TEST)
struct DepthTestEnum {
#if __has_feature(cxx_constexpr)
  constexpr DepthTestEnum() { }
  constexpr operator Capability() const { return Capability(GL_DEPTH_TEST); }
#else
  operator Capability() const { return Capability(GL_DEPTH_TEST); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER)
struct DispatchIndirectBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr DispatchIndirectBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_DISPATCH_INDIRECT_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_DISPATCH_INDIRECT_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DITHER)
struct DitherEnum {
#if __has_feature(cxx_constexpr)
  constexpr DitherEnum() { }
  constexpr operator Capability() const { return Capability(GL_DITHER); }
#else
  operator Capability() const { return Capability(GL_DITHER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DONT_CARE)
struct DontCareEnum {
#if __has_feature(cxx_constexpr)
  constexpr DontCareEnum() { }
  constexpr operator HintOption() const { return HintOption(GL_DONT_CARE); }
#else
  operator HintOption() const { return HintOption(GL_DONT_CARE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DOUBLE)
struct DoubleEnum {
#if __has_feature(cxx_constexpr)
  constexpr DoubleEnum() { }
  constexpr operator DataType() const { return DataType(GL_DOUBLE); }
#else
  operator DataType() const { return DataType(GL_DOUBLE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
struct DrawFramebufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr DrawFramebufferEnum() { }
  constexpr operator FramebufferTarget() const { return FramebufferTarget(GL_DRAW_FRAMEBUFFER); }
#else
  operator FramebufferTarget() const { return FramebufferTarget(GL_DRAW_FRAMEBUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER)
struct DrawIndirectBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr DrawIndirectBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_DRAW_INDIRECT_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_DRAW_INDIRECT_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_ALPHA)
struct DstAlphaEnum {
#if __has_feature(cxx_constexpr)
  constexpr DstAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_DST_ALPHA); }
#else
  operator BlendFunction() const { return BlendFunction(GL_DST_ALPHA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_COLOR)
struct DstColorEnum {
#if __has_feature(cxx_constexpr)
  constexpr DstColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_DST_COLOR); }
#else
  operator BlendFunction() const { return BlendFunction(GL_DST_COLOR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_COPY)
struct DynamicCopyEnum {
#if __has_feature(cxx_constexpr)
  constexpr DynamicCopyEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_COPY); }
#else
  operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_COPY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_DRAW)
struct DynamicDrawEnum {
#if __has_feature(cxx_constexpr)
  constexpr DynamicDrawEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_DRAW); }
#else
  operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_DRAW); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_READ)
struct DynamicReadEnum {
#if __has_feature(cxx_constexpr)
  constexpr DynamicReadEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_READ); }
#else
  operator BufferUsage() const { return BufferUsage(GL_DYNAMIC_READ); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_STORAGE_BIT)
struct DynamicStorageBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr DynamicStorageBitEnum() { }
  constexpr operator BufferStorageBit() const { return BufferStorageBit(GL_DYNAMIC_STORAGE_BIT); }
#else
  operator BufferStorageBit() const { return BufferStorageBit(GL_DYNAMIC_STORAGE_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BARRIER_BIT)
struct ElementArrayBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr ElementArrayBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_ELEMENT_ARRAY_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_ELEMENT_ARRAY_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
struct ElementArrayBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr ElementArrayBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_ELEMENT_ARRAY_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_ELEMENT_ARRAY_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
struct EqualEnum {
#if __has_feature(cxx_constexpr)
  constexpr EqualEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_EQUAL); }
#else
  operator CompareFunc() const { return CompareFunc(GL_EQUAL); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
struct EquivEnum {
#if __has_feature(cxx_constexpr)
  constexpr EquivEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_EQUIV); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_EQUIV); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FASTEST)
struct FastestEnum {
#if __has_feature(cxx_constexpr)
  constexpr FastestEnum() { }
  constexpr operator HintOption() const { return HintOption(GL_FASTEST); }
#else
  operator HintOption() const { return HintOption(GL_FASTEST); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
struct FillEnum {
#if __has_feature(cxx_constexpr)
  constexpr FillEnum() { }
  constexpr operator PolyMode() const { return PolyMode(GL_FILL); }
#else
  operator PolyMode() const { return PolyMode(GL_FILL); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
struct FirstVertexConventionEnum {
#if __has_feature(cxx_constexpr)
  constexpr FirstVertexConventionEnum() { }
  constexpr operator ProvokeMode() const { return ProvokeMode(GL_FIRST_VERTEX_CONVENTION); }
#else
  operator ProvokeMode() const { return ProvokeMode(GL_FIRST_VERTEX_CONVENTION); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIXED)
struct FixedEnum {
#if __has_feature(cxx_constexpr)
  constexpr FixedEnum() { }
  constexpr operator DataType() const { return DataType(GL_FIXED); }
#else
  operator DataType() const { return DataType(GL_FIXED); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT)
struct FloatEnum {
#if __has_feature(cxx_constexpr)
  constexpr FloatEnum() { }
  constexpr operator DataType() const { return DataType(GL_FLOAT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_FLOAT); }
#else
  operator DataType() const { return DataType(GL_FLOAT); }
  operator PixelDataType() const { return PixelDataType(GL_FLOAT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
struct Float32UnsignedInt248RevEnum {
#if __has_feature(cxx_constexpr)
  constexpr Float32UnsignedInt248RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_FLOAT_32_UNSIGNED_INT_24_8_REV); }
#else
  operator PixelDataType() const { return PixelDataType(GL_FLOAT_32_UNSIGNED_INT_24_8_REV); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
struct FragmentShaderEnum {
#if __has_feature(cxx_constexpr)
  constexpr FragmentShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_FRAGMENT_SHADER); }
#else
  operator ShaderType() const { return ShaderType(GL_FRAGMENT_SHADER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
struct FragmentShaderDerivativeHintEnum {
#if __has_feature(cxx_constexpr)
  constexpr FragmentShaderDerivativeHintEnum() { }
  constexpr operator HintTarget() const { return HintTarget(GL_FRAGMENT_SHADER_DERIVATIVE_HINT); }
#else
  operator HintTarget() const { return HintTarget(GL_FRAGMENT_SHADER_DERIVATIVE_HINT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
struct FramebufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferEnum() { }
  constexpr operator FramebufferTarget() const { return FramebufferTarget(GL_FRAMEBUFFER); }
#else
  operator FramebufferTarget() const { return FramebufferTarget(GL_FRAMEBUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BARRIER_BIT)
struct FramebufferBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_FRAMEBUFFER_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_FRAMEBUFFER_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_COMPLETE)
struct FramebufferCompleteEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferCompleteEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_COMPLETE); }
#else
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_COMPLETE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
struct FramebufferIncompleteAttachmentEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferIncompleteAttachmentEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT); }
#else
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER)
struct FramebufferIncompleteDrawBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferIncompleteDrawBufferEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER); }
#else
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
struct FramebufferIncompleteLayerTargetsEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferIncompleteLayerTargetsEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS); }
#else
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
struct FramebufferIncompleteMissingAttachmentEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferIncompleteMissingAttachmentEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT); }
#else
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
struct FramebufferIncompleteMultisampleEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferIncompleteMultisampleEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE); }
#else
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER)
struct FramebufferIncompleteReadBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferIncompleteReadBufferEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER); }
#else
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_SRGB)
struct FramebufferSrgbEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferSrgbEnum() { }
  constexpr operator Capability() const { return Capability(GL_FRAMEBUFFER_SRGB); }
#else
  operator Capability() const { return Capability(GL_FRAMEBUFFER_SRGB); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNDEFINED)
struct FramebufferUndefinedEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferUndefinedEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_UNDEFINED); }
#else
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_UNDEFINED); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNSUPPORTED)
struct FramebufferUnsupportedEnum {
#if __has_feature(cxx_constexpr)
  constexpr FramebufferUnsupportedEnum() { }
  constexpr operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_UNSUPPORTED); }
#else
  operator FramebufferStatus() const { return FramebufferStatus(GL_FRAMEBUFFER_UNSUPPORTED); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
struct FrontEnum {
#if __has_feature(cxx_constexpr)
  constexpr FrontEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT); }
  constexpr operator Face() const { return Face(GL_FRONT); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_FRONT); }
  operator Face() const { return Face(GL_FRONT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
struct FrontAndBackEnum {
#if __has_feature(cxx_constexpr)
  constexpr FrontAndBackEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT_AND_BACK); }
  constexpr operator Face() const { return Face(GL_FRONT_AND_BACK); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_FRONT_AND_BACK); }
  operator Face() const { return Face(GL_FRONT_AND_BACK); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_LEFT)
struct FrontLeftEnum {
#if __has_feature(cxx_constexpr)
  constexpr FrontLeftEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT_LEFT); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_FRONT_LEFT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_RIGHT)
struct FrontRightEnum {
#if __has_feature(cxx_constexpr)
  constexpr FrontRightEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_FRONT_RIGHT); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_FRONT_RIGHT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_ADD)
struct FuncAddEnum {
#if __has_feature(cxx_constexpr)
  constexpr FuncAddEnum() { }
  constexpr operator BlendEquation() const { return BlendEquation(GL_FUNC_ADD); }
#else
  operator BlendEquation() const { return BlendEquation(GL_FUNC_ADD); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_REVERSE_SUBTRACT)
struct FuncReverseSubtractEnum {
#if __has_feature(cxx_constexpr)
  constexpr FuncReverseSubtractEnum() { }
  constexpr operator BlendEquation() const { return BlendEquation(GL_FUNC_REVERSE_SUBTRACT); }
#else
  operator BlendEquation() const { return BlendEquation(GL_FUNC_REVERSE_SUBTRACT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_SUBTRACT)
struct FuncSubtractEnum {
#if __has_feature(cxx_constexpr)
  constexpr FuncSubtractEnum() { }
  constexpr operator BlendEquation() const { return BlendEquation(GL_FUNC_SUBTRACT); }
#else
  operator BlendEquation() const { return BlendEquation(GL_FUNC_SUBTRACT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
struct GeometryShaderEnum {
#if __has_feature(cxx_constexpr)
  constexpr GeometryShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_GEOMETRY_SHADER); }
#else
  operator ShaderType() const { return ShaderType(GL_GEOMETRY_SHADER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
struct GequalEnum {
#if __has_feature(cxx_constexpr)
  constexpr GequalEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_GEQUAL); }
#else
  operator CompareFunc() const { return CompareFunc(GL_GEQUAL); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
struct GreaterEnum {
#if __has_feature(cxx_constexpr)
  constexpr GreaterEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_GREATER); }
#else
  operator CompareFunc() const { return CompareFunc(GL_GREATER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
struct GreenEnum {
#if __has_feature(cxx_constexpr)
  constexpr GreenEnum() { }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_GREEN); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_GREEN); }
#else
  operator SwizzleMode() const { return SwizzleMode(GL_GREEN); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_GREEN); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
struct GreenIntegerEnum {
#if __has_feature(cxx_constexpr)
  constexpr GreenIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_GREEN_INTEGER); }
#else
  operator PixelDataFormat() const { return PixelDataFormat(GL_GREEN_INTEGER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_HALF_FLOAT)
struct HalfFloatEnum {
#if __has_feature(cxx_constexpr)
  constexpr HalfFloatEnum() { }
  constexpr operator DataType() const { return DataType(GL_HALF_FLOAT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_HALF_FLOAT); }
#else
  operator DataType() const { return DataType(GL_HALF_FLOAT); }
  operator PixelDataType() const { return PixelDataType(GL_HALF_FLOAT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
struct IncrEnum {
#if __has_feature(cxx_constexpr)
  constexpr IncrEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_INCR); }
#else
  operator StencilOperation() const { return StencilOperation(GL_INCR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
struct IncrWrapEnum {
#if __has_feature(cxx_constexpr)
  constexpr IncrWrapEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_INCR_WRAP); }
#else
  operator StencilOperation() const { return StencilOperation(GL_INCR_WRAP); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INT)
struct IntEnum {
#if __has_feature(cxx_constexpr)
  constexpr IntEnum() { }
  constexpr operator DataType() const { return DataType(GL_INT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_INT); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_INT); }
#else
  operator DataType() const { return DataType(GL_INT); }
  operator PixelDataType() const { return PixelDataType(GL_INT); }
  operator WholeDataType() const { return WholeDataType(GL_INT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
struct InvalidEnumEnum {
#if __has_feature(cxx_constexpr)
  constexpr InvalidEnumEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_INVALID_ENUM); }
#else
  operator ErrorType() const { return ErrorType(GL_INVALID_ENUM); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
struct InvalidFramebufferOperationEnum {
#if __has_feature(cxx_constexpr)
  constexpr InvalidFramebufferOperationEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_INVALID_FRAMEBUFFER_OPERATION); }
#else
  operator ErrorType() const { return ErrorType(GL_INVALID_FRAMEBUFFER_OPERATION); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
struct InvalidOperationEnum {
#if __has_feature(cxx_constexpr)
  constexpr InvalidOperationEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_INVALID_OPERATION); }
#else
  operator ErrorType() const { return ErrorType(GL_INVALID_OPERATION); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
struct InvalidValueEnum {
#if __has_feature(cxx_constexpr)
  constexpr InvalidValueEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_INVALID_VALUE); }
#else
  operator ErrorType() const { return ErrorType(GL_INVALID_VALUE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
struct InvertEnum {
#if __has_feature(cxx_constexpr)
  constexpr InvertEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_INVERT); }
  constexpr operator StencilOperation() const { return StencilOperation(GL_INVERT); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_INVERT); }
  operator StencilOperation() const { return StencilOperation(GL_INVERT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
struct KeepEnum {
#if __has_feature(cxx_constexpr)
  constexpr KeepEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_KEEP); }
#else
  operator StencilOperation() const { return StencilOperation(GL_KEEP); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
struct LastVertexConventionEnum {
#if __has_feature(cxx_constexpr)
  constexpr LastVertexConventionEnum() { }
  constexpr operator ProvokeMode() const { return ProvokeMode(GL_LAST_VERTEX_CONVENTION); }
#else
  operator ProvokeMode() const { return ProvokeMode(GL_LAST_VERTEX_CONVENTION); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEFT)
struct LeftEnum {
#if __has_feature(cxx_constexpr)
  constexpr LeftEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_LEFT); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_LEFT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
struct LequalEnum {
#if __has_feature(cxx_constexpr)
  constexpr LequalEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_LEQUAL); }
#else
  operator CompareFunc() const { return CompareFunc(GL_LEQUAL); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
struct LessEnum {
#if __has_feature(cxx_constexpr)
  constexpr LessEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_LESS); }
#else
  operator CompareFunc() const { return CompareFunc(GL_LESS); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
struct LineEnum {
#if __has_feature(cxx_constexpr)
  constexpr LineEnum() { }
  constexpr operator PolyMode() const { return PolyMode(GL_LINE); }
#else
  operator PolyMode() const { return PolyMode(GL_LINE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
struct LinearEnum {
#if __has_feature(cxx_constexpr)
  constexpr LinearEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_LINEAR); }
  constexpr operator BlitFilter() const { return BlitFilter(GL_LINEAR); }
  constexpr operator MagFilter() const { return MagFilter(GL_LINEAR); }
#else
  operator MinFilter() const { return MinFilter(GL_LINEAR); }
  operator BlitFilter() const { return BlitFilter(GL_LINEAR); }
  operator MagFilter() const { return MagFilter(GL_LINEAR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_LINEAR)
struct LinearMipmapLinearEnum {
#if __has_feature(cxx_constexpr)
  constexpr LinearMipmapLinearEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_LINEAR_MIPMAP_LINEAR); }
#else
  operator MinFilter() const { return MinFilter(GL_LINEAR_MIPMAP_LINEAR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_NEAREST)
struct LinearMipmapNearestEnum {
#if __has_feature(cxx_constexpr)
  constexpr LinearMipmapNearestEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_LINEAR_MIPMAP_NEAREST); }
#else
  operator MinFilter() const { return MinFilter(GL_LINEAR_MIPMAP_NEAREST); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
struct LinesEnum {
#if __has_feature(cxx_constexpr)
  constexpr LinesEnum() { }
  constexpr operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_LINES); }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINES); }
#else
  operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_LINES); }
  operator PrimitiveType() const { return PrimitiveType(GL_LINES); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
struct LinesAdjacencyEnum {
#if __has_feature(cxx_constexpr)
  constexpr LinesAdjacencyEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINES_ADJACENCY); }
#else
  operator PrimitiveType() const { return PrimitiveType(GL_LINES_ADJACENCY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
struct LineLoopEnum {
#if __has_feature(cxx_constexpr)
  constexpr LineLoopEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINE_LOOP); }
#else
  operator PrimitiveType() const { return PrimitiveType(GL_LINE_LOOP); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH)
struct LineSmoothEnum {
#if __has_feature(cxx_constexpr)
  constexpr LineSmoothEnum() { }
  constexpr operator Capability() const { return Capability(GL_LINE_SMOOTH); }
#else
  operator Capability() const { return Capability(GL_LINE_SMOOTH); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH_HINT)
struct LineSmoothHintEnum {
#if __has_feature(cxx_constexpr)
  constexpr LineSmoothHintEnum() { }
  constexpr operator HintTarget() const { return HintTarget(GL_LINE_SMOOTH_HINT); }
#else
  operator HintTarget() const { return HintTarget(GL_LINE_SMOOTH_HINT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
struct LineStripEnum {
#if __has_feature(cxx_constexpr)
  constexpr LineStripEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINE_STRIP); }
#else
  operator PrimitiveType() const { return PrimitiveType(GL_LINE_STRIP); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
struct LineStripAdjacencyEnum {
#if __has_feature(cxx_constexpr)
  constexpr LineStripAdjacencyEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_LINE_STRIP_ADJACENCY); }
#else
  operator PrimitiveType() const { return PrimitiveType(GL_LINE_STRIP_ADJACENCY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
struct MapCoherentBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr MapCoherentBitEnum() { }
  constexpr operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_COHERENT_BIT); }
  constexpr operator BufferStorageBit() const { return BufferStorageBit(GL_MAP_COHERENT_BIT); }
#else
  operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_COHERENT_BIT); }
  operator BufferStorageBit() const { return BufferStorageBit(GL_MAP_COHERENT_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
struct MapFlushExplicitBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr MapFlushExplicitBitEnum() { }
  constexpr operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_FLUSH_EXPLICIT_BIT); }
#else
  operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_FLUSH_EXPLICIT_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
struct MapInvalidateBufferBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr MapInvalidateBufferBitEnum() { }
  constexpr operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_INVALIDATE_BUFFER_BIT); }
#else
  operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_INVALIDATE_BUFFER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
struct MapInvalidateRangeBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr MapInvalidateRangeBitEnum() { }
  constexpr operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_INVALIDATE_RANGE_BIT); }
#else
  operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_INVALIDATE_RANGE_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
struct MapPersistentBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr MapPersistentBitEnum() { }
  constexpr operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_PERSISTENT_BIT); }
  constexpr operator BufferStorageBit() const { return BufferStorageBit(GL_MAP_PERSISTENT_BIT); }
#else
  operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_PERSISTENT_BIT); }
  operator BufferStorageBit() const { return BufferStorageBit(GL_MAP_PERSISTENT_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
struct MapReadBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr MapReadBitEnum() { }
  constexpr operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_READ_BIT); }
  constexpr operator BufferStorageBit() const { return BufferStorageBit(GL_MAP_READ_BIT); }
#else
  operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_READ_BIT); }
  operator BufferStorageBit() const { return BufferStorageBit(GL_MAP_READ_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
struct MapUnsynchronizedBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr MapUnsynchronizedBitEnum() { }
  constexpr operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_UNSYNCHRONIZED_BIT); }
#else
  operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_UNSYNCHRONIZED_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
struct MapWriteBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr MapWriteBitEnum() { }
  constexpr operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_WRITE_BIT); }
  constexpr operator BufferStorageBit() const { return BufferStorageBit(GL_MAP_WRITE_BIT); }
#else
  operator BufferMapAccessBit() const { return BufferMapAccessBit(GL_MAP_WRITE_BIT); }
  operator BufferStorageBit() const { return BufferStorageBit(GL_MAP_WRITE_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAX)
struct MaxEnum {
#if __has_feature(cxx_constexpr)
  constexpr MaxEnum() { }
  constexpr operator BlendEquation() const { return BlendEquation(GL_MAX); }
#else
  operator BlendEquation() const { return BlendEquation(GL_MAX); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN)
struct MinEnum {
#if __has_feature(cxx_constexpr)
  constexpr MinEnum() { }
  constexpr operator BlendEquation() const { return BlendEquation(GL_MIN); }
#else
  operator BlendEquation() const { return BlendEquation(GL_MIN); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIRRORED_REPEAT)
struct MirroredRepeatEnum {
#if __has_feature(cxx_constexpr)
  constexpr MirroredRepeatEnum() { }
  constexpr operator WrapMode() const { return WrapMode(GL_MIRRORED_REPEAT); }
#else
  operator WrapMode() const { return WrapMode(GL_MIRRORED_REPEAT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MULTISAMPLE)
struct MultisampleEnum {
#if __has_feature(cxx_constexpr)
  constexpr MultisampleEnum() { }
  constexpr operator Capability() const { return Capability(GL_MULTISAMPLE); }
#else
  operator Capability() const { return Capability(GL_MULTISAMPLE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
struct NandEnum {
#if __has_feature(cxx_constexpr)
  constexpr NandEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_NAND); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_NAND); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
struct NearestEnum {
#if __has_feature(cxx_constexpr)
  constexpr NearestEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_NEAREST); }
  constexpr operator BlitFilter() const { return BlitFilter(GL_NEAREST); }
  constexpr operator MagFilter() const { return MagFilter(GL_NEAREST); }
#else
  operator MinFilter() const { return MinFilter(GL_NEAREST); }
  operator BlitFilter() const { return BlitFilter(GL_NEAREST); }
  operator MagFilter() const { return MagFilter(GL_NEAREST); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_LINEAR)
struct NearestMipmapLinearEnum {
#if __has_feature(cxx_constexpr)
  constexpr NearestMipmapLinearEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_NEAREST_MIPMAP_LINEAR); }
#else
  operator MinFilter() const { return MinFilter(GL_NEAREST_MIPMAP_LINEAR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_NEAREST)
struct NearestMipmapNearestEnum {
#if __has_feature(cxx_constexpr)
  constexpr NearestMipmapNearestEnum() { }
  constexpr operator MinFilter() const { return MinFilter(GL_NEAREST_MIPMAP_NEAREST); }
#else
  operator MinFilter() const { return MinFilter(GL_NEAREST_MIPMAP_NEAREST); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
struct NeverEnum {
#if __has_feature(cxx_constexpr)
  constexpr NeverEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_NEVER); }
#else
  operator CompareFunc() const { return CompareFunc(GL_NEVER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NICEST)
struct NicestEnum {
#if __has_feature(cxx_constexpr)
  constexpr NicestEnum() { }
  constexpr operator HintOption() const { return HintOption(GL_NICEST); }
#else
  operator HintOption() const { return HintOption(GL_NICEST); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
struct NoneEnum {
#if __has_feature(cxx_constexpr)
  constexpr NoneEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_NONE); }
  constexpr operator CompareMode() const { return CompareMode(GL_NONE); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_NONE); }
  operator CompareMode() const { return CompareMode(GL_NONE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
struct NoopEnum {
#if __has_feature(cxx_constexpr)
  constexpr NoopEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_NOOP); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_NOOP); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
struct NorEnum {
#if __has_feature(cxx_constexpr)
  constexpr NorEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_NOR); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_NOR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
struct NotequalEnum {
#if __has_feature(cxx_constexpr)
  constexpr NotequalEnum() { }
  constexpr operator CompareFunc() const { return CompareFunc(GL_NOTEQUAL); }
#else
  operator CompareFunc() const { return CompareFunc(GL_NOTEQUAL); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
struct NoErrorEnum {
#if __has_feature(cxx_constexpr)
  constexpr NoErrorEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_NO_ERROR); }
#else
  operator ErrorType() const { return ErrorType(GL_NO_ERROR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
struct OneEnum {
#if __has_feature(cxx_constexpr)
  constexpr OneEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE); }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_ONE); }
#else
  operator BlendFunction() const { return BlendFunction(GL_ONE); }
  operator SwizzleMode() const { return SwizzleMode(GL_ONE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_ALPHA)
struct OneMinusConstantAlphaEnum {
#if __has_feature(cxx_constexpr)
  constexpr OneMinusConstantAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_CONSTANT_ALPHA); }
#else
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_CONSTANT_ALPHA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_COLOR)
struct OneMinusConstantColorEnum {
#if __has_feature(cxx_constexpr)
  constexpr OneMinusConstantColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_CONSTANT_COLOR); }
#else
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_CONSTANT_COLOR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_ALPHA)
struct OneMinusDstAlphaEnum {
#if __has_feature(cxx_constexpr)
  constexpr OneMinusDstAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_DST_ALPHA); }
#else
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_DST_ALPHA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_COLOR)
struct OneMinusDstColorEnum {
#if __has_feature(cxx_constexpr)
  constexpr OneMinusDstColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_DST_COLOR); }
#else
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_DST_COLOR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_ALPHA)
struct OneMinusSrc1AlphaEnum {
#if __has_feature(cxx_constexpr)
  constexpr OneMinusSrc1AlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC1_ALPHA); }
#else
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC1_ALPHA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_COLOR)
struct OneMinusSrc1ColorEnum {
#if __has_feature(cxx_constexpr)
  constexpr OneMinusSrc1ColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC1_COLOR); }
#else
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC1_COLOR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_ALPHA)
struct OneMinusSrcAlphaEnum {
#if __has_feature(cxx_constexpr)
  constexpr OneMinusSrcAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC_ALPHA); }
#else
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC_ALPHA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_COLOR)
struct OneMinusSrcColorEnum {
#if __has_feature(cxx_constexpr)
  constexpr OneMinusSrcColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC_COLOR); }
#else
  operator BlendFunction() const { return BlendFunction(GL_ONE_MINUS_SRC_COLOR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
struct OrEnum {
#if __has_feature(cxx_constexpr)
  constexpr OrEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
struct OrInvertedEnum {
#if __has_feature(cxx_constexpr)
  constexpr OrInvertedEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR_INVERTED); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR_INVERTED); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
struct OrReverseEnum {
#if __has_feature(cxx_constexpr)
  constexpr OrReverseEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR_REVERSE); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_OR_REVERSE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
struct OutOfMemoryEnum {
#if __has_feature(cxx_constexpr)
  constexpr OutOfMemoryEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_OUT_OF_MEMORY); }
#else
  operator ErrorType() const { return ErrorType(GL_OUT_OF_MEMORY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ALIGNMENT)
struct PackAlignmentEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackAlignmentEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_ALIGNMENT); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_ALIGNMENT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_DEPTH)
struct PackCompressedBlockDepthEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackCompressedBlockDepthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_DEPTH); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_DEPTH); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_HEIGHT)
struct PackCompressedBlockHeightEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackCompressedBlockHeightEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_HEIGHT); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_HEIGHT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_SIZE)
struct PackCompressedBlockSizeEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackCompressedBlockSizeEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_SIZE); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_SIZE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_WIDTH)
struct PackCompressedBlockWidthEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackCompressedBlockWidthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_WIDTH); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_COMPRESSED_BLOCK_WIDTH); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_IMAGE_HEIGHT)
struct PackImageHeightEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackImageHeightEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_IMAGE_HEIGHT); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_IMAGE_HEIGHT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_LSB_FIRST)
struct PackLsbFirstEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackLsbFirstEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_LSB_FIRST); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_LSB_FIRST); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ROW_LENGTH)
struct PackRowLengthEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackRowLengthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_ROW_LENGTH); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_ROW_LENGTH); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_IMAGES)
struct PackSkipImagesEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackSkipImagesEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_IMAGES); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_IMAGES); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_PIXELS)
struct PackSkipPixelsEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackSkipPixelsEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_PIXELS); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_PIXELS); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_ROWS)
struct PackSkipRowsEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackSkipRowsEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_ROWS); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SKIP_ROWS); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SWAP_BYTES)
struct PackSwapBytesEnum {
#if __has_feature(cxx_constexpr)
  constexpr PackSwapBytesEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SWAP_BYTES); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_PACK_SWAP_BYTES); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
struct PatchesEnum {
#if __has_feature(cxx_constexpr)
  constexpr PatchesEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_PATCHES); }
#else
  operator PrimitiveType() const { return PrimitiveType(GL_PATCHES); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_BUFFER_BARRIER_BIT)
struct PixelBufferBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr PixelBufferBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_PIXEL_BUFFER_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_PIXEL_BUFFER_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER)
struct PixelPackBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr PixelPackBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_PIXEL_PACK_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_PIXEL_PACK_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER)
struct PixelUnpackBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr PixelUnpackBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_PIXEL_UNPACK_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_PIXEL_UNPACK_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
struct PointEnum {
#if __has_feature(cxx_constexpr)
  constexpr PointEnum() { }
  constexpr operator PolyMode() const { return PolyMode(GL_POINT); }
#else
  operator PolyMode() const { return PolyMode(GL_POINT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
struct PointsEnum {
#if __has_feature(cxx_constexpr)
  constexpr PointsEnum() { }
  constexpr operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_POINTS); }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_POINTS); }
#else
  operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_POINTS); }
  operator PrimitiveType() const { return PrimitiveType(GL_POINTS); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_FILL)
struct PolygonOffsetFillEnum {
#if __has_feature(cxx_constexpr)
  constexpr PolygonOffsetFillEnum() { }
  constexpr operator Capability() const { return Capability(GL_POLYGON_OFFSET_FILL); }
#else
  operator Capability() const { return Capability(GL_POLYGON_OFFSET_FILL); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_LINE)
struct PolygonOffsetLineEnum {
#if __has_feature(cxx_constexpr)
  constexpr PolygonOffsetLineEnum() { }
  constexpr operator Capability() const { return Capability(GL_POLYGON_OFFSET_LINE); }
#else
  operator Capability() const { return Capability(GL_POLYGON_OFFSET_LINE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_POINT)
struct PolygonOffsetPointEnum {
#if __has_feature(cxx_constexpr)
  constexpr PolygonOffsetPointEnum() { }
  constexpr operator Capability() const { return Capability(GL_POLYGON_OFFSET_POINT); }
#else
  operator Capability() const { return Capability(GL_POLYGON_OFFSET_POINT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH)
struct PolygonSmoothEnum {
#if __has_feature(cxx_constexpr)
  constexpr PolygonSmoothEnum() { }
  constexpr operator Capability() const { return Capability(GL_POLYGON_SMOOTH); }
#else
  operator Capability() const { return Capability(GL_POLYGON_SMOOTH); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH_HINT)
struct PolygonSmoothHintEnum {
#if __has_feature(cxx_constexpr)
  constexpr PolygonSmoothHintEnum() { }
  constexpr operator HintTarget() const { return HintTarget(GL_POLYGON_SMOOTH_HINT); }
#else
  operator HintTarget() const { return HintTarget(GL_POLYGON_SMOOTH_HINT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART)
struct PrimitiveRestartEnum {
#if __has_feature(cxx_constexpr)
  constexpr PrimitiveRestartEnum() { }
  constexpr operator Capability() const { return Capability(GL_PRIMITIVE_RESTART); }
#else
  operator Capability() const { return Capability(GL_PRIMITIVE_RESTART); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART_FIXED_INDEX)
struct PrimitiveRestartFixedIndexEnum {
#if __has_feature(cxx_constexpr)
  constexpr PrimitiveRestartFixedIndexEnum() { }
  constexpr operator Capability() const { return Capability(GL_PRIMITIVE_RESTART_FIXED_INDEX); }
#else
  operator Capability() const { return Capability(GL_PRIMITIVE_RESTART_FIXED_INDEX); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PROGRAM_POINT_SIZE)
struct ProgramPointSizeEnum {
#if __has_feature(cxx_constexpr)
  constexpr ProgramPointSizeEnum() { }
  constexpr operator Capability() const { return Capability(GL_PROGRAM_POINT_SIZE); }
#else
  operator Capability() const { return Capability(GL_PROGRAM_POINT_SIZE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R11F_G11F_B10F)
struct R11FG11FB10FEnum {
#if __has_feature(cxx_constexpr)
  constexpr R11FG11FB10FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R11F_G11F_B10F); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R11F_G11F_B10F); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16)
struct R16Enum {
#if __has_feature(cxx_constexpr)
  constexpr R16Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16F)
struct R16FEnum {
#if __has_feature(cxx_constexpr)
  constexpr R16FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16F); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16F); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16I)
struct R16IEnum {
#if __has_feature(cxx_constexpr)
  constexpr R16IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16UI)
struct R16UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr R16UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16_SNORM)
struct R16SnormEnum {
#if __has_feature(cxx_constexpr)
  constexpr R16SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16_SNORM); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R16_SNORM); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32F)
struct R32FEnum {
#if __has_feature(cxx_constexpr)
  constexpr R32FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32F); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32F); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32I)
struct R32IEnum {
#if __has_feature(cxx_constexpr)
  constexpr R32IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32UI)
struct R32UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr R32UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R32UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R3_G3_B2)
struct R3G3B2Enum {
#if __has_feature(cxx_constexpr)
  constexpr R3G3B2Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R3_G3_B2); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R3_G3_B2); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8)
struct R8Enum {
#if __has_feature(cxx_constexpr)
  constexpr R8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8I)
struct R8IEnum {
#if __has_feature(cxx_constexpr)
  constexpr R8IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8UI)
struct R8UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr R8UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8_SNORM)
struct R8SnormEnum {
#if __has_feature(cxx_constexpr)
  constexpr R8SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8_SNORM); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_R8_SNORM); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RASTERIZER_DISCARD)
struct RasterizerDiscardEnum {
#if __has_feature(cxx_constexpr)
  constexpr RasterizerDiscardEnum() { }
  constexpr operator Capability() const { return Capability(GL_RASTERIZER_DISCARD); }
#else
  operator Capability() const { return Capability(GL_RASTERIZER_DISCARD); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
struct ReadFramebufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr ReadFramebufferEnum() { }
  constexpr operator FramebufferTarget() const { return FramebufferTarget(GL_READ_FRAMEBUFFER); }
#else
  operator FramebufferTarget() const { return FramebufferTarget(GL_READ_FRAMEBUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
struct ReadOnlyEnum {
#if __has_feature(cxx_constexpr)
  constexpr ReadOnlyEnum() { }
  constexpr operator BufferMapAccess() const { return BufferMapAccess(GL_READ_ONLY); }
#else
  operator BufferMapAccess() const { return BufferMapAccess(GL_READ_ONLY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
struct ReadWriteEnum {
#if __has_feature(cxx_constexpr)
  constexpr ReadWriteEnum() { }
  constexpr operator BufferMapAccess() const { return BufferMapAccess(GL_READ_WRITE); }
#else
  operator BufferMapAccess() const { return BufferMapAccess(GL_READ_WRITE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
struct RedEnum {
#if __has_feature(cxx_constexpr)
  constexpr RedEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RED); }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_RED); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RED); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RED); }
  operator SwizzleMode() const { return SwizzleMode(GL_RED); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_RED); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
struct RedIntegerEnum {
#if __has_feature(cxx_constexpr)
  constexpr RedIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RED_INTEGER); }
#else
  operator PixelDataFormat() const { return PixelDataFormat(GL_RED_INTEGER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RENDERBUFFER)
struct RenderbufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr RenderbufferEnum() { }
  constexpr operator RenderbufferTarget() const { return RenderbufferTarget(GL_RENDERBUFFER); }
#else
  operator RenderbufferTarget() const { return RenderbufferTarget(GL_RENDERBUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPEAT)
struct RepeatEnum {
#if __has_feature(cxx_constexpr)
  constexpr RepeatEnum() { }
  constexpr operator WrapMode() const { return WrapMode(GL_REPEAT); }
#else
  operator WrapMode() const { return WrapMode(GL_REPEAT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
struct ReplaceEnum {
#if __has_feature(cxx_constexpr)
  constexpr ReplaceEnum() { }
  constexpr operator StencilOperation() const { return StencilOperation(GL_REPLACE); }
#else
  operator StencilOperation() const { return StencilOperation(GL_REPLACE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG)
struct RgEnum {
#if __has_feature(cxx_constexpr)
  constexpr RgEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RG); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_RG); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16)
struct Rg16Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rg16Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16F)
struct Rg16FEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rg16FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16F); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16F); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16I)
struct Rg16IEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rg16IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16UI)
struct Rg16UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rg16UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16_SNORM)
struct Rg16SnormEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rg16SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16_SNORM); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG16_SNORM); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32F)
struct Rg32FEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rg32FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32F); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32F); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32I)
struct Rg32IEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rg32IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32UI)
struct Rg32UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rg32UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG32UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8)
struct Rg8Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rg8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8I)
struct Rg8IEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rg8IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8UI)
struct Rg8UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rg8UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8_SNORM)
struct Rg8SnormEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rg8SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8_SNORM); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RG8_SNORM); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
struct RgbEnum {
#if __has_feature(cxx_constexpr)
  constexpr RgbEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGB); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_RGB); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10)
struct Rgb10Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb10Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2)
struct Rgb10A2Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb10A2Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10_A2); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10_A2); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2UI)
struct Rgb10A2UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb10A2UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10_A2UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB10_A2UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB12)
struct Rgb12Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb12Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB12); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB12); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16)
struct Rgb16Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb16Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16F)
struct Rgb16FEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb16FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16F); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16F); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16I)
struct Rgb16IEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb16IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16UI)
struct Rgb16UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb16UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16_SNORM)
struct Rgb16SnormEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb16SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16_SNORM); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB16_SNORM); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32F)
struct Rgb32FEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb32FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32F); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32F); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32I)
struct Rgb32IEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb32IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32UI)
struct Rgb32UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb32UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB32UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB4)
struct Rgb4Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb4Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB4); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB4); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5)
struct Rgb5Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb5Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB5); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB5); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5_A1)
struct Rgb5A1Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb5A1Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB5_A1); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB5_A1); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8)
struct Rgb8Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8I)
struct Rgb8IEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb8IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8UI)
struct Rgb8UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb8UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8_SNORM)
struct Rgb8SnormEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb8SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8_SNORM); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB8_SNORM); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB9_E5)
struct Rgb9E5Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgb9E5Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB9_E5); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGB9_E5); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
struct RgbaEnum {
#if __has_feature(cxx_constexpr)
  constexpr RgbaEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA); }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGBA); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA); }
  operator PixelDataFormat() const { return PixelDataFormat(GL_RGBA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA12)
struct Rgba12Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba12Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA12); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA12); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16)
struct Rgba16Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba16Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16F)
struct Rgba16FEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba16FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16F); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16F); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16I)
struct Rgba16IEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba16IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16UI)
struct Rgba16UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba16UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16_SNORM)
struct Rgba16SnormEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba16SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16_SNORM); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA16_SNORM); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA2)
struct Rgba2Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba2Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA2); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA2); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32F)
struct Rgba32FEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba32FEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32F); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32F); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32I)
struct Rgba32IEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba32IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32UI)
struct Rgba32UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba32UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA32UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA4)
struct Rgba4Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba4Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA4); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA4); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8)
struct Rgba8Enum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8I)
struct Rgba8IEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba8IEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8I); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8I); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8UI)
struct Rgba8UiEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba8UiEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8UI); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8UI); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8_SNORM)
struct Rgba8SnormEnum {
#if __has_feature(cxx_constexpr)
  constexpr Rgba8SnormEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8_SNORM); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_RGBA8_SNORM); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
struct RgbaIntegerEnum {
#if __has_feature(cxx_constexpr)
  constexpr RgbaIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGBA_INTEGER); }
#else
  operator PixelDataFormat() const { return PixelDataFormat(GL_RGBA_INTEGER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
struct RgbIntegerEnum {
#if __has_feature(cxx_constexpr)
  constexpr RgbIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RGB_INTEGER); }
#else
  operator PixelDataFormat() const { return PixelDataFormat(GL_RGB_INTEGER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
struct RgIntegerEnum {
#if __has_feature(cxx_constexpr)
  constexpr RgIntegerEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_RG_INTEGER); }
#else
  operator PixelDataFormat() const { return PixelDataFormat(GL_RG_INTEGER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RIGHT)
struct RightEnum {
#if __has_feature(cxx_constexpr)
  constexpr RightEnum() { }
  constexpr operator ColorBuffer() const { return ColorBuffer(GL_RIGHT); }
#else
  operator ColorBuffer() const { return ColorBuffer(GL_RIGHT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_COVERAGE)
struct SampleAlphaToCoverageEnum {
#if __has_feature(cxx_constexpr)
  constexpr SampleAlphaToCoverageEnum() { }
  constexpr operator Capability() const { return Capability(GL_SAMPLE_ALPHA_TO_COVERAGE); }
#else
  operator Capability() const { return Capability(GL_SAMPLE_ALPHA_TO_COVERAGE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_ONE)
struct SampleAlphaToOneEnum {
#if __has_feature(cxx_constexpr)
  constexpr SampleAlphaToOneEnum() { }
  constexpr operator Capability() const { return Capability(GL_SAMPLE_ALPHA_TO_ONE); }
#else
  operator Capability() const { return Capability(GL_SAMPLE_ALPHA_TO_ONE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_COVERAGE)
struct SampleCoverageEnum {
#if __has_feature(cxx_constexpr)
  constexpr SampleCoverageEnum() { }
  constexpr operator Capability() const { return Capability(GL_SAMPLE_COVERAGE); }
#else
  operator Capability() const { return Capability(GL_SAMPLE_COVERAGE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_MASK)
struct SampleMaskEnum {
#if __has_feature(cxx_constexpr)
  constexpr SampleMaskEnum() { }
  constexpr operator Capability() const { return Capability(GL_SAMPLE_MASK); }
#else
  operator Capability() const { return Capability(GL_SAMPLE_MASK); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_SHADING)
struct SampleShadingEnum {
#if __has_feature(cxx_constexpr)
  constexpr SampleShadingEnum() { }
  constexpr operator Capability() const { return Capability(GL_SAMPLE_SHADING); }
#else
  operator Capability() const { return Capability(GL_SAMPLE_SHADING); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_TEST)
struct ScissorTestEnum {
#if __has_feature(cxx_constexpr)
  constexpr ScissorTestEnum() { }
  constexpr operator Capability() const { return Capability(GL_SCISSOR_TEST); }
#else
  operator Capability() const { return Capability(GL_SCISSOR_TEST); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
struct SetEnum {
#if __has_feature(cxx_constexpr)
  constexpr SetEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_SET); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_SET); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT)
struct ShaderImageAccessBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr ShaderImageAccessBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BARRIER_BIT)
struct ShaderStorageBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr ShaderStorageBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_SHADER_STORAGE_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_SHADER_STORAGE_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
struct ShaderStorageBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr ShaderStorageBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_SHADER_STORAGE_BUFFER); }
  constexpr operator IndexedBufferTarget() const { return IndexedBufferTarget(GL_SHADER_STORAGE_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_SHADER_STORAGE_BUFFER); }
  operator IndexedBufferTarget() const { return IndexedBufferTarget(GL_SHADER_STORAGE_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHORT)
struct ShortEnum {
#if __has_feature(cxx_constexpr)
  constexpr ShortEnum() { }
  constexpr operator DataType() const { return DataType(GL_SHORT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_SHORT); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_SHORT); }
#else
  operator DataType() const { return DataType(GL_SHORT); }
  operator PixelDataType() const { return PixelDataType(GL_SHORT); }
  operator WholeDataType() const { return WholeDataType(GL_SHORT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_ALPHA)
struct Src1AlphaEnum {
#if __has_feature(cxx_constexpr)
  constexpr Src1AlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_SRC1_ALPHA); }
#else
  operator BlendFunction() const { return BlendFunction(GL_SRC1_ALPHA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_COLOR)
struct Src1ColorEnum {
#if __has_feature(cxx_constexpr)
  constexpr Src1ColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_SRC1_COLOR); }
#else
  operator BlendFunction() const { return BlendFunction(GL_SRC1_COLOR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA)
struct SrcAlphaEnum {
#if __has_feature(cxx_constexpr)
  constexpr SrcAlphaEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_SRC_ALPHA); }
#else
  operator BlendFunction() const { return BlendFunction(GL_SRC_ALPHA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA_SATURATE)
struct SrcAlphaSaturateEnum {
#if __has_feature(cxx_constexpr)
  constexpr SrcAlphaSaturateEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_SRC_ALPHA_SATURATE); }
#else
  operator BlendFunction() const { return BlendFunction(GL_SRC_ALPHA_SATURATE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_COLOR)
struct SrcColorEnum {
#if __has_feature(cxx_constexpr)
  constexpr SrcColorEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_SRC_COLOR); }
#else
  operator BlendFunction() const { return BlendFunction(GL_SRC_COLOR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB)
struct SrgbEnum {
#if __has_feature(cxx_constexpr)
  constexpr SrgbEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8)
struct Srgb8Enum {
#if __has_feature(cxx_constexpr)
  constexpr Srgb8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB8); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB8); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8_ALPHA8)
struct Srgb8Alpha8Enum {
#if __has_feature(cxx_constexpr)
  constexpr Srgb8Alpha8Enum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB8_ALPHA8); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB8_ALPHA8); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB_ALPHA)
struct SrgbAlphaEnum {
#if __has_feature(cxx_constexpr)
  constexpr SrgbAlphaEnum() { }
  constexpr operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB_ALPHA); }
#else
  operator PixelDataInternalFormat() const { return PixelDataInternalFormat(GL_SRGB_ALPHA); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
struct StackOverflowEnum {
#if __has_feature(cxx_constexpr)
  constexpr StackOverflowEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_STACK_OVERFLOW); }
#else
  operator ErrorType() const { return ErrorType(GL_STACK_OVERFLOW); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
struct StackUnderflowEnum {
#if __has_feature(cxx_constexpr)
  constexpr StackUnderflowEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_STACK_UNDERFLOW); }
#else
  operator ErrorType() const { return ErrorType(GL_STACK_UNDERFLOW); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_COPY)
struct StaticCopyEnum {
#if __has_feature(cxx_constexpr)
  constexpr StaticCopyEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STATIC_COPY); }
#else
  operator BufferUsage() const { return BufferUsage(GL_STATIC_COPY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_DRAW)
struct StaticDrawEnum {
#if __has_feature(cxx_constexpr)
  constexpr StaticDrawEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STATIC_DRAW); }
#else
  operator BufferUsage() const { return BufferUsage(GL_STATIC_DRAW); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_READ)
struct StaticReadEnum {
#if __has_feature(cxx_constexpr)
  constexpr StaticReadEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STATIC_READ); }
#else
  operator BufferUsage() const { return BufferUsage(GL_STATIC_READ); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_ATTACHMENT)
struct StencilAttachmentEnum {
#if __has_feature(cxx_constexpr)
  constexpr StencilAttachmentEnum() { }
  constexpr operator FramebufferAttachment() const { return FramebufferAttachment(GL_STENCIL_ATTACHMENT); }
#else
  operator FramebufferAttachment() const { return FramebufferAttachment(GL_STENCIL_ATTACHMENT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
struct StencilBufferBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr StencilBufferBitEnum() { }
  constexpr operator BufferSelectBit() const { return BufferSelectBit(GL_STENCIL_BUFFER_BIT); }
#else
  operator BufferSelectBit() const { return BufferSelectBit(GL_STENCIL_BUFFER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_INDEX)
struct StencilIndexEnum {
#if __has_feature(cxx_constexpr)
  constexpr StencilIndexEnum() { }
  constexpr operator PixelDataFormat() const { return PixelDataFormat(GL_STENCIL_INDEX); }
#else
  operator PixelDataFormat() const { return PixelDataFormat(GL_STENCIL_INDEX); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_TEST)
struct StencilTestEnum {
#if __has_feature(cxx_constexpr)
  constexpr StencilTestEnum() { }
  constexpr operator Capability() const { return Capability(GL_STENCIL_TEST); }
#else
  operator Capability() const { return Capability(GL_STENCIL_TEST); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_COPY)
struct StreamCopyEnum {
#if __has_feature(cxx_constexpr)
  constexpr StreamCopyEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STREAM_COPY); }
#else
  operator BufferUsage() const { return BufferUsage(GL_STREAM_COPY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_DRAW)
struct StreamDrawEnum {
#if __has_feature(cxx_constexpr)
  constexpr StreamDrawEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STREAM_DRAW); }
#else
  operator BufferUsage() const { return BufferUsage(GL_STREAM_DRAW); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_READ)
struct StreamReadEnum {
#if __has_feature(cxx_constexpr)
  constexpr StreamReadEnum() { }
  constexpr operator BufferUsage() const { return BufferUsage(GL_STREAM_READ); }
#else
  operator BufferUsage() const { return BufferUsage(GL_STREAM_READ); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
struct TableTooLargeEnum {
#if __has_feature(cxx_constexpr)
  constexpr TableTooLargeEnum() { }
  constexpr operator ErrorType() const { return ErrorType(GL_TABLE_TOO_LARGE); }
#else
  operator ErrorType() const { return ErrorType(GL_TABLE_TOO_LARGE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
struct TessControlShaderEnum {
#if __has_feature(cxx_constexpr)
  constexpr TessControlShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_TESS_CONTROL_SHADER); }
#else
  operator ShaderType() const { return ShaderType(GL_TESS_CONTROL_SHADER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
struct TessEvaluationShaderEnum {
#if __has_feature(cxx_constexpr)
  constexpr TessEvaluationShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_TESS_EVALUATION_SHADER); }
#else
  operator ShaderType() const { return ShaderType(GL_TESS_EVALUATION_SHADER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D)
struct Texture1DEnum {
#if __has_feature(cxx_constexpr)
  constexpr Texture1DEnum() { }
  constexpr operator TextureTarget() const { return TextureTarget(GL_TEXTURE_1D); }
#else
  operator TextureTarget() const { return TextureTarget(GL_TEXTURE_1D); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
struct Texture1DArrayEnum {
#if __has_feature(cxx_constexpr)
  constexpr Texture1DArrayEnum() { }
  constexpr operator Texture2DTarget() const { return Texture2DTarget(GL_TEXTURE_1D_ARRAY); }
  constexpr operator TextureTarget() const { return TextureTarget(GL_TEXTURE_1D_ARRAY); }
#else
  operator Texture2DTarget() const { return Texture2DTarget(GL_TEXTURE_1D_ARRAY); }
  operator TextureTarget() const { return TextureTarget(GL_TEXTURE_1D_ARRAY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
struct Texture2DEnum {
#if __has_feature(cxx_constexpr)
  constexpr Texture2DEnum() { }
  constexpr operator Texture2DTarget() const { return Texture2DTarget(GL_TEXTURE_2D); }
  constexpr operator TextureTarget() const { return TextureTarget(GL_TEXTURE_2D); }
#else
  operator Texture2DTarget() const { return Texture2DTarget(GL_TEXTURE_2D); }
  operator TextureTarget() const { return TextureTarget(GL_TEXTURE_2D); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
struct Texture2DArrayEnum {
#if __has_feature(cxx_constexpr)
  constexpr Texture2DArrayEnum() { }
  constexpr operator Texture3DTarget() const { return Texture3DTarget(GL_TEXTURE_2D_ARRAY); }
  constexpr operator TextureTarget() const { return TextureTarget(GL_TEXTURE_2D_ARRAY); }
#else
  operator Texture3DTarget() const { return Texture3DTarget(GL_TEXTURE_2D_ARRAY); }
  operator TextureTarget() const { return TextureTarget(GL_TEXTURE_2D_ARRAY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
struct Texture3DEnum {
#if __has_feature(cxx_constexpr)
  constexpr Texture3DEnum() { }
  constexpr operator Texture3DTarget() const { return Texture3DTarget(GL_TEXTURE_3D); }
  constexpr operator TextureTarget() const { return TextureTarget(GL_TEXTURE_3D); }
#else
  operator Texture3DTarget() const { return Texture3DTarget(GL_TEXTURE_3D); }
  operator TextureTarget() const { return TextureTarget(GL_TEXTURE_3D); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
struct TextureBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_TEXTURE_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_TEXTURE_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_COMPRESSION_HINT)
struct TextureCompressionHintEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureCompressionHintEnum() { }
  constexpr operator HintTarget() const { return HintTarget(GL_TEXTURE_COMPRESSION_HINT); }
#else
  operator HintTarget() const { return HintTarget(GL_TEXTURE_COMPRESSION_HINT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
struct TextureCubeMapEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureCubeMapEnum() { }
  constexpr operator Texture2DTarget() const { return Texture2DTarget(GL_TEXTURE_CUBE_MAP); }
  constexpr operator TextureTarget() const { return TextureTarget(GL_TEXTURE_CUBE_MAP); }
#else
  operator Texture2DTarget() const { return Texture2DTarget(GL_TEXTURE_CUBE_MAP); }
  operator TextureTarget() const { return TextureTarget(GL_TEXTURE_CUBE_MAP); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
struct TextureCubeMapNegativeXEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureCubeMapNegativeXEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_X); }
#else
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_X); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
struct TextureCubeMapNegativeYEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureCubeMapNegativeYEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y); }
#else
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
struct TextureCubeMapNegativeZEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureCubeMapNegativeZEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z); }
#else
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
struct TextureCubeMapPositiveXEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureCubeMapPositiveXEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_X); }
#else
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_X); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
struct TextureCubeMapPositiveYEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureCubeMapPositiveYEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_Y); }
#else
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_Y); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
struct TextureCubeMapPositiveZEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureCubeMapPositiveZEnum() { }
  constexpr operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_Z); }
#else
  operator TextureCubeTarget() const { return TextureCubeTarget(GL_TEXTURE_CUBE_MAP_POSITIVE_Z); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_SEAMLESS)
struct TextureCubeMapSeamlessEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureCubeMapSeamlessEnum() { }
  constexpr operator Capability() const { return Capability(GL_TEXTURE_CUBE_MAP_SEAMLESS); }
#else
  operator Capability() const { return Capability(GL_TEXTURE_CUBE_MAP_SEAMLESS); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_FETCH_BARRIER_BIT)
struct TextureFetchBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureFetchBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TEXTURE_FETCH_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TEXTURE_FETCH_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
struct TextureRectangleEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureRectangleEnum() { }
  constexpr operator Texture2DTarget() const { return Texture2DTarget(GL_TEXTURE_RECTANGLE); }
  constexpr operator TextureTarget() const { return TextureTarget(GL_TEXTURE_RECTANGLE); }
#else
  operator Texture2DTarget() const { return Texture2DTarget(GL_TEXTURE_RECTANGLE); }
  operator TextureTarget() const { return TextureTarget(GL_TEXTURE_RECTANGLE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_UPDATE_BARRIER_BIT)
struct TextureUpdateBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr TextureUpdateBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TEXTURE_UPDATE_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TEXTURE_UPDATE_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK)
struct TransformFeedbackEnum {
#if __has_feature(cxx_constexpr)
  constexpr TransformFeedbackEnum() { }
  constexpr operator TransformFeedbackTarget() const { return TransformFeedbackTarget(GL_TRANSFORM_FEEDBACK); }
#else
  operator TransformFeedbackTarget() const { return TransformFeedbackTarget(GL_TRANSFORM_FEEDBACK); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BARRIER_BIT)
struct TransformFeedbackBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr TransformFeedbackBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TRANSFORM_FEEDBACK_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_TRANSFORM_FEEDBACK_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
struct TransformFeedbackBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr TransformFeedbackBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_TRANSFORM_FEEDBACK_BUFFER); }
  constexpr operator IndexedBufferTarget() const { return IndexedBufferTarget(GL_TRANSFORM_FEEDBACK_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_TRANSFORM_FEEDBACK_BUFFER); }
  operator IndexedBufferTarget() const { return IndexedBufferTarget(GL_TRANSFORM_FEEDBACK_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
struct TrianglesEnum {
#if __has_feature(cxx_constexpr)
  constexpr TrianglesEnum() { }
  constexpr operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_TRIANGLES); }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLES); }
#else
  operator BasicPrimitiveType() const { return BasicPrimitiveType(GL_TRIANGLES); }
  operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLES); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
struct TrianglesAdjacencyEnum {
#if __has_feature(cxx_constexpr)
  constexpr TrianglesAdjacencyEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLES_ADJACENCY); }
#else
  operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLES_ADJACENCY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
struct TriangleFanEnum {
#if __has_feature(cxx_constexpr)
  constexpr TriangleFanEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_FAN); }
#else
  operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_FAN); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
struct TriangleStripEnum {
#if __has_feature(cxx_constexpr)
  constexpr TriangleStripEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_STRIP); }
#else
  operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_STRIP); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
struct TriangleStripAdjacencyEnum {
#if __has_feature(cxx_constexpr)
  constexpr TriangleStripAdjacencyEnum() { }
  constexpr operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_STRIP_ADJACENCY); }
#else
  operator PrimitiveType() const { return PrimitiveType(GL_TRIANGLE_STRIP_ADJACENCY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BARRIER_BIT)
struct UniformBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr UniformBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_UNIFORM_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_UNIFORM_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
struct UniformBufferEnum {
#if __has_feature(cxx_constexpr)
  constexpr UniformBufferEnum() { }
  constexpr operator BufferTarget() const { return BufferTarget(GL_UNIFORM_BUFFER); }
  constexpr operator IndexedBufferTarget() const { return IndexedBufferTarget(GL_UNIFORM_BUFFER); }
#else
  operator BufferTarget() const { return BufferTarget(GL_UNIFORM_BUFFER); }
  operator IndexedBufferTarget() const { return IndexedBufferTarget(GL_UNIFORM_BUFFER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ALIGNMENT)
struct UnpackAlignmentEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackAlignmentEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_ALIGNMENT); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_ALIGNMENT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_DEPTH)
struct UnpackCompressedBlockDepthEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackCompressedBlockDepthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_DEPTH); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_DEPTH); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT)
struct UnpackCompressedBlockHeightEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackCompressedBlockHeightEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_SIZE)
struct UnpackCompressedBlockSizeEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackCompressedBlockSizeEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_SIZE); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_SIZE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_WIDTH)
struct UnpackCompressedBlockWidthEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackCompressedBlockWidthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_WIDTH); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_COMPRESSED_BLOCK_WIDTH); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_IMAGE_HEIGHT)
struct UnpackImageHeightEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackImageHeightEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_IMAGE_HEIGHT); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_IMAGE_HEIGHT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_LSB_FIRST)
struct UnpackLsbFirstEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackLsbFirstEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_LSB_FIRST); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_LSB_FIRST); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ROW_LENGTH)
struct UnpackRowLengthEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackRowLengthEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_ROW_LENGTH); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_ROW_LENGTH); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_IMAGES)
struct UnpackSkipImagesEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackSkipImagesEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_IMAGES); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_IMAGES); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_PIXELS)
struct UnpackSkipPixelsEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackSkipPixelsEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_PIXELS); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_PIXELS); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_ROWS)
struct UnpackSkipRowsEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackSkipRowsEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_ROWS); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SKIP_ROWS); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SWAP_BYTES)
struct UnpackSwapBytesEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnpackSwapBytesEnum() { }
  constexpr operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SWAP_BYTES); }
#else
  operator PixelStorageMode() const { return PixelStorageMode(GL_UNPACK_SWAP_BYTES); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE)
struct UnsignedByteEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedByteEnum() { }
  constexpr operator DataType() const { return DataType(GL_UNSIGNED_BYTE); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_BYTE); }
  constexpr operator IndexType() const { return IndexType(GL_UNSIGNED_BYTE); }
#else
  operator DataType() const { return DataType(GL_UNSIGNED_BYTE); }
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE); }
  operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_BYTE); }
  operator IndexType() const { return IndexType(GL_UNSIGNED_BYTE); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_2_3_3_REV)
struct UnsignedByte233RevEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedByte233RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE_2_3_3_REV); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE_2_3_3_REV); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_3_3_2)
struct UnsignedByte332Enum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedByte332Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE_3_3_2); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_BYTE_3_3_2); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT)
struct UnsignedIntEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedIntEnum() { }
  constexpr operator DataType() const { return DataType(GL_UNSIGNED_INT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_INT); }
  constexpr operator IndexType() const { return IndexType(GL_UNSIGNED_INT); }
#else
  operator DataType() const { return DataType(GL_UNSIGNED_INT); }
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT); }
  operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_INT); }
  operator IndexType() const { return IndexType(GL_UNSIGNED_INT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10F_11F_11F_REV)
struct UnsignedInt10F11F11FRevEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedInt10F11F11FRevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_10F_11F_11F_REV); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_10F_11F_11F_REV); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10_10_10_2)
struct UnsignedInt1010102Enum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedInt1010102Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_10_10_10_2); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_10_10_10_2); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_24_8)
struct UnsignedInt248Enum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedInt248Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_24_8); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_24_8); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_2_10_10_10_REV)
struct UnsignedInt2101010RevEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedInt2101010RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_2_10_10_10_REV); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_2_10_10_10_REV); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_5_9_9_9_REV)
struct UnsignedInt5999RevEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedInt5999RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_5_9_9_9_REV); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_5_9_9_9_REV); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8)
struct UnsignedInt8888Enum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedInt8888Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_8_8_8_8); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_8_8_8_8); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8_REV)
struct UnsignedInt8888RevEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedInt8888RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_8_8_8_8_REV); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_INT_8_8_8_8_REV); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT)
struct UnsignedShortEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedShortEnum() { }
  constexpr operator DataType() const { return DataType(GL_UNSIGNED_SHORT); }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT); }
  constexpr operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_SHORT); }
  constexpr operator IndexType() const { return IndexType(GL_UNSIGNED_SHORT); }
#else
  operator DataType() const { return DataType(GL_UNSIGNED_SHORT); }
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT); }
  operator WholeDataType() const { return WholeDataType(GL_UNSIGNED_SHORT); }
  operator IndexType() const { return IndexType(GL_UNSIGNED_SHORT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_1_5_5_5_REV)
struct UnsignedShort1555RevEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedShort1555RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_1_5_5_5_REV); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_1_5_5_5_REV); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4)
struct UnsignedShort4444Enum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedShort4444Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_4_4_4_4); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_4_4_4_4); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4_REV)
struct UnsignedShort4444RevEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedShort4444RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_4_4_4_4_REV); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_4_4_4_4_REV); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_5_5_1)
struct UnsignedShort5551Enum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedShort5551Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_5_5_1); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_5_5_1); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5)
struct UnsignedShort565Enum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedShort565Enum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_6_5); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_6_5); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5_REV)
struct UnsignedShort565RevEnum {
#if __has_feature(cxx_constexpr)
  constexpr UnsignedShort565RevEnum() { }
  constexpr operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_6_5_REV); }
#else
  operator PixelDataType() const { return PixelDataType(GL_UNSIGNED_SHORT_5_6_5_REV); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ARRAY)
struct VertexArrayEnum {
#if __has_feature(cxx_constexpr)
  constexpr VertexArrayEnum() { }
  constexpr operator VertexArrayTarget() const { return VertexArrayTarget(GL_VERTEX_ARRAY); }
#else
  operator VertexArrayTarget() const { return VertexArrayTarget(GL_VERTEX_ARRAY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT)
struct VertexAttribArrayBarrierBitEnum {
#if __has_feature(cxx_constexpr)
  constexpr VertexAttribArrayBarrierBitEnum() { }
  constexpr operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT); }
#else
  operator MemoryBarrierBit() const { return MemoryBarrierBit(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
struct VertexShaderEnum {
#if __has_feature(cxx_constexpr)
  constexpr VertexShaderEnum() { }
  constexpr operator ShaderType() const { return ShaderType(GL_VERTEX_SHADER); }
#else
  operator ShaderType() const { return ShaderType(GL_VERTEX_SHADER); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
struct WriteOnlyEnum {
#if __has_feature(cxx_constexpr)
  constexpr WriteOnlyEnum() { }
  constexpr operator BufferMapAccess() const { return BufferMapAccess(GL_WRITE_ONLY); }
#else
  operator BufferMapAccess() const { return BufferMapAccess(GL_WRITE_ONLY); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
struct XorEnum {
#if __has_feature(cxx_constexpr)
  constexpr XorEnum() { }
  constexpr operator ColorLogicOperation() const { return ColorLogicOperation(GL_XOR); }
#else
  operator ColorLogicOperation() const { return ColorLogicOperation(GL_XOR); }
#endif
};
#endif

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
struct ZeroEnum {
#if __has_feature(cxx_constexpr)
  constexpr ZeroEnum() { }
  constexpr operator BlendFunction() const { return BlendFunction(GL_ZERO); }
  constexpr operator SwizzleMode() const { return SwizzleMode(GL_ZERO); }
  constexpr operator StencilOperation() const { return StencilOperation(GL_ZERO); }
#else
  operator BlendFunction() const { return BlendFunction(GL_ZERO); }
  operator SwizzleMode() const { return SwizzleMode(GL_ZERO); }
  operator StencilOperation() const { return StencilOperation(GL_ZERO); }
#endif
};
#endif

} // namespace smart_enums

#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALPHA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::AlphaEnum kAlpha;
#else
  static smart_enums::AlphaEnum kAlpha;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::AlwaysEnum kAlways;
#else
  static smart_enums::AlwaysEnum kAlways;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::AndEnum kAnd;
#else
  static smart_enums::AndEnum kAnd;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::AndInvertedEnum kAndInverted;
#else
  static smart_enums::AndInvertedEnum kAndInverted;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::AndReverseEnum kAndReverse;
#else
  static smart_enums::AndReverseEnum kAndReverse;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ARRAY_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ArrayBufferEnum kArrayBuffer;
#else
  static smart_enums::ArrayBufferEnum kArrayBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::AtomicCounterBarrierBitEnum kAtomicCounterBarrierBit;
#else
  static smart_enums::AtomicCounterBarrierBitEnum kAtomicCounterBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ATOMIC_COUNTER_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::AtomicCounterBufferEnum kAtomicCounterBuffer;
#else
  static smart_enums::AtomicCounterBufferEnum kAtomicCounterBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::BackEnum kBack;
#else
  static smart_enums::BackEnum kBack;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_LEFT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::BackLeftEnum kBackLeft;
#else
  static smart_enums::BackLeftEnum kBackLeft;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_RIGHT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::BackRightEnum kBackRight;
#else
  static smart_enums::BackRightEnum kBackRight;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::BgrEnum kBgr;
#else
  static smart_enums::BgrEnum kBgr;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::BgraEnum kBgra;
#else
  static smart_enums::BgraEnum kBgra;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGRA_INTEGER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::BgraIntegerEnum kBgraInteger;
#else
  static smart_enums::BgraIntegerEnum kBgraInteger;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BGR_INTEGER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::BgrIntegerEnum kBgrInteger;
#else
  static smart_enums::BgrIntegerEnum kBgrInteger;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLEND)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::BlendEnum kBlend;
#else
  static smart_enums::BlendEnum kBlend;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::BlueEnum kBlue;
#else
  static smart_enums::BlueEnum kBlue;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLUE_INTEGER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::BlueIntegerEnum kBlueInteger;
#else
  static smart_enums::BlueIntegerEnum kBlueInteger;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BUFFER_UPDATE_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::BufferUpdateBarrierBitEnum kBufferUpdateBarrierBit;
#else
  static smart_enums::BufferUpdateBarrierBitEnum kBufferUpdateBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BYTE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ByteEnum kByte;
#else
  static smart_enums::ByteEnum kByte;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CcwEnum kCcw;
#else
  static smart_enums::CcwEnum kCcw;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_BORDER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ClampToBorderEnum kClampToBorder;
#else
  static smart_enums::ClampToBorderEnum kClampToBorder;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLAMP_TO_EDGE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ClampToEdgeEnum kClampToEdge;
#else
  static smart_enums::ClampToEdgeEnum kClampToEdge;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ClearEnum kClear;
#else
  static smart_enums::ClearEnum kClear;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ClientMappedBufferBarrierBitEnum kClientMappedBufferBarrierBit;
#else
  static smart_enums::ClientMappedBufferBarrierBitEnum kClientMappedBufferBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIENT_STORAGE_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ClientStorageBitEnum kClientStorageBit;
#else
  static smart_enums::ClientStorageBitEnum kClientStorageBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIP_DISTANCE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ClipDistanceEnum kClipDistance;
#else
  static smart_enums::ClipDistanceEnum kClipDistance;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT0)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment0Enum kColorAttachment0;
#else
  static smart_enums::ColorAttachment0Enum kColorAttachment0;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT1)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment1Enum kColorAttachment1;
#else
  static smart_enums::ColorAttachment1Enum kColorAttachment1;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT10)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment10Enum kColorAttachment10;
#else
  static smart_enums::ColorAttachment10Enum kColorAttachment10;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT11)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment11Enum kColorAttachment11;
#else
  static smart_enums::ColorAttachment11Enum kColorAttachment11;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT12)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment12Enum kColorAttachment12;
#else
  static smart_enums::ColorAttachment12Enum kColorAttachment12;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT13)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment13Enum kColorAttachment13;
#else
  static smart_enums::ColorAttachment13Enum kColorAttachment13;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT14)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment14Enum kColorAttachment14;
#else
  static smart_enums::ColorAttachment14Enum kColorAttachment14;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT15)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment15Enum kColorAttachment15;
#else
  static smart_enums::ColorAttachment15Enum kColorAttachment15;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT2)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment2Enum kColorAttachment2;
#else
  static smart_enums::ColorAttachment2Enum kColorAttachment2;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT3)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment3Enum kColorAttachment3;
#else
  static smart_enums::ColorAttachment3Enum kColorAttachment3;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT4)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment4Enum kColorAttachment4;
#else
  static smart_enums::ColorAttachment4Enum kColorAttachment4;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT5)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment5Enum kColorAttachment5;
#else
  static smart_enums::ColorAttachment5Enum kColorAttachment5;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT6)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment6Enum kColorAttachment6;
#else
  static smart_enums::ColorAttachment6Enum kColorAttachment6;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT7)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment7Enum kColorAttachment7;
#else
  static smart_enums::ColorAttachment7Enum kColorAttachment7;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT8)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment8Enum kColorAttachment8;
#else
  static smart_enums::ColorAttachment8Enum kColorAttachment8;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT9)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorAttachment9Enum kColorAttachment9;
#else
  static smart_enums::ColorAttachment9Enum kColorAttachment9;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorBufferBitEnum kColorBufferBit;
#else
  static smart_enums::ColorBufferBitEnum kColorBufferBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_LOGIC_OP)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ColorLogicOpEnum kColorLogicOp;
#else
  static smart_enums::ColorLogicOpEnum kColorLogicOp;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMMAND_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CommandBarrierBitEnum kCommandBarrierBit;
#else
  static smart_enums::CommandBarrierBitEnum kCommandBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPARE_REF_TO_TEXTURE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CompareRefToTextureEnum kCompareRefToTexture;
#else
  static smart_enums::CompareRefToTextureEnum kCompareRefToTexture;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CompressedRedEnum kCompressedRed;
#else
  static smart_enums::CompressedRedEnum kCompressedRed;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RED_RGTC1)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CompressedRedRgtc1Enum kCompressedRedRgtc1;
#else
  static smart_enums::CompressedRedRgtc1Enum kCompressedRedRgtc1;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CompressedRgEnum kCompressedRg;
#else
  static smart_enums::CompressedRgEnum kCompressedRg;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGB)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CompressedRgbEnum kCompressedRgb;
#else
  static smart_enums::CompressedRgbEnum kCompressedRgb;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RGBA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CompressedRgbaEnum kCompressedRgba;
#else
  static smart_enums::CompressedRgbaEnum kCompressedRgba;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_RG_RGTC2)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CompressedRgRgtc2Enum kCompressedRgRgtc2;
#else
  static smart_enums::CompressedRgRgtc2Enum kCompressedRgRgtc2;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RED_RGTC1)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CompressedSignedRedRgtc1Enum kCompressedSignedRedRgtc1;
#else
  static smart_enums::CompressedSignedRedRgtc1Enum kCompressedSignedRedRgtc1;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SIGNED_RG_RGTC2)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CompressedSignedRgRgtc2Enum kCompressedSignedRgRgtc2;
#else
  static smart_enums::CompressedSignedRgRgtc2Enum kCompressedSignedRgRgtc2;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CompressedSrgbEnum kCompressedSrgb;
#else
  static smart_enums::CompressedSrgbEnum kCompressedSrgb;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPRESSED_SRGB_ALPHA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CompressedSrgbAlphaEnum kCompressedSrgbAlpha;
#else
  static smart_enums::CompressedSrgbAlphaEnum kCompressedSrgbAlpha;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COMPUTE_SHADER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ComputeShaderEnum kComputeShader;
#else
  static smart_enums::ComputeShaderEnum kComputeShader;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_ALPHA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ConstantAlphaEnum kConstantAlpha;
#else
  static smart_enums::ConstantAlphaEnum kConstantAlpha;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CONSTANT_COLOR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ConstantColorEnum kConstantColor;
#else
  static smart_enums::ConstantColorEnum kConstantColor;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CopyEnum kCopy;
#else
  static smart_enums::CopyEnum kCopy;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CopyInvertedEnum kCopyInverted;
#else
  static smart_enums::CopyInvertedEnum kCopyInverted;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_READ_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CopyReadBufferEnum kCopyReadBuffer;
#else
  static smart_enums::CopyReadBufferEnum kCopyReadBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_WRITE_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CopyWriteBufferEnum kCopyWriteBuffer;
#else
  static smart_enums::CopyWriteBufferEnum kCopyWriteBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CULL_FACE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CullFaceEnum kCullFace;
#else
  static smart_enums::CullFaceEnum kCullFace;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::CwEnum kCw;
#else
  static smart_enums::CwEnum kCw;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DebugOutputEnum kDebugOutput;
#else
  static smart_enums::DebugOutputEnum kDebugOutput;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT_SYNCHRONOUS)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DebugOutputSynchronousEnum kDebugOutputSynchronous;
#else
  static smart_enums::DebugOutputSynchronousEnum kDebugOutputSynchronous;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DecrEnum kDecr;
#else
  static smart_enums::DecrEnum kDecr;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DecrWrapEnum kDecrWrap;
#else
  static smart_enums::DecrWrapEnum kDecrWrap;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_ATTACHMENT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DepthAttachmentEnum kDepthAttachment;
#else
  static smart_enums::DepthAttachmentEnum kDepthAttachment;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DepthBufferBitEnum kDepthBufferBit;
#else
  static smart_enums::DepthBufferBitEnum kDepthBufferBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_CLAMP)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DepthClampEnum kDepthClamp;
#else
  static smart_enums::DepthClampEnum kDepthClamp;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_COMPONENT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DepthComponentEnum kDepthComponent;
#else
  static smart_enums::DepthComponentEnum kDepthComponent;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DepthStencilEnum kDepthStencil;
#else
  static smart_enums::DepthStencilEnum kDepthStencil;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_STENCIL_ATTACHMENT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DepthStencilAttachmentEnum kDepthStencilAttachment;
#else
  static smart_enums::DepthStencilAttachmentEnum kDepthStencilAttachment;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_TEST)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DepthTestEnum kDepthTest;
#else
  static smart_enums::DepthTestEnum kDepthTest;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DISPATCH_INDIRECT_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DispatchIndirectBufferEnum kDispatchIndirectBuffer;
#else
  static smart_enums::DispatchIndirectBufferEnum kDispatchIndirectBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DITHER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DitherEnum kDither;
#else
  static smart_enums::DitherEnum kDither;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DONT_CARE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DontCareEnum kDontCare;
#else
  static smart_enums::DontCareEnum kDontCare;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DOUBLE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DoubleEnum kDouble;
#else
  static smart_enums::DoubleEnum kDouble;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_FRAMEBUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DrawFramebufferEnum kDrawFramebuffer;
#else
  static smart_enums::DrawFramebufferEnum kDrawFramebuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DRAW_INDIRECT_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DrawIndirectBufferEnum kDrawIndirectBuffer;
#else
  static smart_enums::DrawIndirectBufferEnum kDrawIndirectBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_ALPHA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DstAlphaEnum kDstAlpha;
#else
  static smart_enums::DstAlphaEnum kDstAlpha;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DST_COLOR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DstColorEnum kDstColor;
#else
  static smart_enums::DstColorEnum kDstColor;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_COPY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DynamicCopyEnum kDynamicCopy;
#else
  static smart_enums::DynamicCopyEnum kDynamicCopy;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_DRAW)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DynamicDrawEnum kDynamicDraw;
#else
  static smart_enums::DynamicDrawEnum kDynamicDraw;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_READ)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DynamicReadEnum kDynamicRead;
#else
  static smart_enums::DynamicReadEnum kDynamicRead;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DYNAMIC_STORAGE_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::DynamicStorageBitEnum kDynamicStorageBit;
#else
  static smart_enums::DynamicStorageBitEnum kDynamicStorageBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ElementArrayBarrierBitEnum kElementArrayBarrierBit;
#else
  static smart_enums::ElementArrayBarrierBitEnum kElementArrayBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ELEMENT_ARRAY_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ElementArrayBufferEnum kElementArrayBuffer;
#else
  static smart_enums::ElementArrayBufferEnum kElementArrayBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::EqualEnum kEqual;
#else
  static smart_enums::EqualEnum kEqual;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::EquivEnum kEquiv;
#else
  static smart_enums::EquivEnum kEquiv;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FASTEST)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FastestEnum kFastest;
#else
  static smart_enums::FastestEnum kFastest;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FillEnum kFill;
#else
  static smart_enums::FillEnum kFill;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FirstVertexConventionEnum kFirstVertexConvention;
#else
  static smart_enums::FirstVertexConventionEnum kFirstVertexConvention;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIXED)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FixedEnum kFixed;
#else
  static smart_enums::FixedEnum kFixed;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FloatEnum kFloat;
#else
  static smart_enums::FloatEnum kFloat;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Float32UnsignedInt248RevEnum kFloat32UnsignedInt248Rev;
#else
  static smart_enums::Float32UnsignedInt248RevEnum kFloat32UnsignedInt248Rev;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FragmentShaderEnum kFragmentShader;
#else
  static smart_enums::FragmentShaderEnum kFragmentShader;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FragmentShaderDerivativeHintEnum kFragmentShaderDerivativeHint;
#else
  static smart_enums::FragmentShaderDerivativeHintEnum kFragmentShaderDerivativeHint;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferEnum kFramebuffer;
#else
  static smart_enums::FramebufferEnum kFramebuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferBarrierBitEnum kFramebufferBarrierBit;
#else
  static smart_enums::FramebufferBarrierBitEnum kFramebufferBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_COMPLETE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferCompleteEnum kFramebufferComplete;
#else
  static smart_enums::FramebufferCompleteEnum kFramebufferComplete;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferIncompleteAttachmentEnum kFramebufferIncompleteAttachment;
#else
  static smart_enums::FramebufferIncompleteAttachmentEnum kFramebufferIncompleteAttachment;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferIncompleteDrawBufferEnum kFramebufferIncompleteDrawBuffer;
#else
  static smart_enums::FramebufferIncompleteDrawBufferEnum kFramebufferIncompleteDrawBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferIncompleteLayerTargetsEnum kFramebufferIncompleteLayerTargets;
#else
  static smart_enums::FramebufferIncompleteLayerTargetsEnum kFramebufferIncompleteLayerTargets;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferIncompleteMissingAttachmentEnum kFramebufferIncompleteMissingAttachment;
#else
  static smart_enums::FramebufferIncompleteMissingAttachmentEnum kFramebufferIncompleteMissingAttachment;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferIncompleteMultisampleEnum kFramebufferIncompleteMultisample;
#else
  static smart_enums::FramebufferIncompleteMultisampleEnum kFramebufferIncompleteMultisample;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferIncompleteReadBufferEnum kFramebufferIncompleteReadBuffer;
#else
  static smart_enums::FramebufferIncompleteReadBufferEnum kFramebufferIncompleteReadBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_SRGB)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferSrgbEnum kFramebufferSrgb;
#else
  static smart_enums::FramebufferSrgbEnum kFramebufferSrgb;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNDEFINED)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferUndefinedEnum kFramebufferUndefined;
#else
  static smart_enums::FramebufferUndefinedEnum kFramebufferUndefined;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_UNSUPPORTED)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FramebufferUnsupportedEnum kFramebufferUnsupported;
#else
  static smart_enums::FramebufferUnsupportedEnum kFramebufferUnsupported;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FrontEnum kFront;
#else
  static smart_enums::FrontEnum kFront;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FrontAndBackEnum kFrontAndBack;
#else
  static smart_enums::FrontAndBackEnum kFrontAndBack;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_LEFT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FrontLeftEnum kFrontLeft;
#else
  static smart_enums::FrontLeftEnum kFrontLeft;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_RIGHT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FrontRightEnum kFrontRight;
#else
  static smart_enums::FrontRightEnum kFrontRight;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_ADD)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FuncAddEnum kFuncAdd;
#else
  static smart_enums::FuncAddEnum kFuncAdd;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_REVERSE_SUBTRACT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FuncReverseSubtractEnum kFuncReverseSubtract;
#else
  static smart_enums::FuncReverseSubtractEnum kFuncReverseSubtract;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FUNC_SUBTRACT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::FuncSubtractEnum kFuncSubtract;
#else
  static smart_enums::FuncSubtractEnum kFuncSubtract;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEOMETRY_SHADER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::GeometryShaderEnum kGeometryShader;
#else
  static smart_enums::GeometryShaderEnum kGeometryShader;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::GequalEnum kGequal;
#else
  static smart_enums::GequalEnum kGequal;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::GreaterEnum kGreater;
#else
  static smart_enums::GreaterEnum kGreater;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::GreenEnum kGreen;
#else
  static smart_enums::GreenEnum kGreen;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREEN_INTEGER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::GreenIntegerEnum kGreenInteger;
#else
  static smart_enums::GreenIntegerEnum kGreenInteger;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_HALF_FLOAT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::HalfFloatEnum kHalfFloat;
#else
  static smart_enums::HalfFloatEnum kHalfFloat;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::IncrEnum kIncr;
#else
  static smart_enums::IncrEnum kIncr;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::IncrWrapEnum kIncrWrap;
#else
  static smart_enums::IncrWrapEnum kIncrWrap;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::IntEnum kInt;
#else
  static smart_enums::IntEnum kInt;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::InvalidEnumEnum kInvalidEnum;
#else
  static smart_enums::InvalidEnumEnum kInvalidEnum;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::InvalidFramebufferOperationEnum kInvalidFramebufferOperation;
#else
  static smart_enums::InvalidFramebufferOperationEnum kInvalidFramebufferOperation;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::InvalidOperationEnum kInvalidOperation;
#else
  static smart_enums::InvalidOperationEnum kInvalidOperation;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::InvalidValueEnum kInvalidValue;
#else
  static smart_enums::InvalidValueEnum kInvalidValue;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::InvertEnum kInvert;
#else
  static smart_enums::InvertEnum kInvert;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::KeepEnum kKeep;
#else
  static smart_enums::KeepEnum kKeep;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LastVertexConventionEnum kLastVertexConvention;
#else
  static smart_enums::LastVertexConventionEnum kLastVertexConvention;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEFT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LeftEnum kLeft;
#else
  static smart_enums::LeftEnum kLeft;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LequalEnum kLequal;
#else
  static smart_enums::LequalEnum kLequal;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LessEnum kLess;
#else
  static smart_enums::LessEnum kLess;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LineEnum kLine;
#else
  static smart_enums::LineEnum kLine;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LinearEnum kLinear;
#else
  static smart_enums::LinearEnum kLinear;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_LINEAR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LinearMipmapLinearEnum kLinearMipmapLinear;
#else
  static smart_enums::LinearMipmapLinearEnum kLinearMipmapLinear;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_NEAREST)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LinearMipmapNearestEnum kLinearMipmapNearest;
#else
  static smart_enums::LinearMipmapNearestEnum kLinearMipmapNearest;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LinesEnum kLines;
#else
  static smart_enums::LinesEnum kLines;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LinesAdjacencyEnum kLinesAdjacency;
#else
  static smart_enums::LinesAdjacencyEnum kLinesAdjacency;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LineLoopEnum kLineLoop;
#else
  static smart_enums::LineLoopEnum kLineLoop;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LineSmoothEnum kLineSmooth;
#else
  static smart_enums::LineSmoothEnum kLineSmooth;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH_HINT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LineSmoothHintEnum kLineSmoothHint;
#else
  static smart_enums::LineSmoothHintEnum kLineSmoothHint;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LineStripEnum kLineStrip;
#else
  static smart_enums::LineStripEnum kLineStrip;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::LineStripAdjacencyEnum kLineStripAdjacency;
#else
  static smart_enums::LineStripAdjacencyEnum kLineStripAdjacency;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_COHERENT_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MapCoherentBitEnum kMapCoherentBit;
#else
  static smart_enums::MapCoherentBitEnum kMapCoherentBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_FLUSH_EXPLICIT_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MapFlushExplicitBitEnum kMapFlushExplicitBit;
#else
  static smart_enums::MapFlushExplicitBitEnum kMapFlushExplicitBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_BUFFER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MapInvalidateBufferBitEnum kMapInvalidateBufferBit;
#else
  static smart_enums::MapInvalidateBufferBitEnum kMapInvalidateBufferBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_INVALIDATE_RANGE_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MapInvalidateRangeBitEnum kMapInvalidateRangeBit;
#else
  static smart_enums::MapInvalidateRangeBitEnum kMapInvalidateRangeBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_PERSISTENT_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MapPersistentBitEnum kMapPersistentBit;
#else
  static smart_enums::MapPersistentBitEnum kMapPersistentBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_READ_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MapReadBitEnum kMapReadBit;
#else
  static smart_enums::MapReadBitEnum kMapReadBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_UNSYNCHRONIZED_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MapUnsynchronizedBitEnum kMapUnsynchronizedBit;
#else
  static smart_enums::MapUnsynchronizedBitEnum kMapUnsynchronizedBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAP_WRITE_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MapWriteBitEnum kMapWriteBit;
#else
  static smart_enums::MapWriteBitEnum kMapWriteBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MAX)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MaxEnum kMax;
#else
  static smart_enums::MaxEnum kMax;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIN)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MinEnum kMin;
#else
  static smart_enums::MinEnum kMin;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MIRRORED_REPEAT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MirroredRepeatEnum kMirroredRepeat;
#else
  static smart_enums::MirroredRepeatEnum kMirroredRepeat;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MULTISAMPLE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::MultisampleEnum kMultisample;
#else
  static smart_enums::MultisampleEnum kMultisample;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::NandEnum kNand;
#else
  static smart_enums::NandEnum kNand;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::NearestEnum kNearest;
#else
  static smart_enums::NearestEnum kNearest;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_LINEAR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::NearestMipmapLinearEnum kNearestMipmapLinear;
#else
  static smart_enums::NearestMipmapLinearEnum kNearestMipmapLinear;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_NEAREST)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::NearestMipmapNearestEnum kNearestMipmapNearest;
#else
  static smart_enums::NearestMipmapNearestEnum kNearestMipmapNearest;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::NeverEnum kNever;
#else
  static smart_enums::NeverEnum kNever;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NICEST)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::NicestEnum kNicest;
#else
  static smart_enums::NicestEnum kNicest;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::NoneEnum kNone;
#else
  static smart_enums::NoneEnum kNone;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::NoopEnum kNoop;
#else
  static smart_enums::NoopEnum kNoop;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::NorEnum kNor;
#else
  static smart_enums::NorEnum kNor;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::NotequalEnum kNotequal;
#else
  static smart_enums::NotequalEnum kNotequal;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::NoErrorEnum kNoError;
#else
  static smart_enums::NoErrorEnum kNoError;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OneEnum kOne;
#else
  static smart_enums::OneEnum kOne;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_ALPHA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OneMinusConstantAlphaEnum kOneMinusConstantAlpha;
#else
  static smart_enums::OneMinusConstantAlphaEnum kOneMinusConstantAlpha;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_CONSTANT_COLOR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OneMinusConstantColorEnum kOneMinusConstantColor;
#else
  static smart_enums::OneMinusConstantColorEnum kOneMinusConstantColor;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_ALPHA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OneMinusDstAlphaEnum kOneMinusDstAlpha;
#else
  static smart_enums::OneMinusDstAlphaEnum kOneMinusDstAlpha;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_DST_COLOR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OneMinusDstColorEnum kOneMinusDstColor;
#else
  static smart_enums::OneMinusDstColorEnum kOneMinusDstColor;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_ALPHA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OneMinusSrc1AlphaEnum kOneMinusSrc1Alpha;
#else
  static smart_enums::OneMinusSrc1AlphaEnum kOneMinusSrc1Alpha;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC1_COLOR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OneMinusSrc1ColorEnum kOneMinusSrc1Color;
#else
  static smart_enums::OneMinusSrc1ColorEnum kOneMinusSrc1Color;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_ALPHA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OneMinusSrcAlphaEnum kOneMinusSrcAlpha;
#else
  static smart_enums::OneMinusSrcAlphaEnum kOneMinusSrcAlpha;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ONE_MINUS_SRC_COLOR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OneMinusSrcColorEnum kOneMinusSrcColor;
#else
  static smart_enums::OneMinusSrcColorEnum kOneMinusSrcColor;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OrEnum kOr;
#else
  static smart_enums::OrEnum kOr;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OrInvertedEnum kOrInverted;
#else
  static smart_enums::OrInvertedEnum kOrInverted;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OrReverseEnum kOrReverse;
#else
  static smart_enums::OrReverseEnum kOrReverse;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::OutOfMemoryEnum kOutOfMemory;
#else
  static smart_enums::OutOfMemoryEnum kOutOfMemory;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ALIGNMENT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackAlignmentEnum kPackAlignment;
#else
  static smart_enums::PackAlignmentEnum kPackAlignment;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_DEPTH)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackCompressedBlockDepthEnum kPackCompressedBlockDepth;
#else
  static smart_enums::PackCompressedBlockDepthEnum kPackCompressedBlockDepth;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_HEIGHT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackCompressedBlockHeightEnum kPackCompressedBlockHeight;
#else
  static smart_enums::PackCompressedBlockHeightEnum kPackCompressedBlockHeight;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_SIZE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackCompressedBlockSizeEnum kPackCompressedBlockSize;
#else
  static smart_enums::PackCompressedBlockSizeEnum kPackCompressedBlockSize;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_WIDTH)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackCompressedBlockWidthEnum kPackCompressedBlockWidth;
#else
  static smart_enums::PackCompressedBlockWidthEnum kPackCompressedBlockWidth;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_IMAGE_HEIGHT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackImageHeightEnum kPackImageHeight;
#else
  static smart_enums::PackImageHeightEnum kPackImageHeight;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_LSB_FIRST)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackLsbFirstEnum kPackLsbFirst;
#else
  static smart_enums::PackLsbFirstEnum kPackLsbFirst;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ROW_LENGTH)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackRowLengthEnum kPackRowLength;
#else
  static smart_enums::PackRowLengthEnum kPackRowLength;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_IMAGES)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackSkipImagesEnum kPackSkipImages;
#else
  static smart_enums::PackSkipImagesEnum kPackSkipImages;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_PIXELS)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackSkipPixelsEnum kPackSkipPixels;
#else
  static smart_enums::PackSkipPixelsEnum kPackSkipPixels;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_ROWS)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackSkipRowsEnum kPackSkipRows;
#else
  static smart_enums::PackSkipRowsEnum kPackSkipRows;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SWAP_BYTES)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PackSwapBytesEnum kPackSwapBytes;
#else
  static smart_enums::PackSwapBytesEnum kPackSwapBytes;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PatchesEnum kPatches;
#else
  static smart_enums::PatchesEnum kPatches;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_BUFFER_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PixelBufferBarrierBitEnum kPixelBufferBarrierBit;
#else
  static smart_enums::PixelBufferBarrierBitEnum kPixelBufferBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_PACK_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PixelPackBufferEnum kPixelPackBuffer;
#else
  static smart_enums::PixelPackBufferEnum kPixelPackBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PIXEL_UNPACK_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PixelUnpackBufferEnum kPixelUnpackBuffer;
#else
  static smart_enums::PixelUnpackBufferEnum kPixelUnpackBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PointEnum kPoint;
#else
  static smart_enums::PointEnum kPoint;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PointsEnum kPoints;
#else
  static smart_enums::PointsEnum kPoints;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_FILL)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PolygonOffsetFillEnum kPolygonOffsetFill;
#else
  static smart_enums::PolygonOffsetFillEnum kPolygonOffsetFill;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_LINE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PolygonOffsetLineEnum kPolygonOffsetLine;
#else
  static smart_enums::PolygonOffsetLineEnum kPolygonOffsetLine;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_POINT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PolygonOffsetPointEnum kPolygonOffsetPoint;
#else
  static smart_enums::PolygonOffsetPointEnum kPolygonOffsetPoint;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PolygonSmoothEnum kPolygonSmooth;
#else
  static smart_enums::PolygonSmoothEnum kPolygonSmooth;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH_HINT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PolygonSmoothHintEnum kPolygonSmoothHint;
#else
  static smart_enums::PolygonSmoothHintEnum kPolygonSmoothHint;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PrimitiveRestartEnum kPrimitiveRestart;
#else
  static smart_enums::PrimitiveRestartEnum kPrimitiveRestart;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART_FIXED_INDEX)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::PrimitiveRestartFixedIndexEnum kPrimitiveRestartFixedIndex;
#else
  static smart_enums::PrimitiveRestartFixedIndexEnum kPrimitiveRestartFixedIndex;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PROGRAM_POINT_SIZE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ProgramPointSizeEnum kProgramPointSize;
#else
  static smart_enums::ProgramPointSizeEnum kProgramPointSize;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R11F_G11F_B10F)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R11FG11FB10FEnum kR11FG11FB10F;
#else
  static smart_enums::R11FG11FB10FEnum kR11FG11FB10F;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R16Enum kR16;
#else
  static smart_enums::R16Enum kR16;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16F)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R16FEnum kR16F;
#else
  static smart_enums::R16FEnum kR16F;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R16IEnum kR16I;
#else
  static smart_enums::R16IEnum kR16I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R16UiEnum kR16Ui;
#else
  static smart_enums::R16UiEnum kR16Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R16_SNORM)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R16SnormEnum kR16Snorm;
#else
  static smart_enums::R16SnormEnum kR16Snorm;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32F)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R32FEnum kR32F;
#else
  static smart_enums::R32FEnum kR32F;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R32IEnum kR32I;
#else
  static smart_enums::R32IEnum kR32I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R32UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R32UiEnum kR32Ui;
#else
  static smart_enums::R32UiEnum kR32Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R3_G3_B2)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R3G3B2Enum kR3G3B2;
#else
  static smart_enums::R3G3B2Enum kR3G3B2;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R8Enum kR8;
#else
  static smart_enums::R8Enum kR8;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R8IEnum kR8I;
#else
  static smart_enums::R8IEnum kR8I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R8UiEnum kR8Ui;
#else
  static smart_enums::R8UiEnum kR8Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_R8_SNORM)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::R8SnormEnum kR8Snorm;
#else
  static smart_enums::R8SnormEnum kR8Snorm;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RASTERIZER_DISCARD)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RasterizerDiscardEnum kRasterizerDiscard;
#else
  static smart_enums::RasterizerDiscardEnum kRasterizerDiscard;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_FRAMEBUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ReadFramebufferEnum kReadFramebuffer;
#else
  static smart_enums::ReadFramebufferEnum kReadFramebuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_ONLY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ReadOnlyEnum kReadOnly;
#else
  static smart_enums::ReadOnlyEnum kReadOnly;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_READ_WRITE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ReadWriteEnum kReadWrite;
#else
  static smart_enums::ReadWriteEnum kReadWrite;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RedEnum kRed;
#else
  static smart_enums::RedEnum kRed;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RED_INTEGER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RedIntegerEnum kRedInteger;
#else
  static smart_enums::RedIntegerEnum kRedInteger;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RENDERBUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RenderbufferEnum kRenderbuffer;
#else
  static smart_enums::RenderbufferEnum kRenderbuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPEAT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RepeatEnum kRepeat;
#else
  static smart_enums::RepeatEnum kRepeat;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ReplaceEnum kReplace;
#else
  static smart_enums::ReplaceEnum kReplace;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RgEnum kRg;
#else
  static smart_enums::RgEnum kRg;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg16Enum kRg16;
#else
  static smart_enums::Rg16Enum kRg16;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16F)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg16FEnum kRg16F;
#else
  static smart_enums::Rg16FEnum kRg16F;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg16IEnum kRg16I;
#else
  static smart_enums::Rg16IEnum kRg16I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg16UiEnum kRg16Ui;
#else
  static smart_enums::Rg16UiEnum kRg16Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG16_SNORM)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg16SnormEnum kRg16Snorm;
#else
  static smart_enums::Rg16SnormEnum kRg16Snorm;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32F)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg32FEnum kRg32F;
#else
  static smart_enums::Rg32FEnum kRg32F;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg32IEnum kRg32I;
#else
  static smart_enums::Rg32IEnum kRg32I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG32UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg32UiEnum kRg32Ui;
#else
  static smart_enums::Rg32UiEnum kRg32Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg8Enum kRg8;
#else
  static smart_enums::Rg8Enum kRg8;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg8IEnum kRg8I;
#else
  static smart_enums::Rg8IEnum kRg8I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg8UiEnum kRg8Ui;
#else
  static smart_enums::Rg8UiEnum kRg8Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG8_SNORM)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rg8SnormEnum kRg8Snorm;
#else
  static smart_enums::Rg8SnormEnum kRg8Snorm;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RgbEnum kRgb;
#else
  static smart_enums::RgbEnum kRgb;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb10Enum kRgb10;
#else
  static smart_enums::Rgb10Enum kRgb10;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb10A2Enum kRgb10A2;
#else
  static smart_enums::Rgb10A2Enum kRgb10A2;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB10_A2UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb10A2UiEnum kRgb10A2Ui;
#else
  static smart_enums::Rgb10A2UiEnum kRgb10A2Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB12)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb12Enum kRgb12;
#else
  static smart_enums::Rgb12Enum kRgb12;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb16Enum kRgb16;
#else
  static smart_enums::Rgb16Enum kRgb16;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16F)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb16FEnum kRgb16F;
#else
  static smart_enums::Rgb16FEnum kRgb16F;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb16IEnum kRgb16I;
#else
  static smart_enums::Rgb16IEnum kRgb16I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb16UiEnum kRgb16Ui;
#else
  static smart_enums::Rgb16UiEnum kRgb16Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB16_SNORM)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb16SnormEnum kRgb16Snorm;
#else
  static smart_enums::Rgb16SnormEnum kRgb16Snorm;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32F)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb32FEnum kRgb32F;
#else
  static smart_enums::Rgb32FEnum kRgb32F;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb32IEnum kRgb32I;
#else
  static smart_enums::Rgb32IEnum kRgb32I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB32UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb32UiEnum kRgb32Ui;
#else
  static smart_enums::Rgb32UiEnum kRgb32Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB4)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb4Enum kRgb4;
#else
  static smart_enums::Rgb4Enum kRgb4;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb5Enum kRgb5;
#else
  static smart_enums::Rgb5Enum kRgb5;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB5_A1)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb5A1Enum kRgb5A1;
#else
  static smart_enums::Rgb5A1Enum kRgb5A1;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb8Enum kRgb8;
#else
  static smart_enums::Rgb8Enum kRgb8;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb8IEnum kRgb8I;
#else
  static smart_enums::Rgb8IEnum kRgb8I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb8UiEnum kRgb8Ui;
#else
  static smart_enums::Rgb8UiEnum kRgb8Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB8_SNORM)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb8SnormEnum kRgb8Snorm;
#else
  static smart_enums::Rgb8SnormEnum kRgb8Snorm;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB9_E5)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgb9E5Enum kRgb9E5;
#else
  static smart_enums::Rgb9E5Enum kRgb9E5;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RgbaEnum kRgba;
#else
  static smart_enums::RgbaEnum kRgba;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA12)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba12Enum kRgba12;
#else
  static smart_enums::Rgba12Enum kRgba12;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba16Enum kRgba16;
#else
  static smart_enums::Rgba16Enum kRgba16;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16F)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba16FEnum kRgba16F;
#else
  static smart_enums::Rgba16FEnum kRgba16F;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba16IEnum kRgba16I;
#else
  static smart_enums::Rgba16IEnum kRgba16I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba16UiEnum kRgba16Ui;
#else
  static smart_enums::Rgba16UiEnum kRgba16Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA16_SNORM)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba16SnormEnum kRgba16Snorm;
#else
  static smart_enums::Rgba16SnormEnum kRgba16Snorm;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA2)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba2Enum kRgba2;
#else
  static smart_enums::Rgba2Enum kRgba2;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32F)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba32FEnum kRgba32F;
#else
  static smart_enums::Rgba32FEnum kRgba32F;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba32IEnum kRgba32I;
#else
  static smart_enums::Rgba32IEnum kRgba32I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA32UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba32UiEnum kRgba32Ui;
#else
  static smart_enums::Rgba32UiEnum kRgba32Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA4)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba4Enum kRgba4;
#else
  static smart_enums::Rgba4Enum kRgba4;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba8Enum kRgba8;
#else
  static smart_enums::Rgba8Enum kRgba8;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8I)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba8IEnum kRgba8I;
#else
  static smart_enums::Rgba8IEnum kRgba8I;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8UI)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba8UiEnum kRgba8Ui;
#else
  static smart_enums::Rgba8UiEnum kRgba8Ui;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA8_SNORM)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Rgba8SnormEnum kRgba8Snorm;
#else
  static smart_enums::Rgba8SnormEnum kRgba8Snorm;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGBA_INTEGER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RgbaIntegerEnum kRgbaInteger;
#else
  static smart_enums::RgbaIntegerEnum kRgbaInteger;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RGB_INTEGER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RgbIntegerEnum kRgbInteger;
#else
  static smart_enums::RgbIntegerEnum kRgbInteger;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RG_INTEGER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RgIntegerEnum kRgInteger;
#else
  static smart_enums::RgIntegerEnum kRgInteger;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RIGHT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::RightEnum kRight;
#else
  static smart_enums::RightEnum kRight;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_COVERAGE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::SampleAlphaToCoverageEnum kSampleAlphaToCoverage;
#else
  static smart_enums::SampleAlphaToCoverageEnum kSampleAlphaToCoverage;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_ONE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::SampleAlphaToOneEnum kSampleAlphaToOne;
#else
  static smart_enums::SampleAlphaToOneEnum kSampleAlphaToOne;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_COVERAGE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::SampleCoverageEnum kSampleCoverage;
#else
  static smart_enums::SampleCoverageEnum kSampleCoverage;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_MASK)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::SampleMaskEnum kSampleMask;
#else
  static smart_enums::SampleMaskEnum kSampleMask;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_SHADING)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::SampleShadingEnum kSampleShading;
#else
  static smart_enums::SampleShadingEnum kSampleShading;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_TEST)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ScissorTestEnum kScissorTest;
#else
  static smart_enums::ScissorTestEnum kScissorTest;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::SetEnum kSet;
#else
  static smart_enums::SetEnum kSet;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ShaderImageAccessBarrierBitEnum kShaderImageAccessBarrierBit;
#else
  static smart_enums::ShaderImageAccessBarrierBitEnum kShaderImageAccessBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ShaderStorageBarrierBitEnum kShaderStorageBarrierBit;
#else
  static smart_enums::ShaderStorageBarrierBitEnum kShaderStorageBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHADER_STORAGE_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ShaderStorageBufferEnum kShaderStorageBuffer;
#else
  static smart_enums::ShaderStorageBufferEnum kShaderStorageBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SHORT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ShortEnum kShort;
#else
  static smart_enums::ShortEnum kShort;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_ALPHA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Src1AlphaEnum kSrc1Alpha;
#else
  static smart_enums::Src1AlphaEnum kSrc1Alpha;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC1_COLOR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Src1ColorEnum kSrc1Color;
#else
  static smart_enums::Src1ColorEnum kSrc1Color;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::SrcAlphaEnum kSrcAlpha;
#else
  static smart_enums::SrcAlphaEnum kSrcAlpha;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_ALPHA_SATURATE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::SrcAlphaSaturateEnum kSrcAlphaSaturate;
#else
  static smart_enums::SrcAlphaSaturateEnum kSrcAlphaSaturate;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRC_COLOR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::SrcColorEnum kSrcColor;
#else
  static smart_enums::SrcColorEnum kSrcColor;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::SrgbEnum kSrgb;
#else
  static smart_enums::SrgbEnum kSrgb;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Srgb8Enum kSrgb8;
#else
  static smart_enums::Srgb8Enum kSrgb8;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB8_ALPHA8)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Srgb8Alpha8Enum kSrgb8Alpha8;
#else
  static smart_enums::Srgb8Alpha8Enum kSrgb8Alpha8;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SRGB_ALPHA)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::SrgbAlphaEnum kSrgbAlpha;
#else
  static smart_enums::SrgbAlphaEnum kSrgbAlpha;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StackOverflowEnum kStackOverflow;
#else
  static smart_enums::StackOverflowEnum kStackOverflow;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StackUnderflowEnum kStackUnderflow;
#else
  static smart_enums::StackUnderflowEnum kStackUnderflow;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_COPY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StaticCopyEnum kStaticCopy;
#else
  static smart_enums::StaticCopyEnum kStaticCopy;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_DRAW)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StaticDrawEnum kStaticDraw;
#else
  static smart_enums::StaticDrawEnum kStaticDraw;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STATIC_READ)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StaticReadEnum kStaticRead;
#else
  static smart_enums::StaticReadEnum kStaticRead;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_ATTACHMENT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StencilAttachmentEnum kStencilAttachment;
#else
  static smart_enums::StencilAttachmentEnum kStencilAttachment;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StencilBufferBitEnum kStencilBufferBit;
#else
  static smart_enums::StencilBufferBitEnum kStencilBufferBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_INDEX)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StencilIndexEnum kStencilIndex;
#else
  static smart_enums::StencilIndexEnum kStencilIndex;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_TEST)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StencilTestEnum kStencilTest;
#else
  static smart_enums::StencilTestEnum kStencilTest;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_COPY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StreamCopyEnum kStreamCopy;
#else
  static smart_enums::StreamCopyEnum kStreamCopy;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_DRAW)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StreamDrawEnum kStreamDraw;
#else
  static smart_enums::StreamDrawEnum kStreamDraw;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STREAM_READ)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::StreamReadEnum kStreamRead;
#else
  static smart_enums::StreamReadEnum kStreamRead;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TableTooLargeEnum kTableTooLarge;
#else
  static smart_enums::TableTooLargeEnum kTableTooLarge;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_CONTROL_SHADER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TessControlShaderEnum kTessControlShader;
#else
  static smart_enums::TessControlShaderEnum kTessControlShader;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TESS_EVALUATION_SHADER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TessEvaluationShaderEnum kTessEvaluationShader;
#else
  static smart_enums::TessEvaluationShaderEnum kTessEvaluationShader;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Texture1DEnum kTexture1D;
#else
  static smart_enums::Texture1DEnum kTexture1D;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_1D_ARRAY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Texture1DArrayEnum kTexture1DArray;
#else
  static smart_enums::Texture1DArrayEnum kTexture1DArray;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Texture2DEnum kTexture2D;
#else
  static smart_enums::Texture2DEnum kTexture2D;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_2D_ARRAY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Texture2DArrayEnum kTexture2DArray;
#else
  static smart_enums::Texture2DArrayEnum kTexture2DArray;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_3D)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::Texture3DEnum kTexture3D;
#else
  static smart_enums::Texture3DEnum kTexture3D;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureBufferEnum kTextureBuffer;
#else
  static smart_enums::TextureBufferEnum kTextureBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_COMPRESSION_HINT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureCompressionHintEnum kTextureCompressionHint;
#else
  static smart_enums::TextureCompressionHintEnum kTextureCompressionHint;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureCubeMapEnum kTextureCubeMap;
#else
  static smart_enums::TextureCubeMapEnum kTextureCubeMap;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureCubeMapNegativeXEnum kTextureCubeMapNegativeX;
#else
  static smart_enums::TextureCubeMapNegativeXEnum kTextureCubeMapNegativeX;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureCubeMapNegativeYEnum kTextureCubeMapNegativeY;
#else
  static smart_enums::TextureCubeMapNegativeYEnum kTextureCubeMapNegativeY;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureCubeMapNegativeZEnum kTextureCubeMapNegativeZ;
#else
  static smart_enums::TextureCubeMapNegativeZEnum kTextureCubeMapNegativeZ;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureCubeMapPositiveXEnum kTextureCubeMapPositiveX;
#else
  static smart_enums::TextureCubeMapPositiveXEnum kTextureCubeMapPositiveX;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureCubeMapPositiveYEnum kTextureCubeMapPositiveY;
#else
  static smart_enums::TextureCubeMapPositiveYEnum kTextureCubeMapPositiveY;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureCubeMapPositiveZEnum kTextureCubeMapPositiveZ;
#else
  static smart_enums::TextureCubeMapPositiveZEnum kTextureCubeMapPositiveZ;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_SEAMLESS)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureCubeMapSeamlessEnum kTextureCubeMapSeamless;
#else
  static smart_enums::TextureCubeMapSeamlessEnum kTextureCubeMapSeamless;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_FETCH_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureFetchBarrierBitEnum kTextureFetchBarrierBit;
#else
  static smart_enums::TextureFetchBarrierBitEnum kTextureFetchBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_RECTANGLE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureRectangleEnum kTextureRectangle;
#else
  static smart_enums::TextureRectangleEnum kTextureRectangle;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_UPDATE_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TextureUpdateBarrierBitEnum kTextureUpdateBarrierBit;
#else
  static smart_enums::TextureUpdateBarrierBitEnum kTextureUpdateBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TransformFeedbackEnum kTransformFeedback;
#else
  static smart_enums::TransformFeedbackEnum kTransformFeedback;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TransformFeedbackBarrierBitEnum kTransformFeedbackBarrierBit;
#else
  static smart_enums::TransformFeedbackBarrierBitEnum kTransformFeedbackBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRANSFORM_FEEDBACK_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TransformFeedbackBufferEnum kTransformFeedbackBuffer;
#else
  static smart_enums::TransformFeedbackBufferEnum kTransformFeedbackBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TrianglesEnum kTriangles;
#else
  static smart_enums::TrianglesEnum kTriangles;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TrianglesAdjacencyEnum kTrianglesAdjacency;
#else
  static smart_enums::TrianglesAdjacencyEnum kTrianglesAdjacency;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TriangleFanEnum kTriangleFan;
#else
  static smart_enums::TriangleFanEnum kTriangleFan;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TriangleStripEnum kTriangleStrip;
#else
  static smart_enums::TriangleStripEnum kTriangleStrip;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::TriangleStripAdjacencyEnum kTriangleStripAdjacency;
#else
  static smart_enums::TriangleStripAdjacencyEnum kTriangleStripAdjacency;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UniformBarrierBitEnum kUniformBarrierBit;
#else
  static smart_enums::UniformBarrierBitEnum kUniformBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNIFORM_BUFFER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UniformBufferEnum kUniformBuffer;
#else
  static smart_enums::UniformBufferEnum kUniformBuffer;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ALIGNMENT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackAlignmentEnum kUnpackAlignment;
#else
  static smart_enums::UnpackAlignmentEnum kUnpackAlignment;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_DEPTH)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackCompressedBlockDepthEnum kUnpackCompressedBlockDepth;
#else
  static smart_enums::UnpackCompressedBlockDepthEnum kUnpackCompressedBlockDepth;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackCompressedBlockHeightEnum kUnpackCompressedBlockHeight;
#else
  static smart_enums::UnpackCompressedBlockHeightEnum kUnpackCompressedBlockHeight;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_SIZE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackCompressedBlockSizeEnum kUnpackCompressedBlockSize;
#else
  static smart_enums::UnpackCompressedBlockSizeEnum kUnpackCompressedBlockSize;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_WIDTH)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackCompressedBlockWidthEnum kUnpackCompressedBlockWidth;
#else
  static smart_enums::UnpackCompressedBlockWidthEnum kUnpackCompressedBlockWidth;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_IMAGE_HEIGHT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackImageHeightEnum kUnpackImageHeight;
#else
  static smart_enums::UnpackImageHeightEnum kUnpackImageHeight;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_LSB_FIRST)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackLsbFirstEnum kUnpackLsbFirst;
#else
  static smart_enums::UnpackLsbFirstEnum kUnpackLsbFirst;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ROW_LENGTH)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackRowLengthEnum kUnpackRowLength;
#else
  static smart_enums::UnpackRowLengthEnum kUnpackRowLength;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_IMAGES)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackSkipImagesEnum kUnpackSkipImages;
#else
  static smart_enums::UnpackSkipImagesEnum kUnpackSkipImages;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_PIXELS)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackSkipPixelsEnum kUnpackSkipPixels;
#else
  static smart_enums::UnpackSkipPixelsEnum kUnpackSkipPixels;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_ROWS)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackSkipRowsEnum kUnpackSkipRows;
#else
  static smart_enums::UnpackSkipRowsEnum kUnpackSkipRows;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SWAP_BYTES)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnpackSwapBytesEnum kUnpackSwapBytes;
#else
  static smart_enums::UnpackSwapBytesEnum kUnpackSwapBytes;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedByteEnum kUnsignedByte;
#else
  static smart_enums::UnsignedByteEnum kUnsignedByte;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_2_3_3_REV)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedByte233RevEnum kUnsignedByte233Rev;
#else
  static smart_enums::UnsignedByte233RevEnum kUnsignedByte233Rev;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_BYTE_3_3_2)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedByte332Enum kUnsignedByte332;
#else
  static smart_enums::UnsignedByte332Enum kUnsignedByte332;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedIntEnum kUnsignedInt;
#else
  static smart_enums::UnsignedIntEnum kUnsignedInt;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10F_11F_11F_REV)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedInt10F11F11FRevEnum kUnsignedInt10F11F11FRev;
#else
  static smart_enums::UnsignedInt10F11F11FRevEnum kUnsignedInt10F11F11FRev;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_10_10_10_2)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedInt1010102Enum kUnsignedInt1010102;
#else
  static smart_enums::UnsignedInt1010102Enum kUnsignedInt1010102;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_24_8)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedInt248Enum kUnsignedInt248;
#else
  static smart_enums::UnsignedInt248Enum kUnsignedInt248;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_2_10_10_10_REV)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedInt2101010RevEnum kUnsignedInt2101010Rev;
#else
  static smart_enums::UnsignedInt2101010RevEnum kUnsignedInt2101010Rev;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_5_9_9_9_REV)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedInt5999RevEnum kUnsignedInt5999Rev;
#else
  static smart_enums::UnsignedInt5999RevEnum kUnsignedInt5999Rev;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedInt8888Enum kUnsignedInt8888;
#else
  static smart_enums::UnsignedInt8888Enum kUnsignedInt8888;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_INT_8_8_8_8_REV)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedInt8888RevEnum kUnsignedInt8888Rev;
#else
  static smart_enums::UnsignedInt8888RevEnum kUnsignedInt8888Rev;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedShortEnum kUnsignedShort;
#else
  static smart_enums::UnsignedShortEnum kUnsignedShort;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_1_5_5_5_REV)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedShort1555RevEnum kUnsignedShort1555Rev;
#else
  static smart_enums::UnsignedShort1555RevEnum kUnsignedShort1555Rev;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedShort4444Enum kUnsignedShort4444;
#else
  static smart_enums::UnsignedShort4444Enum kUnsignedShort4444;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_4_4_4_4_REV)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedShort4444RevEnum kUnsignedShort4444Rev;
#else
  static smart_enums::UnsignedShort4444RevEnum kUnsignedShort4444Rev;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_5_5_1)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedShort5551Enum kUnsignedShort5551;
#else
  static smart_enums::UnsignedShort5551Enum kUnsignedShort5551;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedShort565Enum kUnsignedShort565;
#else
  static smart_enums::UnsignedShort565Enum kUnsignedShort565;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNSIGNED_SHORT_5_6_5_REV)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::UnsignedShort565RevEnum kUnsignedShort565Rev;
#else
  static smart_enums::UnsignedShort565RevEnum kUnsignedShort565Rev;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ARRAY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::VertexArrayEnum kVertexArray;
#else
  static smart_enums::VertexArrayEnum kVertexArray;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::VertexAttribArrayBarrierBitEnum kVertexAttribArrayBarrierBit;
#else
  static smart_enums::VertexAttribArrayBarrierBitEnum kVertexAttribArrayBarrierBit;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_VERTEX_SHADER)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::VertexShaderEnum kVertexShader;
#else
  static smart_enums::VertexShaderEnum kVertexShader;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_WRITE_ONLY)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::WriteOnlyEnum kWriteOnly;
#else
  static smart_enums::WriteOnlyEnum kWriteOnly;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::XorEnum kXor;
#else
  static smart_enums::XorEnum kXor;
#endif
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
#if __has_feature(cxx_constexpr)
  constexpr smart_enums::ZeroEnum kZero;
#else
  static smart_enums::ZeroEnum kZero;
#endif
#endif

} // namespace enums
using namespace enums;
} // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif
