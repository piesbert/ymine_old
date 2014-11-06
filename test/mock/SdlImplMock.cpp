/* File:       SdlImplMock.cpp
 * Project:    ymine
 * Created on: Nov 6, 2014 6:56:01 PM
 * Author:     piesbert
 *
 * Copyright (C) 2014 Sebastian Szymak
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.    
 */

#include <gmock/gmock.h>

#include "service/interface/ISdl.h"

class SdlImplMock : public ymine::service::interface::ISdl {
public:
    MOCK_CONST_METHOD1(init, int(Uint32 flags));
    MOCK_CONST_METHOD0(quit, void());

    MOCK_CONST_METHOD6(createWindow, SDL_Window*(const char* title, int x, int y, int w, int h, Uint32 flags));
    MOCK_CONST_METHOD1(destroyWindow, void(SDL_Window* window));

    MOCK_CONST_METHOD1(glCreateContext, SDL_GLContext(SDL_Window* window));
    MOCK_CONST_METHOD1(glDeleteContext, void(SDL_GLContext context));
    MOCK_CONST_METHOD1(glSwapWindow, void(SDL_Window* window));

    MOCK_CONST_METHOD2(glSetAttribute, int(SDL_GLattr attr, int value));
    MOCK_CONST_METHOD2(glGetAttribute, int(SDL_GLattr attr, int* value));

    MOCK_CONST_METHOD1(glSetSwapInterval, int(int interval));

    MOCK_CONST_METHOD0(getError, const char*());

    MOCK_CONST_METHOD1(delay, void(Uint32 ms));
    MOCK_CONST_METHOD0(getTicks, Uint32());

    MOCK_CONST_METHOD1(pollEvent, int(SDL_Event* event));
};

