/*
 * EntityManager.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: deano
 */

#include <assert.h>
#include "../log/Logger.h"
#include "Entity.h"
#include "EntityListener.h"
#include "EntityManager.h"

static const std::list<Entity*> EMPTY_ENTITY_LIST;

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{
  for (auto it = this->entityMap_.begin(); it != this->entityMap_.end(); ++it)
  {
    delete (*it).second;
  }
}

void EntityManager::put(Entity* pEntity)
{
#ifdef DEBUG
  assert (pEntity != nullptr &&
      this->entityMap_.find(pEntity->id) == this->entityMap_.end());
#endif

  this->entityMap_[pEntity->id] = pEntity;

  if (!pEntity->tag.empty())
  {
    //TODO: handle potential clashing of tag names.
    this->entityTagMap_[pEntity->tag] = pEntity;
  }

  this->merge(pEntity);
}

Entity* EntityManager::getEntity(unsigned int entityId) const
{
  auto it = this->entityMap_.find(entityId);
  if (it != this->entityMap_.end())
  {
    return (*it).second;
  }

  return nullptr;
}

std::list<Entity*> EntityManager::getAll(const unsigned int componentMask) const
{
  auto it = this->componentMaskMap_.find(componentMask);
  if (it != this->componentMaskMap_.end())
  {
    return (*it).second;
  }

  return EMPTY_ENTITY_LIST;
}

void EntityManager::registerListener(EntityListener* pListener)
{
  this->listenerMap_[pListener->componentMask].push_back(pListener);
  if (this->componentMaskMap_.find(pListener->componentMask) == this->componentMaskMap_.end())
  {
    this->componentMaskMap_[pListener->componentMask] = this->findEntities(pListener->componentMask);
  }
}

void EntityManager::deregisterListener(EntityListener* pListener)
{
  auto it = this->listenerMap_.find(pListener->componentMask);
  if (it != this->listenerMap_.end())
  {
    std::list<EntityListener*> listenerList = (*it).second;
    listenerList.remove(pListener);
    if (listenerList.empty())
    {
      this->listenerMap_.erase(it);
    }
  }
}

void EntityManager::merge(Entity* pEntity)
{
  unsigned int componentMask = pEntity->getComponentMask();
  for (auto i = this->componentMaskMap_.begin(); i != this->componentMaskMap_.end(); ++i)
  {
    if ((componentMask & (*i).first) == (*i).first)
    {
      (*i).second.push_back(pEntity);

      //TODO: improve this - if many new entities are added at once, set dirty after all entities added.
      std::list<EntityListener*> listenerList = this->listenerMap_[(*i).first];
      for (auto j : listenerList)
      {
        j->entityListHasChanged();
      }
    }
  }
}

std::list<Entity*> EntityManager::findEntities(unsigned int componentMask) const
{
  std::list<Entity*> entityList;
  for (auto it : this->entityMap_)
  {
    Entity* pEntity = it.second;
    if ((pEntity->getComponentMask() & componentMask) == componentMask)
    {
      entityList.push_back(pEntity);
    }
  }
  return entityList;
}
