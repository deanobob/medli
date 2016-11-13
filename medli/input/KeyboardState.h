/*
 * KeyboardState.h
 *
 *  Created on: 1 Sep 2013
 *      Author: deano
 */

#ifndef KEYBOARDSTATE_H_
#define KEYBOARDSTATE_H_

#include <list>

class KeyboardState
{
	public:
		KeyboardState();
		virtual ~KeyboardState();

		void setKeyUp(int keycode);
		void setKeyDown(int keycode);
		bool isKeyDown(int keycode);

	private:
		std::list<int> pressedKeyList_;
};

#endif /* KEYBOARDSTATE_H_ */
