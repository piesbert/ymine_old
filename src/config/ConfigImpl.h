/*
 * ConfigImpl.h
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#ifndef SRC_CONFIG_CONFIGIMPL_H_
#define SRC_CONFIG_CONFIGIMPL_H_

#include "interface/IConfig.h"

namespace ymine {
namespace config {

class ConfigImpl: public interface::IConfig {
public:
	ConfigImpl();
	virtual ~ConfigImpl();

	int windowWidth() const;
	int windowHeight() const;

private:
	int m_width;
	int m_height;
};

} /* namespace config */
} /* namespace ymine */

#endif /* SRC_CONFIG_CONFIGIMPL_H_ */
