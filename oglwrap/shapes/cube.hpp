#ifndef CUBE_HPP
#define CUBE_HPP

#include <GL/glew.h>
#include "../vertexAttrib.hpp"
#include "../buffer.hpp"

namespace oglwrap {

/// Class providing vertex attributes and instructions for rendering of a cube.
class Cube {
    float w, h, d;

    VertexArray vao;
    Buffer positions, normals, texcoords, tangents;
    bool rdy2draw;

public:

    /// Constructs a cube centered at the origin with the given width, height, depth.
    /// @param w,h,d - The width, height, depth of the cube, respectively.
    Cube(float w = 1.0f, float h = 1.0f, float d = 1.0f)
        : w(w), h(h), d(d), rdy2draw(false)
    {}

    /// Uploads the vertex positions data to an attribute array, and sets it up for use.
    /// Calling this function changes the currently active VAO and Buffer.
    /// @param attrib - The attribute array to use as destination.
    void Position(VertexAttribArray attrib) {

        /*       (F)-----(B)
                 /|      /|
                / |     / |
              (E)-----(A) |
               | (H)---|-(D)
               | /     | /
               |/      |/
              (G)-----(C)        */

        // Note: Positive Z is towards you!

        const float half_w = w/2;
        const float half_h = h/2;
        const float half_d = d/2;

        #define A +half_w, +half_h, +half_d
        #define B +half_w, +half_h, -half_d
        #define C +half_w, -half_h, +half_d
        #define D +half_w, -half_h, -half_d
        #define E -half_w, +half_h, +half_d
        #define F -half_w, +half_h, -half_d
        #define G -half_w, -half_h, +half_d
        #define H -half_w, -half_h, -half_d

        const float pos[108] = {
            A, B, D,    C, A, D,
            A, F, B,    E, F, A,
            A, C, E,    G, E, C,
            E, G, F,    H, F, G,
            H, G, D,    C, D, G,
            F, H, B,    D, B, H
        };

        vao.Bind();
        positions.Bind();
        positions.Data(sizeof(pos), pos);
        attrib.Setup<glm::vec3>().Enable();
        vao.Unbind();

        rdy2draw = true;
    }

    /// Uploads the vertex normals data to an attribute array, and sets it up for use.
    /// Calling this function changes the currently active VAO and Buffer.
    /// @param attrib - The attribute array to use as destination.
    void Normals(VertexAttribArray attrib) {
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
                for(int i = 0; i != 3; ++i) {
                    *iter++ = n[face][i];
                }
            }
        }

        vao.Bind();
        normals.Bind();
        normals.Data(dest);
        attrib.Setup<glm::vec3>().Enable();
        vao.Unbind();
    };

    /// Uploads the vertex normals data to an attribute array, and sets it up for use.
    /// Calling this function changes the currently active VAO and Buffer.
    /// @param attrib - The attribute array to use as destination.
    void TexCoordinates(VertexAttribArray attrib) {

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
                for(int i = 0; i != 3; ++i) {
                    *iter++ = n[vertex][i];
                }
                *iter++ = face;
            }
        }

        vao.Bind();
        texcoords.Bind();
        texcoords.Data(dest);
        attrib.Setup<glm::vec3>().Enable();
        vao.Unbind();
    }

    /// Uploads the tangents normals data to an attribute array, and sets it up for use.
    /// Calling this function changes the currently active VAO and Buffer.
    /// @param attrib - The attribute array to use as destination.
    void Tangents(VertexAttribArray attrib) {
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
                for(int i = 0; i != 3; ++i) {
                    *iter++ = n[face][i];
                }
            }
        }

        vao.Bind();
        tangents.Bind();
        tangents.Data(dest);
        attrib.Setup<glm::vec3>().Enable();
        vao.Unbind();
    }

    void Draw() {
        if(rdy2draw) {
            vao.Bind();
            glDrawArrays(GL_TRIANGLES, 0, 108 * sizeof(float));
            vao.Unbind();
        }
    }

    /// Returns the face winding of the cube created by this class.
    GLenum FaceWinding() const {
        return GL_CW;
    }

    glm::vec3 BondingSphere_Center() const {
        return glm::vec3(0.0f);
    }

    float BondingSphere_Radius() const {
        return sqrt(w*w + h*h + d*d);
    }
};

} // Namespace oglwrap

#endif // CUBE_HPP
