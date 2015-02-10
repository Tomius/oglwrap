// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_SHAPES_SPHERE_SHAPE_INL_H_
#define OGLWRAP_SHAPES_SPHERE_SHAPE_INL_H_

#include <set>
#include <vector>
#include <algorithm>
#include "./sphere_shape.h"

namespace OGLWRAP_NAMESPACE_NAME {

inline SphereShape::SphereShape(const std::set<AttributeType>& attribs,
                                unsigned rings, unsigned segments)
    : segments_(segments), rings_(rings), vertex_num_(0) {
  assert(rings_);
  assert(segments_);
  assert(attribs.size());

  std::vector<float> data;
  void* offset{nullptr};

  Bind(vao_);
  Bind(buffer_);
  for (int i = 0; i < kAttribTypeNum; ++i) {
    AttributeType type = static_cast<AttributeType>(i);
    if (attribs.find(type) != attribs.end()) {
      GLuint vertex_per_attrib = createAttrib(&data, type);
      VertexAttrib(i).pointer(
          vertex_per_attrib, DataType::kFloat, false, 0, offset).enable();
      offset = (void*)(data.size() * sizeof(float));
      if (vertex_num_ == 0) { vertex_num_ = data.size() / vertex_per_attrib; }
    }
  }
  buffer_.data(data);
  Unbind(buffer_);
  Unbind(vao_);
}

inline void SphereShape::render() {
  Bind(vao_);
  DrawArrays(PrimType::kTriangleStrip, 0, vertex_num_);
  Unbind(vao_);
}

inline GLuint SphereShape::createAttrib(std::vector<float>* data,
                                        AttributeType type) {
  switch (type) {
    case kPosition: return createPositions(data);
    case kNormal: return createNormals(data);
    case kTexCoord: return createTexCoords(data);
    case kTangent: return createTangents(data);
    default: throw new std::runtime_error("Unsupported AttributeType");
  }
}

static inline glm::vec3 SphericalToDescates(float phi, float theta) {
  return {sin(phi) * cos(theta), cos(phi), sin(phi) * sin(theta)};
}

static inline void vector_push_back(std::vector<float>* data,
                                    const glm::vec2& v) {
  data->push_back(v.x); data->push_back(v.y);
}

static inline void vector_push_back(std::vector<float>* data,
                                    const glm::vec3& v) {
  data->push_back(v.x); data->push_back(v.y); data->push_back(v.z);
}

inline GLuint SphereShape::createPositions(std::vector<float>* data) {
  // One triangle strip per ring, then a degenerate to jump to the next ring
  float ring_step = M_PI / rings_;
  for (unsigned ring = 0; ring != rings_; ++ring) {
    float phi0 = ring * ring_step;
    float phi1 = (ring+1) * ring_step;

    float segment_step = 2*M_PI / segments_;
    for (unsigned segment = 0; segment != segments_ + 1; ++segment) {
      float theta = segment * segment_step;

      vector_push_back(data, SphericalToDescates(phi0, theta)/2.0f);
      vector_push_back(data, SphericalToDescates(phi1, theta)/2.0f);
    }

    // Create a degenerate as primitive restart. Technically one vertex could
    // be enough to restart the primitive, but that would invert the face
    // winding, which is unacceptable.
    vector_push_back(data, SphericalToDescates(phi1, 0)/2.0f);
    vector_push_back(data, SphericalToDescates(phi1, 0)/2.0f);
  }

  return 3;
}

inline GLuint SphereShape::createNormals(std::vector<float>* data) {
  float ring_step = M_PI / rings_;
  for (unsigned ring = 0; ring != rings_; ++ring) {
    float phi0 = ring * ring_step;
    float phi1 = (ring+1) * ring_step;

    float segment_step = 2*M_PI / segments_;
    for (unsigned segment = 0; segment != segments_ + 1; ++segment) {
      float theta = segment * segment_step;

      vector_push_back(data, SphericalToDescates(phi0, theta));
      vector_push_back(data, SphericalToDescates(phi1, theta));
    }

    vector_push_back(data, SphericalToDescates(phi1, 0));
    vector_push_back(data, SphericalToDescates(phi1, 0));
  }

  return 3;
}

inline GLuint SphereShape::createTexCoords(std::vector<float>* data) {
  for (unsigned ring = 0; ring != rings_; ++ring) {
    float s0 = float(ring) / rings_;
    float s1 = float(ring+1) / rings_;

    for (unsigned segment = 0; segment != segments_ + 1; ++segment) {
      float t = float(segment) / segments_;

      vector_push_back(data, glm::vec2(s0, t));
      vector_push_back(data, glm::vec2(s1, t));
    }

    vector_push_back(data, glm::vec2(s1, 0));
    vector_push_back(data, glm::vec2(s1, 0));
  }

  return 2;
}

inline GLuint SphereShape::createTangents(std::vector<float>* data) {
  float ring_step = M_PI / rings_;
  for (unsigned ring = 0; ring != rings_; ++ring) {
    float phi0 = ring * ring_step;
    float phi1 = (ring+1) * ring_step;

    float segment_step = 2*M_PI / segments_;
    for (unsigned segment = 0; segment != segments_ + 1; ++segment) {
      float theta = segment * segment_step;

      vector_push_back(data, SphericalToDescates(phi0 + M_PI_2, theta));
      vector_push_back(data, SphericalToDescates(phi1 + M_PI_2, theta));
    }

    vector_push_back(data, SphericalToDescates(phi1, 0));
    vector_push_back(data, SphericalToDescates(phi1, 0));
  }

  return 3;
}

}  // namespace oglwrap

#endif
