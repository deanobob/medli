/*
 * Vector2.cpp
 *
 *  Created on: 30 Apr 2015
 *      Author: Dean Harris
 */

#include <float.h>
#include <math.h>
#include "Vector2.h"
#include "../utilities/Utilities.h"

const Vector2 Vector2::ZERO(0.0f, 0.0f);
const Vector2 Vector2::ONE(1.0f, 1.0f);
const Vector2 Vector2::MAX(FLT_MAX, FLT_MAX);

double Vector2::distance(const Vector2& v1, const Vector2& v2)
{
  double xDist = v2.X - v1.X;
  double yDist = v2.Y - v1.Y;

  return sqrt((xDist * xDist) + (yDist * yDist));
}

float Vector2::dot(const Vector2& v1, const Vector2& v2)
{
  return (v1.X * v2.X) + (v1.Y * v2.Y);
}

Vector2 Vector2::normalise(const Vector2& value)
{
  float v = 1.0f / (float)sqrt((value.X * value.X) + (value.Y * value.Y));

  return Vector2(value.X * v, value.Y * v);
}

Vector2 Vector2::clamp(const Vector2& value, const Vector2& min, const Vector2& max)
{
  return Vector2(Utilities::clamp(value.X, min.X, max.X),
                 Utilities::clamp(value.Y, min.Y, max.Y));
}

Vector2 Vector2::minv(const Vector2& lhs, const Vector2& rhs)
{
  return Vector2(fmin(lhs.X, rhs.X), fmin(lhs.Y, rhs.Y));
}

Vector2 Vector2::maxv(const Vector2& lhs, const Vector2& rhs)
{
  return Vector2(fmax(lhs.X, rhs.X), fmax(lhs.Y, rhs.Y));
}

Vector2::Vector2() :
  Vector2(0.0f, 0.0f)
{

}

Vector2::Vector2(const Vector2& value)
{
  this->X = value.X;
  this->Y = value.Y;
}

Vector2::Vector2(const float x, const float y)
{
  this->X = x;
  this->Y = y;
}

Vector2::~Vector2()
{

}

Vector2 Vector2::perp() const
{
  //anti-clockwise winding - negate the Y value
  return Vector2(this->Y, -this->X);
}

Vector2 Vector2::operator-() const
{
  Vector2 v;
  v.X = -this->X;
  v.Y = -this->Y;
  return v;
}

Vector2 Vector2::operator+ (const Vector2& rhs) const
{
  return Vector2(this->X + rhs.X, this->Y + rhs.Y);
}

Vector2& Vector2::operator+= (const Vector2& rhs)
{
  this->X += rhs.X;
  this->Y += rhs.Y;

  return *this;
}

Vector2 Vector2::operator- (const Vector2& rhs) const
{
  return Vector2(this->X - rhs.X, this->Y - rhs.Y);
}

Vector2& Vector2::operator-= (const Vector2& rhs)
{
  this->X -= rhs.X;
  this->Y -= rhs.Y;

  return *this;
}

Vector2 Vector2::operator* (const Vector2& rhs) const
{
  return Vector2(this->X * rhs.X, this->Y * rhs.Y);
}

Vector2 Vector2::operator* (const double& rhs) const
{
  return Vector2(this->X * rhs, this->Y * rhs);
}

Vector2& Vector2::operator*= (const Vector2& rhs)
{
  this->X *= rhs.X;
  this->Y *= rhs.Y;

  return *this;
}

Vector2 Vector2::operator/ (const Vector2& rhs) const
{
  return Vector2(this->X / rhs.X, this->Y / rhs.Y);
}

Vector2& Vector2::operator/= (const Vector2& rhs)
{
  this->X /= rhs.X;
  this->Y /= rhs.Y;

  return *this;
}

bool Vector2::operator== (const Vector2& rhs) const
{
  return this->X == rhs.X && this->Y == rhs.Y;
}

bool Vector2::operator!= (const Vector2& rhs) const
{
  return !(*this == rhs);
}
