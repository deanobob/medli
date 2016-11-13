/*
 * Vector2.h
 *
 *  Created on: 30 Apr 2015
 *      Author: Dean Harris
 */

#ifndef VECTOR2_H_
#define VECTOR2_H_

class Vector2
{
  public:
    static const Vector2 ZERO;
    static const Vector2 ONE;
    static const Vector2 MAX;

    float X;
    float Y;

    static double distance(const Vector2& v1, const Vector2& v2);
    static float dot(const Vector2& v1, const Vector2& v2);
    static Vector2 normalise(const Vector2& value);
    static Vector2 clamp(const Vector2& value, const Vector2& min, const Vector2& max);
    static Vector2 minv(const Vector2& lhs, const Vector2& rhs);
    static Vector2 maxv(const Vector2& lhs, const Vector2& rhs);

    Vector2();
    Vector2(const Vector2& value);
    Vector2(const float x, const float y);
    virtual ~Vector2();

    Vector2 perp() const;

    Vector2 operator-() const;
    Vector2 operator+ (const Vector2& rhs) const;
    Vector2& operator+= (const Vector2& rhs);
    Vector2 operator- (const Vector2& rhs) const;
    Vector2& operator-= (const Vector2& rhs);
    Vector2 operator* (const Vector2& rhs) const;
    Vector2 operator* (const double& rhs) const;
    Vector2& operator*= (const Vector2& rhs);
    Vector2 operator/ (const Vector2& rhs) const;
    Vector2& operator/= (const Vector2& rhs);
    bool operator== (const Vector2& rhs) const;
    bool operator!= (const Vector2& rhs) const;
};

#endif /* VECTOR2_H_ */
