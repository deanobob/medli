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

namespace MessageId
{
  static const std::string DISPLAY_CLOSE                  = "DISPLAY_CLOSE";
  static const std::string JOYSTICK_CONFIGURATION_CHANGED = "JOYSTICK_CONFIGURATION_CHANGED";
  static const std::string MOUSE_BUTTON_STATE_CHANGED     = "MOUSE_BUTTON_STATE_CHANGED";
  static const std::string MOUSE_AXES_CHANGED             = "MOUSE_AXES_CHANGED";
  static const std::string KEYBOARD_STATE_CHANGED         = "KEYBOARD_STATE_CHANGED";
  static const std::string JOYPAD_AXIS_STATE_CHANGED      = "JOYPAD_AXIS_STATE_CHANGED";
  static const std::string JOYPAD_STATE_CHANGED           = "JOYPAD_STATE_CHANGED";
  static const std::string DISPLAY_RESIZE                 = "DISPLAY_RESIZE";
}

class InputManager
{
	public:
		static bool initialise();
    static void listeningFor(const std::string& messageType, IBroadcastListener* pListener);
    static void stopListeningFor(const std::string& messageType, IBroadcastListener* pListener);
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
