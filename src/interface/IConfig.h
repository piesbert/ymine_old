/*
 * IConfig.h
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#ifndef SRC_INTERFACE_ICONFIG_H_
#define SRC_INTERFACE_ICONFIG_H_

#include <memory>
#include <string>

namespace ymine {
namespace interface {

struct IConfig {
	virtual ~IConfig() {}

	virtual int windowWidth() const = 0;
	virtual int windowHeight() const = 0;

	virtual const std::string &logFile() const = 0;
};

} /* namespace interface */
} /* namespace ymine */

#endif /* SRC_INTERFACE_ICONFIG_H_ */
