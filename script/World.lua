-- File:       Init.lua
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

World.registeredNodes = {}

local aliasMetatable = {
    __index = function(t, name)
        return rawget(t, core.registered_aliases[name])
    end
}

setmetatable(World.registeredNodes, aliasMetatable)
ymineLog("Creating World metatables... done")

function World.registerObject(name, object)
    if ("node" == object.type) then
        setmetatable(object, {__index = World.registeredNodes})
        World.registeredNodes[object.name] = object
    end
end

function World.registerNode(name, node)
    node.type = "node"
    World.registerObject(node)
end