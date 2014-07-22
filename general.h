// Copyright (c) 2014, Tamas Csala

/** @file general.h
    @brief Contains codes that are not related to OpenGL
*/

#ifndef OGLWRAP_GENERAL_H_
#define OGLWRAP_GENERAL_H_

#include <cmath>
#include <memory>
#include <initializer_list>

#include "config.h"

#ifndef M_PI
  #define M_PI 3.14159265359f
#endif

namespace OGLWRAP_NAMESPACE_NAME {

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

template <typename Bit>
class Bitfield {
  GLbitfield bits_;
public:
  Bitfield() : bits_(0) {}
  Bitfield(GLbitfield bits) : bits_(bits) {}
  Bitfield(Bit bit) : bits_(GLbitfield(bit)) {}

  template<typename Iterator>
  Bitfield(const Iterator& begin, const Iterator& end) : bits_(0) {
    for (Iterator i = begin; i != end; ++i) {
      bits_ |= static_cast<GLbitfield>(*i);
    }
  }

  Bitfield(const std::initializer_list<Bit>& bits) : bits_(0) {
    for (Bit b : bits) {
      bits_ |= static_cast<GLbitfield>(b);
    }
  }

  Bitfield operator|(Bitfield b) const {
    return Bitfield{bits_ | b.bits_};
  }

  Bitfield operator|(Bit b) const {
    return Bitfield{bits_ | static_cast<GLbitfield>(b)};
  }

  Bitfield& operator|=(Bitfield b) {
    bits_ |= b.bits_;
    return *this;
  }

  Bitfield& operator|=(Bit b) {
    bits_ |= static_cast<GLbitfield>(b);
    return *this;
  }

  Bitfield operator&(Bitfield b) const {
    return Bitfield{bits_ & b.bits_};
  }

  Bitfield operator&(Bit b) const {
    return Bitfield{bits_ & static_cast<GLbitfield>(b)};
  }

  Bitfield& operator&=(Bitfield b) {
    bits_ &= b.bits_;
    return *this;
  }

  Bitfield& operator&=(Bit b) {
    bits_ &= static_cast<GLbitfield>(b);
    return *this;
  }

  Bitfield operator^(Bitfield b) const {
    return Bitfield{bits_ ^ b.bits_};
  }

  Bitfield operator^(Bit b) const {
    return Bitfield{bits_ ^ static_cast<GLbitfield>(b)};
  }

  Bitfield& operator^=(Bitfield b) {
    bits_ ^= b.bits_;
    return *this;
  }

  Bitfield& operator^=(Bit b) {
    bits_ ^= static_cast<GLbitfield>(b);
    return *this;
  }

  operator GLbitfield() const {
    return bits_;
  }

  bool test(Bit b) const {
    return (bits_ & static_cast<GLbitfield>(b)) == static_cast<GLbitfield>(b);
  }

  bool test(Bitfield b) const {
    return (bits_ & static_cast<GLbitfield>(b)) == static_cast<GLbitfield>(b);
  }

};

} // namespace oglwrap

#endif  // OGLWRAP_GENERAL_H_
