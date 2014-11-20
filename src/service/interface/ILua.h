/* File:       ILuaStack.h
 * Project:    ymine
 * Created on: Nov 20, 2014 12:12:44 AM
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

#ifndef SRC_LUA_INTERFACE_ILUA_H_
#define SRC_LUA_INTERFACE_ILUA_H_

extern "C" {
#include "lua5.1/lua.hpp"
}

#include <string>

namespace ymine {
namespace service {
namespace interface {

struct ILua {
    virtual ~ILua() {}

    virtual void init() = 0;
    virtual lua_State* getStack() = 0;

    virtual bool loadScript(const std::string &path) = 0;
};

} /* namespace interface */
} /* namespace service */
} /* namespace ymine */

#endif /* SRC_LUA_INTERFACE_ILUA_H_ */
