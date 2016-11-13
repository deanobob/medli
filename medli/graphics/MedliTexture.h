/*
 * MedliTexture.h
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#ifndef MEDLITEXTURE_H_
#define MEDLITEXTURE_H_

#include <allegro5/allegro.h>

class MedliTexture
{
  public:
    MedliTexture(ALLEGRO_BITMAP* pBitmap, int left, int top, int width, int height);
    virtual ~MedliTexture();

    const ALLEGRO_BITMAP* getBitmap() const;
    const int getLeft() const;
    const int getTop() const;
    const int getWidth() const;
    const int getHeight() const;

  private:
    ALLEGRO_BITMAP* pBitmap_;
    const int left_;
    const int top_;
    const int width_;
    const int height_;
};

#endif /* MEDLITEXTURE_H_ */
