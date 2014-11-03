/* File:       ISdl.h
 * Project:    ymine
 * Created on: Nov 2, 2014 10:01:33 AM
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

#ifndef SRC_SERVICE_INTERFACE_ISDL_H_
#define SRC_SERVICE_INTERFACE_ISDL_H_

#include <SDL2/SDL.h>

namespace ymine {
namespace service {
namespace interface {

struct ISdl {
    virtual ~ISdl() {}

    virtual int init(Uint32 flags) const = 0;
    virtual void quit() const = 0;

    virtual SDL_Window* createWindow(const char* title, int x, int y, int w, int h, Uint32 flags) const = 0;
    virtual void destroyWindow(SDL_Window* window) const = 0;

    virtual SDL_GLContext glCreateContext(SDL_Window* window) const = 0;
    virtual void glDeleteContext(SDL_GLContext context) const = 0;
    virtual void glSwapWindow(SDL_Window* window) const = 0;
};

} /* namespace interface */
} /* namespace service */
} /* namespace ymine */

#endif /* SRC_SERVICE_INTERFACE_ISDL_H_ */
