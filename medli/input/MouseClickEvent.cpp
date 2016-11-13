/*
 * MouseClickEvent.cpp
 *
 *  Created on: 22 Aug 2014
 *      Author: deano
 */

#include "MouseClickEvent.h"

MouseClickEvent::MouseClickEvent(unsigned int messageId,
                                 MouseButton button,
                                 int positionX,
                                 int positionY,
                                 bool pressed) :
  Event(messageId)
{
  this->button_ = button;
  this->positionX_ = positionX;
  this->positionY_ = positionY;
  this->pressed_ = pressed;
}

MouseClickEvent::~MouseClickEvent()
{

}

MouseButton MouseClickEvent::getButton() const
{
  return this->button_;
}

int MouseClickEvent::getPositionX() const
{
  return this->positionX_;
}

int MouseClickEvent::getPositionY() const
{
  return this->positionY_;
}

bool MouseClickEvent::isPressed() const
{
  return this->pressed_;
}
