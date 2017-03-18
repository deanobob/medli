/*
 * AnimationPlayer.cpp
 *
 *  Created on: 21 Jan 2017
 *      Author: deano
 */

#include <algorithm>
#include "AnimationPlayer.h"
#include "../core/GameTime.h"

AnimationPlayer::AnimationPlayer()
{
  this->pAnimation_ = nullptr;
  this->elapsed_ = 0.0f;
}

AnimationPlayer::~AnimationPlayer()
{

}

void AnimationPlayer::update(const GameTime& gameTime)
{
  this->elapsed_ += gameTime.elapsedGameTime;

  if (this->pAnimation_ != nullptr)
  {
    Frame* pFrame = this->pAnimation_->getCurrentFrame();
    if (pFrame != nullptr)
    {
      if (this->elapsed_ >= pFrame->duration)
      {
        this->elapsed_ = std::fmod(this->elapsed_, pFrame->duration);

        if (this->pAnimation_->getCurrentFrameId() >= pAnimation_->getTotalFrames() - 1)
        {
          if (this->pAnimation_->isLoopy())
          {
            this->pAnimation_->setCurrentFrameId(0);
          }
        }
        else
        {
          this->pAnimation_->setCurrentFrameId(this->pAnimation_->getCurrentFrameId() + 1);
        }
      }
    }
  }
}

void AnimationPlayer::setAnimation(Animation* pAnimation)
{
  if (this->pAnimation_ == nullptr || this->pAnimation_ != pAnimation)
  {
    this->pAnimation_ = pAnimation;
    this->elapsed_ = 0.0f;
  }
}

Animation* AnimationPlayer::getAnimation() const
{
  return this->pAnimation_;
}
