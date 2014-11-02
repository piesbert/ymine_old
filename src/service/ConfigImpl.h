/*
 * ConfigImpl.h
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#ifndef SRC_SERVICE_CONFIGIMPL_H_
#define SRC_SERVICE_CONFIGIMPL_H_

#include "interface/IConfig.h"

namespace ymine {
namespace service {

class ConfigImpl : public interface::IConfig {
public:
	ConfigImpl();
	virtual ~ConfigImpl();

	int windowWidth() const;
	int windowHeight() const;

	const std::string &logFile() const;

private:
	int m_width;
	int m_height;

	std::string m_logFile;
};

} /* namespace config */
} /* namespace ymine */

#endif /* SRC_SERVICE_CONFIGIMPL_H_ */
