/*
 * EntityListener.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: deano
 */

#include <assert.h>
#include "Entity.h"
#include "EntityListener.h"
#include "EntityManager.h"

EntityListener::EntityListener(const unsigned int componentMask) :
    componentMask(componentMask)
{
  this->pEntityManager_ = nullptr;
  this->entityListHasChanged_ = true;
}

EntityListener::~EntityListener()
{

}

void EntityListener::setEntityManager(EntityManager* pEntityManager)
{
  assert(this->pEntityManager_ == nullptr);

  this->pEntityManager_ = pEntityManager;
}

void EntityListener::refreshEntityList()
{
  this->entityList_ = this->pEntityManager_->getAll(this->componentMask);
  this->entityListHasChanged_ = false;

  this->onEntityListChanged();
}

void EntityListener::entityListHasChanged()
{
  this->entityListHasChanged_ = true;
}

Entity* EntityListener::getEntity(const unsigned int id) const
{
  return this->pEntityManager_->getEntity(id);
}

void EntityListener::onEntityListChanged()
{

}
