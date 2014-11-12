/* File:       EventHandler.cpp
 * Project:    ymine
 * Created on: Nov 4, 2014 5:12:17 PM
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

#include "EventHandler.h"

#include "service/Sdl.h"
#include "log/Log.h"

namespace ymine {
namespace input {

EventHandler::EventHandler()
: m_sdl(service::Sdl::instance()),
  m_game(nullptr) {
    defaultConfig();
}

EventHandler::~EventHandler() {
}

void EventHandler::processEvents() {
    while (m_sdl.pollEvent(&m_event)) {
        if (SDL_QUIT == m_event.type) {
            LOGINF("SDL_QUIT event occurred.");
            m_game->quit();
        }
        else {
            handleEvent();
        }
    }
}

void EventHandler::registerGame(core::interface::IGame *game) {
        m_game = game;
}

void EventHandler::setAction(ActionId actionId, interface::IAction::DeviceId deviceId, int code) {
    LOGINF("Action ID: " << actionId << ", Device ID: " << deviceId << ", Code: " << code);
    m_action[actionId].configure(deviceId, code);
}

void EventHandler::defaultConfig() {
        setAction(ActionId::ACTION_NOTHING,     Action::DeviceId::DEVICE_UNKNOWN,  0);
        setAction(ActionId::ACTION_FORWARD,     Action::DeviceId::DEVICE_KEYBOARD, SDLK_w);
        setAction(ActionId::ACTION_BACKWARD,    Action::DeviceId::DEVICE_KEYBOARD, SDLK_s);
        setAction(ActionId::ACTION_STRAFE_LEFT, Action::DeviceId::DEVICE_KEYBOARD, SDLK_a);
        setAction(ActionId::ACTION_STRAFE_RIGHT,Action::DeviceId::DEVICE_KEYBOARD, SDLK_d);
        setAction(ActionId::ACTION_JUMP,        Action::DeviceId::DEVICE_KEYBOARD, SDLK_SPACE);
        setAction(ActionId::ACTION_USE,         Action::DeviceId::DEVICE_MOUSE,    SDL_BUTTON_LEFT);
        setAction(ActionId::ACTION_QUIT,        Action::DeviceId::DEVICE_KEYBOARD, SDLK_ESCAPE);
}

void EventHandler::handleEvent() const {
    ActionId action = ActionId::ACTION_NOTHING;
    Action::State state = Action::State::STATE_UNKNOWN;

    /* don't check ACTION_NOTHING */
    for (int i = 1; i < ActionId::ACTION_MAX; i++) {
        state = m_action[i].isValid(m_event);

        if (state) {
            action = ActionId(i);
            runAction(action, state);
        }
    }
}

void EventHandler::runAction(ActionId actionId, Action::State state) const {
    switch (actionId) {
    case ActionId::ACTION_FORWARD:
        LOGINF("FORWARD " << (state == Action::State::STATE_PRESSED ? "on" : "off"));
        break;
    case ActionId::ACTION_BACKWARD:
        LOGINF("BACKWARD " << (state == Action::State::STATE_PRESSED ? "on" : "off"));
        break;
    case ActionId::ACTION_STRAFE_LEFT:
        LOGINF("STRAFE_LEFT " << (state == Action::State::STATE_PRESSED ? "on" : "off"));
        break;
    case ActionId::ACTION_STRAFE_RIGHT:
        LOGINF("STRAFE_RIGHT " << (state == Action::State::STATE_PRESSED ? "on" : "off"));
        break;
    case ActionId::ACTION_JUMP:
        LOGINF("JUMP " << (state == Action::State::STATE_PRESSED ? "on" : "off"));
        break;
    case ActionId::ACTION_USE:
        LOGINF("USE " << (state == Action::State::STATE_PRESSED ? "on" : "off"));
        break;
    case ActionId::ACTION_QUIT:
        m_game->quit();
        break;
    default:
        break;
    }
}

} /* namespace input */
} /* namespace ymine */
