/*
 * QuadTree.h
 *
 *  Created on: 12 Dec 2016
 *      Author: deano
 */

#ifndef MEDLI_UTILITIES_QUADTREE_H_
#define MEDLI_UTILITIES_QUADTREE_H_

#include <list>
#include <map>
#include <string>
#include "MedliRectangle.h"

struct Leaf
{
  const unsigned int id;
  const MedliRectangle bounds;
  Leaf(unsigned int id, const MedliRectangle& bounds) :
    id(id), bounds(bounds)
  {

  }
  virtual ~Leaf() {}
};

class QuadTree
{
  public:
    QuadTree(MedliRectangle boundary, QuadTree* pParent = nullptr);
    virtual ~QuadTree();

    bool insert(unsigned int entityId, const MedliRectangle& rectangle);
    std::list<unsigned int> query(const MedliRectangle& rectangle) const;
    bool remove(unsigned int entityId);
    void toString(std::string indent) const;

  private:
    std::map<unsigned int, QuadTree*> leafLocationMap_;
    std::list<Leaf> leafList_;
    QuadTree* pParent_;
    QuadTree* pNorthWest_;
    QuadTree* pNorthEast_;
    QuadTree* pSouthWest_;
    QuadTree* pSouthEast_;
    MedliRectangle boundary_;

    void subdivide();
    QuadTree* getLocation(unsigned int id) const;
    void setLocation(unsigned int id, QuadTree* container);
    bool erase(unsigned int entityId);
};

#endif /* MEDLI_UTILITIES_QUADTREE_H_ */
