// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_ENUMS_PROVOKE_MODE_H_
#define OGLWRAP_ENUMS_PROVOKE_MODE_H_

#include "../config.h"

namespace oglwrap {

inline namespace enums {

enum class ProvokeMode : GLenum {
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_FIRST_VERTEX_CONVENTION)
  FirstVertexConvention = GL_FIRST_VERTEX_CONVENTION,
#endif
#if OGLWRAP_DEFINE_EVERYTHING || defined(GL_LAST_VERTEX_CONVENTION)
  LastVertexConvention = GL_LAST_VERTEX_CONVENTION,
#endif
};

} // enums

} // oglwrap

#endif
