/*
 * KeyboardEvent.h
 *
 *  Created on: 9 Sep 2014
 *      Author: deano
 */

#ifndef KEYBOARDEVENT_H_
#define KEYBOARDEVENT_H_

#include "../core/Event.h"

class KeyboardEvent:
    public Event
{
  public:
    KeyboardEvent(unsigned int messageId,
                  unsigned int keycode,
                  bool pressed);
    virtual ~KeyboardEvent();

    unsigned int getKeycode();
    bool isPressed();

  private:
    unsigned int keycode_;
    bool pressed_;
};

#endif /* KEYBOARDEVENT_H_ */
