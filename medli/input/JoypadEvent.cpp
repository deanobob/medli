/*
 * JoypadEvent.cpp
 *
 *  Created on: 10 Sep 2014
 *      Author: deano
 */

#include "JoypadEvent.h"

JoypadEvent::JoypadEvent(unsigned int messageId,
                         unsigned int buttonId,
                         bool pressed) :
    Event(messageId)
{
  this->buttonId_ = buttonId;
  this->pressed_ = pressed;
}

JoypadEvent::~JoypadEvent()
{

}

unsigned int JoypadEvent::getButton()
{
  return this->buttonId_;
}

bool JoypadEvent::isPressed()
{
  return this->pressed_;
}
