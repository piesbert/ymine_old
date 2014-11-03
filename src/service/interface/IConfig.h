/* File:       IConfig.h
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

#ifndef SRC_SERVICE_INTERFACE_ICONFIG_H_
#define SRC_SERVICE_INTERFACE_ICONFIG_H_

#include <string>

namespace ymine {
namespace service {
namespace interface {

struct IConfig {
	virtual ~IConfig() {}

	virtual int windowWidth() const = 0;
	virtual int windowHeight() const = 0;
	virtual const std::string &windowTitle() const = 0;

	virtual const std::string &logFile() const = 0;
};

} /* namespace interface */
} /* namespace service */
} /* namespace ymine */

#endif /* SRC_SERVICE_INTERFACE_ICONFIG_H_ */
