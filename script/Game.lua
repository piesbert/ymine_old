-- File:       Game.lua
-- Project:    ymine
-- Created on: Nov 19, 2014 22:58:34 AM
-- Author:     piesbert
--
-- Copyright (C) 2014 Sebastian Szymak
--
-- This program is free software; you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation; either version 2 of the License, or
-- (at your option) any later version.
--
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License along
-- with this program; if not, write to the Free Software Foundation, Inc.,
-- 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.    
--

Game.registeredNodes = {}
Game.registeredAliases = {}

local aliasMetatable = {
    __index = function(t, name)
        return rawget(t, Game.registeredAliases[name])
    end
}

setmetatable(Game.registeredNodes, aliasMetatable)
Game.log("Creating Game metatables... done")

function Game.registerObject(name, object)
    if ("node" == object.type) then
        setmetatable(object, {__index = Game.registeredNodes})
        Game.registeredNodes[object.name] = object
    end
end

function Game.registerNode(name, node)
    node.type = "node"
    Game.registerObject(node)
end