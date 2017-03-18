/*
 * KeyboardMessage.h
 *
 *  Created on: 9 Sep 2014
 *      Author: deano
 */

#ifndef KEYBOARDMESSAGE_H_
#define KEYBOARDMESSAGE_H_

#include "../core/Message.h"

class KeyboardMessage:
    public Message
{
  public:
    KeyboardMessage(const std::string& messageId,
                    unsigned int keycode,
                    bool pressed);
    virtual ~KeyboardMessage();

    unsigned int getKeycode();
    bool isPressed();

  private:
    unsigned int keycode_;
    bool pressed_;
};

#endif /* KEYBOARDMESSAGE_H_ */
