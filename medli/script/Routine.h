/*
 * Routine.h
 *
 *  Created on: 23 Dec 2014
 *      Author: Dean Harris
 */

#ifndef ROUTINE_H_
#define ROUTINE_H_

enum RoutineState : int
{
  IDLE = 0,
  SUCCESS,
  FAILURE,
  RUNNING
};

class EntityManager;
class ScratchPad;

class Routine
{
  public:
    virtual ~Routine();

    virtual void start(ScratchPad* pScratchPad);
    virtual void act(ScratchPad* pScratchPad) = 0;

    virtual bool isSuccess();
    virtual bool isFailure();
    virtual bool isRunning();

    virtual RoutineState getState();

  protected:
    Routine();

    void succeed();
    void fail();

  private:
    RoutineState state_;
};

#endif /* ROUTINE_H_ */
