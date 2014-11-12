/* File:       IEventHandler.h
 * Project:    ymine
 * Created on: Nov 4, 2014 5:06:14 PM
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

#ifndef SRC_INPUT_INTERFACE_IEVENTHANDLER_H_
#define SRC_INPUT_INTERFACE_IEVENTHANDLER_H_

#include "core/interface/IGame.h"
#include "input/interface/IAction.h"

namespace ymine {
namespace input {
namespace interface {

struct IEventHandler {
    virtual ~IEventHandler() {}

    enum ActionId : int {
        ACTION_NOTHING = 0,
        ACTION_FORWARD,
        ACTION_BACKWARD,
        ACTION_STRAFE_LEFT,
        ACTION_STRAFE_RIGHT,
        ACTION_JUMP,
        ACTION_USE,
        ACTION_QUIT,
        ACTION_MAX
    };

    virtual void processEvents() = 0;
    virtual void registerGame(core::interface::IGame *game) = 0;

    virtual void setAction(ActionId actioId, IAction::DeviceId deviceId, int code) = 0;
};

} /* namespace interface */
} /* namespace input */
} /* namespace ymine */

#endif /* SRC_INPUT_INTERFACE_IEVENTHANDLER_H_ */
