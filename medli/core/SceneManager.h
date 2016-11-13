/*
 * SceneManager.h
 *
 *  Created on: 30 Sep 2014
 *      Author: deano
 */

#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include <vector>
#include "IBroadcastListener.h"

class MedliGame;
class GameTime;
class Scene;

class SceneManager :
    public IBroadcastListener
{
  public:
    SceneManager(MedliGame* pGame);
    virtual ~SceneManager();

    void initialise();
    void load();
    void update(const GameTime& gameTime);
    void draw(const GameTime& gameTime);
    void unload();

    void addScene(Scene* pScene);

    void onMessageBroadcast(Event* pEvent);

  private:
    MedliGame* pGame_;
    std::vector<Scene*> sceneList_;
};

#endif /* SCENEMANAGER_H_ */
