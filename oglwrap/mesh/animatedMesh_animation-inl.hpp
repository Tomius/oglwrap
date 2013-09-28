#ifndef OGLWRAP_MESH_ANIMATED_MESH_ANIMATION_INL_HPP_
#define OGLWRAP_MESH_ANIMATED_MESH_ANIMATION_INL_HPP_

#include "animatedMesh.hpp"

namespace oglwrap {

unsigned AnimatedMesh::findPosition(float animationTime, const aiNodeAnim* node_anim) {
   // Find the first one that is bigger or equals
   for(unsigned i = 0; i < node_anim->mNumPositionKeys - 1; i++) {
      if(animationTime <= (float)node_anim->mPositionKeys[i + 1].mTime) {
         return i;
      }
   }
   // Should never get here
   throw std::runtime_error("Animation Error - Position keyframe not found");
}

unsigned AnimatedMesh::findRotation(float animationTime, const aiNodeAnim* node_anim) {
   for(unsigned i = 0; i < node_anim->mNumRotationKeys - 1; i++) {
      if(animationTime <= (float)node_anim->mRotationKeys[i + 1].mTime) {
         return i;
      }
   }
   throw std::runtime_error("Animation Error - Rotation keyframe not found");
}

unsigned AnimatedMesh::findScaling(float animationTime, const aiNodeAnim* node_anim) {
   for(unsigned i = 0; i < node_anim->mNumScalingKeys - 1; i++) {
      if(animationTime <= (float)node_anim->mScalingKeys[i + 1].mTime) {
         return i;
      }
   }
   throw std::runtime_error("Animation Error - Scaling keyframe not found");
}

void AnimatedMesh::calcInterpolatedPosition(aiVector3D& out, float animTime, const aiNodeAnim* node_anim) {
   const auto& keys = node_anim->mPositionKeys;
   const auto& numKeys = node_anim->mNumPositionKeys;
   if(numKeys == 1) {
      out = keys[0].mValue;
      return;
   }
   size_t i = findPosition(animTime, node_anim);
   float deltaTime = keys[i + 1].mTime - keys[i].mTime;
   float factor = (animTime - (float)keys[i].mTime) / deltaTime;
   if(factor < 0.0f) {
      factor = 0.0f;
   }
   if(factor > 1.0f) {
      factor = 1.0f;
   }
   const aiVector3D& start = keys[i].mValue;
   const aiVector3D& end   = keys[i + 1].mValue;
   out = interpolate(start, end, factor);
}

void AnimatedMesh::calcInterpolatedRotation(aiQuaternion& out, float animTime, const aiNodeAnim* node_anim) {
   const auto& keys = node_anim->mRotationKeys;
   const auto& numKeys = node_anim->mNumRotationKeys;
   if(numKeys == 1) {
      out = keys[0].mValue;
      return;
   }
   size_t i = findRotation(animTime, node_anim);
   float deltaTime = keys[i + 1].mTime - keys[i].mTime;
   float factor = (animTime - (float)keys[i].mTime) / deltaTime;
   if(factor < 0.0f) {
      factor = 0.0f;
   }
   if(factor > 1.0f) {
      factor = 1.0f;
   }
   const aiQuaternion& start = keys[i].mValue;
   const aiQuaternion& end   = keys[i + 1].mValue;
   aiQuaternion::Interpolate(out, start, end, factor); // spherical interpolation
   out = out.Normalize();
}

void AnimatedMesh::calcInterpolatedScaling(aiVector3D& out, float animTime, const aiNodeAnim* node_anim) {
   const auto& keys = node_anim->mScalingKeys;
   const auto& numKeys = node_anim->mNumScalingKeys;
   if(numKeys == 1) {
      out = keys[0].mValue;
      return;
   }
   size_t i = findRotation(animTime, node_anim);
   float deltaTime = keys[i + 1].mTime - keys[i].mTime;
   float factor = (animTime - (float)keys[i].mTime) / deltaTime;
   if(factor < 0.0f) {
      factor = 0.0f;
   } else if(factor > 1.0f) {
      factor = 1.0f;
   }
   const aiVector3D& start = keys[i].mValue;
   const aiVector3D& end   = keys[i + 1].mValue;
   out = interpolate(start, end, factor);
}

const aiNodeAnim* AnimatedMesh::findNodeAnim(const aiAnimation* animation, const std::string node_name) {
   for(unsigned i = 0; i < animation->mNumChannels; i++) {
      const aiNodeAnim* node_anim = animation->mChannels[i];
      if(std::string(node_anim->mNodeName.data) == node_name) {
         return node_anim;
      }
   }
   return nullptr;
}

void AnimatedMesh::updateBoneTree(float animationTime,
                                  const aiNode* node,
                                  const glm::mat4& parent_transform) {
   std::string node_name(node->mName.data);
   const aiAnimation* animation = current_anim.handle->mAnimations[0];
   const aiNodeAnim* node_anim = findNodeAnim(animation, node_name);
   glm::mat4 nodeTransform = convertMatrix(node->mTransformation);
   if(node_anim) {
      // Interpolate the transformations and get the matrices
      aiVector3D scaling;
      calcInterpolatedScaling(scaling, animationTime, node_anim);
      glm::mat4 scalingM = glm::scale(glm::mat4(), glm::vec3(scaling.x, scaling.y, scaling.z));

      aiQuaternion rotation;
      calcInterpolatedRotation(rotation, animationTime, node_anim);
      glm::mat4 rotationM = convertMatrix(rotation.GetMatrix());

      aiVector3D translation;
      calcInterpolatedPosition(translation, animationTime, node_anim);
      glm::mat4 translationM;

      if(node_name == skinning_data.root_bone) {
         current_anim.offset = glm::vec3(translation.x, 0, translation.z);
         if(current_anim.flags & AnimFlag::Mirrored) {
            current_anim.offset *= -1;
         }
         translationM = glm::translate(glm::mat4(), glm::vec3(0, translation.y, 0));
      } else {
         translationM = glm::translate(glm::mat4(), glm::vec3(translation.x, translation.y, translation.z));
      }
      // Combine the transformations
      nodeTransform = translationM * rotationM * scalingM;
   }

   glm::mat4 globalTransformation = parent_transform * nodeTransform;
   if(skinning_data.bone_mapping.find(node_name) != skinning_data.bone_mapping.end()) {
      unsigned bone_idx = skinning_data.bone_mapping[node_name];
      skinning_data.bone_info[bone_idx].final_transform =
         skinning_data.global_inverse_transform *
         globalTransformation *
         skinning_data.bone_info[bone_idx].bone_offset;
   }
   for(unsigned i = 0; i < node->mNumChildren; i++) {
      updateBoneTree(animationTime, node->mChildren[i], globalTransformation);
   }
}

void AnimatedMesh::updateBoneTree_inTransition(float prevAnimationTime,
                                               float nextAnimationTime,
                                               float factor,
                                               const aiNode* node,
                                               const glm::mat4& parent_transform) {
   std::string node_name(node->mName.data);
   const aiAnimation* prevAnimation = last_anim.handle->mAnimations[0];
   const aiAnimation* nextAnimation = current_anim.handle->mAnimations[0];
   const aiNodeAnim* prevNodeAnim = findNodeAnim(prevAnimation, node_name);
   const aiNodeAnim* nextNodeAnim = findNodeAnim(nextAnimation, node_name);
   glm::mat4 node_transform = convertMatrix(node->mTransformation);

   if(prevNodeAnim && nextNodeAnim) {
      // Interpolate the transformations and get the matrices
      aiVector3D prevScaling, nextScaling;
      calcInterpolatedScaling(prevScaling, prevAnimationTime, prevNodeAnim);
      calcInterpolatedScaling(nextScaling, nextAnimationTime, nextNodeAnim);
      aiVector3D scaling = interpolate(prevScaling, nextScaling, factor);
      glm::mat4 scalingM = glm::scale(glm::mat4(), glm::vec3(scaling.x, scaling.y, scaling.z));

      aiQuaternion prevRotation, nextRotation, rotation;
      calcInterpolatedRotation(prevRotation, prevAnimationTime, prevNodeAnim);
      calcInterpolatedRotation(nextRotation, nextAnimationTime, nextNodeAnim);
      // spherical interpolation, and it always chooses the shorter path (exactly what we want).
      aiQuaternion::Interpolate(rotation, prevRotation, nextRotation, factor);
      glm::mat4 rotationM = convertMatrix(rotation.GetMatrix());

      aiVector3D prevTranslation, nextTranslation;
      calcInterpolatedPosition(prevTranslation, prevAnimationTime, prevNodeAnim);
      calcInterpolatedPosition(nextTranslation, nextAnimationTime, nextNodeAnim);
      aiVector3D translation = interpolate(prevTranslation, nextTranslation, factor);
      glm::mat4 translationM;
      if(node_name == skinning_data.root_bone) {
         current_anim.offset = glm::vec3(nextTranslation.x, 0, nextTranslation.z);
         if(current_anim.flags & AnimFlag::Mirrored) {
            current_anim.offset *= -1;
         }
         translationM = glm::translate(glm::mat4(), glm::vec3(0, translation.y, 0));
      } else {
         translationM = glm::translate(glm::mat4(), glm::vec3(translation.x, translation.y, translation.z));
      }
      // Combine the transformations
      node_transform = translationM * rotationM * scalingM;
   }
   glm::mat4 global_transformation = parent_transform * node_transform;
   if(skinning_data.bone_mapping.find(node_name) != skinning_data.bone_mapping.end()) {
      unsigned bone_idx = skinning_data.bone_mapping[node_name];
      skinning_data.bone_info[bone_idx].final_transform =
           skinning_data.global_inverse_transform *
           global_transformation *
           skinning_data.bone_info[bone_idx].bone_offset;
   }
   for(unsigned i = 0; i < node->mNumChildren; i++) {
      updateBoneTree_inTransition(
         prevAnimationTime, nextAnimationTime, factor, node->mChildren[i], global_transformation
      );
   }
}

void AnimatedMesh::updateBoneInfo(float time) {
   if(!current_anim.handle || current_anim.handle->mAnimations == 0 ||
        !last_anim.handle || last_anim.handle->mAnimations == 0) {
      throw std::runtime_error("Tried to run an invalid animation.");
   }

   float last_ticks_per_second = last_anim.handle->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                                 last_anim.handle->mAnimations[0]->mTicksPerSecond : 24.0f;
   float last_time_in_ticks = meta_info.last_period_time * (last_anim.speed * last_ticks_per_second);
   float last_animation_time;
   if(last_anim.flags & AnimFlag::Repeat) {
      last_animation_time = fmod(last_time_in_ticks, (float)last_anim.handle->mAnimations[0]->mDuration);
   } else {
      last_animation_time = std::min(last_time_in_ticks, (float)last_anim.handle->mAnimations[0]->mDuration);
   }
   if(last_anim.flags & AnimFlag::Backwards) {
      last_animation_time = (float)last_anim.handle->mAnimations[0]->mDuration - last_animation_time;
   }

   float current_ticks_per_second = current_anim.handle->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                                    current_anim.handle->mAnimations[0]->mTicksPerSecond : 24.0f;
   float current_time_in_ticks =
      (time - meta_info.end_of_last_anim) * (current_anim.speed * current_ticks_per_second);
   float current_animation_time;
   if(current_anim.flags & AnimFlag::Repeat) {
      current_animation_time = fmod(current_time_in_ticks, (float)current_anim.handle->mAnimations[0]->mDuration);
   } else {
      if(current_time_in_ticks < (float)current_anim.handle->mAnimations[0]->mDuration) {
         current_animation_time = current_time_in_ticks;
      } else {
         force_anim_to_default(time);
         updateBoneInfo(time);
         return;
      }
   }

   if(current_anim.flags & AnimFlag::Backwards) {
      current_animation_time = (float)current_anim.handle->mAnimations[0]->mDuration - current_animation_time;
   }

   bool in_transition = meta_info.transition_time < time - meta_info.end_of_last_anim;
   float transition_factor = (time - meta_info.end_of_last_anim) / meta_info.transition_time;

   if(in_transition) {
      // Normal animation
      updateBoneTree(current_animation_time, scene->mRootNode);
   } else {
      // Transition between two animations.
      updateBoneTree_inTransition(last_animation_time, current_animation_time,
                                  transition_factor, scene->mRootNode);
   }

   // Start a new loop if necessary
   if(current_anim.flags & AnimFlag::Repeat) {
      unsigned loop_count = current_time_in_ticks / (float)current_anim.handle->mAnimations[0]->mDuration;
      if(loop_count > meta_info.last_loop_count) {
         if((current_anim.flags & AnimFlag::MirroredRepeat) == AnimFlag::MirroredRepeat) {
            current_anim.flags ^= AnimFlag::Mirrored;
            current_anim.flags ^= AnimFlag::Backwards;
         }
         if(current_anim.flags & AnimFlag::Backwards) {
            last_anim.offset = current_anim.offset = anims[current_anim.idx].end_offset;
         } else {
            last_anim.offset = current_anim.offset = anims[current_anim.idx].start_offset;
         }
         if(current_anim.flags & AnimFlag::Mirrored) {
            last_anim.offset *= -1;
            current_anim.offset *= -1;
         }
      }
      meta_info.last_loop_count = loop_count;
   }
}

void AnimatedMesh::boneTransform(float time,
                                 LazyUniform<glm::mat4>& bones) {
   updateBoneInfo(time);
   for(unsigned i = 0; i < skinning_data.num_bones; i++) {
      bones[i] = skinning_data.bone_info[i].final_transform;
   }
}

} // namespace oglwrap

#endif // OGLWRAP_MESH_ANIMATED_MESH_ANIMATION_INL_HPP_
