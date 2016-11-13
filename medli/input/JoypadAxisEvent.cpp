/*
 * JoypadAxisEvent.cpp
 *
 *  Created on: 10 Sep 2014
 *      Author: deano
 */

#include "JoypadAxisEvent.h"

JoypadAxisEvent::JoypadAxisEvent(unsigned int messageId,
                                 unsigned int stick,
                                 unsigned int axis,
                                 float position) :
  Event(messageId)
{
  this->stick_ = stick;
  this->axis_ = axis;
  this->position_ = position;
}

JoypadAxisEvent::~JoypadAxisEvent()
{

}

unsigned int JoypadAxisEvent::getStick()
{
  return this->stick_;
}

unsigned int JoypadAxisEvent::getAxis()
{
  return this->axis_;
}

float JoypadAxisEvent::getPosition()
{
  return this->position_;
}
