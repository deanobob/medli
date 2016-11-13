/*
 * EntityCollection.h
 *
 *  Created on: 31 Oct 2016
 *      Author: deano
 */

#ifndef CORE_ENTITYCOLLECTION_H_
#define CORE_ENTITYCOLLECTION_H_

#include <list>
#include <map>

class Entity;
class EntityListener;

class EntityManager
{
  public:
    EntityManager();
    virtual ~EntityManager();

    void put(Entity* pEntity);
    Entity* getEntity(unsigned int entityId) const;
    std::list<Entity*> getAll(const unsigned int componentMask) const;

    void registerListener(EntityListener* pListener);
    void deregisterListener(EntityListener* pListener);

  private:
    std::map<unsigned int, Entity*> entityMap_;
    std::map<const std::string, Entity*> entityTagMap_;
    std::map<unsigned int, std::list<Entity*> > componentMaskMap_;
    std::map<unsigned int, std::list<EntityListener*> > listenerMap_;

    void merge(Entity* pEntity);
    std::list<Entity*> findEntities(unsigned int componentMask) const;
};

#endif /* CORE_ENTITYCOLLECTION_H_ */
