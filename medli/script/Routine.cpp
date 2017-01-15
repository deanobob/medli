/*
 * Routine.cpp
 *
 *  Created on: 23 Dec 2014
 *      Author: Dean Harris
 */

#include "Routine.h"

Routine::Routine()
{
  this->state_ = RoutineState::IDLE;
}

Routine::~Routine()
{

}

void Routine::start(ScratchPad* pScratchPad)
{
  this->state_ = RoutineState::RUNNING;
}

RoutineState Routine::getState()
{
  return this->state_;
}

bool Routine::isSuccess()
{
  return this->state_ == RoutineState::SUCCESS;
}

bool Routine::isRunning()
{
  return this->state_ == RoutineState::RUNNING;
}

bool Routine::isFailure()
{
  return this->state_ == RoutineState::FAILURE;
}

void Routine::succeed()
{
  this->state_ = RoutineState::SUCCESS;
}

void Routine::fail()
{
  this->state_ = RoutineState::FAILURE;
}
