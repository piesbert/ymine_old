/*
 * Application.h
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#ifndef SRC_CORE_APPLICATION_H_
#define SRC_CORE_APPLICATION_H_

#include "interface/IConfig.h"
#include "interface/ISdl.h"

namespace ymine {
namespace core {

class Application {
public:
	Application();
	virtual ~Application();

	int main(int argc, char *argv[]);

private:
	std::unique_ptr<interface::IConfig> m_config;
	std::unique_ptr<interface::ISdl> m_sdl;

	void initServices();
};

} /* namespace core */
} /* namespace ymine */

#endif /* SRC_CORE_APPLICATION_H_ */
