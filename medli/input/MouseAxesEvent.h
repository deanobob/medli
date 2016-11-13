/*
 * MouseAxesEvent.h
 *
 *  Created on: 27 Aug 2014
 *      Author: deano
 */

#ifndef MOUSEAXESEVENT_H_
#define MOUSEAXESEVENT_H_

#include "../core/Event.h"

class MouseAxesEvent:
    public Event
{
  public:
    MouseAxesEvent(unsigned int messageId, int positionX, int positionY, int wheelX, int wheelY);
    virtual ~MouseAxesEvent();

    int getPositionX();
    int getPositionY();
    int getWheelX();
    int getWheelY();

  private:
    int positionX_;
    int positionY_;
    int wheelX_;
    int wheelY_;
};

#endif /* MOUSEAXESEVENT_H_ */
