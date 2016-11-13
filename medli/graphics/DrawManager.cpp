/*
 * DrawManager.cpp
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#include <stdlib.h>
#include "../log/Logger.h"
#include "../MedliGame.h"
#include "CameraCollection.h"
#include "DrawBatch.h"
#include "DrawEngine.h"
#include "DrawManager.h"
#include "DrawTemplates.h"
#include "GraphicsProperties.h"
#include "MedliTexture.h"
#include "ResourceManager.h"

DrawManager::DrawManager(MedliGame* pGame)
{
  this->scale_ = 1.0f;
  this->pCameraCollection_ = nullptr;
  this->pDrawEngine_ = pGame->pDrawEngine;
  this->pResourceManager_ = pGame->pResourceManager;
}

DrawManager::~DrawManager()
{

}

void DrawManager::begin(CameraCollection* pCameraCollection)
{
  this->pCameraCollection_ = pCameraCollection;
}

void DrawManager::draw(const std::string& textureId, float left, float top, float rotation,
    float scale, int flags, float zIndex)
{
  ALLEGRO_BITMAP* pBitmap = this->pResourceManager_->getBitmap(textureId);
  if (pBitmap != nullptr)
  {
    this->drawableQueue_.push(
        new BitmapTemplate(pBitmap, left, top, scale, rotation, flags, zIndex));
  }
}

void DrawManager::drawText(const std::string& text, const std::string& fontName,
    unsigned int fontSize, float left, float top, const ALLEGRO_COLOR* pColour, float zIndex)
{
  ALLEGRO_FONT* pFont = this->pResourceManager_->getFont(fontName, fontSize);
  this->drawableQueue_.push(
      new TextTemplate(text, pFont, left, top, *pColour, zIndex));
}

void DrawManager::drawLine(float x1, float y1, float x2, float y2, const ALLEGRO_COLOR* pColour,
    float lineWidth, float zIndex)
{
  this->drawableQueue_.push(
      new LineTemplate(x1 * this->scale_, y1 * this->scale_, x2 * this->scale_, y2 * this->scale_,
          *pColour, lineWidth * this->scale_, zIndex));
}

void DrawManager::drawRectangle(float left, float top, float width, float height,
    const ALLEGRO_COLOR* pColour, short lineWidth, float zIndex)
{
  this->drawableQueue_.push(
      new RectangleTemplate(left, top, left + width, top + height, *pColour, lineWidth, zIndex));
}

void DrawManager::drawFilledRectangle(float left, float top, float width, float height,
    const ALLEGRO_COLOR* pColour, float zIndex)
{
  this->drawableQueue_.push(
      new FilledRectangleTemplate(left, top, left + width, top + height, *pColour, zIndex));
}

void DrawManager::drawCircle(float centreX, float centreY, float radius,
    const ALLEGRO_COLOR* pColour, short lineWidth, float zIndex)
{
  this->drawableQueue_.push(
      new CircleTemplate(centreX * this->scale_, centreY * this->scale_, radius * this->scale_,
          *pColour, lineWidth * this->scale_, zIndex));
}

void DrawManager::drawFilledCircle(float centreX, float centreY, float radius,
    const ALLEGRO_COLOR* pColour, float zIndex)
{
  this->drawableQueue_.push(
      new FilledCircleTemplate(centreX * this->scale_, centreY * this->scale_,
          radius * this->scale_, *pColour, zIndex));
}

void DrawManager::drawPolygon(const ALLEGRO_VERTEX* pVertex, unsigned int start, unsigned int end,
    int type, float zIndex)
{
  this->drawableQueue_.push(
      new PolygonTemplate(pVertex, start, end, type, zIndex));
}

void DrawManager::drawFilledPolygon(const ALLEGRO_VERTEX* pVertex, unsigned int start,
    unsigned int end, float zIndex)
{
  this->drawableQueue_.push(
      new FilledPolygonTemplate(pVertex, start, end, zIndex));
}

void DrawManager::end()
{
  if (this->pCameraCollection_ != nullptr &&
      !this->pCameraCollection_->empty())
  {
    auto cameraQueue = this->pCameraCollection_->getQueue();
    while (!cameraQueue.empty())
    {
      Camera* pCamera = cameraQueue.top();
      DrawBatch drawBatch(pCamera, this->scale_);
      this->drawQueued(drawBatch);
      this->pDrawEngine_->drawBatch(drawBatch);
      cameraQueue.pop();
    }
  }
  else
  {
    DrawBatch drawBatch(nullptr, this->scale_);
    this->drawQueued(drawBatch);
    this->pDrawEngine_->drawBatch(drawBatch);
  }

  while (!this->drawableQueue_.empty())
  {
    delete this->drawableQueue_.top();
    this->drawableQueue_.pop();
  }

  this->pCameraCollection_ = nullptr;
}

void DrawManager::setFixedHeight(unsigned int height)
{
  this->scale_ = (1.0f / height) * GraphicsProperties::getScreenHeight();
}

float DrawManager::getDisplayScale() const
{
  return this->scale_;
}

void DrawManager::drawQueued(DrawBatch& drawBatch) const
{
  auto tempQueue = this->drawableQueue_;
  while (!tempQueue.empty())
  {
    IDrawTemplate* pTemplate = tempQueue.top();
    drawBatch.add(pTemplate);
    tempQueue.pop();
  }
}
