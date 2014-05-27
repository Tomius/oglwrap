// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_EXTENSIONS_H_
#define OGLWRAP_CONTEXT_EXTENSIONS_H_

#include <cstring>
#include "../config.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

// See http://www.opengl.org/archives/resources/features/OGLextensions
inline bool IsExtensionSupported(const char *extension) {
  const GLubyte *extensions = NULL;
  const GLubyte *start;

  GLubyte *where, *terminator;
  /* Extension names should not have spaces. */

  where = (GLubyte *) strchr(extension, ' ');

  if (where || *extension == '\0')
    return false;

  extensions = gl(GetString(GL_EXTENSIONS));

  /* It takes a bit of care to be fool-proof about parsing the
     OpenGL extensions string. Don't be fooled by sub-strings,
     etc. */

  start = extensions;

  for (;;) {
    where = (GLubyte *) strstr((const char *) start, extension);
    if (!where)
      break;

    terminator = where + strlen(extension);

    if (where == start || *(where - 1) == ' ')
      if (*terminator == ' ' || *terminator == '\0')
        return true;

    start = terminator;
  }

  return false;
}

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif
