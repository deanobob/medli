/*
 * MedliGame.h
 *
 *  Created on: 25 Oct 2016
 *      Author: deano
 */

#ifndef SRC_MEDLIGAME_H_
#define SRC_MEDLIGAME_H_

#include "core/Broadcaster.h"
#include "core/GameTime.h"
#include "core/SceneManager.h"
#include "graphics/DrawEngine.h"
#include "graphics/ResourceManager.h"

class MedliGame
{
  public:
    Broadcaster* pBroadcaster;
    DrawEngine* pDrawEngine;
    ResourceManager* pResourceManager;
    SceneManager* pSceneManager;
    bool isFixedTimeStep;

    MedliGame();
    virtual ~MedliGame();

    void run();
    void exit();

  protected:
    virtual void onInitialise() = 0;
    virtual void onShutdown() = 0;

  private:
    GameTime gameTime_;
    bool exit_;

    void initialise();
    void load();
    void update();
    void draw();
    void shutdown();

};

#endif /* SRC_MEDLIGAME_H_ */
