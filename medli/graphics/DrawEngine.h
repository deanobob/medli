/*
 * DrawEngine.h
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#ifndef DRAWENGINE_H_
#define DRAWENGINE_H_

#include <string>

class ALLEGRO_BITMAP;
class ALLEGRO_DISPLAY;
class BitmapTemplate;
class CircleTemplate;
class MedliRectangle;
class DeanoTexture;
class DrawBatch;
class FilledCircleTemplate;
class FilledRectangleTemplate;
class LineTemplate;
class PolygonTemplate;
class RectangleTemplate;
class TextTemplate;
class Vector2;

class DrawEngine
{
  public:
    DrawEngine();
    virtual ~DrawEngine();

    bool initialise();
    void drawBatch(const DrawBatch& drawBatch);
    void drawBitmap(BitmapTemplate* pTemplate);
    void drawText(TextTemplate* pTemplate);
    void drawLine(LineTemplate* pTemplate);
    void drawRectangle(RectangleTemplate* pTemplate);
    void drawFilledRectangle(FilledRectangleTemplate* pTemplate);
    void drawCircle(CircleTemplate* pTemplate);
    void drawFilledCircle(FilledCircleTemplate* pTemplate);
    void drawPolygon(PolygonTemplate* pTemplate);
    void flip();
    void clear();

    int getDisplayFlags() const;

  private:
    ALLEGRO_DISPLAY* pDisplay_;
    ALLEGRO_BITMAP* pTargetBitmap_;

    void setTransform(const Vector2& target, const Vector2& scale, const float rotation);
};

#endif /* DRAWENGINE_H_ */
