/*
 * Application.cpp
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
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

int main(int argc, char *argv[]) {
	ymine::core::Application application;
	return application.main(argc, argv);
}
