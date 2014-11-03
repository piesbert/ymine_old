/* File:       Application.cpp
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

#include "core/Application.h"

#include "service/ConfigImpl.h"
#include "service/Config.h"
#include "service/SdlImpl.h"
#include "service/Sdl.h"

#include "log/Log.h"

namespace ymine {
namespace core {

Application::Application()
: m_config (new service::ConfigImpl()),
  m_sdl (new service::SdlImpl) {
	initServices();
}

Application::~Application() {
}

int Application::main(int argc, char *argv[]) {
	return 0;
}

void Application::initServices() {
	service::Config::instance().initServiceImpl(m_config.get());
	service::Sdl::instance().initServiceImpl(m_sdl.get());
}

} /* namespace core */
} /* namespace ymine */

using namespace ymine;

int main(int argc, char *argv[]) {
	core::Application application;
	return application.main(argc, argv);
}
