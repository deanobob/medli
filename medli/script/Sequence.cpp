/*
 * Sequence.cpp
 *
 *  Created on: 30 Dec 2014
 *      Author: Dean Harris
 */

#include <string>
#include "Sequence.h"

Sequence::Sequence()
{
  this->pCurrentRoutine_ = nullptr;
}

Sequence::~Sequence()
{
  for (auto routine : this->routineList_)
  {
    delete routine;
  }
  this->routineQueue_.clear();
  this->routineList_.clear();
}

void Sequence::start(ScratchPad* pScratchPad)
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

void Sequence::act(ScratchPad* pScratchPad)
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
    this->fail();
  }
  else
  {
    // if this is the last routine and is not running or failure, then sequence should succeed
    if (this->routineQueue_.empty())
    {
      this->succeed();
    }
    else
    {
      this->pCurrentRoutine_ = this->routineQueue_.front();
      this->routineQueue_.pop_front();

      this->pCurrentRoutine_->start(pScratchPad);
    }
  }
}

void Sequence::addRoutine(Routine* pRoutine)
{
  this->routineList_.push_back(pRoutine);
}
