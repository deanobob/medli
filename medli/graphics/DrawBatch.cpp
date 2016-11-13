/*
 * DrawBatch.cpp
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#include "Camera.h"
#include "DrawBatch.h"
#include "DrawTemplates.h"
#include "GraphicsProperties.h"

DrawBatch::DrawBatch(const Camera* pCamera, float scale)
{
  if (pCamera != nullptr)
  {
    this->window_ = pCamera->Viewport * scale;
    this->position_ = pCamera->Position;
    this->scale_ = pCamera->Zoom * scale;
    this->rotation_ = pCamera->Rotation;
  }
  else
  {
    this->window_ = MedliRectangleF(0.0f,
                                    0.0f,
                                    GraphicsProperties::getScreenWidth() * scale,
                                    GraphicsProperties::getScreenHeight() * scale);
    this->position_ = Vector2::ZERO;
    this->scale_ = Vector2::ONE * scale;
    this->rotation_ = 0.0f;
  }
}

DrawBatch::~DrawBatch()
{

}

void DrawBatch::add(IDrawTemplate* pDrawable)
{
  this->drawableList_.push_back(pDrawable);
}

const std::vector<IDrawTemplate*> DrawBatch::getDrawables() const
{
  return this->drawableList_;
}

const float DrawBatch::getRotation() const
{
  return this->rotation_;
}

const Vector2& DrawBatch::getScale() const
{
  return this->scale_;
}

const Vector2& DrawBatch::getPosition() const
{
  return this->position_;
}

const MedliRectangleF& DrawBatch::getWindow() const
{
  return this->window_;
}
