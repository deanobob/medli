/*
 * JoypadMessage.h
 *
 *  Created on: 10 Sep 2014
 *      Author: deano
 */

#ifndef JOYPADMESSAGE_H_
#define JOYPADMESSAGE_H_

#include "../core/Message.h"

class JoypadMessage:
    public Message
{
  public:
    JoypadMessage(const std::string& messageId,
                  unsigned int buttonId,
                  bool pressed);
    virtual ~JoypadMessage();

    unsigned int getButton();
    bool isPressed();

  private:
    unsigned int buttonId_;
    bool pressed_;
};

#endif /* JOYPADMESSAGE_H_ */
