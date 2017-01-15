/*
 * Scratchpad.h
 *
 *  Created on: 29 Dec 2014
 *      Author: Dean Harris
 */

#ifndef SCRATCHPAD_H_
#define SCRATCHPAD_H_

#include <string>
#include <list>
#include <map>

class INote;

class ScratchPad
{
  public:
    ScratchPad();
    virtual ~ScratchPad();

    void setNote(const std::string& varId, INote* pNote);
    INote* getNote(const std::string& varId);

  private:
    std::map<std::string, INote*> noteMap_;
};

#endif /* SCRATCHPAD_H_ */
