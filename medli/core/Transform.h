/*
 * Transform.h
 *
 *  Created on: 18 Nov 2016
 *      Author: deano
 */

#ifndef MEDLI_CORE_TRANSFORM_H_
#define MEDLI_CORE_TRANSFORM_H_

#include <list>
#include "../utilities/Vector2.h"

namespace Angle
{
  enum type : short
  {
    Degrees,
    Radian
  };
}

class Transform
{
  public:
    static Vector2 rotateAround(const Vector2& origin, const double& angle, Vector2 point);

    Transform();
    virtual ~Transform();

    void move(const Vector2& value);
    void rotate(double value, Angle::type unit = Angle::Radian);
    void setParent(Transform* pTransform);
    Transform* getParent() const;
    void setPosition(const Vector2& position);
    const Vector2 getPosition() const;
    const Vector2 getLocalPosition() const;
    void setRotation(const double& rotation, Angle::type unit = Angle::Radian);
    const double getRotation() const;
    Vector2 forward() const;
    void lookAt(const Vector2& target);
    void addChild(Transform* pTransform);
    const std::list<Transform*>& getChildren() const;

  private:
    Transform* pParent_;
    Vector2 position;
    double rotation;
    std::list<Transform*> childList_;
};

#endif /* MEDLI_CORE_TRANSFORM_H_ */
