/*
 * MouseClickMessage.cpp
 *
 *  Created on: 22 Aug 2014
 *      Author: deano
 */

#include "MouseClickMessage.h"

MouseClickMessage::MouseClickMessage(const std::string& messageId,
                                     MouseButton button,
                                     int positionX,
                                     int positionY,
                                     bool pressed) :
    Message(messageId)
{
  this->button_ = button;
  this->positionX_ = positionX;
  this->positionY_ = positionY;
  this->pressed_ = pressed;
}

MouseClickMessage::~MouseClickMessage()
{

}

MouseButton MouseClickMessage::getButton() const
{
  return this->button_;
}

int MouseClickMessage::getPositionX() const
{
  return this->positionX_;
}

int MouseClickMessage::getPositionY() const
{
  return this->positionY_;
}

bool MouseClickMessage::isPressed() const
{
  return this->pressed_;
}
