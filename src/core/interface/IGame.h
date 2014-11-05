/* File:       IGame.h
 * Project:    ymine
 * Created on: Nov 4, 2014 5:09:20 PM
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

#ifndef SRC_CORE_INTERFACE_IGAME_H_
#define SRC_CORE_INTERFACE_IGAME_H_

namespace ymine {
namespace core {
namespace interface {

struct IGame {
    virtual ~IGame() {}

    virtual void start() = 0;
    virtual void quit() = 0;
};

} /* namespace interface */
} /* namespace core */
} /* namespace ymine */

#endif /* SRC_CORE_INTERFACE_IGAME_H_ */
