/* File:       Game.cpp
 * Project:    ymine
 * Created on: Nov 4, 2014 7:10:01 PM
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

#include "Game.h"

#include "service/Lua.h"
#include "service/Sdl.h"
#include "service/FileSystem.h"

#include "log/Log.h"

namespace ymine {
namespace core {

Game::Game(std::shared_ptr<opengl::interface::IWindow> window, std::shared_ptr<input::interface::IEventHandler> eventHandler)
: m_sdl(service::Sdl::instance()),
  m_running(true),
  m_timePrevious(0),
  m_timeCurrent(0),
  m_timeElapsed(0),
  m_lag(0) {

    /* Run initial lua scripts.
     */
    service::Lua::instance().loadScript(service::FileSystem::instance().getGameDir() + "/script/Init.lua");

    m_window = window;
    m_eventHandler = eventHandler;

    m_eventHandler.get()->registerGame(this);
}

Game::~Game() {
}

void Game::start() {
    m_timePrevious = m_sdl.getTicks();

    while (m_running) {
        m_timeCurrent = m_sdl.getTicks();
        m_timeElapsed = m_timeCurrent - m_timePrevious;

        m_timePrevious = m_timeCurrent;
        m_lag += m_timeElapsed;

        m_eventHandler.get()->processEvents();

        while (m_lag >= MS_PER_UPDATE) {
            // update();

            m_lag -= MS_PER_UPDATE;
        }

        m_sdl.delay(10);
        // render();
    }
}

void Game::quit() {
    m_running = false;
}

} /* namespace core */
} /* namespace ymine */
