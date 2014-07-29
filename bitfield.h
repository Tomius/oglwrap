// Copyright (c) 2014, Tamas Csala

/** @file bitfield.h
    @brief Generic bitfield class to replace GLbitfield
*/

#ifndef OGLWRAP_BITFIELD_H_
#define OGLWRAP_BITFIELD_H_

#include <initializer_list>

#include "./config.h"

namespace OGLWRAP_NAMESPACE_NAME {

template <typename Bit>
class Bitfield {
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

 private:
  GLbitfield bits_;
};

}  // namespace oglwrap

#endif  // OGLWRAP_BITFIELD_H_
