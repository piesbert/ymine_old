/* File:       Config.cpp
 * Project:    ymine
 * Created on: Oct 29, 2014 01:00:00 AM
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

#include "service/Config.h"

namespace ymine {
namespace service {

Config::Config() {
}

Config::~Config() {
}

int Config::windowWidth() const {
	return m_impl->windowWidth();
}

int Config::windowHeight() const {
	return m_impl->windowHeight();
}

const std::string &Config::windowTitle() const {
    return m_impl->windowTitle();
}

const std::string &Config::logFile() const {
    return m_impl->logFile();
}

} /* namespace config */
} /* namespace ymine */
