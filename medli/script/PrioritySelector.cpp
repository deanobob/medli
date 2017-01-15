/*
 * PrioritySelector.cpp
 *
 *  Created on: 30 Dec 2014
 *      Author: Dean Harris
 */

#include <stdlib.h>
#include "PrioritySelector.h"

PrioritySelector::PrioritySelector() :
  Routine()
{

}

PrioritySelector::~PrioritySelector()
{
  for (auto routine : this->routineList_)
  {
    delete routine;
  }
  this->routineList_.clear();
}

void PrioritySelector::start(ScratchPad* pScratchPad)
{
  Routine::start(pScratchPad);
}

void PrioritySelector::act(ScratchPad* pScratchPad)
{
  for (auto routine : routineList_)
  {
    if (!routine->isRunning())
    {
      routine->start(pScratchPad);
    }

    routine->act(pScratchPad);

    if (routine->isRunning())
    {
      break;
    }
    else if (routine->isSuccess())
    {
      this->isSuccess();
    }
  }
}

void PrioritySelector::addRoutine(Routine* pRoutine)
{
  this->routineList_.push_back(pRoutine);
}
