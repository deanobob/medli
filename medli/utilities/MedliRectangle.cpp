/*
 * DeanoRectangle.cpp
 *
 *  Created on: 30 Apr 2015
 *      Author: Dean Harris
 */

#include "../utilities/MedliRectangle.h"
#include "Point.h"
#include "Vector2.h"

const MedliRectangle MedliRectangle::EMPTY;

MedliRectangle::MedliRectangle() :
  MedliRectangle(0, 0, 0, 0)
{

}

MedliRectangle::MedliRectangle(int x, int y, int width, int height)
{
  this->X = x;
  this->Y = y;
  this->Width = width;
  this->Height = height;
}

MedliRectangle::~MedliRectangle()
{

}

int MedliRectangle::getLeft() const
{
  return this->X;
}

int MedliRectangle::getRight() const
{
  return this->X + this->Width;
}

int MedliRectangle::getTop() const
{
  return this->Y;
}

int MedliRectangle::getBottom() const
{
  return this->Y + this->Height;
}

int MedliRectangle::getCenterX() const
{
  return this->X + (this->Width / 2);
}

int MedliRectangle::getCenterY() const
{
  return this->Y + (this->Height / 2);
}

bool MedliRectangle::contains(int x, int y) const
{
  return (x >= this->X &&
          x <= (this->X + this->Width) &&
          y >= this->Y &&
          y <= (this->Y + this->Height));
}

bool MedliRectangle::contains(const Point& value) const
{
  return (value.X >= this->X &&
          value.X <= (this->X + this->Width) &&
          value.Y >= this->Y &&
          value.Y <= (this->Y + this->Height));
}

bool MedliRectangle::contains(const Vector2& value) const
{
  return (value.X >= this->X &&
          value.X <= (this->X + this->Width) &&
          value.Y >= this->Y &&
          value.Y <= (this->Y + this->Height));
}

bool MedliRectangle::contains(const MedliRectangle& value) const
{
  return (value.X >= this->X &&
          (value.X + value.Width) <= (this->X + this->Width) &&
          value.Y >= this->Y &&
          (value.Y + value.Height) <= (this->Y + this->Height));
}

bool MedliRectangle::operator== (const MedliRectangle& rhs) const
{
  return (this->X == rhs.X &&
          this->Y == rhs.Y &&
          this->Width == rhs.Width &&
          this->Height == rhs.Height);
}

bool MedliRectangle::operator!= (const MedliRectangle& rhs) const
{
  return !(*this == rhs);
}
