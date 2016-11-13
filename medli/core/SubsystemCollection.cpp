/*
 * SubsystemQueue.cpp
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#include <stdlib.h>
#include "../log/Logger.h"
#include "Subsystem.h"
#include "SubsystemCollection.h"

SubsystemCollection::SubsystemCollection()
{

}

SubsystemCollection::~SubsystemCollection()
{
  for (auto it : this->subsystemList_)
  {
    delete it;
  }
}

void SubsystemCollection::add(Subsystem* pSubsystem)
{
  this->subsystemList_.push_back(pSubsystem);
  this->updateQueue_.push(pSubsystem);
  this->drawQueue_.push(pSubsystem);
}

std::vector<Subsystem*>::const_iterator SubsystemCollection::begin()
{
  return this->subsystemList_.begin();
}

std::vector<Subsystem*>::const_iterator SubsystemCollection::end()
{
  return this->subsystemList_.end();
}

const std::priority_queue<Subsystem, std::vector<Subsystem*>, UpdateComparator>&
    SubsystemCollection::getUpdateQueue() const
{
  return this->updateQueue_;
}

const std::priority_queue<Subsystem, std::vector<Subsystem*>, DrawComparator>&
    SubsystemCollection::getDrawQueue() const
{
  return this->drawQueue_;
}
