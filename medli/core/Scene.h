/*
 * IScene.h
 *
 *  Created on: 1 Sep 2013
 *      Author: deano
 */

#ifndef ISCENE_H_
#define ISCENE_H_

#include <list>
#include <map>

class Camera;
class CameraCollection;
class DrawManager;
class GameTime;
class MedliGame;

class Scene
{
	public:
    Scene(MedliGame* pGame, const std::string id);
		virtual ~Scene();

		const std::string& getId() const;

		void internalInitialise();
		void internalLoad();
		void internalUpdate(const GameTime& gameTime);
    void internalDraw(const GameTime& gameTime);
    void internalUnload();

    void addCamera(Camera* pCamera);
    Camera* getCamera(const short id);

    DrawManager* getDrawManager() const;

		void setVisible(bool visible);
		bool isVisible();

		void setEnabled(bool enabled);
		bool isEnabled();

	protected:
		CameraCollection* pCameraCollection_;
    DrawManager* pDrawManager_;
		MedliGame* pGame_;

    virtual void initialise() = 0;
    virtual void load() = 0;
    virtual void update(const GameTime& gameTime) = 0;
    virtual void draw(const GameTime& gameTime) = 0;
    virtual void unload() = 0;

	private:
    const std::string id_;
    bool isEnabled_;
    bool isVisible_;
};

#endif /* ISCENE_H_ */
