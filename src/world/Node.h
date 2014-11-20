/* File:       Node.h
 * Project:    ymine
 * Created on: Nov 21, 2014 12:25:52 AM
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

#ifndef WORLD_NODE_H_
#define WORLD_NODE_H_

#include "interface/INode.h"

namespace ymine {
namespace world {

class Node: public interface::INode {
public:
    Node();
    virtual ~Node();

    void serialize(std::ostream &os, unsigned int protocolVersion);
    void deSerialize(std::istream &is);

    void setName(const std::string &name);
    std::string &getName();

    void setType(Type type);
    Type getType();

    void setDiggable(bool diggable);
    bool getDiggable();

    void setHitPoints(int hitPoints);
    int getHitPoints();

private:
    std::string     m_name;
    Type            m_type;
    bool            m_diggable;
    unsigned int    m_hitPoints;
};

} /* namespace world */
} /* namespace ymine */

#endif /* WORLD_NODE_H_ */
