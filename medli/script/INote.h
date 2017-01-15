/*
 * INote.h
 *
 *  Created on: 29 Dec 2014
 *      Author: Dean Harris
 */

#ifndef INOTE_H_
#define INOTE_H_

#include "NoteType.h"

class INote
{
  public:
    virtual ~INote()
    {

    }

    virtual NoteType getTypeId() const = 0;
};

#endif /* INOTE_H_ */
