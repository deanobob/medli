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

class IComponent;

class Entity
{
  public:
    const unsigned int id;
    const std::string tag;

    Entity(const std::string& tag);
    virtual ~Entity();

    void addComponent(IComponent* pComponent);
    IComponent* getComponent(unsigned int componentId);
    const unsigned int getComponentMask() const;

  private:
    static unsigned int nextId_;

    unsigned int componentMask_;
    std::map<unsigned int, IComponent*> componentMap_;
};

#endif /* MEDLI_CORE_ENTITY_H_ */
