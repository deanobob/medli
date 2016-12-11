/*
 * Entity.h
 *
 *  Created on: 1 Nov 2016
 *      Author: deano
 */

#ifndef MEDLI_CORE_ENTITY_H_
#define MEDLI_CORE_ENTITY_H_

#include <map>
#include <string>
#include "Transform.h"
#include "Message.h"

class Component;

class Entity
{
  public:
    const unsigned int id;
    const std::string tag;
    Transform transform;

    Entity(const std::string& tag);
    virtual ~Entity();

    void addComponent(Component* pComponent);
    Component* getComponent(unsigned int componentId);
    const unsigned int getComponentMask() const;
    void sendMessage(const Message* pMessage);

  private:
    static unsigned int nextId_;

    unsigned int componentMask_;
    std::map<unsigned int, Component*> componentMap_;
};

#endif /* MEDLI_CORE_ENTITY_H_ */
