#ifndef GENERAL_HPP
#define GENERAL_HPP

namespace oglwrap {

// -------======{[ Reference Counter declaration ]}======-------

// OpenGL RAII needs to be reference counted.
// So classes with allocated data inherit from this.
class RefCounted {
    int *numInstances;
protected:
    bool isDeleteable();
public:
    RefCounted();
    RefCounted(const RefCounted& rhs);
    RefCounted& operator=(const RefCounted& rhs);
    ~RefCounted();
};

// -------======{[ Reference Counter definition ]}======-------

inline bool RefCounted::isDeleteable() {
    return *numInstances == 1;
}
inline RefCounted::RefCounted() {
    numInstances = new int;
    *numInstances = 1;
}
inline RefCounted::RefCounted(const RefCounted& rhs) {
    numInstances = rhs.numInstances;
    (*numInstances)++;
}
inline RefCounted& RefCounted::operator=(const RefCounted& rhs) {
    numInstances = rhs.numInstances;
    (*numInstances)++;
    return *this;
}
inline RefCounted::~RefCounted() {
    if(isDeleteable())
        delete numInstances;
    else
        (*numInstances)--;
}

}

#endif // GENERAL_HPP
