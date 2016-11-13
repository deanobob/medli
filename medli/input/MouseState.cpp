/*
 * MouseState.cpp
 *
 *  Created on: 4 May 2014
 *      Author: deano
 */

#include "MouseState.h"

MouseState::MouseState()
{
  this->positionX_ = 0;
  this->positionY_ = 0;
  this->wheelX_ = 0;
  this->wheelY_ = 0;
}

MouseState::~MouseState()
{

}

void MouseState::setButtonState(unsigned int button,
                                bool pressed)
{
  this->buttonState_[button] = pressed;
}

bool MouseState::isButtonPressed(unsigned int button)
{
  if (this->buttonState_.find(button) != this->buttonState_.end())
  {
    return this->buttonState_[button];
  }

  return false;
}

void MouseState::setPositionX(int x)
{
  this->positionX_ = x;
}

int MouseState::getPositionX() const
{
  return this->positionX_;
}

void MouseState::setPositionY(int y)
{
  this->positionY_ = y;
}

int MouseState::getPositionY() const
{
  return this->positionY_;
}

void MouseState::setWheelX(int x)
{
  this->wheelX_ = x;
}

int MouseState::getWheelX() const
{
  return this->wheelX_;
}

void MouseState::setWheelY(int y)
{
  this->wheelY_ = y;
}

int MouseState::getWheelY() const
{
  return this->wheelY_;
}
