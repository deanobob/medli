/*
 * BehaviourTree.cpp
 *
 *  Created on: 23 Dec 2014
 *      Author: Dean Harris
 */

#include "BehaviourTree.h"
#include "IntegerNote.h"
#include "Routine.h"
#include "ScratchPad.h"

BehaviourTree::BehaviourTree(Routine* pRoot)
{
  this->pRoot_ = pRoot;
  this->pScratchPad_ = new ScratchPad();
}

BehaviourTree::~BehaviourTree()
{
  delete this->pScratchPad_;
}

void BehaviourTree::update()
{
  if (!this->pRoot_->isRunning())
  {
    this->pRoot_->start(this->pScratchPad_);
  }

  if (this->pRoot_->isRunning())
  {
    this->pRoot_->act(this->pScratchPad_);
  }
}

bool BehaviourTree::isFinished() const
{
  if (this->pRoot_ != nullptr)
  {
    return !this->pRoot_->isRunning();
  }

  return true;
}
