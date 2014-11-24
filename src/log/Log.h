/* File:       Log.h
 * Project:    ymine
 * Created on: Nov 2, 2014 11:03:34 AM
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

#ifndef SRC_LOG_LOG_H_
#define SRC_LOG_LOG_H_

#include <fstream>
#include <string.h>

#define SHORT_FILE_NAME(FILE) (strrchr(FILE, '/') ? strrchr(FILE, '/') + 1 : FILE)

#define LOGERR(L_MSG) ymine::log::Log::instance() \
    << ymine::log::Log::EType::ERR \
    << SHORT_FILE_NAME(__FILE__) \
    << ymine::log::Log::EIntModifier::LINE << __LINE__ \
    << L_MSG << ymine::log::Log::EType::END;

#define LOGWRN(L_MSG) ymine::log::Log::instance() \
    << ymine::log::Log::EType::WRN \
    << SHORT_FILE_NAME(__FILE__) \
    << ymine::log::Log::EIntModifier::LINE << __LINE__ \
    << L_MSG << ymine::log::Log::EType::END;

#define LOGINF(L_MSG) ymine::log::Log::instance() \
    << ymine::log::Log::EType::INF \
    << SHORT_FILE_NAME(__FILE__) \
    << ymine::log::Log::EIntModifier::LINE << __LINE__ \
    << L_MSG << ymine::log::Log::EType::END;

#define LOGLUA(L_MSG) ymine::log::Log::instance() \
    << ymine::log::Log::EType::LUA \
    << L_MSG << ymine::log::Log::EType::END;

#define LOGDEF(L_MSG) ymine::log::Log::instance() \
    << L_MSG << ymine::log::Log::EType::END;

namespace ymine {
namespace log {

class Log {
public:
    static Log &instance();
    virtual ~Log();

    enum class EType {ERR, WRN, INF, LUA, END};
    enum class EIntModifier {INT, LINE};

    friend Log &operator<<(Log &log, const EType type);
    friend Log &operator<<(Log &log, const EIntModifier type);
    friend Log &operator<<(Log &log, const std::string &message);
    friend Log &operator<<(Log &log, const int integer);

    Log(const Log &) = delete;
    Log &operator=(const Log &) = delete;

private:
    unsigned int m_errorCounter;
    unsigned int m_warningCounter;

    std::ofstream m_file;

    EIntModifier m_intModifier;

    Log();
};

} /* namespace log */
} /* namespace ymine */

#endif /* SRC_LOG_LOG_H_ */
