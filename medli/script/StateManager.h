/*
 * StateManager.h
 *
 *  Created on: 11 Feb 2015
 *      Author: Dean Harris
 */

#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_

#include <list>
#include <map>
#include "../core/GameTime.h"

class BaseState;
class EntityManager;

class StateManager
{
  public:
    StateManager();
    virtual ~StateManager();

    void setState(BaseState* pState);
    unsigned int getState() const;
    void handleAction(unsigned int actionId, bool state);
    void update(const GameTime& gameTime);

    bool isActive(unsigned int action);

  private:
    std::list<BaseState*> stateStack_;
    std::map<unsigned int, bool> actionState_;
};

#endif /* STATEMANAGER_H_ */
