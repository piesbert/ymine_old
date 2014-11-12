/* File:       EventHandler.h
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

#ifndef SRC_INPUT_EVENTHANDLER_H_
#define SRC_INPUT_EVENTHANDLER_H_

#include "input/interface/IEventHandler.h"
#include "core/interface/IGame.h"
#include "service/interface/ISdl.h"

#include "input/Action.h"

#include <SDL2/SDL.h>

namespace ymine {
namespace input {

class EventHandler : public input::interface::IEventHandler {
public:
    EventHandler();
    virtual ~EventHandler();

    void processEvents();
    void registerGame(ymine::core::interface::IGame *game);

    void setAction(ActionId actioId, interface::IAction::DeviceId deviceId, int code);

private:
    service::interface::ISdl &m_sdl;
    core::interface::IGame *m_game;

    SDL_Event m_event;

    Action m_action[ActionId::ACTION_MAX];

    void defaultConfig();

    void handleEvent() const;
    void runAction(ActionId, Action::State) const;
};

} /* namespace input */
} /* namespace ymine */

#endif /* SRC_INPUT_EVENTHANDLER_H_ */
