/*
 * DeanoRectangleF.h
 *
 *  Created on: 3 May 2015
 *      Author: Dean Harris
 */

#ifndef DEANORECTANGLEF_H_
#define DEANORECTANGLEF_H_

class Point;
class Vector2;

class MedliRectangleF
{
  public:
    static const MedliRectangleF EMPTY;

    float X;
    float Y;
    float Width;
    float Height;

    MedliRectangleF();
    MedliRectangleF(float x, float y, float width, float height);
    virtual ~MedliRectangleF();

    float getLeft() const;
    float getRight() const;
    float getTop() const;
    float getBottom() const;
    const Vector2 getCenter() const;
    bool contains(float x, float y) const;
    bool contains(const Point& value) const;
    bool contains(const Vector2& value) const;
    bool contains(const MedliRectangleF& value) const;

    bool operator== (const MedliRectangleF& rhs) const;
    bool operator!= (const MedliRectangleF& rhs) const;
    MedliRectangleF operator* (const MedliRectangleF& rhs) const;
    MedliRectangleF operator* (const double& rhs) const;
};

#endif /* DEANORECTANGLEF_H_ */
