/*
 * Config.h
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#ifndef SRC_SERVICE_CONFIG_H_
#define SRC_SERVICE_CONFIG_H_

#include "service/ServiceTemplate.h"
#include "interface/IConfig.h"

namespace ymine {
namespace service {

class Config : public service::ServiceTemplate<Config, interface::IConfig> {
public:
	//Config();
	virtual ~Config();

	int windowWidth() const;
    int windowHeight() const;
};

} /* namespace config */
} /* namespace ymine */

#endif /* SRC_SERVICE_CONFIG_H_ */
