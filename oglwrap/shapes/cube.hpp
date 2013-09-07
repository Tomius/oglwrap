/** @file cube.hpp
    @brief Implements a cube shape wrapper.
*/

#pragma once

namespace oglwrap {

/// Class providing vertex attributes and instructions for rendering of a cube.
class Cube {
    float w, h, d;

    VertexArray vao;
    ArrayBuffer positions, normals, texcoords, tangents;
    bool is_setup_positions, is_setup_normals, is_setup_texcoords, is_setup_tangents;

public:

    /// @brief Constructs a cube centered at the origin with the given width, height, depth.
    /// @param w,h,d - The width, height, depth of the cube, respectively.
    Cube(float w = 1.0f, float h = 1.0f, float d = 1.0f)
        : w(w), h(h), d(d)
        , is_setup_positions(false)
        , is_setup_normals(false)
        , is_setup_texcoords(false)
        , is_setup_tangents(false)
    {}

private:
    /// Helper class for setupPositions
    struct Vector3{
        float x, y, z;
    };

public:
    /// @brief Creates vertex positions, and uploads it to an attribute array.
    /** Uploads the vertex positions data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer. */
    /// @param attrib - The attribute array to use as destination.
    void setup_positions(VertexAttribArray attrib) {

        if(is_setup_positions) {
            std::logic_error("Cube::setup_position is called multiply times on the same object");
        } else {
            is_setup_positions = true;
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

        vao.bind();
        positions.bind();
        positions.data(sizeof(pos), pos);
        attrib.setup<glm::vec3>().enable();
        vao.unbind();
    }

    /// @brief Creates vertex normals, and uploads it to an attribute array.
    /** Uploads the vertex normals data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer. */
    /// @param attrib - The attribute array to use as destination.
    void setup_normals(VertexAttribArray attrib) {

        if(is_setup_normals) {
            std::logic_error("Cube::setup_normals is called multiply times on the same object");
        } else {
            is_setup_normals = true;
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
        for(int face = 0; face < 6; ++face) {
            for(int vertex = 0; vertex < 6; ++vertex) {
                for(int i = 0; i < 3; ++i) {
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

    /// @brief Creates vertex texture coordinates, and uploads it to an attribute array.
    /** Uploads the vertex normals data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer. */
    /// @param attrib - The attribute array to use as destination.
    void setup_texCoords(VertexAttribArray attrib) {

        if(is_setup_texcoords) {
            std::logic_error("Cube::setup_texCoords is called multiply times on the same object");
        } else {
            is_setup_texcoords = true;
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
        for(int face = 0; face < 6; ++face) {
            for(int vertex = 0; vertex < 6; ++vertex) {
                for(int i = 0; i < 2; ++i) {
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

    /// @brief Creates vertex tangents, and uploads it to an attribute array.
    /** Uploads the tangents normals data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer.
      * @param attrib - The attribute array to use as destination. */
    void setup_tangents(VertexAttribArray attrib) {
        if(is_setup_tangents) {
            std::logic_error("Cube::setup_tangents is called multiply times on the same object");
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
        for(int face = 0; face < 6; ++face) {
            for(int vertex = 0; vertex < 6; ++vertex) {
                for(int i = 0; i < 3; ++i) {
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

    /// @brief Draws the cube.
    /** This call changes the currently active VAO. */
    void draw() {
        if(is_setup_positions) {
            vao.bind();
            gl( DrawArrays(GL_TRIANGLES, 0, 108 * sizeof(float)) );
            vao.unbind();
        }
    }

    /// Returns the face winding of the cube created by this class.
    GLenum faceWinding() const {
        return GL_CW;
    }

    /// Returns the center of the cube's bounding sphere
    glm::vec3 bondingSphere_Center() const {
        return glm::vec3(0.0f);
    }

    /// Returns the radius of the cube's bounding sphere
    float bondingSphere_Radius() const {
        return sqrt(w*w + h*h + d*d);
    }
};

} // Namespace oglwrap
