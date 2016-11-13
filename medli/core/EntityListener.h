/*
 * EntityListener.h
 *
 *  Created on: 1 Nov 2016
 *      Author: deano
 */

#ifndef MEDLI_CORE_ENTITYLISTENER_H_
#define MEDLI_CORE_ENTITYLISTENER_H_

#include <list>

class Entity;
class EntityManager;

class EntityListener
{
  public:
    const unsigned int componentMask;

    EntityListener(const unsigned int componentMask);
    virtual ~EntityListener();

    void setEntityManager(EntityManager* pEntityManager);
    void entityListHasChanged();
    Entity* getEntity(const unsigned int id) const;

  protected:
    bool entityListHasChanged_;
    std::list<Entity*> entityList_;

    void refreshEntityList();

  private:
    EntityManager* pEntityManager_;
};

#endif /* MEDLI_CORE_ENTITYLISTENER_H_ */
