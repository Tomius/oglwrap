// Copyright (c) 2014, Tamas Csala

/** @file cube.h
    @brief Implements a cube shape wrapper.
    Note: Several algorithms in this file were borrowed from oglplus.
    See https://github.com/matus-chochlik/oglplus
*/

#ifndef OGLWRAP_SHAPES_CUBE_H_
#define OGLWRAP_SHAPES_CUBE_H_

#include <set>
#include "../buffer.h"
#include "../context.h"
#include "../general.h"
#include "../vertex_attrib.h"

#define GLM_FORCE_RADIANS
#include "../glm/glm/glm.hpp"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/// Class providing vertex attributes and instructions for rendering of a cube.
class Cube {
  VertexArray vao_;
  ArrayBuffer buffer_;

public:
  enum AttributeType {kPosition, kNormal, kTexCoord, kTangent, kAttribTypeNum};

  /// Constructs a cube centered at the origin with the given width, height, depth.
  /** @param w,h,d - The width, height, depth of the cube, respectively. */
  Cube(const std::set<AttributeType>& attribs = {kPosition}) {
    std::vector<glm::vec3> data;
    intptr_t offset[kAttribTypeNum]{};
    if (attribs.find(kPosition) != attribs.end()) {
      offset[kPosition] = data.size()*sizeof(glm::vec3);
      createPositions(&data);
    }

    if (attribs.find(kNormal) != attribs.end()) {
      offset[kNormal] = data.size()*sizeof(glm::vec3);
      createNormals(&data);
    }

    if (attribs.find(kTexCoord) != attribs.end()) {
      offset[kTexCoord] = data.size()*sizeof(glm::vec3);
      createTexCoords(&data);
    }

    if (attribs.find(kTangent) != attribs.end()) {
      offset[kTangent] = data.size()*sizeof(glm::vec3);
      createTangents(&data);
    }

    vao_.bind();
    buffer_.bind();
    buffer_.data(data);
    for (int i = 0; i < kAttribTypeNum; ++i) {
      if (attribs.find(AttributeType(i)) != attribs.end()) {
        gl::VertexAttribArray(i).pointer(3, DataType::kFloat, false, 0,
                                         (const void *)offset[i]).enable();
      }
    }
    vao_.unbind();
  }

  /// Draws the cube.
  /** This call changes the currently active VAO. */
  void render() {
    vao_.bind();
    DrawArrays(PrimType::kTriangles, 0, 108);
    vao_.unbind();
  }

  /// Returns the face winding of the cube created by this class.
  FaceOrientation faceWinding() const {
    return FaceOrientation::kCw;
  }

private:
  /// Creates vertex positions.
  void createPositions(std::vector<glm::vec3>* data) {
    /*       (E)-----(A)
             /|      /|
            / |     / |
          (F)-----(B) |
           | (H)---|-(D)
           | /     | /
           |/      |/
          (G)-----(C)        */

    // Note: Positive Z is towards you!

    glm::vec3 A = {+0.5f, +0.5f, -0.5f};
    glm::vec3 B = {+0.5f, +0.5f, +0.5f};
    glm::vec3 C = {+0.5f, -0.5f, +0.5f};
    glm::vec3 D = {+0.5f, -0.5f, -0.5f};
    glm::vec3 E = {-0.5f, +0.5f, -0.5f};
    glm::vec3 F = {-0.5f, +0.5f, +0.5f};
    glm::vec3 G = {-0.5f, -0.5f, +0.5f};
    glm::vec3 H = {-0.5f, -0.5f, -0.5f};

    const glm::vec3 pos[] = {
      A, D, B,    C, B, D,
      A, B, E,    F, E, B,
      B, C, F,    G, F, C,
      F, G, E,    H, E, G,
      H, G, D,    C, D, G,
      E, H, A,    D, A, H
    };

    data->insert(data->end(), std::begin(pos), std::end(pos));
  }

  /// Creates vertex normals.
  void createNormals(std::vector<glm::vec3>* data) {
    const glm::vec3 n[6] = {
      {+1,  0,  0},
      { 0, +1,  0},
      { 0,  0, +1},
      {-1,  0,  0},
      { 0, -1,  0},
      { 0,  0, -1}
    };

    for (int face = 0; face < 6; ++face) {
      for (int vertex = 0; vertex < 6; ++vertex) {
        data->push_back(n[face]);
      }
    }
  };

  /// Creates vertex texture coordinates.
  void createTexCoords(std::vector<glm::vec3>* data) {
    const float n[6][2] = {
      {+1, +1},
      {+1,  0},
      { 0, +1},
      { 0,  0},
      { 0, +1},
      {+1,  0}
    };

    for (int face = 0; face < 6; ++face) {
      for (int vertex = 0; vertex < 6; ++vertex) {
        data->emplace_back(n[vertex][0], n[vertex][1], face);
      }
    }
  }

  /// Creates vertex tangents.
  void createTangents(std::vector<glm::vec3>* data) {
    const glm::vec3 n[6] = {
      { 0,  0, -1},
      {+1,  0,  0},
      {+1,  0,  0},
      { 0,  0, +1},
      {-1,  0,  0},
      {-1,  0,  0}
    };

    for (int face = 0; face < 6; ++face) {
      for (int vertex = 0; vertex < 6; ++vertex) {
        data->push_back(n[face]);
      }
    }
  }
};

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_SHAPES_CUBE_H_

