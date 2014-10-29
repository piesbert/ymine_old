/*
 * Application.cpp
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#include "core/Application.h"

#include "service/ConfigImpl.h"
#include "service/Config.h"

namespace ymine {
namespace core {

Application::Application()
: m_config (new service::ConfigImpl()) {
	initServices();
}

Application::~Application() {
}

int Application::main(int argc, char *argv[]) {
	return 0;
}

void Application::initServices() {
	service::Config::instance().init(m_config.get());
}

} /* namespace core */
} /* namespace ymine */

int main(int argc, char *argv[]) {
	ymine::core::Application application;
	return application.main(argc, argv);
}
