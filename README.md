oglwrap
=======

Oglwrap is a lightweight header-only C++ wrapper for the core OpenGL 3.3. 

It highly inspired by [oglplus](https://github.com/matus-chochlik/oglplus), has similar interface with oglplus (though there are several
major differences), however the implementation is entirely different. It doesn't provide as much feature as oglplus does,
but oglwrap's simplicity may actually count as an advantage.

Features:
-------------
* Portable, and easy to use as it is only 2 header files
* A lot of default parameters, often used function take about half as much parameter than with C OpenGL
* RAII resource handling. You won't have to generate or delete the resources yourself, it happens in the constructor & destructor.
* Typesafety, functions do not take GLenum or GLuint, but for ex. Buffer::Data takes a DataType enum value.
* Less macros, nicer looking names.
* Easy to read, easy to parse. It is fully supported by intellicenses unlike the C OpenGL or oglplus.
* Built in error checking and debug information.  
