// Copyright (c) 2014, Tamas Csala

/** @file sphere_shape.h
    @brief Implements a sphere shape wrapper.
*/

#ifndef OGLWRAP_SHAPES_SPHERE_SHAPE_H_
#define OGLWRAP_SHAPES_SPHERE_SHAPE_H_

#include <set>
#include <vector>
#include "../buffer.h"
#include "../context.h"
#include "../vertex_attrib.h"

namespace OGLWRAP_NAMESPACE_NAME {

class SphereShape {
 public:
  enum AttributeType {kPosition, kNormal, kTexCoord, kTangent};

  /// Creates the attribute datas for the sphere, that are requested in the constructor argument.
  explicit SphereShape(const std::set<AttributeType>& attribs = {kPosition},
                      unsigned rings = 12, unsigned segments = 18);

  /// Renders the sphere.
  /** This call changes the currently active VAO. */
  void render();

  /// Returns the face winding of the sphere created by this class.
  FaceOrientation faceWinding() const { return FaceOrientation::kCw; }

  unsigned segments() const { return segments_; }
  unsigned rings() const { return rings_; }

 private:
  VertexArray vao_;
  ArrayBuffer buffer_;
  const unsigned segments_, rings_;
  unsigned vertex_num_;
  static const int kAttribTypeNum = 4;

  GLuint createAttrib(std::vector<float>* data, AttributeType type);
  GLuint createPositions(std::vector<float>* data);
  GLuint createNormals(std::vector<float>* data);
  GLuint createTexCoords(std::vector<float>* data);
  GLuint createTangents(std::vector<float>* data);
};

}  // namespace oglwrap

#include "./sphere_shape-inl.h"

#endif  // OGLWRAP_SHAPES_SPHERE_H_

