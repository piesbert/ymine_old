/* File:       Application.h
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

#ifndef SRC_CORE_APPLICATION_H_
#define SRC_CORE_APPLICATION_H_

#include "interface/IConfig.h"
#include "interface/ISdl.h"

#include <memory>

namespace ymine {
namespace core {

class Application {
public:
	Application();
	virtual ~Application();

	int main(int argc, char *argv[]);

private:
	std::unique_ptr<interface::IConfig> m_config;
	std::unique_ptr<interface::ISdl> m_sdl;

	void initServices();
};

} /* namespace core */
} /* namespace ymine */

#endif /* SRC_CORE_APPLICATION_H_ */
