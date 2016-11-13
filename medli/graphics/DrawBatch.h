/*
 * DrawBatch.h
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#ifndef DRAWBATCH_H_
#define DRAWBATCH_H_

#include <stdlib.h>
#include <vector>
#include "../utilities/MedliRectangleF.h"
#include "../utilities/Vector2.h"

class Camera;
class IDrawTemplate;

class DrawBatch
{
  public:
    DrawBatch(const Camera* pCamera = nullptr, float scale = 1.0f);
    virtual ~DrawBatch();

    void add(IDrawTemplate* pDrawable);
    const std::vector<IDrawTemplate*> getDrawables() const;
    const float getRotation() const;
    const Vector2& getScale() const;
    const Vector2& getPosition() const;
    const MedliRectangleF& getWindow() const;

  private:
    std::vector<IDrawTemplate*> drawableList_;
    float rotation_;
    Vector2 scale_;
    Vector2 position_;
    MedliRectangleF window_;
};

#endif /* DRAWBATCH_H_ */
