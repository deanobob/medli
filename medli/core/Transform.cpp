/*
 * Transform.cpp
 *
 *  Created on: 18 Nov 2016
 *      Author: deano
 */

#include <math.h>
#include "../utilities/MathUtilities.h"
#include "Transform.h"

Vector2 Transform::rotateAround(const Vector2& centre, const double& angle, Vector2 point)
{
  float s = sin(angle);
  float c = cos(angle);

  // translate point back to origin
  point.X -= centre.X;
  point.Y -= centre.Y;

  // rotate point
  float xnew = point.X * c - point.Y * s;
  float ynew = point.X * s + point.Y * c;

  // translate point back
  point.X = xnew + centre.X;
  point.Y = ynew + centre.Y;

  return point;
}

Transform::Transform()
{
  this->pParent_ = nullptr;
  this->position = Vector2::ZERO;
  this->rotation = 0.0f;
}

Transform::~Transform()
{

}

void Transform::setParent(Transform* pTransform)
{
  this->pParent_ = pTransform;
}

Transform* Transform::getParent() const
{
  return this->pParent_;
}

void Transform::move(const Vector2& value)
{
  this->position += value;
}

void Transform::rotate(double value, Angle::type unit)
{
  if (unit == Angle::Degrees)
  {
    value = MathUtilities::degreesToRadian(value);
  }

  this->rotation += value;
}

void Transform::setPosition(const Vector2& position)
{
  this->position = position;
}

const Vector2 Transform::getPosition() const
{
  Vector2 value = this->position;

  if (this->pParent_ != nullptr)
  {
    Vector2 parentPosition = this->pParent_->getPosition();
    value = Transform::rotateAround(parentPosition, this->pParent_->getRotation(), parentPosition + this->position);
  }

  return value;
}

const Vector2 Transform::getLocalPosition() const
{
  return this->position;
}

void Transform::setRotation(const double& rotation,  Angle::type unit)
{
  if (unit == Angle::Radian)
  {
    this->rotation = rotation;
  }
  else
  {
    this->rotation = MathUtilities::degreesToRadian(rotation);
  }
}

const double Transform::getRotation() const
{
  if (this->pParent_ != nullptr)
  {
    return this->getParent()->getRotation() + this->rotation;
  }

  return this->rotation;
}

Vector2 Transform::forward() const
{
  const double rotation = this->getRotation();
  return Vector2(cos(rotation), sin(rotation));
}

void Transform::lookAt(const Vector2& target)
{
  this->rotation = atan2(target.Y - this->position.Y, target.X - this->position.X);
}

void Transform::addChild(Transform* pTransform)
{
  this->childList_.push_back(pTransform);
  pTransform->setParent(this);
}

const std::list<Transform*>& Transform::getChildren() const
{
  return this->childList_;
}
