#ifndef OGLWRAP_MESH_ANIMATED_MESH_GENERAL_INL_HPP_
#define OGLWRAP_MESH_ANIMATED_MESH_GENERAL_INL_HPP_

namespace oglwrap {

AnimatedMesh::AnimatedMesh(const std::string& filename, unsigned int flags)
  : Mesh(filename, flags)
  , skinning_data(scene->mNumMeshes) {

  glm::mat4 matrix = convertMatrix(scene->mRootNode->mTransformation);
  skinning_data.global_inverse_transform = glm::inverse(matrix);
}

AnimatedMesh::~AnimatedMesh() {
  for(auto i = anims.data.begin(); i != anims.data.end(); i++) {
    delete i->importer;
  }
}

} // namespace oglwrap

#endif // OGLWRAP_MESH_ANIMATED_MESH_GENERAL_INL_HPP_
