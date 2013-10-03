/** @file animatedMesh.hpp
    @brief An animation loader using assimp
*/

#ifndef OGLWRAP_MESH_ANIMATEDMESH_HPP_
#define OGLWRAP_MESH_ANIMATEDMESH_HPP_

#include "mesh.hpp"
#include "../config.hpp"
#include "animState.hpp"
#include "skinningData.hpp"
#include "animInfo.hpp"

namespace oglwrap {

class AnimatedMesh : public Mesh {

  /// Stores data related to skin definition.
  SkinningData skinning_data_;

  /// The animations.
  AnimData anims_;

  /// Stores data to handle animation transitions.
  AnimMetaInfo anim_meta_info_;

  /// The current animation.
  AnimationState current_anim_;

  /// The last animation.
  AnimationState last_anim_;

public:
  /// Loads in the mesh and the skeleton for an asset, and prepares it for animation.
  /** @param filename - The name of the file.
    * @param flags - The assimp post-process flags to use while loading the mesh. */
  AnimatedMesh(const std::string& filename, unsigned int flags);

  /// Destructor.
  ~AnimatedMesh();

private:
  /// Just a private declaration of the copy constructor... it shouldn't be copyable.
  AnimatedMesh(const AnimatedMesh& src);

  /// Just a private declaration of the assign operator... it shouldn't be copyable.
  void operator=(const AnimatedMesh& rhs);

  /*         //=====:==-==-==:=====\\                                 //=====:==-==-==:=====\\
      <---<}>==~=~=~==--==--==~=~=~==<{>----- Skin definition -----<}>==~=~=~==--==--==~=~=~==<{>--->
             \\=====:==-==-==:=====//                                 \\=====:==-==-==:=====//          */

  /// Fills the bone_mapping with data.
  void mapBones();

  /// A recursive functions that should be started from the root node, and it returns the first bone under it.
  /** @param node - The current root node.
    * @param anim - The animation to seek the root bone in. */
  const aiNodeAnim* getRootBone(const aiNode* node, const aiScene* anim);

  template <class Index_t>
  /// Creates bone attributes data.
  /** It is a template, as the type of boneIDs shouldn't be fix. Most of the times,
    * a skeleton won't contain more than 256 bones, but that doesn't mean boneIDs
    * should be forced to GLubyte, it works with shorts and even ints too. Although
    * I really doubt anyone would be using a skeleton with more than 65535 bones... */
  void loadBones();

  /// Creates the bone attributes data (the skinning.)
  /** It actually just calls the loadBones function with the appropriate template parameter */
  void createBonesData();

  template <class Index_t>
  /// Shader plumbs the bone data.
  /** It is a template, as the type of boneIDs shouldn't be fix. Most of the times,
    * a skeleton won't contain more than 256 bones, but that doesn't mean boneIDs
    * should be forced to GLubyte, it works with shorts and even ints too. Although
    * I really doubt anyone would be using a skeleton with more than 65535 bones...
    * @param idx_t - The oglwrap enum, naming the data type that should be used.
    * @param boneIDs - Should be an array of attributes, that will be shader plumbed for the boneIDs data.
    * @param boneWeights - Should be an array of attributes, that will be shader plumbed for the boneWeights data. */
  void shaderPlumbBones(DataType idx_t, LazyVertexAttribArray boneIDs, LazyVertexAttribArray boneWeights);

private:

  aiNode* findNode(aiNode* currentRoot, const std::string& name) {
    if(currentRoot->mName.data == name)
      return currentRoot;

    for(int i = 0; i != currentRoot->mNumChildren; ++i) {
        aiNode* children_return = findNode(currentRoot->mChildren[i], name);
        if(children_return)
          return children_return;
    }

    return nullptr;
  }

