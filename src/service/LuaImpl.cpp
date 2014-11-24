/* File:       LuaImpl.cpp
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

#include "LuaImpl.h"

#include "FileSystem.h"

#include "log/Log.h"


namespace ymine {
namespace service {

LuaImpl::LuaImpl()
: m_luaStack(nullptr),
  m_errorHandler(0) {
}

LuaImpl::~LuaImpl() {
    lua_close(m_luaStack);
}

void LuaImpl::init() {
    m_luaStack = luaL_newstate();

    if (nullptr == m_luaStack) {
        LOGERR("Lua stack initialization failed!");
        exit(-2);
    }

    luaL_openlibs(m_luaStack);

    lua_pushcfunction(m_luaStack, LuaImpl::errorHandler);
    m_errorHandler = lua_gettop(m_luaStack);

    lua_newtable(m_luaStack);
    lua_setglobal(m_luaStack, "Game");

    setGlobalVariables();
    setGlobalFunctions();

    LOGINF("Lua initialization... done");
}

lua_State* LuaImpl::getStack() {
    return m_luaStack;
}

bool LuaImpl::loadScript(const std::string &path) {
    bool retval = true;

    LOGINF("Loading and running script from " << path);

    lua_State *L = getStack();

    int status = luaL_loadfile(L, path.c_str()) || lua_pcall(L, 0, 0, m_errorHandler);

    if (status) {
        LOGWRN("In Lua script: " << path);
        LOGERR("Error raport : BEGIN");
        LOGDEF(lua_tostring(L, -1));
        LOGERR("Error raport : END");
        lua_pop(L, 1); // Pop error message from stack
        retval = false;
    }

    return retval;
}

void LuaImpl::setGlobalVariables() {
    lua_pushstring(m_luaStack, FileSystem::instance().getDirDelimiter().c_str());
    lua_setglobal(m_luaStack, "DIR_DELIMITER");

    lua_pushfstring(m_luaStack, FileSystem::instance().getGameDir().c_str());
    lua_setglobal(m_luaStack, "GAME_DIR");

    lua_pushfstring(m_luaStack, FileSystem::instance().getUserDir().c_str());
    lua_setglobal(m_luaStack, "USER_DIR");
}

void LuaImpl::setGlobalFunctions() {
    lua_pushcfunction(m_luaStack, log);
    lua_setglobal(m_luaStack, "ymineLog");
}

int LuaImpl::errorHandler(lua_State *L) {
    bool done = false;

    lua_getglobal(L, "debug");

    if (!lua_istable(L, -1)) {
            lua_pop(L, 1);
            done = true;
    }

    if(!done) {
        lua_getfield(L, -1, "traceback");
        if (!lua_isfunction(L, -1)) {
            lua_pop(L, 2);
            done = true;
        }
    }

    if (!done) {
        lua_pushvalue(L, 1);
        lua_pushinteger(L, 2);
        lua_call(L, 2, 1);
    }

    return 1;
}

int LuaImpl::log(lua_State *L) {
    const char* message = lua_tostring(L, 1);

    lua_Debug debug;
    lua_getstack(L, 1, &debug);
    lua_getinfo(L, "Sl", &debug);

    LOGLUA(SHORT_FILE_NAME(debug.short_src) << "(" << debug.currentline << "): " << message);

    return 0;
}

} /* namespace service */
} /* namespace ymine */
