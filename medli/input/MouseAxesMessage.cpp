/*
 * MouseAxesMessage.cpp
 *
 *  Created on: 27 Aug 2014
 *      Author: deano
 */

#include "MouseAxesMessage.h"

MouseAxesMessage::MouseAxesMessage(const std::string& messageId,
                                   int positionX,
                                   int positionY,
                                   int wheelX,
                                   int wheelY) :
  Message(messageId)
{
  this->positionX_ = positionX;
  this->positionY_ = positionY;
  this->wheelX_ = wheelX;
  this->wheelY_ = wheelY;
}

MouseAxesMessage::~MouseAxesMessage()
{

}

int MouseAxesMessage::getPositionX()
{
  return this->positionX_;
}

int MouseAxesMessage::getPositionY()
{
  return this->positionY_;
}

int MouseAxesMessage::getWheelX()
{
  return this->wheelX_;
}

int MouseAxesMessage::getWheelY()
{
  return this->wheelY_;
}
