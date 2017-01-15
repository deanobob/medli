/*
 * Scratchpad.cpp
 *
 *  Created on: 29 Dec 2014
 *      Author: Dean Harris
 */

#include <list>
#include <string>
#include "INote.h"
#include "ScratchPad.h"

ScratchPad::ScratchPad()
{

}

ScratchPad::~ScratchPad()
{

}

void ScratchPad::setNote(const std::string& noteId, INote* pNote)
{
  if (this->noteMap_.find(noteId) != this->noteMap_.end())
  {
    INote* pPreviousNote = this->noteMap_[noteId];
    if (pPreviousNote != nullptr)
    {
      delete pPreviousNote;
    }
  }

  this->noteMap_[noteId] = pNote;
}

INote* ScratchPad::getNote(const std::string& noteId)
{
  INote* pNote = nullptr;

  std::map<std::string, INote*>::iterator it = this->noteMap_.find(noteId);
  if (it != this->noteMap_.end())
  {
    pNote = (*it).second;
  }

  return pNote;
}
