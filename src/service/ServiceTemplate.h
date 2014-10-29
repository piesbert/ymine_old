/*
 * Service.h
 *
 *  Created on: 29 paź 2014
 *      Author: piesbert
 */

#ifndef SRC_SERVICE_SERVICETEMPLATE_H_
#define SRC_SERVICE_SERVICETEMPLATE_H_

namespace ymine {
namespace service {

template<class T>
class ServiceTemplate : public T {
public:
	ServiceTemplate() : m_impl(nullptr) {}
	virtual ~ServiceTemplate() {}

	void init(T const *impl) {
		if (nullptr == m_impl) {
			m_impl = impl;
		}
	}

protected:
	T const *m_impl;
};

} /* namespace service */
} /* namespace ymine */

#endif /* SRC_SERVICE_SERVICETEMPLATE_H_ */
