/** @file general.hpp
    @brief Contains codes that are (mostly) not related to OpenGL
*/

#pragma once

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

#ifndef APIENTRY
#define APIENTRY
#endif

#ifndef GLAPIENTRY
#define GLAPIENTRY APIENTRY
#endif

/// The signature of glGen* functions
typedef void (GLAPIENTRY *glGenFunc) (GLsizei, GLuint*);

/// The signature of glDelete* functions
typedef void (GLAPIENTRY *glDeleteFunc) (GLsizei, const GLuint*);

// Note the '&' after the function pointer. The template parameters for
// objects defined in an extension are function pointer that point out
// to an external library, therefore the function pointer itself has
// undefined value compile time, it will get a value after linking,
// but template deductions happen compile time. But the address of
// the function pointer works fine as a template argument.
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

    /// Deletes the object.
    /** Deletes the resource if only one instance of
      * this object exists, and it is initialized. */
    ~ObjectExt() {
        if(isDeletable()) {
            if(*inited) {
                glfunc(destructor(1, handle));
            }
            delete inited;
            delete handle;
        }
    }

    /// Allocates the resource. It only happens upon the first use.
    void init() const {
        *inited = true;
        glfunc(constructor(1, handle));
    }

    /// Returns if there's allocated memory for this class.
    bool isInited() const {
        return *inited;
    }

    /// Returns a self-pointer, useful for inheritance
    const ObjectExt& getHandle() const {
        return *this;
    }

    /// Returns the C handle for the object. Inits it, if this is the first call for it.
    operator GLuint() const {
        if(!*inited)
            init();

        return *handle;
    }
};

// Functions that existed in legacy OpenGL like glGenTextures, are explicitly defined
// compile time. These work fine without the '&'. But they won't work with the ObjectExt
// class, as they are functions not function pointers, so writing their name already
// causes an indirection, their name evaluates as a hexa value not a variable, therefore
// we can't get the address of it, nor can reference it.
template <const glGenFunc constructor, const glDeleteFunc destructor>
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

    /// Deletes the object.
    /** Deletes the resource if only one instance of
      * this object exists, and it is initialized. */
    ~Object() {
        if(isDeletable()) {
            if(*inited) {
                glfunc(destructor(1, handle));
            }
            delete inited;
            delete handle;
        }
    }

    /// Allocates the resource. It only happens upon the first use.
    void Init() const {
        *inited = true;
        glfunc(constructor(1, handle));
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

