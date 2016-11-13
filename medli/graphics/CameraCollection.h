/*
 * CameraCollection.h
 *
 *  Created on: 26 Apr 2015
 *      Author: Dean Harris
 */

#ifndef CAMERACOLLECTION_H_
#define CAMERACOLLECTION_H_

#include <queue>
#include <map>
#include <vector>
#include "Camera.h"

struct CameraComparator
{
    bool operator()(const Camera* lhs, const Camera* rhs) const
    {
      return rhs->ZIndex < lhs->ZIndex;
    }
};

class CameraCollection
{
  public:
    CameraCollection();
    virtual ~CameraCollection();

    void add(Camera* pCamera);
    Camera* get(const short id);

    bool empty() const;
    const std::priority_queue<Camera, std::vector<Camera*>, CameraComparator>&
      getQueue() const;

  private:
    std::map<const short, Camera*> cameraMap_;
    std::priority_queue<Camera, std::vector<Camera*>, CameraComparator> cameraQueue_;
};

#endif /* CAMERACOLLECTION_H_ */
