/*
 * KeyboardState.cpp
 *
 *  Created on: 1 Sep 2013
 *      Author: deano
 */

#include <algorithm>
#include "KeyboardState.h"

KeyboardState::KeyboardState()
{

}

KeyboardState::~KeyboardState()
{

}

void KeyboardState::setKeyUp(int keycode)
{
  this->pressedKeyList_.remove(keycode);
}

void KeyboardState::setKeyDown(int keycode)
{
  this->pressedKeyList_.push_back(keycode);
}

bool KeyboardState::isKeyDown(int keycode)
{
  return std::find(this->pressedKeyList_.begin(), this->pressedKeyList_.end(), keycode) != this->pressedKeyList_.end();
}
