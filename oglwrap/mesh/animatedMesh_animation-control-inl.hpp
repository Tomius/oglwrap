#ifndef OGLWRAP_MESH_ANIMATED_MESH_ANIMATION_CONTROL_INL_HPP_
#define OGLWRAP_MESH_ANIMATED_MESH_ANIMATION_CONTROL_INL_HPP_

#include "animatedMesh.hpp"
#include "animInfo.hpp"

namespace oglwrap {

void AnimatedMesh::add_animation(const std::string& filename,
                                 const std::string& anim_name,
                                 unsigned flags,
                                 float speed) {
   if(anims.canFind(anim_name)) {
      std::string err = "Animation name '" + anim_name + "' isn't unique for '" + filename + "'";
      throw std::runtime_error(err);
   }
   size_t idx = anims.data.size();
   anims.names[anim_name] = idx;
   anims.data.push_back(AnimInfo());
   anims[idx].importer = new Assimp::Importer();
   anims[idx].handle = anims[idx].importer->ReadFile(filename, aiProcess_Debone);
   if(!anims[idx].handle) {
      throw std::runtime_error("Error parsing " + filename
                               + " : " + anims[idx].importer->GetErrorString());
   }

   auto node = getRootBone(scene->mRootNode, anims[idx].handle);
   if(!node) {
      throw std::runtime_error(
         "Animation error: The mesh's skeleton, and the animated skeleton '" +
         anim_name + "' doesn't have a single bone in common.");
   }

   aiVector3D v = node->mPositionKeys[0].mValue;
   anims[idx].start_offset = glm::vec3(v.x, v.y, v.z);

   v = node->mPositionKeys[node->mNumPositionKeys - 1].mValue;
   anims[idx].end_offset =  glm::vec3(v.x, v.y, v.z);

   anims[idx].flags = flags;
   anims[idx].speed = speed;
}

void AnimatedMesh::set_default_animation(const std::string& anim_name,
                                         float default_transition_time) {
   if(!anims.canFind(anim_name)) {
      throw std::invalid_argument(
         "Tried to set default animation to '" + anim_name + "', "
         "but the AnimatedMesh doesn't have an animation with that name"
      );
   }
   anim_meta_info.default_idx = anims.names[anim_name];
   anim_meta_info.default_transition_time = default_transition_time;
   if(!(anims[anim_meta_info.default_idx].flags & AnimFlag::Repeat)) {
      throw std::invalid_argument(
         "Tried to set a default animation that didn't have the "
         "repeat flag, but the default animation must be a cycle."
      );
   }
}

void AnimatedMesh::change_animation(size_t anim_idx,
                                    float current_time,
                                    float transition_time,
                                    unsigned flags,
                                    float speed) {
   bool was_last_invalid = (last_anim.handle == nullptr);

   last_anim = current_anim;

   current_anim.idx = anim_idx;
   current_anim.handle = anims[anim_idx].handle;

   if(flags & AnimFlag::Backwards) {
      current_anim.offset = anims[anim_idx].end_offset;
   } else {
      current_anim.offset = anims[anim_idx].start_offset;
   }
   if(flags & AnimFlag::Mirrored) {
      current_anim.offset *= -1;
   }

   last_anim.offset = current_anim.offset;

   if(speed > 0.0f) {
      current_anim.speed = speed;
      current_anim.flags = flags;
   } else {
      current_anim.speed = -speed;
      current_anim.flags = flags ^ AnimFlag::Backwards;
   }

   if(was_last_invalid) {
     last_anim = current_anim;
     last_anim.offset = glm::vec3();
   }

   // Meta animation data
   anim_meta_info.transition_time = transition_time;
   anim_meta_info.last_period_time = current_time - anim_meta_info.end_of_last_anim;
   anim_meta_info.end_of_last_anim = current_time;
}

void AnimatedMesh::set_current_animation(const std::string& anim_name,
                                         float current_time,
                                         float transition_time,
                                         unsigned flags,
                                         float speed) {
   if((anim_meta_info.end_of_last_anim + anim_meta_info.transition_time) <= current_time
         && (current_anim.flags & AnimFlag::Interruptable)) {
      force_current_animation(anim_name, current_time, transition_time, flags, speed);
   }
}

void AnimatedMesh::force_current_animation(const std::string& anim_name,
                                           float current_time,
                                           float transition_time,
                                           unsigned flags,
                                           float speed) {
   if(!anims.canFind(anim_name)) {
      throw std::invalid_argument(
         "Tried to set current animation to '" + anim_name + "', "
         "but the AnimatedMesh doesn't have an animation with name"
      );
   }
   size_t anim_idx = anims.names[anim_name];
   if(current_anim.handle == anims[anim_idx].handle) {
      return;
   }
   if(fabs(speed) < 1e-5) {
      change_animation(
         anim_idx,
         current_time,
         transition_time,
         flags,
         anims[anim_idx].speed
      );
   } else {
      change_animation(
         anim_idx,
         current_time,
         transition_time,
         flags,
         speed
      );
   }
}

void AnimatedMesh::set_current_animation(const std::string& anim_name,
                                         float current_time,
                                         float transition_time,
                                         float speed) {
   if((anim_meta_info.end_of_last_anim + anim_meta_info.transition_time) <= current_time
         && (current_anim.flags & AnimFlag::Interruptable)
     ) {
      force_current_animation(anim_name, current_time, transition_time, speed);
   }
}

void AnimatedMesh::force_current_animation(const std::string& anim_name,
                                           float current_time,
                                           float transition_time,
                                           float speed) {
   if(!anims.canFind(anim_name)) {
      throw std::invalid_argument(
         "Tried to set current animation to '" + anim_name + "', "
         "but the AnimatedMesh doesn't have an animation with name"
      );
   }
   size_t anim_idx = anims.names[anim_name];
   if(current_anim.handle == anims[anim_idx].handle) {
      return;
   }

   if(fabs(speed) < 1e-5) {
      change_animation(
         anim_idx,
         current_time,
         transition_time,
         anims[anim_idx].flags,
         anims[anim_idx].speed
      );
   } else {
      change_animation(
         anim_idx,
         current_time,
         transition_time,
         anims[anim_idx].flags,
         speed
      );
   }
}

void AnimatedMesh::set_anim_to_default(float current_time) {
   if(current_anim.flags & AnimFlag::Interruptable) {
      force_anim_to_default(current_time);
   }
}

void AnimatedMesh::force_anim_to_default(float current_time) {
   assert(anims[anim_meta_info.default_idx].flags & AnimFlag::Repeat);
   if(current_anim.handle != anims[anim_meta_info.default_idx].handle)
      change_animation(
         anim_meta_info.default_idx,
         current_time,
         anim_meta_info.default_transition_time,
         anims[anim_meta_info.default_idx].flags,
         anims[anim_meta_info.default_idx].speed
      );
}

glm::vec2 AnimatedMesh::offset_since_last_frame() {
   auto ret = current_anim.offset - last_anim.offset;
   last_anim.offset = current_anim.offset;
   return glm::vec2(ret.x, ret.z);
}

} // namespace oglwrap

#endif // OGLWRAP_MESH_ANIMATED_MESH_ANIMATION_CONTROL_INL_HPP_
