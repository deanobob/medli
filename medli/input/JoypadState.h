/*
 * JoypadState.h
 *
 *  Created on: 1 Sep 2013
 *      Author: deano
 */

#ifndef JOYPADSTATE_H_
#define JOYPADSTATE_H_

#include <list>
#include <map>
#include <vector>

class JoypadState
{
	public:
		JoypadState();
		virtual ~JoypadState();

		void setAxisState(unsigned int stick, unsigned int axis, float position);
		float getAxisState(unsigned int stick, unsigned int axis);

    void setButtonUp(int button);
    void setButtonDown(int button);
    bool isButtonDown(int button);

  private:
    std::map<unsigned int, std::vector<float> > stickList_;
    std::list<unsigned int> pressedButtonList_;
};

#endif /* JOYPADSTATE_H_ */
