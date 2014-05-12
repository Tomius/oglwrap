// Copyright (c) 2014, Tamas Csala

/** @file enums.h
    @brief Contains enumeration wrappers for GLenums.
*/

#ifndef OGLWRAP_ENUMS_H_
#define OGLWRAP_ENUMS_H_

#include "config.h"

namespace oglwrap {

inline namespace enums {

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
