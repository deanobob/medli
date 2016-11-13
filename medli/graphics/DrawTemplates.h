/*
 * DrawTemplates.h
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#ifndef DRAWTEMPLATES_H_
#define DRAWTEMPLATES_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <string>

enum TemplateType
{
  TEMPLATE_TYPE_BITMAP,
  TEMPLATE_TYPE_TEXT,
  TEMPLATE_TYPE_LINE,
  TEMPLATE_TYPE_RECTANGLE,
  TEMPLATE_TYPE_FILLED_RECTANGLE,
  TEMPLATE_TYPE_CIRCLE,
  TEMPLATE_TYPE_FILLED_CIRCLE,
  TEMPLATE_TYPE_POLYGON
};

class IDrawTemplate
{
  public:
    const float ZIndex;

    IDrawTemplate(float zIndex) :
      ZIndex(zIndex) {};
    virtual ~IDrawTemplate() {};
    virtual TemplateType getType() const = 0;
};

class BitmapTemplate :
    public IDrawTemplate
{
  public:
    ALLEGRO_BITMAP* Bitmap;
    const float DestX;
    const float DestY;
    const float Scale;
    const float Rotation;
    const int Flags;

    BitmapTemplate(ALLEGRO_BITMAP* pBitmap, float destX, float destY, float scale, float rotation,
        int flags, float zIndex = 0.0f) :
          IDrawTemplate(zIndex), Bitmap(pBitmap), DestX(destX), DestY(destY), Scale(scale),
          Rotation(rotation), Flags(flags)
    {
      
    }

    virtual ~BitmapTemplate()
    {

    }

    TemplateType getType() const override
    {
      return TEMPLATE_TYPE_BITMAP;
    }
};


class TextTemplate :
    public IDrawTemplate
{
  public:
    const std::string Text;
    const ALLEGRO_FONT* Font;
    const float Left;
    const float Top;
    const ALLEGRO_COLOR Colour;

    TextTemplate(const std::string text, ALLEGRO_FONT* font, float left, float top,
        ALLEGRO_COLOR colour, float zIndex = 0.0f) :
          IDrawTemplate(zIndex), Text(text), Font(font), Left(left), Top(top), Colour(colour)
    {

    }

    virtual ~TextTemplate()
    {

    }

    TemplateType getType() const override
    {
      return TEMPLATE_TYPE_TEXT;
    }
};


class LineTemplate :
    public IDrawTemplate
{
  public:
    const float X1;
    const float Y1;
    const float X2;
    const float Y2;
    const ALLEGRO_COLOR Colour;
    const int LineWidth;

    LineTemplate(float x1, float y1, float x2, float y2, ALLEGRO_COLOR colour, int lineWidth,
        float zIndex = 0.0f) :
      IDrawTemplate(zIndex), X1(x1), Y1(y1), X2(x2), Y2(y2), Colour(colour), LineWidth(lineWidth)
    {

    }

    TemplateType getType() const override
    {
      return TEMPLATE_TYPE_LINE;
    }
};


class RectangleTemplate :
    public IDrawTemplate
{
  public:
    const float X1;
    const float Y1;
    const float X2;
    const float Y2;
    const ALLEGRO_COLOR Colour;
    const int LineWidth;

    RectangleTemplate(float x1, float y1, float x2, float y2, ALLEGRO_COLOR colour, int lineWidth,
        float zIndex = 0.0f) :
          IDrawTemplate(zIndex), X1(x1), Y1(y1), X2(x2), Y2(y2), Colour(colour),
          LineWidth(lineWidth)
    {

    }

    virtual ~RectangleTemplate()
    {

    }

    TemplateType getType() const override
    {
      return TEMPLATE_TYPE_RECTANGLE;
    }
};


class FilledRectangleTemplate :
    public IDrawTemplate
{
  public:
    const float X1;
    const float Y1;
    const float X2;
    const float Y2;
    const ALLEGRO_COLOR Colour;

    FilledRectangleTemplate(float x1, float y1, float x2, float y2, ALLEGRO_COLOR colour,
        float zIndex = 0.0f) :
          IDrawTemplate(zIndex), X1(x1), Y1(y1), X2(x2), Y2(y2), Colour(colour)
    {

    }

    virtual ~FilledRectangleTemplate()
    {

    }

    TemplateType getType() const override
    {
      return TEMPLATE_TYPE_FILLED_RECTANGLE;
    }
};


class CircleTemplate :
    public IDrawTemplate
{
  public:
    const float CentreX;
    const float CentreY;
    const float Radius;
    const ALLEGRO_COLOR Colour;
    const short LineWidth;

    CircleTemplate(float centreX, float centreY, float radius, ALLEGRO_COLOR colour,
        short lineWidth, float zIndex = 0.0f) :
          IDrawTemplate(zIndex), CentreX(centreX), CentreY(centreY), Radius(radius),
          Colour(colour), LineWidth(lineWidth)
    {

    }

    virtual ~CircleTemplate()
    {

    }

    TemplateType getType() const override
    {
      return TEMPLATE_TYPE_CIRCLE;
    }
};


class FilledCircleTemplate :
    public IDrawTemplate
{
  public:
    const float CentreX;
    const float CentreY;
    const float Radius;
    const ALLEGRO_COLOR Colour;

    FilledCircleTemplate(float centreX, float centreY, float radius, ALLEGRO_COLOR colour,
        float zIndex = 0.0f) :
          IDrawTemplate(zIndex), CentreX(centreX), CentreY(centreY), Radius(radius), Colour(colour)
    {

    }

    virtual ~FilledCircleTemplate()
    {

    }

    TemplateType getType() const override
    {
      return TEMPLATE_TYPE_FILLED_CIRCLE;
    }
};


class PolygonTemplate :
    public IDrawTemplate
{
  public:
    const ALLEGRO_VERTEX* VertexList;
    const unsigned int Start;
    const unsigned int End;
    const unsigned int Type;

    PolygonTemplate(const ALLEGRO_VERTEX* pVertexList, unsigned int start, unsigned int end,
        unsigned int type, float zIndex = 0.0f) :
          IDrawTemplate(zIndex), VertexList(pVertexList), Start(start), End(end), Type(type)
    {

    }

    virtual ~PolygonTemplate()
    {

    }

    TemplateType getType() const override
    {
      return TEMPLATE_TYPE_POLYGON;
    }
};


class FilledPolygonTemplate :
    public PolygonTemplate
{
  public:
    FilledPolygonTemplate(const ALLEGRO_VERTEX* pVertexList, unsigned int start, unsigned int end,
        float zIndex) :
          PolygonTemplate(pVertexList, start, end, ALLEGRO_PRIM_TRIANGLE_STRIP, zIndex = 0.0f)
    {

    }

    virtual ~FilledPolygonTemplate()
    {

    }
};

#endif /* DRAWTEMPLATES_H_ */
