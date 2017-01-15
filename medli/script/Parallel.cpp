/*
 * Parallel.cpp
 *
 *  Created on: 30 Dec 2014
 *      Author: Dean Harris
 */

#include "Parallel.h"
#include "ScratchPad.h"

Parallel::Parallel()
{

}

Parallel::~Parallel()
{
  for (auto routine : this->routineList_)
  {
    delete routine;
  }

  this->routineList_.clear();
}

void Parallel::start(ScratchPad* pScratchPad)
{
  Routine::start(pScratchPad);

  for (auto routine : this->routineList_)
  {
    routine->start(pScratchPad);
  }
}

void Parallel::act(ScratchPad* pScratchPad)
{
  bool isRunning = false;

  for (auto routine : this->routineList_)
  {
    if (!routine->isRunning())
    {
      if (routine->isFailure())
      {
        this->fail();
      }
    }
    else
    {
      this->act(pScratchPad);
      isRunning = true;
    }
  }

  if (!isRunning)
  {
    this->succeed();
  }
}

void Parallel::addRoutine(Routine* pRoutine)
{
  this->routineList_.push_back(pRoutine);
}
