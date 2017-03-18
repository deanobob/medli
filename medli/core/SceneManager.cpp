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
#include "SceneMessages.h"

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
  for (auto it : this->sceneMap_)
  {
    it.second->internalInitialise();
  }

  this->pGame_->pBroadcaster->listenFor(MessageId::SCENE_STATE, this);
}

void SceneManager::load()
{
  for (auto it : this->sceneMap_)
  {
    it.second->internalLoad();
  }
}

void SceneManager::update(const GameTime& gameTime)
{
  Scene* pScene = nullptr;
  for (auto it : this->sceneMap_)
  {
    pScene = it.second;
    if (pScene->isEnabled())
    {
      pScene->internalUpdate(gameTime);
    }
  }
}

void SceneManager::draw(const GameTime& gameTime)
{
  Scene* pScene = nullptr;
  for (auto it : this->sceneMap_)
  {
    pScene = it.second;
    if (pScene->isVisible())
    {
      pScene->internalDraw(gameTime);
    }
  }
}

void SceneManager::unload()
{
  for (auto it : this->sceneMap_)
  {
    it.second->internalUnload();
  }

  this->pGame_->pBroadcaster->stopListeningFor(MessageId::SCENE_STATE, this);
}

void SceneManager::addScene(Scene* pScene)
{
  this->sceneMap_[pScene->getId()] = pScene;
}

void SceneManager::onMessageBroadcast(Message* pMessage)
{
  if (pMessage->messageId == MessageId::SCENE_STATE)
  {
    SceneMessageState* pSceneMessage = (SceneMessageState*)pMessage;
    auto it = this->sceneMap_.find(pSceneMessage->sceneId);
    if (it != this->sceneMap_.end())
    {
      it->second->setEnabled(pSceneMessage->enabled);
      it->second->setVisible(pSceneMessage->visible);
    }
    else
    {
      ERR("Failed to find scene %s", pSceneMessage->sceneId.c_str());
    }
  }
}
