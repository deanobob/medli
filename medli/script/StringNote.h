/*
 * StringNote.h
 *
 *  Created on: 29 Dec 2014
 *      Author: Dean Harris
 */

#ifndef STRINGNOTE_H_
#define STRINGNOTE_H_

#include <string>
#include "INote.h"

class StringNote:
    public INote
{
  public:
    const std::string value;

    StringNote(const std::string& value);
    virtual ~StringNote();

    NoteType getTypeId() const;
};

#endif /* STRINGNOTE_H_ */
