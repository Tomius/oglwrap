#ifndef OGLWRAP_ASSIMP_HPP_
#define OGLWRAP_ASSIMP_HPP_

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/type_ptr.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

// Conversion between oglplus and glm matrices

namespace oglwrap {

/// Converts an assimp aiMatrix4x4 to glm mat4
/// @param m - the matrix to convert
static inline glm::mat4 convertMatrix(const aiMatrix4x4& m) {
  return glm::transpose(glm::make_mat4(&m.a1));
}

/// Converts an assimp aiMatrix3x3 to glm mat4
/// @param m - the matrix to convert
static inline glm::mat4 convertMatrix(const aiMatrix3x3& m) {
  return glm::mat4(glm::transpose(glm::make_mat3(&m.a1)));
}

/// Converts a glm mat4 to an assimp aiMatrix4x4
/// @param m - the matrix to convert
static inline aiMatrix4x4 convertMatrix(const glm::mat4& m) {
  return aiMatrix4x4 {
    m[0][0], m[1][0], m[2][0], m[3][0],
    m[0][1], m[1][1], m[2][1], m[3][1],
    m[0][2], m[1][2], m[2][2], m[3][2],
    m[0][3], m[1][3], m[2][3], m[3][3]
  };
}

}

#endif // OGLWRAP_ASSIMP_HPP_
