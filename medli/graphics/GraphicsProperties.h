/*
 * GraphicsProperties.h
 *
 *  Created on: 30 Aug 2013
 *      Author: deano
 */

#ifndef GRAPHICSPROPERTIES_H_
#define GRAPHICSPROPERTIES_H_

#include <allegro5/allegro5.h>
#include <string>

enum WindowMode
{
  WM_WINDOWED,
  WM_FULLSCREEN,
  WM_FULLSCREEN_WINDOWED
};

class GraphicsProperties
{
  public:
    static WindowMode getWindowMode();
    static void setWindowMode(WindowMode windowMode);
    static void setWindowTitle(std::string windowTitle);
    static unsigned int getScreenWidth();
    static unsigned int getScreenHeight();
    static void setWindowSize(unsigned int screenWidth, unsigned int screenHeight);
    static std::string getWindowTitle();
    static void setClearColor(unsigned int r, unsigned int g, unsigned int b);
    static const ALLEGRO_COLOR& getClearColor();
    static void setVSyncEnabled(bool enabled);
    static int getVSyncSetting();

  private:
    static GraphicsProperties GP;

    WindowMode windowMode;
    unsigned int screenWidth_;
    unsigned int screenHeight_;
    std::string windowTitle_;
    ALLEGRO_COLOR clearColor_;
    bool vSyncEnabled_;

    GraphicsProperties();
    virtual ~GraphicsProperties();
};

#endif /* GRAPHICSPROPERTIES_H_ */
