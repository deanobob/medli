/*
 * BaseState.cpp
 *
 *  Created on: 11 Feb 2015
 *      Author: Dean Harris
 */

#include <assert.h>
#include <stdlib.h>
#include "BaseState.h"
#include "StateManager.h"

BaseState::BaseState()
{
  this->pStateManager_ = nullptr;
  this->finished_ = false;
}

BaseState::~BaseState()
{

}

void BaseState::finished()
{
  this->finished_ = true;
}

bool BaseState::isFinished() const
{
  return this->finished_;
}

void BaseState::setStateManager(StateManager* pStateManager)
{
  this->pStateManager_ = pStateManager;
}
