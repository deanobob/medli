/*
 * JoypadMessage.cpp
 *
 *  Created on: 10 Sep 2014
 *      Author: deano
 */

#include "JoypadMessage.h"

JoypadMessage::JoypadMessage(const std::string& messageId,
                             unsigned int buttonId,
                             bool pressed) :
    Message(messageId)
{
  this->buttonId_ = buttonId;
  this->pressed_ = pressed;
}

JoypadMessage::~JoypadMessage()
{

}

unsigned int JoypadMessage::getButton()
{
  return this->buttonId_;
}

bool JoypadMessage::isPressed()
{
  return this->pressed_;
}
