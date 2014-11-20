/* File:       Lua.cpp
 * Project:    ymine
 * Created on: Nov 20, 2014 6:13:23 PM
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

#include "Lua.h"

namespace ymine {
namespace service {

Lua::Lua() {
}

Lua::~Lua() {
}

void Lua::init() {
    m_impl->init();
}

lua_State* Lua::getStack() {
    return m_impl->getStack();
}

bool Lua::loadScript(const std::string &path) {
    return m_impl->loadScript(path);
}

} /* namespace service */
} /* namespace ymine */
