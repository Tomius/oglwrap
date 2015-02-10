// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_DEBUG_INSERTION_H_
#define OGLWRAP_DEBUG_INSERTION_H_

#include <iostream>
#include <string>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

template <typename T, glm::precision P>
/// Prints a glm vector to a given ostream.
/** @param os - The ostream.
  * @param v - The vector. */
static inline std::ostream& operator<<(std::ostream& os, const glm::tvec2<T, P>& v) {
  os << v.x << ", " << v.y;
  return os;
}

template <typename T, glm::precision P>
/// Prints a glm vector to a given ostream.
/** @param os - The ostream.
  * @param v - The vector. */
static inline std::ostream& operator<<(std::ostream& os, const glm::tvec3<T, P>& v) {
  os << v.x << ", " << v.y << ", " << v.z;
  return os;
}

template <typename T, glm::precision P>
/// Prints a glm vector to a given ostream.
/** @param os - The ostream.
  * @param v - The vector. */
static inline std::ostream& operator<<(std::ostream& os, const glm::tvec4<T, P>& v) {
  os << v.x << ", " << v.y << ", " << v.z << ", " << v.w;
  return os;
}

template <typename T, glm::precision P>
/// Prints a glm vector to a given ostream.
/** @param os - The ostream.
  * @param v - The vector. */
static inline std::ostream& operator<<(std::ostream& os, const glm::tquat<T, P>& v) {
  os << v.x << ", " << v.y << ", " << v.z << ", " << v.w;
  return os;
}

template <typename T, glm::precision P>
/// Prints a glm matrix to a given ostream.
/** @param os - The ostream.
  * @param mat - The matrix. */
static inline std::ostream& operator<<(std::ostream& os, const glm::tmat2x2<T, P>& mat) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout << mat[j][i];
      if (i != 1 || j != 1) {
        std::cout  << ", ";
      }
    }
    std::cout << std::endl;
  }
  return os;
}

template <typename T, glm::precision P>
/// Prints a glm matrix to a given ostream.
/** @param os - The ostream.
  * @param mat - The matrix. */
static inline std::ostream& operator<<(std::ostream& os, const glm::tmat3x3<T, P>& mat) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << mat[j][i];
      if (i != 2 || j != 2) {
        std::cout  << ", ";
      }
    }
    std::cout << std::endl;
  }
  return os;
}

template <typename T, glm::precision P>
/// Prints a glm matrix to a given ostream.
/** @param os - The ostream.
  * @param mat - The matrix. */
static inline std::ostream& operator<<(std::ostream& os, const glm::tmat4x4<T, P>& mat) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << mat[j][i];
      if (i != 3 || j != 3) {
        std::cout  << ", ";
      }
    }
    std::cout << std::endl;
  }
  return os;
}

#endif  // OGLWRAP_GLOBAL_H_
