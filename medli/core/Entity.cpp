/*
 * Entity.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: deano
 */

#include <assert.h>
#include "Component.h"
#include "Entity.h"

unsigned int Entity::nextId_ = 1;

Entity::Entity(const std::string& tag) :
    id(Entity::nextId_++), tag(tag)
{
  this->componentMask_ = 0;
}

Entity::~Entity()
{

}

void Entity::addComponent(Component* pComponent)
{
  assert (this->componentMap_.find(pComponent->id) == this->componentMap_.end());

  this->componentMask_ |= pComponent->id;
  this->componentMap_[pComponent->id] = pComponent;

  pComponent->setEntity(this);
}

Component* Entity::getComponent(unsigned int componentId)
{
  return this->componentMap_[componentId];
}

const unsigned int Entity::getComponentMask() const
{
  return this->componentMask_;
}

void Entity::sendMessage(const Message* pMessage)
{
  for (std::pair<unsigned int, Component*> c : this->componentMap_)
  {
    c.second->handleMessage(pMessage);
  }
}
