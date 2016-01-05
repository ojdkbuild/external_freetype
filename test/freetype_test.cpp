/*
 * Copyright 2016, alex at staticlibs.net
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   freetype_test.cpp
 * Author: alex
 *
 * Created on January 5, 2016, 7:18 PM
 */

#include <memory>
#include <cassert>

#include <ft2build.h>
#include FT_FREETYPE_H


int main() {
    FT_Library library;
    auto err_init = FT_Init_FreeType(std::addressof(library));
    (void) err_init; assert(!err_init);
    FT_Face face;
    auto err_load = FT_New_Face(library, "../test/font/DejaVuSans.ttf", 0, &face);
    (void) err_load; assert(!err_load);
    
    FT_Done_FreeType(library);
    
    return 0;
}

