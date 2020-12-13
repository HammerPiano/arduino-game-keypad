/**
 * This file is originaly from the Keypad library
 * https://github.com/Chris--A/Keypad
 * 
 * Modified to serve this project
 */

#pragma once

#include <Arduino.h>


template <class T>
class Key {
public:
	// members
	T _kvalue;
	boolean _value_used;
	// methods
	Key()
	{
		_value_used = false;
		//kvalue = NO_KEY;
		_kstate = IDLE;
		_stateChanged = false;
	}

	Key(T userKeyChar)
	{
		_value_used = true;
		_kvalue = userKeyChar;
		_kstate = IDLE;
		_stateChanged = false;
	}

	void key_update(char userKeyChar, KeyState userState, boolean userStatus)
	{
		_kvalue = userKeyChar;
		_kstate = userState;
		_stateChanged = userStatus;
	}

private:

};