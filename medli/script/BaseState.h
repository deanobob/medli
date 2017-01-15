/*
 * BaseState.h
 *
 *  Created on: 11 Feb 2015
 *      Author: Dean Harris
 */

#ifndef BASESTATE_H_
#define BASESTATE_H_

#include "../core/GameTime.h"

class EntityManager;
class StateManager;

class BaseState
{
  public:
    BaseState();
    virtual ~BaseState();

    virtual unsigned int getStateId() const = 0;

    virtual void enter() = 0;
    virtual BaseState* handleAction(unsigned int action,
                                    bool isActive) = 0;
    virtual void update(const GameTime& gameTime) = 0;
    virtual void exit() = 0;

    void finished();
    bool isFinished() const;

    void setStateManager(StateManager* pStateManager);

  protected:
    StateManager* pStateManager_;

  private:
    bool finished_;
};

#endif /* BASESTATE_H_ */
