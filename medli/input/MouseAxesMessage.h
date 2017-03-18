/*
 * MouseAxesMessage.h
 *
 *  Created on: 27 Aug 2014
 *      Author: deano
 */

#ifndef MOUSEAXESMESSAGE_H_
#define MOUSEAXESMESSAGE_H_

#include "../core/Message.h"

class MouseAxesMessage:
    public Message
{
  public:
    MouseAxesMessage(const std::string& messageId, int positionX, int positionY, int wheelX, int wheelY);
    virtual ~MouseAxesMessage();

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

#endif /* MOUSEAXESMESSAGE_H_ */
