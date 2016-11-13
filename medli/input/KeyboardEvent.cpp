/*
 * KeyboardEvent.cpp
 *
 *  Created on: 9 Sep 2014
 *      Author: deano
 */

#include "KeyboardEvent.h"

KeyboardEvent::KeyboardEvent(unsigned int messageId,
                             unsigned int keycode,
                             bool pressed) :
    Event(messageId)
{
  this->keycode_ = keycode;
  this->pressed_ = pressed;
}

KeyboardEvent::~KeyboardEvent()
{

}

unsigned int KeyboardEvent::getKeycode()
{
  return this->keycode_;
}

bool KeyboardEvent::isPressed()
{
  return this->pressed_;
}
