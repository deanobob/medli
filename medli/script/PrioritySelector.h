/*
 * PrioritySelector.h
 *
 *  Created on: 30 Dec 2014
 *      Author: Dean Harris
 */

#ifndef PRIORITYSELECTOR_H_
#define PRIORITYSELECTOR_H_

#include <list>
#include "Routine.h"

class PrioritySelector:
    public Routine
{
  public:
    PrioritySelector();
    virtual ~PrioritySelector();

    void start(ScratchPad* pScratchPad);
    void act(ScratchPad* pScratchPad);

    void addRoutine(Routine* pRoutine);

  private:
    std::list<Routine*> routineList_;
};

#endif /* PRIORITYSELECTOR_H_ */
