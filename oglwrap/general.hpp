/** @file general.hpp
    @brief Contains codes that aren't related to OpenGL
*/

#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <functional>

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
    int *numInstances; ///< A dynamically allocated int that stores the number of currently active instances.

protected:
    /// Allocates the counter.
    RefCounted() {
        numInstances = new int;
        *numInstances = 1;
    }

public:
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

    /// Returns if only one instance of this object exists.
    bool isDeletable() {
        return *numInstances == 1;
    }

    /// Decreases counter, or deletes the counter.
    ~RefCounted() {
        if(isDeletable())
            delete numInstances;
        else
            (*numInstances)--;
    }
};

/// The signature of glGen* functions
typedef void (*glGenFunc) (GLsizei, GLuint*);

/// The signature of glDelete* functions
typedef void (*glDeleteFunc) (GLsizei, const GLuint*);

// Note: This class wouldn't work if the template parameters were
// normal function pointers rather than function pointer constant
// references. The reason behind it is that, for example glew's glGenBuffers,
// (__glewGenBuffers) is a local function pointer to an external function,
// so ObjectExt<glGenBuffers, glDeleteBuffers> tries to create the template
// with a function pointer not the function itself. But function pointers
// can not be used as template arguments, because they are mutable. Though
// a pointer (or a const&) to a function pointer is totally valid, and it
// does what we want.
template <const glGenFunc& constructor, const glDeleteFunc& destructor>
/// A class for managing OpenGL resources that are defined in an extension.
/** This class is pretty simple, but really important. What it does,
    is that it moves object creation (server side memory allocation)
    from the constructor of the object, to the first place, where the object
    is used. With this you can declare global objects, which would segfault
    normally, as they are initialized without an existing context. Also
    if an object is never used then no memory will get allocated to it.
    On top of this, it is reference counted, so you can copy Objects
    without having to worry that the deletion of one will effect the other. */
class ObjectExt : public RefCounted {
    /// The C handle for the object.
    GLuint *handle;
    /// The boolean for the object being initialized.
    /** It is a pointer because it is shared between the copies. If one inits
      * the handle, then all instances will have the inited handle */
    bool *inited;
public:
    /// Creates the object, but does not allocate any resource yet.
    ObjectExt()
        : handle(new GLuint)
        , inited(new bool) {

        *inited = false;
    }

    /// @brief Deletes the object.
    /** Deletes the resource if only one instance of
      * this object exists, and it is initialized. */
    ~ObjectExt() {
        if(isDeletable()) {
            if(*inited) {
                oglfunc(destructor(1, handle));
            }
            delete inited;
            delete handle;
        }
    }

    /// Allocates the resource. It only happens upon the first use.
    void Init() const {
        *inited = true;
        oglfunc(constructor(1, handle));
    }

    /// Returns if there's allocated memory for this class.
    bool isInited() const {
        return *inited;
    }

    /// Returns a self-pointer, useful for inheritance
    const ObjectExt& Handle() const {
        return *this;
    }

    /// Returns the C handle for the object. Inits it, if this is the first call for it.
    operator GLuint() const {
        if(!*inited)
            Init();

        return *handle;
    }
};

template <glGenFunc constructor, glDeleteFunc destructor>
/// A class for managing OpenGL resources for object that existed in legacy OpenGL.
/** The class is pretty simple, but really important. What it does,
    is that it moves object creation (server side memory allocation)
    from the constructor of the object, to the first place, where the object
    is used. With this you can declare global objects, which would segfault
    normally, as they are initialized without an existing context. Also
    if an object is never used then no memory will get allocated to it.
    On top of this, it is reference counted, so you can copy Objects
    without having to worry that the deletion of one will effect the other. */
class Object : public RefCounted {
    /// The C handle for the object.
    GLuint *handle;
    /// The boolean for the object being initialized.
    /** It is a pointer because it is shared between the copies. If one inits
      * the handle, then all instances will have the inited handle */
    bool *inited;
public:
    /// Creates the object, but does not allocate any resource yet.
    Object()
        : handle(new GLuint)
        , inited(new bool) {

        *inited = false;
    }

    /// @brief Deletes the object.
    /** Deletes the resource if only one instance of
      * this object exists, and it is initialized. */
    ~Object() {
        if(isDeletable()) {
            if(*inited) {
                oglfunc(destructor(1, handle));
            }
            delete inited;
            delete handle;
        }
    }

    /// Allocates the resource. It only happens upon the first use.
    void Init() const {
        *inited = true;
        oglfunc(constructor(1, handle));
    }

    /// Returns if there's allocated memory for this class.
    bool isInited() const {
        return *inited;
    }

    /// Returns a self-pointer, useful for inheritance
    const Object& Handle() const {
        return *this;
    }

    /// Returns the C handle for the object. Inits it, if this is the first call for it.
    operator GLuint() const {
        if(!*inited)
            Init();

        return *handle;
    }
};

} // namespace oglwrap

#endif // GENERAL_HPP
