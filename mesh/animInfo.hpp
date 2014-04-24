#ifndef OGLWRAP_MESH_ANIMINFO_HPP_
#define OGLWRAP_MESH_ANIMINFO_HPP_

#include <map>

#include "../assimp.hpp"

namespace oglwrap {

/// A struct storing info per animation
struct AnimInfo {
  /// The importer that stores the animations.
  Assimp::Importer* importer;

  /// Handle for the animations
  const aiScene* handle;

  /// The name of the animation.
  std::string name;

  /// Default animation flag for this animation.
  unsigned flags;

  /// Default speed modifier.
  float speed;

  /// The offset value at the starts of the animation.
  glm::vec3 start_offset;

  /// The offset values at the ends of the animations.
  glm::vec3 end_offset;

  /// Default constructor
  AnimInfo()
      : importer(nullptr)
      , handle(nullptr)
      , flags(0)
      , speed(1.0f)
  { }
};

struct AnimMetaInfo {
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

  /// It is used to detect when did the animation start a new cycle.
  /** For animations that have AnimFlag::Repeat flag specified only, of course. */
  unsigned last_loop_count;

  AnimMetaInfo()
      : default_idx(0)
      , default_transition_time(0.0f)
      , transition_time(0.0f)
      , end_of_last_anim(0.0f)
      , last_period_time(0.0f)
      , last_loop_count(0.0f)
  { }
};

struct AnimData {
  /// Handles for the animations
  std::vector<AnimInfo> data;

  /// maps user defined animation names to indexes.
  std::map<std::string, size_t> names;

  AnimInfo& operator[](size_t idx) {
    return data[idx];
  }

  const AnimInfo& operator[](size_t idx) const {
    return data[idx];
  }

  AnimInfo& operator[](std::string anim_name) {
    return data[names[anim_name]];
  }

  bool canFind(std::string anim_name) {
    return names.find(anim_name) != names.end();
  }
};

} // namespace oglwrap

#endif // OGLWRAP_MESH_ANIMINFO_HPP_
