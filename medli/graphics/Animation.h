/*
 * Animation.h
 *
 *  Created on: 21 Jan 2017
 *      Author: deano
 */

#ifndef MEDLI_GRAPHICS_ANIMATION_H_
#define MEDLI_GRAPHICS_ANIMATION_H_

#include <vector>
#include "Frame.h"

class Animation
{
  public:
    Animation(const std::vector<Frame*> frameList, const bool loop, const int flags = 0, unsigned int initialFrame = 0);
    virtual ~Animation();

    void setCurrentFrameId(unsigned int currentFrame);
    Frame* getCurrentFrame() const;
    unsigned int getCurrentFrameId() const;
    unsigned int getTotalFrames() const;
    const int getFlags() const;
    bool isLoopy() const;

  private:
    const std::vector<Frame*> frameList_;
    const bool loop_;
    const int flags_;
    unsigned int currentFrame_;
};

#endif /* MEDLI_GRAPHICS_ANIMATION_H_ */
