#ifndef OGLWRAP_MESH_ANIMATED_MESH_GENERAL_INL_HPP_
#define OGLWRAP_MESH_ANIMATED_MESH_GENERAL_INL_HPP_

#include "animatedMesh.hpp"

namespace oglwrap {

inline AnimatedMesh::AnimatedMesh(const std::string& filename, unsigned int flags)
  : Mesh(filename, flags)
  , skinning_data_(scene_->mNumMeshes)
  , anim_ended_callback_(nullptr) {
}

inline AnimatedMesh::~AnimatedMesh() {
  for(auto i = anims_.data.begin(); i != anims_.data.end(); i++) {
    delete i->importer;
  }
}

} // namespace oglwrap

#endif // OGLWRAP_MESH_ANIMATED_MESH_GENERAL_INL_HPP_
