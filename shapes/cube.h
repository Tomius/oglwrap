// Copyright (c) 2014, Tamas Csala

/** @file cube.h
    @brief Implements a cube shape wrapper.
    Note: Several algorithms in this file were borrowed from oglplus.
    See https://github.com/matus-chochlik/oglplus
*/

#ifndef OGLWRAP_SHAPES_CUBE_H_
#define OGLWRAP_SHAPES_CUBE_H_

#include "../buffer.h"
#include "../context.h"
#include "../vertex_attrib.h"

#include "../define_internal_macros.h"

namespace oglwrap {

/// Class providing vertex attributes and instructions for rendering of a cube.
class Cube {
  float w, h, d;

  VertexArray vao;
  ArrayBuffer positions, normals, texcoords, tangents;
  bool is_setup_positions_, is_setup_normals_, is_setup_texcoords_, is_setup_tangents;

public:

  /// Constructs a cube centered at the origin with the given width, height, depth.
  /** @param w,h,d - The width, height, depth of the cube, respectively. */
  Cube(float w = 1.0f, float h = 1.0f, float d = 1.0f)
    : w(w), h(h), d(d)
    , is_setup_positions_(false)
    , is_setup_normals_(false)
    , is_setup_texcoords_(false)
    , is_setup_tangents(false)
  {}

private:
  /// Helper class for setupPositions
  struct Vector3 {
    float x, y, z;
  };

public:
  /// Creates vertex positions, and uploads it to an attribute array.
  /** Uploads the vertex positions data to an attribute array, and sets it up for use.
    * Calling this function changes the currently active VAO and ArrayBuffer.
    * @param attrib - The attribute array to use as destination. */
  void setupPositions(VertexAttribArray attrib) {

    if (is_setup_positions_) {
      throw std::logic_error("Cube::setup_position is called multiply times on the same object");
    } else {
      is_setup_positions_ = true;
    }

    /*       (E)-----(A)
             /|      /|
            / |     / |
          (F)-----(B) |
           | (H)---|-(D)
           | /     | /
           |/      |/
          (G)-----(C)        */

    // Note: Positive Z is towards you!

    const float half_w = w/2;
    const float half_h = h/2;
    const float half_d = d/2;


    Vector3 A = {+half_w, +half_h, -half_d};
    Vector3 B = {+half_w, +half_h, +half_d};
    Vector3 C = {+half_w, -half_h, +half_d};
    Vector3 D = {+half_w, -half_h, -half_d};
    Vector3 E = {-half_w, +half_h, -half_d};
    Vector3 F = {-half_w, +half_h, +half_d};
    Vector3 G = {-half_w, -half_h, +half_d};
    Vector3 H = {-half_w, -half_h, -half_d};

    const Vector3 pos[] = {
      A, D, B,    C, B, D,
      A, B, E,    F, E, B,
      B, C, F,    G, F, C,
      F, G, E,    H, E, G,
      H, G, D,    C, D, G,
      E, H, A,    D, A, H
    };

    // Care with -fipa-pure-const flag
    vao.bind();
    positions.bind();
    positions.data(sizeof(pos), pos);
    attrib.setup<glm::vec3>().enable();
    vao.unbind();
  }

  /// Creates vertex normals, and uploads it to an attribute array.
  /** Uploads the vertex normals data to an attribute array, and sets it up for use.
    * Calling this function changes the currently active VAO and ArrayBuffer.
    * @param attrib - The attribute array to use as destination. */
  void setupNormals(VertexAttribArray attrib) {

    if (is_setup_normals_) {
      std::logic_error("Cube::setupNormals is called multiply times on the same object");
    } else {
      is_setup_normals_ = true;
    }

    const float n[6][3] = {
      {+1,  0,  0},
      { 0, +1,  0},
      { 0,  0, +1},
      {-1,  0,  0},
      { 0, -1,  0},
      { 0,  0, -1}
    };

    std::vector<float> dest(108);
    auto iter = dest.begin();
    for (int face = 0; face < 6; ++face) {
      for (int vertex = 0; vertex < 6; ++vertex) {
        for (int i = 0; i < 3; ++i) {
          *iter++ = n[face][i];
        }
      }
    }

    vao.bind();
    normals.bind();
    normals.data(dest);
    attrib.setup<glm::vec3>().enable();
    vao.unbind();
  };

  /// Creates vertex texture coordinates, and uploads it to an attribute array.
  /** Uploads the vertex normals data to an attribute array, and sets it up for use.
    * Calling this function changes the currently active VAO and ArrayBuffer.
    * @param attrib - The attribute array to use as destination. */
  void setupTexCoords(VertexAttribArray attrib) {

    if (is_setup_texcoords_) {
      std::logic_error("Cube::setupTexCoords is called multiply times on the same object");
    } else {
      is_setup_texcoords_ = true;
    }

    const float n[6][2] = {
      {+1, +1},
      {+1,  0},
      { 0, +1},
      { 0,  0},
      { 0, +1},
      {+1,  0}
    };

    std::vector<float> dest(108);
    auto iter = dest.begin();
    for (int face = 0; face < 6; ++face) {
      for (int vertex = 0; vertex < 6; ++vertex) {
        for (int i = 0; i < 2; ++i) {
          *iter++ = n[vertex][i];
        }
        *iter++ = face;
      }
    }

    vao.bind();
    texcoords.bind();
    texcoords.data(dest);
    attrib.setup<glm::vec3>().enable();
    vao.unbind();
  }

  /// Creates vertex tangents, and uploads it to an attribute array.
  /** Uploads the tangents normals data to an attribute array, and sets it up for use.
    * Calling this function changes the currently active VAO and ArrayBuffer.
    * @param attrib - The attribute array to use as destination. */
  void setupTangents(VertexAttribArray attrib) {
    if (is_setup_tangents) {
      std::logic_error("Cube::setupTangents is called multiply times on the same object");
    } else {
      is_setup_tangents = true;
    }

    const float n[6][3] = {
      { 0,  0, -1},
      {+1,  0,  0},
      {+1,  0,  0},
      { 0,  0, +1},
      {-1,  0,  0},
      {-1,  0,  0}
    };

    std::vector<float> dest(108);
    auto iter = dest.begin();
    for (int face = 0; face < 6; ++face) {
      for (int vertex = 0; vertex < 6; ++vertex) {
        for (int i = 0; i < 3; ++i) {
          *iter++ = n[face][i];
        }
      }
    }

    vao.bind();
    tangents.bind();
    tangents.data(dest);
    attrib.setup<glm::vec3>().enable();
    vao.unbind();
  }

  /// Draws the cube.
  /** This call changes the currently active VAO. */
  void render() {
    if (is_setup_positions_) {
      vao.bind();
      Context::DrawArrays(PrimType::Triangles, 0, 108 * sizeof(float));
      vao.unbind();
    }
  }

  /// Returns the face winding of the cube created by this class.
  GLenum faceWinding() const {
    return GL_CW;
  }

  /// Returns the center of the cube's bounding sphere
  glm::vec3 bSphereCenter() const {
    return glm::vec3(0.0f);
  }

  /// Returns the radius of the cube's bounding sphere
  float bSphereRadius() const {
    return sqrt(w*w + h*h + d*d);
  }
};

} // Namespace oglwrap

#include "../undefine_internal_macros.h"

#endif // OGLWRAP_SHAPES_CUBE_H_

