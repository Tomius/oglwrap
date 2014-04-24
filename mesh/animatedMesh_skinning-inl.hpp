#ifndef OGLWRAP_MESH_ANIMATED_MESH_SKINNING_INL_HPP_
#define OGLWRAP_MESH_ANIMATED_MESH_SKINNING_INL_HPP_

#include "animatedMesh.hpp"

namespace oglwrap {

/// Fills the bone_mapping with data.
inline void AnimatedMesh::mapBones() {
  for(size_t entry = 0; entry < entries_.size(); entry++) {
    const aiMesh* pMesh = scene_->mMeshes[entry];

    for(unsigned i = 0; i < pMesh->mNumBones; i++) {
      std::string bone_name(pMesh->mBones[i]->mName.data);
      size_t bone_index = 0;

      // Search for this bone in the BoneMap
      if(skinning_data_.bone_mapping.find(bone_name) == skinning_data_.bone_mapping.end()) {
        // Allocate an index for the new bone
        bone_index = skinning_data_.num_bones++;
        skinning_data_.bone_info.push_back(SkinningData::BoneInfo());
        skinning_data_.bone_info[bone_index].bone_offset = convertMatrix(pMesh->mBones[i]->mOffsetMatrix);
        skinning_data_.bone_mapping[bone_name] = bone_index;
      }
    }
  }
}

/// A recursive functions that should be started from the root node, and it returns the first bone under it.
/** @param node - The current root node.
  * @param anim - The animation to seek the root bone in. */
inline const aiNodeAnim* AnimatedMesh::getRootBone(const aiNode* node, const aiScene* anim) {
  std::string node_name(node->mName.data);

  const aiAnimation* animation = anim->mAnimations[0];
  const aiNodeAnim* node_anim = findNodeAnim(animation, node_name);

  if(node_anim) {
    if(skinning_data_.root_bone.empty()) {
      skinning_data_.root_bone = node_name;
    } else {
      if(skinning_data_.root_bone != node_name) {
        throw std::runtime_error(
          "Animation error: the animated skeletons have different root bones."
        );
      }
    }
    return node_anim;
  } else {
    for(unsigned i = 0; i < node->mNumChildren; i++) {
      auto childsReturn = getRootBone(node->mChildren[i], anim);
      if(childsReturn) {
        return childsReturn;
      }
    }
  }

  return nullptr;
}

template <class Index_t>
/// Creates bone attributes data.
/** It is a template, as the type of boneIDs shouldn't be fix. Most of the times,
  * a skeleton won't contain more than 256 bones, but that doesn't mean boneIDs
  * should be forced to GLubyte, it works with shorts and even ints too. Although
  * I really doubt anyone would be using a skeleton with more than 65535 bones... */
void AnimatedMesh::loadBones() {

  const size_t per_attrib_size = sizeof(SkinningData::VertexBoneData_PerAttribute<Index_t>);

  skinning_data_.per_mesh_attrib_max.resize(entries_.size());

  for(size_t entry = 0; entry < entries_.size(); entry++) {
    std::vector<SkinningData::VertexBoneData<Index_t>> vertices;
    const aiMesh* pMesh = scene_->mMeshes[entry];
    vertices.resize(pMesh->mNumVertices);

    // -------======{[ Create the bone ID's and weights data ]}======-------

    for(unsigned i = 0; i < pMesh->mNumBones; i++) {
      std::string bone_name(pMesh->mBones[i]->mName.data);
      size_t bone_index = skinning_data_.bone_mapping[bone_name];

      for(unsigned j = 0; j < pMesh->mBones[i]->mNumWeights; j++) {
        unsigned vertexID = pMesh->mBones[i]->mWeights[j].mVertexId;
        float weight = pMesh->mBones[i]->mWeights[j].mWeight;
        vertices[vertexID].AddBoneData(bone_index, weight);
      }
    }

    // -------======{[ Upload the bone data ]}======-------

    entries_[entry].vao.bind();
    skinning_data_.vertex_bone_data_buffers[entry].bind();

    // I can't just upload to the buffer with .data(), as bones aren't stored in a continuous buffer,
    // and it is an array of not fixed sized arrays, but OpenGL needs it in fix sized parts.

    // Get the current number of max bone attributes.
    unsigned char& current_attrib_max = skinning_data_.per_mesh_attrib_max[entry];
    for(size_t i = 0; i < vertices.size(); i++) {
      if(vertices[i].data.size() > current_attrib_max) {
        current_attrib_max = vertices[i].data.size();
      }
    }

    if(current_attrib_max > skinning_data_.max_bone_attrib_num) {
      skinning_data_.max_bone_attrib_num = current_attrib_max;
    }

    size_t per_vertex_size = current_attrib_max * per_attrib_size;
    size_t buffer_size = vertices.size() * per_vertex_size;

#if OGLWRAP_PORTABILITY_MODE // Don't use mapping in portability mode

    // Upload the bones data into a continuous buffer then upload that to OpenGL.
    std::unique_ptr<GLbyte> data{ new GLbyte[buffer_size] };
    GLintptr offset = 0;
    for(size_t i = 0; i < vertices.size(); i++) {
      size_t curr_size = vertices[i].data.size() * per_attrib_size;

      // Copy the bone data
      memcpy(
        data.get() + offset, // destination
        vertices[i].data.data(),  // source
        curr_size // length
      );

      // Zero out all the remaining memory. Remember a
      // bone with a 0.0f weight doesn't have any influence
      if(per_vertex_size > curr_size) {
        memset(
          data.get() + offset + curr_size, // memory place
          0, // value
          per_vertex_size - curr_size // length
        );
      }

      offset += per_vertex_size;
    }

    // upload
    skinning_data_.vertex_bone_data_buffers[entry].data(buffer_size, data.get());

#else // Upload the bones data in continuous, fix-sized parts using mapping.

    // First we have to allocate the buffer's storage.
    vertex_bone_data_buffers[entry].data(buffer_size, (void*)0);

    {
      // The buffer gets unmapped when it's lifetime ends
      ArrayBuffer::Map bones_buffer_map(BufferMapAccess::Write);
      GLintptr offset = 0;
      for(size_t i = 0; i < vertices.size(); i++) {
        size_t curr_size = vertices[i].data.size() * per_attrib_size;

        // Copy the bone data
        memcpy(
          (GLbyte*)bones_buffer_map.data() + offset, // destination
          vertices[i].data.data(),  // source
          curr_size // length
        );

        // Zero out all the remaining memory. Remember a
        // bone with a 0.0f weight doesn't have any influence
        if(per_vertex_size > curr_size) {
          memset(
            (GLbyte*)bones_buffer_map.data() + offset + curr_size, // memory place
            0, // value
            per_vertex_size - curr_size // length
          );
        }

        offset += per_vertex_size;
      }
    }

#endif // OGLWRAP_PORTABILITY_MODE

  }

  // Unbind our things, so they won't be modified from outside
  VertexArray::Unbind();
  ArrayBuffer::Unbind();
}

/// Creates the bone attributes data (the skinning.)
/** It actually just calls the loadBones function with the appropriate template parameter */
inline void AnimatedMesh::createBonesData() {
  mapBones();

  if(skinning_data_.num_bones < UCHAR_MAX) {
    loadBones<unsigned char>();
  } else if(skinning_data_.num_bones < USHRT_MAX) {
    loadBones<unsigned short>();
  } else { // more than 65535 bones? WTF???
    loadBones<unsigned int>();
  }
}

template <class Index_t>
/// Shader plumbs the bone data.
/** It is a template, as the type of boneIDs shouldn't be fix. Most of the times,
  * a skeleton won't contain more than 256 bones, but that doesn't mean boneIDs
  * should be forced to GLubyte, it works with shorts and even ints too. Although
  * I really doubt anyone would be using a skeleton with more than 65535 bones...
  * @param idx_t - The oglwrap enum, naming the data type that should be used.
  * @param boneIDs - Should be an array of attributes, that will be shader plumbed for the boneIDs data.
  * @param bone_weights - Should be an array of attributes, that will be shader plumbed for the bone_weights data.
  * @param integerIDs - If true, boneIDs are uploaded as integers (#version 130+) else they are uploaded as floats */
void AnimatedMesh::shaderPlumbBones(DataType idx_t, LazyVertexAttribArray boneIDs,
                                    LazyVertexAttribArray bone_weights, bool integerIDs) {
  const size_t per_attrib_size = sizeof(SkinningData::VertexBoneData_PerAttribute<Index_t>);

  for(size_t entry = 0; entry < entries_.size(); entry++) {

    entries_[entry].vao.bind();
    skinning_data_.vertex_bone_data_buffers[entry].bind();
    unsigned char current_attrib_max = skinning_data_.per_mesh_attrib_max[entry];

    for(unsigned char boneAttribSet = 0; boneAttribSet < current_attrib_max; boneAttribSet++) {
      const size_t stride = current_attrib_max * per_attrib_size;

      intptr_t baseOffset = boneAttribSet * per_attrib_size;
      intptr_t weightOffset = baseOffset + 4 * sizeof(Index_t);

      if(integerIDs) {
        boneIDs[boneAttribSet].ipointer(4, WholeDataType(idx_t), stride, (const void*)baseOffset).enable();
      } else {
        boneIDs[boneAttribSet].pointer(4, idx_t, false, stride, (const void*)baseOffset).enable();
      }
      bone_weights[boneAttribSet].setup(4, DataType::Float, stride, (const void*)weightOffset).enable();
    }

    // static setup the VertexArrays that aren't enabled, to all zero.
    // Remember (0, 0, 0, 1) is the default, which isn't what we want.
    for(int i = current_attrib_max; i < skinning_data_.max_bone_attrib_num; i++) {
      if(integerIDs) {
        boneIDs[i].static_setup(glm::ivec4(0, 0, 0, 0));
      } else {
        boneIDs[i].static_setup(glm::vec4(0, 0, 0, 0));
      }
      bone_weights[i].static_setup(glm::vec4(0, 0, 0, 0));
    }
  }

  // Unbind our things, so they won't be modified from outside
  VertexArray::Unbind();
  ArrayBuffer::Unbind();
}

/// Returns the first node called \a name, who is under \a currentRoot in the bone hierarchy.
/** Note: this function is recursive
  * @param currentRoot - The bone under which to search.
  * @param name - The name of the bone that is to be found.
  * @return the handle to the bone that is called name, or nullptr. */
inline aiNode* AnimatedMesh::findNode(aiNode* currentRoot, const std::string& name) {
  if(currentRoot->mName.data == name)
    return currentRoot;

  for(int i = 0; i != currentRoot->mNumChildren; ++i) {
    aiNode* children_return = findNode(currentRoot->mChildren[i], name);
    if(children_return)
      return children_return;
  }

  return nullptr;
}

/// Marks all of a bone's child external recursively.
/** @param parent - A pointer to the parent ExternalBone struct.
    @param node - The current node.
    @param should_be_external - Should be false if called from outside, true if called recursively. */
inline ExternalBone AnimatedMesh::markChildExternal(ExternalBone* parent, aiNode* node, bool should_be_external) {
  size_t bidx = skinning_data_.bone_mapping[node->mName.data];
  SkinningData::BoneInfo& binfo = skinning_data_.bone_info[bidx];
  binfo.external = should_be_external;
  ExternalBone ebone(
    node->mName.data,
    binfo.bone_offset,
    convertMatrix(node->mTransformation),
    binfo.final_transform,
    parent
  );

  for(int i = 0; i < node->mNumChildren; ++i) {
    ebone.child.push_back(markChildExternal(&ebone, node->mChildren[i], true));
  }

  return ebone;
}

/// Marks a bone to be modified from outside.
/** @return A structure, which through the bone, and all of its child can be moved.
  * @param bone_name - The name of the bone. */
inline ExternalBoneTree AnimatedMesh::markBoneExternal(const std::string& bone_name) {
  if(skinning_data_.bone_mapping.find(bone_name) == skinning_data_.bone_mapping.end()) {
    throw std::runtime_error(
      "AnimatedMesh '" + filename_ + "' doesn't have any bone named '" + bone_name + "'."
    );
  }

  // Find the bone that is to be marked
  aiNode* marked_node = findNode(scene_->mRootNode, bone_name);

  ExternalBoneTree ebone_tree(markChildExternal(nullptr, marked_node));

  // Get the root bone's BoneInfo
  size_t bidx = skinning_data_.bone_mapping[marked_node->mName.data];
  SkinningData::BoneInfo& binfo = skinning_data_.bone_info[bidx];

  // Set the root bone's local transformation pointer to be able to set it from "inside".
  binfo.global_transform_ptr = ebone_tree.global_transform_ptr.get();
  binfo.pinned = true;

  return ebone_tree;
}

/// Returns the number of bones this scene has.
/** May change the currently active VAO and ArrayBuffer at the first call. */
inline size_t AnimatedMesh::getNumBones() {

  // If loadBones hasn't been called yet, than have to create
  // the bones data first to know the number of bones.
  if(skinning_data_.per_mesh_attrib_max.size() == 0) {
    createBonesData();
  }

  return skinning_data_.num_bones;
}

/// Returns the size that boneIds and BoneWeights attribute arrays should be.
/** May change the currently active VAO and ArrayBuffer at the first call. */
inline size_t AnimatedMesh::getBoneAttribNum() {

  // If loadBones hasn't been called yet, than have to create
  // the bones data first to know max_bone_attrib_num.
  if(skinning_data_.per_mesh_attrib_max.size() == 0) {
    createBonesData();
  }

  return skinning_data_.max_bone_attrib_num;
}

/// Loads in bone weight and id information to the given array of attribute arrays.
/** Uploads the bone weight and id to an array of attribute arrays, and sets it up for use.
  * For example if you specified "in vec4 boneIds[3]" you have to give "prog | boneIds"
  * Calling this function changes the currently active VAO and ArrayBuffer.
  * @param boneIDs - The array of attributes array to use as destination for bone IDs.
  * @param bone_weights - The array of attributes array to use as destination for bone weights.
  * @param integerIDs - if true, boneIDs are uploaded as integers (#version 130+) else they are uploaded as floats */
inline void AnimatedMesh::setupBones(LazyVertexAttribArray boneIDs, LazyVertexAttribArray bone_weights, bool integerIDs) {

  if(skinning_data_.is_setup_bones) {
    throw std::logic_error("AnimatedMesh::setupBones is called multiply times on the same object");
  } else {
    skinning_data_.is_setup_bones = true;
  }

  // If the bones data hasn't been created yet, than call the function to do it.
  if(skinning_data_.per_mesh_attrib_max.size() == 0) {
    createBonesData();
  }

  if(skinning_data_.num_bones < UCHAR_MAX) {
    shaderPlumbBones<unsigned char>(DataType::UnsignedByte, boneIDs, bone_weights, integerIDs);
  } else if(skinning_data_.num_bones < USHRT_MAX) {
    shaderPlumbBones<unsigned short>(DataType::UnsignedShort, boneIDs, bone_weights, integerIDs);
  } else { // more than 65535 bones? WTF???
    shaderPlumbBones<unsigned int>(DataType::UnsignedInt, boneIDs, bone_weights, integerIDs);
  }
}

} // namespace oglwrap

#endif // OGLWRAP_MESH_ANIMATED_MESH_SKINNING_INL_HPP_
