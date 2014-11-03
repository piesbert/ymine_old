/* File:       Window.h
 * Project:    ymine
 * Created on: Nov 3, 2014 8:58:52 PM
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

#ifndef SRC_OPENGL_WINDOW_H_
#define SRC_OPENGL_WINDOW_H_

#include "opengl/interface/IWindow.h"

#include "service/interface/ISdl.h"
#include "service/interface/IConfig.h"

namespace ymine {
namespace opengl {

class Window : public opengl::interface::IWindow {
public:
    Window();
    virtual ~Window();

    void draw();

private:
    service::interface::ISdl &m_sdl;
    service::interface::IConfig &m_config;

    SDL_Window *m_window;
    SDL_GLContext m_glContext;

    int m_red;
    int m_green;
    int m_blue;

    void setGlAttributes();
    void checkColors();
};

} /* namespace opengl */
} /* namespace ymine */

#endif /* SRC_OPENGL_WINDOW_H_ */