  ExternalBone markChildsExternal(ExternalBone* parent, aiNode* root) {
    size_t bidx = skinning_data_.bone_mapping[root->mName.data];
    SkinningData::BoneInfo& binfo = skinning_data_.bone_info[bidx];
    binfo.external = true;
    ExternalBone ebone = {
      binfo.bone_offset,
      binfo.final_transform,
      nullptr
    };

    for(int i = 0; i < root->mNumChildren; ++i) {
        ebone.child.push_back(markChildsExternal(&ebone, root->mChildren[i]));
    }

    return ebone;
  }

public:

  /// Marks a bone to be modified from outside.
  /** @return A structure, which through the bone, and all of its child can be moved.
    * @param boneName - The name of the bone. */
  ExternalBone markBoneExternal(const std::string& boneName) {
    if(skinning_data_.bone_mapping.find(boneName) == skinning_data_.bone_mapping.end()) {
      throw std::runtime_error(
          "AnimatedMesh '" + filename_ + "' doesn't have any bone named '" + boneName + "'."
      );
    }

    return markChildsExternal(nullptr, findNode(scene_->mRootNode, boneName));
  }

  /// Returns the number of bones this scene has.
  /** May change the currently active VAO and ArrayBuffer at the first call. */
  size_t getNumBones();

  /// Returns the size that boneIds and BoneWeights attribute arrays should be.
  /** May change the currently active VAO and ArrayBuffer at the first call. */
  size_t getBoneAttribNum();

  /// Loads in bone weight and id information to the given array of attribute arrays.
  /** Uploads the bone weight and id to an array of attribute arrays, and sets it up for use.
    * For example if you specified "in vec4 boneIds[3]" you have to give "prog | boneIds"
    * Calling this function changes the currently active VAO and ArrayBuffer.
    * @param boneIDs - The array of attributes array to use as destination for bone IDs.
    * @param boneWeights - The array of attributes array to use as destination for bone weights. */
  void setupBones(LazyVertexAttribArray boneIDs, LazyVertexAttribArray boneWeights);

  /*         //=====:==-==-==:=====\\                           //=====:==-==-==:=====\\
      <---<}>==~=~=~==--==--==~=~=~==<{>----- Animation -----<}>==~=~=~==--==--==~=~=~==<{>--->
             \\=====:==-==-==:=====//                           \\=====:==-==-==:=====//          */

private:

  /// Returns the index of the currently active translation keyframe for the given animation and time.
  /// @param animationTime - The time elapsed since the start of this animation.
  /// @param node_anim - The animation node, in which the function should search for a keyframe.
  unsigned findPosition(float animationTime, const aiNodeAnim* node_anim);

  /// Returns the index of the currently active rotation keyframe for the given animation and time.
  /// @param animationTime - The time elapsed since the start of this animation.
  /// @param node_anim - The animation node, in which the function should search for a keyframe.
  unsigned findRotation(float animationTime, const aiNodeAnim* node_anim);

  /// Returns the index of the currently active scaling keyframe for the given animation and time.
  /// @param animationTime - The time elapsed since the start of this animation.
  /// @param node_anim - The animation node, in which the function should search for a keyframe.
  unsigned findScaling(float animationTime, const aiNodeAnim* node_anim);

  /// Returns a linearly interpolated value between the previous and next translation keyframes.
  /// @param out - Returns the result here.
  /// @param animationTime - The time elapsed since the start of this animation.
  /// @param node_anim - The animation node, in which the function should search for the keyframes.
  void calcInterpolatedPosition(aiVector3D& out, float animTime, const aiNodeAnim* node_anim);

  /// Returns a spherically interpolated value (always choosing the short path) between the previous and next rotation keyframes.
  /// @param out - Returns the result here.
  /// @param animationTime - The time elapsed since the start of this animation.
  /// @param node_anim - The animation node, in which the function should search for the keyframes.
  void calcInterpolatedRotation(aiQuaternion& out, float animTime, const aiNodeAnim* node_anim);

