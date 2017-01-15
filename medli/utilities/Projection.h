/*
 * Projection.h
 *
 *  Created on: 10 May 2015
 *      Author: Dean Harris
 */

#ifndef PROJECTION_H_
#define PROJECTION_H_

class Projection
{
  public:
    const double min;
    const double max;

    Projection(double min, double max);
    virtual ~Projection();

    bool isOverlapping(const Projection& value);
    float getOverlap(const Projection& other);
    bool contains(const Projection& other);
};

#endif /* PROJECTION_H_ */
