/*
 * IBroadcastListener.h
 *
 *  Created on: 8 Aug 2014
 *      Author: deano
 */

#ifndef IBROADCASTLISTENER_H_
#define IBROADCASTLISTENER_H_

#include <stdlib.h>

class Event;

class IBroadcastListener
{
  public:
    virtual ~IBroadcastListener()
    {

    }

    virtual void onMessageBroadcast(Event* pEvent) = 0;
};

#endif /* BROADCASTLISTENER_H_ */
