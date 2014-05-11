/** @file enums.h
    @brief Contains enumeration wrappers for GLenums.
*/

#ifndef OGLWRAP_ENUMS_H_
#define OGLWRAP_ENUMS_H_

#include "config.h"

namespace oglwrap {

inline namespace enums {

namespace _Capability {
enum Capability {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BLEND)
  Blend = GL_BLEND,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLIP_DISTANCE)
  ClipDistance = GL_CLIP_DISTANCE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_LOGIC_OP)
  ColorLogicOp = GL_COLOR_LOGIC_OP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CULL_FACE)
  CullFace = GL_CULL_FACE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT)
  DebugOutput = GL_DEBUG_OUTPUT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEBUG_OUTPUT_SYNCHRONOUS)
  DebugOutputSynchronous = GL_DEBUG_OUTPUT_SYNCHRONOUS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_CLAMP)
  DepthClamp = GL_DEPTH_CLAMP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_TEST)
  DepthTest = GL_DEPTH_TEST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DITHER)
  Dither = GL_DITHER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRAMEBUFFER_SRGB)
  FramebufferSrgb = GL_FRAMEBUFFER_SRGB,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_SMOOTH)
  LineSmooth = GL_LINE_SMOOTH,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_MULTISAMPLE)
  Multisample = GL_MULTISAMPLE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_FILL)
  PolygonOffsetFill = GL_POLYGON_OFFSET_FILL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_LINE)
  PolygonOffsetLine = GL_POLYGON_OFFSET_LINE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_OFFSET_POINT)
  PolgonOffsetPoint = GL_POLYGON_OFFSET_POINT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POLYGON_SMOOTH)
  PolygonSmooth = GL_POLYGON_SMOOTH,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART)
  PrimitiveRestart = GL_PRIMITIVE_RESTART,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PRIMITIVE_RESTART_FIXED_INDEX)
  PrimitiveRestartFixedIndex = GL_PRIMITIVE_RESTART_FIXED_INDEX,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RASTERIZER_DISCARD)
  RasterizerDiscard = GL_RASTERIZER_DISCARD,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_COVERAGE)
  SampleAlphaToCoverage = GL_SAMPLE_ALPHA_TO_COVERAGE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_ALPHA_TO_ONE)
  SampleAlphaToOne = GL_SAMPLE_ALPHA_TO_ONE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_COVERAGE)
  SampleCoverage = GL_SAMPLE_COVERAGE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_SHADING)
  SampleShading = GL_SAMPLE_SHADING,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SAMPLE_MASK)
  SampleMask = GL_SAMPLE_MASK,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SCISSOR_TEST)
  ScissorTest = GL_SCISSOR_TEST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_TEST)
  StencilTest = GL_STENCIL_TEST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TEXTURE_CUBE_MAP_SEAMLESS)
  TextureCubeMapSeamless = GL_TEXTURE_CUBE_MAP_SEAMLESS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PROGRAM_POINT_SIZE)
  ProgramPointSize = GL_PROGRAM_POINT_SIZE,
#endif
};
}
typedef _Capability::Capability Capability;

namespace _GLError {
enum GLError {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NO_ERROR)
  NoError = GL_NO_ERROR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_ENUM)
  InvalidEnum = GL_INVALID_ENUM,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_VALUE)
  InvalidValue = GL_INVALID_VALUE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_OPERATION)
  InvalidOperation = GL_INVALID_OPERATION,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_OVERFLOW)
  StackOverflow = GL_STACK_OVERFLOW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STACK_UNDERFLOW)
  StackUnderflow = GL_STACK_UNDERFLOW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OUT_OF_MEMORY)
  OutOfMemory = GL_OUT_OF_MEMORY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVALID_FRAMEBUFFER_OPERATION)
  InvalidFramebufferOperation = GL_INVALID_FRAMEBUFFER_OPERATION,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TABLE_TOO_LARGE)
  TableTooLarge = GL_TABLE_TOO_LARGE,
#endif
};
}
typedef _GLError::GLError GLError;

