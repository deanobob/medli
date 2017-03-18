/*
 * Message.h
 *
 *  Created on: 22 Aug 2014
 *      Author: deano
 */

#ifndef CORE_MESSAGE_H_
#define CORE_MESSAGE_H_

#include <string>

class Message
{
  public:
    const std::string messageId;

    Message(const std::string& messageId);
    virtual ~Message();
};

#endif /* CORE_MESSAGE_H_ */
