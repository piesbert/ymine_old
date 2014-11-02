/* File:       ConfigImpl.cpp
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

#include "service/ConfigImpl.h"

namespace ymine {
namespace service {

ConfigImpl::ConfigImpl() :
	m_width(800),
	m_height(600),
	m_logFile("ymine.log") {
}

ConfigImpl::~ConfigImpl() {
}

int ConfigImpl::windowWidth() const {
	return m_width;
}

int ConfigImpl::windowHeight() const {
	return m_height;
}

const std::string &ConfigImpl::logFile() const {
    return m_logFile;
}

} /* namespace config */
} /* namespace ymine */
