/* File:       Node.cpp
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

#include "Node.h"

namespace ymine {
namespace world {

Node::Node()
: m_type(NORMAL),
  m_diggable(false),
  m_hitPoints(1) {
}

Node::~Node() {
}

void Node::serialize(std::ostream &os, unsigned int protocolVersion) {
}

void Node::deSerialize(std::istream &is) {
}

void Node::setName(const std::string &name) {
    m_name = name;
}

std::string &Node::getName() {
    return m_name;
}

void Node::setType(Type type) {
    m_type = type;
}
Node::Type Node::getType() {
    return m_type;
}

void Node::setDiggable(bool diggable) {
    m_diggable = false;

    if (m_type < NON_DIGABBLE) {
        m_diggable = diggable;
    }
}

bool Node::getDiggable() {
    return m_diggable;
}

void Node::setHitPoints(int hitPoints) {
    m_hitPoints = hitPoints;
}

int Node::getHitPoints() {
    int retval = 1;

    if (m_type < NON_DIGABBLE) {
        retval = m_hitPoints;
    }

    return retval;
}

} /* namespace world */
} /* namespace ymine */
