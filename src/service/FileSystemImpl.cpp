/* File:       FileSystemImpl.cpp
 * Project:    ymine
 * Created on: Nov 20, 2014 5:25:04 PM
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

#include "FileSystemImpl.h"

#ifdef _WIN32
const std::string DIR_DELIMITER  = "\\";
#else
const std::string DIR_DELIMITER = "/";
#endif

namespace ymine {
namespace service {

FileSystemImpl::FileSystemImpl() {
}

FileSystemImpl::~FileSystemImpl() {
}

const std::string &FileSystemImpl::getDirDelimiter() const {
    return DIR_DELIMITER;
}

} /* namespace service */
} /* namespace ymine */
