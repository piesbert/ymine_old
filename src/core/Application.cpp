/*
 * Application.cpp
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#include "core/Application.h"
#include "config/Config.h"

namespace ymine {
namespace core {

Application::Application() {
}

Application::~Application() {
}

int Application::main(int argc, char *argv[]) {
	return 0;
}

} /* namespace core */
} /* namespace ymine */

int main(int argc, char *argv[]) {
	ymine::core::Application application;

	ymine::config::Config::instance().init(new ymine::config::ConfigImpl);

	return application.main(argc, argv);
}
