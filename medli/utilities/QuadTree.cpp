/*
 * QuadTree.cpp
 *
 *  Created on: 12 Dec 2016
 *      Author: deano
 */

#include "../log/Logger.h"
#include "QuadTree.h"
#include "Utilities.h"

static const int CAPACITY = 4;

QuadTree::QuadTree(MedliRectangle boundary, QuadTree* pParent)
{
  this->pParent_ = pParent;
  this->pNorthWest_ = nullptr;
  this->pNorthEast_ = nullptr;
  this->pSouthWest_ = nullptr;
  this->pSouthEast_ = nullptr;
  this->boundary_ = boundary;
}

QuadTree::~QuadTree()
{

}

bool QuadTree::insert(unsigned int id, const MedliRectangle& rectangle)
{
  bool rc = false;

  if (this->boundary_.contains(rectangle))
  {
    if (this->leafList_.size() >= CAPACITY && this->pNorthWest_ == nullptr)
    {
      this->subdivide();
    }

    if (this->pNorthWest_ != nullptr)
    {
      rc = this->pNorthWest_->insert(id, rectangle) ||
           this->pNorthEast_->insert(id, rectangle) ||
           this->pSouthWest_->insert(id, rectangle) ||
           this->pSouthEast_->insert(id, rectangle);
    }

    if (!rc)
    {
      this->leafList_.push_back(Leaf(id, rectangle));
      this->setLocation(id, this);
      rc = true;
    }
  }

  return rc;
}

std::list<unsigned int> QuadTree::query(const MedliRectangle& rectangle) const
{
  std::list<unsigned int> result;

  if (this->boundary_.intersects(rectangle))
  {
    for (Leaf leaf : this->leafList_)
    {
      if (leaf.bounds.intersects(rectangle))
      {
        result.push_back(leaf.id);
      }
    }

    if (this->pNorthEast_ != nullptr)
    {
      result.splice(result.end(), this->pNorthEast_->query(rectangle));
      result.splice(result.end(), this->pNorthWest_->query(rectangle));
      result.splice(result.end(), this->pSouthEast_->query(rectangle));
      result.splice(result.end(), this->pSouthWest_->query(rectangle));
    }
  }

  return result;
}

bool QuadTree::remove(unsigned int id)
{
  bool rc = false;

  QuadTree* pQuadTree = this->getLocation(id);
  if (pQuadTree != nullptr)
  {
    rc = pQuadTree->erase(id);
  }

  return rc;
}

void QuadTree::toString(std::string indent) const
{
  std::string str = indent;
  str.append("[");
  for (Leaf leaf : this->leafList_)
  {
    str.append(Utilities::integerToString(leaf.id));
    str.append(", ");
  }
  str.append("]");
  DBUG("%s", str.c_str());

  if (this->pNorthWest_ != nullptr)
  {
    indent.append("  ");
    this->pNorthWest_->toString(indent);
    this->pNorthEast_->toString(indent);
    this->pSouthWest_->toString(indent);
    this->pSouthEast_->toString(indent);
  }
}

void QuadTree::subdivide()
{
  int left = this->boundary_.X;
  int top = this->boundary_.Y;
  int halfWidth = this->boundary_.Width / 2;
  int halfHeight = this->boundary_.Height / 2;

  this->pNorthWest_ = new QuadTree(MedliRectangle(left, top, halfWidth, halfHeight), this);
  this->pNorthEast_ = new QuadTree(MedliRectangle(left + halfWidth, top, halfWidth, halfHeight), this);
  this->pSouthWest_ = new QuadTree(MedliRectangle(left, top + halfHeight, halfWidth, halfHeight), this);
  this->pSouthEast_ = new QuadTree(MedliRectangle(left + halfWidth, top + halfHeight, halfWidth, halfHeight), this);

  std::list<Leaf> leaves = this->leafList_;
  this->leafList_.clear();

  for (Leaf leaf : leaves)
  {
    this->insert(leaf.id, leaf.bounds);
  }
}

QuadTree* QuadTree::getLocation(unsigned int id) const
{
  QuadTree* pQuadTree = NULL;

  if (this->pParent_ == nullptr)
  {
    std::map<unsigned int, QuadTree*>::const_iterator it = this->leafLocationMap_.find(id);
    if (it != this->leafLocationMap_.end())
    {
      pQuadTree = (*it).second;
    }
    else
    {
      //unknown id - should this be throwing an error?
    }
  }
  else
  {
    this->pParent_->getLocation(id);
  }

  return pQuadTree;
}

void QuadTree::setLocation(unsigned int id, QuadTree* pContainer)
{
  if (this->pParent_ == nullptr)
  {
    if (pContainer == nullptr)
    {
      this->leafLocationMap_.erase(id);
    }
    else
    {
      this->leafLocationMap_[id] = pContainer;
    }
  }
  else
  {
    this->pParent_->setLocation(id, pContainer);
  }
}

bool QuadTree::erase(unsigned int id)
{
  bool rc = false;

  for (std::list<Leaf>::iterator it = this->leafList_.begin();
      it != this->leafList_.end();
      ++it)
  {
    Leaf leaf = (*it);
    if (leaf.id == id)
    {
      this->leafList_.erase(it);
      this->setLocation(id, nullptr);
      rc = true;
      break;
    }
  }

  return rc;
}
