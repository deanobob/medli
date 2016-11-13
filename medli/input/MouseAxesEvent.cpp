/*
 * MouseAxesEvent.cpp
 *
 *  Created on: 27 Aug 2014
 *      Author: deano
 */

#include "MouseAxesEvent.h"

MouseAxesEvent::MouseAxesEvent(unsigned int messageId,
                               int positionX,
                               int positionY,
                               int wheelX,
                               int wheelY) :
  Event(messageId)
{
  this->positionX_ = positionX;
  this->positionY_ = positionY;
  this->wheelX_ = wheelX;
  this->wheelY_ = wheelY;
}

MouseAxesEvent::~MouseAxesEvent()
{

}

int MouseAxesEvent::getPositionX()
{
  return this->positionX_;
}

int MouseAxesEvent::getPositionY()
{
  return this->positionY_;
}

int MouseAxesEvent::getWheelX()
{
  return this->wheelX_;
}

int MouseAxesEvent::getWheelY()
{
  return this->wheelY_;
}
