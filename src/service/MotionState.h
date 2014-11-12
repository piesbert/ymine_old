/* File:       MotionState.h
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

#ifndef SRC_SERVICE_MOTIONSTATE_H_
#define SRC_SERVICE_MOTIONSTATE_H_

#include "service/ServiceTemplate.h"
#include "service/interface/IMotionState.h"

namespace ymine {
namespace service {

class MotionState: public service::ServiceTemplate<MotionState, service::interface::IMotionState> {
public:
    MotionState();
    virtual ~MotionState();

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
};

} /* namespace service */
} /* namespace ymine */

#endif /* SRC_SERVICE_MOTIONSTATE_H_ */
