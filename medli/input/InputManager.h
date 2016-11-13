/*
 * InputManager.h
 *
 *  Created on: 1 Sep 2013
 *      Author: deano
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <allegro5/allegro.h>
#include <vector>
#include "JoypadState.h"
#include "KeyboardState.h"
#include "MouseState.h"

class Broadcaster;
class IBroadcastListener;

class InputManager
{
	public:
    enum MessageType : int
    {
      DisplayClose = 0,
      JoystickConfigurationChanged,
      MouseButtonStateChanged,
      MouseAxesChanged,
      KeyboardStateChanged,
      JoypadAxisStateChanged,
      JoypadStateChanged,
      DisplayResize
    };

		static bool initialise();
    static void listeningFor(MessageType messageType, IBroadcastListener* pListener);
    static void stopListeningFor(MessageType messageType, IBroadcastListener* pListener);
    static void registerEventSource(ALLEGRO_EVENT_SOURCE* pSource);
    static void update();
		static void shutdown();

		static MouseState* getMouseState();
		static JoypadState* getJoypadState(unsigned int joypadId);
		static KeyboardState* getKeyboardState();

	private:
		static InputManager InputManager_;

		Broadcaster* pBroadcaster_;
    std::vector<JoypadState*> joypadList_;
    KeyboardState* pKeyboardState_;
    MouseState* pMouseState_;
    ALLEGRO_EVENT_QUEUE* pEventQueue_;

    InputManager();
    virtual ~InputManager();
};

#endif /* INPUTMANAGER_H_ */
