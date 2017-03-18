/*
 * Broadcaster.cpp
 *
 *  Created on: 8 Aug 2014
 *      Author: deano
 */

#include "Broadcaster.h"
#include "IBroadcastListener.h"
#include "Message.h"

Broadcaster::Broadcaster()
{

}

Broadcaster::~Broadcaster()
{

}

void Broadcaster::listenFor(const std::string messageId, IBroadcastListener* pListener)
{
  this->listenerMap_[messageId].push_back(pListener);
}

void Broadcaster::stopListeningFor(const std::string messageId, IBroadcastListener* pListener)
{
  this->listenerMap_[messageId].remove(pListener);
}

void Broadcaster::send(Message* pMessage)
{
  auto listenerList = this->listenerMap_[pMessage->messageId];

  for (auto listener : listenerList)
  {
    listener->onMessageBroadcast(pMessage);
  }
}
