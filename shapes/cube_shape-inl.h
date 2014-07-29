// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_SHAPES_CUBE_SHAPE_INL_H_
#define OGLWRAP_SHAPES_CUBE_SHAPE_INL_H_

#include "./cube_shape.h"

namespace OGLWRAP_NAMESPACE_NAME {

inline CubeShape::CubeShape(const std::set<AttributeType>& attribs) {
  std::vector<glm::vec3> data;
  data.reserve(attribs.size()*36);
  void* offset{nullptr};

  Bind(vao_);
  Bind(buffer_);
  for (int i = 0; i < kAttribTypeNum; ++i) {
    AttributeType type = static_cast<AttributeType>(i);
    if (attribs.find(type) != attribs.end()) {
      createAttrib(&data, type);
      VertexAttrib(i).pointer(
          3, DataType::kFloat, false, 0, offset).enable();
      offset = (void*)(data.size() * sizeof(glm::vec3));
    }
  }
  buffer_.data(data);
  Unbind(buffer_);
  Unbind(vao_);
}

inline void CubeShape::render() {
  Bind(vao_);
  DrawArrays(PrimType::kTriangles, 0, 36);
  Unbind(vao_);
}

inline void CubeShape::createAttrib(std::vector<glm::vec3>* data,
                                    AttributeType type) {
  switch (type) {
    case kPosition: return createPositions(data);
    case kNormal:   return createNormals(data);
    case kTexCoord: return createTexCoords(data);
    case kTangent:  return createTangents(data);
  }
}

inline void CubeShape::createPositions(std::vector<glm::vec3>* data) {
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

inline void CubeShape::createNormals(std::vector<glm::vec3>* data) {
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

inline void CubeShape::createTexCoords(std::vector<glm::vec3>* data) {
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

inline void CubeShape::createTangents(std::vector<glm::vec3>* data) {
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

}  // namespace oglwrap

#endif
