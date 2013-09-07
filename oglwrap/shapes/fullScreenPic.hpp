/** @file fullScreenPic.hpp
    @brief Implements a rectangle that covers the entire screen.
*/

#pragma once

namespace oglwrap {

/// Class providing vertex attributes and instructions for rendering of a cube.
class FullScreenPic {
    VertexArray vao;
    ArrayBuffer positions, texcoords;
    bool is_setup_positions, is_setup_texcoords;
public:

    /// Constructs a rectangle that covers the entire screen.
    FullScreenPic()
        : is_setup_positions(false)
        , is_setup_texcoords(false)
    {}

    /// Creates vertex positions, and uploads it to an attribute array.
    /** Uploads the vertex positions (in NDC) data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer. */
    /// @param attrib - The attribute array to use as destination.
    void setup_positions(VertexAttribArray attrib) {

        if(is_setup_positions) {
            std::logic_error("FullScreenPic::setup_position is called multiply times on the same object");
        } else {
            is_setup_positions = true;
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
    void setup_texCoords(VertexAttribArray attrib) {

        if(is_setup_texcoords) {
            std::logic_error("FullScreenPic::setup_texCoords is called multiply times on the same object");
        } else {
            is_setup_texcoords = true;
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


    /// Draws the cube.
    /** This call changes the currently active VAO. */
    void draw() {
        if(is_setup_positions) {
            vao.bind();
            gl( DrawArrays(GL_TRIANGLE_STRIP, 0, 4) );
            vao.unbind();
        }
    }

    /// Returns the face winding of the cube created by this class.
    GLenum faceWinding() const {
        return GL_CW;
    }
};

} // Namespace oglwrap

