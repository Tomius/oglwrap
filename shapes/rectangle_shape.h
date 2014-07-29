// Copyright (c) 2014, Tamas Csala

/** @file rectangle_shape.h
    @brief Implements an NDC rectangle shape.
*/

#ifndef OGLWRAP_SHAPES_RECTANGLE_SHAPE_H_
#define OGLWRAP_SHAPES_RECTANGLE_SHAPE_H_

#include <set>
#include <vector>
#include "../buffer.h"
#include "../context.h"
#include "../vertex_array.h"
#include "../vertex_attrib.h"

namespace OGLWRAP_NAMESPACE_NAME {

class RectangleShape {
 public:
  enum AttributeType {kPosition, kTexCoord};

  /// Constructs a rectangle that covers the entire screen NDC space.
  explicit RectangleShape(const std::set<AttributeType>& attribs = {kPosition});

  /// Renders the rectangle.
  /** This call changes the currently active VAO. */
  void render();

  /// Returns the face winding of the cube created by this class.
  FaceOrientation faceWinding() const { return FaceOrientation::kCw; }

 private:
  VertexArray vao_;
  ArrayBuffer buffer_;
  static const int kAttribTypeNum = 2;

  static void createAttrib(std::vector<glm::vec2>* data, AttributeType type);
  static void createPositions(std::vector<glm::vec2>* data);
  static void createTexCoords(std::vector<glm::vec2>* data);
};

}  // namespace oglwrap

#include "./rectangle_shape-inl.h"

#endif  // OGLWRAP_SHAPES_FULLSCREENRECT_H_
