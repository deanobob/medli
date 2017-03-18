/*
 * AnimationPlayer.h
 *
 *  Created on: 21 Jan 2017
 *      Author: deano
 */

#ifndef MEDLI_GRAPHICS_ANIMATIONPLAYER_H_
#define MEDLI_GRAPHICS_ANIMATIONPLAYER_H_

#include <list>
#include "Animation.h"

class GameTime;

class AnimationPlayer
{
  public:
    AnimationPlayer();
    virtual ~AnimationPlayer();

    void update(const GameTime& gameTime);

    void setAnimation(Animation* pAnimation);
    Animation* getAnimation() const;

  private:
    Animation* pAnimation_;
    float elapsed_;
};

#endif /* MEDLI_GRAPHICS_ANIMATIONPLAYER_H_ */
