/*
 * DrawEngine.cpp
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <stdlib.h>
#include "../input/InputManager.h"
#include "../log/Logger.h"
#include "../utilities/MedliRectangleF.h"
#include "../utilities/Vector2.h"
#include "DrawBatch.h"
#include "DrawEngine.h"
#include "DrawTemplates.h"
#include "GraphicsProperties.h"

DrawEngine::DrawEngine()
{
  this->pDisplay_ = nullptr;
  this->pTargetBitmap_ = nullptr;
}

DrawEngine::~DrawEngine()
{
  if (this->pDisplay_ != nullptr)
  {
    al_destroy_bitmap(this->pTargetBitmap_);
    al_destroy_display(this->pDisplay_);
  }
}

bool DrawEngine::initialise()
{
  if (!al_init_image_addon())
  {
    ERR("Failed to initialise image addon", nullptr);
    return false;
  }

  if (!al_init_primitives_addon())
  {
    ERR("Failed to initialise primitives addon", nullptr);
    return false;
  }

  al_init_font_addon();

  if (!al_init_ttf_addon())
  {
    ERR("Failed to initialise ttf addon", nullptr);
    return false;
  }

  al_set_new_display_flags(this->getDisplayFlags());

  al_set_new_display_option(ALLEGRO_VSYNC, GraphicsProperties::getVSyncSetting(), ALLEGRO_REQUIRE);

  this->pDisplay_ = al_create_display(GraphicsProperties::getScreenWidth(),
                                      GraphicsProperties::getScreenHeight());

  if (this->pDisplay_ == nullptr)
  {
    ERR("Failed to load display", nullptr);
    return false;
  }
  else
  {
    al_set_window_title(this->pDisplay_, GraphicsProperties::getWindowTitle().c_str());

    this->pTargetBitmap_ = al_create_bitmap(GraphicsProperties::getScreenWidth(),
                                          GraphicsProperties::getScreenHeight());

    InputManager::registerEventSource(al_get_display_event_source(this->pDisplay_));
  }

  return true;
}

void DrawEngine::drawBatch(const DrawBatch& drawBatch)
{
  ALLEGRO_BITMAP* pLastBitmap = al_get_target_bitmap();
  al_set_target_bitmap(this->pTargetBitmap_);
  this->clear();

  this->setTransform(drawBatch.getPosition(),
                     drawBatch.getScale(),
                     drawBatch.getRotation());

  al_set_clipping_rectangle(0,
                            0,
                            drawBatch.getWindow().Width,
                            drawBatch.getWindow().Height);

  al_hold_bitmap_drawing(true);

  std::vector<IDrawTemplate*> drawableList = drawBatch.getDrawables();
  for (auto it : drawableList)
  {
    switch (it->getType())
    {
      case TEMPLATE_TYPE_BITMAP:
        this->drawBitmap((BitmapTemplate*)it);
        break;
      case TEMPLATE_TYPE_TEXT:
        this->drawText((TextTemplate*)it);
        break;
      case TEMPLATE_TYPE_LINE:
        this->drawLine((LineTemplate*)it);
        break;
      case TEMPLATE_TYPE_RECTANGLE:
        this->drawRectangle((RectangleTemplate*)it);
        break;
      case TEMPLATE_TYPE_FILLED_RECTANGLE:
        this->drawFilledRectangle((FilledRectangleTemplate*)it);
        break;
      case TEMPLATE_TYPE_CIRCLE:
        this->drawCircle((CircleTemplate*)it);
        break;
      case TEMPLATE_TYPE_FILLED_CIRCLE:
        this->drawFilledCircle((FilledCircleTemplate*)it);
        break;
      case TEMPLATE_TYPE_POLYGON:
        this->drawPolygon((PolygonTemplate*)it);
        break;
      default:
        DBUG("Unknown template type", nullptr);
        break;
    }
  }
  al_hold_bitmap_drawing(false);

  al_set_target_bitmap(pLastBitmap);

  al_draw_bitmap_region(this->pTargetBitmap_,
                        0,
                        0,
                        drawBatch.getWindow().Width,
                        drawBatch.getWindow().Height,
                        drawBatch.getWindow().X,
                        drawBatch.getWindow().Y,
                        0);
}

void DrawEngine::setTransform(const Vector2& position, const Vector2& scale, const float rotation)
{
  ALLEGRO_TRANSFORM transform;
  al_identity_transform(&transform);
  al_translate_transform(&transform, position.X, position.Y);
  al_scale_transform(&transform, scale.X, scale.Y);
  al_rotate_transform(&transform, rotation);
  al_use_transform(&transform);
}

void DrawEngine::drawBitmap(BitmapTemplate* pTemplate)
{
  float imageWidth = al_get_bitmap_width(pTemplate->Bitmap);
  float imageHeight = al_get_bitmap_height(pTemplate->Bitmap);
  float centreX = (imageWidth / 2.0f);
  float centreY = (imageHeight / 2.0f);

  al_draw_scaled_rotated_bitmap(pTemplate->Bitmap,
                                centreX,
                                centreY,
                                pTemplate->DestX + centreX,
                                pTemplate->DestY + centreY,
                                pTemplate->Scale,
                                pTemplate->Scale,
                                pTemplate->Rotation,
                                pTemplate->Flags);
}

void DrawEngine::drawText(TextTemplate* pTemplate)
{
  al_draw_text(pTemplate->Font,
               pTemplate->Colour,
               pTemplate->Left,
               pTemplate->Top,
               0,
               pTemplate->Text.c_str());
}

void DrawEngine::drawLine(LineTemplate* pTemplate)
{
  al_draw_line(pTemplate->X1,
               pTemplate->Y1,
               pTemplate->X2,
               pTemplate->Y2,
               pTemplate->Colour,
               pTemplate->LineWidth);
}

void DrawEngine::drawRectangle(RectangleTemplate* pTemplate)
{
  al_draw_rectangle(pTemplate->X1,
                    pTemplate->Y1,
                    pTemplate->X2,
                    pTemplate->Y2,
                    pTemplate->Colour,
                    pTemplate->LineWidth);
}

void DrawEngine::drawFilledRectangle(FilledRectangleTemplate* pTemplate)
{
  al_draw_filled_rectangle(pTemplate->X1,
                           pTemplate->Y1,
                           pTemplate->X2,
                           pTemplate->Y2,
                           pTemplate->Colour);
}

void DrawEngine::drawCircle(CircleTemplate* pTemplate)
{
  al_draw_circle(pTemplate->CentreX,
                 pTemplate->CentreY,
                 pTemplate->Radius,
                 pTemplate->Colour,
                 pTemplate->LineWidth);
}

void DrawEngine::drawFilledCircle(FilledCircleTemplate* pTemplate)
{
  al_draw_filled_circle(pTemplate->CentreX,
                        pTemplate->CentreY,
                        pTemplate->Radius,
                        pTemplate->Colour);
}

void DrawEngine::drawPolygon(PolygonTemplate* pTemplate)
{
  al_draw_prim(pTemplate->VertexList,
               nullptr,
               nullptr,
               pTemplate->Start,
               pTemplate->End,
               pTemplate->Type);
}

void DrawEngine::flip()
{
  al_flip_display();
}

void DrawEngine::clear()
{
  al_clear_to_color(GraphicsProperties::getClearColor());
}

int DrawEngine::getDisplayFlags() const
{
  int displayFlags = 0;
  displayFlags |= ALLEGRO_OPENGL;

  switch (GraphicsProperties::getWindowMode())
  {
    case WM_WINDOWED:
      displayFlags |= ALLEGRO_WINDOWED;
      break;
    case WM_FULLSCREEN:
      displayFlags |= ALLEGRO_FULLSCREEN;
      break;
    case WM_FULLSCREEN_WINDOWED:
      displayFlags |= ALLEGRO_FULLSCREEN_WINDOW;
      break;
  }
  displayFlags |= ALLEGRO_MIN_LINEAR;
  displayFlags |= ALLEGRO_MAG_LINEAR;

  return displayFlags;
}
