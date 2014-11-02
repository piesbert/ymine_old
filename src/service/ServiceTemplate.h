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

template<class S, class T>
class ServiceTemplate : public T {
public:
	virtual ~ServiceTemplate() {}

	static S &instance() {
		static S singleInstance;
		return singleInstance;
	}

	virtual void initServiceImpl(T const *impl) final {
		if (nullptr == m_impl) {
			m_impl = impl;
		}
	}

protected:
	T const *m_impl;
	inline explicit ServiceTemplate() : m_impl(nullptr) {}

private:
	ServiceTemplate(const ServiceTemplate&) = delete;
	ServiceTemplate& operator=(const ServiceTemplate&) = delete;
};

} /* namespace service */
} /* namespace ymine */

#endif /* SRC_SERVICE_SERVICETEMPLATE_H_ */
