/* File:       EventHandler.cpp
 * Project:    ymine
 * Created on: Nov 4, 2014 5:12:17 PM
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

#include "EventHandler.h"

#include "service/Sdl.h"
#include "log/Log.h"

namespace ymine {
namespace input {

EventHandler::EventHandler()
: m_sdl(service::Sdl::instance()),
  m_game(nullptr) {
}

EventHandler::~EventHandler() {
}

void EventHandler::processEvents() {
    while (m_sdl.pollEvent(&m_event)) {
        switch (m_event.type) {
        case SDL_QUIT : {
            LOGINF("SDL_QUIT event occurred.");
            m_game->quit();
            break;
        }
        }
    }
}

void EventHandler::registerGame(core::interface::IGame *game) {
        m_game = game;
}

} /* namespace input */
} /* namespace ymine */
