/*
 * Point.h
 *
 *  Created on: 1 May 2015
 *      Author: Dean Harris
 */

#ifndef POINT_H_
#define POINT_H_

class Point
{
  public:
    static const Point ZERO;
    static const Point ONE;

    int X;
    int Y;

    Point();
    Point(const Point& value);
    Point(const int x, const int y);
    virtual ~Point();

    Point operator+ (const Point& rhs) const;
    Point& operator+= (const Point& rhs);
    Point operator- (const Point& rhs) const;
    Point& operator-= (const Point& rhs);
    Point operator* (const Point& rhs) const;
    Point& operator*= (const Point& rhs);
    Point operator/ (const Point& rhs) const;
    Point& operator/= (const Point& rhs);
    bool operator== (const Point& rhs) const;
    bool operator!= (const Point& rhs) const;
};

#endif /* POINT_H_ */
