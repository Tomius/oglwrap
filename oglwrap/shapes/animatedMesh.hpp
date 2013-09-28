/** @file animatedMesh.hpp
    @brief An animation loader using assimp
*/

#ifndef OGLWRAP_SHAPES_ANIMATEDMESH_HPP_
#define OGLWRAP_SHAPES_ANIMATEDMESH_HPP_

#include "mesh.hpp"
#include "../config.hpp"

namespace oglwrap {

namespace _AnimFlag {
/// Animation modifying flags.
enum AnimFlag {
  /// Doesn't do anything.
  None = 0x0,

  /// Repeats the animation until it's interrupted by another animation.
  Repeat = 0x1,

  /// Repeats the animation, but repeats it like OpenGL's MirroredRepeat.
  /** You can get this effect by setting repeat to true, and negating the
    * mirrored and backwards flags after every repetition. */
  MirroredRepeat = 0x3,

  /// Mirrors the movement during the animation.
  /** For example, for a walking with Mirrored flag will cause Moonwalk.
    * (The character will be animated as he/she was moving forwards, back
    * he/she actually moves backwards.) */
  Mirrored = 0x4,

  /// Plays the animation backwards
  Backwards = 0x8,

  /// Marks the animation as interruptable by other animations.
  /** Tip: if your animation is a cycle, 99% that you'll want it be
    * interruptable, however, single animations like a jump, usually
    * shouldn't be interrupted by another animations. */
  Interruptable = 0x10
};
}
typedef _AnimFlag::AnimFlag AnimFlag;

/// A class storing an animation's state.
struct AnimationState {
  /// The handle to the animation.
  const aiScene* handle;

  /// The index of the animation in the anim vector.
  size_t idx;

  /// The offset of the root bone of the animated object inside the animation, on the XZ plain.
  glm::vec3 offset;

  /// The current animation modifier flags.
  unsigned flags;

  /// The speed modifier
  float speed;

  /// Default constructor
  AnimationState()
      : handle(nullptr)
      , idx(0)
      , flags(0)
      , speed(1.0f)
  { }
};

class AnimatedMesh : public Mesh {

  template<class Index_t>
  /// A struct containing an "ivec4" for the boneIDs, and a vec4 for bone weights.
  /** The boneIDs part is not fixed to be int (unsigned), it becomes the smallest type
    * that possible to store the all the ids of the bones. */
  struct VertexBoneData_PerAttribute;

  template<class Index_t>
  /// Contains an array of VertexBoneData_PerAttribute.
  /** The size of that vector varies per vertex. */
  struct VertexBoneData;

  /// A structure for storing the default, relative-to-parent, and current transformations.
  struct BoneInfo;

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

  /// Stores if setup_bones is called. It shouldn't be called more than once.
  bool is_setup_bones;

  /// Stores the root node transform's inverse-
  glm::mat4 global_inverse_transform;

  /// Stores the importers that store the additional animations loaded by addAnimation calls.
  /** Has to be a pointer. vector::push_back(Assimp::Importer()) wouldn't work, because it has
    * a weird copy constructor, that doesn't actually copy. It must be dynamic. */
  std::vector<Assimp::Importer*> animation_importers;

  /// Handles for the animations
  std::vector<const aiScene*> animations;

  /// maps user defined animation names to indexes.
  std::map<std::string, size_t> anim_names;

  /// The index of the default animation.
  size_t default_idx;

  /// The fading time that is used when changing the animation back to the default one.
  float default_transition_time;

  /// The fading time between the previous and the current animation.
  float transition_time;

  /// The time of when did the last animation end.
  /** It is needed to know the time in the current animation. */
  float end_of_last_anim;

  /// The animation of time the previous animation.
  /** It is needed to make the transition between two animations. */
  float last_period_time;

  /// The offset values at the starts of the animations
  std::vector<glm::vec3> start_offsets;

