/* File:       INode.h
 * Project:    ymine
 * Created on: Nov 20, 2014 11:59:20 PM
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

#ifndef WORLD_INTERFACE_INODE_H_
#define WORLD_INTERFACE_INODE_H_

#include "ISerializable.h"

#include <string>

namespace ymine {
namespace world {
namespace interface {

struct INode : public ISerializable {
    virtual ~INode() {}

    enum Type {
        NORMAL,
        GLASS,
        LEAVES,

        NON_DIGABBLE,

        AIR,
        LIQUID
    };

    virtual void setName(const std::string &name) = 0;
    virtual std::string &getName() = 0;

    virtual void setType(Type type) = 0;
    virtual Type getType() = 0;

    virtual void setDiggable(bool diggable) = 0;
    virtual bool getDiggable() = 0;

    virtual void setHitPoints(int hitPoints) = 0;
    virtual int getHitPoints() = 0;
};

} /* namespace interface */
} /* namespace world */
} /* namespace ymine */

#endif /* WORLD_INTERFACE_INODE_H_ */
