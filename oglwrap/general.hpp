/** @file general.hpp
    @brief Contains codes that are (mostly) not related to OpenGL
*/

#ifndef OGLWRAP_GENERAL_HPP_
#define OGLWRAP_GENERAL_HPP_

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

/// A simple reference counter that you should use with inheritance.
/** If your class inherit from this class (w/ protected or public inheritance),
  * at your class' destructor you can call isDeletable(), which returns true
  * if exactly one instance of that object exists. Note that OpenGL RAII needs
  * to be reference counted! */
class RefCounted {
  int *numInstances_; ///< A dynamically allocated int that stores the number of currently active instances.

protected:
  /// Allocates the counter.
  RefCounted() {
    numInstances_ = new int;
    *numInstances_ = 1;
  }

public:
  /// Creates a copy (copy ctor), and increases counter.
  RefCounted(const RefCounted& rhs) {
    numInstances_ = rhs.numInstances_;
    (*numInstances_)++;
  }

  /// Creates a copy (assign op), and increases counter.
  RefCounted& operator=(const RefCounted& rhs) {
    numInstances_ = rhs.numInstances_;
    (*numInstances_)++;
    return *this;
  }

  /// Returns if only one instance of this object exists.
  bool isDeletable() {
    return *numInstances_ == 1;
  }

  /// Decreases counter, or deletes the counter.
  ~RefCounted() {
    if(isDeletable()) {
      delete numInstances_;
    } else {
      (*numInstances_)--;
    }
  }
};

template <typename T>
/// A reference counted pointer that manages a dynamically allocated object.
/** It releases the resource, if no reference would point to this object. */
class SmartPtr : protected RefCounted {
  T* const ptr; /// < The pointer to the resource
public:
  /// Default ctr. Dynamically allocates a new object with its default ctor
  SmartPtr()
    : ptr(new T())
  { }

  /// Constructs the SmartPointer from an existing pointer to a dynamically allocated object.
  SmartPtr(T* ptr)
    : ptr(ptr)
  { }

  /// Releases the resource, if no reference would point to this object.
  ~SmartPtr() {
    if(isDeletable()) {
      delete ptr;
    }
  }

  /// Returns the pointer.
  operator T*() const {
    return ptr;
  }

  /// Returns the object.
  operator T&() const {
    return *ptr;
  }
};

/// A class for managing OpenGL resources.
class Object : public RefCounted {
private:
  /// The boolean for the object being initialized.
  /** It is a pointer because it is shared between the copies. If one inits
    * the handle, then all instances will have the inited handle */
  bool *inited_;

  /// Allocates the resource. It only happens upon the first use.
  void init() const {
    *inited_ = true;
    constructor();
  }

protected:
  /// The C handle for the object.
  GLuint *handle_;

public:
  /// Creates the object, but does not allocate any resource yet.
  Object()
    : inited_(new bool)
    , handle_(new GLuint) {

    *inited_ = false;
  }

  /// Deletes the object.
  /** Deletes the resource if only one instance of
    * this object exists, and it is initialized. */
  ~Object() {
    if(isDeletable()) {
      if(*inited_) {
        destructor();
      }
      delete inited_;
      delete handle_;
    }
  }

  /// The GL function that allocates the name for this object. Must be overwritten.
  virtual void constructor() const {}

  /// The GL function that deallocates the name of this object. Must be overwritten.
  virtual void destructor() const {}

  /// Returns the C handle for the object. Inits it, if this is the first call for it.
  operator GLuint() const {
    if(!*inited_) {
      init();
    }

    return *handle_;
  }
};

} // namespace oglwrap

#endif // OGLWRAP_GENERAL_HPP_
