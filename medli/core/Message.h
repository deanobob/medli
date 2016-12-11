/*
 * Message.h
 *
 *  Created on: 22 Aug 2014
 *      Author: deano
 */

#ifndef CORE_MESSAGE_H_
#define CORE_MESSAGE_H_

class Message
{
  public:
    const unsigned int messageId;

    Message(unsigned int messageId);
    virtual ~Message();
};

#endif /* CORE_MESSAGE_H_ */
