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

namespace ymine {
namespace core {

Game::Game(std::shared_ptr<opengl::interface::IWindow> window, std::shared_ptr<input::interface::IEventHandler> eventHandler)
: m_running(true) {
    m_window = window;
    m_eventHandler = eventHandler;

    m_eventHandler.get()->registerGame(this);
}

Game::~Game() {
}

void Game::start() {
}

void Game::quit() {
    m_running = false;
}

} /* namespace core */
} /* namespace ymine */
