/*
 * Application.h
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#ifndef SRC_CORE_APPLICATION_H_
#define SRC_CORE_APPLICATION_H_

namespace ymine {
namespace core {

class Application {
public:
	Application();
	virtual ~Application();

	int main(int argc, char *argv[]);
};

} /* namespace core */
} /* namespace ymine */

#endif /* SRC_CORE_APPLICATION_H_ */