  /// The offset values at the ends of the animations
  std::vector<glm::vec3> end_offsets;

  /// It is used to detect when did the animation start a new cycle.
  /** For animations that have AnimFlag::Repeat flag specified only, of course. */
  unsigned last_loop_count;

  /// The name of the root bone. It's usually not equal to the root node. It is need to get the offsets.
  std::string root_bone;

  /// Default animation flags specified in the addAnimation function.
  std::vector<unsigned> default_flags;

  /// Default speed modifiers
  std::vector<float> speed_modifiers;

  /// The current animation.
  AnimationState current_anim;

  /// The last animation.
  AnimationState last_anim;

public:
  AnimatedMesh(const std::string& filename, unsigned int flags)
    : Mesh(filename, flags)
    , vertex_bone_data_buffers(scene->mNumMeshes)
    , num_bones(0)
    , max_bone_attrib_num(0)
    , is_setup_bones(false)
    , default_idx(0)
    , default_transition_time(0)
    , transition_time(0)
    , end_of_last_anim(0)
    , last_period_time(0)
    , last_loop_count(0) {

    glm::mat4 matrix = convertMatrix(scene->mRootNode->mTransformation);
    global_inverse_transform = glm::inverse(matrix);
  }

  ~AnimatedMesh() {
    for(auto i = animation_importers.begin(); i != animation_importers.end(); i++) {
      delete *i;
    }
  }

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
  void create_bones_data();

  template <class Index_t>
  /// Shader plumbs the bone data.
  /** It is a template, as the type of boneIDs shouldn't be fix. Most of the times,
    * a skeleton won't contain more than 256 bones, but that doesn't mean boneIDs
    * should be forced to GLubyte, it works with shorts and even ints too. Although
    * I really doubt anyone would be using a skeleton with more than 65535 bones...
    * @param idx_t - The oglwrap enum, naming the data type that should be used.
    * @param boneIDs - Should be an array of attributes, that will be shader plumbed for the boneIDs data.
    * @param boneWeights - Should be an array of attributes, that will be shader plumbed for the boneWeights data. */
  void shader_plumb_bones(DataType idx_t, LazyVertexAttribArray boneIDs, LazyVertexAttribArray boneWeights);

public:
  /// Returns the number of bones this scene has.
  /** May change the currently active VAO and ArrayBuffer at the first call. */
  size_t get_num_bones();

  /// Returns the size that boneIds and BoneWeights attribute arrays should be.
  /** May change the currently active VAO and ArrayBuffer at the first call. */
  size_t get_bone_attrib_num();

