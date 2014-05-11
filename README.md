![logo](logo.png) *OpenGL C++ wrapper*
===

Oglwrap is a lightweight, cross-platform, object-oriented, header-only C++ wrapper for modern (2.1+) OpenGL, that focuses on preventing most of the trivial OpenGL errors, and giving as much debug information about the other errors, as possible.

This project is mainly for personal use, and its interface might change often.
If you need a object-oriented OpenGL wrapper with long term compatibility
take a look at [oglplus](https://github.com/matus-chochlik/oglplus).

Features:
-------------
* Header only, platform-independent
* No need to configure it per machine (but you might want some configuration using macros per projects)
* Has full code-completion support
* Type-safe enums instead GLenum (so you get compile time errors in oglwrap, where you would get a GL_INVALID_ENUM runtime in C OpenGL)
* Has bind-checking. This means that you'll get warnings if forget to bind some OpenGL object before you use it:
```
oglwrap::Texture2D tex;
tex.loadImage("image.png"); // Causes bind-check error because tex isn't bound.
```
Or this:
```
std::vector<glm::vec3> vertices_vector;
// ... upload data to the vertices_vector
oglwrap::ArrayBuffer buffer0, buffer1;
buffer0.bind();
buffer1.data(vertices_vector); // Causes bind-check error because buffer0 is bound, but the function is called through buffer1.
```
* Note, that bind-checking (and debug-info in general) makes zero runtime overhead if you write ```#define OGLWRAP_DEBUG 0```
* Oglwrap has full glm support, glm classes are treated like they were GL types. For example you can use Uniform< vec2 > to load data into a vec2 uniform (instead of with glUniform2fv).
* Functions overloads, templates and default parameters let you type less than with C OpenGL. Consider:
```
Texture2D tex;
tex.bind();
tex.upload(PixelDataInternalFormat::RGBA, 32, 32, PixelDataFormat::RGBA, PixelDataType::UnsignedByte, nullptr);
```
Versus:
```
GLuint tex;
glGenTextures(1, &tex);
glBindTexture(GL_TEXTURE_2D, tex);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 32, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
// ...
glDeleteTextures(1, tex);
```
Note how much the enum class names affect the readability of the code. In the C OpenGL its hard to know, whats the purpose of the first and second GL_RGBA. In the oglwrap implementation, its obvious for the reader.

Also note, that you can't bind the texture to a wrong target, and you can't
specify an invalid border value. Also its more explicit, that you are uploading the base texture, not a mipmap (you can use tex.uploadMipmap() for that)
* Lots of debug info if you do something invalid. For example the following code:
```
gl.DrawArrays(PrimitiveType::Triangles, 0, -1);
```
Results this output:
```
---------========={[ Invalid Value ]}=========---------

Caused by glDrawArrays(GLenum(type), first, count)
In function: static void oglwrap::context::Drawing::DrawArrays(PrimitiveType, GLint, GLsizei);
In 'include/oglwrap/context/drawing.h' at line 47

Stack trace:
./LoD(_ZN7oglwrap23OGLWRAP_PrintStackTraceERSo+0x27) [0x46f587]
./LoD(_ZN7oglwrap18OGLWRAP_PrintErrorERKNS_12ErrorMessageE+0x337) [0x46b6f7]
./LoD(_ZNSt17_Function_handlerIFvN7oglwrap12ErrorMessageEEPFvRKS1_EE9_M_invokeERKSt9_Any_dataS1_+0x32) [0x46f9c2]
./LoD(_ZNKSt8functionIFvN7oglwrap12ErrorMessageEEEclES1_+0x6b) [0x46a31b]
./LoD(_ZN7oglwrap11DebugOutput10PrintErrorENS_12ErrorMessageE+0xc4) [0x469fd4]
./LoD(_ZN7oglwrap18OGLWRAP_CheckErrorEPKcS1_iS1_+0x344) [0x469604]
./LoD(_ZN7oglwrap7context7Drawing10DrawArraysENS_5enums14_PrimitiveType13PrimitiveTypeEii+0x41) [0x4a0121]
./LoD(main+0x525) [0x4a21b5]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf5) [0x7f26a868cde5]
./LoD() [0x45f179]

The following OpenGL function:

  void glDrawArrays(GLenum mode,
                    GLint first,
                    GLsizei count);

Has generated the error because one of the following(s) were true:
- Count is negative.

-------------------------------------------------------
```

This lets you know, that the source of the GL_INVALID_VALUE was a glDrawArrays call in the main() function (the first one in the call stack that is not in the oglwrap namespace), where the count parameter was negative. Imagine how useful this information could be in a 100 000+ lines project.

----------------------
If you have any problem, please post in the issues tab or mail me at icyplusplus@gmail.com. Any feedback would be appreciated.
