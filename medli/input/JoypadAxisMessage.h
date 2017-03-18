/*
 * JoypadAxisMessage.h
 *
 *  Created on: 10 Sep 2014
 *      Author: deano
 */

#ifndef JOYPADAXISMESSAGE_H_
#define JOYPADAXISMESSAGE_H_

#include "../core/Message.h"

class JoypadAxisMessage:
    public Message
{
  public:
    JoypadAxisMessage(const std::string& messageId,
                      unsigned int stick,
                      unsigned int axis,
                      float position);
    virtual ~JoypadAxisMessage();

    unsigned int getStick();
    unsigned int getAxis();
    float getPosition();

  private:
    unsigned int stick_;
    unsigned int axis_;
    float position_;
};

#endif /* JOYPADAXISMESSAGE_H_ */
