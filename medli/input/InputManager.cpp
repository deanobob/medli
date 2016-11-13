/*
 * InputManager.cpp
 *
 *  Created on: 1 Sep 2013
 *      Author: deano
 */

#include <cmath>
#include "../core/Broadcaster.h"
#include "../core/Event.h"
#include "../graphics/GraphicsProperties.h"
#include "../log/Logger.h"
#include "InputManager.h"
#include "JoypadAxisEvent.h"
#include "JoypadEvent.h"
#include "KeyboardEvent.h"
#include "KeyboardState.h"
#include "MouseAxesEvent.h"
#include "MouseClickEvent.h"

InputManager InputManager::InputManager_;

bool InputManager::initialise()
{
  bool rc = true;

  if (!al_install_mouse())
  {
    ERR("Failed to install mouse", nullptr);
    rc = false;
  }

  if (!al_install_keyboard())
  {
    ERR("Failed to install keyboard", nullptr);
    rc = false;
  }

  if (!al_install_joystick())
  {
    ERR("Failed to install joystick", nullptr);
    rc = false;
  }

  InputManager_.pEventQueue_ = al_create_event_queue();
  if (InputManager_.pEventQueue_ == nullptr)
  {
    ERR("Failed to create event queue", nullptr);
    rc = false;
  }

  InputManager::registerEventSource(al_get_mouse_event_source());
  InputManager::registerEventSource(al_get_keyboard_event_source());
  InputManager::registerEventSource(al_get_joystick_event_source());

  return rc;
}

void InputManager::registerEventSource(ALLEGRO_EVENT_SOURCE* pSource)
{
  if (InputManager_.pEventQueue_ != nullptr)
  {
    al_register_event_source(InputManager_.pEventQueue_, pSource);
  }
}

void InputManager::listeningFor(MessageType messageId, IBroadcastListener* pBroadcastListener)
{
  InputManager_.pBroadcaster_->listenFor(messageId, pBroadcastListener);
}

void InputManager::stopListeningFor(MessageType messageId, IBroadcastListener* pBroadcastListener)
{
  InputManager_.pBroadcaster_->stopListeningFor(messageId, pBroadcastListener);
}

void InputManager::update()
{
  ALLEGRO_EVENT event;

  while (al_get_next_event(InputManager_.pEventQueue_, &event))
  {
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
      InputManager_.pKeyboardState_->setKeyDown(event.keyboard.keycode);

      KeyboardEvent e = KeyboardEvent(KeyboardStateChanged,
                                      event.keyboard.keycode,
                                      true);
      InputManager_.pBroadcaster_->send(&e);
    }
    else if (event.type == ALLEGRO_EVENT_KEY_UP)
    {
      InputManager_.pKeyboardState_->setKeyUp(event.keyboard.keycode);

      KeyboardEvent e = KeyboardEvent(KeyboardStateChanged,
                                      event.keyboard.keycode,
                                      false);
      InputManager_.pBroadcaster_->send(&e);
    }
    else if (event.type == ALLEGRO_EVENT_JOYSTICK_AXIS)
    {
      InputManager_.joypadList_[0]->setAxisState(event.joystick.stick,
                                                 event.joystick.axis,
                                                 event.joystick.pos);

      JoypadAxisEvent e = JoypadAxisEvent(JoypadAxisStateChanged,
                                          event.joystick.stick,
                                          event.joystick.axis,
                                          event.joystick.pos);
      InputManager_.pBroadcaster_->send(&e);
    }
    else if (event.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN)
    {
      InputManager_.joypadList_[0]->setButtonDown(event.joystick.button);

      JoypadEvent e = JoypadEvent(JoypadStateChanged,
                                  event.joystick.button,
                                  true);
      InputManager_.pBroadcaster_->send(&e);
    }
    else if (event.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_UP)
    {
      InputManager_.joypadList_[0]->setButtonUp(event.joystick.button);

      JoypadEvent e = JoypadEvent(JoypadStateChanged,
                                  event.joystick.button,
                                  false);
      InputManager_.pBroadcaster_->send(&e);
    }
    else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
      InputManager_.pMouseState_->setButtonState(event.mouse.button, true);
      MouseClickEvent e = MouseClickEvent(MouseButtonStateChanged,
                                          (MouseButton)event.mouse.button,
                                          event.mouse.x,
                                          event.mouse.y,
                                          true);
      InputManager_.pBroadcaster_->send(&e);
    }
    else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
    {
      InputManager_.pMouseState_->setButtonState(event.mouse.button, false);

      MouseClickEvent e = MouseClickEvent(MouseButtonStateChanged,
                                          (MouseButton)event.mouse.button,
                                          event.mouse.x,
                                          event.mouse.y,
                                          false);
      InputManager_.pBroadcaster_->send(&e);
    }
    else if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
    {
      InputManager_.pMouseState_->setPositionX(event.mouse.x);
      InputManager_.pMouseState_->setPositionY(event.mouse.y);
      InputManager_.pMouseState_->setWheelX(event.mouse.w);
      InputManager_.pMouseState_->setWheelY(event.mouse.z);

      MouseAxesEvent e = MouseAxesEvent(MouseAxesChanged,
                                        event.mouse.x,
                                        event.mouse.y,
                                        event.mouse.w,
                                        event.mouse.z);
      InputManager_.pBroadcaster_->send(&e);
    }
    else if (event.type == ALLEGRO_EVENT_JOYSTICK_CONFIGURATION)
    {
      al_reconfigure_joysticks();

      Event e = Event(JoystickConfigurationChanged);
      InputManager_.pBroadcaster_->send(&e);
    }
    else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
      Event e = Event(DisplayClose);
      InputManager_.pBroadcaster_->send(&e);
    }
    else if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
    {
      al_acknowledge_resize(event.display.source);

      GraphicsProperties::setWindowSize(event.display.width, event.display.height);

      Event e = Event(DisplayResize);
      InputManager_.pBroadcaster_->send(&e);
    }
  }
}

void InputManager::shutdown()
{
  if (InputManager_.pEventQueue_ != nullptr)
  {
    al_destroy_event_queue(InputManager_.pEventQueue_);
  }
}

MouseState* InputManager::getMouseState()
{
  return InputManager_.pMouseState_;
}

JoypadState* InputManager::getJoypadState(unsigned int joypadId)
{
  if (joypadId < InputManager_.joypadList_.size())
  {
    return InputManager_.joypadList_[joypadId];
  }

  return nullptr;
}

KeyboardState* InputManager::getKeyboardState()
{
  return InputManager_.pKeyboardState_;
}

InputManager::InputManager()
{
  InputManager_.pEventQueue_ = nullptr;
  InputManager_.pBroadcaster_ = new Broadcaster();
  InputManager_.pKeyboardState_ = new KeyboardState();
  InputManager_.pMouseState_ = new MouseState();
  InputManager_.joypadList_.push_back(new JoypadState());
}

InputManager::~InputManager()
{
  delete InputManager_.pBroadcaster_;
  delete InputManager_.pKeyboardState_;
  delete InputManager_.pMouseState_;

  for (auto joypad : InputManager_.joypadList_)
  {
    delete joypad;
  }

  InputManager::joypadList_.clear();
}
