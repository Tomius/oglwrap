// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_SHAPES_RECTANGLE_SHAPE_INL_H_
#define OGLWRAP_SHAPES_RECTANGLE_SHAPE_INL_H_

#include "./rectangle_shape.h"

namespace OGLWRAP_NAMESPACE_NAME {

inline RectangleShape::RectangleShape(const std::set<AttributeType>& attribs) {
  std::vector<glm::vec2> data;
  data.reserve(attribs.size()*4);
  void* offset{nullptr};

  Bind(vao_);
  Bind(buffer_);
  for (int i = 0; i < kAttribTypeNum; ++i) {
    AttributeType type = static_cast<AttributeType>(i);
    if (attribs.find(type) != attribs.end()) {
      createAttrib(&data, type);
      VertexAttrib(i).pointer(
          2, DataType::kFloat, false, 0, offset).enable();
      offset = (void*)(data.size() * sizeof(glm::vec2));
    }
  }
  buffer_.data(data);
  Unbind(buffer_);
  Unbind(vao_);
}

inline void RectangleShape::render() {
  Bind(vao_);
  DrawArrays(PrimType::kTriangleStrip, 0, 4);
  Unbind(vao_);
}

inline void RectangleShape::createAttrib(std::vector<glm::vec2>* data,
                                         AttributeType type) {
  switch (type) {
    case kPosition: return createPositions(data);
    case kTexCoord: return createTexCoords(data);
  }
}

inline void RectangleShape::createPositions(std::vector<glm::vec2>* data) {
  const glm::vec2 pos[4] = {
    {-1.0f, -1.0f},
    {-1.0f, +1.0f},
    {+1.0f, -1.0f},
    {+1.0f, +1.0f},
  };

  data->insert(data->end(), std::begin(pos), std::end(pos));
}


inline void RectangleShape::createTexCoords(std::vector<glm::vec2>* data) {
  const glm::vec2 coords[4] = {
    {0.0f, 0.0f},
    {0.0f, 1.0f},
    {1.0f, 0.0f},
    {1.0f, 1.0f}
  };

  data->insert(data->end(), std::begin(coords), std::end(coords));
}

}  // namespace oglwrap

#endif
