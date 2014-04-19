#ifndef OGLWRAP_MESH_ANIM_STATE_HPP_
#define OGLWRAP_MESH_ANIM_STATE_HPP_

#include "mesh.hpp"

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
  /** For example, this flag makes a walk animation become a moonwalk.
    * (The character will be animated as he/she was moving forwards, back
    * he/she actually moves backwards.) */
  Mirrored = 0x4,

  /// Plays the animation backwards
  Backwards = 0x8,

  /// Marks the animation as interruptable by other animations.
  /** Only affects setCurrentAnimation, forceCurrentAnimation ignores it.
    * This logically shouldn't be part of the animation loader & player,
    * but it can help to make your code easier to read. */
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

  /// Default constructor.
  AnimationState()
      : handle(nullptr)
      , idx(0)
      , flags(0)
      , speed(1.0f)
  { }
};

/// A placeholder class for passing AnimationParameters
struct AnimParams {
  /// The name of the animation
  std::string name;

  /// The transition time between the last, and this animation, in seconds
  float transition_time;

  /// Specifies if the default flags should be used for this animation
  bool use_default_flags;

  /// A "bitfield" of the Animation modifying flags
  unsigned flags;

  /// The speed multiplier
  float speed;

  /// Creates a placeholder class for passing AnimationParameters
  /** @param name - The name of the animation.
    * @param transition_time - The transition time between the last, and this animation, in seconds.
    * @param flags - A "bitfield" of the Animation modifying flags
    * @param speed - The speed multiplier. Uses the default anim speed if it is zero */
  AnimParams(std::string name,
             float transition_time,
             unsigned flags,
             float speed = 0.0f)
      : name(name)
      , transition_time(transition_time)
      , use_default_flags(false)
      , flags(flags)
      , speed(speed)
  { }

  /// Creates a placeholder class for passing AnimationParameters using the default animation flags.
  /** @param name - The name of the animation.
    * @param transition_time - The transition time between the last, and this animation, in seconds.
    * @param speed - The speed multiplier. Uses the default anim speed if it is zero */
  AnimParams(std::string name = "",
             float transition_time = 0.1f,
             float speed = 0.0f)
      : name(name)
      , transition_time(transition_time)
      , use_default_flags(true)
      , flags(AnimFlag::None)
      , speed(speed)
  { }
};

} // namespace oglwrap

#endif // OGLWRAP_MESH_ANIM_STATE_HPP_
