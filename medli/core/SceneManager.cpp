/*
 * SceneManager.cpp
 *
 *  Created on: 30 Sep 2014
 *      Author: deano
 */

#include "../log/Logger.h"
#include "../MedliGame.h"
#include "GameTime.h"
#include "Scene.h"
#include "SceneManager.h"

SceneManager::SceneManager(MedliGame* pGame) :
  IBroadcastListener()
{
  this->pGame_ = pGame;
}

SceneManager::~SceneManager()
{

}

void SceneManager::initialise()
{
  for (auto it : this->sceneList_)
  {
    it->internalInitialise();
  }
}

void SceneManager::load()
{
  for (auto it : this->sceneList_)
  {
    it->internalLoad();
  }
}

void SceneManager::update(const GameTime& gameTime)
{
  Scene* pScene = nullptr;
  for (auto it : this->sceneList_)
  {
    pScene = it;
    if (pScene->isEnabled())
    {
      pScene->internalUpdate(gameTime);
    }
  }
}

void SceneManager::draw(const GameTime& gameTime)
{
  Scene* pScene = nullptr;
  for (auto it : this->sceneList_)
  {
    pScene = it;
    if (pScene->isVisible())
    {
      pScene->internalDraw(gameTime);
    }
  }
}

void SceneManager::unload()
{
  for (auto it : this->sceneList_)
  {
    it->internalUnload();
  }
}

void SceneManager::addScene(Scene* pScene)
{
  this->sceneList_.push_back(pScene);
}

void SceneManager::onMessageBroadcast(Event* pEvent)
{

}
