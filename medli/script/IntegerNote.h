/*
 * IntegerNote.h
 *
 *  Created on: 29 Dec 2014
 *      Author: Dean Harris
 */

#ifndef INTEGERNOTE_H_
#define INTEGERNOTE_H_

#include "INote.h"

class IntegerNote:
    public INote
{
  public:
    IntegerNote(int value);
    virtual ~IntegerNote();

    NoteType getTypeId() const;
    int getInteger();

  private:
    int value_;
};

#endif /* INTEGERNOTE_H_ */
