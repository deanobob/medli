/*
 * BehaviourTree.h
 *
 *  Created on: 23 Dec 2014
 *      Author: Dean Harris
 */

#ifndef BEHAVIOURTREE_H_
#define BEHAVIOURTREE_H_

class EntityManager;
class Routine;
class ScratchPad;

class BehaviourTree
{
  public:
    BehaviourTree(Routine* pRoot);
    virtual ~BehaviourTree();

    void update();
    bool isFinished() const;

  private:
    Routine* pRoot_;
    ScratchPad* pScratchPad_;
};

#endif /* BEHAVIOURTREE_H_ */
