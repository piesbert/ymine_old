/* File:       SdlImpl.h
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

#ifndef SRC_SERVICE_SDLIMPL_H_
#define SRC_SERVICE_SDLIMPL_H_

#include "service/interface/ISdl.h"

namespace ymine {
namespace service {

class SdlImpl: public interface::ISdl {
public:
    SdlImpl();
    virtual ~SdlImpl();

    int init(Uint32 flags) const;
    void quit() const;

    SDL_Window* createWindow(const char* title, int x, int y, int w, int h, Uint32 flags) const;
    void destroyWindow(SDL_Window* window) const;

    SDL_GLContext glCreateContext(SDL_Window* window) const;
    void glDeleteContext(SDL_GLContext context) const;
    void glSwapWindow(SDL_Window* window) const;

    int glSetAttribute(SDL_GLattr attr, int value) const;
    int glGetAttribute(SDL_GLattr attr, int* value) const;

    int glSetSwapInterval(int interval) const;

    const char* getError() const;

    void delay(Uint32 ms) const;
    Uint32 getTicks() const;

    int pollEvent(SDL_Event* event) const;
};

} /* namespace service */
} /* namespace ymine */

#endif /* SRC_SERVICE_SDLIMPL_H_ */
