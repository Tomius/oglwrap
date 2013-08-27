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
    void Positions(VertexAttribArray attrib) {

        const float pos[4][2] = {
            {-1.0f, -1.0f},
            {-1.0f, +1.0f},
            {+1.0f, -1.0f},
            {+1.0f, +1.0f}
        };

        vao.Bind();
        positions.Bind();
        positions.Data(sizeof(pos), pos);
        attrib.Setup<glm::vec2>().Enable();
        vao.Unbind();

        rdy2draw = true;
    }

    /// Creates vertex texture coordinates, and uploads it to an attribute array.
    /** Uploads the vertex normals data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer. */
    /// @param attrib - The attribute array to use as destination.
    void TexCoords(VertexAttribArray attrib) {
        const float coords[4][2] = {
            {0.0f, 0.0f},
            {0.0f, 1.0f},
            {1.0f, 0.0f},
            {1.0f, 1.0f}
        };

        vao.Bind();
        texcoords.Bind();
        texcoords.Data(sizeof(coords), coords);
        attrib.Setup<glm::vec2>().Enable();
        vao.Unbind();
    }


    /// Draws the cube.
    /** This call changes the currently active VAO. */
    void Draw() {
        if(rdy2draw) {
            vao.Bind();
            gl( DrawArrays(GL_TRIANGLE_STRIP, 0, 4) );
            vao.Unbind();
        }
    }

    /// Returns the face winding of the cube created by this class.
    GLenum FaceWinding() const {
        return GL_CW;
    }
};

} // Namespace oglwrap

#endif // FULLSCREENPIC_HPP
