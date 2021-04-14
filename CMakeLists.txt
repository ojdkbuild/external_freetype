# Copyright 2016, alex at staticlibs.net
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

cmake_minimum_required ( VERSION 2.8.12 )

# project
project ( external_freetype CXX C )
set ( ${PROJECT_NAME}_STATICLIB_VERSION 2.8-5 )
set ( ${PROJECT_NAME}_DESCRIPTION "FreeType2 library build for Staticlibs" )
set ( ${PROJECT_NAME}_URL https://github.com/staticlibs/external_freetype )

# standalone build
if ( NOT DEFINED CMAKE_LIBRARY_OUTPUT_DIRECTORY )
    set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
endif ( )

# freetype library
add_subdirectory ( ${CMAKE_CURRENT_LIST_DIR}/resources/freetype_cmake ${CMAKE_CURRENT_BINARY_DIR}/freetype )
add_custom_target ( ${PROJECT_NAME} DEPENDS freetype${freetype_LIBNAME_POSTFIX} )

# pkg-config
set ( ${PROJECT_NAME}_MODULE freetype${freetype_LIBNAME_POSTFIX} )
set ( ${PROJECT_NAME}_PC_CFLAGS "-I${CMAKE_CURRENT_BINARY_DIR}/freetype${freetype_LIBNAME_POSTFIX}/include -I${freetype_LOOKASIDE_DIR}/include" )
set ( ${PROJECT_NAME}_PC_LIBS "-L${CMAKE_LIBRARY_OUTPUT_DIRECTORY} -lfreetype${freetype_LIBNAME_POSTFIX}" )
configure_file ( ${CMAKE_CURRENT_LIST_DIR}/resources/pkg-config.in 
        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/pkgconfig/freetype${freetype_LIBNAME_POSTFIX}.pc )
