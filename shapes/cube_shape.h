// Copyright (c) 2014, Tamas Csala

/** @file cube_shape.h
    @brief Implements a cube shape wrapper.
*/

#ifndef OGLWRAP_SHAPES_CUBE_SHAPE_H_
#define OGLWRAP_SHAPES_CUBE_SHAPE_H_

#include <set>
#include <vector>
#include "../buffer.h"
#include "../context.h"
#include "../vertex_array.h"
#include "../vertex_attrib.h"

namespace OGLWRAP_NAMESPACE_NAME {

class CubeShape {
 public:
  enum AttributeType {kPosition, kNormal, kTexCoord, kTangent};

  /// Creates the attribute datas for the cube, that are requested in the constructor argument.
  explicit CubeShape(const std::set<AttributeType>& attribs = {kPosition});

  /// Renders the cube.
  /** This call changes the currently active VAO. */
  void render();

  /// Returns the face winding of the cube created by this class.
  FaceOrientation faceWinding() const { return FaceOrientation::kCw; }

 private:
  VertexArray vao_;
  ArrayBuffer buffer_;
  static const int kAttribTypeNum = 4;

  static void createAttrib(std::vector<glm::vec3>* data, AttributeType type);
  static void createPositions(std::vector<glm::vec3>* data);
  static void createNormals(std::vector<glm::vec3>* data);
  static void createTexCoords(std::vector<glm::vec3>* data);
  static void createTangents(std::vector<glm::vec3>* data);
};

}  // namespace oglwrap

#include "./cube_shape-inl.h"

#endif  // OGLWRAP_SHAPES_CUBE_H_

