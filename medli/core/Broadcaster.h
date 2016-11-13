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

class Event;
class IBroadcastListener;

class Broadcaster
{
  public:
    Broadcaster();
    virtual ~Broadcaster();

    void listenFor(unsigned int messageId, IBroadcastListener* pListener);
    void stopListeningFor(unsigned int messageId, IBroadcastListener* pListener);
    void send(Event* pEvent);

  private:
    std::map<unsigned int, std::list<IBroadcastListener*> > listenerMap_;
};

#endif /* BROADCASTER_H_ */
