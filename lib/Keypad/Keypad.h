/**
 * This file is originaly from the Keypad library
 * https://github.com/Chris--A/Keypad
 * 
 * Modified to serve this project
 */

#pragma once

typedef struct {
    byte rows;
    byte columns;
} KeypadSize;

template <class T>
class Keypad {
public:

	Keypad(T * userKeymap, byte * row, byte * col, byte numRows, byte numCols)
	{
		rowPins = row;
		columnPins = col;
		sizeKpd.rows = numRows;
		sizeKpd.columns = numCols;
		pressed_pins = malloc(numRows * numCols);
		pressed_pins_count = 0;

		// Init pins
		for (byte i=0; i<sizeKpd.rows; i++)
		{
			pinMode(rowPins[i],INPUT_PULLUP);
		}

		for (byte i = 0; i < sizeKpd.columns; i++)
		{
			pinMode(columnPins[i], INPUT);
		}
		

		begin(userKeymap);

		setDebounceTime(10);
		startTime = millis();
	}

	unsigned long holdTimer;

	// Populate the key list.
	bool getKeys()
	{
		bool keyActivity = false;

		// Limit how often the keypad is scanned. This makes the loop() run 10 times as fast.
		if ( (millis()-startTime) > debounceTime )
		{
			scanKeys();
			keyActivity = get_pressed_pins_count() > 0;
			startTime = millis();
		}

		return keyActivity;
	}
	void begin(T *userKeymap)
	{
    	keymap = userKeymap;
	}

	void setDebounceTime(uint16_t debounce)
	{
		// Recommenced is atleast 10ms, to allow the button to stabilize
		debounceTime = debounce;
	}

	byte * get_pressed_pins()
	{
		return pressed_pins;
	}

	byte get_pressed_pins_count()
	{
		return pressed_pins_count;
	}

	T operator[](byte pin_number)
	{
		return keymap[pin_number];
	}

	bool is_command_pin(byte pin)
	{
		// First row is command pin
		return pin < sizeKpd.columns;
	}
private:
	unsigned long startTime;
	T * keymap;
    byte *rowPins;
    byte *columnPins;
	KeypadSize sizeKpd;
	uint16_t debounceTime;

	byte * pressed_pins;
	byte pressed_pins_count;

	void scanKeys()
	{
		pressed_pins_count = 0;
		// bitMap stores ALL the keys that are being pressed.
		for (byte c=0; c<sizeKpd.columns; c++)
		{
			pinMode(columnPins[c],OUTPUT);
			digitalWrite(columnPins[c], LOW);	// Begin column pulse output.
			for (byte r=0; r<sizeKpd.rows; r++)
			{
				// keypress is active low so invert to high.
				if (digitalRead(rowPins[r]) == LOW) 
				{
					/* Values, 2d array, with rows number of arraies, each colum number of cells */
					pressed_pins[pressed_pins_count] = r * sizeKpd.columns + c; 
					pressed_pins_count++;
				}
			}
			// Set pin to high impedance input. Effectively ends column pulse.
			digitalWrite(columnPins[c],HIGH);
			pinMode(columnPins[c],INPUT);
		}
	}

	
};