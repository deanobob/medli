/*
 * Sequence.h
 *
 *  Created on: 30 Dec 2014
 *      Author: Dean Harris
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <list>
#include "Routine.h"

class Sequence:
    public Routine
{
  public:
    Sequence();
    virtual ~Sequence();

    void start(ScratchPad* pScratchPad);
    void act(ScratchPad* pScratchPad);

    void addRoutine(Routine* pRoutine);

  private:
    Routine* pCurrentRoutine_;
    std::list<Routine*> routineList_;
    std::list<Routine*> routineQueue_;
};

#endif /* SEQUENCE_H_ */
