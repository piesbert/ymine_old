/* File:       Window.cpp
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

#include "Window.h"

#include "log/Log.h"
#include "service/Sdl.h"
#include "service/Config.h"

namespace ymine {
namespace opengl {

Window::Window()
: m_sdl(service::Sdl::instance()),
  m_config(service::Config::instance()),
  m_window(nullptr),
  m_glContext(nullptr) {
    if (m_sdl.init(SDL_INIT_VIDEO) < 0) {
        LOGERR(m_sdl.getError());
        exit(2);
    }

    setGlAttributes();

    m_window = m_sdl.createWindow(
            m_config.windowTitle().c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            m_config.windowWidth(), m_config.windowHeight(),
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (nullptr == m_window) {
        LOGERR(m_sdl.getError());
        exit(2);
    }

    m_glContext = m_sdl.glCreateContext(m_window);
    if (nullptr == m_glContext) {
        LOGERR(m_sdl.getError());
        exit(2);
    }

    checkColors();

    /* VSync on.
     */
    m_sdl.glSetSwapInterval(1);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

Window::~Window() {
    if (nullptr != m_glContext) {
        m_sdl.glDeleteContext(m_glContext);
    }
    if (nullptr != m_window) {
        m_sdl.destroyWindow(m_window);
    }

    m_sdl.quit();
}

void Window::draw() {
    m_sdl.glSwapWindow(m_window);
}

void Window::setGlAttributes() {
    /* Request an OpenGL 3.0 context.
     */
    m_sdl.glSetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    m_sdl.glSetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    /* Request double buffer .
     */
    m_sdl.glSetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    /* Turn on x4 multisampling anti-aliasing (MSAA)
     */
    m_sdl.glSetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    m_sdl.glSetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
}

void Window::checkColors() {
    m_sdl.glGetAttribute(SDL_GL_RED_SIZE, &m_red);
    m_sdl.glGetAttribute(SDL_GL_GREEN_SIZE, &m_green);
    m_sdl.glGetAttribute(SDL_GL_BLUE_SIZE, &m_blue);

    LOGINF("RGB buffer size: " << m_red << "x" << m_green << "x" << m_blue);
}

} /* namespace opengl */
} /* namespace ymine */
