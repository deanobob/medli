/*
 * Wait.h
 *
 *  Created on: 30 Dec 2014
 *      Author: Dean Harris
 */

#ifndef WAIT_H_
#define WAIT_H_

#include "Routine.h"

class Wait :
    public Routine
{
  public:
    Wait(float duration);
    virtual ~Wait();

    void start(ScratchPad* pScratchPad);
    void act(ScratchPad* pScratchPad);

    void setDuration(float duration);

  private:
    const float duration_;
    float elapsedTime_;
};

#endif /* WAIT_H_ */