namespace _ColorBuffer {
enum ColorBuffer {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NONE)
  None = GL_NONE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_LEFT)
  FrontLeft = GL_FRONT_LEFT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_RIGHT)
  FrontRight = GL_FRONT_RIGHT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_LEFT)
  BackLeft = GL_BACK_LEFT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK_RIGHT)
  BackRight = GL_BACK_RIGHT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
  Front = GL_FRONT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
  Back = GL_BACK,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEFT)
  Left = GL_LEFT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_RIGHT)
  Right = GL_RIGHT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
  FrontAndBack = GL_FRONT_AND_BACK,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT0)
  Color0 = GL_COLOR_ATTACHMENT0,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT1)
  Color1 = GL_COLOR_ATTACHMENT1,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT2)
  Color2 = GL_COLOR_ATTACHMENT2,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT3)
  Color3 = GL_COLOR_ATTACHMENT3,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT4)
  Color4 = GL_COLOR_ATTACHMENT4,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT5)
  Color5 = GL_COLOR_ATTACHMENT5,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT6)
  Color6 = GL_COLOR_ATTACHMENT6,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT7)
  Color7 = GL_COLOR_ATTACHMENT7,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT8)
  Color8 = GL_COLOR_ATTACHMENT8,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT9)
  Color9 = GL_COLOR_ATTACHMENT9,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT10)
  Color10 = GL_COLOR_ATTACHMENT10,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT11)
  Color11 = GL_COLOR_ATTACHMENT11,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT12)
  Color12 = GL_COLOR_ATTACHMENT12,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT13)
  Color13 = GL_COLOR_ATTACHMENT13,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT14)
  Color14 = GL_COLOR_ATTACHMENT14,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_ATTACHMENT15)
  Color15 = GL_COLOR_ATTACHMENT15,
#endif
};
}
typedef _ColorBuffer::ColorBuffer ColorBuffer;

namespace _Face {
enum Face {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT)
  Front = GL_FRONT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_BACK)
  Back = GL_BACK,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FRONT_AND_BACK)
  FrontAndBack = GL_FRONT_AND_BACK,
#endif
};
}
typedef _Face::Face Face;

namespace _FaceOrientation {
enum FaceOrientation {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CW)
  CW = GL_CW,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CCW)
  CCW = GL_CCW,
#endif
};
}
typedef _FaceOrientation::FaceOrientation FaceOrientation;

namespace _PolyMode {
enum PolyMode {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINT)
  Point = GL_POINT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE)
  Line = GL_LINE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FILL)
  Fill = GL_FILL,
#endif
};
}
typedef _PolyMode::PolyMode PolyMode;

namespace _ProvokeMode {
enum ProvokeMode {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
  FirstVertexConvention = GL_FIRST_VERTEX_CONVENTION,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
  LastVertexConvention = GL_LAST_VERTEX_CONVENTION,
#endif
};
}
typedef _ProvokeMode::ProvokeMode ProvokeMode;

namespace _PrimitiveType {
enum PrimitiveType {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
  Points = GL_POINTS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
  Lines = GL_LINES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP)
  LineStrip = GL_LINE_STRIP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_LOOP)
  LineLoop = GL_LINE_LOOP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
  Triangles = GL_TRIANGLES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP)
  TriangleStrip = GL_TRIANGLE_STRIP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_FAN)
  TriangleFan = GL_TRIANGLE_FAN,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES_ADJACENCY)
  LinesAdjacency = GL_LINES_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINE_STRIP_ADJACENCY)
  LineStripAdjacency = GL_LINE_STRIP_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES_ADJACENCY)
  TrianglesAdjacency = GL_TRIANGLES_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLE_STRIP_ADJACENCY)
  TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PATCHES)
  Patches = GL_PATCHES,
#endif
};
}
typedef _PrimitiveType::PrimitiveType PrimitiveType;
typedef PrimitiveType PrimType;

namespace _CompareFunction {
enum CompareFunction {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LEQUAL)
  LEqual = GL_LEQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GEQUAL)
  GEqual = GL_GEQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LESS)
  Less = GL_LESS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_GREATER)
  Greater = GL_GREATER,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUAL)
  Equal = GL_EQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOTEQUAL)
  NotEqual = GL_NOTEQUAL,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ALWAYS)
  Always = GL_ALWAYS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEVER)
  Never = GL_NEVER,
#endif
};
}
typedef _CompareFunction::CompareFunction CompareFunction;

namespace _StencilOperation {
enum StencilOperation {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_KEEP)
  Keep = GL_KEEP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_ZERO)
  Zero = GL_ZERO,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_REPLACE)
  Replace = GL_REPLACE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR)
  Incr = GL_INCR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR)
  Decr = GL_DECR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
  Invert = GL_INVERT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INCR_WRAP)
  IncrWrap = GL_INCR_WRAP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DECR_WRAP)
  DecrWrap = GL_DECR_WRAP,
#endif
};
}
typedef _StencilOperation::StencilOperation StencilOperation;

