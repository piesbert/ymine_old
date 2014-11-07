/* File:       Action.h
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

#ifndef SRC_INPUT_ACTION_H_
#define SRC_INPUT_ACTION_H_

#include "interface/IAction.h"

namespace ymine {
namespace input {

class Action: public interface::IAction {
public:
    Action();
    virtual ~Action();

    virtual State isValid(const SDL_Event &event) const;
    virtual void configure(DeviceId deviceId, int code);

private:
    DeviceId m_device;
    int m_code;
};

} /* namespace input */
} /* namespace ymine */

#endif /* SRC_INPUT_ACTION_H_ */
