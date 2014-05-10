#ifndef OGLWRAP_ENUMS_MIN_FILTER_HPP_
#define OGLWRAP_ENUMS_MIN_FILTER_HPP_

#include "../config.hpp"

namespace oglwrap {

inline namespace enums {

enum class MinFilter : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST)
  Nearest = GL_NEAREST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR)
  Linear = GL_LINEAR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_NEAREST)
  NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_NEAREST_MIPMAP_LINEAR)
  NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_NEAREST)
  LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINEAR_MIPMAP_LINEAR)
  LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR,
#endif
};

} // enums

} // oglwrap

#endif
