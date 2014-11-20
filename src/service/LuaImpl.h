/* File:       LuaImpl.h
 * Project:    ymine
 * Created on: Nov 20, 2014 6:04:21 PM
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

#ifndef SRC_SERVICE_LUAIMPL_H_
#define SRC_SERVICE_LUAIMPL_H_

#include "interface/ILua.h"

#include <string>

namespace ymine {
namespace service {

class LuaImpl: public interface::ILua {
public:
    LuaImpl();
    virtual ~LuaImpl();

    void init();
    lua_State* getStack();

    bool loadScript(const std::string &path);

private:
    lua_State* m_luaStack;

    int m_errorHandler;

    static int errorHandler(lua_State *L);
};

} /* namespace service */
} /* namespace ymine */

#endif /* SRC_SERVICE_LUAIMPL_H_ */
