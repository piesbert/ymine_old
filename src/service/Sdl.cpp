/* File:       Sdl.cpp
 * Project:    ymine
 * Created on: Nov 2, 2014 10:10:59 AM
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

#include "Sdl.h"

namespace ymine {
namespace service {

Sdl::Sdl() {
}

Sdl::~Sdl() {
}

int Sdl::init(Uint32 flags) const {
    return m_impl->init(flags);
}

void Sdl::quit() const {
    m_impl->quit();
}

SDL_Window* Sdl::createWindow(const char* title, int x, int y, int w, int h, Uint32 flags) const {
    return m_impl->createWindow(title, x, y, w, h, flags);
}

void Sdl::destroyWindow(SDL_Window* window) const {
    m_impl->destroyWindow(window);
}

SDL_GLContext Sdl::glCreateContext(SDL_Window* window) const {
    return m_impl->glCreateContext(window);
}

void Sdl::glDeleteContext(SDL_GLContext context) const {
    m_impl->glDeleteContext(context);
}

void Sdl::glSwapWindow(SDL_Window* window) const {
    m_impl->glSwapWindow(window);
}

int Sdl::glSetAttribute(SDL_GLattr attr, int value) const {
    return m_impl->glSetAttribute(attr, value);
}

int Sdl::glGetAttribute(SDL_GLattr attr, int* value) const {
    return m_impl->glGetAttribute(attr, value);
}

int Sdl::glSetSwapInterval(int interval) const {
    return m_impl->glSetSwapInterval(interval);
}

const char *Sdl::getError() const {
    return m_impl->getError();
}

void Sdl::delay(Uint32 ms) const {
    m_impl->delay(ms);
}

Uint32 Sdl::getTicks() const {
    return m_impl->getTicks();
}

int Sdl::pollEvent(SDL_Event* event) const {
    return m_impl->pollEvent(event);
}

} /* namespace service */
} /* namespace ymine */
