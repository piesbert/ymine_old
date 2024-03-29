/* File:       SdlImpl.cpp
 * Project:    ymine
 * Created on: Nov 2, 2014 10:11:27 AM
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

#include "SdlImpl.h"

namespace ymine {
namespace service {

SdlImpl::SdlImpl() {
}

SdlImpl::~SdlImpl() {
}

int SdlImpl::init(Uint32 flags) const {
    return SDL_Init(flags);
}
void SdlImpl::quit() const {
    SDL_Quit();
}

SDL_Window *SdlImpl::createWindow(const char *title, int x, int y, int w, int h, Uint32 flags) const {
    return SDL_CreateWindow(title, x, y, w, h, flags);
}

void SdlImpl::destroyWindow(SDL_Window* window) const {
    SDL_DestroyWindow(window);
}

SDL_GLContext SdlImpl::glCreateContext(SDL_Window *window) const {
    return SDL_GL_CreateContext(window);
}

void SdlImpl::glDeleteContext(SDL_GLContext context) const {
    SDL_GL_DeleteContext(context);
}

void SdlImpl::glSwapWindow(SDL_Window *window) const {
    SDL_GL_SwapWindow(window);
}

int SdlImpl::glSetAttribute(SDL_GLattr attr, int value) const {
    return SDL_GL_SetAttribute(attr, value);
}

int SdlImpl::glGetAttribute(SDL_GLattr attr, int* value) const {
    return SDL_GL_GetAttribute(attr, value);
}

int SdlImpl::glSetSwapInterval(int interval) const {
    return SDL_GL_SetSwapInterval(interval);
}

const char* SdlImpl::getError() const {
    return SDL_GetError();
}

void SdlImpl::delay(Uint32 ms) const {
    SDL_Delay(ms);
}

Uint32 SdlImpl::getTicks() const {
    return SDL_GetTicks();
}

int SdlImpl::pollEvent(SDL_Event* event) const {
    return SDL_PollEvent(event);
}

} /* namespace service */
} /* namespace ymine */
