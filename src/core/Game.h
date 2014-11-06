/* File:       Game.h
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

#ifndef SRC_CORE_GAME_H_
#define SRC_CORE_GAME_H_

#include "interface/IGame.h"

#include "opengl/interface/IWindow.h"
#include "input/interface/IEventHandler.h"
#include "service/interface/ISdl.h"

#include <memory>

const int MS_PER_UPDATE = 5;

namespace ymine {
namespace core {

class Game: public core::interface::IGame {
public:
    Game(std::shared_ptr<opengl::interface::IWindow> window, std::shared_ptr<input::interface::IEventHandler> eventHandler);
    virtual ~Game();

    void start();
    void quit();

private:
    service::interface::ISdl &m_sdl;

    std::shared_ptr<opengl::interface::IWindow> m_window;
    std::shared_ptr<input::interface::IEventHandler> m_eventHandler;

    bool m_running;

    int m_timePrevious;
    int m_timeCurrent;
    int m_timeElapsed;
    int m_lag;
};

} /* namespace core */
} /* namespace ymine */

#endif /* SRC_CORE_GAME_H_ */
