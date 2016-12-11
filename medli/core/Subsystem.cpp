/*
 * Subsystem.cpp
 *
 *  Created on: 14 Jun 2014
 *      Author: deano
 */

#include "../log/Logger.h"
#include "../MedliGame.h"
#include "GameTime.h"
#include "Subsystem.h"

Subsystem::Subsystem(short typeId, unsigned int componentMask, short updatePriority, short drawPriority) :
    EntityListener(componentMask), typeId_(typeId), updatePriority_(updatePriority), drawPriority_(drawPriority)
{
  this->pDrawManager_ = nullptr;
  this->pGame_ = nullptr;
  this->pScene_ = nullptr;
  this->isEnabled_ = true;
  this->isVisible_ = true;
}

Subsystem::~Subsystem()
{

}

unsigned short Subsystem::getTypeId() const
{
  return this->typeId_;
}

void Subsystem::initialise()
{
  this->onInitialise();
}

void Subsystem::load()
{
  this->onLoad();
}

void Subsystem::update(const GameTime& gameTime)
{
  if (this->entityListHasChanged_)
  {
    this->refreshEntityList();
  }

  this->onUpdate(gameTime);
}

void Subsystem::draw(const GameTime& gameTime)
{
  this->onDraw(gameTime);
}

void Subsystem::unload()
{
  this->onUnload();
}

void Subsystem::setGame(MedliGame* pGame)
{
  this->pGame_ = pGame;
}

void Subsystem::setDrawManager(DrawManager* pDrawManager)
{
  this->pDrawManager_ = pDrawManager;
}

void Subsystem::setScene(Scene* pScene)
{
  this->pScene_ = pScene;
}

void Subsystem::setVisible(bool visible)
{
  this->isVisible_ = visible;
}

bool Subsystem::isVisible() const
{
  return this->isVisible_;
}

void Subsystem::setEnabled(bool enabled)
{
  this->isEnabled_ = enabled;
}

bool Subsystem::isEnabled() const
{
  return this->isEnabled_;
}

short Subsystem::getUpdatePriority() const
{
  return this->updatePriority_;
}

short Subsystem::getDrawPriority() const
{
  return this->drawPriority_;
}
