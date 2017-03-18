/*
 * ComponentScene.h
 *
 *  Created on: 16 Jun 2014
 *      Author: deano
 */

#ifndef COMPONENTSCENE_H_
#define COMPONENTSCENE_H_

#include <list>
#include "EntityManager.h"
#include "Scene.h"
#include "SubsystemCollection.h"

class EntityManager;
class GameTime;
class MedliGame;
class Subsystem;

class ComponentScene :
    public Scene
{
  public:
    EntityManager entityManager;

    ComponentScene(MedliGame* pGame, const std::string& id);
    virtual ~ComponentScene();

    void addSubsystem(Subsystem* pSubsystem);

  protected:
    virtual void onInitialise() = 0;
    virtual void onLoad() = 0;
    virtual void onUpdate() = 0;
    virtual void onDraw() = 0;
    virtual void onUnload() = 0;

  private:
    SubsystemCollection subsystemCollection_;
    bool isInitialised_;
    bool isLoaded_;

    void initialise() override;
    void load() override;
    void update(const GameTime& gameTime) override;
    void draw(const GameTime& gameTime) override;
    void unload() override;
};

#endif /* COMPONENTSCENE_H_ */