  /// Returns a linearly interpolated value between the previous and next scaling keyframes.
  /** @param out - Returns the result here.
    * @param animationTime - The time elapsed since the start of this animation.
    * @param node_anim - The animation node, in which the function should search for the keyframes. */
  void calcInterpolatedScaling(aiVector3D& out, float animTime, const aiNodeAnim* node_anim);

  /// Returns the animation node in the given animation, referenced by its name.
  /** Returns nullptr if it doesn't find a node with that name,
    * which usually means that it's not a bone.
    * @param animation - The animation, this function should search in.
    * @param node_name - The name of the bone to search. */
  const aiNodeAnim* findNodeAnim(const aiAnimation* animation, const std::string node_name);

  /// Recursive function that travels through the entire node hierarchy, and creates transformation values in world space.
  /** Bone transformations are stored relative to their parents. That's why it is needed.
    * Also note, that the translation of the root node on the XZ plane is treated differently, that offset isn't
    * baked into the animation, you can get the offset with the offsetSinceLastFrame() function, and you have to
    * externally do the object's movement, as normally it will stay right where it was at the start of the animation.
    * @param animationTime - The current animation time.
    * @param node - The node (bone) whose, and whose child's transformation should be updated. You should call this function with the root node.
    * @param parent_transform - The transformation of the parent node. You should call it with an identity matrix. */
  void updateBoneTree(float animationTime,
                      const aiNode* node,
                      const glm::mat4& parent_transform = glm::mat4());

  /// Does the same thing as readNodeHierarchy, but it is used to create transitions between animations, so it interpolates between four keyframes not two.
  /** @param prevAnimationTime - The animation time of when, the last animation was interrupted.
    * @param nextAnimationTime - The current animation time.
    * @param node - The node (bone) whose, and whose child's transformation should be updated. You should call this function with the root node.
    * @param parent_transform - The transformation of the parent node. You should call it with an identity matrix. */
  void updateBoneTreeInTransition(float prevAnimationTime,
                                  float nextAnimationTime,
                                  float factor,
                                  const aiNode* node,
                                  const glm::mat4& parent_transform  = glm::mat4());

  /// Does what it's name says, updates the bones transformations.
  /** @param time_in_seconds - Expected to be a time value in seconds. It doesn't matter, since when does it count the time, just it should be counting up. */
  void updateBoneInfo(float time_in_seconds);

public:

  /// Updates the bones transformation and uploads them into the given uniforms.
  /** @param time_in_seconds - Expect a time value as a float, optimally since the start of the program.
    * @param bones - The uniform naming the bones array. It should be indexable. */
  void boneTransform(float time_in_seconds,
                     LazyUniform<glm::mat4>& bones);

  /*       //=====:==-==-==:=====\\                                   //=====:==-==-==:=====\\
    <---<}>==~=~=~==--==--==~=~=~==<{>----- Animation Control -----<}>==~=~=~==--==--==~=~=~==<{>--->
           \\=====:==-==-==:=====//                                   \\=====:==-==-==:=====//       */

  /// Adds an external animation from a file.
  /** You should give this animation a name, you will be able to
    * reference it with this name in the future. You can also set
    * the default animation modifier flags for this animation.
    * These flags will be used everytime you change to this animation
    * without explicitly specifying new flags.
    * @param filename - The name of the file, from where to load the animation.
    * @param anim_name - The name with you wanna reference this animation.
    * @param flags - You can specify animation modifiers, like repeat the animation after it ends, play it backwards, etc...
    * @param speed - Sets the default speed of the animation. If it's 1, it will be played with the its default speed. If it's negative, it will be played backwards. */
  void addAnimation(const std::string& filename,
                    const std::string& anim_name,
                    unsigned flags = AnimFlag::None,
                    float speed = 1.0f);

