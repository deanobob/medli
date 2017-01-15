/*
 * Selector.h
 *
 *  Created on: 30 Dec 2014
 *      Author: Dean Harris
 */

#ifndef SELECTOR_H_
#define SELECTOR_H_

#include <list>
#include "Routine.h"

class Selector :
    public Routine
{
  public:
    Selector();
    virtual ~Selector();

    void start(ScratchPad* pScratchPad);
    void act(ScratchPad* pScratchPad);

    void addRoutine(Routine* pRoutine);

  private:
    Routine* pCurrentRoutine_;
    std::list<Routine*> routineList_;
    std::list<Routine*> routineQueue_;
};

#endif /* SELECTOR_H_ */
