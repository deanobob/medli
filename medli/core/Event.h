/*
 * Event.h
 *
 *  Created on: 22 Aug 2014
 *      Author: deano
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <stdlib.h>

class Event
{
  public:
    Event(unsigned int messageId);
    virtual ~Event();

    unsigned int getMessageId() const;

  private:
    unsigned int messageId_;
};

#endif /* EVENT_H_ */
