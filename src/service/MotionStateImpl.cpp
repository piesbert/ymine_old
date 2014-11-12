/* File:       MotionStateImpl.cpp
 * Project:    ymine
 * Created on: Nov 12, 2014 5:46:17 PM
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

#include "MotionStateImpl.h"

namespace ymine {
namespace service {

MotionStateImpl::MotionStateImpl()
: m_forward(false),
  m_backward(false),
  m_left(false),
  m_right(false),
  m_jump(false),
  m_use(false),
  m_pitch(0.0f),
  m_yaw(0.0f) {
}

MotionStateImpl::~MotionStateImpl() {
}

void MotionStateImpl::setForward(bool forward) {
    m_forward = forward;
}

bool MotionStateImpl::getForward() const {
    return m_forward;
}

void MotionStateImpl::setBackward(bool backward) {
    m_backward = backward;
}

bool MotionStateImpl::getBackward() const {
    return m_backward;
}

void MotionStateImpl::setLeft(bool left) {
    m_left = left;
}

bool MotionStateImpl::getLeft() const {
    return m_left;
}

void MotionStateImpl::setRight(bool right) {
    m_right = right;
}

bool MotionStateImpl::getRight() const {
    return m_right;
}

void MotionStateImpl::setJump(bool jump) {
    m_jump = jump;
}

bool MotionStateImpl::getJump() const {
    return m_jump;
}

void MotionStateImpl::setUse(bool use) {
    m_use = use;
}

bool MotionStateImpl::getUse() const {
    return m_use;
}

void MotionStateImpl::setPitch(float pitch) {
    m_pitch = pitch;
}

float MotionStateImpl::getPitch() const {
    return m_pitch;
}

void MotionStateImpl::setYaw(float yaw) {
    m_yaw = yaw;
}

float MotionStateImpl::getYaw() const {
    return m_yaw;
}

} /* namespace service */
} /* namespace ymine */
