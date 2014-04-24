/** @file general.hpp
    @brief Contains codes that are not related to OpenGL
*/

#ifndef OGLWRAP_GENERAL_HPP_
#define OGLWRAP_GENERAL_HPP_

#include <cmath>
#include <memory>

#include "config.hpp"

/// A template to convert an angle value from degrees to radians
template<class T>
T ToRadian(const T& x) {
  return fmod(x * M_PI / 180.0f, 2 * M_PI);
}

/// A template to convert an angle value from radians to degrees
template<class T>
T ToDegree(const T& x) {
  return fmod(x * 180.0f / M_PI, 360.0f);
}

namespace oglwrap {

/// A class for managing OpenGL resources.
class glObject {
protected:
  /// The C handle for the object.
  std::shared_ptr<GLuint> handle_;
  glObject() : handle_(new GLuint{0}) {}

public:
  /// Returns if this is the only instance of this glObject
  bool unique() const { return handle_.unique(); }

#if OGLWRAP_INITIALIZE_GLOBAL_GL_OBJECTS_ON_USE
  virtual void constructor() const = 0;
#endif

  /// Returns the C handle for the object.
  operator GLuint() const {
#if OGLWRAP_INITIALIZE_GLOBAL_GL_OBJECTS_ON_USE
    if(*handle_ == 0) {
      constructor();
    }
#endif
     return *handle_;
   }
};

} // namespace oglwrap

#endif // OGLWRAP_GENERAL_HPP_
