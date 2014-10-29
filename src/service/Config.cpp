/*
 * Config.cpp
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#include "service/Config.h"

namespace ymine {
namespace service {

Config::Config() {
}

Config::~Config() {
}

int Config::windowWidth() const {
	return m_impl->windowWidth();
}

int Config::windowHeight() const {
	return m_impl->windowHeight();
}

} /* namespace config */
} /* namespace ymine */
