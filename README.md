FreeType2 library build for Staticlibs
======================================

[![travis](https://travis-ci.org/staticlibs/external_freetype.svg?branch=master)](https://travis-ci.org/staticlibs/external_freetype)
[![appveyor](https://ci.appveyor.com/api/projects/status/github/staticlibs/external_freetype?svg=true)](https://ci.appveyor.com/project/staticlibs/external-freetype)

This project is a part of [Staticlibs](http://staticlibs.net/).

This project contains a CMake wrapper for the [Freetype library](http://freetype.org/) that 
can be used to build sources imported from [CentOS lookaside](https://github.com/staticlibs/lookaside_freetype.git).

Link to the [API documentation](http://freetype.org/freetype2/docs/reference/ft2-index.html).

How to build
------------

[CMake](http://cmake.org/) is required for building.

To build the library on Windows using Visual Studio 2013 Express run the following commands using
Visual Studio development command prompt 
(`C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts\VS2013 x86 Native Tools Command Prompt`):

    git clone https://github.com/staticlibs/external_freetype.git
    git clone https://github.com/staticlibs/lookaside_freetype.git
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

**2019-12-02**

 * version 2.8-4
 * support overriding C runtime lib on Windows

**2019-10-02**

 * version 2.8-3
 * 2 patches applied

**2019-04-10**

 * version 2.8-2
 * fix `gb2312` encoding name

**2019-01-07**

 * version 2.8-1
 * update to freetype-2.8

**2018-03-05**

 * version 2.4.11-2
 * drop submodule

**2016-12-18**

 * version 2.4.11-1
 * lookaside build

**2016-01-17**

 * version 2.6.2.1
 * minor CMake changes

**2016-01-05**

 * version 2.6.2.0
 * initial public version
