/* File:       ConfigImpl.h
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

#ifndef SRC_SERVICE_CONFIGIMPL_H_
#define SRC_SERVICE_CONFIGIMPL_H_

#include "interface/IConfig.h"

namespace ymine {
namespace service {

class ConfigImpl : public interface::IConfig {
public:
	ConfigImpl();
	virtual ~ConfigImpl();

	int windowWidth() const;
	int windowHeight() const;
	const std::string &windowTitle() const;

	const std::string &logFile() const;

private:
	int m_width;
	int m_height;
	std::string m_windowTitle;

	std::string m_logFile;
};

} /* namespace config */
} /* namespace ymine */

#endif /* SRC_SERVICE_CONFIGIMPL_H_ */
