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
  /** For example, for a walking with Mirrored flag will cause Moonwalk.
    * (The character will be animated as he/she was moving forwards, back
    * he/she actually moves backwards.) */
  Mirrored = 0x4,

  /// Plays the animation backwards
  Backwards = 0x8
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

} // namespace oglwrap

#endif // OGLWRAP_MESH_ANIM_STATE_HPP_
