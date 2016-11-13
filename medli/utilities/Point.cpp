/*
 * Point.cpp
 *
 *  Created on: 1 May 2015
 *      Author: Dean Harris
 */

#include "Point.h"

const Point Point::ZERO(0, 0);
const Point Point::ONE(1, 1);

Point::Point() :
    Point(0, 0)
{

}

Point::Point(const Point& point)
{
  this->X = point.X;
  this->Y = point.Y;
}

Point::Point(const int x, const int y)
{
  this->X = x;
  this->Y = y;
}

Point::~Point()
{

}

Point Point::operator+ (const Point& rhs) const
{
  return Point(this->X + rhs.X, this->Y + rhs.Y);
}

Point& Point::operator+= (const Point& rhs)
{
  this->X += rhs.X;
  this->Y += rhs.Y;

  return *this;
}

Point Point::operator- (const Point& rhs) const
{
  return Point(this->X - rhs.X, this->Y - rhs.Y);
}

Point& Point::operator-= (const Point& rhs)
{
  this->X -= rhs.X;
  this->Y -= rhs.Y;

  return *this;
}

Point Point::operator* (const Point& rhs) const
{
  return Point(this->X * rhs.X, this->Y * rhs.Y);
}

Point& Point::operator*= (const Point& rhs)
{
  this->X *= rhs.X;
  this->Y *= rhs.Y;

  return *this;
}

Point Point::operator/ (const Point& rhs) const
{
  return Point(this->X / rhs.X, this->Y / rhs.Y);
}

Point& Point::operator/= (const Point& rhs)
{
  this->X /= rhs.X;
  this->Y /= rhs.Y;

  return *this;
}

bool Point::operator== (const Point& rhs) const
{
  return this->X == rhs.X && this->Y == rhs.Y;
}

bool Point::operator!= (const Point& rhs) const
{
  return !(*this == rhs);
}
