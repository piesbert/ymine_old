/*
 * ConfigImpl.cpp
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#include "ConfigImpl.h"

namespace ymine {
namespace config {

ConfigImpl::ConfigImpl() :
	m_width(800),
	m_height(600) {
}

ConfigImpl::~ConfigImpl() {
}

int ConfigImpl::windowWidth() const {
	return m_width;
}

int ConfigImpl::windowHeight() const {
	return m_height;
}

} /* namespace config */
} /* namespace ymine */