namespace _ColorLogicOperation {
enum ColorLogicOperation {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_CLEAR)
  Clear = GL_CLEAR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_SET)
  Set = GL_SET,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_INVERT)
  Invert = GL_INVERT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOOP)
  Noop = GL_NOOP,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND)
  And = GL_AND,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_REVERSE)
  AndReverse = GL_AND_REVERSE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_AND_INVERTED)
  AndInverted= GL_AND_INVERTED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NAND)
  Nand = GL_NAND,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR)
  Or = GL_OR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_REVERSE)
  OrReverse = GL_OR_REVERSE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_OR_INVERTED)
  OrInverted = GL_OR_INVERTED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_XOR)
  Xor = GL_XOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NOR)
  Nor = GL_NOR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY)
  Copy = GL_COPY,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COPY_INVERTED)
  CopyInverted = GL_COPY_INVERTED,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_EQUIV)
  Equiv = GL_EQUIV,
#endif
};
}
typedef _ColorLogicOperation::ColorLogicOperation ColorLogicOperation;

namespace _PixelStorageMode {
enum PixelStorageMode {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SWAP_BYTES)
  PackSwapBytes = GL_PACK_SWAP_BYTES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_LSB_FIRST)
  PackLsbFirst = GL_PACK_LSB_FIRST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ROW_LENGTH)
  PackRowLength = GL_PACK_ROW_LENGTH,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_ROWS)
  PackSkipRows = GL_PACK_SKIP_ROWS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_PIXELS)
  PackSkipPixels = GL_PACK_SKIP_PIXELS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_ALIGNMENT)
  PackAlignment = GL_PACK_ALIGNMENT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_IMAGE_HEIGHT)
  PackImageHeight = GL_PACK_IMAGE_HEIGHT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_SKIP_IMAGES)
  PackSkipImages = GL_PACK_SKIP_IMAGES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_WIDTH)
  PackCompressedBlockWidth = GL_PACK_COMPRESSED_BLOCK_WIDTH,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_HEIGHT)
  PackCompressedBlockHeight = GL_PACK_COMPRESSED_BLOCK_HEIGHT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_DEPTH)
  PackCompressedBlockDepth = GL_PACK_COMPRESSED_BLOCK_DEPTH,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_PACK_COMPRESSED_BLOCK_SIZE)
  PackCompressedBlockSize = GL_PACK_COMPRESSED_BLOCK_SIZE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_WIDTH)
  UnpackCompressedBlockWidth = GL_UNPACK_COMPRESSED_BLOCK_WIDTH,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT)
  UnpackCompressedBlockHeight = GL_UNPACK_COMPRESSED_BLOCK_HEIGHT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_DEPTH)
  UnpackCompressedBlockDepth = GL_UNPACK_COMPRESSED_BLOCK_DEPTH,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_COMPRESSED_BLOCK_SIZE)
  UnpackCompressedBlockSize = GL_UNPACK_COMPRESSED_BLOCK_SIZE,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SWAP_BYTES)
  UnpackSwapBytes = GL_UNPACK_SWAP_BYTES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_LSB_FIRST)
  UnpackLsbFirst = GL_UNPACK_LSB_FIRST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ROW_LENGTH)
  UnpackRowLength = GL_UNPACK_ROW_LENGTH,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_ROWS)
  UnpackSkipRows = GL_UNPACK_SKIP_ROWS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_PIXELS)
  UnpackSkipPixels = GL_UNPACK_SKIP_PIXELS,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_ALIGNMENT)
  UnpackAlignment = GL_UNPACK_ALIGNMENT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_IMAGE_HEIGHT)
  UnpackImageHeight = GL_UNPACK_IMAGE_HEIGHT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_UNPACK_SKIP_IMAGES)
  UnpackSkipImages = GL_UNPACK_SKIP_IMAGES,
#endif
};
}
typedef _PixelStorageMode::PixelStorageMode PixelStorageMode;

namespace _BlitFilter {
enum BlitFilter {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
  Nearest = GL_NEAREST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
  Linear = GL_LINEAR,
#endif
};
}
typedef _BlitFilter::BlitFilter BlitFilter;

namespace _BufferSelectBit {
enum BufferSelectBit {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_COLOR_BUFFER_BIT)
  ColorBuffer = GL_COLOR_BUFFER_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_DEPTH_BUFFER_BIT)
  DepthBuffer = GL_DEPTH_BUFFER_BIT,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_STENCIL_BUFFER_BIT)
  StencilBuffer = GL_STENCIL_BUFFER_BIT,
#endif
};
}
typedef _BufferSelectBit::BufferSelectBit BufferSelectBit;

} // Namespace enums

} // Namespace oglwrap

#endif // OGLWRAP_ENUMS_H_
