/*
 * MedliGame.cpp
 *
 *  Created on: 25 Oct 2016
 *      Author: deano
 */

#include "core/GameTime.h"
#include "input/InputManager.h"
#include "log/Logger.h"
#include "utilities/Utilities.h"
#include "MedliGame.h"

static const double TARGET_ELAPSED_TIME = 1.0 / 60.0;
static const double MAX_ELAPSED_TIME = 1.0 / 4.0;

MedliGame::MedliGame()
{
  this->exit_ = false;
  this->isFixedTimeStep = true;
  this->pDrawEngine = new DrawEngine();
  this->pResourceManager = new ResourceManager();
  this->pSceneManager = new SceneManager(this);
}

MedliGame::~MedliGame()
{
  delete this->pDrawEngine;
  delete this->pResourceManager;
  delete this->pSceneManager;
}

void MedliGame::run()
{
  this->initialise();
  this->load();

  double currentTime = Utilities::getCurrentTimeInSeconds();
  double accumulatedTime = 0.0;
  double previousTime = 0.0;

  while (!this->exit_)
  {
    currentTime = Utilities::getCurrentTimeInSeconds();
    accumulatedTime += currentTime - previousTime;
    previousTime = currentTime;

    if (this->isFixedTimeStep && accumulatedTime < TARGET_ELAPSED_TIME)
    {
      Utilities::sleep(TARGET_ELAPSED_TIME - accumulatedTime, TimeFormat::SECONDS);
    }
    else
    {
      if (accumulatedTime > MAX_ELAPSED_TIME)
      {
        accumulatedTime = MAX_ELAPSED_TIME;
      }

      if (this->isFixedTimeStep)
      {
        this->gameTime_.elapsedGameTime = TARGET_ELAPSED_TIME;

        unsigned int stepCount = 0;
        while (accumulatedTime >= TARGET_ELAPSED_TIME)
        {
          this->gameTime_.totalGameTime += TARGET_ELAPSED_TIME;
          accumulatedTime -= TARGET_ELAPSED_TIME;
          ++stepCount;

          this->update();
        }

        this->gameTime_.totalGameTime = TARGET_ELAPSED_TIME * stepCount;
      }
      else
      {
        this->gameTime_.elapsedGameTime = accumulatedTime;
        this->gameTime_.totalGameTime = accumulatedTime;
        accumulatedTime = 0.0;

        this->update();
      }

      this->draw();
    }
  }

  this->shutdown();
}

void MedliGame::exit()
{
  this->exit_ = true;
}

void MedliGame::initialise()
{
  if (!al_init())
  {
    ERR("Failed to initialise allegro", nullptr);

    this->exit();
  }
  else if (!InputManager::initialise())
  {
    this->exit();
  }
  else if (!this->pDrawEngine->initialise())
  {
    this->exit();
  }
  else
  {
    this->pResourceManager->initialise();

    this->onInitialise();

    this->pSceneManager->initialise();
  }
}

void MedliGame::load()
{
  this->pSceneManager->load();
}

void MedliGame::update()
{
  InputManager::update();

  this->pSceneManager->update(this->gameTime_);
}

void MedliGame::draw()
{
  this->pDrawEngine->clear();
  this->pSceneManager->draw(this->gameTime_);
  this->pDrawEngine->flip();
}

void MedliGame::shutdown()
{
  this->onShutdown();

  this->pSceneManager->unload();

  InputManager::shutdown();
}
