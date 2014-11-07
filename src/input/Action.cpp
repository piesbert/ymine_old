/* File:       Action.cpp
 * Project:    ymine
 * Created on: Nov 7, 2014 5:40:18 PM
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

#include "Action.h"

namespace ymine {
namespace input {

Action::Action()
: m_device(DeviceId::DEVICE_UNKNOWN),
  m_code(-1) {
}

Action::~Action() {
}

Action::State Action::isValid(const SDL_Event &event) const {
    State retval = State::STATE_UNKNOWN;

    if ((DeviceId::DEVICE_KEYBOARD == m_device) && (m_code == event.key.keysym.sym)) {
        if (event.type == SDL_KEYDOWN) {
            retval = State::STATE_PRESSED;
        }
        else if (event.type == SDL_KEYUP) {
            retval = State::STATE_RELEASED;
        }
    }
    else if ((DeviceId::DEVICE_MOUSE == m_device) && (m_code == event.button.button)) {
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            retval = State::STATE_PRESSED;
        }
        else if (event.type == SDL_MOUSEBUTTONUP) {
            retval = State::STATE_RELEASED;
        }
    }

    return retval;
}

void Action::configure(Action::DeviceId deviceId, int code) {
    m_device = deviceId;
    m_code   = code;
}

} /* namespace input */
} /* namespace ymine */
