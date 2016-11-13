/*
 * MouseClickEvent.h
 *
 *  Created on: 22 Aug 2014
 *      Author: deano
 */

#ifndef MOUSECLICKEVENT_H_
#define MOUSECLICKEVENT_H_

#include "../core/Event.h"
#include "InputEnums.h"

class MouseClickEvent:
    public Event
{
  public:
    MouseClickEvent(unsigned int messageId,
                    MouseButton button,
                    int positionX,
                    int positionY,
                    bool state);
    virtual ~MouseClickEvent();

    MouseButton getButton() const;
    int getPositionX() const;
    int getPositionY() const;
    bool isPressed() const;

  private:
    MouseButton button_;
    int positionX_;
    int positionY_;
    bool pressed_;
};

#endif /* MOUSECLICKEVENT_H_ */