  /// Sets the default animation, that will be played if you don't set to play another one.
  /** @param anim_name - The user-defined name of the animation that should be set to be default.
    * @param default_transition_time - The fading time that should be used when changing to the default animation. */
  void setDefaultAnimation(const std::string& anim_name,
                           float default_transition_time = 0.0f);

private:
  /// Changes the current animation to a specified one.
  /** @param anim_idx - The index of the new animation.
    * @param current_time - The current time in seconds, optimally since the start of the program.
    * @param transition_time - The fading time to be used for the transition.
    * @param flags - A bitfield containing the animation specifier flags.
    * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
  void changeAnimation(size_t anim_idx,
                       float current_time,
                       float transition_time,
                       unsigned flags,
                       float speed = 1.0f);

public:
  /// Tries to change the current animation to a specified one.
  /** Only changes it if the current animation is interruptable,
    * it's not currently in a transition, and new animation is
    * not the same as the one currently playing.
    * @param anim_name - The user-defined name of the animation.
    * @param current_time - The current time in seconds, optimally since the start of the program.
    * @param transition_time - The fading time to be used for the transition.
    * @param flags - A bitfield containing the animation specifier flags.
    * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
  void setCurrentAnimation(const std::string& anim_name,
                           float current_time,
                           float transition_time,
                           unsigned flags,
                           float speed = 0.0f);

  /// Forces the current animation to a specified one.
  /** Only changes it if the new animation is not the same as the one currently playing.
    * @param anim_name - The user-defined name of the animation.
    * @param current_time - The current time in seconds, optimally since the start of the program.
    * @param transition_time - The fading time to be used for the transition.
    * @param flags - A bitfield containing the animation specifier flags.
    * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
  void forceCurrentAnimation(const std::string& anim_name,
                             float current_time,
                             float transition_time,
                             unsigned flags,
                             float speed = 0.0f);

  /// Tries to change the current animation to a specified one, using the default anim modifier flags specified for this anim.
  /** Only changes it if the current animation is interruptable,
    * it's not currently in a transition, and new animation is
    * not the same as the one currently playing.
    * @param anim_name - The user-defined name of the animation.
    * @param current_time - The current time in seconds, optimally since the start of the program.
    * @param transition_time - The fading time to be used for the transition.
    * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
  void setCurrentAnimation(const std::string& anim_name,
                           float current_time,
                           float transition_time = 0.0f,
                           float speed = 0.0f);

  /// Forces the current animation to a specified one, using the default anim modifier flags specified for this anim.
  /** Only changes it if the new animation is not the same as the one currently playing.
    * @param anim_name - The user-defined name of the animation.
    * @param current_time - The current time in seconds, optimally since the start of the program.
    * @param transition_time - The fading time to be used for the transition.
    * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
  void forceCurrentAnimation(const std::string& anim_name,
                             float current_time,
                             float transition_time = 0.0f,
                             float speed = 0.0f);

  /// Tries to change the current animation to the default one.
  /** Only changes it if the current animation is interruptable,
    * it's not currently in a transition, and new animation is
    * not the same as the one currently playing. Will use the default
    * anim modifier flags for the default anim.
    * @param current_time - The current time in seconds, optimally since the start of the program. */
  void setAnimToDefault(float current_time);

  /// Forces the current animation to the default one.
  /** Only changes it if the new animation is not the same as the one currently
    * playing. Will use the default anim modifier flags for the default anim.
    * @param current_time - The current time in seconds, optimally since the start of the program. */
  void forceAnimToDefault(float current_time);

  /// Returns the offset of the root bone, since it was last queried.
  /** It should be queried every frame (hence the name),
    * but it works even if you only query every 10th frame,
    * just the animation will "lag", and will look bad. */
  glm::vec2 offsetSinceLastFrame();

}; // AnimatedMesh

} // namespace oglwrap

#include "animatedMesh_general-inl.hpp"
#include "animatedMesh_skinning-inl.hpp"
#include "animatedMesh_animation-inl.hpp"
#include "animatedMesh_animation-control-inl.hpp"

#endif // OGLWRAP_MESH_ANIMATEDMESH_HPP_
