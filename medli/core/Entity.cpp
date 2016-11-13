/*
 * Entity.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: deano
 */

#include <assert.h>
#include "Entity.h"
#include "IComponent.h"

unsigned int Entity::nextId_ = 1;

Entity::Entity(const std::string& tag) :
    id(Entity::nextId_++), tag(tag)
{
  this->componentMask_ = 0;
}

Entity::~Entity()
{

}

void Entity::addComponent(IComponent* pComponent)
{
  assert (this->componentMap_.find(pComponent->id) == this->componentMap_.end());

  this->componentMask_ |= pComponent->id;
  this->componentMap_[pComponent->id] = pComponent;
}

IComponent* Entity::getComponent(unsigned int componentId)
{
  return this->componentMap_[componentId];
}

const unsigned int Entity::getComponentMask() const
{
  return this->componentMask_;
}
