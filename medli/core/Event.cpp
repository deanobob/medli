/*
 * Event.cpp
 *
 *  Created on: 22 Aug 2014
 *      Author: deano
 */

#include "Event.h"

Event::Event(unsigned int messageId)
{
  this->messageId_ = messageId;
}

Event::~Event()
{

}

unsigned int Event::getMessageId() const
{
  return this->messageId_;
}
