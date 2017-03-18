/*
 * JoypadAxisMessage.cpp
 *
 *  Created on: 10 Sep 2014
 *      Author: deano
 */

#include "JoypadAxisMessage.h"

JoypadAxisMessage::JoypadAxisMessage(const std::string& messageId,
                                     unsigned int stick,
                                     unsigned int axis,
                                     float position) :
  Message(messageId)
{
  this->stick_ = stick;
  this->axis_ = axis;
  this->position_ = position;
}

JoypadAxisMessage::~JoypadAxisMessage()
{

}

unsigned int JoypadAxisMessage::getStick()
{
  return this->stick_;
}

unsigned int JoypadAxisMessage::getAxis()
{
  return this->axis_;
}

float JoypadAxisMessage::getPosition()
{
  return this->position_;
}
