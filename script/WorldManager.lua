-- File:       Init.lua
-- Project:    ymine
-- Created on: Nov 24, 2014 22:14:34 AM
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

require "lfs"

worldManager = {}

worldManager.worldsDirs = {
    ["game"] = GAME_DIR..DIR_DELIMITER.."worlds"..DIR_DELIMITER,
    ["user"] = USER_DIR..DIR_DELIMITER.."worlds"..DIR_DELIMITER
}

worldManager.worldCount = 0

worldManager.currentWorldId = 0
worldManager.currentWorldPath = ""
worldManager.currentWorldName = ""
worldManager.currentWorldType = ""

local function isDir(path)
    retval = false
    
    if (nil ~= lfs.attributes(path)) then
        if ("directory" == lfs.attributes(path,"mode")) then
            retval = true
        end
    end
    
    if (path == '.') or (path == '..') then
        retval = false
    end
    
    return retval
end

local function isFile(path)
    retval = false
    
    if (nil ~= lfs.attributes(path)) then
        if ("file" == lfs.attributes(path,"mode")) then
            retval = true
        end
    end
    
    return retval
end

function worldManager.processWorld()
    retval = false

    if isFile(worldManager.currentConfig) then        
        dofile(worldManager.currentConfig)
        
        worldManager.currentWorldId   = worldManager.currentWorldId + 1
        worldManager.currentWorldName = Game.worldName
        worldManager.currentWorldType = worldManager.currentType
        
        Game.log("New world found: "..worldManager.currentWorldName..", Id: "..worldManager.currentWorldId)
    else
        Game.log("Missing 'Config.lua' in "..worldManager.currentWorldPath)
    end
    
    return retval
end

function worldManager.scan()
    worldsFound = 0
      
    for path in lfs.dir(worldManager.currentPath) do
    
    -- Ignore ./ and ../ folders
    if (path ~= ".") and (path ~= "..") then
        worldManager.currentWorldPath = worldManager.currentPath..path
        
        if (isDir(worldManager.currentWorldPath)) then
            worldManager.currentConfig = worldManager.currentWorldPath..DIR_DELIMITER.."Config.lua"
            
            if worldManager.processWorld() then
                worldsFound = worldsFound + 1
            end
        end
    end
    
    end -- for
    
    return worldsFound
end

function worldManager.init()
    Game.log("Searching for new worlds.")
    
    for type, path in pairs(worldManager.worldsDirs) do
        Game.log("Scaning "..path)
        
        if (isDir(path)) then
            worldManager.currentType = type
            worldManager.currentPath = path
        
            worldsCount = worldManager.scan()
            
            worldManager.worldCount = worldManager.worldCount + worldsCount
        end
    end
    
    Game.log("Worlds found: "..worldManager.worldCount)
end

worldManager.init()