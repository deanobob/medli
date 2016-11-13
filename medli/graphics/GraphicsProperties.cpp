/*
 * GraphicsProperties.cpp
 *
 *  Created on: 30 Aug 2013
 *      Author: deano
 */

#include "GraphicsProperties.h"

static const std::string DEFAULT_TITLE = "";
static const int DEFAULT_SCREEN_WIDTH = 1024;
static const int DEFAULT_SCREEN_HEIGHT = 768;
static const int VSYNC_ON = 1;
static const int VSYNC_OFF = 2;

GraphicsProperties GraphicsProperties::GP;

WindowMode GraphicsProperties::getWindowMode()
{
  return GP.windowMode;
}

void GraphicsProperties::setWindowMode(WindowMode windowMode)
{
  GP.windowMode = windowMode;
}

unsigned int GraphicsProperties::getScreenWidth()
{
  return GP.screenWidth_;
}

unsigned int GraphicsProperties::getScreenHeight()
{
  return GP.screenHeight_;
}

void GraphicsProperties::setWindowSize(unsigned int screenWidth,
                                       unsigned int screenHeight)
{
  GP.screenWidth_ = screenWidth;
  GP.screenHeight_ = screenHeight;
}

void GraphicsProperties::setWindowTitle(std::string windowTitle)
{
  GP.windowTitle_ = windowTitle;
}

std::string GraphicsProperties::getWindowTitle()
{
  return GP.windowTitle_;
}

void GraphicsProperties::setClearColor(unsigned int r,
                                       unsigned int g,
                                       unsigned int b)
{
  ALLEGRO_COLOR clearColor;
  clearColor.r = r;
  clearColor.g = g;
  clearColor.b = b;
  GP.clearColor_ = clearColor;
}

const ALLEGRO_COLOR& GraphicsProperties::getClearColor()
{
  return GP.clearColor_;
}

void GraphicsProperties::setVSyncEnabled(bool enabled)
{
  GP.vSyncEnabled_ = enabled;
}

int GraphicsProperties::getVSyncSetting()
{
  return GP.vSyncEnabled_ ? VSYNC_ON : VSYNC_OFF;
}

GraphicsProperties::GraphicsProperties()
{
  GP.windowTitle_ = DEFAULT_TITLE;
  GP.screenWidth_ = DEFAULT_SCREEN_WIDTH;
  GP.screenHeight_ = DEFAULT_SCREEN_HEIGHT;
  GP.windowMode = WM_WINDOWED;
  GP.vSyncEnabled_ = false;
}

GraphicsProperties::~GraphicsProperties()
{

}
