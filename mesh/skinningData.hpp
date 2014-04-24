#ifndef OGLWRAP_MESH_SKINNING_DATA_HPP_
#define OGLWRAP_MESH_SKINNING_DATA_HPP_

#include <memory>
#include "mesh.hpp"

namespace oglwrap {

struct SkinningData {
  template<class Index_t>
  /// A struct containing an "ivec4" for the boneIDs, and a vec4 for bone weights.
  /** The boneIDs part is not fixed to be int (unsigned), it becomes the
    * smallest type that can store all the ids of the bones. */
  struct VertexBoneData_PerAttribute{
    Index_t ids[4];
    float weights[4];

    VertexBoneData_PerAttribute() {
      memset(ids, 0, sizeof(ids));
      memset(weights, 0, sizeof(weights));
    };
  };

  template<class Index_t>
  /// Contains an array of VertexBoneData_PerAttribute.
  /** The size of that vector varies per vertex. */
  struct VertexBoneData {
    std::vector<VertexBoneData_PerAttribute<Index_t>> data;

    void AddBoneData(Index_t boneID, float weight) {
      do {
        for(size_t i = 0; i < data.size(); i++) {
          for(int j = 0; j < 4; j++) {
            if(data[i].weights[j] < 1e-10) { // if equals 0
              data[i].ids[j] = boneID;
              data[i].weights[j] = weight;
              return;
            }
          }
        }

        // If there isn't enough space yet, then make some new
        data.push_back(VertexBoneData_PerAttribute<Index_t>());

      } while(data.size() < 8); // Bone attributes shouldn't use up all the 16 attribute slots.
    }
  };

  /// A structure for storing the default, relative-to-parent, and current transformations.
  struct BoneInfo {
    glm::mat4 bone_offset;
    glm::mat4 final_transform;

    // For editing bones from outside
    bool external = false;
    bool pinned = false;
    glm::mat4* global_transform_ptr = nullptr;
  };

  /// The OpenGL buffers for the vertex bone data.
  std::vector<ArrayBuffer> vertex_bone_data_buffers;

  /// The transformations of the bones.
  std::vector<BoneInfo> bone_info;

  /// Maps a bone name to its index.
  /** It is needed as usually multiply meshes share the same bone, but with
    * different index. The only way to reference it, without getting too much
    * multiplies, is to reference them by their name */
  std::map<std::string, unsigned> bone_mapping;

  /// The number of the bones.
  size_t num_bones;

  /// The maximum of per mesh bone attribute number's maximum for the entire scene.
  unsigned char max_bone_attrib_num;

  /// The maximum of per mesh bone attribute number's maximum per mesh.
  std::vector<unsigned char> per_mesh_attrib_max;

  /// Stores if setupBones is called. It shouldn't be called more than once.
  bool is_setup_bones;

  /// The name of the root bone. It's usually not equal to the root node. It is need to get the offsets.
  std::string root_bone;

  SkinningData(size_t num_meshes = 0)
    : vertex_bone_data_buffers(num_meshes)
    , num_bones(0)
    , max_bone_attrib_num(0)
    , is_setup_bones(false)
  { }
};

struct ExternalBone;

struct BasicExternalBone {
  const std::string name; // FIXME - only for debug
  const glm::mat4 offset;
  const glm::mat4 default_transform;

  std::vector<ExternalBone> child;

  BasicExternalBone(const std::string& name,
                    const glm::mat4& offset,
                    const glm::mat4& default_transform)
      : name(name)
      , offset(offset)
      , default_transform(default_transform)
  { }
};

struct ExternalBone : public BasicExternalBone {
  glm::mat4& final_transform;
  const BasicExternalBone* parent;

  ExternalBone(const std::string& name,
               const glm::mat4& offset,
               const glm::mat4& default_transform,
               glm::mat4& final_transform,
               const BasicExternalBone* parent)
      : BasicExternalBone(name, offset, default_transform)
      , final_transform(final_transform)
      , parent(parent)
  { }
};

struct ExternalBoneTree : public BasicExternalBone {
  // This will be modified by the AnimatedClass's updateBoneInfo() call.
  std::shared_ptr<glm::mat4> global_transform_ptr;

  ExternalBoneTree(const BasicExternalBone& super)
      : BasicExternalBone(super)
      , global_transform_ptr(new glm::mat4{})
  { }

};

} // namespace oglwrap

#endif // OGLWRAP_MESH_SKINNING_DATA_HPP_
