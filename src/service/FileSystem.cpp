/* File:       FileSystem.cpp
 * Project:    ymine
 * Created on: Nov 20, 2014 5:32:21 PM
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

#include "FileSystem.h"

namespace ymine {
namespace service {

FileSystem::FileSystem() {
}

FileSystem::~FileSystem() {
}

const std::string &FileSystem::getDirDelimiter() const {
    return m_impl->getDirDelimiter();
}

const std::string &FileSystem::getGameDir() const {
    return m_impl->getGameDir();
}

const std::string &FileSystem::getUserDir() const {
    return m_impl->getUserDir();
}

} /* namespace service */
} /* namespace ymine */
