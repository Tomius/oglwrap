#ifndef OGLWRAP_SHAPES_ANIMATED_MESH_ANIMATION_CONTROL_INL_HPP_
#define OGLWRAP_SHAPES_ANIMATED_MESH_ANIMATION_CONTROL_INL_HPP_

#include "animatedMesh.hpp"

namespace oglwrap {

void AnimatedMesh::add_animation(const std::string& filename,
                   const std::string& animName,
                   unsigned flags,
                   float speed) {

  if(anim_names.find(animName) != anim_names.end()) {
    std::string err = "Animation name '" + animName + "' isn't unique for '" + filename + "'";
    throw std::runtime_error(err);
  }
  size_t idx = animations.size();
  anim_names[animName] = idx;
  animation_importers.push_back(new Assimp::Importer());
  animations.push_back(animation_importers[idx]->ReadFile(filename, aiProcess_Debone));

  if(!animations[idx]) {
    throw std::runtime_error("Error parsing " + filename
                             + " : " + animation_importers[idx]->GetErrorString());
  }

  auto node = getRootBone(scene->mRootNode, animations[idx]);
  if(!node) {
    throw std::runtime_error(
      "Animation error: The mesh's skeleton, and the animated skeleton '" +
      animName + "' doesn't have a single bone in common.");
  }

  aiVector3D v = node->mPositionKeys[0].mValue;
  start_offsets.push_back(glm::vec3(v.x, v.y, v.z));
  v = node->mPositionKeys[node->mNumPositionKeys - 1].mValue;
  end_offsets.push_back(glm::vec3(v.x, v.y, v.z));

  default_flags.push_back(flags);
  speed_modifiers.push_back(speed);
}

void AnimatedMesh::set_default_animation(const std::string& animName,
                           float default_transition_time) {

  if(anim_names.find(animName) == anim_names.end()) {
    throw std::invalid_argument(
      "Tried to set default animation to '" + animName + "', "
      "but the AnimatedMesh doesn't have an animation with that name"
    );
  }

  default_idx = anim_names[animName];
  this->default_transition_time = default_transition_time;

  if(!(default_flags[default_idx] & AnimFlag::Repeat)) {
    throw std::invalid_argument(
      "Tried to set a default animation that didn't have the "
      "repeat flag, but the default animation must be a cycle."
    );
  }
}

void AnimatedMesh::change_animation(size_t animIndex,
                      float currentTime,
                      float transition_time,
                      unsigned flags,
                      float speed) {

  last_idx = curr_idx;
  curr_idx = animIndex;
  last_anim = current_anim;
  current_anim = animations[animIndex];
  this->transition_time = transition_time;
  last_period_time = currentTime - end_of_last_anim;
  end_of_last_anim = currentTime;

  if(flags & AnimFlag::Backwards) {
    last_offset = current_offset = end_offsets[curr_idx];
  } else {
    last_offset = current_offset = start_offsets[curr_idx];
  }

  if(flags & AnimFlag::Mirrored) {
    last_offset *= -1;
    current_offset *= -1;
  }

  if(!last_anim) {
    last_offset = glm::vec3();
    last_anim = current_anim;
  }

  last_flags = current_flags;
  if(speed > 0.0f) {
    current_flags = flags;
  } else {
    speed *= -1;
    current_flags = flags ^ AnimFlag::Backwards;
  }

  last_speed = current_speed;
  current_speed = speed;
}

void AnimatedMesh::set_current_animation(const std::string& animName,
                           float currentTime,
                           float transition_time,
                           unsigned flags,
                           float speed) {

  if((end_of_last_anim + this->transition_time) <= currentTime
      && (current_flags & AnimFlag::Interruptable)
    ) {
    force_current_animation(animName, currentTime, transition_time, flags, speed);
  }
}

void AnimatedMesh::force_current_animation(const std::string& animName,
                             float currentTime,
                             float transition_time,
                             unsigned flags,
                             float speed) {

  if(anim_names.find(animName) == anim_names.end()) {
    throw std::invalid_argument(
      "Tried to set current animation to '" + animName + "', "
      "but the AnimatedMesh doesn't have an animation with name"
    );
  }

  size_t animIndex = anim_names[animName];

  if(current_anim == animations[animIndex]) {
    return;
  }

  if(fabs(speed) < 1e-5) {
    change_animation(
      animIndex,
      currentTime,
      transition_time,
      flags,
      speed_modifiers[animIndex]
    );
  } else {
    change_animation(
      animIndex,
      currentTime,
      transition_time,
      flags,
      speed
    );
  }
}

void AnimatedMesh::set_current_animation(const std::string& animName,
                           float currentTime,
                           float transition_time,
                           float speed) {

  if((end_of_last_anim + this->transition_time) <= currentTime
      && (current_flags & AnimFlag::Interruptable)
    ) {
    force_current_animation(animName, currentTime, transition_time, speed);
  }
}

void AnimatedMesh::force_current_animation(const std::string& animName,
                             float currentTime,
                             float transition_time,
                             float speed) {

  if(anim_names.find(animName) == anim_names.end()) {
    throw std::invalid_argument(
      "Tried to set current animation to '" + animName + "', "
      "but the AnimatedMesh doesn't have an animation with name"
    );
  }

  size_t animIndex = anim_names[animName];

  if(current_anim == animations[animIndex]) {
    return;
  }

  if(fabs(speed) < 1e-5) {
    change_animation(
      animIndex,
      currentTime,
      transition_time,
      default_flags[animIndex],
      speed_modifiers[animIndex]
    );
  } else {
    change_animation(
      animIndex,
      currentTime,
      transition_time,
      default_flags[animIndex],
      speed
    );
  }
}

void AnimatedMesh::set_anim_to_default(float currentTime) {
  if(current_flags & AnimFlag::Interruptable) {
    force_anim_to_default(currentTime);
  }
}

void AnimatedMesh::force_anim_to_default(float currentTime) {
  assert(default_flags[default_idx] & AnimFlag::Repeat);
  if(current_anim != animations[default_idx])
    change_animation(
      default_idx,
      currentTime,
      default_transition_time,
      default_flags[default_idx],
      speed_modifiers[default_idx]
    );
}

glm::vec3 AnimatedMesh::offset_since_last_frame() {
  auto ret = current_offset - last_offset;
  last_offset = current_offset;
  ret.y = 0;
  return ret;
}

} // namespace oglwrap

#endif // OGLWRAP_SHAPES_ANIMATED_MESH_ANIMATION_CONTROL_INL_HPP_
