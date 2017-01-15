/*
 * PolygonShape.cpp
 *
 *  Created on: 10 May 2015
 *      Author: Dean Harris
 */

#include "../log/Logger.h"
#include "Projection.h"
#include "PolygonShape.h"
#include "Vector2.h"

PolygonShape::PolygonShape()
{
  this->minVector_ = Vector2::ZERO;
  this->maxVector_ = Vector2::ZERO;
}

PolygonShape::~PolygonShape()
{

}

Shapes::Enum PolygonShape::getType() const
{
  return Shapes::Polygon;
}

Vector2 PolygonShape::getPosition() const
{
  return this->minVector_;
}

int PolygonShape::getWidth() const
{
  return this->maxVector_.X - this->minVector_.X;
}

int PolygonShape::getHeight() const
{
  return this->maxVector_.Y - this->minVector_.Y;
}


void PolygonShape::addVertex(const Vector2& value)
{
  if (this->vertexList_.empty())
  {
    this->minVector_ = value;
    this->maxVector_ = value;
  }
  else
  {
    this->minVector_.X = std::min(this->minVector_.X, value.X);
    this->minVector_.Y = std::min(this->minVector_.Y, value.Y);
    this->maxVector_.X = std::max(this->maxVector_.X, value.X);
    this->maxVector_.Y = std::max(this->maxVector_.Y, value.Y);
  }

  this->vertexList_.push_back(value);
}

const std::vector<Vector2>& PolygonShape::getVertices() const
{
  return this->vertexList_;
}

int PolygonShape::getVertexCount() const
{
  return this->vertexList_.size();
}

//TODO: calculate this only when necessary
const std::vector<Vector2> PolygonShape::getAxes() const
{
  std::vector<Vector2> axes;
  for (unsigned int i = 0; i < this->vertexList_.size(); i++)
  {
    Vector2 p1 = this->vertexList_.at(i);
    Vector2 p2 = this->vertexList_.at(i + 1 == this->vertexList_.size() ? 0 : i + 1);
    Vector2 edge = p1 - p2;
    Vector2 normal = edge.perp();

    axes.push_back(Vector2::normalise(normal));
  }

  return axes;
}

Projection PolygonShape::project(const Vector2& position, const Vector2& axis) const
{
  if (this->vertexList_.size() <= 0) return Projection(0, 0);

  double min = Vector2::dot(axis, position + this->vertexList_.at(0));
  double max = min;

  for (unsigned int i = 1; i < this->vertexList_.size(); i++)
  {
    double p = Vector2::dot(axis, position + this->vertexList_.at(i));
    if (p < min)
    {
      min = p;
    }
    else if (p > max)
    {
      max = p;
    }
  }

  return Projection(min, max);
}

void PolygonShape::transform(const Vector2& axis)
{
  for (unsigned int i = 0; i < this->vertexList_.size(); i++)
  {
    this->vertexList_.at(i) += axis;
  }
}
