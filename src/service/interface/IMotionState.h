/* File:       IMotionState.h
 * Project:    ymine
 * Created on: Nov 12, 2014 5:39:55 PM
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

#ifndef SRC_SERVICE_INTERFACE_IMOTIONSTATE_H_
#define SRC_SERVICE_INTERFACE_IMOTIONSTATE_H_

namespace ymine {
namespace service {
namespace interface {

struct IMotionState {
    virtual ~IMotionState() {}

    virtual void setForward(bool forward) = 0;
    virtual bool getForward() const = 0;

    virtual void setBackward(bool backward) = 0;
    virtual bool getBackward() const = 0;

    virtual void setLeft(bool left) = 0;
    virtual bool getLeft() const = 0;

    virtual void setRight(bool right) = 0;
    virtual bool getRight() const = 0;

    virtual void setJump(bool jump) = 0;
    virtual bool getJump() const = 0;

    virtual void setUse(bool use) = 0;
    virtual bool getUse() const = 0;

    virtual void setPitch(float pitch) = 0;
    virtual float getPitch() const = 0;

    virtual void setYaw(float yaw) = 0;
    virtual float getYaw()const = 0;
};

} /* namespace interface */
} /* namespace service */
} /* namespace ymine */

#endif /* SRC_SERVICE_INTERFACE_IMOTIONSTATE_H_ */
