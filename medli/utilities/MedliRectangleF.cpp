/*
 * DeanoRectangleF.cpp
 *
 *  Created on: 30 Apr 2015
 *      Author: Dean Harris
 */

#include "../utilities/MedliRectangleF.h"
#include "Point.h"
#include "Vector2.h"

const MedliRectangleF MedliRectangleF::EMPTY;

MedliRectangleF::MedliRectangleF() :
  MedliRectangleF(0.0f, 0.0f, 0.0f, 0.0f)
{

}

MedliRectangleF::MedliRectangleF(float x, float y, float width, float height)
{
  this->X = x;
  this->Y = y;
  this->Width = width;
  this->Height = height;
}

MedliRectangleF::~MedliRectangleF()
{

}

float MedliRectangleF::getLeft() const
{
  return this->X;
}

float MedliRectangleF::getRight() const
{
  return this->X + this->Width;
}

float MedliRectangleF::getTop() const
{
  return this->Y;
}

float MedliRectangleF::getBottom() const
{
  return this->Y + this->Height;
}

const Vector2 MedliRectangleF::getCenter() const
{
  return Vector2(this->X + (this->Width / 2),
                 this->Y + (this->Height / 2));
}

bool MedliRectangleF::contains(float x, float y) const
{
  return (x >= this->X &&
          x <= (this->X + this->Width) &&
          y >= this->Y &&
          y <= (this->Y + this->Height));
}

bool MedliRectangleF::contains(const Point& value) const
{
  return (value.X >= this->X &&
          value.X <= (this->X + this->Width) &&
          value.Y >= this->Y &&
          value.Y <= (this->Y + this->Height));
}

bool MedliRectangleF::contains(const Vector2& value) const
{
  return (value.X >= this->X &&
          value.X <= (this->X + this->Width) &&
          value.Y >= this->Y &&
          value.Y <= (this->Y + this->Height));
}

bool MedliRectangleF::contains(const MedliRectangleF& value) const
{
  return (value.X >= this->X &&
          (value.X + value.Width) <= (this->X + this->Width) &&
          value.Y >= this->Y &&
          (value.Y + value.Height) <= (this->Y + this->Height));
}

bool MedliRectangleF::operator== (const MedliRectangleF& rhs) const
{
  return (this->X == rhs.X &&
          this->Y == rhs.Y &&
          this->Width == rhs.Width &&
          this->Height == rhs.Height);
}

bool MedliRectangleF::operator!= (const MedliRectangleF& rhs) const
{
  return !(*this == rhs);
}

MedliRectangleF MedliRectangleF::operator* (const MedliRectangleF& rhs) const
{
  return MedliRectangleF(this->X * rhs.X,
                         this->Y * rhs.Y,
                         this->Width * rhs.Width,
                         this->Height * rhs.Height);
}

MedliRectangleF MedliRectangleF::operator* (const double& rhs) const
{
  return MedliRectangleF(this->X * rhs,
                         this->Y * rhs,
                         this->Width * rhs,
                         this->Height * rhs);
}
