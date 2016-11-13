/*
 * DrawManager.h
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#ifndef DRAWMANAGER_H_
#define DRAWMANAGER_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <queue>
#include <string>
#include "DrawBatch.h"
#include "DrawTemplates.h"

class CameraCollection;
class DrawEngine;
class MedliGame;
class ResourceManager;

struct IDrawTemplateComparator
{
    bool operator()(const IDrawTemplate* lhs, const IDrawTemplate* rhs) const
    {
      return rhs->ZIndex < lhs->ZIndex;
    }
};

class DrawManager
{
  public:
    DrawManager(MedliGame* pGame);
    virtual ~DrawManager();

    void begin(CameraCollection* pCameraCollection = nullptr);
    void draw(const std::string& textureId, float left, float top, float rotation = 0.0f,
        float scale = 1.0f, int flags = 0, float zIndex = 0.0f);
    void drawText(const std::string& text, const std::string& fontName, unsigned int fontSize,
        float left, float top, const ALLEGRO_COLOR* pColour, float zIndex = 0.0f);
    void drawLine(float x1, float y1, float x2, float y2, const ALLEGRO_COLOR* pColour,
        float lineWidth, float zIndex = 0.0f);
    void drawRectangle(float left, float top, float width, float height,
        const ALLEGRO_COLOR* pColour, short lineWidth, float zIndex = 0.0f);
    void drawFilledRectangle(float left, float top, float width, float height,
        const ALLEGRO_COLOR* pColour, float zIndex = 0.0f);
    void drawCircle(float centreX, float centreY, float radius, const ALLEGRO_COLOR* pColour,
        short lineWidth, float zIndex = 0.0f);
    void drawFilledCircle(float centreX, float centreY, float radius, const ALLEGRO_COLOR* pColour,
        float zIndex = 0.0f);
    void drawPolygon(const ALLEGRO_VERTEX* pVertex, unsigned int start, unsigned int end,
        int type = ALLEGRO_PRIM_LINE_LOOP, float zIndex = 0.0f);
    void drawFilledPolygon(const ALLEGRO_VERTEX* pVertex, unsigned int start, unsigned int end,
        float zIndex = 0.0f);
    void end();

    void setFixedHeight(unsigned int height);
    float getDisplayScale() const;

  private:
    float scale_;
    CameraCollection* pCameraCollection_;
    DrawEngine* pDrawEngine_;
    ResourceManager* pResourceManager_;
    std::priority_queue<IDrawTemplate, std::vector<IDrawTemplate*>, IDrawTemplateComparator> drawableQueue_;

    void drawQueued(DrawBatch& drawBatch) const;
};

#endif /* DRAWMANAGER_H_ */
