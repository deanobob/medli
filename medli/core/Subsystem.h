/*
 * Subsystem.h
 *
 *  Created on: 14 Jun 2014
 *      Author: deano
 */

#ifndef SUBSYSTEM_H_
#define SUBSYSTEM_H_

#include "EntityListener.h"

class DrawManager;
class GameTime;
class MedliGame;
class Scene;

class Subsystem :
    public EntityListener
{
  public:
    Subsystem(short typeId, const unsigned int componentMask, short updatePriority = 0, short drawPriority = 0);
    virtual ~Subsystem();

    virtual unsigned short getTypeId() const;

    void initialise();
    void load();
    void update(const GameTime& gameTime);
    void draw(const GameTime& gameTime);
    void unload();

    void setGame(MedliGame* pGame);
    void setDrawManager(DrawManager* pDrawManager);
    void setScene(Scene* pScene);

    void setVisible(bool visible);
    bool isVisible() const;

    void setEnabled(bool enabled);
    bool isEnabled() const;

    short getUpdatePriority() const;
    short getDrawPriority() const;

  protected:
    MedliGame* pGame_;
    DrawManager* pDrawManager_;
    Scene* pScene_;

    virtual void onInitialise() = 0;
    virtual void onLoad() = 0;
    virtual void onUpdate(const GameTime& gameTime) = 0;
    virtual void onDraw(const GameTime& gameTime) = 0;
    virtual void onUnload() = 0;

  private:
    bool isVisible_;
    bool isEnabled_;
    const short typeId_;
    const short updatePriority_;
    const short drawPriority_;
};


#endif /* SUBSYSTEM_H_ */
