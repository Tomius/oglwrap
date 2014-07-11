// Copyright (c) 2014, Tamas Csala

/** @file fullScreenPic.h
    @brief Implements a rectangle that covers the entire screen.
*/

#ifndef OGLWRAP_SHAPES_RECTANGLE_H_
#define OGLWRAP_SHAPES_RECTANGLE_H_

#include "../buffer.h"
#include "../context.h"
#include "../vertex_attrib.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/// Class providing vertex attributes and instructions for rendering of a rectangle.
class Rectangle {
  VertexArray vao_;
  ArrayBuffer positions_, tex_coords_;
  bool has_setup_positions_, has_setup_tex_coords_;

 public:
  /// Constructs a rectangle that covers the entire screen.
  Rectangle()
    : has_setup_positions_(false)
    , has_setup_tex_coords_(false)
  {}

  /**
   * @brief Creates vertex positions, and uploads it to an attribute array.
   *
   * Uploads the vertex positions (in NDC) data to an attribute array, and sets
   * it up for use. Calling this function changes the currently active VAO and
   * ArrayBuffer.
   *
   * @param attrib - The attribute array to use as destination.
   */
  void setupPositions(VertexAttribArray attrib) {
    if (!has_setup_positions_) {
      has_setup_positions_ = true;
    } else {
      std::cerr << "Rectangle::setupPositions is called multiple "
                   "times on the same object. If the two calls want to set "
                   "positions up into the same attribute position, then the "
                   "second call is unneccesary. If they want to set the "
                   "positions to different attribute positions then the "
                   "second call would make the first call not work anymore. "
                   "Either way, calling setupPositions multiply times is a "
                   "design error, that should be avoided.";
      std::terminate();
    }

    const float pos[4][2] = {
      {-1.0f, -1.0f},
      {-1.0f, +1.0f},
      {+1.0f, -1.0f},
      {+1.0f, +1.0f}
    };

    vao_.bind();
    positions_.bind();
    positions_.data(sizeof(pos), pos);
    attrib.setup<glm::vec2>().enable();
    vao_.unbind();
  }

  /**
   * @brief Creates vertex texture coordinates, and uploads it to an attribute array.
   *
   * Uploads the vertex normals data to an attribute array, and sets it up for use.
   * Calling this function changes the currently active VAO and ArrayBuffer.
   *
   * @param attrib - The attribute array to use as destination.
   */
  void setupTexCoords(VertexAttribArray attrib, bool upside_down = false) {
    if (!has_setup_tex_coords_) {
      has_setup_tex_coords_ = true;
    } else {
      std::cerr << "Rectangle::setupTexCoords is called multiple "
                   "times on the same object. If the two calls want to set "
                   "tex_coords up into the same attribute position, then the "
                   "second call is unneccesary. If they want to set the "
                   "tex_coords to different attribute positions then the "
                   "second call would make the first call not work anymore. "
                   "Either way, calling setupTexCoords multiply times is a "
                   "design error, that should be avoided.";
      std::terminate();
    }

    const float coords[4][2] = {
      {0.0f, 0.0f},
      {0.0f, 1.0f},
      {1.0f, 0.0f},
      {1.0f, 1.0f}
    };

    const float rev_coords[4][2] = {
      {0.0f, 1.0f},
      {0.0f, 0.0f},
      {1.0f, 1.0f},
      {1.0f, 0.0f}
    };

    vao_.bind();
    tex_coords_.bind();
    tex_coords_.data(sizeof(coords), upside_down ? rev_coords : coords);
    attrib.setup<glm::vec2>().enable();
    vao_.unbind();
  }


  /// Renders the rectangle.
  /** This call changes the currently active VAO. */
  void render() {
    if (has_setup_positions_) {
      vao_.bind();
      DrawArrays(PrimType::kTriangleStrip, 0, 4);
      vao_.unbind();
    }
  }

  /// Returns the face winding of the cube created by this class.
  FaceOrientation faceWinding() const {
    return FaceOrientation::kCw;
  }
};

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif  // OGLWRAP_SHAPES_FULLSCREENRECT_H_
