/** @file fullScreenPic.hpp
    @brief Implements a rectangle that covers the entire screen.
*/

#ifndef FULLSCREENPIC_HPP
#define FULLSCREENPIC_HPP

namespace oglwrap {

/// Class providing vertex attributes and instructions for rendering of a cube.
class FullScreenPic {
    VertexArray vao;
    ArrayBuffer positions, texcoords;
    bool rdy2draw;
public:

    /// Constructs a rectangle that covers the entire screen.
    FullScreenPic() : rdy2draw(false)
    {}

    /// Creates vertex positions, and uploads it to an attribute array.
    /** Uploads the vertex positions (in NDC) data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer. */
    /// @param attrib - The attribute array to use as destination.
    void setup_positions(VertexAttribArray attrib) {

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

        rdy2draw = true;
    }

    /// Creates vertex texture coordinates, and uploads it to an attribute array.
    /** Uploads the vertex normals data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer. */
    /// @param attrib - The attribute array to use as destination.
    void setup_texCoords(VertexAttribArray attrib) {
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
        if(rdy2draw) {
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

#endif // FULLSCREENPIC_HPP
