/* File:       ISerializable.h
 * Project:    ymine
 * Created on: Nov 21, 2014 12:01:26 AM
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

#ifndef WORLD_INTERFACE_ISERIALIZABLE_H_
#define WORLD_INTERFACE_ISERIALIZABLE_H_

#include <iostream>

namespace ymine {
namespace world {
namespace interface {

struct ISerializable {
    virtual ~ISerializable() {}

    virtual void serialize(std::ostream &os, unsigned int protocolVersion) = 0;
    virtual void deSerialize(std::istream &is) = 0;
};

} /* namespace interface */
} /* namespace world */
} /* namespace ymine */

#endif /* WORLD_INTERFACE_ISERIALIZABLE_H_ */
