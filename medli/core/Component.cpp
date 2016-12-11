/*
 * Component.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: deano
 */

#include "Component.h"

Component::Component(const unsigned int id) :
    id(id)
{
  this->pEntity_ = nullptr;
}

Component::~Component()
{

}

void Component::setEntity(Entity* pEntity)
{
  this->pEntity_ = pEntity;
}

Entity* Component::getEntity() const
{
  return this->pEntity_;
}

Transform& Component::transform()
{
  return this->pEntity_->transform;
}

void Component::handleMessage(const Message* pMessage)
{
  // do nothing
}
