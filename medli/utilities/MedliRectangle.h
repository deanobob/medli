/*
 * DeanoRectangle.h
 *
 *  Created on: 30 Apr 2015
 *      Author: Dean Harris
 */

#ifndef DEANORECTANGLE_H_
#define DEANORECTANGLE_H_

#include <vector>

class Point;
class IShape;
class Vector2;

class MedliRectangle
{
  public:
    static const MedliRectangle EMPTY;

    int X;
    int Y;
    int Width;
    int Height;

    MedliRectangle();
    MedliRectangle(int x, int y, int width, int height);
    virtual ~MedliRectangle();

    Vector2 getPosition() const;
    int getLeft() const;
    int getRight() const;
    int getTop() const;
    int getBottom() const;
    Vector2 getCentre() const;
    int getCentreX() const;
    int getCentreY() const;
    bool contains(int x, int y) const;
    bool contains(const Point& value) const;
    bool contains(const Vector2& value) const;
    bool contains(const MedliRectangle& value) const;
    bool intersects(const MedliRectangle& value) const;
    IShape* getShape() const;

    bool operator== (const MedliRectangle& rhs) const;
    bool operator!= (const MedliRectangle& rhs) const;
};

#endif /* DEANORECTANGLE_H_ */
