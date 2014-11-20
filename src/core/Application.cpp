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
#include "service/FileSystemImpl.h"
#include "service/FileSystem.h"
#include "service/LuaImpl.h"
#include "service/Lua.h"
#include "service/MotionStateImpl.h"
#include "service/MotionState.h"
#include "service/SdlImpl.h"
#include "service/Sdl.h"


#include "opengl/Window.h"
#include "input/EventHandler.h"
#include "core/Game.h"

#include "log/Log.h"

namespace ymine {
namespace core {

Application::Application() {
	initServices();

	m_window.reset(new opengl::Window());
	m_eventHandler.reset(new input::EventHandler());

	m_game.reset(new core::Game(m_window, m_eventHandler));
}

Application::~Application() {
}

int Application::main(int argc, char *argv[]) {
    m_game.get()->start();
	return 0;
}

void Application::initServices() {
    m_configImpl.reset(new service::ConfigImpl());
    service::Config::instance().initServiceImpl(m_configImpl.get());

    m_fileSystemImpl.reset(new service::FileSystemImpl());
    service::FileSystem::instance().initServiceImpl(m_fileSystemImpl.get());

    m_luaImpl.reset(new service::LuaImpl());
    service::Lua::instance().initServiceImpl(m_luaImpl.get());

    m_motionStateImpl.reset(new service::MotionStateImpl());
    service::MotionState::instance().initServiceImpl(m_motionStateImpl.get());

    m_sdlImpl.reset(new service::SdlImpl());
    service::Sdl::instance().initServiceImpl(m_sdlImpl.get());

    LOGINF("Services initialization... done.");

    service::Lua::instance().init();
}

} /* namespace core */
} /* namespace ymine */
