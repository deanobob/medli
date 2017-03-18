/*
 * Broadcaster.h
 *
 *  Created on: 8 Aug 2014
 *      Author: deano
 */

#ifndef BROADCASTER_H_
#define BROADCASTER_H_

#include <stdlib.h>
#include <list>
#include <map>

class IBroadcastListener;
class Message;

class Broadcaster
{
  public:
    Broadcaster();
    virtual ~Broadcaster();

    void listenFor(const std::string messageId, IBroadcastListener* pListener);
    void stopListeningFor(const std::string messageId, IBroadcastListener* pListener);
    void send(Message* pMessage);

  private:
    std::map<const std::string, std::list<IBroadcastListener*> > listenerMap_;
};

#endif /* BROADCASTER_H_ */
