/*
 * MedliTexture.cpp
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#include <allegro5/allegro.h>
#include "MedliTexture.h"

MedliTexture::MedliTexture(ALLEGRO_BITMAP* pBitmap, int left, int top, int width, int height) :
  pBitmap_(pBitmap), left_(left), top_(top), width_(width), height_(height)
{

}

MedliTexture::~MedliTexture()
{
  al_destroy_bitmap(this->pBitmap_);
}

const ALLEGRO_BITMAP* MedliTexture::getBitmap() const
{
  return this->pBitmap_;
}

const int MedliTexture::getLeft() const
{
  return this->left_;
}

const int MedliTexture::getTop() const
{
  return this->top_;
}

const int MedliTexture::getWidth() const
{
  return this->width_;
}

const int MedliTexture::getHeight() const
{
  return this->height_;
}
