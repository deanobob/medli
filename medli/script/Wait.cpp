/*
 * Wait.cpp
 *
 *  Created on: 30 Dec 2014
 *      Author: Dean Harris
 */

#include "ScratchPad.h"
#include "Wait.h"

Wait::Wait(float duration) :
    Routine(), duration_(duration)
{
  this->elapsedTime_ = 0.0f;
}

Wait::~Wait()
{

}

void Wait::start(ScratchPad* pScratchPad)
{
  Routine::start(pScratchPad);

  this->elapsedTime_ = 0.0f;
}

void Wait::act(ScratchPad* pScratchPad)
{
  if (this->elapsedTime_ < this->duration_)
  {
    this->elapsedTime_ += 1.0 / 60.0;
  }
  else
  {
    this->succeed();
  }
}
