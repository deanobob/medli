/*
 * Component.h
 *
 *  Created on: 1 Nov 2016
 *      Author: deano
 */

#ifndef MEDLI_CORE_COMPONENT_H_
#define MEDLI_CORE_COMPONENT_H_

#include "Entity.h"
#include "Message.h"
#include "Transform.h"

class Component
{
  public:
    const unsigned int id;

    Component(const unsigned int id);
    virtual ~Component();

    void setEntity(Entity* pEntity);
    Entity* getEntity() const;
    Transform& transform();

    virtual void handleMessage(const Message* pMessage);

  private:
    Entity* pEntity_;
};

#endif /* MEDLI_CORE_COMPONENT_H_ */
