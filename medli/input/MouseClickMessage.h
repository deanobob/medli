/*
 * MouseClickMessage.h
 *
 *  Created on: 22 Aug 2014
 *      Author: deano
 */

#ifndef MOUSECLICKMESSAGE_H_
#define MOUSECLICKMESSAGE_H_

#include "../core/Message.h"
#include "InputEnums.h"

class MouseClickMessage:
    public Message
{
  public:
    MouseClickMessage(const std::string& messageId,
                      MouseButton button,
                      int positionX,
                      int positionY,
                      bool state);
    virtual ~MouseClickMessage();

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

#endif /* MOUSECLICKMESSAGE_H_ */
