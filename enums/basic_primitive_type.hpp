#ifndef OGLWRAP_ENUMS_BASIC_PRIMITIVE_TYPE_HPP_
#define OGLWRAP_ENUMS_BASIC_PRIMITIVE_TYPE_HPP_

#include "../config.hpp"

namespace oglwrap {

inline namespace enums {

enum class BasicPrimitiveType : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_TRIANGLES)
  Triangles = GL_TRIANGLES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LINES)
  Lines = GL_LINES,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_POINTS)
  Points = GL_POINTS,
#endif
};

} // enums

} // oglwrap

#endif
