/*
 * Parallel.h
 *
 *  Created on: 30 Dec 2014
 *      Author: Dean Harris
 */

#ifndef PARALLEL_H_
#define PARALLEL_H_

#include <list>
#include "Routine.h"

class Parallel:
    public Routine
{
  public:
    Parallel();
    virtual ~Parallel();

    void start(ScratchPad* pScratchPad);
    void act(ScratchPad* pScratchPad);

    void addRoutine(Routine* pRoutine);

  private:
    std::list<Routine*> routineList_;
};

#endif /* PARALLEL_H_ */
