/*
 * StateManager.cpp
 *
 *  Created on: 11 Feb 2015
 *      Author: Dean Harris
 */

#include <assert.h>
#include <stdlib.h>
#include "BaseState.h"
#include "StateManager.h"

StateManager::StateManager()
{

}

StateManager::~StateManager()
{

}

void StateManager::setState(BaseState* pState)
{
  assert(pState != nullptr);

  this->stateStack_.push_back(pState);
  pState->setStateManager(this);
  pState->enter();
}

unsigned int StateManager::getState() const
{
  if (!this->stateStack_.empty())
  {
    BaseState* pState = this->stateStack_.back();

    if (pState != nullptr)
    {
      return pState->getStateId();
    }
  }

  return 0;
}

void StateManager::handleAction(unsigned int actionId, bool isActive)
{
  this->actionState_[actionId] = isActive;

  if (!this->stateStack_.empty())
  {
    BaseState* pState = this->stateStack_.back();

    if (pState != nullptr)
    {
      BaseState* pNewState = pState->handleAction(actionId, isActive);

      if (pState->isFinished())
      {
        pState->exit();
        delete pState;

        this->stateStack_.pop_back();
      }

      if (pNewState != nullptr)
      {
        this->stateStack_.push_back(pNewState);
        pNewState->setStateManager(this);

        pNewState->enter();
      }
      else if (!this->stateStack_.empty())
      {
        this->stateStack_.back()->enter();
      }
    }
  }
}

void StateManager::update(const GameTime& gameTime)
{
  if (!this->stateStack_.empty())
  {
    BaseState* pState = this->stateStack_.back();

    if (pState != nullptr)
    {
      pState->update(gameTime);

      if (pState->isFinished())
      {
        pState->exit();
        delete pState;

        this->stateStack_.pop_back();

        if (!this->stateStack_.empty())
        {
          this->stateStack_.back()->enter();
        }
      }
    }
  }
}

bool StateManager::isActive(unsigned int action)
{
  std::map<unsigned int, bool>::const_iterator it = this->actionState_.find(action);
  if (it != this->actionState_.end())
  {
    return (*it).second;
  }

  return false;
}
