FreeType2 library build for Staticlibs
======================================

This project is a part of [Staticlibs](http://staticlibs.net/).

This project contains a CMake wrapper for the [Freetype library](http://freetype.org/). 

FreeType unofficial GitHub mirror is used as a git submodule of this project. FreeType is pinned to version 2.6.2.

Link to [API documentation](http://freetype.org/freetype2/docs/reference/ft2-index.html).

How to build
------------

[CMake](http://cmake.org/) is required for building.

To build the library on Windows using Visual Studio 2013 Express run the following commands using
Visual Studio development command prompt 
(`C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts\VS2013 x86 Native Tools Command Prompt`):

    git clone --recursive https://github.com/staticlibs/external_freetype.git
    cd external_freetype
    mkdir build
    cd build
    cmake ..
    msbuild external_freetype.sln

See [StaticlibsToolchains](https://github.com/staticlibs/wiki/wiki/StaticlibsToolchains) for 
more information about the CMake toolchains setup and cross-compilation.

License information
-------------------

This project is released under the [Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0).

Changelog
---------

**2016-01-17**

 * version 2.6.2.1
 * minor CMake changes

**2016-01-05**

 * version 2.6.2.0
 * initial public version
