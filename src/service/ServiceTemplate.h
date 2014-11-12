/* File:       ServiceTemplate.h
 * Project:    ymine
 * Created on: Oct 29, 2014 01:00:00 AM
 * Author:     piesbert
 *
 * Copyright (C) 2014 Sebastian Szymak
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
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

	virtual void initServiceImpl(T *impl) final {
		if (nullptr == m_impl) {
			m_impl = impl;
		}
	}

protected:
	T *m_impl;
	inline explicit ServiceTemplate() : m_impl(nullptr) {}

private:
	ServiceTemplate(const ServiceTemplate&) = delete;
	ServiceTemplate& operator=(const ServiceTemplate&) = delete;
};

} /* namespace service */
} /* namespace ymine */

#endif /* SRC_SERVICE_SERVICETEMPLATE_H_ */
