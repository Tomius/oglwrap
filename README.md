oglwrap
=======

Oglwrap is a lightweight header-only C++ wrapper for the core OpenGL 3.3. 

It highly inspired by [oglplus](https://github.com/matus-chochlik/oglplus) has similar interface (though there are lot of
changes) with oglplus, however the implementation is entirely different. This is made to be a simple library.

Features:
-------------
* Portable, and easy to use as it is only 2 header files
* A lot of default parameters, often used function take about half as much parameter than with C OpenGL
* RAII resource handling. You won't have to generate or delete the resources yourself, it happens in the constructor & destructor.
* Typesafety, functions do not take GLenum or GLuint, but for ex. Buffer::Data takes a DataType enum value.
* Less macros, nicer looking names.
* Easy to read, easy to parse. It is fully supported by intellicenses unlike the C OpenGL or oglplus.
* Built in error checking and debug information.  
