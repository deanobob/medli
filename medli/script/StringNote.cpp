/*
 * StringNote.cpp
 *
 *  Created on: 29 Dec 2014
 *      Author: Dean Harris
 */

#include "StringNote.h"

StringNote::StringNote(const std::string& value) :
    value(value)
{

}

StringNote::~StringNote()
{

}

NoteType StringNote::getTypeId() const
{
  return NoteType::STRING;
}
