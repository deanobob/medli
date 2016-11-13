/*
 * Camera.h
 *
 *  Created on: 29 Apr 2015
 *      Author: Dean Harris
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "../utilities/MedliRectangleF.h"
#include "../utilities/Vector2.h"

class Camera
{
  public:
    const short ID;
    Vector2 Position;
    Vector2 Zoom;
    float Rotation;
    MedliRectangleF Viewport;
    float ZIndex;

    Camera(const short id);
    virtual ~Camera();

    void moveTo(const Vector2& target, const MedliRectangleF& bounds = MedliRectangleF::EMPTY);
};

#endif /* CAMERA_H_ */
