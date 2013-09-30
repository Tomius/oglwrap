![logo](logo.png) *OpenGL C++ wrapper*
===

Oglwrap is a lightweight, cross-platform, object oriented, header-only C++ wrapper for OpenGL, with a debugging, and error checking module, and some utilites. 

Features:
-------------
* Portable, and easy to use, as it is platform-indipendent, header only, and doesn't even have to be configured (apart from the extra features, that can be turned on with defining macros before the inclusion of oglwrap, or in the config.hpp).
* RAII resource handling. You won't have to generate or delete the resources yourself, the memory will be allocated when you first use the object,
  (It happens there, rather than in the constructor, because this way, you can declare global objects, whose constructor run before the creation of the GL context. Normally this would cause a segfault, but with oglwrap, it works fine)
* Typesafety, you get compile time error for giving wrong enum arguments to a function, unlike with GLenum, which only signs that you did something wrong runtime, by generating a GL_INVALID_ENUM. This typesafety also applies to binding targets, which means, for ex. you can't call glBindBufferBase (IndexedBuffer::BindBase) on an ArrayBuffer, because that target is not indexed, so calling BindBase on it wouldn't even make sense.
* oglwrap is not only type-safe, but its also bind-safe, because functions that operate with, or operate on a binding target, are bind-checked. This means that you'll get warnings if you do things like this:

```
std::vector<glm::vec3> vertices_vector;
// ... upload data to the vertices_vector
oglwrap::ArrayBuffer buffer0, buffer1;
buffer0.bind(); 
buffer1.data(vertices_vector); // Causes bind-check error because buffer0 is bound, but the function is called through buffer1.
```
Or this
```
oglwrap::Texture2D tex;
tex.loadImage("image.png"); // Causes bind-check error because tex isn't bound.
```
Of course, these functions should be logically static, but to bindcheck them, they have to be non-static. Though all of the bind-checked functions have a static version, that start with a capital letter, like Texture2D::LoadImage();
* It has full glm support, glm classes are treated like they were GL types. You can use Uniform< vec2 > to upload with glUniform2fv, 
  you can upload vec2 to buffers, setup attribute arrays with Setup< vec2 >() instead of Pointer(2, GLfloat, ...) etc..
* Easy to read, easy to parse. It is fully supported by intellicenses unlike the C OpenGL.
* A lot of default parameters, often used function take about half as much parameter than with C OpenGL
* Gives you cool utilites like a free-fly camera, and even more powerful ones with external libraries. For example with assimp, you get a generic model loader that can load nearly any kind of mesh from over 30 different file formats, and you can get it on screen with less then 10 lines of code! You also get an animation loader, that can load and display nearly any kind of animation with GPU skinning, but on top of that, it also gives you some other cool features, like it can create smooth transition between two animations, or it can play animations backwards, or it can make a simple walk animation into a moonwalk using the AnimFlags::Mirrored flag..  
* Has a pretty awesome debugging module. It catches every error generated inside an oglwrap code, but also let's you catches errors the same way. For example you can debug a simple glEnable(GL_DEPTH_TEST); call with adding two extra characters into it: gl( Enable(GL_DEPTH_TEST) );. This isn't just making the code easier to read, but gives you insane amount of valuable information, if something goes wrong. For example, I intentionally changed the buffers' binding targets to an invalid value. This is what the program said:

```
---------========={[ GL_INVALID_ENUM ]}=========---------

Caused by glBindBuffer(0, buffer)
In function: void oglwrap::BufferObject<buffer_t>::bind() const [with oglwrap::_BufferType::BufferType buffer_t = (oglwrap::_BufferType::BufferType)34962u]
In '.../oglwrap/buffer.hpp' at line 33

The following OpenGL function: 

    void glBindBuffer(GLenum target,
     		          GLuint buffer);

Has generated the error because one of the following(s) were true:
- Target is not one of the allowable values.

---------========={[ GL_INVALID_OPERATION ]}=========---------

Caused by glBufferData(buffer_t, data.size() * sizeof(GLtype), data.data(), usage)
In function: static void oglwrap::BufferObject<buffer_t>::data(const std::vector<GLtype>&, oglwrap::BufferUsage) [with GLtype = float; oglwrap::_BufferType::BufferType buffer_t = (oglwrap::_BufferType::BufferType)34962u; oglwrap::BufferUsage = oglwrap::_BufferUsage::BufferUsage]
In '.../oglwrap/buffer.hpp' at line 60

The following OpenGL function: 

    void glBufferData(GLenum        target,
     		          GLsizeiptr    size,
     		          const GLvoid* data,
     		          GLenum        usage);

Has generated the error because one of the following(s) were true:
- The reserved buffer object name 0 is bound to target.
```

* Documented inside the code, so with intellicense you won't ever have to google OpenGL functions again.
For example:
![screenshot](http://oi42.tinypic.com/hrmv7c.jpg)
