-- File:       Init.lua
-- Project:    ymine
-- Created on: Nov 18, 2014 22:14:34 AM
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

scriptPath = GAME_DIR..DIR_DELIMITER.."script"..DIR_DELIMITER

local scripts = {
    "Game.lua"
}

for key, value in pairs(scripts) do
    Game.log("Running: "..value)
    dofile(scriptPath..value)
end