/*
 * Camera.cpp
 *
 *  Created on: 29 Apr 2015
 *      Author: Dean Harris
 */

#include <algorithm>
#include "../log/Logger.h"
#include "../utilities/MedliRectangle.h"
#include "../utilities/Vector2.h"
#include "Camera.h"
#include "GraphicsProperties.h"

Camera::Camera(const short id) :
    ID(id)
{
  this->Position = Vector2::ZERO;
  this->Rotation = 0.0f;
  this->Viewport = MedliRectangleF::EMPTY;
  this->ZIndex = 0;
  this->Zoom = Vector2::ONE;
}

Camera::~Camera()
{

}

void Camera::moveTo(const Vector2& target, const MedliRectangleF& bounds)
{
  Vector2 scaledViewport = Vector2(this->Viewport.Width / this->Zoom.X,
                                   this->Viewport.Height / this->Zoom.Y);
  Vector2 newPosition = -target + (scaledViewport * 0.5f);

  if (newPosition.X > bounds.X)
  {
    newPosition.X = bounds.X;
  }

  if (newPosition.X < this->Viewport.Width - bounds.Width)
  {
    newPosition.X = this->Viewport.Width - bounds.Width;
  }

  if (newPosition.Y > bounds.Y)
  {
    newPosition.Y = bounds.Y;
  }

  if (newPosition.Y < this->Viewport.Height - bounds.Height)
  {
    newPosition.Y = this->Viewport.Height - bounds.Height;
  }

  this->Position = newPosition ;
}
