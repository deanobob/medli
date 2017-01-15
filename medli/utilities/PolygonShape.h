/*
 * PolygonShape.h
 *
 *  Created on: 10 May 2015
 *      Author: Dean Harris
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <vector>
#include "IShape.h"
#include "Vector2.h"

class Projection;

class PolygonShape :
    public IShape
{
  public:
    PolygonShape();
    virtual ~PolygonShape();

    Shapes::Enum getType() const;

    Vector2 getPosition() const;
    int getWidth() const;
    int getHeight() const;

    void addVertex(const Vector2& value);
    const std::vector<Vector2>& getVertices() const;
    int getVertexCount() const;
    const std::vector<Vector2> getAxes() const;
    Projection project(const Vector2& position, const Vector2& axis) const;
    void transform(const Vector2& axis);

  private:
    Vector2 minVector_;
    Vector2 maxVector_;
    std::vector<Vector2> axesList_;
    std::vector<Vector2> vertexList_;

};

#endif /* SHAPE_H_ */
