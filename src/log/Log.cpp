/* File:       Log.cpp
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

#include "Log.h"
#include "service/Config.h"

namespace ymine {
namespace log {

Log::Log()
: m_errorCounter(0),
  m_warningCounter(0),
  m_file(),
  m_intModifier(EIntModifier::INT) {
    m_file.open(service::Config::instance().logFile());

    if (m_file.is_open()) {
        m_file << "Log file created." << std::endl << std::endl;
    }
}

Log::~Log() {
    if (m_file.is_open()) {
        m_file << std::endl;

        m_file << m_warningCounter << " warnings." << std::endl;
        m_file << m_errorCounter << " errors." << std::endl;

        m_file.close();
    }
}

Log &Log::instance() {
    static Log instance;
    return instance;
}
Log &operator<<(Log &log, const Log::EType type) {
    switch (type) {
    case(Log::EType::ERR) : {
        log.m_file << "ERR ";
        log.m_errorCounter++;
        break;
    }
    case(Log::EType::WRN) : {
        log.m_file << "WRN ";
        log.m_warningCounter++;
        break;
    }
    case(Log::EType::INF) : {
        log.m_file << "INF ";
        break;
    }
    case(Log::EType::END) : {
        log.m_file << std::endl;
        break;
    }
    }

    return log;
}

Log &operator<<(Log &log, const Log::EIntModifier modifier) {
    log.m_intModifier = modifier;
    return log;
}

Log &operator<<(Log &log, const std::string &message) {
    log.m_file << message;
    return log;
}

Log &operator<<(Log &log, const int integer) {
    if (Log::EIntModifier::LINE == log.m_intModifier) {
        log.m_file << '(' << integer << "): ";
    }
    else {
        log.m_file << integer;
    }

    log.m_intModifier = Log::EIntModifier::INT;

    return log;
}

} /* namespace log */
} /* namespace ymine */
