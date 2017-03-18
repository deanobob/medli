/*
 * KeyboardMessage.cpp
 *
 *  Created on: 9 Sep 2014
 *      Author: deano
 */

#include "KeyboardMessage.h"

KeyboardMessage::KeyboardMessage(const std::string& messageId,
                                 unsigned int keycode,
                                 bool pressed) :
    Message(messageId)
{
  this->keycode_ = keycode;
  this->pressed_ = pressed;
}

KeyboardMessage::~KeyboardMessage()
{

}

unsigned int KeyboardMessage::getKeycode()
{
  return this->keycode_;
}

bool KeyboardMessage::isPressed()
{
  return this->pressed_;
}
