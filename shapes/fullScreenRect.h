/** @file fullScreenPic.hpp
    @brief Implements a rectangle that covers the entire screen.
*/

#ifndef OGLWRAP_SHAPES_FULLSCREENRECT_H_
#define OGLWRAP_SHAPES_FULLSCREENRECT_H_

#include "../buffer.h"
#include "../context.h"
#include "../vertex_attrib.h"

#include "../define_internal_macros.h"

namespace oglwrap {

/// Class providing vertex attributes and instructions for rendering of a cube.
class FullScreenRectangle {
  VertexArray vao;
  ArrayBuffer positions, texcoords;
  bool is_setup_positions_, is_setup_texcoords_;
public:

  /// Constructs a rectangle that covers the entire screen.
  FullScreenRectangle()
    : is_setup_positions_(false)
    , is_setup_texcoords_(false)
  {}

  /// Creates vertex positions, and uploads it to an attribute array.
  /** Uploads the vertex positions (in NDC) data to an attribute array, and sets it up for use.
    * Calling this function changes the currently active VAO and ArrayBuffer. */
  /// @param attrib - The attribute array to use as destination.
  void setupPositions(VertexAttribArray attrib) {

    if (is_setup_positions_) {
      std::logic_error("FullScreenRectangle::setup_position is called multiply times on the same object");
    } else {
      is_setup_positions_ = true;
    }

    const float pos[4][2] = {
      {-1.0f, -1.0f},
      {-1.0f, +1.0f},
      {+1.0f, -1.0f},
      {+1.0f, +1.0f}
    };

    vao.bind();
    positions.bind();
    positions.data(sizeof(pos), pos);
    attrib.setup<glm::vec2>().enable();
    vao.unbind();
  }

  /// Creates vertex texture coordinates, and uploads it to an attribute array.
  /** Uploads the vertex normals data to an attribute array, and sets it up for use.
    * Calling this function changes the currently active VAO and ArrayBuffer. */
  /// @param attrib - The attribute array to use as destination.
  void setupTexCoords(VertexAttribArray attrib) {

    if (is_setup_texcoords_) {
      std::logic_error("FullScreenRectangle::setupTexCoords is called multiply times on the same object");
    } else {
      is_setup_texcoords_ = true;
    }

    const float coords[4][2] = {
      {0.0f, 0.0f},
      {0.0f, 1.0f},
      {1.0f, 0.0f},
      {1.0f, 1.0f}
    };

    vao.bind();
    texcoords.bind();
    texcoords.data(sizeof(coords), coords);
    attrib.setup<glm::vec2>().enable();
    vao.unbind();
  }


  /// Renders the image.
  /** This call changes the currently active VAO. */
  void render() {
    if (is_setup_positions_) {
      vao.bind();
      Context::DrawArrays(PrimType::TriangleStrip, 0, 4);
      vao.unbind();
    }
  }

  /// Returns the face winding of the cube created by this class.
  GLenum faceWinding() const {
    return GL_CW;
  }
};

} // Namespace oglwrap

#include "../undefine_internal_macros.h"

#endif // OGLWRAP_SHAPES_FULLSCREENRECT_H_
