/*
 * Frame.cpp
 *
 *  Created on: 21 Jan 2017
 *      Author: deano
 */

#include "Frame.h"

Frame::Frame(const std::string& sprite, const float duration, const Vector2& offset) :
    sprite(sprite), duration(duration), offset(offset)
{

}

Frame::~Frame()
{

}

