#ifndef OGLWRAP_MESH_ANIMATED_MESH_ANIMATION_INL_HPP_
#define OGLWRAP_MESH_ANIMATED_MESH_ANIMATION_INL_HPP_

#include "../global.hpp"
#include "animatedMesh.hpp"

namespace oglwrap {

inline unsigned AnimatedMesh::findPosition(float anim_time, const aiNodeAnim* node_anim) {
   // Find the first one that is bigger or equals
   for(unsigned i = 0; i < node_anim->mNumPositionKeys - 1; i++) {
      if(anim_time <= (float)node_anim->mPositionKeys[i + 1].mTime) {
         return i;
      }
   }
   // Should never get here
   assert(0);
}

inline unsigned AnimatedMesh::findRotation(float anim_time, const aiNodeAnim* node_anim) {
   for(unsigned i = 0; i < node_anim->mNumRotationKeys - 1; i++) {
      if(anim_time <= (float)node_anim->mRotationKeys[i + 1].mTime) {
         return i;
      }
   }
   assert(0);
}

inline unsigned AnimatedMesh::findScaling(float anim_time, const aiNodeAnim* node_anim) {
   for(unsigned i = 0; i < node_anim->mNumScalingKeys - 1; i++) {
      if(anim_time <= (float)node_anim->mScalingKeys[i + 1].mTime) {
         return i;
      }
   }
   assert(0);
}

inline void AnimatedMesh::calcInterpolatedPosition(aiVector3D& out, float anim_time,
                                                   const aiNodeAnim* node_anim) {
   const auto& keys = node_anim->mPositionKeys;
   const auto& numKeys = node_anim->mNumPositionKeys;
   if(numKeys == 1) {
      out = keys[0].mValue;
      return;
   }
   size_t i = findPosition(anim_time, node_anim);
   float deltaTime = keys[i + 1].mTime - keys[i].mTime;
   float factor = (anim_time - (float)keys[i].mTime) / deltaTime;
   factor = clamp(factor, 0.0f, 1.0f);

   const aiVector3D& start = keys[i].mValue;
   const aiVector3D& end   = keys[i + 1].mValue;
   out = interpolate(start, end, factor);
}

inline void AnimatedMesh::calcInterpolatedRotation(aiQuaternion& out, float anim_time,
                                                   const aiNodeAnim* node_anim) {
   const auto& keys = node_anim->mRotationKeys;
   const auto& numKeys = node_anim->mNumRotationKeys;
   if(numKeys == 1) {
      out = keys[0].mValue;
      return;
   }
   size_t i = findRotation(anim_time, node_anim);
   float deltaTime = keys[i + 1].mTime - keys[i].mTime;
   float factor = (anim_time - (float)keys[i].mTime) / deltaTime;
   factor = clamp(factor, 0.0f, 1.0f);

   const aiQuaternion& start = keys[i].mValue;
   const aiQuaternion& end   = keys[i + 1].mValue;
   aiQuaternion::Interpolate(out, start, end, factor);
   out = out.Normalize();
}

inline void AnimatedMesh::calcInterpolatedScaling(aiVector3D& out, float anim_time,
                                                  const aiNodeAnim* node_anim) {
   const auto& keys = node_anim->mScalingKeys;
   const auto& numKeys = node_anim->mNumScalingKeys;
   if(numKeys == 1) {
      out = keys[0].mValue;
      return;
   }
   size_t i = findRotation(anim_time, node_anim);
   float deltaTime = keys[i + 1].mTime - keys[i].mTime;
   float factor = (anim_time - (float)keys[i].mTime) / deltaTime;
   factor = clamp(factor, 0.0f, 1.0f);

   const aiVector3D& start = keys[i].mValue;
   const aiVector3D& end   = keys[i + 1].mValue;
   out = interpolate(start, end, factor);
}

inline const aiNodeAnim* AnimatedMesh::findNodeAnim(const aiAnimation* animation,
                                                    const std::string node_name) {
   for(unsigned i = 0; i < animation->mNumChannels; i++) {
      const aiNodeAnim* node_anim = animation->mChannels[i];
      if(std::string(node_anim->mNodeName.data) == node_name) {
         return node_anim;
      }
   }
   return nullptr;
}

inline void AnimatedMesh::updateBoneTree(float anim_time,
                                         const aiNode* node,
                                         const glm::mat4& parent_transform) {
   std::string node_name(node->mName.data);
   const aiAnimation* animation = current_anim_.handle->mAnimations[0];
   const aiNodeAnim* node_anim = findNodeAnim(animation, node_name);
   glm::mat4 local_transform = convertMatrix(node->mTransformation);

   if(node_anim) {
      // Interpolate the transformations and get the matrices
      aiVector3D scaling;
      calcInterpolatedScaling(scaling, anim_time, node_anim);
      glm::mat4 scalingM = glm::scale(glm::mat4(), glm::vec3(scaling.x, scaling.y, scaling.z));

      aiQuaternion rotation;
      calcInterpolatedRotation(rotation, anim_time, node_anim);
      glm::mat4 rotationM = convertMatrix(rotation.GetMatrix());

      aiVector3D translation;
      calcInterpolatedPosition(translation, anim_time, node_anim);
      glm::mat4 translationM;

      if(node_name == skinning_data_.root_bone) {
         current_anim_.offset = glm::vec3(translation.x, 0, translation.z);
         if(current_anim_.flags & AnimFlag::Mirrored) {
            current_anim_.offset *= -1;
         }
         translationM = glm::translate(glm::mat4(), glm::vec3(0, translation.y, 0));
      } else {
         translationM = glm::translate(glm::mat4(), glm::vec3(translation.x, translation.y, translation.z));
      }
      // Combine the transformations
      local_transform = translationM * rotationM * scalingM;
   }

   glm::mat4 global_transform = parent_transform * local_transform;

   if(skinning_data_.bone_mapping.find(node_name) != skinning_data_.bone_mapping.end()) {
      unsigned bone_idx = skinning_data_.bone_mapping[node_name];
      if(skinning_data_.bone_info[bone_idx].external == false) {
         skinning_data_.bone_info[bone_idx].final_transform =
            global_transform * skinning_data_.bone_info[bone_idx].bone_offset;
      }
      if(skinning_data_.bone_info[bone_idx].pinned == true) {
         *skinning_data_.bone_info[bone_idx].global_transform_ptr = global_transform;
         // A pinned bone has all external child
         return;
      }
   }
   for(unsigned i = 0; i < node->mNumChildren; i++) {
      updateBoneTree(anim_time, node->mChildren[i], global_transform);
   }
}

inline void AnimatedMesh::updateBoneTreeInTransition(float prev_anim_time,
                                                     float next_anim_time,
                                                     float factor,
                                                     const aiNode* node,
                                                     const glm::mat4& parent_transform) {
   std::string node_name(node->mName.data);
   const aiAnimation* prev_animation = last_anim_.handle->mAnimations[0];
   const aiAnimation* next_animation = current_anim_.handle->mAnimations[0];
   const aiNodeAnim* prev_node_anim = findNodeAnim(prev_animation, node_name);
   const aiNodeAnim* next_node_anim = findNodeAnim(next_animation, node_name);

   glm::mat4 local_transform = convertMatrix(node->mTransformation);

   if(prev_node_anim && next_node_anim) {
      // Interpolate the transformations and get the matrices
      aiVector3D prev_scaling, next_scaling;
      calcInterpolatedScaling(prev_scaling, prev_anim_time, prev_node_anim);
      calcInterpolatedScaling(next_scaling, next_anim_time, next_node_anim);
      aiVector3D scaling = interpolate(prev_scaling, next_scaling, factor);
      glm::mat4 scalingM = glm::scale(glm::mat4(), glm::vec3(scaling.x, scaling.y, scaling.z));

      aiQuaternion prev_rotation, next_rotation, rotation;
      calcInterpolatedRotation(prev_rotation, prev_anim_time, prev_node_anim);
      calcInterpolatedRotation(next_rotation, next_anim_time, next_node_anim);
      
      // Spherical linear interpolation, that chooses the shorter path.
      aiQuaternion::Interpolate(rotation, prev_rotation, next_rotation, factor);
      glm::mat4 rotationM = convertMatrix(rotation.GetMatrix());

      aiVector3D prev_translation, next_translation;
      calcInterpolatedPosition(prev_translation, prev_anim_time, prev_node_anim);
      calcInterpolatedPosition(next_translation, next_anim_time, next_node_anim);
      aiVector3D translation = interpolate(prev_translation, next_translation, factor);
      glm::mat4 translationM;
      if(node_name == skinning_data_.root_bone) {
         current_anim_.offset = glm::vec3(next_translation.x, 0, next_translation.z);
         if(current_anim_.flags & AnimFlag::Mirrored) {
            current_anim_.offset *= -1;
         }
         translationM = glm::translate(glm::mat4(), glm::vec3(0, translation.y, 0));
      } else {
         translationM = glm::translate(glm::mat4(), glm::vec3(translation.x, translation.y, translation.z));
      }
      // Combine the transformations
      local_transform = translationM * rotationM * scalingM;
   }

   glm::mat4 global_transform = parent_transform * local_transform;

   if(skinning_data_.bone_mapping.find(node_name) != skinning_data_.bone_mapping.end()) {
      unsigned bone_idx = skinning_data_.bone_mapping[node_name];
      if(skinning_data_.bone_info[bone_idx].external == false) {
         skinning_data_.bone_info[bone_idx].final_transform =
            global_transform * skinning_data_.bone_info[bone_idx].bone_offset;
      }
      if(skinning_data_.bone_info[bone_idx].pinned == true) {
         *skinning_data_.bone_info[bone_idx].global_transform_ptr = global_transform;
         // A pinned bone has all external child
         return;
      }
   }
   for(unsigned i = 0; i < node->mNumChildren; i++) {
      updateBoneTreeInTransition(
         prev_anim_time, next_anim_time, factor, node->mChildren[i], global_transform
      );
   }
}

inline void AnimatedMesh::updateBoneInfo(float time) {
   if(!current_anim_.handle || current_anim_.handle->mAnimations == 0
      || !last_anim_.handle || last_anim_.handle->mAnimations == 0) {
      throw std::runtime_error("Tried to run an invalid animation.");
   }

   float last_ticks_per_second = last_anim_.handle->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                                 last_anim_.handle->mAnimations[0]->mTicksPerSecond : 24.0f;
   float last_time_in_ticks = anim_meta_info_.last_period_time * (last_anim_.speed * last_ticks_per_second);
   float last_anim_time;
   if(last_anim_.flags & AnimFlag::Repeat) {
      last_anim_time = fmod(last_time_in_ticks, (float)last_anim_.handle->mAnimations[0]->mDuration);
   } else {
      last_anim_time = std::min(last_time_in_ticks, (float)last_anim_.handle->mAnimations[0]->mDuration);
   }
   if(last_anim_.flags & AnimFlag::Backwards) {
      last_anim_time = (float)last_anim_.handle->mAnimations[0]->mDuration - last_anim_time;
   }

   float current_ticks_per_second = current_anim_.handle->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                                    current_anim_.handle->mAnimations[0]->mTicksPerSecond : 24.0f;
   float current_time_in_ticks =
      (time - anim_meta_info_.end_of_last_anim) * (current_anim_.speed * current_ticks_per_second);
   float current_anim_time;
   if(current_anim_.flags & AnimFlag::Repeat) {
      current_anim_time = fmod(current_time_in_ticks, (float)current_anim_.handle->mAnimations[0]->mDuration);
   } else {
      if(current_time_in_ticks < (float)current_anim_.handle->mAnimations[0]->mDuration) {
         current_anim_time = current_time_in_ticks;
      } else {
         animationEnded(time);
         updateBoneInfo(time);
         return;
      }
   }

   if(current_anim_.flags & AnimFlag::Backwards) {
      current_anim_time = (float)current_anim_.handle->mAnimations[0]->mDuration - current_anim_time;
   }

   bool in_transition = anim_meta_info_.transition_time < time - anim_meta_info_.end_of_last_anim;
   float transition_factor = (time - anim_meta_info_.end_of_last_anim) / anim_meta_info_.transition_time;

   if(in_transition) {
      // Normal animation
      updateBoneTree(current_anim_time, scene_->mRootNode);
   } else {
      // Transition between two animations.
      updateBoneTreeInTransition(last_anim_time, current_anim_time,
                                 transition_factor, scene_->mRootNode);
   }

   // Start a new loop if necessary
   if(current_anim_.flags & AnimFlag::Repeat) {
      unsigned loop_count = current_time_in_ticks / (float)current_anim_.handle->mAnimations[0]->mDuration;
      if(loop_count > anim_meta_info_.last_loop_count) {
         if((current_anim_.flags & AnimFlag::MirroredRepeat) == AnimFlag::MirroredRepeat) {
            current_anim_.flags ^= AnimFlag::Mirrored;
            current_anim_.flags ^= AnimFlag::Backwards;
         }
         if(current_anim_.flags & AnimFlag::Backwards) {
            last_anim_.offset = current_anim_.offset = anims_[current_anim_.idx].end_offset;
         } else {
            last_anim_.offset = current_anim_.offset = anims_[current_anim_.idx].start_offset;
         }
         if(current_anim_.flags & AnimFlag::Mirrored) {
            last_anim_.offset *= -1;
            current_anim_.offset *= -1;
         }
      }
      anim_meta_info_.last_loop_count = loop_count;
   }
}

/// Updates the bones transformations.
/** @param time_in_seconds - Expected to be a time value in seconds. */
inline void AnimatedMesh::uploadBoneInfo(LazyUniform<glm::mat4>& bones) {
  for(unsigned i = 0; i < skinning_data_.num_bones; i++) {
      bones[i] = skinning_data_.bone_info[i].final_transform;
  }
}

inline void AnimatedMesh::updateAndUploadBoneInfo(float time, LazyUniform<glm::mat4>& bones) {
  updateBoneInfo(time);
  uploadBoneInfo(bones);
}

} // namespace oglwrap

#endif // OGLWRAP_MESH_ANIMATED_MESH_ANIMATION_INL_HPP_
