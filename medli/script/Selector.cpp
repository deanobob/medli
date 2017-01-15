/*
 * Selector.cpp
 *
 *  Created on: 30 Dec 2014
 *      Author: Dean Harris
 */

#include <stdlib.h>
#include "Selector.h"

Selector::Selector() :
  Routine()
{
  this->pCurrentRoutine_ = nullptr;
}

Selector::~Selector()
{
  for (auto routine : this->routineList_)
  {
    delete routine;
  }

  this->routineQueue_.clear();
  this->routineList_.clear();
}

void Selector::start(ScratchPad* pScratchPad)
{
  Routine::start(pScratchPad);

  this->routineQueue_.clear();
  this->routineQueue_.insert(this->routineQueue_.begin(),
                             this->routineList_.begin(),
                             this->routineList_.end());

  if (!this->routineQueue_.empty())
  {
    this->pCurrentRoutine_ = this->routineQueue_.front();
    this->routineQueue_.pop_front();

    this->pCurrentRoutine_->start(pScratchPad);
  }
  else
  {
    this->pCurrentRoutine_ = nullptr;
  }
}

void Selector::act(ScratchPad* pScratchPad)
{
  if (this->pCurrentRoutine_ == nullptr)
  {
    this->fail();
    return;
  }

  if (this->pCurrentRoutine_->isRunning())
  {
    this->pCurrentRoutine_->act(pScratchPad);
  }
  else if (this->pCurrentRoutine_->isFailure())
  {
    if (this->routineQueue_.empty())
    {
      this->fail();
    }
    else
    {
      this->pCurrentRoutine_ = this->routineQueue_.front();
      this->routineQueue_.pop_front();

      this->pCurrentRoutine_->start(pScratchPad);
    }
  }
  else
  {
    this->succeed();
  }
}

void Selector::addRoutine(Routine* pRoutine)
{
  this->routineList_.push_back(pRoutine);
}
