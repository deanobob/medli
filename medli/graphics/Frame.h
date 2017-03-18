/*
 * Frame.h
 *
 *  Created on: 21 Jan 2017
 *      Author: deano
 */

#ifndef MEDLI_GRAPHICS_FRAME_H_
#define MEDLI_GRAPHICS_FRAME_H_

#include <string>
#include "../utilities/Vector2.h"

class Frame
{
  public:
    const std::string sprite;
    const float duration;
    const Vector2 offset;

    Frame(const std::string& sprite, const float duration, const Vector2& offset);
    virtual ~Frame();
};

#endif /* MEDLI_GRAPHICS_FRAME_H_ */