  /// Loads in bone weight and id information to the given array of attribute arrays.
  /** Uploads the bone weight and id to an array of attribute arrays, and sets it up for use.
    * For example if you specified "in vec4 boneIds[3]" you have to give "prog | boneIds"
    * Calling this function changes the currently active VAO and ArrayBuffer.
    * @param boneIDs - The array of attributes array to use as destination for bone IDs.
    * @param boneWeights - The array of attributes array to use as destination for bone weights. */
  void setup_bones(LazyVertexAttribArray boneIDs, LazyVertexAttribArray boneWeights);

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
    * baked into the animation, you can get the offset with the offset_since_last_frame() function, and you have to
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
  void updateBoneTree_inTransition(float prevAnimationTime,
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
    * @param animName - The name with you wanna reference this animation.
    * @param flags - You can specify animation modifiers, like repeat the animation after it ends, play it backwards, etc...
    * @param speed - Sets the default speed of the animation. If it's 1, it will be played with the its default speed. If it's negative, it will be played backwards. */
  void add_animation(const std::string& filename,
                     const std::string& animName,
                     unsigned flags = AnimFlag::None,
                     float speed = 1.0f);

  /// Sets the default animation, that will be played if you don't set to play another one.
  /** @param animName - The user-defined name of the animation that should be set to be default.
    * @param default_transition_time - The fading time that should be used when changing to the default animation. */
  void set_default_animation(const std::string& animName,
                             float default_transition_time = 0.0f);

private:
  /// Changes the current animation to a specified one.
  /** @param anim_idx - The index of the new animation.
    * @param currentTime - The current time in seconds, optimally since the start of the program.
    * @param transition_time - The fading time to be used for the transition.
    * @param flags - A bitfield containing the animation specifier flags.
    * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
  void change_animation(size_t anim_idx,
                        float currentTime,
                        float transition_time,
                        unsigned flags,
                        float speed = 1.0f);

public:
  /// Tries to change the current animation to a specified one.
  /** Only changes it if the current animation is interruptable,
    * it's not currently in a transition, and new animation is
    * not the same as the one currently playing.
    * @param animName - The user-defined name of the animation.
    * @param currentTime - The current time in seconds, optimally since the start of the program.
    * @param transition_time - The fading time to be used for the transition.
    * @param flags - A bitfield containing the animation specifier flags.
    * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
  void set_current_animation(const std::string& animName,
                             float currentTime,
                             float transition_time,
                             unsigned flags,
                             float speed = 0.0f);

  /// Forces the current animation to a specified one.
  /** Only changes it if the new animation is not the same as the one currently playing.
    * @param animName - The user-defined name of the animation.
    * @param currentTime - The current time in seconds, optimally since the start of the program.
    * @param transition_time - The fading time to be used for the transition.
    * @param flags - A bitfield containing the animation specifier flags.
    * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
  void force_current_animation(const std::string& animName,
                               float currentTime,
                               float transition_time,
                               unsigned flags,
                               float speed = 0.0f);

  /// Tries to change the current animation to a specified one, using the default anim modifier flags specified for this anim.
  /** Only changes it if the current animation is interruptable,
    * it's not currently in a transition, and new animation is
    * not the same as the one currently playing.
    * @param animName - The user-defined name of the animation.
    * @param currentTime - The current time in seconds, optimally since the start of the program.
    * @param transition_time - The fading time to be used for the transition.
    * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
  void set_current_animation(const std::string& animName,
                             float currentTime,
                             float transition_time = 0.0f,
                             float speed = 0.0f);

  /// Forces the current animation to a specified one, using the default anim modifier flags specified for this anim.
  /** Only changes it if the new animation is not the same as the one currently playing.
    * @param animName - The user-defined name of the animation.
    * @param currentTime - The current time in seconds, optimally since the start of the program.
    * @param transition_time - The fading time to be used for the transition.
    * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
  void force_current_animation(const std::string& animName,
                               float currentTime,
                               float transition_time = 0.0f,
                               float speed = 0.0f);

  /// Tries to change the current animation to the default one.
  /** Only changes it if the current animation is interruptable,
    * it's not currently in a transition, and new animation is
    * not the same as the one currently playing. Will use the default
    * anim modifier flags for the default anim.
    * @param currentTime - The current time in seconds, optimally since the start of the program. */
  void set_anim_to_default(float currentTime);

  /// Forces the current animation to the default one.
  /** Only changes it if the new animation is not the same as the one currently
    * playing. Will use the default anim modifier flags for the default anim.
    * @param currentTime - The current time in seconds, optimally since the start of the program. */
  void force_anim_to_default(float currentTime);

  /// Returns the offset of the root bone, since it was last queried.
  /** It should be queried every frame (hence the name),
    * but it works even if you only query every 10th frame,
    * just the animation will "lag", and will look bad. */
  glm::vec3 offset_since_last_frame();

}; // AnimatedMesh

} // namespace oglwrap

#include "animatedMesh_general-inl.hpp"
#include "animatedMesh_skinning-inl.hpp"
#include "animatedMesh_animation-inl.hpp"
#include "animatedMesh_animation-control-inl.hpp"

#endif // OGLWRAP_SHAPES_ANIMATEDMESH_HPP_
