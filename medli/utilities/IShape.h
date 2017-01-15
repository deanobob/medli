/*
 * PolygonShape.h
 *
 *  Created on: 10 May 2015
 *      Author: Dean Harris
 */

#ifndef ISHAPE_H_
#define ISHAPE_H_

#include "Shapes.h"

class Vector2;

class IShape
{
  public:
    virtual ~IShape() {}

    virtual Shapes::Enum getType() const = 0;

    virtual Vector2 getPosition() const = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
};

#endif /* ISHAPE_H_ */
