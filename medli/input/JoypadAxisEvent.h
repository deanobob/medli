/*
 * JoypadAxisEvent.h
 *
 *  Created on: 10 Sep 2014
 *      Author: deano
 */

#ifndef JOYPADAXISEVENT_H_
#define JOYPADAXISEVENT_H_

#include "../core/Event.h"

class JoypadAxisEvent:
    public Event
{
  public:
    JoypadAxisEvent(unsigned int messageId,
                    unsigned int stick,
                    unsigned int axis,
                    float position);
    virtual ~JoypadAxisEvent();

    unsigned int getStick();
    unsigned int getAxis();
    float getPosition();

  private:
    unsigned int stick_;
    unsigned int axis_;
    float position_;
};

#endif /* JOYPADAXISEVENT_H_ */
