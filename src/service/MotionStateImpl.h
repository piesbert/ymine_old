/* File:       MotionStateImpl.h
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

#ifndef SRC_SERVICE_MOTIONSTATEIMPL_H_
#define SRC_SERVICE_MOTIONSTATEIMPL_H_

#include "interface/IMotionState.h"

namespace ymine {
namespace service {

class MotionStateImpl: public interface::IMotionState {
public:
    MotionStateImpl();
    virtual ~MotionStateImpl();

    void setForward(bool forward);
    bool getForward() const;

    void setBackward(bool backward);
    bool getBackward() const;

    void setLeft(bool left);
    bool getLeft() const;

    void setRight(bool right);
    bool getRight() const;

    void setJumping(bool jumping);
    bool getJumping() const;

    void setPitch(float pitch);
    float getPitch() const;

    void setYaw(float yaw);
    float getYaw() const;

private:
    bool m_forward;
    bool m_backward;
    bool m_left;
    bool m_right;
    bool m_jumping;

    float m_pitch;
    float m_yaw;
};

} /* namespace service */
} /* namespace ymine */

#endif /* SRC_SERVICE_MOTIONSTATEIMPL_H_ */
