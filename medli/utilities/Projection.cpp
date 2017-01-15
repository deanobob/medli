/*
 * Projection.cpp
 *
 *  Created on: 10 May 2015
 *      Author: Dean Harris
 */

#include <algorithm>
#include "Projection.h"

Projection::Projection(double min, double max) :
    min(min), max(max)
{

}

Projection::~Projection()
{

}

bool Projection::isOverlapping(const Projection& other)
{
  return !(this->min > other.max || other.min > this->max);
}

float Projection::getOverlap(const Projection& other)
{
  float start = std::max(this->min, other.min);
  float end = std::min(this->max, other.max);
  return end - start;
}

bool Projection::contains(const Projection& other)
{
  return other.min > this->min && other.max < this->max;
}
