oglwrap
=======

Oglwrap is a lightweight header-only C++ wrapper for the core OpenGL 3.3. 

It is highly inspired by [oglplus](https://github.com/matus-chochlik/oglplus), has similar interface with oglplus (though there are several
major differences), however the implementation is entirely different. It doesn't provide as much feature as oglplus does,
but oglwrap's simplicity may actually count as an advantage.

Features:
-------------
* It has full glm support, it is treated as a GL type vector. You can use Uniform< vec2 > to upload with glUniform2fv, 
  you can upload vec2 to buffers, setup attribute arrays with Setup< vec2 >() instead of Pointer(2, GLfloat, ...)
* Portable, and easy to use, as it is header only.
* A lot of default parameters, often used function take about half as much parameter than with C OpenGL
* RAII resource handling. You won't have to generate or delete the resources yourself, it happens in the constructor & destructor.
* Typesafety, functions do not take GLenum or GLuint, but for ex. VertexAttribArray::Pointer takes a FloatDataType enum value, so
  you can't call Pointer for Ints, you only can IPointer with int parameter. But VertexAttribArray also has a setup template which 
  figures this out for you, so you don't even have to bother with that 'I'.
* Less macros, nicer looking names.
* Easy to read, easy to parse. It is fully supported by intellicenses unlike the C OpenGL or oglplus.
* Built in conditional error checking for every OpenGL call, so you can exactly know when and where did the error happen. The checking only happens if you #define OGLWRAP_DEBUG 1 as it might make you loose up to 5 FPS.
* Documented inside the code, so with intellicense you won't ever have to google OpenGL functions again.
For example:
![screenshot](http://oi42.tinypic.com/hrmv7c.jpg)
