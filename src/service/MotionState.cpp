/* File:       MotionState.cpp
 * Project:    ymine
 * Created on: Nov 12, 2014 6:03:36 PM
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

#include "MotionState.h"

namespace ymine {
namespace service {

MotionState::MotionState() {
}

MotionState::~MotionState() {
}

void MotionState::setForward(bool forward) {
    m_impl->setForward(forward);
}

bool MotionState::getForward() const {
    return m_impl->getForward();
}

void MotionState::setBackward(bool backward) {
    m_impl->setBackward(backward);
}

bool MotionState::getBackward() const {
    return m_impl->getBackward();
}

void MotionState::setLeft(bool left) {
    m_impl->setLeft(left);
}

bool MotionState::getLeft() const {
    return m_impl->getLeft();
}

void MotionState::setRight(bool right) {
    m_impl->setRight(right);
}

bool MotionState::getRight() const {
    return m_impl->getRight();
}

void MotionState::setJump(bool jump) {
    m_impl->setJump(jump);
}

bool MotionState::getJump() const {
    return m_impl->getJump();
}

void MotionState::setUse(bool use) {
    m_impl->setUse(use);
}

bool MotionState::getUse() const {
    return m_impl->getUse();
}

void MotionState::setPitch(float pitch) {
    m_impl->setPitch(pitch);
}

float MotionState::getPitch() const {
    return m_impl->getPitch();
}

void MotionState::setYaw(float yaw) {
   m_impl->setYaw(yaw);
}

float MotionState::getYaw() const {
    return m_impl->getYaw();
}

} /* namespace service */
} /* namespace ymine */
