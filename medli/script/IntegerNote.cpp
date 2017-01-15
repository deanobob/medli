/*
 * IntegerNote.cpp
 *
 *  Created on: 29 Dec 2014
 *      Author: Dean Harris
 */

#include "IntegerNote.h"

IntegerNote::IntegerNote(int value)
{
  this->value_ = value;
}

IntegerNote::~IntegerNote()
{

}

NoteType IntegerNote::getTypeId() const
{
  return NoteType::INTEGER;
}

int IntegerNote::getInteger()
{
  return this->value_;
}
