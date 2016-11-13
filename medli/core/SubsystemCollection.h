/*
 * SubsystemCollection.h
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#ifndef SUBSYSTEMCOLLECTION_H_
#define SUBSYSTEMCOLLECTION_H_

#include <map>
#include <queue>
#include "Subsystem.h"

struct UpdateComparator
{
    bool operator()(const Subsystem* lhs, const Subsystem* rhs) const
    {
      return rhs->getUpdatePriority() < lhs->getUpdatePriority();
    }
};

struct DrawComparator
{
    bool operator()(const Subsystem* lhs, const Subsystem* rhs) const
    {
      return rhs->getDrawPriority() < lhs->getDrawPriority();
    }
};

class SubsystemCollection
{
  public:
    SubsystemCollection();
    virtual ~SubsystemCollection();

    void add(Subsystem* pSubsystem);
    std::vector<Subsystem*>::const_iterator begin();
    std::vector<Subsystem*>::const_iterator end();

    const std::priority_queue<Subsystem, std::vector<Subsystem*>, UpdateComparator>&
      getUpdateQueue() const;
    const std::priority_queue<Subsystem, std::vector<Subsystem*>, DrawComparator>&
      getDrawQueue() const;

  private:
    std::vector<Subsystem*> subsystemList_;
    std::priority_queue<Subsystem, std::vector<Subsystem*>, UpdateComparator> updateQueue_;
    std::priority_queue<Subsystem, std::vector<Subsystem*>, DrawComparator> drawQueue_;
};

#endif /* SUBSYSTEMCOLLECTION_H_ */
