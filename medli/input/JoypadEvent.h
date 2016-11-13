/*
 * JoypadEvent.h
 *
 *  Created on: 10 Sep 2014
 *      Author: deano
 */

#ifndef JOYPADEVENT_H_
#define JOYPADEVENT_H_

#include "../core/Event.h"

class JoypadEvent:
    public Event
{
  public:
    JoypadEvent(unsigned int messageId,
                unsigned int buttonId,
                bool pressed);
    virtual ~JoypadEvent();

    unsigned int getButton();
    bool isPressed();

  private:
    unsigned int buttonId_;
    bool pressed_;
};

#endif /* JOYPADEVENT_H_ */
