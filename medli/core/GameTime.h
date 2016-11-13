/*
 * GameTime.h
 *
 *  Created on: 11 Aug 2013
 *      Author: deano
 */

#ifndef GAMETIME_H_
#define GAMETIME_H_

class GameTime
{
  public:
    double elapsedGameTime;
    double totalGameTime;

    GameTime();
    virtual ~GameTime();
};

#endif /* GAMETIME_H_ */
