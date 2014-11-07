/* File:       IAction.h
 * Project:    ymine
 * Created on: Nov 7, 2014 5:34:58 PM
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

#ifndef SRC_INPUT_INTERFACE_IACTION_H_
#define SRC_INPUT_INTERFACE_IACTION_H_

#include <SDL2/SDL.h>

namespace ymine {
namespace input {
namespace interface {

struct IAction {
    virtual ~IAction() {}

    enum DeviceId : int {
        DEVICE_UNKNOWN = 0,
        DEVICE_KEYBOARD,
        DEVICE_MOUSE
    };

    enum State : int {
        STATE_UNKNOWN = 0,
        STATE_PRESSED,
        STATE_RELEASED
    };

    virtual State isValid(const SDL_Event &event) const = 0;
    virtual void configure(DeviceId deviceId, int code) = 0;
};

} /* namespace interface */
} /* namespace input */
} /* namespace ymine */

#endif /* SRC_INPUT_INTERFACE_IACTION_H_ */
