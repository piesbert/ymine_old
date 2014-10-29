/*
 * Config.cpp
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#include "Config.h"

namespace ymine {
namespace config {

Config::Config() : m_config(nullptr) {
}

Config::~Config() {
}

Config &Config::instance() {
	static Config instance;
	return instance;
}

void Config::init(interface::IConfig const *config) {
	m_config = config;
}

int Config::windowWidth() const {
	return m_config->windowWidth();
}
int Config::windowHeight() const {
	return m_config->windowHeight();
}

} /* namespace config */
} /* namespace ymine */
