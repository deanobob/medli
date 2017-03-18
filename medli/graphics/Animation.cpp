/*
 * Animation.cpp
 *
 *  Created on: 21 Jan 2017
 *      Author: deano
 */

#include <assert.h>
#include <stdexcept>
#include "Animation.h"

Animation::Animation(const std::vector<Frame*> frameList, const bool loop, const int flags, unsigned int initialFrame) :
    frameList_(frameList), loop_(loop), flags_(flags)
{
  assert (initialFrame < frameList.size());
  this->currentFrame_ = initialFrame;
}

Animation::~Animation()
{

}

void Animation::setCurrentFrameId(unsigned int currentFrame)
{
  if (currentFrame > this->getTotalFrames())
  {
    throw std::out_of_range("Cannot set frame - out of range!");
  }
  else
  {
    this->currentFrame_ = currentFrame;
  }
}

Frame* Animation::getCurrentFrame() const
{
  return this->frameList_.at(this->currentFrame_);
}

unsigned int Animation::getCurrentFrameId() const
{
  return this->currentFrame_;
}

unsigned int Animation::getTotalFrames() const
{
  return this->frameList_.size();
}

const int Animation::getFlags() const
{
  return this->flags_;
}

bool Animation::isLoopy() const
{
  return this->loop_;
}
