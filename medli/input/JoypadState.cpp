/*
 * JoypadState.cpp
 *
 *  Created on: 1 Sep 2013
 *      Author: deano
 */

#include <algorithm>
#include "JoypadState.h"

JoypadState::JoypadState()
{

}

JoypadState::~JoypadState()
{

}

void JoypadState::setAxisState(unsigned int stick, unsigned int axis, float position)
{
  std::vector<float> axisList;
  if (this->stickList_.find(stick) != this->stickList_.end())
  {
    axisList = this->stickList_[stick];
  }

  if (axisList.size() < axis + 1)
  {
    while (axisList.size() < axis + 1)
    {
      axisList.push_back(0.0f);
    }
  }

  axisList[axis] = position;

  this->stickList_[stick] = axisList;
}

float JoypadState::getAxisState(unsigned int stick, unsigned int axis)
{
  std::vector<float> axisList;
  if (this->stickList_.find(stick) != this->stickList_.end())
  {
    axisList = this->stickList_[stick];
  }

  if (axisList.size() > axis)
  {
    return axisList.at(axis);
  }

  return 0.0f;
}

void JoypadState::setButtonUp(int button)
{
  this->pressedButtonList_.remove(button);
}

void JoypadState::setButtonDown(int button)
{
  this->pressedButtonList_.push_back(button);
}

bool JoypadState::isButtonDown(int button)
{
  return std::find(this->pressedButtonList_.begin(), this->pressedButtonList_.end(), button) !=
      this->pressedButtonList_.end();
}
