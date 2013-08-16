/** @file general.hpp
    @brief Contains codes that aren't related to OpenGL
*/

#ifndef GENERAL_HPP
#define GENERAL_HPP

/// Macro to convert an angle value from degrees to radians
#define ToRadian(x) ((x) * M_PI / 180.0f)

/// Macro to convert an angle value from radians to degrees
#define ToDegree(x) ((x) * 180.0f / M_PI)

namespace oglwrap {

/// A simple reference counter that you should use with inheritance.
/** If your class inherit from this class (protected inheritance recommended),
  * at your class' destructor you can call isDeletable(), which returns true
  * if exactly one instance of that object exists. Note that OpenGL RAII needs
  * to be reference counted! */
class RefCounted {
    int *numInstances; /// A dynamically allocated int that stores the number of currently active instances.
protected:
    /// Returns if only one instance of this object exists.
    bool isDeletable() {
        return *numInstances == 1;
    }

    /// Allocates the counter.
    RefCounted() {
        numInstances = new int;
        *numInstances = 1;
    }

    /// Creates a copy (copy ctor), and increases counter.
    RefCounted(const RefCounted& rhs) {
        numInstances = rhs.numInstances;
        (*numInstances)++;
    }

    /// Creates a copy (assign op), and increases counter.
    RefCounted& operator=(const RefCounted& rhs) {
        numInstances = rhs.numInstances;
        (*numInstances)++;
        return *this;
    }

    /// Decreases counter, or deletes the counter.
    ~RefCounted() {
        if(isDeletable())
            delete numInstances;
        else
            (*numInstances)--;
    }
};

} // namespace oglwrap

#endif // GENERAL_HPP
