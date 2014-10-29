/*
 * Config.h
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#ifndef SRC_CONFIG_CONFIG_H_
#define SRC_CONFIG_CONFIG_H_

#include "config/ConfigImpl.h"

namespace ymine {
namespace config {

class Config {
public:
	static Config &instance();
	virtual ~Config();

	void init(interface::IConfig const *config);

	int windowWidth() const;
    int windowHeight() const;

    Config(Config const&) = delete;
    void operator=(Config const&) = delete;

private:
	Config();

	interface::IConfig const *m_config;
};

} /* namespace config */
} /* namespace ymine */

#endif /* SRC_CONFIG_CONFIG_H_ */
