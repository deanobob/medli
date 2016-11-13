/*
 * Broadcaster.cpp
 *
 *  Created on: 8 Aug 2014
 *      Author: deano
 */

#include "Broadcaster.h"
#include "Event.h"
#include "IBroadcastListener.h"

Broadcaster::Broadcaster()
{

}

Broadcaster::~Broadcaster()
{

}

void Broadcaster::listenFor(unsigned int messageId, IBroadcastListener* pListener)
{
  this->listenerMap_[messageId].push_back(pListener);
}

void Broadcaster::stopListeningFor(unsigned int messageId, IBroadcastListener* pListener)
{
  this->listenerMap_[messageId].remove(pListener);
}

void Broadcaster::send(Event* pEvent)
{
  auto listenerList = this->listenerMap_[pEvent->getMessageId()];

  for (auto listener : listenerList)
  {
    listener->onMessageBroadcast(pEvent);
  }
}
