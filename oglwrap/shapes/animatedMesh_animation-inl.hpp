#ifndef OGLWRAP_SHAPES_ANIMATED_MESH_ANIMATION_INL_HPP_
#define OGLWRAP_SHAPES_ANIMATED_MESH_ANIMATION_INL_HPP_

#include "animatedMesh.hpp"

namespace oglwrap {

unsigned AnimatedMesh::findPosition(float animationTime, const aiNodeAnim* nodeAnim) {
   // Find the first one that is bigger or equals
   for(unsigned i = 0; i < nodeAnim->mNumPositionKeys - 1; i++) {
      if(animationTime <= (float)nodeAnim->mPositionKeys[i + 1].mTime) {
         return i;
      }
   }
   // Should never get here
   throw std::runtime_error("Animation Error - Position keyframe not found");
}

unsigned AnimatedMesh::findRotation(float animationTime, const aiNodeAnim* nodeAnim) {
   for(unsigned i = 0; i < nodeAnim->mNumRotationKeys - 1; i++) {
      if(animationTime <= (float)nodeAnim->mRotationKeys[i + 1].mTime) {
         return i;
      }
   }
   throw std::runtime_error("Animation Error - Rotation keyframe not found");
}

unsigned AnimatedMesh::findScaling(float animationTime, const aiNodeAnim* nodeAnim) {
   for(unsigned i = 0; i < nodeAnim->mNumScalingKeys - 1; i++) {
      if(animationTime <= (float)nodeAnim->mScalingKeys[i + 1].mTime) {
         return i;
      }
   }
   throw std::runtime_error("Animation Error - Scaling keyframe not found");
}

void AnimatedMesh::calcInterpolatedPosition(aiVector3D& out, float animTime, const aiNodeAnim* nodeAnim) {
   const auto& keys = nodeAnim->mPositionKeys;
   const auto& numKeys = nodeAnim->mNumPositionKeys;
   if(numKeys == 1) {
      out = keys[0].mValue;
      return;
   }
   size_t i = findPosition(animTime, nodeAnim);
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

void AnimatedMesh::calcInterpolatedRotation(aiQuaternion& out, float animTime, const aiNodeAnim* nodeAnim) {
   const auto& keys = nodeAnim->mRotationKeys;
   const auto& numKeys = nodeAnim->mNumRotationKeys;
   if(numKeys == 1) {
      out = keys[0].mValue;
      return;
   }
   size_t i = findRotation(animTime, nodeAnim);
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

void AnimatedMesh::calcInterpolatedScaling(aiVector3D& out, float animTime, const aiNodeAnim* nodeAnim) {
   const auto& keys = nodeAnim->mScalingKeys;
   const auto& numKeys = nodeAnim->mNumScalingKeys;
   if(numKeys == 1) {
      out = keys[0].mValue;
      return;
   }
   size_t i = findRotation(animTime, nodeAnim);
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

const aiNodeAnim* AnimatedMesh::findNodeAnim(const aiAnimation* animation, const std::string nodeName) {
   for(unsigned i = 0; i < animation->mNumChannels; i++) {
      const aiNodeAnim* nodeAnim = animation->mChannels[i];
      if(std::string(nodeAnim->mNodeName.data) == nodeName) {
         return nodeAnim;
      }
   }
   return nullptr;
}

void AnimatedMesh::updateBoneTree(float animationTime,
                                  const aiNode* node,
                                  const glm::mat4& parentTransform) {
   std::string nodeName(node->mName.data);
   const aiAnimation* animation = current_anim->mAnimations[0];
   const aiNodeAnim* nodeAnim = findNodeAnim(animation, nodeName);
   glm::mat4 nodeTransform = convertMatrix(node->mTransformation);
   if(nodeAnim) {
      // Interpolate the transformations and get the matrices
      aiVector3D scaling;
      calcInterpolatedScaling(scaling, animationTime, nodeAnim);
      glm::mat4 scalingM = glm::scale(glm::mat4(), glm::vec3(scaling.x, scaling.y, scaling.z));
      aiQuaternion rotation;
      calcInterpolatedRotation(rotation, animationTime, nodeAnim);
      glm::mat4 rotationM = convertMatrix(rotation.GetMatrix());
      aiVector3D translation;
      calcInterpolatedPosition(translation, animationTime, nodeAnim);
      glm::mat4 translationM;
      if(nodeName == root_bone) {
         current_offset = glm::vec3(translation.x, 0, translation.z);
         if(current_flags & AnimFlag::Mirrored) {
            current_offset *= -1;
         }
         translationM = glm::translate(glm::mat4(), glm::vec3(0, translation.y, 0));
      } else {
         translationM = glm::translate(glm::mat4(), glm::vec3(translation.x, translation.y, translation.z));
      }
      // Combine the transformations
      nodeTransform = translationM * rotationM * scalingM;
   }
   glm::mat4 globalTransformation = parentTransform * nodeTransform;
   if(bone_mapping.find(nodeName) != bone_mapping.end()) {
      unsigned boneIndex = bone_mapping[nodeName];
      bone_info[boneIndex].final_transform =
         global_inverse_transform * globalTransformation * bone_info[boneIndex].bone_offset;
   }
   for(unsigned i = 0; i < node->mNumChildren; i++) {
      updateBoneTree(animationTime, node->mChildren[i], globalTransformation);
   }
}

void AnimatedMesh::updateBoneTree_inTransition(float prevAnimationTime,
                                               float nextAnimationTime,
                                               float factor,
                                               const aiNode* node,
                                               const glm::mat4& parentTransform) {
   std::string nodeName(node->mName.data);
   const aiAnimation* prevAnimation = last_anim->mAnimations[0];
   const aiAnimation* nextAnimation = current_anim->mAnimations[0];
   const aiNodeAnim* prevNodeAnim = findNodeAnim(prevAnimation, nodeName);
   const aiNodeAnim* nextNodeAnim = findNodeAnim(nextAnimation, nodeName);
   glm::mat4 nodeTransform = convertMatrix(node->mTransformation);
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
      if(nodeName == root_bone) {
         current_offset = glm::vec3(nextTranslation.x, 0, nextTranslation.z);
         if(current_flags & AnimFlag::Mirrored) {
            current_offset *= -1;
         }
         translationM = glm::translate(glm::mat4(), glm::vec3(0, translation.y, 0));
      } else {
         translationM = glm::translate(glm::mat4(), glm::vec3(translation.x, translation.y, translation.z));
      }
      // Combine the transformations
      nodeTransform = translationM * rotationM * scalingM;
   }
   glm::mat4 globalTransformation = parentTransform * nodeTransform;
   if(bone_mapping.find(nodeName) != bone_mapping.end()) {
      unsigned boneIndex = bone_mapping[nodeName];
      bone_info[boneIndex].final_transform =
         global_inverse_transform * globalTransformation * bone_info[boneIndex].bone_offset;
   }
   for(unsigned i = 0; i < node->mNumChildren; i++) {
      updateBoneTree_inTransition(
         prevAnimationTime, nextAnimationTime, factor, node->mChildren[i], globalTransformation
      );
   }
}

void AnimatedMesh::updateBoneInfo(float time_in_seconds) {
   if(!current_anim || current_anim->mAnimations == 0 ||
         !last_anim || last_anim->mAnimations == 0) {
      throw std::runtime_error("Tried to run an invalid animation.");
   }
   float last_ticks_per_second = last_anim->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                                 last_anim->mAnimations[0]->mTicksPerSecond : 24.0f;
   float last_time_in_ticks = last_period_time * (last_speed * last_ticks_per_second);
   float last_animation_time;
   if(last_flags & AnimFlag::Repeat) {
      last_animation_time = fmod(last_time_in_ticks, (float)last_anim->mAnimations[0]->mDuration);
   } else {
      last_animation_time = std::min(last_time_in_ticks, (float)last_anim->mAnimations[0]->mDuration);
   }
   if(last_flags & AnimFlag::Backwards) {
      last_animation_time = (float)last_anim->mAnimations[0]->mDuration - last_animation_time;
   }
   float current_ticks_per_second = current_anim->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                                    current_anim->mAnimations[0]->mTicksPerSecond : 24.0f;
   float current_time_in_ticks =
      (time_in_seconds - end_of_last_anim) * (current_speed * current_ticks_per_second);
   float current_animation_time;
   if(current_flags & AnimFlag::Repeat) {
      current_animation_time = fmod(current_time_in_ticks, (float)current_anim->mAnimations[0]->mDuration);
   } else {
      if(current_time_in_ticks < (float)current_anim->mAnimations[0]->mDuration) {
         current_animation_time = current_time_in_ticks;
      } else {
         force_anim_to_default(time_in_seconds);
         updateBoneInfo(time_in_seconds);
         return;
      }
   }
   if(current_flags & AnimFlag::Backwards) {
      current_animation_time = (float)current_anim->mAnimations[0]->mDuration - current_animation_time;
   }
   bool in_transition = transition_time < time_in_seconds - end_of_last_anim;
   float transition_factor = (time_in_seconds - end_of_last_anim) / transition_time;
   if(in_transition) {
      // Normal animation
      updateBoneTree(current_animation_time, scene->mRootNode);
   } else {
      // Transition between two animations.
      updateBoneTree_inTransition(last_animation_time, current_animation_time,
                                  transition_factor, scene->mRootNode);
   }
   // Start a new loop if necessary
   if(current_flags & AnimFlag::Repeat) {
      unsigned loop_count = current_time_in_ticks / (float)current_anim->mAnimations[0]->mDuration;
      if(loop_count > last_loop_count) {
         if((current_flags & AnimFlag::MirroredRepeat) == AnimFlag::MirroredRepeat) {
            current_flags ^= AnimFlag::Mirrored;
            current_flags ^= AnimFlag::Backwards;
         }
         if(current_flags & AnimFlag::Backwards) {
            last_offset = current_offset = end_offsets[curr_idx];
         } else {
            last_offset = current_offset = start_offsets[curr_idx];
         }
         if(current_flags & AnimFlag::Mirrored) {
            last_offset *= -1;
            current_offset *= -1;
         }
      }
      last_loop_count = loop_count;
   }
}

void AnimatedMesh::boneTransform(float time_in_seconds,
                                 LazyUniform<glm::mat4>& bones) {
   updateBoneInfo(time_in_seconds);
   for(unsigned i = 0; i < num_bones; i++) {
      bones[i] = bone_info[i].final_transform;
   }
}

} // namespace oglwrap

#endif // OGLWRAP_SHAPES_ANIMATED_MESH_ANIMATION_INL_HPP_
