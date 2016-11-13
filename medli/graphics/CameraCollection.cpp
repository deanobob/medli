/*
 * CameraCollection.cpp
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#include "CameraCollection.h"

CameraCollection::CameraCollection()
{

}

CameraCollection::~CameraCollection()
{
  for (auto it : this->cameraMap_)
  {
    delete it.second;
  }
}

void CameraCollection::add(Camera* pCamera)
{
  this->cameraMap_[pCamera->ID]  = pCamera;
  this->cameraQueue_.push(pCamera);
}

Camera* CameraCollection::get(const short id)
{
  auto it = this->cameraMap_.find(id);

  if (it != this->cameraMap_.end())
  {
    return (*it).second;
  }

  return nullptr;
}

bool CameraCollection::empty() const
{
  return this->cameraMap_.empty();
}

const std::priority_queue<Camera, std::vector<Camera*>, CameraComparator>&
    CameraCollection::getQueue() const
{
  return this->cameraQueue_;
}
