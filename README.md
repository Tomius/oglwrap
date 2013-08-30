oglwrap
=======

Oglwrap is a lightweight header-only C++ wrapper for the core OpenGL 3.3. 

It is highly inspired by [oglplus](https://github.com/matus-chochlik/oglplus), there are a lot of similarites in the interfaces of the two library, however in some aspects, like binding targets, the two library work enitrely diffrent.
However there aren't much similarity in the aspect of implementation. Oglwrap is meant to be an easy to read, easy to parse library, but this isn't true for oglplus, because it offers a lot better portability and is safer work with, at the cost of beeing a more roboust library. But there are also a lot of major differences in the two library apart from simplicity. For example in oglwarp resource allocation happens at the first use of an object, in oglplus, it happens when the constructor runs. So with oglwrap you can declare global/static objects, whose constructor run without an avaliable context, and they will work fine, but with oglplus object you can't do this. The two debugging systems are definitely not even alike, oglwrap doesn't have a fancy expection system, but it usually provides more information about what has happened (but running oglwrap in debug mode is more costy in terms of performance), and it rather just prints the error to stderr, if it's not fatal, and program could keep on working, instead of throwing an exception and probably terminating the program.    

Features:
-------------
* It has full glm support, glm classes are treated like they were GL types. You can use Uniform< vec2 > to upload with glUniform2fv, 
  you can upload vec2 to buffers, setup attribute arrays with Setup< vec2 >() instead of Pointer(2, GLfloat, ...) etc..
* Portable, and easy to use, as it is header only.
* A lot of default parameters, often used function take about half as much parameter than with C OpenGL
* RAII resource handling. You won't have to generate or delete the resources yourself, the memory will be allocated when you first use the object,
  ( It happens there, rather than in the constructor, because this way, you can declare global or static objects, whose ctor run before the creatin of the GL context. )
* Typesafety, functions do not take GLenum or GLuint, but for ex. VertexAttribArray::Pointer takes a FloatDataType enum value, so
  you can't call Pointer for Ints, you only can IPointer with int parameter. But VertexAttribArray also has a setup template which 
  figures this out for you, so you don't even have to bother with that 'I'.
* Less macros, nicer looking names.
* Easy to read, easy to parse. It is fully supported by intellicenses unlike the C OpenGL or oglplus.
* Built in conditional error checking for every OpenGL call, so you can exactly know when and where did the error happen, and you usually get detailed information about why did the error happen. The checking can be turned off with #define OGLWRAP_DEBUG 0. Also if you can create a debug context you might want to use DebugOutput::Activate().
* Documented inside the code, so with intellicense you won't ever have to google OpenGL functions again.
For example:
![screenshot](http://oi42.tinypic.com/hrmv7c.jpg)
