/*
 * MouseState.h
 *
 *  Created on: 4 May 2014
 *      Author: deano
 */

#ifndef MOUSESTATE_H_
#define MOUSESTATE_H_

#include <map>

static const int ALLEGRO_MOUSE_BUTTON_LEFT  = 1;
static const int ALLEGRO_MOUSE_BUTTON_RIGHT = 2;

class MouseState
{
  public:
    MouseState();
    virtual ~MouseState();

    void setButtonState(unsigned int button,
                        bool pressed);
    bool isButtonPressed(unsigned int button);
    void setPositionX(int x);
    int getPositionX() const;
    void setPositionY(int y);
    int getPositionY() const;
    void setWheelX(int x);
    int getWheelX() const;
    void setWheelY(int y);
    int getWheelY() const;

  private:
    std::map<int, bool> buttonState_;
    int positionX_;
    int positionY_;
    int wheelX_;
    int wheelY_;
};

#endif /* MOUSESTATE_H_ */
