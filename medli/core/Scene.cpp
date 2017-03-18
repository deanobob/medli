/*
 * Scene.cpp
 *
 *  Created on: 25 Apr 2015
 *      Author: Dean Harris
 */

#include "../graphics/CameraCollection.h"
#include "../graphics/DrawManager.h"
#include "../MedliGame.h"
#include "GameTime.h"
#include "Scene.h"

Scene::Scene(MedliGame* pGame, const std::string id) :
    id_(id)
{
  this->pGame_ = pGame;
  this->pCameraCollection_ = new CameraCollection();
  this->pDrawManager_ = new DrawManager(this->pGame_);
  this->isEnabled_ = true;
  this->isVisible_ = true;
}

Scene::~Scene()
{
  delete this->pCameraCollection_;
  delete this->pDrawManager_;
}

const std::string& Scene::getId() const
{
  return this->id_;
}

void Scene::internalInitialise()
{
  this->initialise();
}

void Scene::internalLoad()
{
  this->load();
}

void Scene::internalUpdate(const GameTime& gameTime)
{
  this->update(gameTime);
}

void Scene::internalDraw(const GameTime& gameTime)
{
  this->pDrawManager_->begin(this->pCameraCollection_);
  this->draw(gameTime);
  this->pDrawManager_->end();
}

void Scene::internalUnload()
{
  this->unload();
}

void Scene::addCamera(Camera* pCamera)
{
  this->pCameraCollection_->add(pCamera);
}

Camera* Scene::getCamera(const short id)
{
  return this->pCameraCollection_->get(id);
}

DrawManager* Scene::getDrawManager() const
{
  return this->pDrawManager_;
}

void Scene::setVisible(bool visible)
{
  this->isVisible_ = visible;
}

bool Scene::isVisible()
{
  return this->isVisible_;
}

void Scene::setEnabled(bool enabled)
{
  this->isEnabled_ = enabled;
}

bool Scene::isEnabled()
{
  return this->isEnabled_;
}
