# Copyright 2016, akashche at redhat.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# this file is based on https://github.com/staticlibs/mirror_freetype2/blob/master/CMakeLists.txt
cmake_minimum_required ( VERSION 2.8.12 )
project ( freetype C )

if ( NOT DEFINED ${PROJECT_NAME}_LOOKASIDE_DIR )
    set ( ${PROJECT_NAME}_LOOKASIDE_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../lookaside_freetype CACHE INTERNAL "" )
endif ( )

include ( CheckIncludeFile )

file ( MAKE_DIRECTORY "${PROJECT_BINARY_DIR}/include/freetype/config" )

# Create the configuration file
message ( STATUS "Creating file ${PROJECT_BINARY_DIR}/include/freetype/config/ftconfig.h" )

if ( UNIX )
    check_include_file ( "unistd.h" HAVE_UNISTD_H )
    check_include_file ( "fcntl.h" HAVE_FCNTL_H )
    check_include_file ( "stdint.h" HAVE_STDINT_H )

    file ( READ "${${PROJECT_NAME}_LOOKASIDE_DIR}/builds/unix/ftconfig.in" FTCONFIG_H )
    if ( HAVE_UNISTD_H )
        string ( REGEX REPLACE "#undef +(HAVE_UNISTD_H)" "#define \\1" FTCONFIG_H "${FTCONFIG_H}" )
    endif ( )
    if ( HAVE_FCNTL_H )
        string ( REGEX REPLACE "#undef +(HAVE_FCNTL_H)" "#define \\1" FTCONFIG_H "${FTCONFIG_H}" )
    endif ( )
    if ( HAVE_STDINT_H )
        string ( REGEX REPLACE "#undef +(HAVE_STDINT_H)" "#define \\1" FTCONFIG_H "${FTCONFIG_H}" )
    endif ( )
    string ( REPLACE "/undef " "#undef " FTCONFIG_H "${FTCONFIG_H}" )
    file ( WRITE "${PROJECT_BINARY_DIR}/include/freetype/config/ftconfig.h" "${FTCONFIG_H}" )
else ( )
    file ( READ "${${PROJECT_NAME}_LOOKASIDE_DIR}/include/freetype/config/ftconfig.h" FTCONFIG_H )
    file ( WRITE "${PROJECT_BINARY_DIR}/include/freetype/config/ftconfig.h" "${FTCONFIG_H}" )
endif ( )

# library
file ( GLOB ${PROJECT_NAME}_PUBLIC_HEADERS 
        "${${PROJECT_NAME}_LOOKASIDE_DIR}/include/ft2build.h" 
        "${${PROJECT_NAME}_LOOKASIDE_DIR}/include/freetype/*.h" )
source_group ( "include_public" FILES ${${PROJECT_NAME}_PUBLIC_HEADERS} )
file ( GLOB ${PROJECT_NAME}_PUBLIC_CONFIG_HEADERS "${${PROJECT_NAME}_LOOKASIDE_DIR}/include/freetype/config/*.h")
source_group ( "include_public_config" FILES ${${PROJECT_NAME}_PUBLIC_CONFIG_HEADERS} )
file ( GLOB ${PROJECT_NAME}_PRIVATE_HEADERS "${${PROJECT_NAME}_LOOKASIDE_DIR}/include/freetype/internal/*.h")
source_group ( "include_private" FILES ${${PROJECT_NAME}_PRIVATE_HEADERS} )

set ( ${PROJECT_NAME}_BASE_SRCS
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/autofit/autofit.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftbase.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftbbox.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftbdf.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftbitmap.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftcid.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftfntfmt.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftfstype.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftgasp.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftglyph.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftgxval.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftinit.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftlcdfil.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftmm.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftotval.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftpatent.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftpfr.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftstroke.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftsynth.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftsystem.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/fttype1.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftwinfnt.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/bdf/bdf.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/bzip2/ftbzip2.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/cache/ftcache.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/cff/cff.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/cid/type1cid.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/gzip/ftgzip.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/lzw/ftlzw.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/pcf/pcf.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/pfr/pfr.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/psaux/psaux.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/pshinter/pshinter.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/psnames/psnames.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/raster/raster.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/sfnt/sfnt.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/smooth/smooth.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/truetype/truetype.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/type1/type1.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/type42/type42.c
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/winfonts/winfnt.c )
source_group ( "src" FILES ${${PROJECT_NAME}_BASE_SRCS} )        

if ( WIN32 )
    set ( BASE_SRCS ${BASE_SRCS} ${${PROJECT_NAME}_LOOKASIDE_DIR}/builds/windows/ftdebug.c )
else ( )
    set ( BASE_SRCS ${BASE_SRCS} ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/base/ftdebug.c )
endif ( )

add_library( ${PROJECT_NAME}${${PROJECT_NAME}_LIBNAME_POSTFIX} STATIC
    ${${PROJECT_NAME}_BASE_SRCS}
    ${${PROJECT_NAME}_PUBLIC_HEADERS}
    ${${PROJECT_NAME}_PUBLIC_CONFIG_HEADERS}
    ${${PROJECT_NAME}_PRIVATE_HEADERS} )

target_include_directories ( ${PROJECT_NAME}${${PROJECT_NAME}_LIBNAME_POSTFIX} BEFORE PRIVATE "${${PROJECT_NAME}_LOOKASIDE_DIR}/include" )
target_include_directories ( ${PROJECT_NAME}${${PROJECT_NAME}_LIBNAME_POSTFIX} BEFORE PRIVATE "${PROJECT_BINARY_DIR}/include" )
target_compile_definitions ( ${PROJECT_NAME}${${PROJECT_NAME}_LIBNAME_POSTFIX} PRIVATE -DFT2_BUILD_LIBRARY )

if ( ${CMAKE_C_COMPILER_ID}x MATCHES "MSVCx" )
    if ( DEFINED ${PROJECT_NAME}_MSVC_ALT_CRUNTIME )
        target_compile_options ( ${PROJECT_NAME}${${PROJECT_NAME}_LIBNAME_POSTFIX} PRIVATE
                ${${PROJECT_NAME}_MSVC_ALT_CRUNTIME} )
    endif ( )
endif ( )