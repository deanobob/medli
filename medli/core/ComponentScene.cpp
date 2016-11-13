/*
 * ComponentScene.cpp
 *
 *  Created on: 16 Jun 2014
 *      Author: deano
 */

#include "../graphics/DrawManager.h"
#include "../MedliGame.h"
#include "ComponentScene.h"
#include "Subsystem.h"
#include "SubsystemCollection.h"

ComponentScene::ComponentScene(MedliGame* pGame) :
    Scene(pGame)
{
  this->isInitialised_ = false;
  this->isLoaded_ = false;
}

ComponentScene::~ComponentScene()
{

}

void ComponentScene::initialise()
{
  for (auto it : this->subsystemCollection_)
  {
    it->initialise();
  }

  this->onInitialise();

  this->isInitialised_ = true;
}

void ComponentScene::load()
{
  for (auto it : this->subsystemCollection_)
  {
    it->load();
  }

  this->onLoad();

  this->isLoaded_ = true;
}

void ComponentScene::update(const GameTime& gameTime)
{
  auto updateQueue = this->subsystemCollection_.getUpdateQueue();

  Subsystem* pSubsystem = nullptr;
  while (!updateQueue.empty())
  {
    pSubsystem = updateQueue.top();

    if (pSubsystem->isEnabled())
    {
      pSubsystem->update(gameTime);
    }

    updateQueue.pop();
  }

  this->onUpdate();
}

void ComponentScene::draw(const GameTime& gameTime)
{
  auto drawQueue = this->subsystemCollection_.getDrawQueue();

  Subsystem* pSubsystem = nullptr;
  while (!drawQueue.empty())
  {
    pSubsystem = drawQueue.top();

    if (pSubsystem->isVisible())
    {
      pSubsystem->draw(gameTime);
    }

    drawQueue.pop();
  }

  this->onDraw();
}

void ComponentScene::unload()
{
  for (auto it : this->subsystemCollection_)
  {
    it->unload();
  }

  this->onUnload();

  this->isLoaded_ = false;
}

void ComponentScene::addSubsystem(Subsystem* pSubsystem)
{
  pSubsystem->setGame(this->pGame_);
  pSubsystem->setDrawManager(this->pDrawManager_);
  pSubsystem->setEntityManager(&this->entityManager);
  pSubsystem->setScene(this);

  if (this->isInitialised_)
  {
    pSubsystem->initialise();
  }

  if (this->isLoaded_)
  {
    pSubsystem->load();
  }

  this->subsystemCollection_.add(pSubsystem);
  this->entityManager.registerListener(pSubsystem);
}
