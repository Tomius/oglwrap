![logo](logo.png) *OpenGL C++ wrapper*
===

Oglwrap is a lightweight, cross-platform, object-oriented, header-only C++ wrapper for modern (2.1+) OpenGL, that focuses on preventing most of the trivial OpenGL errors, and giving as much debug information about the other errors, as possible.

This project is mainly for personal use, and its interface might change often.
If you need a object-oriented OpenGL wrapper with long term compatibility
take a look at [oglplus](https://github.com/matus-chochlik/oglplus) or [oogl](https://github.com/Overv/OOGL).

Dependencies:
-------------
* [GLM](https://github.com/g-truc/glm)

Features:
---------
* Header only, platform-independent
* No need to configure it per machine (but you might want some configuration using macros per projects)
* Has full code-completion support
* Type-safe enums instead GLenum (so you can say goodbye to GL_INVALID_ENUM forever).
* Has bind-checking. This means that you'll get warnings if forget to bind some OpenGL object before you use it:
```c++
gl::Texture2D tex;
tex.loadImage("image.png"); // Causes bind-check error because tex isn't bound.
```
Or this:
```c++
std::vector<glm::vec3> vertices_vector;
// ... upload data to the vertices_vector
gl::ArrayBuffer buffer0, buffer1;
gl::Bind(buffer0);
buffer1.data(vertices_vector); // Causes bind-check error because buffer0 is bound, but the function is called through buffer1.
```
* Note, that bind-checking (and debug-info in general) can be disabled with ```#define OGLWRAP_DEBUG 0```. With this, and function inlining enabled, oglwrap runs with zero runtime overhead compared to C OpenGL.
* Oglwrap has full glm support, glm classes are treated like they were GL types. For example you can use Uniform< vec2 > to load data into a vec2 uniform (instead of with glUniform2fv).
* Functions overloads, templates and default parameters let you type less than with C OpenGL. Consider:
```c++
Texture2D tex;
gl::BindToTexUnit(tex, 2);
tex.upload(gl::kRgba, 32, 32, gl::kRgba, gl::kUnsignedByte, nullptr);
tex.generateMipmap();
tex.minFilter(gl::kLinearMipmapLinear);
tex.magFilter(gl::kLinear);
tex.wrapS(gl::kRepeat);
tex.wrapT(gl::kRepeat);
```
Versus:
```c++
GLuint tex;
glGenTextures(1, &tex);
glActiveTexture(GL_TEXTURE2);
glBindTexture(GL_TEXTURE_2D, tex);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 32, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
glGenerateMipmap(GL_TEXTURE_2D);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

// ...
glDeleteTextures(1, tex);
```

Notice that if you write a wrong enum for a function, for ex:
```c++
tex.magFilter(gl::kLinearMipmapLinear);
```
You get a compile time error:
```
Error - no viable conversion from 'const smart_enums::LinearMipmapLinearEnum' to 'enums::MagFilter'
```
While with C OpenGL, the error would only pop at runtime, as a GL_INVALID_ENUM.

Also note, that you can't bind the texture to a wrong target, and you can't
specify an invalid border value. Also its more explicit, that you are uploading the base texture, not a mipmap (you can use tex.uploadMipmap() for that). Oh, and you can't forget about deleting the textures, because RAII
does that for you (even if an exception is thrown). And should I remind you,
that if you compile with OGLWRAP_DEBUG turned on, you get explicit warning
if you forget to call tex.bind(); and even if you do forget, oglwrap will bind
it for you, and your code will still work. And you get all this stuff with zero runtime overhead for a release build.

* Lots of runtime debug info if you do something invalid that can't be caught compile-time. For example the following code:
```c++
gl::DrawArrays(PrimitiveType::Triangles, 0, -1);
```
Results this output:
```
---------========={[ Invalid Value ]}=========---------

Caused by glDrawArrays(GLenum(type), first, count)
In function: static void gl::context::Drawing::DrawArrays(PrimitiveType, GLint, GLsizei);
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



Notes about using oglwrap:
-------------
- A ```#define OGLWRAP_INSTANTIATE 1``` line is required at exactly one CXX file (.cpp, .cc etc), before including oglwrap. It is needed for explicit template instantiations (but oglwrap is header-only). Alternatively you can link oglwrap.cc to your application, which has the exact same effect (but you loose the benefits of a header-only library, however in case of precompiled headers, it makes your life a lot easier)
- You have to load OpenGL extensions before including oglwrap with your preferred extension loader. If you don't have a preferred one, I recommend using [GLEW](https://github.com/nigels-com/glew).


----------------------
If you have any problem, please post in the issues tab or mail me at icyplusplus@gmail.com. Any feedback would be appreciated.
